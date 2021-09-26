
%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define YYDEBUG 1

/** VARIABLES GLOBALES **/
int flag_error=0;
int contador=0;
char* tipo;
/** VARIABLES GLOBALES **/

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


// Type
%right '=' OPERADOR_ASIGNACION
%right '?' ':'
%left OPERADOR_O_LOGICO
%left OPERADOR_Y_LOGICO
%left '|'
%left '^'
%left '&'
%left OPERADOR_RELACIONAL '<' '>'
%left OPERADOR_CORRIMIENTO
%left '-' '+'
%left '*' '/' '%'
%right OPERADOR_INCREMENTO OPERADOR_SIZEOF
%left ')'
%right '('


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

/****************************** DECLARACIONES ************************************/

declaracion: declaracion_variables 
             | 
             declaracion_funciones
;

declaracion_funciones: IDENTIFICADOR '(' listaParametros ')' 
;

declaracion_variables: identVariable 
                      | 
                      identVariable ',' declaracion_variables
;

listaParametros: TIPO_DATO IDENTIFICADOR 
                 | 
                 TIPO_DATO IDENTIFICADOR ',' listaParametros 
                 |
                 /** VACIO***/
;

identVariable: TIPO_DATO IDENTIFICADOR 
               | 
               TIPO_DATO IDENTIFICADOR '=' constante 
               | 
               error
;

constante: CONSTANTE_DECIMAL 
           |
           CONSTANTE_OCTAL
           |
           CONSTANTE_HEXADECIMAL
           |
           CONSTANTE_CARACTER
           |
           error
;


sentencia_list: sentencia                  { printf("sentencia_list -> sentencia\n"); }
                | sentencia sentencia_list { printf("sentencia_list -> sentencia_list sentencia\n"); }
;

sentencia_expresion: expresion ';'     { printf("sentencia_expresion -> expresion ';'\n"); }
                    | asignacion ';'  { printf("sentencia_expresion -> asignacion ';'\n"); }
;

/****************************** EXPRESIONES ************************************/

expresion: expresion_logica                                 { printf("Expresion  -> expresion_logica\n"); }
         | expresion_logica '?' expresion ':' expresion     { printf("Expresion  -> expresion_logica '?' expresion ':' expresion \n"); }
         | expresion '-' expresion                          { printf("Expresion_logica -> expresion '-' expresion\n"); }
         | expresion '+' expresion                          { printf("Expresion_logica -> expresion '+' expresion\n"); }
         | expresion '*' expresion                          { printf("Expresion_logica -> expresion '*' expresion\n"); }
         | expresion OPERADOR_MULTIPLICATIVO expresion      { printf("Expresion_logica -> expresion '/' expresion\n"); }
;

expresion_logica: expresion_prefija                     { printf("Expresion_logica -> expresion_prefija \n"); }
          | expresion OPERADOR_ASIGNACION expresion     { printf("Expresion_logica -> expresion 'OPERADOR DE ASIGNACION' expresion \n"); }
          | expresion OPERADOR_O_LOGICO expresion       { printf("Expresion_logica -> expresion OR expresion \n"); }
          | expresion OPERADOR_Y_LOGICO expresion       { printf("Expresion_logica -> expresion AND expresion \n"); }
          | expresion OPERADOR_O_INCLUSIVO expresion    { printf("Expresion_logica -> expresion '|' expresion  \n"); }
          | expresion OPERADOR_O_EXCLUSIVO expresion    { printf("Expresion_logica -> expresion 'OPERADOR O EXCLUSIVO' expresion\n"); }
          | expresion '&' expresion                     { printf("Expresion_logica -> expresion '&' expresion\n"); }
          | expresion OPERADOR_IGUALDAD expresion       { printf("Expresion_logica -> expresion 'OPERADOR IGUALDAD' expresion\n"); }
          | expresion OPERADOR_CORRIMIENTO expresion    { printf("Expresion_logica -> expresion 'OPERADOR CORRIMIENTO' expresion\n"); }
          | expresion OPERADOR_RELACIONAL expresion     { printf("Expresion_logica -> expresion 'OPERADOR RELACIONAL' expresion\n"); }
;

expresion_prefija: expresion_postfija                       { printf("expresion_prefija -> expresion_postfija\n"); }
                  | OPERADOR_SIZEOF '(' TIPO_DATO ')'       { printf("expresion_prefija -> SIZEOF '(' TIPO_DATO ')'\n"); }
                  | OPERADOR_INCREMENTO expresion_prefija   { printf("expresion_prefija -> ++ expresion_prefija\n"); }
                  | operador_unario expresion_prefija       { printf("expresion_prefija -> operador_unario\n"); }
;

expresion_postfija: expresion_constante                    { printf("expresion_postfija -> expresion_constante\n"); }
                   | expresion_indexada                     { printf("expresion_postfija -> expresion_indexada\n"); }
                   | expresion_postfija OPERADOR_INCREMENTO { printf("expresion_postfija -> expresion_postfija ++\n"); }
;

expresion_indexada: IDENTIFICADOR { printf("expresion_indexada -> IDENTIFICADOR\n"); }
                    |
                    expresion_indexada '[' expresion ']' { printf("expresion_indexada -> expresion_indexada '[' expresion ']'\n"); }
;

expresion_constante: CONSTANTE_CADENA        { printf("expresion_constante -> CADENA\n"); }
                      | CONSTANTE_DECIMAL       { printf("expresion_constante -> DECIMAL\n"); }
                      | CONSTANTE_OCTAL         { printf("expresion_constante -> OCTAL\n"); }
                      | CONSTANTE_HEXADECIMAL   { printf("expresion_constante -> HEXADECIMAL\n"); }
                      | CONSTANTE_CARACTER      { printf("expresion_constante -> CARACTER\n"); }
                      | CONSTANTE_REAL          { printf("expresion_constante -> REAL\n"); }
                      | '(' expresion ')'       { printf("expresion_constante -> '(' expresion ')'\n"); }
;

asignacion: expresion_indexada operador_asignacion expresion { printf("asignacion -> expresion_indexada operador_asignacion expresion\n"); } 
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

/****************************** OPERADORES ************************************/

operador_unario: '&'  { printf("Operador unario  -> '&'\n"); }
                 | '*' { printf("Operador unario  -> '*'\n"); }
                 | '+' { printf("Operador unario  -> '+'\n"); }
                 | '-' { printf("Operador unario  -> '-'\n"); }
                 | '~' { printf("Operador unario  -> '~'\n"); }
                 | '!' { printf("Operador unario  -> '!'\n"); }
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