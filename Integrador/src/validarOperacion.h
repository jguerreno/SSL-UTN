#include  <stdio.h>
#include"lib.h"

extern EstructuraErrorSemantico* listaErroresSemanticos;

int agregarTipo(char *tipo1,char *tipo2,char *valor,int flag);
int validarOperacionBinaria(char *tipo1, char*tipo2);