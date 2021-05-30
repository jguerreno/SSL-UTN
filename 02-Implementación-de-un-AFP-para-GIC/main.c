#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    
    //Leer una cadena de caracteres

    //Eliminar los espacios en blanco de la cadena
    printf("Ejemplo para probar Trimm: \n"); //Solo a modo de prueba, cuando este listo todo esto se saca
    char cadena[]="\t  (2 + 4)+ 86 - 2 /     (10 + 6) = \t\t\n\n";
    printf("%s",cadena);
    myTrimm(cadena);
    printf("Nueva cadena:\n%s\n",cadena);

    //Procesar la cadena

    //Imprimir si fue reconocida o no
    return 0;
}
