#include "comentariosSimples.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void push(ComentarioSmpleNode** head, char comentario[]){
    /* 1. allocate node */
    ComentarioSmpleNode* new_node = (ComentarioSmpleNode*) malloc(sizeof(ComentarioSmpleNode));

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


ComentarioSmpleNode* search(ComentarioSmpleNode* head, char comentario[]){
    ComentarioSmpleNode* current = head;  // Initialize current

    while (current != NULL || strcmp(current->data.comentario, comentario)!=0){
        current = current->next;
    }

   return current;
}


void printList(ComentarioSmpleNode* node){

    printf("Comentarios Simples\n");

    while (node != NULL){
     printf("%s\n", node->data.comentario);

     node = node->next;
  }

}


void deleteList(ComentarioSmpleNode** head){
    /* deref head_ref to get the real head */
    ComentarioSmpleNode* current = *head;
    ComentarioSmpleNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}


void sortIdentidier(ComentarioSmpleNode** head){
}


void reporteComentariosSimples(ComentarioSmpleNode** head,char comentario[]){
    push(head,comentario);
}

