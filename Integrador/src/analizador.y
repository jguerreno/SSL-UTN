%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "lib.h"
#include"sentencias.h"


#define YYDEBUG 1

int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror (const char *s) {}

//
EstructuraInvalidaNode* listaErroresSintacticos = NULL;

// Errores Lexicos
EstructuraErrorLexico* listaErroresLexicos = NULL;

// Errores Semanticos
EstructuraErrorSemantico* listaErroresSemanticos = NULL;

// TS Variables
VariableNode* listaVariables = NULL;
// Aulxiliar
NombreVariableNode* listaNombreDeVariables = NULL;
int flagVariable = 0;

// TS Funciones
FuncionNode* listaFunciones = NULL;
// Auxiliares
ParametroNode* listaParametros = NULL;
char* identificadorFuncion = NULL;
int flagFuncion = 0;

// Auxiliar para funciones y variables
char* tipo = NULL;

// Llamada a Funciones
ParametroNode* parametrosLlamadaFuncion = NULL;

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
%left OPERADOR_O_INCLUSIVO
%left '&'
%left OPERADOR_RELACIONAL
%left OPERADOR_CORRIMIENTO
%left '-' '+'
%left '*' OPERADOR_MULTIPLICATIVO
%right OPERADOR_INCREMENTO OPERADOR_SIZEOF
%left ')'
%right '('

%%
input: /* vacio */
     | input line
     | error line                    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); } 
;

line: '\n'                        
    | TIPO_DATO declaracion         { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, $<cadena>1, identificadorFuncion, &flagFuncion, &flagVariable);}
    | sentencia
    | error line                    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); } 

;

/****************************** SENTENCIAS ************************************/
sentencia: bloque_sentencias           
         | sentencia_expresion          
         | sentencia_bifurcacion       
         | sentencia_bucle              
         | sentencia_salto             
         | sentencia_retorno           
         | '\n'
         | error sentencia { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }

;

bloque_sentencias: '{' '}'                                                
                 | '{' '\n' declaracion_list { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, tipo, identificadorFuncion, &flagFuncion, &flagVariable); } sentencia_list '\n' '}'     
;

declaracion_list: /* VACIO */                                          
                | TIPO_DATO declaracion     { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, $<cadena>1, identificadorFuncion, &flagFuncion, &flagVariable); } '\n' declaracion_list           { tipo = strdup($<cadena>1); }
                | error declaracion_list    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

/****************************** DECLARACIONES ************************************/
declaracion: declaracion_funcion
           | declaracion_variables ';'   {flagVariable = 1;}
;

declaracion_funcion: IDENTIFICADOR '(' listaParametros ')' def_dec  { identificadorFuncion = strdup($<cadena>1); }
;

def_dec: bloque_sentencias      
       | ';'                   { flagFuncion = 1;}
;

declaracion_variables: identVariable
                     | identVariable ',' declaracion_variables
;

listaParametros: /* VACIO */ 
               | TIPO_DATO IDENTIFICADOR ',' listaParametros           { pushParametro(&listaParametros, $<cadena>1, $<cadena>2);}
               | TIPO_DATO IDENTIFICADOR                               { pushParametro(&listaParametros, $<cadena>1, $<cadena>2);}
;

identVariable: IDENTIFICADOR                            { pushNombreVariable(&listaNombreDeVariables, $<cadena>1); }
             | IDENTIFICADOR '=' expresion_constante    { pushNombreVariable(&listaNombreDeVariables, $<cadena>1); }
;

sentencia_list: /* VACIO */                  
              | sentencia_list sentencia 
              | error sentencia_list          { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
            
;

sentencia_expresion: expresion ';'     
                   | asignacion ';'  
;

/****************************** EXPRESIONES ************************************/
expresion: expresion_logica                                
         | expresion_logica '?' expresion ':' expresion    
         | expresion operacion_matematica expresion         //{validacionOperacionBinaria(expresionVal1,expresionVal2); validacionBinaria=0;}
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

expresion_constante: CONSTANTE_CADENA           //{if(validacionBinario==0){expresionVal1=strudup($<cadena>1);validacionBinario=1;}else{expresionVal2=strudup($<cadena>1);;validacionBinario=0;// todo esto iria dentro de una funcion}}
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

sentencia_salto: CONTINUE ';'                   
               | BREAK ';'                      
;

sentencia_retorno: RETURN ';'                   
                 | RETURN expresion ';'         
;

operador_unario: '&'  
               | '*' 
               | '+' 
               | '-' 
               | '~' 
               | '!' 
;

llamada_funcion: IDENTIFICADOR '(' parametros ')'       { chequearLlamadaFuncion($<cadena>1, &parametrosLlamadaFuncion);}
;

parametros: /* VACIO */                          
          | IDENTIFICADOR                                     { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, $<cadena>1);}
          | IDENTIFICADOR  ',' parametros                     { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, $<cadena>1);}
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

    // Errores
    printListErrorLexico(reporte, listaErroresLexicos);
    printListEstructuraInvalida(reporte, listaErroresSintacticos);
    printListErrorSemantico(reporte, listaErroresSemanticos);

    fclose(reporte);
}
