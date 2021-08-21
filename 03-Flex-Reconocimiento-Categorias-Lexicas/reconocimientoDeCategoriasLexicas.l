%option noyywrap

%{
#include<stdio.h> 
#include "lib.h"   
#include "identificadores.h"
/*
#include "palabrasNoReconocidas.h"
*/
#include "palabrasReservadas.h"
#include "operadoresYcaracteresDePuntuacion.h"
#include "constantesDec.h"
#include "constantesOct.h"
#include "constantesHex.h"
#include "constantesReal.h"
#include "constantesCaracter.h"
#include "comentarios.h"
#define MAX_TAM_IDENTIFIER 50

// Cantidad de lineas
int numeroDeLinea = 1;

//ACUMULADOR DE CONSTANTES DECIMALES
int acumDecimal = 0;

// Identificadores
IdentifierNode *listaIdentificadores = NULL;

//Constantes Decimales
ConstDecNode* listaConstantesDecimales = NULL;

//Constantes Octales
ConstOctNode* listaConstantesOctales = NULL;

//Constantes Hexadecimales
ConstHexNode* listaConstantesHexadecimales = NULL;

//Constante Real
ConstRealNode* listaConstantesReales = NULL;

//Constante Caracter 
ConstCaracNode* listaConstantesCaracter = NULL;

// Palabras Reservadas
PalabrasReservadasNode* listaPalabrasReservadas = NULL;

// Operadores y Caracteres de Puntuacion
OperadoresNode* listaOperadores = NULL;

// Comentarios Simples
ComentarioNode* listaComentariosSimples = NULL;

// Comentarios Compuestos
ComentarioNode* listaComentariosCompuestos = NULL;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 

%%
[1-9]{DIGITO_DECIMAL}* {
                        acumDecimal += atoi(yytext);
                        pushConstDec(&listaConstantesDecimales, yytext);
                        numeroDeLinea++;
                        }
0{DIGITO_OCTAL}* {
                  pushConstOct(&listaConstantesOctales,yytext);
                  numeroDeLinea++;
                  }
0[xX]{DIGITO_HEXADECIMAL}+ { 
                            pushConstHex(&listaConstantesHexadecimales,yytext);
                            numeroDeLinea++;
                            }

[0-9]+\.[0-9]+[Ee]((\+?)|\-)[0-9]+ {
                              pushConstReal(&listaConstantesReales,yytext);
                              numeroDeLinea++;
                    }

\'.\' {
        char constanteCaracter = yytext[1];
        pushConstCarac(&listaConstantesCaracter, yytext[1]);
        numeroDeLinea++;
      }

\".*\" { 
        printf("Encontra un literal cadena \n"); 
         numeroDeLinea++;
       }

(char|do|double|else|float|for|if|int|long|return|sizeof|struct|typeof|void|while) {
     appendPalabraReservada(&listaPalabrasReservadas, yytext); 
     numeroDeLinea++;
}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {
                                        addIdentifier(&listaIdentificadores, yytext); 
                                        numeroDeLinea++;
                                        }

(\+\+|\-\-|\*|\+|&|\!|sizeof|%|\/|<|>|<=|>=|==|\!=|&&|\|\||=|\+=|\-=) {
     addOperadores(&listaOperadores, yytext[0]); 
     numeroDeLinea++;
}

[\(\)\{\}\,\;\[\]] {
     addOperadores(&listaOperadores, yytext[0]); 
     numeroDeLinea++;
}

\/\/.*\n {
     pushComentario(&listaComentariosSimples, yytext); 
     numeroDeLinea++;
}

\/\*.*\*\/ {
     pushComentario(&listaComentariosSimples, yytext); 
     numeroDeLinea++;
}

%%


int main(void){    
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    yylex();

   // Identificadores
    printListIdentifier(listaIdentificadores);

    //Constantes Decimales
    printConstantesDecimales(listaConstantesDecimales);
    printf("Acumulado valor decimal %d\n",acumDecimal);

    //Constanes Octales
    printConstantesOctales(listaConstantesOctales);

    //Constantes Hexadecimales
    printConstantesHexadecimales(listaConstantesHexadecimales);

    //Constantes Reales
    printConstantesReales(listaConstantesReales);

    //Consantes Caracter
    printConstantesCaracter(listaConstantesCaracter);

    //Palabras Reservadas
    printPalabrasReservadas(listaPalabrasReservadas);

    //Operadores y caracteres de Puntuacion
    printOperadores(listaOperadores);

    // Comentarios simples
    char comentariosSimples[] = "Simples";
    printComentarios(listaComentariosSimples, comentariosSimples);

    // Comentarios compuestos
    char comentariosCompuestos[] = "Compuestos";
    printComentarios(listaComentariosCompuestos, comentariosCompuestos);

    return 0;
}

/**
ACLARACION: POR CUESTIONES DE SIMPLICIDAD, NO TENEMOS EN CUENTA EL SIGUIENTE CASO: 
.4E3

TAMPOCO EL SIGUIENTE CASO: 
4.
**/