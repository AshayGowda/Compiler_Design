/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     DO = 260,
     WHILE = 261,
     RETURN = 262,
     VOID = 263,
     INT = 264,
     FLOAT = 265,
     CHAR = 266,
     INC_OP = 267,
     DEC_OP = 268,
     PLUS = 269,
     MINUS = 270,
     STAR = 271,
     SLASH = 272,
     LT = 273,
     LTEQ = 274,
     GT = 275,
     GTEQ = 276,
     EQ = 277,
     NEQ = 278,
     ASSIGN = 279,
     SEMI = 280,
     COMMA = 281,
     LPAREN = 282,
     RPAREN = 283,
     LSQUAR = 284,
     RSQUAR = 285,
     LBRACE = 286,
     RBRACE = 287,
     LCOMMENT = 288,
     RCOMMENT = 289,
     ID = 290,
     NUM = 291,
     FLT = 292,
     CHR = 293,
     LETTER = 294,
     DIGIT = 295,
     NONTOKEN = 296,
     ERROR = 297,
     ENDFILE = 298,
     PRINTF = 299,
     NL = 300,
     ENDL = 301,
     STR = 302,
     PREPROC = 303,
     NEW = 304,
     THEN = 305,
     LOWER_THAN_IF = 306
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define DO 260
#define WHILE 261
#define RETURN 262
#define VOID 263
#define INT 264
#define FLOAT 265
#define CHAR 266
#define INC_OP 267
#define DEC_OP 268
#define PLUS 269
#define MINUS 270
#define STAR 271
#define SLASH 272
#define LT 273
#define LTEQ 274
#define GT 275
#define GTEQ 276
#define EQ 277
#define NEQ 278
#define ASSIGN 279
#define SEMI 280
#define COMMA 281
#define LPAREN 282
#define RPAREN 283
#define LSQUAR 284
#define RSQUAR 285
#define LBRACE 286
#define RBRACE 287
#define LCOMMENT 288
#define RCOMMENT 289
#define ID 290
#define NUM 291
#define FLT 292
#define CHR 293
#define LETTER 294
#define DIGIT 295
#define NONTOKEN 296
#define ERROR 297
#define ENDFILE 298
#define PRINTF 299
#define NL 300
#define ENDL 301
#define STR 302
#define PREPROC 303
#define NEW 304
#define THEN 305
#define LOWER_THAN_IF 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 342 "parser.y"
{
	char chr;
	int integer;
	float ft;
	char *str;
}
/* Line 1529 of yacc.c.  */
#line 158 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

