#include <stdio.h>

typedef struct DataSentencias{
    char* tipoSentencia;
    int linea;
} DataSentencias;

typedef struct SentenciaNode{
    DataSentencias data;
    struct SentenciaNode* next;
} SentenciaNode;



void addSentencia(SentenciaNode** head, char* tipoSentencia,int linea);
void pushSentencia(SentenciaNode** head, char* tipoSentencia,int linea);
DataSentencias newDataSentencia(char* tipoSentencia,int linea);
SentenciaNode* searchSentencia(SentenciaNode* head, char* tipoSentencia);
void printListSentencia(FILE *reporte, SentenciaNode* node);
