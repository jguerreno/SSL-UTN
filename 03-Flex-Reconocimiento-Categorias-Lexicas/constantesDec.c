#include "constantesDec.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void pushConstDec(ConstDecNode** head, char *dec);
DataConstDec newDataConstDec(char *dec);
void printConstDec(ConstDecNode* node);
void deleteListaConstanteDecimales(ConstDecNode** head);

void pushConstDec(ConstDecNode** head, char *dec){
    /* 1. allocate node */
    ConstDecNode* new_node = (ConstDecNode*) malloc(sizeof(ConstDecNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstDec(dec);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataConstDec newDataConstDec(char *dec){
    DataConstDec data;

    strcpy(data.constante, dec);

    return data;
}

void printConstantesDecimales(ConstDecNode *node){

    printf("CONSTANTES DECIMALES\n");

    while (node != NULL){
     printf("%s\n", node->data.constante);

     node = node->next;
  }

}


void deleteListaComentarios(ConstDecNode** head){
    /* deref head_ref to get the real head */
    ConstDecNode* current = *head;
    ConstDecNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

