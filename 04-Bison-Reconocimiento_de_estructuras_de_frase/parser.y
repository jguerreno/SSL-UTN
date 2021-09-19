/* Calculadora de notacion polaca inversa */

%{
#include <math.h>
#include <stdio.h>
#include <ctype.h>

int yylex();
int yyerror (char *s){printf ("%s\n", s);}
int yywrap(){return(1);}
%}

%union {
    int entero;
    float real;
    char* cadena;
}


","|"?"|":"|"("|")"|"["|"]"|"="|"{"|"}"|";"|"*"|"&"|"+"|"-"|"~"|"!" { return yytext[0]; }

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
        | exp '\n'  { printf ("\t %d\n", $1); }
;

%%

/****************************** INSTRUCCIONES ************************************/

instruccion : bloque_instrucciones { printf("instruccion -> bloque_instrucciones\n"); }
            | instruccion_expresion { printf("instruccion -> instruccion_expresion\n"); }
            | instruccion_bifurcacion { printf("instruccion -> instruccion_bifurcacion\n"); }
            | instruccion_bucle { printf("instruccion -> instruccion_bucle\n"); }
            | instruccion_salto { printf("instruccion -> instruccion_salto\n"); }
            | instruccion_destino_salto { printf("instruccion -> instruccion_destino_salto\n"); }
            | instruccion_retorno { printf("instruccion -> instruccion_retorno\n"); };

bloque_instrucciones : '{' '}' { printf("bloque_instrucciones -> '{' '}'\n"); }
                     | '{' declaracion_list '}' { printf("bloque_instrucciones -> '{' declaracion_list '}'\n"); }
                     | '{' instruccion_list '}' { printf("bloque_instrucciones -> '{' instruccion_list '}'\n"); }
                     | '{' declaracion_list instruccion_list '}' { printf("bloque_instrucciones -> '{' declaracion_list instruccion_list '}'\n"); };

declaracion_list : declaracion { printf("declaracion_list -> declaracion\n"); }
                 | declaracion declaracion_list { printf("declaracion_list -> declaracion_list declaracion\n"); };


instruccion_list : instruccion { printf("instruccion_list -> instruccion\n"); }
                 | instruccion instruccion_list { printf("instruccion_list -> instruccion_list instruccion\n"); };

instruccion_expresion : expresion ';' { printf("instruccion_expresion -> expresion ';'\n"); }
                      | asignacion ';' { printf("instruccion_expresion -> asignacion ';'\n"); }



asignacion : expresion_indexada operador_asignacion expresion { printf("asignacion -> expresion_indexada operador_asignacion expresion\n"); } ;


operador_asignacion : '=' { printf("operador_asignacion -> '='\n"); }
                    | TEQUAL { printf("operador_asignacion -> TEQUAL\n"); }
					| PEQUAL { printf("operador_asignacion -> PEQUAL\n"); }
                    | DIVEQUAL { printf("operador_asignacion -> DIVEQUAL\n"); }
                    | PLUSEQUAL { printf("operador_asignacion -> PLUSEQUAL\n"); }
                    | MINUSEQUAL { printf("operador_asignacion -> MINUSEQUAL\n"); }
                    | BYTELASSIGN { printf("operador_asignacion -> BYTELASSIGN\n"); }
                    | BYTERASSIGN { printf("operador_asignacion -> BYTERASSIGN\n"); }
                    | ANDEQUAL { printf("operador_asignacion -> ANDEQUAL\n"); }
                    | POWEQUAL { printf("operador_asignacion -> POWEQUAL\n"); }
                    | OREQUAL { printf("operador_asignacion -> OREQUAL\n"); };

instruccion_bifurcacion : IF '(' expresion ')' instruccion { printf("instruccion_bifurcacion -> IF '(' expresion ')' instruccion\n"); }
                        | IF '(' expresion ')' instruccion ELSE instruccion { printf("instruccion_bifurcacion -> IF '(' expresion ')' instruccion ELSE instruccion\n"); }
                        | SWITCH '(' expresion ')' '{' instruccion_caso_list'}' { printf("instruccion_bifurcacion -> SWITCH '(' expresion ')' '{' instruccion_caso_list'}'\n"); };

instruccion_caso_list : instruccion_caso { printf("instruccion_caso_list -> instruccion_caso\n"); }
                      | instruccion_caso instruccion_caso_list { printf("instruccion_caso_list -> instruccion_caso_list instruccion_caso\n"); } ;

instruccion_caso : CASE expresion ':' instruccion { printf("instruccion_caso -> CASE expresion ':' instruccion\n"); }
                 | DEFAULT ':' instruccion { printf("instruccion_caso -> DEFAULT ':' instruccion\n"); };

instruccion_bucle : WHILE '(' expresion ')' instruccion { printf("instruccion_bucle -> WHILE '(' expresion ')' instruccion\n"); }
                  | DO instruccion WHILE '(' expresion ')' ';' { printf("instruccion_bucle -> DO instruccion WHILE '(' expresion ')' ;\n"); }
                  | FOR '(' ';' expresion ';' expresion ')' instruccion { printf("instruccion_bucle -> FOR '(' ';' expresion ';' expresion ')' instruccion\n"); }
                  | FOR '(' lista_asignaciones ';' expresion ';' expresion ')' instruccion { printf("instruccion_bucle -> FOR '(' lista_asignaciones ';' expresion ';' expresion ')' instruccion\n"); };

lista_asignaciones : asignacion { printf("lista_asignaciones -> asignacion\n"); }
                   | asignacion ',' lista_asignaciones { printf("lista_asignaciones -> lista_asignaciones ',' asignacion\n"); } ;

instruccion_salto : GOTO IDENTIFIER ';' { printf("instruccion_salto -> GOTO IDENTIFIER ';'\n"); }
                  | CONTINUE ';' { printf("instruccion_salto -> CONTINUE ';'\n"); }
                  | BREAK ';' { printf("instruccion_salto -> BREAK ';'\n"); };

instruccion_destino_salto : IDENTIFIER ':' instruccion ';' { printf("instruccion_destino_salto -> IDENTIFIER ':' instruccion ';'\n"); };

instruccion_retorno : RETURN ';' { printf("instruccion_retorno -> RETURN ';'\n"); }
                    | RETURN expresion ';' { printf("instruccion_retorno -> RETURN expresion ';'\n"); };



int main ()
{

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif

  yyparse ();
}