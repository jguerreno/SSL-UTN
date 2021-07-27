
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char comentario[MAX_TAM_IDENTIFIER];
} Data;

typedef struct ComentarioSmpleNode{
    Data data;
    struct Node* next;
} ComentarioSmpleNode;



void push(ComentarioSmpleNode** head, char comentario[]);
Data newDataIdentifier(char comentario[]);
ComentarioSmpleNode* search(ComentarioSmpleNode* head, char comentario[]);
void sortIdentidier(ComentarioSmpleNode** head);
void printList(ComentarioSmpleNode* node);
void deleteList(ComentarioSmpleNode** head);

void reportecomentarios(ComentarioSmpleNode** head,char comentario[]);
