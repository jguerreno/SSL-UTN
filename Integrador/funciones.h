#include <stdio.h>

// int saludar(int num, char c);
typedef struct DataFuncion{
    char* funcion;
    char* tipoDeRetorno;
    //ParametroNode* listaParametro;
    int linea;
} DataFuncion;

typedef struct FuncionNode{
    DataFuncion data;
    struct FuncionNode* next;
} FuncionNode;

void addFuncion(FuncionNode** head, char* funcion,int linea);
void pushFuncion(FuncionNode** head, char* funcion,int linea);
DataFuncion newDataFuncion(char* funcion,int linea);
FuncionNode* searchFuncion(FuncionNode* head, char* funcion);
void printListFuncion(FILE *reporte, FuncionNode* node);

//----------------------------------------------------------------------------------------

typedef struct DataParametro {
    char* tipoDeDato;
    char* nombre;
} DataParametro;

typedef struct ParametroNode {
    DataParametro data;
    struct ParametroNode* next;
} ParametroNode;

void addParametro(ParametroNode** head, char* tipoDeDato, char* nombre);
void pushParametro(ParametroNode** head, char* tipoDeDato, char* nombre);
DataParametro newDataParametro(char* tipoDeDato, char* nombre);
ParametroNode* searchParametro(ParametroNode* head, char* funcion);
void printListParametro(FILE *reporte, ParametroNode* node);