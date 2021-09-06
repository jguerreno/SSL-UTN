#include <stdio.h>

#define MAX_TAM_COMENTARIO 150

typedef struct DataComentario{
    char* comentario;
} DataComentario;

typedef struct ComentarioNode{
    DataComentario data;
    struct ComentarioNode* next;
} ComentarioNode;



void pushComentario(ComentarioNode** head, char* comentario);
DataComentario newDataComentario(char* comentario);
void printComentarios(FILE *reporte, ComentarioNode* node, char tipo[]);
void deleteListaComentarios(ComentarioNode** head);
