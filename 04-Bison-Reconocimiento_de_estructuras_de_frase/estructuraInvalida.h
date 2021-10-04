#include <stdio.h>


typedef struct DataEstructuraInvalida{
    char* estructura;
} DataEstructuraInvalida;

typedef struct EstructuraInvalidaNode{
    DataEstructuraInvalida data;
    struct EstructuraInvalidaNode* next;
} EstructuraInvalidaNode;

void addEstructuraInvalida(EstructuraInvalidaNode** head, char* estructura);
void pushEstructuraInvalida(EstructuraInvalidaNode** head, char* estructura);
DataEstructuraInvalida newDataEstructuraInvalida(char* estructura);
EstructuraInvalidaNode* searchEstructuraInvalida(EstructuraInvalidaNode* head, char* estructura);
void printListEstructuraInvalida(FILE *reporte, EstructuraInvalidaNode* node);
