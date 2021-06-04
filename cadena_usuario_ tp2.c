#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){

    char s[400];
    printf("Ingrese una cadena: ");
    fgets(s, sizeof s, stdin);
	s[strcspn(s, "\n")] = '\0';

     return 0;
}
