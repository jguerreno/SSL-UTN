#include "lib.h"
#include <stdio.h>

int main(){
    struct Node *lista = NULL;

    push(&lista, 10);
    push(&lista, 30);
    push(&lista, 11);
    push(&lista, 21);
    push(&lista, 14);

    printList(lista);

    


    return 0;
}