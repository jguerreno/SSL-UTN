
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char palabraReservada[MAX_TAM_IDENTIFIER];
} Data;

typedef struct PalabrasReservadasNode{
    Data data;
    struct Node* next;
} PalabrasReservadasNode;



void append(PalabrasReservadasNode** head_ref, char palabraReservada[]);
Data newDataIdentifier(char palabraReservada[]);
void printList(PalabrasReservadasNode* node);
void deleteList(PalabrasReservadasNode** head);
void reportePalabrasReservadas(PalabrasReservadasNode** head,char palabraReservada[]);
