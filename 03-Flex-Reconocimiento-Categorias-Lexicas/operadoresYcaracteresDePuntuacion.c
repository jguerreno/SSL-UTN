#include "operadoresYcaracteresDePuntuacion.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addOperadores(OperadoresNode** head, char operador){

    OperadoresNode* node = searchOperadores(*head, operador);

    if(node != NULL){
        node->data.repeticion++;
    }
    else{
        pushOperadores(head, operador);
    }
}


void pushOperadores(OperadoresNode** head, char operador){
    /* 1. allocate node */
    OperadoresNode* new_node = (OperadoresNode*) malloc(sizeof(OperadoresNode));

    /* 2. put in the data  */
    new_node->data  = newDataOperadores(operador);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataOperadores newDataOperadores(char operador){
    DataOperadores data = {operador, 1};

    return data;
}


OperadoresNode* searchOperadores(OperadoresNode* head, char operador){
    OperadoresNode* current = head;  // Initialize current

    while (current != NULL && current->data.operador != operador){
        current = current->next;
    }

   return current;
}


void printOperadores(OperadoresNode* node){

    printf("Operadores y Caracteres de Puntuacion\tCantidad de Repeticiones\n");

    while (node != NULL){
     printf("%c\t\t%d\n", node->data.operador, node->data.repeticion);

     node = node->next;
  }

}


void deleteListaOperadores(OperadoresNode** head){
    /* deref head_ref to get the real head */
    OperadoresNode* current = *head;
    OperadoresNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

