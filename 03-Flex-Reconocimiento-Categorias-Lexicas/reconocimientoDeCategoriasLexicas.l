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
#include "palabras.h"
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
PalabrasReservadasNode* listaPalabrasReservadas_TipoDeDatos = NULL;
PalabrasReservadasNode* listaPalabrasReservadas_Estructuras = NULL;
PalabrasReservadasNode* listaPalabrasReservadas_Otros = NULL;


// Comentarios Simples
ComentarioNode* listaComentariosSimples = NULL;

// Comentarios Compuestos
ComentarioNode* listaComentariosCompuestos = NULL;

// Palabras no reconocidas
NoReconocidoNode* listaPalabrasNoReconocidas = NULL;

%}


OPERADOR_CARACTER_DE_PUNTUACION ("*="|"/="|"%="|"+="|"*="|"<<="|">>="|"&="|"^="|"|="|"||"|"&&"|"|"|"^"|"=="|"!="|"<"|">"|"<="|">="|"<<"|">>"|"/"|"%"|"++"|"--"|","|"."|"?"|":"|"("|")"|"["|"]"|"="|"{"|"}"|";"|"*"|"&"|"+"|"-"|"~"|"!"|"->")

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 


%%
\n {numeroDeLinea++;}
" "|"\t"

(char|double|float|int|long|struct|void|enum|union|short) {
          appendPalabraReservada(&listaPalabrasReservadas_TipoDeDatos, yytext);
}
(do|else|for|if|while|switch|case|default) {
          appendPalabraReservada(&listaPalabrasReservadas_Estructuras, yytext);
}
(return|sizeof|typeof|typedef|auto|break|register|extern|const|unsigned|continue|signed|goto|volatile|static) {
          appendPalabraReservada(&listaPalabrasReservadas_Otros, yytext);
}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {
                                        addIdentifier(&listaIdentificadores, yytext); 
                                        }

{OPERADOR_CARACTER_DE_PUNTUACION} {addOperadores(&listaOperadores, yytext);}



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
        appendConstantesCaracter(&listaConstantesCaracter, yytext[1]);
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
    printPalabrasReservadas(reporte, listaPalabrasReservadas_TipoDeDatos, "Tipo de Datos");
    printPalabrasReservadas(reporte, listaPalabrasReservadas_Estructuras, "Estructuras");
    printPalabrasReservadas(reporte, listaPalabrasReservadas_Otros, "Otros");

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

