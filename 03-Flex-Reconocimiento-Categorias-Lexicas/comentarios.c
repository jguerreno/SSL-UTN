#include "comentarios.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void pushComentario(ComentarioNode** head, char comentario[]){
    /* 1. allocate node */
    ComentarioNode* new_node = (ComentarioNode*) malloc(sizeof(ComentarioNode));

    /* 2. put in the data  */
    new_node->data  = newDataIdentifier(comentario);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


Data newDataIdentifier(char comentario[]){
    Data data;

    strcpy(data.comentario, comentario);

    return data;
}


void printComentarios(ComentarioNode* node, char tipo[]){

    printf("Comentarios %s\n", tipo);

    while (node != NULL){
     printf("%s\n", node->data.comentario);

     node = node->next;
  }

}


void deleteListaComentarios(ComentarioNode** head){
    /* deref head_ref to get the real head */
    ComentarioNode* current = *head;
    ComentarioNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

