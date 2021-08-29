#include "literalesCadena.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void addLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[], int longitudCadenaLiteral){

    LiteralCadenaNode* node = searchLiteralCadena(*head, cadenaLiteral, longitudCadenaLiteral);

    if(node != NULL){
        pushLiteralCadena(head, cadenaLiteral, longitudCadenaLiteral);
    }
}


void pushLiteralCadena(LiteralCadenaNode** head, char cadenaLiteral[], int longitudCadenaLiteral){
    /* 1. allocate node */
    LiteralCadenaNode* new_node = (LiteralCadenaNode*) malloc(sizeof(LiteralCadenaNode));

    /* 2. put in the data  */
    new_node->data  = newDataLiteralCadena(cadenaLiteral, longitudCadenaLiteral);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataLiteralCadena newDataLiteralCadena(char cadenaLiteral[], int longitudCadenaLiteral){
    DataLiteralCadena data;

    strcpy(data.cadenaLiteral, cadenaLiteral);
    data.longitud = longitudCadenaLiteral;

    return data;
}


LiteralCadenaNode* searchLiteralCadena(LiteralCadenaNode* head, char cadenaLiteral[], int longitudCadenaLiteral){
    LiteralCadenaNode* current = head;  // Initialize current

    while (current != NULL && strcmp(current->data.cadenaLiteral, cadenaLiteral)!=0){
        current = current->next;
    }

   return current;
}


void printListLiteralCadena(FILE *reporte, LiteralCadenaNode* node){

    fprintf(reporte,"cadenaLiteral\tLongitud\n");

    //sortLiteralCadena(&node);

    while (node != NULL){
     fprintf(reporte,"%-20s\t%d\n", node->data.cadenaLiteral, node->data.longitud);
     node = node->next;
  }

}


void deleteListLiteralCadena(LiteralCadenaNode** head){
    /* deref head_ref to get the real head */
    LiteralCadenaNode* current = *head;
    LiteralCadenaNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

void sortLiteralCadena(LiteralCadenaNode** head){

    LiteralCadenaNode *aux, *aux2, *temp, * current = *head;
    LiteralCadenaNode* next;

    int mayor = 0;
    
    aux = (*head);
    aux2 = aux;
    
    while (aux->next != NULL)
    {
        while (aux2 != NULL)
        {
            if (aux2->next->data.longitud >= mayor)
                mayor = aux2->next->data.longitud;
        }
        
        aux2 = aux;
        
        while (aux2->next != NULL)
        {
            if ((aux2->next)->next->data.longitud == mayor)
            {
                temp = (aux2->next)->next;
                (aux2->next)->next = aux;
                aux->next = temp;
            }
            aux2 = aux2->next;
            
        }
        aux = aux->next;
    }
}


