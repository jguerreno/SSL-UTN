#include "palabras.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * PALABRAS RESERVADAS
 * **/
void appendPalabraReservada(PalabrasReservadasNode** head_ref, char* palabraReservada){
    /* 1. allocate node */
    PalabrasReservadasNode* new_node = (PalabrasReservadasNode*) malloc(sizeof(PalabrasReservadasNode));

    PalabrasReservadasNode *last = *head_ref;  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data = newDataPalabraReservada(palabraReservada);
    
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

DataPalabraReservada newDataPalabraReservada(char* palabraReservada){
    DataPalabraReservada data;

    data.palabraReservada = strdup(palabraReservada);

    return data;
}


void printPalabrasReservadas(FILE *reporte, PalabrasReservadasNode* node, char* tipo){

    fprintf(reporte,"------------- PALABRAS RESERVADAS -------------\n");
    fprintf(reporte,"------------- %s -------------\n", tipo);

    while (node != NULL){
     fprintf(reporte,"%s\n", node->data.palabraReservada);

     node = node->next;
    }
}


void deletePalabrasReservadas(PalabrasReservadasNode** head){
    /* deref head_ref to get the real head */
    PalabrasReservadasNode* current = *head;
    PalabrasReservadasNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

/**
 * PALABRAS NO RECONOCIDAS
 * **/
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


DataPalabraNoReconocida newDataPalabraNoReconocida(char* palabraNoReconocida, int linea){
    DataPalabraNoReconocida data;

    data.noReconocida = strdup(palabraNoReconocida);
    data.linea = linea;

    return data;
}


void printPalabrasNoReconocidas(FILE *reporte, NoReconocidoNode* node){

    fprintf(reporte,"------------- PALABRAS NO RECONOCIDAS -------------\n");

    while (node != NULL){
        fprintf(reporte,"Linea: %d\tPalabra no Reconocida: %s\n", node->data.linea, node->data.noReconocida);

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