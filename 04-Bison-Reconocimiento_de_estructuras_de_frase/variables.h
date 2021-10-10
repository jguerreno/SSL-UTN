#include <stdio.h>

#define MAX_TAM_IDENTIFIER 100

typedef struct DataVariable{
    char* identificador;
    char* tipoDato;
    int linea;
} DataVariable;

typedef struct VariableNode{
    DataVariable data;
    struct VariableNode* next;
} VariableNode;

void addVariable(VariableNode** head, char* identificador,char* tipoDato,int linea);
void pushVariable(VariableNode** head, char* identificador ,char* tipoDato, int linea);
DataVariable newDataVariable(char* identificador ,char* tipoDato,int linea);
VariableNode* searchVariable(VariableNode* head, char* identificador);
void printListVariable(FILE *reporte, VariableNode* node);
