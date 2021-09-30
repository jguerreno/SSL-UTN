#include "estructuraInvalida.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addEstructuraInvalida(EstructuraInvalidaNode** head, char estructura[]){

    EstructuraInvalidaNode* node = searchEstructuraInvalida(*head, estructura);

    if(node == NULL){
        pushEstructuraInvalida(head, estructura);
    }
}


void pushEstructuraInvalida(EstructuraInvalidaNode** head, char estructura[]){
    /* 1. allocate node */
    EstructuraInvalidaNode* new_node = (EstructuraInvalidaNode*) malloc(sizeof(EstructuraInvalidaNode));

    /* 2. put in the data  */
    new_node->data  = newDataEstructuraInvalida(estructura);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataEstructuraInvalida newDataEstructuraInvalida(char estructura[]){
    DataEstructuraInvalida data;

    strcpy(data.estructura, estructura);

    return data;
}


EstructuraInvalidaNode* searchEstructuraInvalida(EstructuraInvalidaNode* head, char estructura[]){
    EstructuraInvalidaNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.estructura, estructura)!=0){
        current = current->next;
    }

   return current;
}


void printListEstructuraInvalida(FILE *reporte, EstructuraInvalidaNode* node){

    fprintf(reporte,"-------------------- ESTRUCTURAS INVALIDAS --------------------\n");
    fprintf(reporte,"Estructura\t \t \t \n");


    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t\n", node->data.estructura);

     node = node->next;
  }

}
