#include "lib.h"
#include<string.h>

void obtenerToken(FILE*, char[]);
int procesarToken(FILE*, char[]);

void imprimirCadena(FILE* archivo, char cadena[], int tipo){
    int i=0;
    char tipoToken[25];

    obtenerTipoToken(tipoToken, tipo);
    strcat(cadena, tipoToken);

    while(cadena[i] != '\0'){
        fwrite(&cadena[i], sizeof(char), 1, archivo);
        i++;
    }
}

void obtenerTipoToken(char tipoToken[], int tipo){
    if(tipo == -1)
        strcpy(tipoToken, "\tCadena no reconocida\n\0");
    else{
        if(tipo == 8)
            strcpy(tipoToken, "\tOctal\n\0");

        if(tipo == 16)
            strcpy(tipoToken, "\tHexadecimal\n\0");

        if(tipo == 10)
            strcpy(tipoToken, "\tDecimal\n\0");
    }
}