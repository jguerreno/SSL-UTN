#include "llamadaAFuncion.h"


void chequearLlamadaFuncion(char* identificador, ParametroNode** parametrosLlamadaFuncion) {
    FuncionNode*  existenciaFuncion = searchFuncion(listaFunciones, identificador);

    if(existenciaFuncion == NULL) {
        char errorSemantico[100] = "Funcion no declarada ";
        strcat(errorSemantico, identificador);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);
    }
    else{
        chequearCantidadDeParametros2(*parametrosLlamadaFuncion,existenciaFuncion);
        chequearTipoDeParametros2(*parametrosLlamadaFuncion,existenciaFuncion->data.listaParametros, identificador);
    }

    *parametrosLlamadaFuncion = NULL;
}


void addParametroLlamadaFuncion(ParametroNode**parametrosLlamadaFuncion, char* identificador) {
    VariableNode* variable = searchVariable(listaVariables, identificador);

    if(variable != NULL){
        pushParametro(parametrosLlamadaFuncion, variable->data.tipoDato, identificador);
    }
    else {
        char errorSemantico[100] = "Variable no declarada ";
        strcat(errorSemantico, identificador);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);

        pushParametro(parametrosLlamadaFuncion, "SinTipo", identificador);
    }

}


void chequearCantidadDeParametros2(ParametroNode* parametrosLlamadaFuncion, FuncionNode* existenciaFuncion) {
    int cantidadParametros1 = sizeListParametro(existenciaFuncion->data.listaParametros);
    int cantidadParametros2 = sizeListParametro(parametrosLlamadaFuncion);

    if(cantidadParametros1 != cantidadParametros2) {
        char errorSemantico[100] = "Cantidad incorrecta de parametros en llamada a ";
        strcat(errorSemantico, existenciaFuncion->data.funcion);
        pushErrorSemantico(&listaErroresSemanticos, errorSemantico);
    }
}


void chequearTipoDeParametros2(ParametroNode* parametrosLlamadaFuncion, ParametroNode* existenciaFuncion, char* identificador) {
    while(parametrosLlamadaFuncion != NULL && existenciaFuncion != NULL) {
        if(strcmp(parametrosLlamadaFuncion->data.tipoDeDato, existenciaFuncion->data.tipoDeDato) != 0) {
            char errorSemantico[100] = "No coinciden los tipos de datos de ";
            strcat(errorSemantico, identificador);
            pushErrorSemantico(&listaErroresSemanticos, errorSemantico);

            break;
        }

        existenciaFuncion = existenciaFuncion->next;
        existenciaFuncion = existenciaFuncion->next;
    }
}
