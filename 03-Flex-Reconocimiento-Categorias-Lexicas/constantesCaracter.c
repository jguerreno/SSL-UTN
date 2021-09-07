#include "constantesCaracter.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void pushConstCarac(ConstCaracNode** head, char constCarac){
    /* 1. allocate node */
    ConstCaracNode* new_node = (ConstCaracNode*) malloc(sizeof(ConstCaracNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstCarac(constCarac);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}

void appendConstantesCaracter(ConstCaracNode** head_ref, char constCarac){
    /* 1. allocate node */
    ConstCaracNode* new_node = (ConstCaracNode*) malloc(sizeof(ConstCaracNode));
    
    ConstCaracNode *last = (*head_ref);  /* used in step 5*/
  
    /* 2. put in the data  */
    new_node->data  = newDataConstCarac(constCarac);
 
    /* 3. This new node is going to be the last node, so make next of it as NULL*/
    new_node->next = NULL;
    
    /* 4. If the Linked List is empty, then make the new node as head */
    if ((*head_ref) == NULL){
        (*head_ref) = new_node;
    }
    else{
        /* 5. Else traverse till the last node */
        while (last->next != NULL){
            last = last->next;
        }
        
        /* 6. Change the next of last node */
        last->next = new_node;
    }
}


DataConstCarac newDataConstCarac(char constCarac){
    DataConstCarac data;

    data.constanteCaracter = constCarac;

    return data;
}

void printConstantesCaracter(FILE *reporte, ConstCaracNode *node){

    fprintf(reporte,"------------- CONSTANTES CARACTER -------------\n");
    fprintf(reporte,"Caracter\n");

    while (node != NULL){
     fprintf(reporte,"%c\n", node->data.constanteCaracter);
     node = node->next;
  }

}

void deleteListaConstantesCaracter(ConstCaracNode** head){
    ConstCaracNode* current = *head;
    ConstCaracNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }   
    *head = NULL;
}

