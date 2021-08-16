#include "literalesCadena.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void add(LiteralCadenaNode** head, char identificador[]){

    LiteralCadenaNode* node = search(*head, identificador);

    if(node != NULL){
        node->data.repeticion++;
    }
    else{
        push(head, identificador);
    }
}


void push(LiteralCadenaNode** head, char identificador[]){
    /* 1. allocate node */
    LiteralCadenaNode* new_node = (LiteralCadenaNode*) malloc(sizeof(LiteralCadenaNode));

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


LiteralCadenaNode* search(LiteralCadenaNode* head, char identificador[]){
    LiteralCadenaNode* current = head;  // Initialize current

    while (current != NULL || strcmp(current->data.identificador, identificador)==0){
        current = current->next;
    }

   return current;
}


void printList(LiteralCadenaNode* node){

    printf("Identificador\tCantidad de Repeticiones\n");

    while (node != NULL){
     printf("%s\t%d\n", node->data.identificador, node->data.repeticion);

     node = node->next;
  }

}


void deleteList(LiteralCadenaNode** head){
    /* deref head_ref to get the real head */
    LiteralCadenaNode* current = *head;
    LiteralCadenaNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

void sortIdentidier(LiteralCadenaNode** head){

    LiteralCadenaNode *aux, *aux2, *temp, * current = *head;
    LiteralCadenaNode* next;

    int mayor = 0;
    
    aux = (*head);
    aux2 = aux;
    
    while (aux->next != NULL)
    {
        while (aux2 != NULL)
        {
            if (aux2->current >= mayor)
                mayor = aux2->current;
        }
        
        aux2 = aux;
        
        while (aux2->next != NULL)
        {
            if ((aux2->next)->current == mayor)
            {
                temp = (aux2->next)->next;
                (aux2->next)->next = aux;
                aux->next = temp;
            }
            aux2 = aux2->next;
            
        }
        aux = aux->next;
    }
}


