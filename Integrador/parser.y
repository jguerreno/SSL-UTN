
%{

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include"variables.h"
#include"sentencias.h"


#define YYDEBUG 1


int yylex(void);
extern int yylineno;
extern FILE *yyin;

int yyerror (const char *s){
    printf("-------- ERRROR ---------\n");
    printf ("%s %d\n", s,yylineno);
    return -1;
}


//
EstructuraInvalidaNode* listaErroresSintacticos = NULL;

// 
SentenciaNode* listaSentencias = NULL;



// Errores Lexicos
EstructuraErrorLexico* listaErroresLexicos = NULL;

// Errores Semanticos
EstructuraErrorSemantico* listaErroresSemanticos = NULL;

// TS Variables
VariableNode* listaVariables = NULL;
// Aulxiliar
NombreVariableNode* listaNombreDeVariables = NULL;
//char* tipoDeDato = NULL;
int flagDeclaracionVariables = 0;

// TS Funciones
FuncionNode* listaFunciones = NULL;
// Auxiliares
ParametroNode* listaParametros = NULL;
//char* tipoDeRetorno = NULL;
char* identificadorFuncion = NULL;
int flagDeclaracionFuncion = 0;

// Auxiliar para funciones y variables
char* tipo = NULL;

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

line:   '\n'                        
        | TIPO_DATO declaracion     { addVariable(&listaVariables, listaFunciones, &listaNombreDeVariables, $<cadena>1);} // Funcion con los flags con todos los parametros
        | sentencia
;


/****************************** SENTENCIAS ************************************/
sentencia: bloque_sentencias            { addSentencia(&listaSentencias, "Sentencia Compuesta")}
         | sentencia_expresion          { addSentencia(&listaSentencias, "Sentencia Expresion")}
         | sentencia_bifurcacion        { addSentencia(&listaSentencias, "Sentencia Seleccion")}
         | sentencia_bucle              { addSentencia(&listaSentencias, "Sentencia Iteracion")}
         | sentencia_salto              { addSentencia(&listaSentencias, "Sentencia Salto")}
         | sentencia_retorno            { addSentencia(&listaSentencias, "Sentencia de Retorno")}
         | '\n'
         | error sentencia              { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

bloque_sentencias: '{' '}'                                                
                | '{' '\n' declaracion_list { addVariable(&listaVariables, listaFunciones, &listaNombreDeVariables, tipo); } sentencia_list '\n' '}'     
                | error {pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1);} declaracion_list { addVariable(&listaVariables, listaFunciones, &listaNombreDeVariables, $<cadena>1); } sentencia_list '\n' '}'
                | error sentencia_list '\n' '}'        { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
                | error '}'        { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); }
;

declaracion_list: /* VACIO */                                          
                | TIPO_DATO declaracion { addVariable(&listaVariables, listaFunciones, &listaNombreDeVariables, $<cadena>1); } '\n' declaracion_list           { tipo = strdup($<cadena>1); }
;


/****************************** DECLARACIONES ************************************/
declaracion: declaracion_funcion
            | declaracion_variables ';'   
;

declaracion_funcion: IDENTIFICADOR '(' listaParametros ')' def_dec {if(flagDeclaracionFuncion == 1){addFuncion(&listaFunciones, $<cadena>1, tipo, &listaParametros);flagDeclaracionFuncion=0;}}
;

def_dec: bloque_sentencias      
        | ';'                   { flagDeclaracionFuncion=1;}
;

declaracion_variables: identVariable
                     | identVariable ',' declaracion_variables
;

listaParametros: /* VACIO */ 
                | TIPO_DATO IDENTIFICADOR ',' listaParametros   //{ pushParametro(&listaParametros, $<char>1, $<char>2);}
                | TIPO_DATO IDENTIFICADOR                       //{ pushParametro(&listaParametros, $<char>1, $<char>2);}
;

identVariable: IDENTIFICADOR                            { pushNombreVariable(&listaNombreDeVariables, $<cadena>1); }
               | IDENTIFICADOR '=' expresion_constante  { pushNombreVariable(&listaNombreDeVariables, $<cadena>1); }
;

sentencia_list: /* VACIO */                  
                | sentencia_list sentencia 
;

sentencia_expresion: expresion ';'     
                    | asignacion ';'  
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
    printListSentencia(reporte, listaSentencias);
    // Errores
    printListErrorLexico(reporte, listaErroresLexicos);
    printListEstructuraInvalida(reporte, listaErroresSintacticos);
    printListErrorSemantico(reporte, listaErroresSemanticos);

    fclose(reporte);
}


// Mirar
// Sentencias           X
// Variables            
// Funciones            

// Errores
// Lexicos              X
// Sintacticos          
// Semanticos           
//      Variables       
//      Funciones       
//      OB              