#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    char nombreArchivoEntrada[] = "entrada.txt";
    char nombreArchivoSalida[] = "salida.txt";

    // Abro archivos
    FILE* archivoEntrada = fopen(nombreArchivoEntrada, "r+b");
    FILE* archivoSalida = fopen(nombreArchivoSalida, "w+b");

    // Cadenas en la que voy leyendo
    char cadena[20];
    int tipoToken = -1;

    obtenerToken(archivoEntrada, cadena);
    // Recorro ArchprocesarTokenarCadena(archivoEntrada, &cadena);
    while( !feof(archivoEntrada) ){
        tipoToken = procesarToken(cadena);
        char *tipoCadena = tipoDeToken(tipoToken);
        imprimirCadena(archivoSalida, cadena, tipoCadena);
        //Libero la memoria usada por el puntero
        free(tipoCadena);
        obtenerToken(archivoEntrada, cadena);
    }
    // Imprimo y Proceso el ultima Token
    tipoToken = procesarToken(cadena);
    char *tipoCadena = tipoDeToken(tipoToken);
    imprimirCadena(archivoSalida, cadena, tipoCadena);
    
    //Libero la memoria usada por el puntero
    free(tipoCadena);
    

    // Cierro archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
