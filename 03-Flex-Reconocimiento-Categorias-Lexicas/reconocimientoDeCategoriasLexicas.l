%option noyywrap

%{
#include<stdio.h> 
#include "lib.h"   
#include "identificadores.h"
#include "comentarios.h"
#include "palabrasReservadas.h"
#include "palabrasNoReconocidas.h"
#include "operadoresYcaracteresDePuntuacion.h"
#include "constantesDec.h"
#include "constantesOct.h"
#include "constantesHex.h"

#define MAX_TAM_IDENTIFIER 50

// Cantidad de lineas
int numeroDeLinea = 1;

//ACUMULADOR DE CONSTANTES DECIMALES
int acumDecimal = 0;

//Constantes Decimales
ConstDecNode* listaConstantesDecimales = NULL;

//Constantes Octales
ConstOctNode* listaConstantesOctales = NULL;

// Identificadores
IdentifierNode *listaIdentificadores = NULL;

//Constantes Hexadecimales
ConstHexNode* listaConstantesHexadecimales = NULL;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 

%%
[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s de longitud %d \n",yytext,yyleng); 
                        pushConstDec(&listaConstantesDecimales, yytext);
                        acumDecimal += atoi(yytext);
                        numeroDeLinea++;
                        }
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal: %s de longitud %d \n",yytext,yyleng); 
                  pushConstOct(&listaConstantesOctales,yytext);
                  numeroDeLinea++;
                  }
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s de longitud %d \n",yytext,yyleng); 
                            numeroDeLinea++;
                            pushConstHex(&listaConstantesHexadecimales,yytext);
                            }

[0-9]+\.[0-9]+[Ee]((\+?)|\-)[0-9]+ {printf("Encontre una constante real: %s\n",yytext);}

\'.\' {printf("Encontre una constante caracter"); numeroDeLinea++;}

\".*\" {printf("Encontra un literal cadena"); numeroDeLinea++;}

(char|do|double|else|float|for|if|int|long|return|sizeof|struct|typeof|void|while) {
    appendPalabraReservada(&listaPalabrasReservadas, yytext); numeroDeLinea++;
}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {
    addIdentifier(&listaIdentificadores, yytext); numeroDeLinea++;
}

(\+\+|\-\-|\*|\+|&|\!|sizeof|%|\/|<|>|<=|>=|==|\!=|&&|\|\||=|\+=|\-=) {
    addOperadores(&listaOperadores, yytext[0]); numeroDeLinea++;
}

[\(\)\{\}\,\;\[\]] {
    addOperadores(&listaOperadores, yytext[0]); numeroDeLinea++;
}

\/\/.*\n {
    pushComentario(&listaComentariosSimples, yytext); numeroDeLinea++;
}

\/\*.*\*\/ {
    pushComentario(&listaComentariosCompuestos, yytext); numeroDeLinea++;
}

.+  {
    pushPalabraNoReconocida(&listaPalabrasNoReconocidas, yytext, numeroDeLinea); numeroDeLinea++;
}

%%


int main(void){    
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    yylex();

    // Palabras reservadas
    printPalabrasReservadas(listaPalabrasReservadas);
    deletePalabrasReservadas(&listaPalabrasReservadas);


    // Comentarios
    // Simples
    char comentariosSimples[] = "Simples";
    printComentarios(listaComentariosSimples, comentariosSimples);
    deleteListaComentarios(&listaComentariosSimples);

    // Compuestos
    char comentariosCompuestos[] = "Compuestos";
    printComentarios(listaComentariosCompuestos, comentariosCompuestos);
    deleteListaComentarios(&listaComentariosCompuestos);


	// Palabras No Reconocidas
    printPalabrasNoReconocidas(listaPalabrasNoReconocidas);
    deleteListaPalabrasNoReconocidas(&listaPalabrasNoReconocidas);


    // Operadores y Caracteres de Puntuacion
    printOperadores(listaOperadores);
    deleteListaOperadores(&listaOperadores);

   // Identificadores
    printListIdentifier(listaIdentificadores);
    deleteListIdentifier(&listaIdentificadores);
    
    //Constantes Decimales
    printConstantesDecimales(listaConstantesDecimales);
    deleteListaConstanteDecimales(&listaConstantesDecimales);
    printf("Acumulado valor decimal %d\n",acumDecimal);

    //Constanes Octales
    printConstantesOctales(listaConstantesOctales);
    deleteListaConstanteDecimales(&listaConstantesOctales);

    //Constantes Hexadecimales
    printConstantesHexadecimales(listaConstantesHexadecimales);


    return 0;
}

/**
ACLARACION: POR CUESTIONES DE SIMPLICIDAD, NO TENEMOS EN CUENTA EL SIGUIENTE CASO: 
.4E3

TAMPOCO EL SIGUIENTE CASO: 
4.
**/