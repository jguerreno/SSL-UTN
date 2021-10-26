#include "sentencias.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addSentencia(SentenciaNode** head, char* tipoSentencia,int linea){

    SentenciaNode* node = searchSentencia(*head, tipoSentencia);

    if(node == NULL){
        pushSentencia(head, tipoSentencia,linea);
    }
}


void pushSentencia(SentenciaNode** head, char* tipoSentencia,int linea){
    /* 1. allocate node */
    SentenciaNode* new_node = (SentenciaNode*) malloc(sizeof(SentenciaNode));

    /* 2. put in the data  */
    new_node->data  = newDataSentencia(tipoSentencia,linea);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataSentencias newDataSentencia(char* tipoSentencia,int line){
    DataSentencias data;

    data.tipoSentencia = strdup(tipoSentencia);
    data.linea = line;

    return data;
}


SentenciaNode* searchSentencia(SentenciaNode* head, char* tipoSentencia){
    SentenciaNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.tipoSentencia, tipoSentencia)!=0){
        current = current->next;
    }

   return current;
}


void printListSentencia(FILE *reporte, SentenciaNode* node){

    fprintf(reporte,"-------------------- SENTENCIAS --------------------\n");
    fprintf(reporte,"Tipo de Sentencia\n");


    while (node != NULL){
     fprintf(reporte,"%s \t \t \t \t \t %d\n", node->data.tipoSentencia,node->data.linea);

     node = node->next;
  }

}
