#include <stdio.h>


typedef struct DataPalabraReservada{
    char* palabraReservada;
} DataPalabraReservada;

typedef struct PalabrasReservadasNode{
    DataPalabraReservada data;
    struct PalabrasReservadasNode* next;
} PalabrasReservadasNode;


void appendPalabraReservada(PalabrasReservadasNode** head_ref, char* palabraReservada);
DataPalabraReservada newDataPalabraReservada(char* palabraReservada);
void printPalabrasReservadas(FILE *reporte, PalabrasReservadasNode* node);
void deletePalabrasReservadas(PalabrasReservadasNode** head);
