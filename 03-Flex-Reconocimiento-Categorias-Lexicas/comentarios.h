
#define MAX_TAM_IDENTIFIER 50



typedef struct Data{
    char comentario[MAX_TAM_IDENTIFIER];
} Data;

typedef struct ComentarioNode{
    Data data;
    struct ComentarioNode* next;
} ComentarioNode;



void pushComentario(ComentarioNode** head, char comentario[]);
Data newDataIdentifier(char comentario[]);
void printComentarios(ComentarioNode* node, char tipo[]);
void deleteListaComentarios(ComentarioNode** head);
