
#define MAX_TAM_IDENTIFIER 50
typedef struct DataPalabraReservada{
    char palabraReservada[MAX_TAM_IDENTIFIER];
} DataPalabraReservada;

typedef struct PalabrasReservadasNode{
    DataPalabraReservada data;
    struct PalabrasReservadasNode* next;
} PalabrasReservadasNode;

void appendPalabraReservada(PalabrasReservadasNode** head_ref, char palabraReservada[]);
DataPalabraReservada newDataPalabraReservada(char palabraReservada[]);
void printPalabrasReservadas(PalabrasReservadasNode* node);
void deletePalabrasReservadas(PalabrasReservadasNode** head);
