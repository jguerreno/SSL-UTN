#include "lib.h"
#include <stdio.h>

int main(){
    struct Node *lista =(struct Node*) malloc(sizeof(struct Node));
    lista->data = 3;
    lista->next = NULL;
    printf("Hola");
    printf("%d",lista->data);
    return 0;
}