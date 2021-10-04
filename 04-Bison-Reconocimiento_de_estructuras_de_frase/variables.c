/**
 * Lista de librerias a realizar/trabajar
 * 
 * 1. Listado de variables declaradas con tipo de dato
 * 
 * 2. Listado de funciones declaradas
 * 
 * 3. Listado de tipos de sentencias encontradas
 * 
 * 4. Listado de  secuencias y/o estructuras invalidas
 * */

#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addVariable(VariableNode** head, char* identificador,char* tipoDato){

    VariableNode* node = searchVariable(*head, identificador);

    if(node == NULL){
        pushVariable(head, identificador,tipoDato);
    }
}


void pushVariable(VariableNode** head, char* identificador,char* tipoDato ){
    /* 1. allocate node */
    VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

    /* 2. put in the data  */
    new_node->data  = newDataVariable(identificador,tipoDato);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataVariable newDataVariable(char* identificador,char* tipoDato){
    DataVariable data;

    data.identificador = strdup(identificador);
    data.tipoDato = strdup(tipoDato);

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
     fprintf(reporte,"%s\t \t \t \t \t \t \t%s\n", node->data.identificador, node->data.tipoDato);

     node = node->next;
  }

}
