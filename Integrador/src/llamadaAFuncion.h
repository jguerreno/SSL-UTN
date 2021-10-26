#include <stdio.h>
#include <string.h>
#include "variables.h"


// Errores
extern EstructuraErrorSemantico* listaErroresSemanticos;
// TS
extern VariableNode* listaVariables;
extern FuncionNode* listaFunciones;


void chequearLlamadaFuncion(char* identificador, ParametroNode** parametrosLlamadaFuncion);
void addParametroLlamadaFuncion(ParametroNode** parametrosLlamadaFuncion, char* identificador);
void chequearCantidadDeParametros2(ParametroNode* parametrosLlamadaFuncion, FuncionNode* existenciaFuncion);
void chequearTipoDeParametros2(ParametroNode* parametrosLlamadaFuncion, ParametroNode* existenciaFuncion, char* identificador);