#include "constantesOct.h"
#include "lib.h"   
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void pushConstOct(ConstOctNode** head, char *oct){
    /* 1. allocate node */
    ConstOctNode* new_node = (ConstOctNode*) malloc(sizeof(ConstOctNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstOct(oct);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataConstOct newDataConstOct(char *oct){
    DataConstOct data;

    strcpy(data.constante, oct);

    return data;
}

void printConstantesOctales(FILE *reporte, ConstOctNode *node){

    fprintf(reporte,"----------------- CONSTANTES OCTALES -----------------\n");

    while (node != NULL){
     fprintf(reporte,"%s ", node->data.constante);
     int octal = atoi(node->data.constante);
     fprintf(reporte,"Valor Decimal: %d\n",octalToDec(octal));

     node = node->next;
  }

}

void deleteListaConstanteOctales(ConstOctNode** head){
    /* deref head_ref to get the real head */
    ConstOctNode* current = *head;
    ConstOctNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

