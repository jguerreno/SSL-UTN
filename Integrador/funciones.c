#include "funciones.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, ParametroNode** parametros) {

    FuncionNode* node = searchFuncion(*head, funcion); // Solo vamos a contemplar el nombre, no la sobrecarga

    if(node == NULL){
        pushFuncion(head, funcion, tipoDeRetorno, *parametros);
    }
    else {
        char errorSemantico[100] = "Multiples declaraciones de ";
        strcat(errorSemantico, funcion);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);
    }

    *parametros = NULL;
}


void pushFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, ParametroNode* parametros) {
    /* 1. allocate node */
    FuncionNode* new_node = (FuncionNode*) malloc(sizeof(FuncionNode));

    /* 2. put in the data  */
    new_node->data  = newDataFuncion(funcion, tipoDeRetorno, parametros);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataFuncion newDataFuncion(char* funcion, char* tipoDeRetorno, ParametroNode* parametros){
    DataFuncion data;

    data.funcion = strdup(funcion);
    data.tipoDeRetorno = strdup(tipoDeRetorno);
    data.listaParametros = parametros;

    return data;
}


FuncionNode* searchFuncion(FuncionNode* head, char* funcion) {
    FuncionNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.funcion, funcion)!=0){
        current = current->next;
    }

   return current;
}


void printListFuncion(FILE *reporte, FuncionNode* node){

    fprintf(reporte,"-------------------- FUNCIONES --------------------\n");
    fprintf(reporte,"Identificador\t \t \t Tipo de Retorno\n");


    while(node != NULL) {
        fprintf(reporte,"%s\t \t \t \t %s\n", node->data.funcion, node->data.tipoDeRetorno);
        printListParametro(reporte, node->data.listaParametros);

        node = node->next;
    }

    fprintf(reporte,"\n");

}

//-------------------------------------------------------------------------------//


void pushParametro(ParametroNode** head, char* tipoDeDato, char* nombre) {
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

int sizeListParametro(ParametroNode* node) {

    int cant = 0;

    while(node != NULL) {
        cant++;
        node = node->next;
    }

    return cant;

}

void printListParametro(FILE *reporte, ParametroNode* node) {

    fprintf(reporte,"PARAMETROS: ");

    while(node != NULL) {
        fprintf(reporte,"%s\t %s,  ", node->data.tipoDeDato, node->data.nombre);

        node = node->next;
    }

    fprintf(reporte,"\n");

}