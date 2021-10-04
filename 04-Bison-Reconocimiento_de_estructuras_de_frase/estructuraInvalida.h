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

/****************************************************************************/
typedef struct DataErrorLexico{
    char* error;
} DataErrorLexico;

typedef struct EstructuraErrorLexico{
    DataErrorLexico data;
    struct EstructuraErrorLexico* next;
} EstructuraErrorLexico;

void addErrorLexico(EstructuraErrorLexico** head, char* error);
void pushErrorLexico(EstructuraErrorLexico** head, char* error);
DataErrorLexico newDataErrorLexico(char* error);
EstructuraErrorLexico* searchErrorLexico(EstructuraErrorLexico* head, char* error);
void printListErrorLexico(FILE *reporte, EstructuraErrorLexico* node);