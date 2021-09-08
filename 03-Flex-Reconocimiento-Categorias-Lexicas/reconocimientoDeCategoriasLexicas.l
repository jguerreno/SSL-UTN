%option noyywrap

%{
#include<stdio.h> 
#include "lib.h"   
#include "identificadores.h"
#include "literalesCadena.h"
#include "constantes.h"
#include "constantesReal.h"
#include "constantesCaracter.h"
#include "operadoresYcaracteresDePuntuacion.h"
#include "palabrasReservadas.h"
#include "palabrasNoReconocidas.h"
#include "comentarios.h"


// Cantidad de lineas
int numeroDeLinea = 1;

//ACUMULADOR DE CONSTANTES DECIMALES
int acumDecimal = 0;

int firstTimeLitCadena = 1;

// Identificadores
IdentifierNode *listaIdentificadores = NULL;

//Literales Cadena
LiteralCadenaNode *listaLiteralCadena = NULL;

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

// Operadores y Caracteres de Puntuacion
OperadoresNode* listaOperadores = NULL;

// Palabras Reservadas
PalabrasReservadasNode* listaPalabrasReservadas = NULL;

// Comentarios Simples
ComentarioNode* listaComentariosSimples = NULL;

// Comentarios Compuestos
ComentarioNode* listaComentariosCompuestos = NULL;

// Palabras no reconocidas
NoReconocidoNode* listaPalabrasNoReconocidas = NULL;

%}


DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 


%%
\n {numeroDeLinea++;}
" "|"\t"

(char|do|double|else|float|for|if|int|long|return|sizeof|struct|typeof|void|while) {
          appendPalabraReservada(&listaPalabrasReservadas, yytext);
}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {
                                        addIdentifier(&listaIdentificadores, yytext); 
                                        }

(\+\+|\-\-|\*|\+|&|\!|sizeof|%|\/|<|>|<=|>=|==|\!=|&&|\|\||=|\+=|\-=|\-) {
     addOperadores(&listaOperadores, yytext[0]); 
}

[\(\)\{\}\,\;\[\]] {
     addOperadores(&listaOperadores, yytext[0]); 
}



[1-9]{DIGITO_DECIMAL}* {
                        acumDecimal += atoi(yytext);
                        pushConstDec(&listaConstantesDecimales, yytext);
                        }
0{DIGITO_OCTAL}* {
                  pushConstOct(&listaConstantesOctales,yytext);
                  }
0[xX]{DIGITO_HEXADECIMAL}+ { 
                            pushConstHex(&listaConstantesHexadecimales,yytext);
                            }

[0-9]+\.[0-9]+([Ee](\+|\-)?[0-9]+)? {
                         pushConstReal(&listaConstantesReales,yytext);
                    }

\'.\' {
        pushConstCarac(&listaConstantesCaracter, yytext[1]);
      }

\".*\" {
          if(firstTimeLitCadena==1){
               LiteralCadenaNode* new_node = (LiteralCadenaNode*) malloc(sizeof(LiteralCadenaNode));
               new_node->data  = newDataLiteralCadena(yytext, yyleng);
               new_node->next = listaLiteralCadena;
               (listaLiteralCadena) = new_node;
               firstTimeLitCadena = -1;
          }else{
               addLiteralCadena(&listaLiteralCadena, yytext, yyleng);
          }
       }

\/\/.* {
     pushComentario(&listaComentariosSimples, yytext); 
}

\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/ {
     pushComentario(&listaComentariosCompuestos, yytext); 
}


. {
     pushPalabraNoReconocida(&listaPalabrasNoReconocidas, yytext, numeroDeLinea);
}
%%


int main(void){    
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    FILE *reporte;
    reporte = fopen("reporte.txt", "w"); 

    yylex();

    //Intro al reporte
    writeIntroReporte(reporte);

    //Identificadores
    printListIdentifier(reporte, listaIdentificadores);

     //LiteralesCadena
    printListLiteralCadena(reporte, listaLiteralCadena);

    //Constantes Decimales
    printConstantesDecimales(reporte, listaConstantesDecimales);
    fprintf(reporte,"Acumulado valor decimal %d\n",acumDecimal); 
    
    //Constanes Octales
    printConstantesOctales(reporte, listaConstantesOctales);

    //Constantes Hexadecimales
    printConstantesHexadecimales(reporte, listaConstantesHexadecimales);

    //Constantes Reales
    printConstantesReales(reporte, listaConstantesReales);

    //Consantes Caracter
    printConstantesCaracter(reporte, listaConstantesCaracter);

    //Operadores y caracteres de Puntuacion
    printOperadores(reporte, listaOperadores);

     //Palabras Reservadas
    printPalabrasReservadas(reporte, listaPalabrasReservadas);

     // Comentarios simples
    char comentariosSimples[] = "Simples";
    printComentarios(reporte, listaComentariosSimples, comentariosSimples);

    // Comentarios compuestos
    char comentariosCompuestos[] = "Compuestos";
    printComentarios(reporte, listaComentariosCompuestos, comentariosCompuestos);

    // Palabras No Reconocidas
    printPalabrasNoReconocidas(reporte, listaPalabrasNoReconocidas);

    fclose(reporte); 

    return 0;
}

