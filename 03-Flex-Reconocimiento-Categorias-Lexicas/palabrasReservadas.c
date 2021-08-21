#include "palabrasReservadas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void appendPalabraReservada(PalabrasReservadasNode** head_ref, char *palabraReservada){
    /* 1. allocate node */
    PalabrasReservadasNode* new_node = (PalabrasReservadasNode*) malloc(sizeof(PalabrasReservadasNode));

    PalabrasReservadasNode *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data = newDataPalabraReservada(palabraReservada);
    
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
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

