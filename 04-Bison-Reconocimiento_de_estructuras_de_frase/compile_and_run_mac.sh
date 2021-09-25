#!/bin/bash

set -e 


bison -d parser.y
flex scanner.l
gcc -o p parser.tab.c lex.yy.c
./p