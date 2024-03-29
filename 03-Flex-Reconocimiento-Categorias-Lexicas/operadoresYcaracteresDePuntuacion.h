#include <stdio.h>


typedef struct DataOperadores{
    char* operador;
    int repeticion;
} DataOperadores;

typedef struct OperadoresNode{
    DataOperadores data;
    struct OperadoresNode* next;
} OperadoresNode;

void addOperadores(OperadoresNode** head, char* operador);
void pushOperadores(OperadoresNode** head, char* operador);
DataOperadores newDataOperadores(char* operador);
OperadoresNode* searchOperadores(OperadoresNode* head, char* operador);
void sortOperadores(OperadoresNode** head);
void printOperadores(FILE *reporte, OperadoresNode* node);
void deleteListaOperadores(OperadoresNode** head);

