#include <stdio.h>


typedef struct DataFuncion{
    char* funcion;
    int linea;
} DataFuncion;

typedef struct FuncionNode{
    DataFuncion data;
    struct FuncionNode* next;
} FuncionNode;

void addFuncion(FuncionNode** head, char* funcion,int linea);
void pushFuncion(FuncionNode** head, char* funcion,int linea);
DataFuncion newDataFuncion(char* funcion,int linea);
FuncionNode* searchFuncion(FuncionNode* head, char* funcion);
void printListFuncion(FILE *reporte, FuncionNode* node);
