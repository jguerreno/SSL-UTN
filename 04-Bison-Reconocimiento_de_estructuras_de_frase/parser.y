
%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include"funciones.h"
#include"variables.h"
#include"estructuraInvalida.h"
#include"sentencias.h"


#define YYDEBUG 1

/** VARIABLES GLOBALES **/
int flag_error=0;
int contador=0;
char* tipo;
/** VARIABLES GLOBALES **/

int yylex(void);
extern int yylineno;

int yyerror (const char *s){
    printf("-------- ERRROR ---------\n");
    printf ("%s %d\n", s,yylineno);
    return -1;
}

extern FILE *yyin;

FuncionNode* listaFunciones = NULL;
int flagDeclaracionFuncion = 0;

VariableNode* listaVariables = NULL;
char* tipoDeDato = NULL;
char *errorN = NULL;

//
EstructuraInvalidaNode* listaErroresSintacticos = NULL;

//
EstructuraErrorLexico* listaErroresLexicos = NULL;

// 
NombreVariableNode* listaNombreDeVariables = NULL;

SentenciaNode* listaSentencias = NULL;

int numeroDeLinea = 0;
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
%token <cadena> FLECHA

// Identificador
%token <cadena> IDENTIFICADOR

// Constantes
%token <cadena> CONSTANTE_CADENA
%token <entero> CONSTANTE_DECIMAL
%token <entero> CONSTANTE_OCTAL
%token <entero> CONSTANTE_HEXADECIMAL
%token <entero> CONSTANTE_CARACTER
%token <real>   CONSTANTE_REAL

//ERROR
%token <cadena> error

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
        | error linea                    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); } 
;

line:   '\n'                        {numeroDeLinea = yylineno;}
        | TIPO_DATO declaracion     {tipoDeDato = strdup($<cadena>1); addVariable(&listaVariables, &listaNombreDeVariables, $<cadena>1, yylineno); numeroDeLinea = yylineno;}
        | sentencia
;


/****************************** SENTENCIAS ************************************/
sentencia: bloque_sentencias          { printf("sentencia -> bloque_sentencias\n");      addSentencia(&listaSentencias, "Sentencia Compuesta", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_expresion     { printf("sentencia -> sentencia_expresion\n");    addSentencia(&listaSentencias, "Sentencia Expresion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_bifurcacion   { printf("sentencia -> sentencia_bifurcacion\n");  addSentencia(&listaSentencias, "Sentencia Seleccion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_bucle         { printf("sentencia -> sentencia_bucle\n");        addSentencia(&listaSentencias, "Sentencia Iteracion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_salto         { printf("sentencia -> sentencia_salto\n");        addSentencia(&listaSentencias, "Sentencia Salto", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_retorno       { printf("sentencia -> sentencia_retorno\n");      addSentencia(&listaSentencias, "Sentencia de Retorno", numeroDeLinea); numeroDeLinea = yylineno+1;}
            | '\n'
            | error sentencia { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

bloque_sentencias: '{' '}'                                                 { printf("bloque_sentencias -> '{' '}'\n"); }
                | '{' '\n' declaracion_list {addVariable(&listaVariables, &listaNombreDeVariables, tipoDeDato, numeroDeLinea);} sentencia_list '\n' '}'        { printf("bloque_sentencias -> '{' declaracion_list sentencia_list '}'\n"); }
                | error {pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1);} declaracion_list {addVariable(&listaVariables, &listaNombreDeVariables, tipoDeDato, numeroDeLinea);} sentencia_list '\n' '}'
                | error sentencia_list '\n' '}'        { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
                | error '}'        { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

declaracion_list: /* VACIO */                                           { printf("declaracion_list -> declaracion\n"); }
                | TIPO_DATO declaracion {tipoDeDato = strdup($<cadena>1); addVariable(&listaVariables, &listaNombreDeVariables, tipoDeDato, numeroDeLinea); numeroDeLinea = yylineno;} '\n' declaracion_list           { printf("declaracion_list -> declaracion_list declaracion\n");  tipoDeDato = strdup($<cadena>1);}
;


/****************************** DECLARACIONES ************************************/
declaracion: declaracion_funcion          { printf("declaracion -> declaracion\n"); }
            | declaracion_variables ';'   { numeroDeLinea = yylineno; }
;

declaracion_funcion: IDENTIFICADOR '(' listaParametros ')' def_dec { printf("declaracion_funciones -> declaracion funciones\n"); if(flagDeclaracionFuncion == 1){addFuncion(&listaFunciones, $<cadena>1, numeroDeLinea);flagDeclaracionFuncion=0;}}
;

def_dec: bloque_sentencias      { printf("funciones 1\n"); }
        | ';'                   { printf("funciones 2\n"); flagDeclaracionFuncion=1;  numeroDeLinea = yylineno;}
;

declaracion_variables: identVariable
                     | identVariable ',' declaracion_variables
;

listaParametros: /* VACIO */ 
                | TIPO_DATO IDENTIFICADOR ',' listaParametros
                | TIPO_DATO IDENTIFICADOR
;

identVariable: IDENTIFICADOR                            {printf("identificador"); pushNombreVariable(&listaNombreDeVariables, $<cadena>1);}
               | IDENTIFICADOR '=' expresion_constante  {printf("identificador ="); pushNombreVariable(&listaNombreDeVariables, $<cadena>1);}
;

sentencia_list: /* VACIO */                  { printf("sentencia_list -> sentencia\n"); }
                | sentencia_list sentencia { printf("sentencia_list -> sentencia_list sentencia\n"); }
;

sentencia_expresion: expresion ';'     { printf("sentencia_expresion -> expresion ';'\n"); numeroDeLinea = yylineno;}
                    | asignacion ';'   { printf("sentencia_expresion -> asignacion ';'\n"); numeroDeLinea = yylineno;}
;


/****************************** EXPRESIONES ************************************/
expresion: expresion_logica                                 { printf("Expresion  -> expresion_logica\n"); }
        | expresion_logica '?' expresion ':' expresion     { printf("Expresion  -> expresion_logica '?' expresion ':' expresion \n"); }
        | expresion operacion_matematica expresion                          { printf("Expresion_logica -> expresion '-' expresion\n"); }
        | llamada_funcion
;

operacion_matematica: '-'
                    | '+'
                    | '*'
                    | OPERADOR_MULTIPLICATIVO
;

expresion_logica: expresion_prefija                     { printf("Expresion_logica -> expresion_prefija \n"); }
          | expresion operacion_logica expresion     { printf("Expresion_logica -> expresion 'OPERADOR DE ASIGNACION' expresion \n"); }
;

operacion_logica: OPERADOR_ASIGNACION
                | OPERADOR_O_LOGICO
                | OPERADOR_Y_LOGICO
                | OPERADOR_O_INCLUSIVO
                | OPERADOR_O_EXCLUSIVO
                | '&'
                | OPERADOR_IGUALDAD
                | OPERADOR_CORRIMIENTO
                | OPERADOR_RELACIONAL
;

expresion_prefija: expresion_postfija                       { printf("expresion_prefija -> expresion_postfija\n"); }
                  | OPERADOR_SIZEOF '(' TIPO_DATO ')'       { printf("expresion_prefija -> SIZEOF '(' TIPO_DATO ')'\n"); }
                  | OPERADOR_INCREMENTO expresion_prefija   { printf("expresion_prefija -> ++ expresion_prefija\n"); }
                  | operador_unario expresion_prefija       { printf("expresion_prefija -> operador_unario\n"); }
;

expresion_postfija: expresion_constante
                   | expresion_indexada                     { printf("expresion_postfija -> expresion_indexada\n"); }
                   | expresion_postfija OPERADOR_INCREMENTO { printf("expresion_postfija -> expresion_postfija ++\n"); }
;

expresion_indexada: IDENTIFICADOR { printf("expresion_indexada -> IDENTIFICADOR\n"); }
                | expresion_indexada '[' expresion ']' { printf("expresion_indexada -> expresion_indexada '[' expresion ']'\n"); }
                | expresion_indexada '.' IDENTIFICADOR { printf("expresion_indexada -> expresion_indexada '.' IDENTIFIER\n"); }
                | expresion_indexada FLECHA IDENTIFICADOR { printf("expresion_indexada -> expresion_indexada ARROW IDENTIFIER\n"); };
;

expresion_constante: CONSTANTE_CADENA
                   | CONSTANTE_DECIMAL
                   | CONSTANTE_OCTAL
                   | CONSTANTE_HEXADECIMAL
                   | CONSTANTE_CARACTER
                   | CONSTANTE_REAL
                   | '(' expresion ')'
;

asignacion: expresion_indexada operador_asignacion expresion { printf("asignacion -> expresion_indexada operador_asignacion expresion\n"); } 
;

operador_asignacion: '='
                   | OPERADOR_ASIGNACION
;

sentencia_bifurcacion: IF '(' expresion ')' bloque_sentencias                   { printf("instruccion_bifurcacion -> IF '(' expresion ')' instruccion\n"); }
                | IF '(' expresion ')' bloque_sentencias ELSE bloque_sentencias { printf("instruccion_bifurcacion -> IF '(' expresion ')' instruccion ELSE instruccion\n"); }
                | SWITCH '(' expresion ')' '{' sentencia_caso_list'}'           { printf("sentencia_bifurcacion -> SWITCH '(' expresion ')' '{' sentencia_caso_list'}'\n"); }
;

sentencia_caso_list: /* vacio */                       { printf("sentencia_caso_list -> sentencia_caso\n"); }
                | sentencia_caso sentencia_caso_list { printf("sentencia_caso_list -> sentencia_caso_list sentencia_caso\n"); }
;

sentencia_caso: CASE expresion ':' sentencia   { printf("sentencia_caso -> CASE expresion ':' sentencia\n"); }
              | DEFAULT ':' sentencia        { printf("sentencia_caso -> DEFAULT ':' sentencia\n"); }
;

sentencia_bucle: WHILE '(' expresion ')' bloque_sentencias                                        { printf("sentencia_bucle -> WHILE '(' expresion ')' sentencia\n"); }
                | DO bloque_sentencias WHILE '(' expresion ')' ';'                             { printf("sentencia_bucle -> DO sentencia WHILE '(' expresion ')' ;\n"); }
                | FOR '(' lista_asignaciones ';' expresion ';' expresion ')' bloque_sentencias  { printf("sentencia_bucle -> FOR '(' lista_asignaciones ';' expresion ';' expresion ')' sentencia\n"); }
;

lista_asignaciones: asignacion                        { printf("lista_asignaciones -> asignacion\n"); }
                   | asignacion ',' lista_asignaciones { printf("lista_asignaciones -> lista_asignaciones ',' asignacion\n"); } 
;

sentencia_salto: CONTINUE ';'                   {numeroDeLinea = yylineno;}
               | BREAK ';'                      {numeroDeLinea = yylineno;}
;

sentencia_retorno: RETURN ';'                   {numeroDeLinea = yylineno;}
                 | RETURN expresion ';'         {numeroDeLinea = yylineno;}
;

operador_unario: '&'  
                | '*' 
                | '+' 
                | '-' 
                | '~' 
                | '!' 
;

llamada_funcion: IDENTIFICADOR '(' parametros ')'  { printf("llamada_funcion -> call\n"); }
;

parametros: /* VACIO */                            { printf("Parametros -> no hay\n"); }
        | parametro
        | parametro  ',' parametros   { printf("Parametros -> parametros\n"); }
;

parametro: expresion_indexada
        | expresion_constante
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


    // Reporte
    FILE* reporte = fopen("reporte.txt","w+b");

    printListFuncion(reporte, listaFunciones);
    printListVariable(reporte, listaVariables);
    printListErrorLexico(reporte, listaErroresLexicos);
    printListSentencia(reporte, listaSentencias);
    printListEstructuraInvalida(reporte, listaErroresSintacticos);

    fclose(reporte);
}