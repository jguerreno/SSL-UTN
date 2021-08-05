
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char palabraReservada[MAX_TAM_IDENTIFIER];
} Data;

typedef struct PalabrasReservadasNode{
    Data data;
    struct PalabrasReservadasNode* next;
} PalabrasReservadasNode;



void append(PalabrasReservadasNode** head_ref, char palabraReservada[]);
Data newDataIdentifier(char palabraReservada[]);
void printPalabrasReservadas(PalabrasReservadasNode* node);
void deletePalabrasReservadas(PalabrasReservadasNode** head);
