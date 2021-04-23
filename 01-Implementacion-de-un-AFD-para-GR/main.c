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

    obtenerToken(archivoEntrada, cadena);
    // Recorro ArchprocesarTokenarCadena(archivoEntrada, &cadena);
    while( !feof(archivoEntrada) ){
        tipoCadena = procesarToken(archivoEntrada, cadena);
        imprimirCadena(archivoSalida, cadena, tipoCadena);

        obtenerToken(archivoEntrada, cadena);
    }
    // Imprimo y Proceso el ultima Token
    tipoCadena = procesarToken(archivoEntrada, cadena);
    imprimirCadena(archivoSalida, cadena, tipoCadena);

    // Cierro archivos
    fclose(archivoEntrada);
    fclose(archivoSalida);

    return 0;
}
