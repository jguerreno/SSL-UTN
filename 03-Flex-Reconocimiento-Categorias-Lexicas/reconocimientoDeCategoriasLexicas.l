%option noyywrap

%{
#include<stdio.h> 
#include "lib.h"   
#define MAX_TAM_IDENTIFIER 50
%}

DIGITO_DECIMAL [0-9] 
DIGITO_OCTAL [0-7] 
DIGITO_HEXADECIMAL [a-fA-F0-9] 
LETRA [a-zA-Z] 

%%
[1-9]{DIGITO_DECIMAL}* {printf("Encontre la constante entera decimal: %s de longitud %d \n",yytext,yyleng);}
0{DIGITO_OCTAL}* {printf("Encontre la constante entera octal: %s de longitud %d \n",yytext,yyleng);}
0[xX]{DIGITO_HEXADECIMAL}+ {printf("Encontre la constante entera hexadecimal: %s de longitud %d \n",yytext,yyleng);}


\'.\' {printf("Encontre una constante caracter");}

\".\" {printf("Encontra un literal cadena");}

(char|do|double|else|float|for|if|int|long|return|sizeof|struct|typeof|void|while) {printf("Se reconocio una palabra reservada \n");}

(_|{LETRA})({DIGITO_DECIMAL}|{LETRA}|_)* {printf("Se reconocio una identificador\n");}

(\+\+|\-\-|\*|\+|&|!|sizeof|%|/|<|>|<=|>=|==|!=|&&|\|\||=|\+=|\-=) {printf("Se reconocio un operador\n")}

(\(|\)|\{|\}|,|;) {printf("Se reconocio un caracter de puntuacion\n");}


\/\/.*\n {printf("Encontre un comentario simple\n");}


\/\*.*\*\/ {printf("Encontre un comentario de multiple linea\n");}

%%

/**FALTA HACER ERX DE CONSTANTES REALES **/

/**
Listado de identificadores encontrados indicando la cantidad de veces que aparece cada uno de ellos. El listado debe estar ordenado alfabéticamente.
**/


int main(void){
    
    yyout = fopen("salida.txt","w");
    yylex();

    return 0;
}