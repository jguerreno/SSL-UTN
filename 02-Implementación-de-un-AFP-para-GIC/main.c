#include "lib.h"
#include <stdio.h>

int main(void){
    
    char s[200];
    int estado_final;

    //Leer una cadena de caracteres
    ingresarCadena(s);
    //Repetir
    while (strlen(s) > 0){
    
        //Eliminar los espacios en blanco de la cadena
        myTrimm(s);

        printf("Comenzando procesamiento de Token: \n");
        
        estado_final = procesarToken(s);
        if(estado_final == 1 || estado_final == 2){
            printf("Cadena reconocida correctamente, estado final: %d\n", estado_final);
        }else{
            printf("Cadena NO reconocida, estado final: %d\n", estado_final);
        }

        limpiarBuffer(s);
        ingresarCadena(s);
    }
 
    return 0;
}
