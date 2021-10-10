
#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addVariable(VariableNode** head, char* identificador,char* tipoDato,int linea){

    VariableNode* node = searchVariable(*head, identificador);

    if(node == NULL){
        pushVariable(head, identificador,tipoDato,linea);
    }
}


void pushVariable(VariableNode** head, char* identificador,char* tipoDato,int linea){
    /* 1. allocate node */
    VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

    /* 2. put in the data  */
    new_node->data  = newDataVariable(identificador,tipoDato,linea);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataVariable newDataVariable(char* identificador,char* tipoDato,int line){
    DataVariable data;

    data.identificador = strdup(identificador);
    data.tipoDato = strdup(tipoDato);
    data.linea = line;

    return data;
}


VariableNode* searchVariable(VariableNode* head, char* identificador){
    VariableNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.identificador, identificador)!=0){
        current = current->next;
    }

   return current;
}


void printListVariable(FILE *reporte, VariableNode* node){

    fprintf(reporte,"-------------------- VARIABLES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t Tipo de dato\n");


    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t%s \t \t \t %d\n", node->data.identificador, node->data.tipoDato,node->data.linea);

     node = node->next;
  }

}
