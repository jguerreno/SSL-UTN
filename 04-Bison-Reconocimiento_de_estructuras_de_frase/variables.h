#include <stdio.h>

#define MAX_TAM_IDENTIFIER 100

typedef struct DataVariable{
    char* identificador;
    char* tipoDato;
} DataVariable;

typedef struct VariableNode{
    DataVariable data;
    struct VariableNode* next;
} VariableNode;

void addVariable(VariableNode** head, char* identificador,char* tipoDato );
void pushVariable(VariableNode** head, char* identificador ,char* tipoDato );
DataVariable newDataVariable(char* identificador ,char* tipoDato);
VariableNode* searchVariable(VariableNode* head, char* identificador);
void printListVariable(FILE *reporte, VariableNode* node);
