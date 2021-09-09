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
    data.repeticion = 1;

    return data;
}


IdentifierNode* searchIdentifier(IdentifierNode* head, char identificador[]){
    IdentifierNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.identificador, identificador)!=0){
        current = current->next;
    }

   return current;
}


void printListIdentifier(FILE *reporte, IdentifierNode* node){

    fprintf(reporte,"-------------------- IDENTIFICADORES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t Cantidad de Repeticiones\n");

    sortIdentidier(&node);


    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t%d\n", node->data.identificador, node->data.repeticion);

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
    IdentifierNode *aux1;
    IdentifierNode *aux2 = NULL;
    
    int swapped;

    /* CHECKING FOR EMPTY LIST*/
    if((*head) == NULL) return;
    
    aux1 = (*head);
    aux2 = NULL;

    do{
        swapped = 0;
        aux1 = (*head);

        while(aux1->next != aux2){
            if(strcmp(aux1->data.identificador,aux1->next->data.identificador)>0){
                swapIdentifiers(aux1,aux1->next);
                swapped = 1;
            }
            aux1 = aux1->next;
        }
        aux2 = aux1;
    }while(swapped);

}

void swapIdentifiers(IdentifierNode *a, IdentifierNode *b)
{
    int rep = a->data.repeticion;
    char id[MAX_TAM_IDENTIFIER];
    strcpy(id,a->data.identificador);
    a->data = b->data;
    b->data.repeticion = rep;
    strcpy(b->data.identificador,id);
}


/*
    
    aux2 = (*head);
    while (aux2 != NULL)
    {
        if (aux2->data.repeticion >= mayor){
            mayor = aux2->data.repeticion;
        }
        aux2 = aux2->next;
    }
    
    printf("NUMERO MAXIMO DE REPETICIONES ENCONTRADO %d",mayor);

    do{
        swapped = 0;
        aux1 = (*head);

        while(aux1->next != aux2){
            if(aux1->data.repeticion >= mayor){
                mayor = aux1->data.repeticion;
                swapIdentifiers(aux1,aux1->next);
                swapped = 1;
            }
            aux1 = aux1->next;
        }
        aux2 = aux1;
    }while(swapped);
*/

