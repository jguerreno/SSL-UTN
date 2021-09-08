#include <stdio.h>

#define MAX_TAM_IDENTIFIER 50

/**
 * CONSTANTES DECIMALES
 * **/
typedef struct DataConstDec{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstDec;

typedef struct ConstDecNode{
    DataConstDec data;
    struct ConstDecNode* next;
} ConstDecNode;

/**
 * CONSTANTES OCTALES
 * **/

typedef struct DataConstOct{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstOct;

typedef struct ConstOctNode{
    DataConstOct data;
    struct ConstOctNode* next;
} ConstOctNode;

/**
 * CONSTANTES HEXADECIMALES
 * **/
typedef struct DataConstHex{
    char constante[MAX_TAM_IDENTIFIER];
} DataConstHex;

typedef struct ConstHexNode{
    DataConstHex data;
    struct ConstHexNode* next;
} ConstHexNode;


/**
 * FUNCIONES CONSTANTES DECIMALES
 * **/
void pushConstDec(ConstDecNode** head, char *dec);
DataConstDec newDataConstDec(char *dec);
void printConstantesDecimales(FILE *reporte, ConstDecNode* node);
void deleteListaConstanteDecimales(ConstDecNode** head);

/**
 * FUNCIONES CONSTANTES OCTALES
 * **/
void pushConstOct(ConstOctNode** head, char *oct);
DataConstOct newDataConstOct(char *oct);
void printConstantesOctales(FILE *reporte, ConstOctNode* node);
void deleteListaConstanteOctales(ConstOctNode** head);

/**
 * FUNCIONES CONSTANTES HEXADCEIMALES
 * **/
void pushConstHex(ConstHexNode** head, char *hex);
DataConstHex newDataConstHex(char *hex);
void printConstantesHexadecimales(FILE *reporte, ConstHexNode* node);
void deleteListaConstanteHexadecimales(ConstHexNode** head);