#include <stdio.h>


typedef struct DataParametro {
    char* tipoDeDato;
    char* nombre;
} DataParametro;

typedef struct ParametroNode {
    DataParametro data;
    struct ParametroNode* next;
} ParametroNode;


void pushParametro(ParametroNode** head, char* tipoDeDato, char* nombre);
DataParametro newDataParametro(char* tipoDeDato, char* nombre);
ParametroNode* searchParametro(ParametroNode* head, char* tipoDeDato, char* nombre);
int sizeListParametro(ParametroNode* node);
void printListParametro(FILE *reporte, ParametroNode* node);

//----------------------------------------------------------------------------------------

typedef struct DataFuncion{
    char* funcion;
    char* tipoDeRetorno;
    ParametroNode* listaParametros;
} DataFuncion;

typedef struct FuncionNode{
    DataFuncion data;
    struct FuncionNode* next;
} FuncionNode;


void addFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, ParametroNode** parametros);
void pushFuncion(FuncionNode** head, char* funcion, char* tipoDeRetorno, ParametroNode* parametros);
DataFuncion newDataFuncion(char* funcion, char* tipoDeRetorno, ParametroNode* parametros);
FuncionNode* searchFuncion(FuncionNode* head, char* funcion);
void printListFuncion(FILE *reporte, FuncionNode* node);
