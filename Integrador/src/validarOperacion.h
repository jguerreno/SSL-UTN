#include  <stdio.h>
#include"lib.h"

extern EstructuraErrorSemantico* listaErroresSemanticos;
// Errores en expresion binaria
extern int validacionBinaria;
extern char auxTipo1[100]; 
extern char auxTipo2[100];


int agregarTipo(char *tipo1,char *tipo2,char *valor,int flag);
int validarOperacionBinaria(char *tipo1, char*tipo2);

void agregarTipoDeDato(VariableNode* listaVariables, char* identificador);