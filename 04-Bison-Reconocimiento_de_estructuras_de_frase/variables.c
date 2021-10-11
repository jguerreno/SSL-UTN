
#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


/*
void addVariable(VariableNode** head, char* identificador,char* tipoDato,int linea){

    VariableNode* node = searchVariable(*head, identificador);

    if(node == NULL){
        pushVariable(head, identificador,tipoDato,linea);
    }
}
*/
void addVariable(VariableNode** head, NombreVariableNode** listaNombreVariables, char* tipoDato, int linea){
    NombreVariableNode* listaAuxNombreVariables = *listaNombreVariables;

    while(listaAuxNombreVariables != NULL){
        /* 1. allocate node */
        VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

        /* 2. put in the data  */
        new_node->data  = newDataVariable(listaAuxNombreVariables->data.identificador, tipoDato, linea);

        /* 3. Make next of new node as head */
        new_node->next = (*head);

        /* 4. move the head to point to the new node */
        (*head) = new_node;

        listaAuxNombreVariables = listaAuxNombreVariables->next;
    }
    
    deleteListNombreVariable(listaNombreVariables);
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


/*******************************************************************************************/


void pushNombreVariable(NombreVariableNode** head_ref, char* nombreVariable){
    /* 1. allocate node */
    NombreVariableNode* new_node = (NombreVariableNode*) malloc(sizeof(NombreVariableNode));

    /* 2. put in the data  */
    new_node->data  = newDataNombreVariable(nombreVariable);

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}


DataNombreVariable newDataNombreVariable(char* nombreVariable){
    DataNombreVariable data;

    data.identificador = strdup(nombreVariable);

    return data;
}


void deleteListNombreVariable(NombreVariableNode** head_ref){
   /* deref head_ref to get the real head */
   NombreVariableNode* current = *head_ref;
   NombreVariableNode* next;
 
   while (current != NULL) {
       next = current->next;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back in the caller. */
   *head_ref = NULL;
}

