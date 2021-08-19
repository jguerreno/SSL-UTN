#include "identificadores.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addIdentifier(IdentifierNode** head, char identificador[]){

    IdentifierNode* node = searchIdentifier(*head, identificador);

    if(node != NULL){
        node->data.repeticion++;
    }
    else{
        pushIdentifier(head, identificador);
    }
}


void pushIdentifier(IdentifierNode** head, char identificador[]){
    /* 1. allocate node */
    IdentifierNode* new_node = (IdentifierNode*) malloc(sizeof(IdentifierNode));

    /* 2. put in the data  */
    new_node->data  = newDataIdentifier(identificador);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataIdentifier newDataIdentifier(char identificador[]){
    DataIdentifier data;

    strcpy(data.identificador, identificador);
    data.repeticion = 0;

    return data;
}


IdentifierNode* searchIdentifier(IdentifierNode* head, char identificador[]){
    IdentifierNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.identificador, identificador)!=0){
        current = current->next;
    }

   return current;
}


void printListIdentifier(IdentifierNode* node){

    printf("Identificador\tCantidad de Repeticiones\n");

    while (node != NULL){
     printf("%s\t%d\n", node->data.identificador, node->data.repeticion);

     node = node->next;
  }

}


void deleteListIdentifier(IdentifierNode** head){
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
    IdentifierNode *aux, *aux2, *temp;
    
    int mayor = 0;
    
    aux = (*head);
    
    aux2 = aux;
    
    while (aux->next != NULL)
    {
        while (aux2 != NULL)
        {
            if (aux2->data.repeticion >= mayor)
                mayor = aux2->data.repeticion;
        }
        
        aux2 = aux;
        
        while (aux2->next != NULL)
        {
            if ((aux2->next)->data.repeticion == mayor)
            {
                temp = (aux2->next)->next;
                (aux2->next)->next= aux;
                aux->next = temp;
            }
            aux2 = aux2->next;
            
        }
        aux = aux->next;
    }
}




