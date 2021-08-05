
#define MAX_TAM_IDENTIFIER 50


typedef struct Data{
    char noReconocida[MAX_TAM_IDENTIFIER];
    int linea;
} Data;

typedef struct NoReconocidoNode{
    Data data;
    struct NoReconocidoNode* next;
} NoReconocidoNode;



void pushPalabraNoReconocida(NoReconocidoNode** head, char palabraNoReconocida[], int linea);
Data newDataIdentifier(char palabraNoReconocida[], int linea);
void printPalabrasNoReconocidas(NoReconocidoNode* node);
void deleteListaPalabrasNoReconocidas(NoReconocidoNode** head);
