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
    if (strcmp(tipo1,tipo2) == 0){
        printf("OPERACION VALIDA \n");
        return 1;
    }else{
        printf("OPERACION INVALIDA  entre %s y %s \n",tipo1,tipo2);
        return -1;
    }
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