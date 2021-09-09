#include <stdio.h>


typedef struct DataConstCarac{
    char constanteCaracter;
} DataConstCarac;

typedef struct ConstCaracNode{
    DataConstCarac data;
    struct ConstCaracNode* next;
} ConstCaracNode;

void pushConstCarac(ConstCaracNode** head, char constCarac);
void appendConstantesCaracter(ConstCaracNode** head_ref, char constCarac);
DataConstCarac newDataConstCarac(char constCarac);
void printConstantesCaracter(FILE *reporte, ConstCaracNode* node);
void deleteListaConstantesCaracter(ConstCaracNode** head);
