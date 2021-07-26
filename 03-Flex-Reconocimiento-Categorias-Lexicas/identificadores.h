
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char identificador[MAX_TAM_IDENTIFIER];
    int repeticion;
} Data;

typedef struct IdentifierNode{
    Data data;
    struct Node* next;
} IdentifierNode;



void add(IdentifierNode** head, char identificador[]);
void push(IdentifierNode** head, char identificador[]);
Data newDataIdentifier(char identificador[]);
IdentifierNode* search(IdentifierNode* head, char identificador[]);
// Falta el sort
void printList(IdentifierNode* node);
void deleteList(IdentifierNode** head);
