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
    
    struct Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d SACADO DE LA PILA\n", pop(stack));
 
    return 0;
}
