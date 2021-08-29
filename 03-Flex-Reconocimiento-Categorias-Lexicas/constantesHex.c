#include "constantesHex.h"
#include "lib.h"   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>




void pushConstHex(ConstHexNode** head, char *hex){
    /* 1. allocate node */
    ConstHexNode* new_node = (ConstHexNode*) malloc(sizeof(ConstHexNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstHex(hex);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataConstHex newDataConstHex(char *hex){
    DataConstHex data;

    strcpy(data.constante, hex);

    return data;
}

void printConstantesHexadecimales(FILE *reporte, ConstHexNode *node){

    fprintf(reporte,"----------------- CONSTANTES HEXADECIMALES -----------------\n");

    while (node != NULL){
     fprintf(reporte,"%s ", node->data.constante);
     fprintf(reporte,"Valor Decimal: %d\n",hexToDec(node->data.constante));

     node = node->next;
  }

}

void deleteListaConstanteHexadecimales(ConstHexNode** head){
    /* deref head_ref to get the real head */
    ConstHexNode* current = *head;
    ConstHexNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

