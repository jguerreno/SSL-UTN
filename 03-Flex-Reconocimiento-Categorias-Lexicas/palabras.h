#include <stdio.h>

/**
 * PALABRAS RESERVADAS
 * **/
typedef struct DataPalabraReservada{
    char* palabraReservada;
} DataPalabraReservada;

typedef struct PalabrasReservadasNode{
    DataPalabraReservada data;
    struct PalabrasReservadasNode* next;
} PalabrasReservadasNode;

/**
 * PALABRAS NO RECONOCIDAS
 * **/
typedef struct DataPalabraNoReconocida{
    char* noReconocida;
    int linea;
} DataPalabraNoReconocida;

typedef struct NoReconocidoNode{
    DataPalabraNoReconocida data;
    struct NoReconocidoNode* next;
} NoReconocidoNode;



/**
 * FUNCIONES PALABRAS RESERVADAS
 * **/
void appendPalabraReservada(PalabrasReservadasNode** head_ref, char* palabraReservada);
DataPalabraReservada newDataPalabraReservada(char* palabraReservada);
void printPalabrasReservadas(FILE *reporte, PalabrasReservadasNode* node, char* tipo);
void deletePalabrasReservadas(PalabrasReservadasNode** head);


/**
 * FUNCIONES PALABRAS NO RECONOCIDAS
 * **/
void pushPalabraNoReconocida(NoReconocidoNode** head, char* palabraNoReconocida, int linea);
DataPalabraNoReconocida newDataPalabraNoReconocida(char* palabraNoReconocida, int linea);
void printPalabrasNoReconocidas(FILE *reporte, NoReconocidoNode* node);
void deleteListaPalabrasNoReconocidas(NoReconocidoNode** head);