%option noyywrap

%{
#include<stdio.h>    
%}

NUMERO [0-9]
LETRA [a-zA-Z]

%%
(_|{LETRA})({NUMERO}|{LETRA}|_)* {printf("Se reconocio una identificador\n");}
%%

int main(void){
    
    yyout = fopen("salida.txt","w");
    yylex();

    return 0;
}