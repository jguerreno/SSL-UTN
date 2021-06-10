#include "lib.h"
#include <string.h>
#include <stdlib.h>

int ERROR_PILA=-1;

void limpiarBuffer(char cadena[]){
    memset(cadena, 0,50);
}

/**
 * Clasifica el Token segun la matriz de transicion dada
 * @author Nicolas Garcia
 * @param cadena Token a clasificar
 * @return Entero correspondiente al estado en la matriz de transicion 
 * @see "grupoCaracter"
 * TODO: Rewrite
 */
int procesarToken (char *cadena){
    //Estado 0 = Estado Inicial
    int estado = 0;
    //La matriz: 7 x 6
    int matriz[7][6] = {{1,2,2,6,6,6},{5,5,6,6,3,6},{2,2,2,6,6,6},{4,4,4,4,6,6},{4,4,4,4,6,6},{5,5,6,6,6,6},{6,6,6,6,6,6}};
    for(int i=0;i<strlen(cadena);i++){
        estado=matriz[estado][grupoCaracter(cadena[i])];
        // Estado de error para evitar que siga procesando.
        // Solo para ahorrar tiempo en tokens largos
        if (estado ==  6){
            break;
        }
    }

    return estado;
}

/**
 * Funcion Auxiliar que clasifica el caracter segun la columna correspondiente de la matriz de transicion
 *  
 * @param caracter Caracter a clasificar
 * @return Entero correspondiente a la columna en la matriz de transicion
 * @author Nicolas Garcia
 */
int grupoCaracter(char caracter){
    if(caracter == '0'){
        return 0;
    }else{
        if (caracter >= '1' && caracter <= '7'){
            return 1;
        }
        else{
            if (caracter >= '8' && caracter <='9'){
                return 2;
            }
            else{
                if((caracter >= 'a' && caracter<='f') || (caracter >= 'A' && caracter<='F')){
                    return 3;
                }
                else{
                    if (caracter == 'x' || caracter == 'X'){
                        return 4;
                    }
                }
            }
        }
    }
    return 5; //Error  
}


/**
 * Funcion Auxiliar que elimina los espacios blancos dentro de toda la cadena
 *  
 * @param cadena Caracter a modificar
 * @return Misma cadena sin los espacios en blanco
 * @author Matias Planchuelo
 */
void myTrimm (char *cadena)
{
    int i=0;
    int largo = strlen(cadena);
    leftTrimm (cadena); rightTrimm(cadena);
    while (cadena[i] != '\0')
    {
        if (cadena[i] == ' ')
        {
            for (int j=i;j<largo;j++)
            {
                cadena[j]=cadena[j+1];
            }
        largo--;
        }
        if (cadena[i]!=' ')
        {
            i++;
        }
    }
    return;
}

void rightTrimm (char *cadena)
{
    int largo = strlen (cadena) - 1;
    while (largo>0)
    {
        switch (cadena[largo])
        {
            case '\t':
            case '\n':
                cadena[largo] = '\0';
                largo--;
                break;

            default:
                return;
        }
    }
}

void leftTrimm (char *cadena)
{
    reverse(cadena);
    rightTrimm(cadena);
    reverse(cadena);
}

/**
 * Funcion Auxiliar que invierte el orden de toda la cadena
 *  
 * @param cadena Caracter a modificar
 * @return Misma cadena invertido su orden
 * @author Matias Planchuelo
 */
void reverse (char *cadena)
{
    int i, j;
    char *dup;
    dup=strdup(cadena);
    j=strlen(cadena) - 1;

    for (i=0;i<strlen(cadena);i++)
    {
        cadena[i]=dup[j];
        j--;
    }
    free(dup); 
}    


struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
 
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 

void push(struct Stack* stack, int item)
{
    if (isFull(stack)){
        printf("PILA LLENA");
        return;
    } 
    stack->array[++stack->top] = item;
    printf("%d AÑADIDO A LA PILA\n", item);
}
 

int pop(struct Stack* stack)
{
    if (isEmpty(stack)){
        printf("PILA VACIA");
        return ERROR_PILA;
    } 
    return stack->array[stack->top--];
}
