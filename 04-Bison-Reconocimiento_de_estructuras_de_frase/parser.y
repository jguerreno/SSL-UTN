
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

void yyerror (const char *s){}

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
        | error line                    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); } 
;

line:   '\n'                            {numeroDeLinea = yylineno;}
        | TIPO_DATO declaracion         {tipoDeDato = strdup($<cadena>1); addVariable(&listaVariables, &listaNombreDeVariables, $<cadena>1, yylineno); numeroDeLinea = yylineno;}
        | sentencia
        | error line                    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); } 
;


/****************************** SENTENCIAS ************************************/
sentencia: bloque_sentencias          { addSentencia(&listaSentencias, "Sentencia Compuesta", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_expresion     { addSentencia(&listaSentencias, "Sentencia Expresion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_bifurcacion   { addSentencia(&listaSentencias, "Sentencia Seleccion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_bucle         { addSentencia(&listaSentencias, "Sentencia Iteracion", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_salto         { addSentencia(&listaSentencias, "Sentencia Salto", numeroDeLinea); numeroDeLinea = yylineno;}
            | sentencia_retorno       { addSentencia(&listaSentencias, "Sentencia de Retorno", numeroDeLinea); numeroDeLinea = yylineno+1;}
            | '\n'
            | error sentencia { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

bloque_sentencias: '{' '}'
                | '{' '\n' declaracion_list {addVariable(&listaVariables, &listaNombreDeVariables, tipoDeDato, numeroDeLinea);} sentencia_list '\n' '}'       
;

declaracion_list: /* VACIO */                                           
                | TIPO_DATO declaracion {tipoDeDato = strdup($<cadena>1); addVariable(&listaVariables, &listaNombreDeVariables, tipoDeDato, numeroDeLinea); numeroDeLinea = yylineno;} '\n' declaracion_list           { tipoDeDato = strdup($<cadena>1);}
                | error declaracion_list { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;


/****************************** DECLARACIONES ************************************/
declaracion: declaracion_funcion          
            | declaracion_variables ';'   { numeroDeLinea = yylineno; }
;

declaracion_funcion: IDENTIFICADOR '(' listaParametros ')' def_dec { if(flagDeclaracionFuncion == 1){addFuncion(&listaFunciones, $<cadena>1, numeroDeLinea);flagDeclaracionFuncion=0;}}
;

def_dec: bloque_sentencias      
        | ';'                   { flagDeclaracionFuncion=1;  numeroDeLinea = yylineno;}
;

declaracion_variables: identVariable
                     | identVariable ',' declaracion_variables
;

listaParametros: /* VACIO */ 
                | TIPO_DATO IDENTIFICADOR ',' listaParametros
                | TIPO_DATO IDENTIFICADOR
;

identVariable: IDENTIFICADOR                            { pushNombreVariable(&listaNombreDeVariables, $<cadena>1);}
               | IDENTIFICADOR '=' expresion_constante  { pushNombreVariable(&listaNombreDeVariables, $<cadena>1);}
;

sentencia_list: /* VACIO */               
                | sentencia_list sentencia
                | error sentencia_list          { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

sentencia_expresion: expresion ';'     { numeroDeLinea = yylineno;}
                    | asignacion ';'   { numeroDeLinea = yylineno;}
;


/****************************** EXPRESIONES ************************************/
expresion: expresion_logica             
        | expresion_logica '?' expresion ':' expresion     
        | expresion operacion_matematica expresion       
        | llamada_funcion
;

operacion_matematica: '-'
                    | '+'
                    | '*'
                    | OPERADOR_MULTIPLICATIVO
;

expresion_logica: expresion_prefija                     
          | expresion operacion_logica expresion     
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

expresion_prefija: expresion_postfija                       
                  | OPERADOR_SIZEOF '(' TIPO_DATO ')'       
                  | OPERADOR_INCREMENTO expresion_prefija   
                  | operador_unario expresion_prefija       
;

expresion_postfija: expresion_constante
                   | expresion_indexada                     
                   | expresion_postfija OPERADOR_INCREMENTO 
;

expresion_indexada: IDENTIFICADOR 
                | expresion_indexada '[' expresion ']' 
                | expresion_indexada '.' IDENTIFICADOR 
                | expresion_indexada FLECHA IDENTIFICADOR 
;

expresion_constante: CONSTANTE_CADENA
                   | CONSTANTE_DECIMAL
                   | CONSTANTE_OCTAL
                   | CONSTANTE_HEXADECIMAL
                   | CONSTANTE_CARACTER
                   | CONSTANTE_REAL
                   | '(' expresion ')'
;

asignacion: expresion_indexada operador_asignacion expresion 
;

operador_asignacion: '='
                   | OPERADOR_ASIGNACION
;

sentencia_bifurcacion: IF '(' expresion ')' bloque_sentencias                   
                | IF '(' expresion ')' bloque_sentencias ELSE bloque_sentencias 
                | SWITCH '(' expresion ')' '{' sentencia_caso_list'}'           
;

sentencia_caso_list: /* vacio */                       
                | sentencia_caso sentencia_caso_list 
;

sentencia_caso: CASE expresion ':' sentencia   
              | DEFAULT ':' sentencia        
;

sentencia_bucle: WHILE '(' expresion ')' bloque_sentencias                                        
                | DO bloque_sentencias WHILE '(' expresion ')' ';'                             
                | FOR '(' lista_asignaciones ';' expresion ';' expresion ')' bloque_sentencias 
;

lista_asignaciones: asignacion                        
                   | asignacion ',' lista_asignaciones 
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

llamada_funcion: IDENTIFICADOR '(' parametros ')'  
;

parametros: /* VACIO */                            
        | parametro
        | parametro  ',' parametros   
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