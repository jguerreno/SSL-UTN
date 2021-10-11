#include "estructuraInvalida.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addEstructuraInvalida(EstructuraInvalidaNode** head, char estructura[],int linea){

    EstructuraInvalidaNode* node = searchEstructuraInvalida(*head, estructura);

    if(node == NULL){
        pushEstructuraInvalida(head, estructura,linea);
    }
}


void pushEstructuraInvalida(EstructuraInvalidaNode** head, char estructura[],int linea){
    /* 1. allocate node */
    EstructuraInvalidaNode* new_node = (EstructuraInvalidaNode*) malloc(sizeof(EstructuraInvalidaNode));

    /* 2. put in the data  */
    new_node->data  = newDataEstructuraInvalida(estructura,linea);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataEstructuraInvalida newDataEstructuraInvalida(char estructura[],int line){
    DataEstructuraInvalida data;

    strcpy(data.estructura, estructura);
    data.linea = line;

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
     fprintf(reporte,"%s\t \t \t \t \t \t \t %d\n", node->data.estructura,node->data.linea);

     node = node->next;
  }

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
}