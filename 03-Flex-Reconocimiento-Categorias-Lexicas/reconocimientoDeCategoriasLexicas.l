%option noyywrap

%{
#include<stdio.h> 
#include "lib.h"   
#include "identificadores.h"
#define MAX_TAM_IDENTIFIER 50

int numeroDeLinea = 1;
struct IdentifierNode *listaIdentificadores = NULL;

%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 

%%
[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s de longitud %d \n",yytext,yyleng); numeroDeLinea++;}
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal: %s de longitud %d \n",yytext,yyleng); numeroDeLinea++;}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s de longitud %d \n",yytext,yyleng); numeroDeLinea++;}


\'.\' {printf("Encontre una constante caracter"); numeroDeLinea++;}

\".*\" {printf("Encontra un literal cadena"); numeroDeLinea++;}

(char|do|double|else|float|for|if|int|long|return|sizeof|struct|typeof|void|while) {printf("Se reconocio una palabra reservada \n"); numeroDeLinea++;}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {printf("Se reconocio una identificador\n"); numeroDeLinea++;}

(\+\+|\-\-|\*|\+|&|\!|sizeof|%|\/|<|>|<=|>=|==|\!=|&&|\|\||=|\+=|\-=) {printf("Se reconocio un operador\n"); numeroDeLinea++;}

[\(\)\{\}\,\;\[\]] {printf("Reconoci un carac de puntuacion\n"); numeroDeLinea++;}

\/\/.*\n {printf("Encontre un comentario simple\n"); numeroDeLinea++;}

\/\*.*\*\/ {printf("Encontre un comentario de multiple linea\n"); numeroDeLinea++;}

.+  {numeroDeLinea++;}


%%

/**FALTA HACER ERX DE CONSTANTES REALES **/

/**FALTA HACER EL ORDENAMIENTO DE LA LISTA EN IDENTIFICADORES**/

/**FALTA HACER EL ORDENAMIENTO EN CADENAS LITERALES**/

/**
Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. 
El listado debe estar ordenado alfabéticamente.
**/

/**
Listado de literales cadena encontrados indicando la longitud de los mismos y ordenados por longitud ascendente. 
En caso de igual longitud no importa el orden.
**/

/**
Listado de palabras reservadas en el orden en el que han aparecido en el archivo.
**/

int main(void){    
     yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	

    yylex();
	
    return 0;
}