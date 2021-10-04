#include <stdio.h>


typedef struct DataFuncion{
    char* funcion;
} DataFuncion;

typedef struct FuncionNode{
    DataFuncion data;
    struct FuncionNode* next;
} FuncionNode;

void addFuncion(FuncionNode** head, char* funcion);
void pushFuncion(FuncionNode** head, char* funcion);
DataFuncion newDataFuncion(char* funcion);
FuncionNode* searchFuncion(FuncionNode* head, char* funcion);
void printListFuncion(FILE *reporte, FuncionNode* node);
