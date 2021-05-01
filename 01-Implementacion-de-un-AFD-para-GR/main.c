#include "lib.h"

int main(void){
    char nombreArchivoEntrada[] = "entrada.txt";
    char nombreArchivoSalida[] = "salida.txt";

    // Abro archivos
    FILE* archivoEntrada = fopen(nombreArchivoEntrada, "r+b");
    FILE* archivoSalida = fopen(nombreArchivoSalida, "w+b");

    // Cadenas en la que voy leyendo
    char cadena[20];
    int tipoCadena = -1;

    if(feof(archivoEntrada)){
        printf("Archivo ingresado esta vacio \n");
    }    
    // Recorro ArchprocesarTokenarCadena(archivoEntrada, &cadena);
    while( !feof(archivoEntrada) ){
        obtenerToken(archivoEntrada, cadena);
        /*tipoCadena = procesarToken(archivoEntrada, cadena);
        imprimirCadena(archivoSalida, cadena, tipoCadena);*/
        int largoCadena = strlen(cadena);
        if(largoCadena > 0 ){
            printf("Token encontrado: %s\n",cadena);
            printf("Largo de la cadena encontrada %d\n",largoCadena);
            printf("------------\n");
        }
        limpiarBuffer(cadena);
    }
    // Imprimo y Proceso el ultima Token
    /*tipoCadena = procesarToken(archivoEntrada, cadena);
    imprimirCadena(archivoSalida, cadena, tipoCadena);*/

    // Cierro archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
