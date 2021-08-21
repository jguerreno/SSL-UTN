#include "constCaracter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void pushConstCarac(ConstCaracNode** head, char *constCarac){
    /* 1. allocate node */
    ConstCaracNode* new_node = (ConstCaracNode*) malloc(sizeof(ConstCaracNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstCarac(constCarac);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataConstCarac newDataConstDec(char constCarac){
    DataConstCarac data;

    data.constanteCaracter = constCarac;

    return data;
}

void printConstantesCaracter(ConstCaracNode *node){

    int i = 0;
    printf("CONSTANTES CARACTER\n");

    while (node != NULL){
     printf("%s %d\n", i, node->data.constanteCaracter);
     i++;

     node = node->next;
  }

}

void deleteListaConstantesCaracter(ConstCaracNode** head){
    /* deref head_ref to get the real head */
    ConstCaracNode* current = *head;
    ConstCaracNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

