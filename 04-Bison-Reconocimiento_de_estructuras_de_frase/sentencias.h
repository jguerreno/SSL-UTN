#include <stdio.h>

typedef struct DataSentencias{
    char* sentencia;
    char* tipo;
} DataSentencias;

typedef struct SentenciaNode{
    DataSentencias data;
    struct SentenciaNode* next;
} SentenciaNode;

void addSentencia(SentenciaNode** head, char* sentencia ,char* tipo);
void pushSentencia(SentenciaNode** head, char* sentencia,char* tipo);
DataSentencias newDataSentencia(char* sentencia,char* tipo);
SentenciaNode* searchSentencia(SentenciaNode* head, char* sentencia);
void printListSentencia(FILE *reporte, SentenciaNode* node);
