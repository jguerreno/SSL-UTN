#include <stdio.h>
#include <stdlib.h>
#include "llamadaAFuncion.h"

// Errores
//extern EstructuraErrorSemantico* listaErroresSemanticos;
// TS
extern VariableNode* listaVariables;
extern FuncionNode* listaFunciones;


void declaracionFuncionVariable(ParametroNode** listaParametros, NombreVariableNode** listaNombreDeVariables, 
                                char* tipo, char* identificadorFuncion, int* flagFuncion, int* flagVariable);
