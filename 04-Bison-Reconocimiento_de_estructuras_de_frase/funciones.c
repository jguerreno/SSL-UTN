#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addFuncion(FuncionNode** head, char funcion[]){

    FuncionNode* node = searchFuncion(*head, funcion);

    if(node == NULL){
        pushFuncion(head,funcion);
    }
}


void pushFuncion(FuncionNode** head, char funcion[]){
    /* 1. allocate node */
    FuncionNode* new_node = (FuncionNode*) malloc(sizeof(FuncionNode));

    /* 2. put in the data  */
    new_node->data  = newDataFuncion(funcion);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataFuncion newDataFuncion(char funcion[]){
    DataFuncion data;

    strcpy(data.funcion,funcion);

    return data;
}


FuncionNode* searchFuncion(FuncionNode* head, char funcion[]){
    FuncionNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.funcion, funcion)!=0){
        current = current->next;
    }

   return current;
}


void printListVariable(FILE *reporte, FuncionNode* node){

    fprintf(reporte,"-------------------- FUNCIONES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t \n");


    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t\n", node->data.funcion);

     node = node->next;
  }

}
