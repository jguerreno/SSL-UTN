
#include "variables.h"
#include "funciones.h"
#include "estructuraInvalida.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addVariable(VariableNode** listaVariables, FuncionNode* listaFunciones, EstructuraErrorSemantico** listaErroresSemanticos, 
                NombreVariableNode** listaNombreVariables, char* tipoDato) {
    NombreVariableNode* listaAuxNombreVariables = *listaNombreVariables;

    while(listaAuxNombreVariables != NULL){
        int existenciaNombreEnVariables = searchVariable(*listaVariables, listaAuxNombreVariables->data.identificador);
        int existenciaNombreEnFunciones = searchFuncion(listaFunciones, listaAuxNombreVariables->data.identificador);

        if(existenciaNombreEnVariables==NULL && existenciaNombreEnFunciones==NULL) {
            /* 1. allocate node */
            VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

            /* 2. put in the data  */
            new_node->data  = newDataVariable(listaAuxNombreVariables->data.identificador, tipoDato);

            /* 3. Make next of new node as head */
            new_node->next = (*listaVariables);

            /* 4. move the head to point to the new node */
            (*listaVariables) = new_node;

            listaAuxNombreVariables = listaAuxNombreVariables->next;
        }
        else {
            char* errorSemantico;
            strcpy(errorSemantico,"Multiples declaraciones de ");
            strcat(errorSemantico, listaAuxNombreVariables->data.identificador);

            pushErrorSemantico(listaErroresSemanticos, errorSemantico);
        }
    }
    
    deleteListNombreVariable(listaNombreVariables);
}


void pushVariable(VariableNode** listaVariables, char* identificador ,char* tipoDato) {
    /* 1. allocate node */
    VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

    /* 2. put in the data  */
    new_node->data  = newDataVariable(identificador,tipoDato);

    /* 3. Make next of new node as head */
    new_node->next = (*listaVariables);

    /* 4. move the head to point to the new node */
    (*listaVariables)    = new_node;
}


DataVariable newDataVariable(char* identificador,char* tipoDato) {
    DataVariable data;

    data.identificador = strdup(identificador);
    data.tipoDato = strdup(tipoDato);

    return data;
}


VariableNode* searchVariable(VariableNode* listaVariables, char* identificador) {

    while (listaVariables!=NULL && strcmp(listaVariables->data.identificador, identificador)!=0){
        listaVariables = listaVariables->next;
    }

   return listaVariables;
}


void printListVariable(FILE *reporte, VariableNode* listaVariables) {

    fprintf(reporte,"-------------------- VARIABLES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t Tipo de dato\n");


    while (listaVariables != NULL) {
        fprintf(reporte,"%s\t \t \t \t \t %s \t \t \t %d\n", listaVariables->data.identificador, listaVariables->data.tipoDato);

        listaVariables = listaVariables->next;
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

