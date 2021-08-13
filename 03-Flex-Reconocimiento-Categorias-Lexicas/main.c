#include "lib.h"
#include <stdio.h>

int main(){
    /*struct Node *lista = NULL;

    push(&lista, 10);
    push(&lista, 30);
    push(&lista, 11);
    push(&lista, 21);
    push(&lista, 14);

    printList(lista);*/

    int a = realToEntero("1.575E1");
    printf("%d\n",a);

    int c = mantisaToEntero("1.575E1");
    printf("%d\n",c);

    float test = 4.;
    printf("%f\n",test);

    return 0;
}