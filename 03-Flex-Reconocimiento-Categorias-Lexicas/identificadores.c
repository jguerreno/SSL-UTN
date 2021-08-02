#include "identificadores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void add(IdentifierNode** head, char identificador[]){

    IdentifierNode* node = search(*head, identificador);

    if(node != NULL){
        node->data.repeticion++;
    }
    else{
        push(head, identificador);
    }
}


void push(IdentifierNode** head, char identificador[]){
    /* 1. allocate node */
    IdentifierNode* new_node = (IdentifierNode*) malloc(sizeof(IdentifierNode));

    /* 2. put in the data  */
    new_node->data  = newDataIdentifier(identificador);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


Data newDataIdentifier(char identificador[]){
    Data data;

    strcpy(data.identificador, identificador);
    data.repeticion = 0;

    return data;
}


IdentifierNode* search(IdentifierNode* head, char identificador[]){
    IdentifierNode* current = head;  // Initialize current

    while (current != NULL || strcmp(current->data.identificador, identificador)!=0){
        current = current->next;
    }

   return current;
}


void printList(IdentifierNode* node){

    printf("Identificador\tCantidad de Repeticiones\n");

    while (node != NULL){
     printf("%s\t%d\n", node->data.identificador, node->data.repeticion);

     node = node->next;
  }

}


void deleteList(IdentifierNode** head){
    /* deref head_ref to get the real head */
    IdentifierNode* current = *head;
    IdentifierNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}


void sortIdentidier(IdentifierNode** head){
}


void reporteIdentificadores(IdentifierNode** head,char identificador[]){
    add(head,identificador);
}

