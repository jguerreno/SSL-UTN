#include <stdio.h>

#define MAX_TAM_IDENTIFIER 100

typedef struct DataSentencias{
    char sentencia[MAX_TAM_IDENTIFIER];
    char tipo[MAX_TAM_IDENTIFIER];
} DataSentencias;

typedef struct SentenciaNode{
    DataSentencias data;
    struct SentenciaNode* next;
} SentenciaNode;

void addSentencia(SentenciaNode** head, char sentencia[] ,char tipo[]);
void pushSentencia(SentenciaNode** head, char sentencia[],char tipo[]);
DataSentencias newDataSentencia(char sentencia[],char tipo[]);
SentenciaNode* searchSentencia(SentenciaNode* head, char sentencia[]);
void printListSentencia(FILE *reporte, SentenciaNode* node);
