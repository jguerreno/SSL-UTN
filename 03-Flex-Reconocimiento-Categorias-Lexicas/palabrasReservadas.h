
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char palabraReservada[MAX_TAM_IDENTIFIER];
} Data;

typedef struct PalabrasReservadasNode{
    Data data;
    struct Node* next;
} PalabrasReservadasNode;



void add(PalabrasReservadasNode** head, char palabraReservada[]);
void push(PalabrasReservadasNode** head, char palabraReservada[]);
Data newDataIdentifier(char palabraReservada[]);
PalabrasReservadasNode* search(PalabrasReservadasNode* head, char palabraReservada[]);
void sortIdentidier(PalabrasReservadasNode** head);
void printList(PalabrasReservadasNode* node);
void deleteList(PalabrasReservadasNode** head);

void reportePalabrasReservadas(PalabrasReservadasNode** head,char palabraReservada[]);
