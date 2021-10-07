#!/bin/bash

set -e 


bison -d parser.y
flex scanner.l
gcc -o p funciones.c estructuraInvalida.c sentencias.c variables.c parser.tab.c lex.yy.c
./p