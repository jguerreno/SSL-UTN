
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
#line 2 "../src/analizador.y"


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "lib.h"
#include"sentencias.h"


#define YYDEBUG 1


int yylex(void);
extern int yylineno;
extern FILE *yyin;

void yyerror (const char *s) {}


//
EstructuraInvalidaNode* listaErroresSintacticos = NULL;

// 
SentenciaNode* listaSentencias = NULL;



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



/* Line 189 of yacc.c  */
#line 132 "analizador.tab.c"

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
#line 62 "../src/analizador.y"

    int entero;
    float real;
    char* cadena;



/* Line 214 of yacc.c  */
#line 209 "analizador.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 221 "analizador.tab.c"

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  182

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      49,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,    46,    39,     2,
      48,    47,    44,    43,    53,    42,    56,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    52,
      40,    34,    41,    35,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,    37,    51,    57,     2,     2,     2,
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
       0,     0,     3,     4,     7,    10,    12,    15,    17,    19,
      21,    23,    25,    27,    29,    31,    34,    35,    43,    44,
      45,    51,    53,    56,    62,    64,    66,    68,    72,    73,
      78,    81,    83,    87,    88,    91,    94,    97,    99,   105,
     109,   111,   113,   115,   117,   119,   121,   125,   127,   129,
     131,   133,   135,   137,   139,   141,   143,   145,   150,   153,
     156,   158,   160,   163,   165,   170,   174,   178,   180,   182,
     184,   186,   188,   190,   194,   198,   200,   202,   208,   216,
     224,   225,   228,   233,   237,   243,   251,   261,   263,   267,
     270,   273,   276,   280,   282,   284,   286,   288,   290,   292,
     297,   298,   300
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      60,     0,    -1,    -1,    60,    61,    -1,     1,    61,    -1,
      49,    -1,    14,    67,    -1,    62,    -1,    63,    -1,    74,
      -1,    85,    -1,    88,    -1,    90,    -1,    91,    -1,    49,
      -1,    50,    51,    -1,    -1,    50,    49,    65,    64,    73,
      49,    51,    -1,    -1,    -1,    14,    67,    66,    49,    65,
      -1,    68,    -1,    70,    52,    -1,    27,    48,    71,    47,
      69,    -1,    63,    -1,    52,    -1,    72,    -1,    72,    53,
      70,    -1,    -1,    14,    27,    53,    71,    -1,    14,    27,
      -1,    27,    -1,    27,    34,    82,    -1,    -1,    73,    62,
      -1,    75,    52,    -1,    83,    52,    -1,    77,    -1,    77,
      35,    75,    36,    75,    -1,    75,    76,    75,    -1,    93,
      -1,    42,    -1,    43,    -1,    44,    -1,    23,    -1,    79,
      -1,    75,    78,    75,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    19,    -1,    39,    -1,    20,    -1,    22,
      -1,    21,    -1,    80,    -1,    25,    48,    14,    47,    -1,
      24,    79,    -1,    92,    79,    -1,    82,    -1,    81,    -1,
      80,    24,    -1,    27,    -1,    81,    54,    75,    55,    -1,
      81,    56,    27,    -1,    81,    26,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    31,    -1,    32,    -1,    33,    -1,
      48,    75,    47,    -1,    81,    84,    75,    -1,    34,    -1,
      15,    -1,     3,    48,    75,    47,    63,    -1,     3,    48,
      75,    47,    63,     4,    63,    -1,     5,    48,    75,    47,
      50,    86,    51,    -1,    -1,    87,    86,    -1,     9,    75,
      36,    62,    -1,    10,    36,    62,    -1,     6,    48,    75,
      47,    63,    -1,     7,    63,     6,    48,    75,    47,    52,
      -1,     8,    48,    89,    52,    75,    52,    75,    47,    63,
      -1,    83,    -1,    83,    53,    89,    -1,    11,    52,    -1,
      12,    52,    -1,    13,    52,    -1,    13,    75,    52,    -1,
      39,    -1,    44,    -1,    43,    -1,    42,    -1,    57,    -1,
      58,    -1,    27,    48,    94,    47,    -1,    -1,    27,    -1,
      27,    53,    94,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   132,   133,   136,   137,   138,   143,   144,
     145,   146,   147,   148,   149,   152,   153,   153,   156,   157,
     157,   162,   163,   166,   169,   170,   173,   174,   177,   178,
     179,   182,   183,   186,   187,   190,   191,   196,   197,   198,
     199,   202,   203,   204,   205,   208,   209,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   223,   224,   225,   226,
     229,   230,   231,   234,   235,   236,   237,   240,   241,   242,
     243,   244,   245,   246,   249,   252,   253,   256,   257,   258,
     261,   262,   265,   266,   269,   270,   271,   274,   275,   278,
     279,   282,   283,   286,   287,   288,   289,   290,   291,   294,
     297,   298,   299
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
  "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'",
  "'/'", "'%'", "')'", "'('", "'\\n'", "'{'", "'}'", "';'", "','", "'['",
  "']'", "'.'", "'~'", "'!'", "$accept", "input", "line", "sentencia",
  "bloque_sentencias", "$@1", "declaracion_list", "$@2", "declaracion",
  "declaracion_funcion", "def_dec", "declaracion_variables",
  "listaParametros", "identVariable", "sentencia_list",
  "sentencia_expresion", "expresion", "operacion_matematica",
  "expresion_logica", "operacion_logica", "expresion_prefija",
  "expresion_postfija", "expresion_indexada", "expresion_constante",
  "asignacion", "operador_asignacion", "sentencia_bifurcacion",
  "sentencia_caso_list", "sentencia_caso", "sentencia_bucle",
  "lista_asignaciones", "sentencia_salto", "sentencia_retorno",
  "operador_unario", "llamada_funcion", "parametros", 0
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
     285,   286,   287,   288,    61,    63,    58,   124,    94,    38,
      60,    62,    45,    43,    42,    47,    37,    41,    40,    10,
     123,   125,    59,    44,    91,    93,    46,   126,    33
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    62,    62,    62,    62,    63,    64,    63,    65,    66,
      65,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    79,    79,    79,    79,
      80,    80,    80,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82,    82,    83,    84,    84,    85,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    89,    89,    90,
      90,    91,    91,    92,    92,    92,    92,    92,    92,    93,
      94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     7,     0,     0,
       5,     1,     2,     5,     1,     1,     1,     3,     0,     4,
       2,     1,     3,     0,     2,     2,     2,     1,     5,     3,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     2,     2,
       1,     1,     2,     1,     4,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     5,     7,     7,
       0,     2,     4,     3,     5,     7,     9,     1,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     4,
       0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    67,    68,    69,    70,    71,
      72,    93,    96,    95,    94,     0,     5,     0,    97,    98,
       4,     7,     8,     9,     0,    37,    45,    56,    61,    60,
       0,    10,    11,    12,    13,     0,    40,     1,     3,     0,
       0,     0,     0,     0,    89,    90,    91,     0,    61,    31,
       6,    21,     0,    26,    63,    58,     0,   100,     0,    18,
      15,    47,    48,    49,    50,    51,    53,    55,    54,    44,
      52,    41,    42,    43,    35,     0,     0,     0,    62,    76,
       0,    75,     0,     0,     0,    36,    59,     0,     0,     0,
       0,     0,    87,     0,    92,     0,    28,    22,     0,     0,
     101,     0,    73,     0,    16,    39,    46,     0,    66,     0,
      65,    74,     0,     0,     0,     0,     0,     0,    32,     0,
       0,    31,    27,    57,   100,    99,    19,    33,     0,    64,
      77,    80,    84,     0,    88,     0,    30,     0,   102,     0,
       0,    38,     0,     0,     0,     0,    80,     0,     0,    28,
      25,    24,    23,    18,    14,    34,    78,     0,     0,    79,
      81,    85,     0,    29,    20,    17,     0,    14,    83,     0,
      82,    86
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    30,    31,    32,   137,   114,   149,    60,    61,
     162,    62,   130,    63,   150,    33,    34,    85,    35,    86,
      36,    37,    58,    39,    40,    94,    41,   155,   156,    42,
     103,    43,    44,    45,    46,   111
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -143
static const yytype_int16 yypact[] =
{
      35,   206,   158,   -37,   -35,   -24,   -22,   -21,   -27,   -20,
     421,     3,   456,    -4,    -3,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,   478,  -143,   -44,  -143,  -143,
    -143,  -143,  -143,  -143,   346,    15,  -143,    27,    46,  -143,
       5,  -143,  -143,  -143,  -143,   456,  -143,  -143,  -143,   478,
     478,   478,    50,    31,  -143,  -143,  -143,   357,   -23,   -25,
    -143,  -143,    17,    18,  -143,  -143,    56,    49,   522,    59,
    -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,  -143,
    -143,  -143,  -143,  -143,  -143,   478,   478,   478,  -143,  -143,
      54,  -143,   478,    55,   478,  -143,  -143,   531,   564,   573,
      38,    46,    34,    36,  -143,   -11,    80,  -143,    68,    52,
      44,    57,  -143,     3,  -143,   687,   687,   648,  -143,    91,
    -143,   687,   -22,    51,   -22,   478,    31,   478,  -143,    76,
      58,    81,  -143,  -143,    49,  -143,  -143,  -143,   478,  -143,
     112,     6,  -143,   606,  -143,   395,    64,   -40,  -143,    69,
     254,   695,   -22,   478,    83,    70,     6,    71,   478,    80,
    -143,  -143,  -143,    59,    73,  -143,  -143,   657,   302,  -143,
    -143,  -143,   615,  -143,  -143,  -143,   302,  -143,  -143,   -22,
    -143,  -143
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   124,  -142,    -2,  -143,   -36,  -143,    19,  -143,
    -143,    20,   -19,  -143,  -143,  -143,     4,  -143,  -143,  -143,
      -6,  -143,    -1,    32,   -51,  -143,  -143,   -18,  -143,  -143,
      10,  -143,  -143,  -143,  -143,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      38,    38,   102,    90,    52,    69,    65,    70,   165,   105,
      27,    49,   160,    50,    57,   153,   154,    15,    16,    17,
      18,    19,    20,   106,    51,    54,   178,    53,    27,    68,
      59,    92,    55,    93,   180,    -2,     1,    25,    -2,    96,
      -2,    -2,    -2,    -2,    66,    67,    -2,    -2,    -2,    -2,
      87,    88,   101,    97,    98,    99,   100,    95,    64,    -2,
      -2,    89,    -2,    -2,    -2,    -2,    -2,    -2,    -2,   107,
     109,   108,    90,   113,    -2,   102,   110,    -2,    -2,    -2,
      91,   118,   120,    -2,    -2,    -2,   125,   126,   127,   115,
     116,   117,    -2,    -2,   129,   131,   119,   134,   121,   133,
      92,   141,    93,   146,   135,   147,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   105,   152,   159,   163,   168,
     140,   169,   142,   171,   175,   101,    48,   174,   132,   143,
      80,   145,   136,    81,    82,    83,   144,   128,   170,     0,
     173,   148,   151,     0,     0,   161,   139,     0,     0,    38,
     166,     0,     0,     0,     0,     0,     0,   167,    47,     0,
       0,     3,   172,     4,     5,     6,     7,    38,     0,     8,
       9,    10,    11,     0,     0,    38,     0,   181,     0,     0,
       0,     0,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
      22,    23,    24,     0,     0,     0,    25,    26,    27,     3,
       0,     4,     5,     6,     7,    28,    29,     8,     9,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,    22,    23,
      24,     0,     0,     0,    25,    26,    27,     3,     0,     4,
       5,     6,     7,    28,    29,     8,     9,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,    13,
       0,    14,    15,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,    22,    23,    24,     0,
       0,     0,    25,   164,    27,     3,     0,     4,     5,     6,
       7,    28,    29,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,    22,    23,    24,     0,     0,     0,
      25,   177,    27,     0,     0,     0,     0,     0,     0,    28,
      29,    71,    72,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,     0,    80,     0,     0,    81,    82,
      83,     0,     0,     0,     0,     0,    80,     0,    84,    81,
      82,    83,     0,     0,     0,     0,     0,     0,     0,   104,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,     0,     0,    81,    82,    83,
       0,     0,     0,     0,     0,    12,    13,   158,    14,    15,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,    22,    23,    24,     0,     0,     0,    25,
       0,     0,     0,    56,     0,     0,     0,     0,    28,    29,
      12,    13,     0,    64,    15,    16,    17,    18,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,    22,    23,
      24,     0,    12,    13,    25,    14,    15,    16,    17,    18,
      19,    20,     0,    28,    29,     0,     0,    21,     0,     0,
      22,    23,    24,     0,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,     0,     0,     0,
       0,    80,     0,     0,    81,    82,    83,     0,     0,   112,
      80,     0,     0,    81,    82,    83,     0,     0,   122,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    71,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
       0,     0,     0,    80,     0,     0,    81,    82,    83,     0,
       0,   123,    80,     0,     0,    81,    82,    83,     0,     0,
     124,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,    80,     0,     0,    81,    82,
      83,     0,     0,   157,    80,     0,     0,    81,    82,    83,
       0,     0,   179,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,     0,   138,     0,     0,    80,     0,     0,
      81,    82,    83,   176,     0,     0,    80,     0,     0,    81,
      82,    83,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,     0,     0,     0,     0,    80,     0,     0,    81,
      82,    83,     0,     0,    80,     0,     0,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       1,     2,    53,    26,     6,    49,    12,    51,   150,    34,
      50,    48,    52,    48,    10,     9,    10,    28,    29,    30,
      31,    32,    33,    48,    48,    52,   168,    48,    50,    25,
      27,    54,    52,    56,   176,     0,     1,    48,     3,    45,
       5,     6,     7,     8,    48,    48,    11,    12,    13,    14,
      35,    24,    53,    49,    50,    51,     6,    52,    27,    24,
      25,    15,    27,    28,    29,    30,    31,    32,    33,    52,
      14,    53,    26,    14,    39,   126,    27,    42,    43,    44,
      34,    27,    27,    48,    49,    50,    48,    53,    52,    85,
      86,    87,    57,    58,    14,    27,    92,    53,    94,    47,
      54,    50,    56,    27,    47,    47,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    34,     4,    53,    49,    36,
     122,    51,   124,    52,    51,   126,     2,   163,   108,   125,
      39,   127,   113,    42,    43,    44,   126,   105,   156,    -1,
     159,   134,   138,    -1,    -1,   147,    55,    -1,    -1,   150,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   153,     0,    -1,
      -1,     3,   158,     5,     6,     7,     8,   168,    -1,    11,
      12,    13,    14,    -1,    -1,   176,    -1,   179,    -1,    -1,
      -1,    -1,    24,    25,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    48,    49,    50,     3,
      -1,     5,     6,     7,     8,    57,    58,    11,    12,    13,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    48,    49,    50,     3,    -1,     5,
       6,     7,     8,    57,    58,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,    -1,
      -1,    -1,    48,    49,    50,     3,    -1,     5,     6,     7,
       8,    57,    58,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,
      48,    49,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    39,    -1,    52,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    24,    25,    52,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    42,    43,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    57,    58,
      24,    25,    -1,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    24,    25,    48,    27,    28,    29,    30,    31,
      32,    33,    -1,    57,    58,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,
      39,    -1,    -1,    42,    43,    44,    -1,    -1,    47,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    42,    43,    44,    -1,
      -1,    47,    39,    -1,    -1,    42,    43,    44,    -1,    -1,
      47,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,    43,
      44,    -1,    -1,    47,    39,    -1,    -1,    42,    43,    44,
      -1,    -1,    47,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    36,    -1,    -1,    39,    -1,    -1,
      42,    43,    44,    36,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    42,
      43,    44,    -1,    -1,    39,    -1,    -1,    42,    43,    44
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    60,     3,     5,     6,     7,     8,    11,    12,
      13,    14,    24,    25,    27,    28,    29,    30,    31,    32,
      33,    39,    42,    43,    44,    48,    49,    50,    57,    58,
      61,    62,    63,    74,    75,    77,    79,    80,    81,    82,
      83,    85,    88,    90,    91,    92,    93,     0,    61,    48,
      48,    48,    63,    48,    52,    52,    52,    75,    81,    27,
      67,    68,    70,    72,    27,    79,    48,    48,    75,    49,
      51,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      39,    42,    43,    44,    52,    76,    78,    35,    24,    15,
      26,    34,    54,    56,    84,    52,    79,    75,    75,    75,
       6,    81,    83,    89,    52,    34,    48,    52,    53,    14,
      27,    94,    47,    14,    65,    75,    75,    75,    27,    75,
      27,    75,    47,    47,    47,    48,    53,    52,    82,    14,
      71,    27,    70,    47,    53,    47,    67,    64,    36,    55,
      63,    50,    63,    75,    89,    75,    27,    47,    94,    66,
      73,    75,     4,     9,    10,    86,    87,    47,    52,    53,
      52,    63,    69,    49,    49,    62,    63,    75,    36,    51,
      86,    52,    75,    71,    65,    51,    36,    49,    62,    47,
      62,    63
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
#line 133 "../src/analizador.y"
    { pushEstructuraInvalida(&listaErroresSintacticos, yylineno-1); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 137 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, (yyvsp[(1) - (2)].cadena), identificadorFuncion, &flagFuncion, &flagVariable);;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 143 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia Compuesta");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 144 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia Expresion");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 145 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia Seleccion");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 146 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia Iteracion");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 147 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia Salto");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 148 "../src/analizador.y"
    { addSentencia(&listaSentencias, "Sentencia de Retorno");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, tipo, identificadorFuncion, &flagFuncion, &flagVariable); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "../src/analizador.y"
    { declaracionFuncionVariable(&listaParametros, &listaNombreDeVariables, (yyvsp[(1) - (2)].cadena), identificadorFuncion, &flagFuncion, &flagVariable); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 157 "../src/analizador.y"
    { tipo = strdup((yyvsp[(1) - (5)].cadena)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 163 "../src/analizador.y"
    {flagVariable = 1;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 166 "../src/analizador.y"
    { identificadorFuncion = strdup((yyvsp[(1) - (5)].cadena)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 170 "../src/analizador.y"
    { flagFuncion = 1;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 178 "../src/analizador.y"
    { pushParametro(&listaParametros, (yyvsp[(1) - (4)].cadena), (yyvsp[(2) - (4)].cadena));;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 179 "../src/analizador.y"
    { pushParametro(&listaParametros, (yyvsp[(1) - (2)].cadena), (yyvsp[(2) - (2)].cadena));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 182 "../src/analizador.y"
    { pushNombreVariable(&listaNombreDeVariables, (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 183 "../src/analizador.y"
    { pushNombreVariable(&listaNombreDeVariables, (yyvsp[(1) - (3)].cadena)); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 294 "../src/analizador.y"
    { chequearLlamadaFuncion((yyvsp[(1) - (4)].cadena), &parametrosLlamadaFuncion);;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 298 "../src/analizador.y"
    { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, (yyvsp[(1) - (1)].cadena));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 299 "../src/analizador.y"
    { addParametroLlamadaFuncion(&parametrosLlamadaFuncion, (yyvsp[(1) - (3)].cadena));;}
    break;



/* Line 1455 of yacc.c  */
#line 1848 "analizador.tab.c"
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
#line 302 "../src/analizador.y"



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
    printListSentencia(reporte, listaSentencias);
    // Errores
    printListErrorLexico(reporte, listaErroresLexicos);
    printListEstructuraInvalida(reporte, listaErroresSintacticos);
    printListErrorSemantico(reporte, listaErroresSemanticos);

    fclose(reporte);
}


// Mirar
// Sentencias           X
// Variables            X
// Funciones            X

// Errores
// Lexicos              X
// Sintacticos          
// Semanticos           
//      Variables       
//      Funciones       
//      OB              

// 1. Makefile
// 2. Emprolijar el codigo
// 3. Errores sintacticos
// 4. OPCIONAL error sintactico imprimir linea
// 5. Fijarse si falta algo o si hay algo de mas
