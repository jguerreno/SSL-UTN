#include "palabrasNoReconocidas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void pushPalabraNoReconocida(NoReconocidoNode** head, char palabraNoReconocida[], int linea){
    /* 1. allocate node */
    NoReconocidoNode* new_node = (NoReconocidoNode*) malloc(sizeof(NoReconocidoNode));

    /* 2. put in the data  */
    new_node->data  = newDataPalabraNoReconocida(palabraNoReconocida, linea);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataPalabraNoReconocida newDataPalabraNoReconocida(char palabraNoReconocida[], int linea){
    DataPalabraNoReconocida data;

    strcpy(data.noReconocida, palabraNoReconocida);
    data.linea = linea;

    return data;
}


void printPalabrasNoReconocidas(FILE *reporte, NoReconocidoNode* node){

    fprintf(reporte,"Palabras no reconocidas\n");

    while (node != NULL){
        fprintf(reporte,"Linea: %d\tPalabra no Reconocida: %s", node->data.linea, node->data.noReconocida);

        node = node->next;
    }

}


void deleteListaPalabrasNoReconocidas(NoReconocidoNode** head){
    /* deref head_ref to get the real head */
    NoReconocidoNode* current = *head;
    NoReconocidoNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}