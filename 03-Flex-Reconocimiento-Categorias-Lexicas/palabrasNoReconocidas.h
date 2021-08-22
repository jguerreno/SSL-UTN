#include <stdio.h>

#define MAX_TAM_IDENTIFIER 50

typedef struct DataPalabraNoReconocida{
    char noReconocida[MAX_TAM_IDENTIFIER];
    int linea;
} DataPalabraNoReconocida;

typedef struct NoReconocidoNode{
    DataPalabraNoReconocida data;
    struct NoReconocidoNode* next;
} NoReconocidoNode;



void pushPalabraNoReconocida(NoReconocidoNode** head, char palabraNoReconocida[], int linea);
DataPalabraNoReconocida newDataPalabraNoReconocida(char palabraNoReconocida[], int linea);
void printPalabrasNoReconocidas(FILE *reporte, NoReconocidoNode* node);
void deleteListaPalabrasNoReconocidas(NoReconocidoNode** head);
