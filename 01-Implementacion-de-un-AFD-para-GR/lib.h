#ifndef NUESTRA_LIB_
#define NUESTRA_LIB_

#include <stdio.h>

void obtenerToken(FILE*, char[]);
int procesarToken(char*);
char* tipoDeToken (int);
int grupoCaracter(char caracter);
void imprimirCadena(FILE*, char[], char*);

#endif  // NUESTRA_LIB_