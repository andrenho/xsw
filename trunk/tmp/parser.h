/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ENTER = 258,
     EQUALS = 259,
     SET = 260,
     COLON = 261,
     AT = 262,
     PLUS = 263,
     MINUS = 264,
     MULTIPLY = 265,
     DIVIDE = 266,
     LPAREN = 267,
     RPAREN = 268,
     MORE_THAN = 269,
     LESS_THAN = 270,
     LESS_EQUAL = 271,
     MORE_EQUAL = 272,
     WHILE = 273,
     END = 274,
     DEF = 275,
     ID = 276,
     VARIABLE = 277,
     NUMBER = 278,
     STRING = 279
   };
#endif
/* Tokens.  */
#define ENTER 258
#define EQUALS 259
#define SET 260
#define COLON 261
#define AT 262
#define PLUS 263
#define MINUS 264
#define MULTIPLY 265
#define DIVIDE 266
#define LPAREN 267
#define RPAREN 268
#define MORE_THAN 269
#define LESS_THAN 270
#define LESS_EQUAL 271
#define MORE_EQUAL 272
#define WHILE 273
#define END 274
#define DEF 275
#define ID 276
#define VARIABLE 277
#define NUMBER 278
#define STRING 279




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



