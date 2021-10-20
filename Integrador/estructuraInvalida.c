#include "estructuraInvalida.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void pushEstructuraInvalida(EstructuraInvalidaNode** head, int linea) {
    /* 1. allocate node */
    EstructuraInvalidaNode* new_node = (EstructuraInvalidaNode*) malloc(sizeof(EstructuraInvalidaNode));

    /* 2. put in the data  */
    new_node->data  = newDataEstructuraInvalida(linea);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataEstructuraInvalida newDataEstructuraInvalida(int line){
    DataEstructuraInvalida data = {line};
    return data;
}


void printListEstructuraInvalida(FILE *reporte, EstructuraInvalidaNode* node){

    fprintf(reporte,"-------------------- ESTRUCTURAS INVALIDAS --------------------\n");

    while (node != NULL) {
        fprintf(reporte,"Linea: \t \t \t \t \t \t %d\n", node->data.linea);
        
        node = node->next;
    }

    fprintf(reporte,"\n");
}


/****************************************************************************/


void addErrorLexico(EstructuraErrorLexico** head, char* error){

    EstructuraErrorLexico* node = searchErrorLexico(*head, error);

    if(node == NULL){
        pushErrorLexico(head, error);
    }
}

void pushErrorLexico(EstructuraErrorLexico** head, char* error){
    /* 1. allocate node */
    EstructuraErrorLexico* new_node = (EstructuraErrorLexico*) malloc(sizeof(EstructuraErrorLexico));

    /* 2. put in the data  */
    new_node->data  = newDataErrorLexico(error);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}

DataErrorLexico newDataErrorLexico(char* error){
    DataErrorLexico data;

    data.error= strdup(error);

    return data;
}

EstructuraErrorLexico* searchErrorLexico(EstructuraErrorLexico* head, char* error){
    EstructuraErrorLexico* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.error, error)!=0){
        current = current->next;
    }

   return current;
}

void printListErrorLexico(FILE *reporte, EstructuraErrorLexico* node){
    
    fprintf(reporte,"-------------------- ESTRUCTURAS INVALIDAS --------------------\n");
    fprintf(reporte,"Estructura\t \t \t \n");

    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t\n", node->data.error);

     node = node->next;
    }

    fprintf(reporte,"\n");

}


/***************************** Error Semantico ***********************************************/

void pushErrorSemantico(EstructuraErrorSemantico** head, char* error) {
    /* 1. allocate node */
    EstructuraErrorSemantico* new_node = (EstructuraErrorSemantico*) malloc(sizeof(EstructuraErrorSemantico));

    /* 2. put in the data  */
    new_node->data = newDataErrorSemantico(error);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataErrorSemantico newDataErrorSemantico(char* error) {
    DataErrorSemantico data;
    data.error = strdup(error);
    return data;
}


void printListErrorSemantico(FILE *reporte, EstructuraErrorSemantico* node) {

    fprintf(reporte,"-------------------- ERRORES SEMANTICOS --------------------\n");

    while (node != NULL){
        fprintf(reporte,"Error: \t \t %s\n", node->data.error);

        node = node->next;
    }

    fprintf(reporte,"\n");

}

