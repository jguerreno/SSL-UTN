#include "lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int test_ProcesarToken(void);

int main(void){

    
    test_ProcesarToken();
    return 0;
}

int test_ProcesarToken(void)
{
    /** 1 = Octal /
    * 2 = Decimal /
    * 3 = (Seria los correspondientes a 0x Error?) /
    * 4 = Hexadecimal /
    * 5 = Octal /
    * 6 = Error /
    * */

    // Test a Octal string:
    printf("Testing an Octal Number: ");
    assert(procesarToken("0245") == 5);
    printf("Passed\n");

    
}