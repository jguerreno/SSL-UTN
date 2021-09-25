
%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define YYDEBUG 1

int yylex(void);

int yyerror (const char *s){
    printf("-------- ERRROR ---------\n");
    printf ("%s\n", s);
    return -1;
}

extern FILE *yyin;
extern int yylineno;
%}


%union {
    int entero;
    float real;
    char* cadena;
}


// Palabras Reservadas
%token <cadena> IF
%token <cadena> ELSE
%token <cadena> SWITCH
%token <cadena> WHILE
%token <cadena> DO
%token <cadena> FOR
%token <cadena> CASE
%token <cadena> DEFAULT
%token <cadena> CONTINUE
%token <cadena> BREAK
%token <cadena> RETURN

// Tipo de Dato
%token <cadena> TIPO_DATO

// Operadores                        
%token <cadena> OPERADOR_ASIGNACION
%token <cadena> OPERADOR_O_LOGICO
%token <cadena> OPERADOR_Y_LOGICO
%token <cadena> OPERADOR_O_INCLUSIVO
%token <cadena> OPERADOR_O_EXCLUSIVO
%token <cadena> OPERADOR_IGUALDAD
%token <cadena> OPERADOR_RELACIONAL
%token <cadena> OPERADOR_CORRIMIENTO
%token <cadena> OPERADOR_MULTIPLICATIVO
%token <cadena> OPERADOR_INCREMENTO
%token <cadena> OPERADOR_SIZEOF

// Identificador
%token <cadena> IDENTIFICADOR

// Constantes
%token <cadena> CONSTANTE_CADENA
%token <entero> CONSTANTE_DECIMAL
%token <entero> CONSTANTE_OCTAL
%token <entero> CONSTANTE_HEXADECIMAL
%token <entero> CONSTANTE_CARACTER
%token <real>   CONSTANTE_REAL


%%
input:    /* vacio */
        | input line
;

line:     '\n'
        | sentencia '\n'  { printf ("\t Sentencia\n"); }
;


/****************************** sentencias ************************************/
sentencia: bloque_sentencias         { printf("sentencia -> bloque_sentencias\n"); }
            | sentencia_expresion     { printf("sentencia -> sentencia_expresion\n"); }
            | sentencia_bifurcacion   { printf("sentencia -> sentencia_bifurcacion\n"); }
            | sentencia_bucle         { printf("sentencia -> sentencia_bucle\n"); }
            | sentencia_salto         { printf("sentencia -> sentencia_salto\n"); }
            | sentencia_retorno       { printf("sentencia -> sentencia_retorno\n"); }
;

bloque_sentencias: '{' '}'                                     { printf("bloque_sentencias -> '{' '}'\n"); }
                     | '{' declaracion_list sentencia_list '}'  { printf("bloque_sentencias -> '{' declaracion_list sentencia_list '}'\n"); }
;

declaracion_list: declaracion                  { printf("declaracion_list -> declaracion\n"); }
                | declaracion declaracion_list { printf("declaracion_list -> declaracion_list declaracion\n"); }
;

sentencia_list: sentencia                  { printf("sentencia_list -> sentencia\n"); }
                | sentencia sentencia_list { printf("sentencia_list -> sentencia_list sentencia\n"); }
;

sentencia_expresion: expresion ';'     { printf("sentencia_expresion -> expresion ';'\n"); }
                    | asignacion ';'  { printf("sentencia_expresion -> asignacion ';'\n"); }
;

asignacion: expresion_indexada operador_asignacion expresion { printf("asignacion -> expresion_indexada operador_asignacion expresion\n"); } 
;

expresion_indexada: IDENTIFICADOR { printf("expresion_indexada -> IDENTIFICADOR\n"); }
                    |
                    expresion_indexada '[' expresion ']' { printf("expresion_indexada -> expresion_indexada '[' expresion ']'\n"); }
;

operador_asignacion: '='                   { printf("operador_asignacion -> '='\n"); }
                    | OPERADOR_ASIGNACION   { printf("operador_asignacion -> IGUAL Y ALGO\n"); }
;

sentencia_bifurcacion:  IF '(' expresion ')' sentencia else_opcional        { printf("sentencia_bifurcacion -> IF '(' expresion ')' sentencia ELSE sentencia\n"); }
                        | SWITCH '(' expresion ')' '{' sentencia_caso_list'}'  { printf("sentencia_bifurcacion -> SWITCH '(' expresion ')' '{' sentencia_caso_list'}'\n"); }
;

else_opcional: /* vacio */
            | ELSE sentencia        { printf("sentencia_bifurcacion -> ELSE sentencia\n"); }
;

sentencia_caso_list: sentencia_caso                       { printf("sentencia_caso_list -> sentencia_caso\n"); }
                      | sentencia_caso sentencia_caso_list { printf("sentencia_caso_list -> sentencia_caso_list sentencia_caso\n"); }
;

sentencia_caso: CASE expresion ':' sentencia   { printf("sentencia_caso -> CASE expresion ':' sentencia\n"); }
                 | DEFAULT ':' sentencia        { printf("sentencia_caso -> DEFAULT ':' sentencia\n"); }
;

sentencia_bucle: WHILE '(' expresion ')' sentencia                                       { printf("sentencia_bucle -> WHILE '(' expresion ')' sentencia\n"); }
                  | DO sentencia WHILE '(' expresion ')' ';'                              { printf("sentencia_bucle -> DO sentencia WHILE '(' expresion ')' ;\n"); }
                  | FOR '(' lista_asignaciones ';' expresion ';' expresion ')' sentencia  { printf("sentencia_bucle -> FOR '(' lista_asignaciones ';' expresion ';' expresion ')' sentencia\n"); }
;

lista_asignaciones: asignacion                        { printf("lista_asignaciones -> asignacion\n"); }
                   | asignacion ',' lista_asignaciones { printf("lista_asignaciones -> lista_asignaciones ',' asignacion\n"); } 
;

sentencia_salto: CONTINUE ';'            { printf("sentencia_salto -> CONTINUE ';'\n"); }
                | BREAK ';'               { printf("sentencia_salto -> BREAK ';'\n"); }
;

sentencia_retorno: RETURN ';'              { printf("sentencia_retorno -> RETURN ';'\n"); }
                    | RETURN expresion ';'  { printf("sentencia_retorno -> RETURN expresion ';'\n"); }
;
%%


int main ()
{
    yyin = fopen("entrada.txt", "r");

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif
    yyparse ();

    fclose(yyin);
}