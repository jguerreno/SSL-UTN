#ifndef NUESTRA_LIB_
#define NUESTRA_LIB_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

void limpiarBuffer(char cadena[]);
int procesarToken(char*);
int grupoCaracter(char caracter);
void myTrimm (char *cadena);
void leftTrimm (char *cadena);
void rightTrimm (char *cadena);
void reverse (char *cadena);


int pop(struct Stack* stack);
void push(struct Stack* stack, int item);
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
struct Stack* createStack(unsigned capacity);
int freeStack(struct Stack* stack);

#endif  // NUESTRA_LIB_
