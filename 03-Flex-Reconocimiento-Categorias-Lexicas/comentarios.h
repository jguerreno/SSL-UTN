
#define MAX_TAM_IDENTIFIER 50



typedef struct DataComentario{
    char comentario[MAX_TAM_IDENTIFIER];
} DataComentario;

typedef struct ComentarioNode{
    DataComentario data;
    struct ComentarioNode* next;
} ComentarioNode;



void pushComentario(ComentarioNode** head, char comentario[]);
DataComentario newDataComentario(char comentario[]);
void printComentarios(ComentarioNode* node, char tipo[]);
void deleteListaComentarios(ComentarioNode** head);
