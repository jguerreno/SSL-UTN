#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, DataParametro* parametros){

    FuncionNode* node = searchFuncion(*head, funcion, tipoDeRetorno, parametros);

    if(node == NULL){
        pushFuncion(head,funcion, tipoDeRetorno, parametros);
    }
}


void pushFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, DataParametro* parametros){
    /* 1. allocate node */
    FuncionNode* new_node = (FuncionNode*) malloc(sizeof(FuncionNode));

    /* 2. put in the data  */
    new_node->data  = newDataFuncion(funcion, tipoDeRetorno, parametros);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataFuncion newDataFuncion(char* funcion, char* tipoDeRetorno, DataParametro* parametros){
    DataFuncion data;

    data.funcion = strdup(funcion);
    data.tipoDeRetorno = strdup(tipoDeRetorno);
    data.listaParametro = parametros;

    return data;
}


FuncionNode* searchFuncion(FuncionNode* head, char* funcion, char* tipoDeRetorno, DataParametro* parametros){
    FuncionNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.funcion, funcion)!=0){
        current = current->next;
    }

   return current;
}


void printListFuncion(FILE *reporte, FuncionNode* node){

    fprintf(reporte,"-------------------- FUNCIONES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t \n");


    while(node != NULL) {
        fprintf(reporte,"%s\t \t \t \t \t \t \t \n", node->data.funcion);

        node = node->next;
    }

    fprintf(reporte,"\n");

}

//-------------------------------------------------------------------------------//

void addParametro(ParametroNode** head, char* tipoDeDato, char* nombre){
    FuncionNode* node = searchParametro(*head, tipoDeDato, nombre);

    if(node == NULL){
        pushParametro(head,tipoDeDato,nombre);
    }
}

void pushParametro(ParametroNode** head, char* tipoDeDato, char* nombre){
    /* 1. allocate node */
    ParametroNode* new_node = (ParametroNode*) malloc(sizeof(ParametroNode));

    /* 2. put in the data  */
    new_node->data  = newDataParametro(tipoDeDato, nombre);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}

DataParametro newDataParametro(char* tipoDeDato, char* nombre){
    DataParametro data;

    data.tipoDeDato = strdup(tipoDeDato);
    data.nombre = strdup(nombre);

    return data;
}

ParametroNode* searchParametro(ParametroNode* head, char* tipoDeDato, char* nombre){
    ParametroNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.tipoDeDato, tipoDeDato)!=0){
        current = current->next;
    }

   return current;
}
void printListParametro(FILE *reporte, ParametroNode* node){
    //No encontre si lo pide o no esto
    fprintf(reporte,"-------------------- PARAMETROS --------------------\n");
    fprintf(reporte,"Identificador\t \t \t \n");


    while(node != NULL) {
        fprintf(reporte,"%s\t \t \t \t \t \t \t \n", node->data.tipoDeDato);

        node = node->next;
    }

    fprintf(reporte,"\n");
}