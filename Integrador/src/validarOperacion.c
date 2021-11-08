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
    /*
    if (strcmp(tipo1,tipo2) == 0){
        printf("OPERACION VALIDA \n");
        return 1;
    }else{
        printf("OPERACION INVALIDA  entre %s y %s \n",tipo1,tipo2);
        memset(tipo1,0,strlen(tipo1));
        memset(tipo2,0,strlen(tipo2));

        return -1;
    }
    */
   if (strcmp(tipo1,tipo2) == 0) {
        return 1;
    }
    else {
        char errorSemantico[100] = "OPERACION INVALIDA  entre ";
        strcat(errorSemantico, tipo1);
        strcat(errorSemantico, " y ");
        strcat(errorSemantico, tipo2);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);
        
        memset(tipo1,0,strlen(tipo1));
        memset(tipo2,0,strlen(tipo2));

        return -1;
    }
}





void agregarTipoDeDato(VariableNode* listaVariables, char* identificador) {
    VariableNode* existenciaNombreEnVariables = searchVariable(listaVariables, identificador);

    if(existenciaNombreEnVariables != NULL) {
        validacionBinaria = agregarTipo(auxTipo1, auxTipo2, existenciaNombreEnVariables->data.tipoDato, validacionBinaria);
    }
    else {
        char errorSemantico[100] = "Variable no declarada ";
        strcat(errorSemantico, identificador);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);
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