#include "validarOperacion.h"
#include <string.h>
#include <stdlib.h>

int agregarTipo(char *tipo1,char *tipo2,char *valor,int flag){
    if(flag == 0){
        strcpy(tipo1,valor);
        flag = 1;
    }else{
        strcpy(tipo2,valor);
        flag = 0;
    }
    return flag;
}

int validarOperacionBinaria(char *tipo1, char*tipo2){
    return (strcmp(tipo1,tipo2) == 0);
}


/** 
 * 
 * if(validacionBinario==0){
                                                    auxTipo1=strudup($<cadena>1);
                                                    validacionBinario=1;
                                                }else{
                                                    auxTipo2=strudup($<cadena>1);
                                                    validacionBinario=0;
                                                    }
**/