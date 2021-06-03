#include "lib.h"
#include <stdlib.h>
#include <stdio.h>


int main(void){
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d SACADO DE LA PILA\n", pop(stack));
 
    return 0;
}
