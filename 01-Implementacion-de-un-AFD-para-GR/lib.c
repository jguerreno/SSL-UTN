#include "lib.h"

void limpiarBuffer(char cadena[]){
    memset(cadena, 0,20);
}


void obtenerToken(FILE* fileName, char cadena[]){
    char c; 
    int i = 0;
    fread(&c,sizeof(char),1,fileName);

    while(c!=','){
        cadena[i] = c;
        i++;
        fread(&c,sizeof(char),1,fileName);
        if(feof(fileName)){
           return;
        }
    }
}
/*int procesarToken(FILE*, char[]);
void imprimirCadena(FILE*, char[], int);*/
