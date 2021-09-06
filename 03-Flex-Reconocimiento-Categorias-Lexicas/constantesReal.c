#include "constantesReal.h"
#include "lib.h"  
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void pushConstReal(ConstRealNode** head, char *real){
    /* 1. allocate node */
    ConstRealNode* new_node = (ConstRealNode*) malloc(sizeof(ConstRealNode));

    /* 2. put in the data  */
    new_node->data  = newDataConstReal(real);

    /* 3. Make next of new node as head */
    new_node->next = (*head);

    /* 4. move the head to point to the new node */
    (*head)    = new_node;
}


DataConstReal newDataConstReal(char *real){
    DataConstReal data;

    strcpy(data.constante, real);

    return data;
}

void printConstantesReales(FILE *reporte, ConstRealNode *node){

    fprintf(reporte,"------------- CONSTANTES REALES -------------\n");
    while (node != NULL){
    printf("CONSTANTE : %s\n",node->data.constante);
     fprintf(reporte,"%s\n", node->data.constante);
     int parteEntera = realToEntero(node->data.constante);
     fprintf(reporte,"Parte entera: %d\n",parteEntera);

     int parteMantisa = mantisaToEntero(node->data.constante);
     fprintf(reporte,"Parte mantisa: %d\n",parteMantisa);

     node = node->next;
  }

}

void deleteListaConstanteReales(ConstRealNode** head){
    /* deref head_ref to get the real head */
    ConstRealNode* current = *head;
    ConstRealNode* next;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
   
    /* deref head to affect the real head back in the caller. */
    *head = NULL;
}

