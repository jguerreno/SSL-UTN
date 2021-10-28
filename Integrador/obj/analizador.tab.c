
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/analizador.y"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//#include "lib.h"
#include"validarOperacion.h"


#define YYDEBUG 1

int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror (const char *s) {}

//
EstructuraInvalidaNode* listaErroresSintacticos = NULL;

// Errores Lexicos
EstructuraErrorLexico* listaErroresLexicos = NULL;

// Errores Semanticos
EstructuraErrorSemantico* listaErroresSemanticos = NULL;

// TS Variables
VariableNode* listaVariables = NULL;
// Aulxiliar
NombreVariableNode* listaNombreDeVariables = NULL;
int flagVariable = 0;

// TS Funciones
FuncionNode* listaFunciones = NULL;
// Auxiliares
ParametroNode* listaParametros = NULL;
char* identificadorFuncion = NULL;
int flagFuncion = 0;

// Auxiliar para funciones y variables
char* tipo = NULL;

// Llamada a Funciones
ParametroNode* parametrosLlamadaFuncion = NULL;

//Aux para validacion de tipos
int validacionBinaria = 0;
char auxTipo1[100]; 
char auxTipo2[100];




/* Line 189 of yacc.c  */
#line 130 "analizador.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 57 "../src/analizador.y"

    int entero;
    float real;
    char* cadena;



/* Line 214 of yacc.c  */
#line 207 "analizador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 219 "analizador.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  48
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   809

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNRULES -- Number of states.  */
#define YYNSTATES  191

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,     2,    37,     2,
      42,    41,    40,    39,    47,    38,    50,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    46,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,    51,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    15,    17,    20,
      22,    24,    26,    28,    30,    32,    34,    37,    40,    41,
      49,    50,    51,    57,    60,    62,    65,    71,    73,    75,
      77,    81,    82,    87,    90,    92,    96,    97,   100,   103,
     106,   109,   111,   117,   121,   123,   125,   127,   129,   131,
     133,   137,   139,   141,   143,   145,   147,   149,   151,   153,
     155,   157,   162,   165,   168,   170,   172,   175,   177,   182,
     186,   190,   192,   194,   196,   198,   200,   202,   206,   210,
     212,   214,   220,   228,   236,   237,   240,   245,   249,   255,
     263,   273,   275,   279,   282,   285,   288,   292,   294,   296,
     298,   300,   302,   304,   309,   310,   312
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    -1,    54,    55,    -1,     1,    55,    -1,
      43,    -1,    14,    61,    -1,    56,    -1,     1,    55,    -1,
      57,    -1,    68,    -1,    79,    -1,    82,    -1,    84,    -1,
      85,    -1,    43,    -1,     1,    56,    -1,    44,    45,    -1,
      -1,    44,    43,    59,    58,    67,    43,    45,    -1,    -1,
      -1,    14,    61,    60,    43,    59,    -1,     1,    59,    -1,
      62,    -1,    64,    46,    -1,    27,    42,    65,    41,    63,
      -1,    57,    -1,    46,    -1,    66,    -1,    66,    47,    64,
      -1,    -1,    14,    27,    47,    65,    -1,    14,    27,    -1,
      27,    -1,    27,    34,    76,    -1,    -1,    67,    56,    -1,
       1,    67,    -1,    69,    46,    -1,    77,    46,    -1,    71,
      -1,    71,    35,    69,    36,    69,    -1,    69,    70,    69,
      -1,    87,    -1,    38,    -1,    39,    -1,    40,    -1,    23,
      -1,    73,    -1,    69,    72,    69,    -1,    15,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    37,    -1,    20,
      -1,    22,    -1,    21,    -1,    74,    -1,    25,    42,    14,
      41,    -1,    24,    73,    -1,    86,    73,    -1,    76,    -1,
      75,    -1,    74,    24,    -1,    27,    -1,    75,    48,    69,
      49,    -1,    75,    50,    27,    -1,    75,    26,    27,    -1,
      28,    -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,
      33,    -1,    42,    69,    41,    -1,    75,    78,    69,    -1,
      34,    -1,    15,    -1,     3,    42,    69,    41,    57,    -1,
       3,    42,    69,    41,    57,     4,    57,    -1,     5,    42,
      69,    41,    44,    80,    45,    -1,    -1,    81,    80,    -1,
       9,    69,    36,    56,    -1,    10,    36,    56,    -1,     6,
      42,    69,    41,    57,    -1,     7,    57,     6,    42,    69,
      41,    46,    -1,     8,    42,    83,    46,    69,    46,    69,
      41,    57,    -1,    77,    -1,    77,    47,    83,    -1,    11,
      46,    -1,    12,    46,    -1,    13,    46,    -1,    13,    69,
      46,    -1,    37,    -1,    40,    -1,    39,    -1,    38,    -1,
      51,    -1,    52,    -1,    27,    42,    88,    41,    -1,    -1,
      27,    -1,    27,    47,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   124,   125,   128,   129,   130,   131,   136,
     137,   138,   139,   140,   141,   142,   143,   147,   148,   148,
     151,   152,   152,   153,   157,   158,   161,   164,   165,   168,
     169,   172,   173,   174,   177,   178,   181,   182,   183,   187,
     188,   192,   193,   194,   197,   200,   201,   202,   203,   206,
     207,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     221,   222,   223,   224,   227,   228,   229,   232,   233,   234,
     235,   238,   239,   240,   241,   242,   243,   244,   247,   250,
     251,   254,   255,   256,   259,   260,   263,   264,   267,   268,
     269,   272,   273,   276,   277,   280,   281,   284,   285,   286,
     287,   288,   289,   292,   295,   296,   297
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "CASE", "DEFAULT", "CONTINUE", "BREAK", "RETURN", "TIPO_DATO",
  "OPERADOR_ASIGNACION", "OPERADOR_O_LOGICO", "OPERADOR_Y_LOGICO",
  "OPERADOR_O_INCLUSIVO", "OPERADOR_O_EXCLUSIVO", "OPERADOR_IGUALDAD",
  "OPERADOR_RELACIONAL", "OPERADOR_CORRIMIENTO", "OPERADOR_MULTIPLICATIVO",
  "OPERADOR_INCREMENTO", "OPERADOR_SIZEOF", "FLECHA", "IDENTIFICADOR",
  "CONSTANTE_CADENA", "CONSTANTE_DECIMAL", "CONSTANTE_OCTAL",
  "CONSTANTE_HEXADECIMAL", "CONSTANTE_CARACTER", "CONSTANTE_REAL", "'='",
  "'?'", "':'", "'&'", "'-'", "'+'", "'*'", "')'", "'('", "'\\n'", "'{'",
  "'}'", "';'", "','", "'['", "']'", "'.'", "'~'", "'!'", "$accept",
  "input", "line", "sentencia", "bloque_sentencias", "$@1",
  "declaracion_list", "$@2", "declaracion", "declaracion_funcion",
  "def_dec", "declaracion_variables", "listaParametros", "identVariable",
  "sentencia_list", "sentencia_expresion", "expresion",
  "operacion_matematica", "expresion_logica", "operacion_logica",
  "expresion_prefija", "expresion_postfija", "expresion_indexada",
  "expresion_constante", "asignacion", "operador_asignacion",
  "sentencia_bifurcacion", "sentencia_caso_list", "sentencia_caso",
  "sentencia_bucle", "lista_asignaciones", "sentencia_salto",
  "sentencia_retorno", "operador_unario", "llamada_funcion", "parametros", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    61,    63,    58,    38,    45,    43,
      42,    41,    40,    10,   123,   125,    59,    44,    91,    93,
      46,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    57,
      59,    60,    59,    59,    61,    61,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    73,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    77,    78,
      78,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     7,
       0,     0,     5,     2,     1,     2,     5,     1,     1,     1,
       3,     0,     4,     2,     1,     3,     0,     2,     2,     2,
       2,     1,     5,     3,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     2,     1,     1,     2,     1,     4,     3,
       3,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     5,     7,     7,     0,     2,     4,     3,     5,     7,
       9,     1,     3,     2,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    71,    72,    73,    74,
      75,    76,    97,   100,    99,    98,     0,     5,     0,   101,
     102,     4,     7,     9,    10,     0,    41,    49,    60,    65,
      64,     0,    11,    12,    13,    14,     0,    44,     1,     3,
       8,     7,     0,     0,     0,     0,     0,    93,    94,    95,
       0,    65,    34,     6,    24,     0,    29,    67,    62,     0,
     104,     0,     0,    17,    51,    52,    53,    54,    55,    57,
      59,    58,    48,    56,    45,    46,    47,    39,     0,     0,
       0,    66,    80,     0,    79,     0,     0,     0,    40,    63,
       0,     0,     0,     0,     0,    91,     0,    96,     0,    31,
      25,     0,     0,   105,     0,    77,     0,     0,    18,    43,
      50,     0,    70,     0,    69,    78,     0,     0,     0,     0,
       0,     0,    35,     0,     0,    34,    30,    61,   104,   103,
      23,    21,     0,     0,    68,    81,    84,    88,     0,    92,
       0,    33,     0,   106,     0,     0,     0,    42,     0,     0,
       0,     0,    84,     0,     0,    31,    28,    27,    26,     0,
       0,     0,    15,    37,    82,     0,     0,    83,    85,    89,
       0,    32,    22,    15,    16,    19,     0,    87,     0,    86,
      90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    31,    32,    33,   142,   118,   154,    63,    64,
     168,    65,   134,    66,   156,    34,    35,    88,    36,    89,
      37,    38,    61,    40,    41,    97,    42,   161,   162,    43,
     106,    44,    45,    46,    47,   114
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -110
static const yytype_int16 yypact[] =
{
     188,   293,   241,   293,   -33,   -18,   -16,    -2,     3,     5,
       7,   530,    13,   559,    14,    15,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   588,  -110,   -20,  -110,
    -110,  -110,  -110,  -110,  -110,    48,    23,  -110,    25,    -7,
    -110,    16,  -110,  -110,  -110,  -110,   559,  -110,  -110,  -110,
    -110,  -110,   588,   588,   588,    53,    34,  -110,  -110,  -110,
      80,     2,   -12,  -110,  -110,    26,    28,  -110,  -110,    59,
      47,   626,   345,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   588,   588,
     588,  -110,  -110,    49,  -110,   588,    50,   588,  -110,  -110,
     635,   662,   671,    37,    -7,    31,    35,  -110,   150,    76,
    -110,    65,    52,    57,    64,  -110,   345,    13,  -110,   769,
     769,   734,  -110,    -5,  -110,   769,    -2,    62,    -2,   588,
      34,   588,  -110,    94,    66,   100,  -110,  -110,    47,  -110,
    -110,  -110,   397,   588,  -110,   123,    27,  -110,   698,  -110,
      93,    81,   -15,  -110,    92,   397,   449,   124,    -2,   588,
     102,    91,    27,   103,   588,    76,  -110,  -110,  -110,   345,
     501,   501,   105,  -110,  -110,   743,   501,  -110,  -110,  -110,
     707,  -110,  -110,  -110,  -110,  -110,   501,  -110,    -2,  -110,
    -110
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -110,  -110,    36,     1,    -4,  -110,  -109,  -110,    39,  -110,
    -110,    40,   -13,  -110,     4,  -110,    -6,  -110,  -110,  -110,
       8,  -110,    -1,    58,   -50,  -110,  -110,     6,  -110,  -110,
      30,  -110,  -110,  -110,  -110,    29
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -37
static const yytype_int16 yytable[] =
{
      39,    39,    39,    55,    51,    60,   105,   140,    92,    52,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    93,
      71,    68,   108,    72,    53,    73,    54,    94,    93,    28,
     109,   166,    83,    84,    85,    86,   159,   160,    49,    50,
      62,    95,    28,    96,   144,    56,   100,   101,   102,    91,
      95,    57,    96,    58,    99,   104,    69,    70,    90,   103,
     182,    67,    98,    74,    75,    76,    77,    78,    79,    80,
      81,    82,   110,   112,   113,   111,   122,   124,   130,   129,
     105,   131,   119,   120,   121,    83,    84,    85,    86,   123,
     133,   125,   135,   137,    87,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   138,   139,   146,   152,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   151,   145,   148,   147,   150,   107,   158,   165,   104,
      83,    84,    85,    86,   108,   169,   177,   157,   176,   164,
      75,    76,    77,    78,    79,    80,    81,    82,   167,   179,
     185,   136,   181,   175,   174,    39,   141,   173,   180,   170,
     149,    83,    84,    85,    86,     0,   132,   153,   178,    39,
      39,   173,   184,     0,     0,    39,     0,   187,    16,    17,
      18,    19,    20,    21,   190,    39,     0,   189,    -2,     1,
       0,    -2,    26,    -2,    -2,    -2,    -2,     0,     0,    -2,
      -2,    -2,    -2,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -2,    -2,     0,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,     0,     0,     0,    -2,    -2,    -2,    -2,     0,
      -2,    -2,    -2,     0,     0,     0,     0,     0,     0,    -2,
      -2,    48,     3,     0,     4,     0,     5,     6,     7,     8,
       0,     0,     9,    10,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,    22,    23,
      24,    25,     0,    26,    27,    28,     0,     0,     0,     0,
       0,     0,    29,    30,     3,     0,     4,     0,     5,     6,
       7,     8,     0,     0,     9,    10,    11,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,     0,     0,     0,
      22,    23,    24,    25,     0,    26,    27,    28,     0,     0,
       0,     0,     0,     0,    29,    30,   116,     0,   -20,     0,
     -20,   -20,   -20,   -20,     0,     0,   -20,   -20,   -20,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -20,
     -20,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,
       0,     0,   -20,   -20,   -20,   -20,     0,   -20,   -20,   -20,
       0,     0,     0,     0,     0,     0,   -20,   -20,   155,     0,
     -36,     0,   -36,   -36,   -36,   -36,     0,     0,   -36,   -36,
     -36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   -36,   -36,     0,   -36,   -36,   -36,   -36,   -36,   -36,
     -36,     0,     0,     0,   -36,   -36,   -36,   -36,     0,   -36,
     -36,   -36,     0,     0,     0,     0,     0,     0,   -36,   -36,
     171,     0,     4,     0,     5,     6,     7,     8,     0,     0,
       9,    10,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,     0,    15,    16,    17,    18,
      19,    20,    21,     0,     0,     0,    22,    23,    24,    25,
       0,    26,   172,    28,     0,     0,     0,     0,     0,     0,
      29,    30,   171,     0,     4,     0,     5,     6,     7,     8,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    13,    14,     0,    15,    16,
      17,    18,    19,    20,    21,     0,     0,     0,    22,    23,
      24,    25,     0,    26,   183,    28,     0,     0,     0,     0,
       0,     0,    29,    30,    13,    14,     0,    15,    16,    17,
      18,    19,    20,    21,     0,     0,     0,    22,    23,    24,
      25,     0,    26,     0,     0,     0,    59,     0,     0,     0,
       0,    29,    30,    13,    14,     0,    67,    16,    17,    18,
      19,    20,    21,     0,     0,     0,    22,    23,    24,    25,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    30,    13,    14,     0,    15,    16,    17,    18,    19,
      20,    21,     0,     0,     0,    22,    23,    24,    25,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    29,
      30,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,    83,    84,    85,    86,   115,     0,     0,
       0,     0,    83,    84,    85,    86,   126,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    74,    75,    76,    77,
      78,    79,    80,    81,    82,     0,     0,     0,     0,    83,
      84,    85,    86,   127,     0,     0,     0,     0,    83,    84,
      85,    86,   128,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,    83,    84,    85,    86,   163,
       0,     0,     0,     0,    83,    84,    85,    86,   188,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,     0,     0,
     143,    83,    84,    85,    86,     0,     0,     0,     0,   186,
      83,    84,    85,    86,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     7,     3,    11,    56,   116,    15,    42,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    26,
      26,    13,    34,    43,    42,    45,    42,    34,    26,    44,
      42,    46,    37,    38,    39,    40,     9,    10,     2,     3,
      27,    48,    44,    50,    49,    42,    52,    53,    54,    24,
      48,    46,    50,    46,    46,    56,    42,    42,    35,     6,
     169,    27,    46,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    46,    14,    27,    47,    27,    27,    47,    42,
     130,    46,    88,    89,    90,    37,    38,    39,    40,    95,
      14,    97,    27,    41,    46,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    47,    41,    44,    41,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    37,    38,    39,
      40,    27,   126,   129,   128,   131,    46,     4,    47,   130,
      37,    38,    39,    40,    34,    43,    45,   143,    36,    46,
      16,    17,    18,    19,    20,    21,    22,    23,   152,    46,
      45,   111,   165,   159,   158,   156,   117,   156,   164,   155,
     130,    37,    38,    39,    40,    -1,   108,   138,   162,   170,
     171,   170,   171,    -1,    -1,   176,    -1,   176,    28,    29,
      30,    31,    32,    33,   188,   186,    -1,   186,     0,     1,
      -1,     3,    42,     5,     6,     7,     8,    -1,    -1,    11,
      12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,     0,     1,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,     1,    -1,     3,    -1,     5,     6,
       7,     8,    -1,    -1,    11,    12,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    42,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,     1,    -1,     3,    -1,
       5,     6,     7,     8,    -1,    -1,    11,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,     1,    -1,
       3,    -1,     5,     6,     7,     8,    -1,    -1,    11,    12,
      13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,     1,    -1,     3,    -1,     5,     6,     7,     8,
      -1,    -1,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    51,    52,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    38,    39,    40,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    54,     1,     3,     5,     6,     7,     8,    11,
      12,    13,    14,    24,    25,    27,    28,    29,    30,    31,
      32,    33,    37,    38,    39,    40,    42,    43,    44,    51,
      52,    55,    56,    57,    68,    69,    71,    73,    74,    75,
      76,    77,    79,    82,    84,    85,    86,    87,     0,    55,
      55,    56,    42,    42,    42,    57,    42,    46,    46,    46,
      69,    75,    27,    61,    62,    64,    66,    27,    73,    42,
      42,    69,    43,    45,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    37,    38,    39,    40,    46,    70,    72,
      35,    24,    15,    26,    34,    48,    50,    78,    46,    73,
      69,    69,    69,     6,    75,    77,    83,    46,    34,    42,
      46,    47,    14,    27,    88,    41,     1,    14,    59,    69,
      69,    69,    27,    69,    27,    69,    41,    41,    41,    42,
      47,    46,    76,    14,    65,    27,    64,    41,    47,    41,
      59,    61,    58,    36,    49,    57,    44,    57,    69,    83,
      69,    27,    41,    88,    60,     1,    67,    69,     4,     9,
      10,    80,    81,    41,    46,    47,    46,    57,    63,    43,
      67,     1,    43,    56,    57,    69,    36,    45,    80,    46,
      69,    65,    59,    43,    56,    45,    36,    56,    41,    56,
      57
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 125 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 129 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, (yyvsp[(1) - (2)].cadena), identificadorFuncion, &flagFuncion, &flagVariable);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 131 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 143 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 148 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, tipo, identificadorFuncion, &flagFuncion, &flagVariable); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 152 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, (yyvsp[(1) - (2)].cadena), identificadorFuncion, &flagFuncion, &flagVariable); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 152 "../src/analizador.y"
    { tipo = strdup((yyvsp[(1) - (5)].cadena)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 153 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 158 "../src/analizador.y"
    {flagVariable = 1;;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 161 "../src/analizador.y"
    { identificadorFuncion = strdup((yyvsp[(1) - (5)].cadena)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 165 "../src/analizador.y"
    { flagFuncion = 1;;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 173 "../src/analizador.y"
    { pushParametro(&listaParametros, (yyvsp[(1) - (4)].cadena), (yyvsp[(2) - (4)].cadena));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 174 "../src/analizador.y"
    { pushParametro(&listaParametros, (yyvsp[(1) - (2)].cadena), (yyvsp[(2) - (2)].cadena));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 177 "../src/analizador.y"
    { pushNombreVariable(&listaNombreDeVariables, (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 178 "../src/analizador.y"
    { pushNombreVariable(&listaNombreDeVariables, (yyvsp[(1) - (3)].cadena)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 183 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 194 "../src/analizador.y"
    { validarOperacionBinaria(auxTipo1,auxTipo2); 
                                                              validacionBinaria=0;
                                                            ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 238 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"char",validacionBinaria); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 239 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"int",validacionBinaria);  ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 240 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"int",validacionBinaria);  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 241 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"int",validacionBinaria);  ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 242 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"char",validacionBinaria); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 243 "../src/analizador.y"
    { validacionBinaria = agregarTipo(auxTipo1,auxTipo2,"float",validacionBinaria);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 292 "../src/analizador.y"
    { chequearLlamadaFuncion((yyvsp[(1) - (4)].cadena), &parametrosLlamadaFuncion);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 296 "../src/analizador.y"
    { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 297 "../src/analizador.y"
    { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, (yyvsp[(1) - (3)].cadena));;}
    break;



/* Line 1455 of yacc.c  */
#line 1900 "analizador.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 300 "../src/analizador.y"


int main ()
{
    yyin = fopen("entrada.txt", "r");

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif

    yyparse ();
    fclose(yyin);

    // Reporte
    FILE* reporte = fopen("reporte.txt","w+b");

    printListFuncion(reporte, listaFunciones);
    printListVariable(reporte, listaVariables);

    // Errores
    printListErrorLexico(reporte, listaErroresLexicos);
    printListEstructuraInvalida(reporte, listaErroresSintacticos);
    printListErrorSemantico(reporte, listaErroresSemanticos);

    fclose(reporte);
}

