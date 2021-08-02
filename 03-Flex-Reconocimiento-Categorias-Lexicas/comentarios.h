
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char comentario[MAX_TAM_IDENTIFIER];
} Data;

typedef struct ComentarioNode{
    Data data;
    struct Node* next;
} ComentarioNode;



void push(ComentarioNode** head, char comentario[]);
Data newDataIdentifier(char comentario[]);
ComentarioNode* search(ComentarioNode* head, char comentario[]);
void sortIdentidier(ComentarioNode** head);
void printList(ComentarioNode* node, char tipo[]);
void deleteList(ComentarioNode** head);

void reportecomentarios(ComentarioNode** head,char comentario[]);
