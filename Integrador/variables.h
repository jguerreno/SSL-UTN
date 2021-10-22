#include <stdio.h>
#include "funciones.h"
#include "estructuraInvalida.h"


typedef struct DataVariable{
    char* identificador;
    char* tipoDato;
    int linea;
} DataVariable;

typedef struct VariableNode{
    DataVariable data;
    struct VariableNode* next;
} VariableNode;

/*******************************************************************************************/
typedef struct DataNombreVariable{
    char* identificador;
} DataNombreVariable;

typedef struct NombreVariableNode{
    DataNombreVariable data;
    struct NombreVariableNode* next;
} NombreVariableNode;



void addVariable(VariableNode** listaVariables, FuncionNode* listaFunciones, EstructuraErrorSemantico** listaErroresSemanticos, NombreVariableNode** listaNombreVariables, char* tipoDato);
void pushVariable(VariableNode** listaVariables, char* identificador ,char* tipoDato);
DataVariable newDataVariable(char* identificador ,char* tipoDato);
VariableNode* searchVariable(VariableNode* listaVariables, char* identificador);
void printListVariable(FILE *reporte, VariableNode* listaVariables);

/*******************************************************************************************/

void pushNombreVariable(NombreVariableNode** head_ref, char* nombreVariable);
DataNombreVariable newDataNombreVariable(char* nombreVariable);
void deleteListNombreVariable(NombreVariableNode** head_ref);
