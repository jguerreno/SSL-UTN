#include "palabrasReservadas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void appendPalabraReservada(PalabrasReservadasNode** head_ref, char palabraReservada[]){
    /* 1. allocate node */
    PalabrasReservadasNode* new_node = (PalabrasReservadasNode*) malloc(sizeof(PalabrasReservadasNode));

    PalabrasReservadasNode *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data = newDataPalabraReservada(palabraReservada);
    //strcpy(new_node->data.palabraReservada, palabraReservada);
 
    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;
     
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
       *head_ref = new_node;
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;
  
    /* 6. Change the next of last node */
    last->next = new_node;
}

DataPalabraReservada newDataPalabraReservada(char palabraReservada[]){
    DataPalabraReservada data;

    strcpy(data.palabraReservada, palabraReservada);

    return data;
}


void printPalabrasReservadas(PalabrasReservadasNode* node){

    printf("Palabra Reservada\n");

    while (node != NULL){
     printf("%s\n", node->data.palabraReservada);

     node = node->next;
    }
}


void deletePalabrasReservadas(PalabrasReservadasNode** head){
    /* deref head_ref to get the real head */
    PalabrasReservadasNode* current = *head;
    PalabrasReservadasNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

