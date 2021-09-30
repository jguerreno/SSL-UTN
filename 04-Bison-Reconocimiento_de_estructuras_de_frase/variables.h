#include <stdio.h>

#define MAX_TAM_IDENTIFIER 100

typedef struct DataVariable{
    char identificador[MAX_TAM_IDENTIFIER];
    char tipoDato[MAX_TAM_IDENTIFIER];
} DataVariable;

typedef struct VariableNode{
    DataVariable data;
    struct VariableNode* next;
} VariableNode;

void addVariabe(VariableNode** head, char identificador[],char tipoDato[]);
void pushVariable(VariableNode** head, char identificador[],char tipoDato[]);
DataVariable newDataVariable(char identificador[],char tipoDato[]);
VariableNode* searchVariable(VariableNode* head, char identificador[]);
void printListIdentifier(FILE *reporte, VariableNode* node);
