#include <stdio.h>

#define MAX_TAM_IDENTIFIER 50

typedef struct DataConstCarac{
    char constanteCaracter;
} DataConstCarac;

typedef struct ConstCaracNode{
    DataConstCarac data;
    struct ConstCaracNode* next;
} ConstCaracNode;

void pushConstCarac(ConstCaracNode** head, char constCarac);
DataConstCarac newDataConstCarac(char constCarac);
void printConstantesCaracter(FILE *reporte, ConstCaracNode* node);
void deleteListaConstantesCaracter(ConstCaracNode** head);
