
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     SWITCH = 260,
     WHILE = 261,
     DO = 262,
     FOR = 263,
     CASE = 264,
     DEFAULT = 265,
     CONTINUE = 266,
     BREAK = 267,
     RETURN = 268,
     TIPO_DATO = 269,
     OPERADOR_ASIGNACION = 270,
     OPERADOR_O_LOGICO = 271,
     OPERADOR_Y_LOGICO = 272,
     OPERADOR_O_INCLUSIVO = 273,
     OPERADOR_O_EXCLUSIVO = 274,
     OPERADOR_IGUALDAD = 275,
     OPERADOR_RELACIONAL = 276,
     OPERADOR_CORRIMIENTO = 277,
     OPERADOR_MULTIPLICATIVO = 278,
     OPERADOR_INCREMENTO = 279,
     OPERADOR_SIZEOF = 280,
     FLECHA = 281,
     IDENTIFICADOR = 282,
     CONSTANTE_CADENA = 283,
     CONSTANTE_DECIMAL = 284,
     CONSTANTE_OCTAL = 285,
     CONSTANTE_HEXADECIMAL = 286,
     CONSTANTE_CARACTER = 287,
     CONSTANTE_REAL = 288
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 51 "../src/analizador.y"

    int entero;
    float real;
    char* cadena;



/* Line 1676 of yacc.c  */
#line 93 "analizador.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


