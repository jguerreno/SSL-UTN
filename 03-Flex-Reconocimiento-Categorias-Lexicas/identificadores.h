#include <stdio.h>

#define MAX_TAM_IDENTIFIER 50


typedef struct DataIdentifier{
    char identificador[MAX_TAM_IDENTIFIER];
    int repeticion;
} DataIdentifier;

typedef struct IdentifierNode{
    DataIdentifier data;
    struct IdentifierNode* next;
} IdentifierNode;



void addIdentifier(IdentifierNode** head, char identificador[]);
void pushIdentifier(IdentifierNode** head, char identificador[]);
DataIdentifier newDataIdentifier(char identificador[]);
IdentifierNode* searchIdentifier(IdentifierNode* head, char identificador[]);
void sortIdentidier(IdentifierNode** head);
void printListIdentifier(FILE *reporte, IdentifierNode* node);
void deleteListIdentifier(IdentifierNode** head);
void swapIdentifiers(IdentifierNode *a, IdentifierNode *b);
