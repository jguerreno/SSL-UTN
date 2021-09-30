#include "sentencias.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addSentencia(SentenciaNode** head, char sentencia[],char tipo[]){

    SentenciaNode* node = searchIdentifier(*head, sentencia);

    if(node == NULL){
        pushSentencia(head, sentencia,tipo);
    }
}


void pushSentencia(VariableNode** head, char identificador[],char tipoDato[]){
    /* 1. allocate node */
    VariableNode* new_node = (VariableNode*) malloc(sizeof(VariableNode));

    /* 2. put in the data  */
    new_node->data  = newDataVariable(identificador,tipoDato);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataSentencias newDataVariable(char sentencia[],char tipo[]){
    DataSentencias data;

    strcpy(data.sentencia, sentencia);
    strcpy(data.tipoDato,tipo);

    return data;
}


SentenciaNode* searchSentencia(SentenciaNode* head, char sentencia[]){
    SentenciaNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.sentencia, sentencia)!=0){
        current = current->next;
    }

   return current;
}


void printListSentencia(FILE *reporte, SentenciaNode* node){

    fprintf(reporte,"-------------------- SENTENCIAS --------------------\n");
    fprintf(reporte,"Sentencia \t \t \t Tipo de sentencia\n");


    while (node != NULL){
     fprintf(reporte,"%s\t \t \t \t \t \t \t%s\n", node->data.sentencia, node->data.tipo);

     node = node->next;
  }

}
