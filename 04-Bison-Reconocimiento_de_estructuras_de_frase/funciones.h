#include <stdio.h>

#define MAX_TAM_IDENTIFIER 100

typedef struct DataFuncion{
    char funcion[MAX_TAM_IDENTIFIER];
} DataFuncion;

typedef struct FuncionNode{
    DataFuncion data;
    struct FuncionNode* next;
} FuncionNode;

void addFuncion(FuncionNode** head, char funcion[]);
void pushFuncion(FuncionNode** head, char funcion[]);
DataFuncion newDataFuncion(char funcion[]);
FuncionNode* searchFuncion(FuncionNode* head, char funcion[]);
void printListFuncion(FILE *reporte, FuncionNode* node);
