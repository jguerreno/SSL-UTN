#include <stdio.h>
#include <stdlib.h>
#include "validarOperacion.h"

// Retorna el valor char de i.
// Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i)
{
   //De nuevo lo mismo asi que es al reves
   return ( (char) i + 48 );
}

int main(){
    int validacionBinaria = 0;
    char auxTipo1[100];
    char auxTipo2[100];

    char *aux1 = "char";
    char *aux2 = "char";
    validacionBinaria = agregarTipo(auxTipo1,auxTipo2,aux1,validacionBinaria);
    printf("Returned value %d \n",validacionBinaria);
    printf("------------------\n");
    validacionBinaria = agregarTipo(auxTipo1,auxTipo2,aux2,validacionBinaria);
    printf("Returned value %d \n",validacionBinaria);

    int res = validarOperacionBinaria(auxTipo1,auxTipo2);

    printf("--- VALOR DEVUELTO : %d \n",res);
    
    return 0;
}