
#define MAX_TAM_IDENTIFIER 50


typedef struct DataConstante{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstante;

typedef struct ComentarioNode{
    DataComentario data;
    struct ComentarioNode* next;
} ComentarioNode;



void pushComentario(ComentarioNode** head, char comentario[]);
DataComentario newDataComentario(char comentario[]);
void printComentarios(ComentarioNode* node, char tipo[]);
void deleteListaComentarios(ComentarioNode** head);
