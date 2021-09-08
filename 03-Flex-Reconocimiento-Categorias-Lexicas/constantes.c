#include "constantes.h"
#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * CONSTANTES DECIMALES
 * 
 * */
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

void printConstantesDecimales(FILE *reporte, ConstDecNode *node){

    fprintf(reporte,"----------------- CONSTANTES DECIMALES -----------------\n");

    while (node != NULL){
     fprintf(reporte,"%s\n", node->data.constante);

     node = node->next;
  }

}

void deleteListaConstanteDecimales(ConstDecNode** head){
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

/**
 * CONSTANTES OCTALES
 * **/
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

/**
 * CONSTANTES HEXADECIMALES
 * **/

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

