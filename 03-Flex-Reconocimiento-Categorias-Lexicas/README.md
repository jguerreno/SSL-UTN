# Trabajo Práctico n° 3 -  FLEX para reconocimiento de categorías léxicas de C

* https://docs.google.com/document/u/2/d/1kJJnqjQfIk0gE2tRjPqDVt6UF3Ntc09Du5A6CFmH9lE/edit

## Integrantes
- Garcia Nicolas
- Cynthia Abbate
- Matias Planchuelo
- Alejo Lovallo
- Juan Guerreño 

### RUN

* flex reconocimientoDeCategoriasLexicas.l

* gcc -o p lib.c lex.yy.c comentarios.c constantesCaracter.c constantesDec.c constantesOct.c constantesHex.c constantesReal.c identificadores.c literalesCadena.c operadoresYcaracteresDePuntuacion.c palabrasNoReconocidas.c palabrasReservadas.c 


### DEBUG

* IDENTIFICADORES OK
* CADENAS LITREALES OK
* PALABRAS NO RECONOCIDAS OK
* PALABRAS RESERVADAS OK