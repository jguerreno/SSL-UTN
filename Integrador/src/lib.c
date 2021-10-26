#include "lib.h"


void declaracionFuncionVariable(ParametroNode** listaParametros, NombreVariableNode** listaNombreDeVariables, 
                                char* tipo, char* identificadorFuncion, int* flagFuncion, int* flagVariable) {
    
    if(*flagFuncion == 1) {
        addFuncion(&listaFunciones, identificadorFuncion, tipo, listaParametros);
        *flagFuncion = 0;
    }

    if(*flagVariable == 1) {
        addVariable(&listaVariables, listaFunciones, listaNombreDeVariables, tipo);
        *flagVariable = 0;
    }
}
