#include <stdio.h>

#define MAX_TAM_IDENTIFIER 50


typedef struct DataLiteralCadena{
    char cadenaLiteral[MAX_TAM_IDENTIFIER];
    int longitud;
} DataLiteralCadena;

typedef struct LiteralCadenaNode{
    DataLiteralCadena data;
    struct LiteralCadenaNode* next;
} LiteralCadenaNode;



void addLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[], int longitudCadenaLiteral);
void pushLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[], int longitudCadenaLiteral);
DataLiteralCadena newDataLiteralCadena(char cadenaLiteral[], int longitudCadenaLiteral);
LiteralCadenaNode* searchLiteralCadena(LiteralCadenaNode* head, char cadenaLiteral[], int longitudCadenaLiteral);
void sortLiteralCadena(LiteralCadenaNode** head);
void printListLiteralCadena(FILE *reporte, LiteralCadenaNode* node);
void deleteListLiteralCadena(LiteralCadenaNode** head);

