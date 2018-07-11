/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 2 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* mylexer.c
* C source file generated from mylexer.l.
* 
* Date: 07/11/18
* Time: 14:45:40
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\mylexer.l"

/****************************************************************************
mylexer.l
ParserWizard generated Lex file.

Date: 2018Äê7ÔÂ10ÈÕ
****************************************************************************/

#include "myparser.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#line 54 "mylexer.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\mylexer.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 52 ".\\mylexer.l"
;
#line 175 "mylexer.c"
		}
		break;
	case 2:
		{
#line 54 ".\\mylexer.l"
return CREATE;
#line 182 "mylexer.c"
		}
		break;
	case 3:
		{
#line 55 ".\\mylexer.l"
return USE;
#line 189 "mylexer.c"
		}
		break;
	case 4:
		{
#line 56 ".\\mylexer.l"
return SHOW;
#line 196 "mylexer.c"
		}
		break;
	case 5:
		{
#line 57 ".\\mylexer.l"
return INSERT;
#line 203 "mylexer.c"
		}
		break;
	case 6:
		{
#line 58 ".\\mylexer.l"
return SELECT;
#line 210 "mylexer.c"
		}
		break;
	case 7:
		{
#line 59 ".\\mylexer.l"
return UPDATE;
#line 217 "mylexer.c"
		}
		break;
	case 8:
		{
#line 60 ".\\mylexer.l"
return SET;
#line 224 "mylexer.c"
		}
		break;
	case 9:
		{
#line 61 ".\\mylexer.l"
return DELETE;
#line 231 "mylexer.c"
		}
		break;
	case 10:
		{
#line 62 ".\\mylexer.l"
return DROP;
#line 238 "mylexer.c"
		}
		break;
	case 11:
		{
#line 63 ".\\mylexer.l"
return INTO;
#line 245 "mylexer.c"
		}
		break;
	case 12:
		{
#line 64 ".\\mylexer.l"
return VALUES;
#line 252 "mylexer.c"
		}
		break;
	case 13:
		{
#line 65 ".\\mylexer.l"
return FROM;
#line 259 "mylexer.c"
		}
		break;
	case 14:
		{
#line 66 ".\\mylexer.l"
return WHERE;
#line 266 "mylexer.c"
		}
		break;
	case 15:
		{
#line 67 ".\\mylexer.l"
return AND;
#line 273 "mylexer.c"
		}
		break;
	case 16:
		{
#line 68 ".\\mylexer.l"
return OR;
#line 280 "mylexer.c"
		}
		break;
	case 17:
		{
#line 69 ".\\mylexer.l"
return EXIT;
#line 287 "mylexer.c"
		}
		break;
	case 18:
		{
#line 70 ".\\mylexer.l"
return TABLE;
#line 294 "mylexer.c"
		}
		break;
	case 19:
		{
#line 71 ".\\mylexer.l"
return TABLES;
#line 301 "mylexer.c"
		}
		break;
	case 20:
		{
#line 72 ".\\mylexer.l"
return DATABASE;
#line 308 "mylexer.c"
		}
		break;
	case 21:
		{
#line 73 ".\\mylexer.l"
return DATABASES;
#line 315 "mylexer.c"
		}
		break;
	case 22:
		{
#line 74 ".\\mylexer.l"
return CHAR;
#line 322 "mylexer.c"
		}
		break;
	case 23:
		{
#line 75 ".\\mylexer.l"
return INT;
#line 329 "mylexer.c"
		}
		break;
	case 24:
		{
#line 76 ".\\mylexer.l"

	yylval.yych=(char *)malloc(strlen(yytext)+1); 
	strcpy(yylval.yych, yytext);
	return ID;

#line 340 "mylexer.c"
		}
		break;
	case 25:
		{
#line 81 ".\\mylexer.l"

	yylval.yych=(char *)malloc(strlen(yytext)+1); 
	strcpy(yylval.yych, yytext);
	return NUMBER;

#line 351 "mylexer.c"
		}
		break;
	case 26:
		{
#line 87 ".\\mylexer.l"
return ';';
#line 358 "mylexer.c"
		}
		break;
	case 27:
		{
#line 88 ".\\mylexer.l"
return '(';
#line 365 "mylexer.c"
		}
		break;
	case 28:
		{
#line 89 ".\\mylexer.l"
return ')';
#line 372 "mylexer.c"
		}
		break;
	case 29:
		{
#line 90 ".\\mylexer.l"
return ',';
#line 379 "mylexer.c"
		}
		break;
	case 30:
		{
#line 91 ".\\mylexer.l"
return '.';
#line 386 "mylexer.c"
		}
		break;
	case 31:
		{
#line 92 ".\\mylexer.l"
return '!';
#line 393 "mylexer.c"
		}
		break;
	case 32:
		{
#line 93 ".\\mylexer.l"
return '=';
#line 400 "mylexer.c"
		}
		break;
	case 33:
		{
#line 94 ".\\mylexer.l"
return '<';
#line 407 "mylexer.c"
		}
		break;
	case 34:
		{
#line 95 ".\\mylexer.l"
return '>';
#line 414 "mylexer.c"
		}
		break;
	case 35:
		{
#line 96 ".\\mylexer.l"
return QUOTE;
#line 421 "mylexer.c"
		}
		break;
	case 36:
		{
#line 97 ".\\mylexer.l"
return '+';
#line 428 "mylexer.c"
		}
		break;
	case 37:
		{
#line 98 ".\\mylexer.l"
return '-';
#line 435 "mylexer.c"
		}
		break;
	case 38:
		{
#line 99 ".\\mylexer.l"
return '*';
#line 442 "mylexer.c"
		}
		break;
	case 39:
		{
#line 100 ".\\mylexer.l"
return '/';
#line 449 "mylexer.c"
		}
		break;
	case 40:
		{
#line 101 ".\\mylexer.l"
return 0;
#line 456 "mylexer.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 310;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 3, 1 },
	{ 53, 34 },
	{ 0, 33 },
	{ 53, 34 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 52, 52 },
	{ 4, 4 },
	{ 0, 0 },
	{ 65, 45 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 35, 20 },
	{ 4, 1 },
	{ 5, 1 },
	{ 66, 45 },
	{ 34, 52 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 6, 1 },
	{ 7, 1 },
	{ 8, 1 },
	{ 9, 1 },
	{ 10, 1 },
	{ 11, 1 },
	{ 12, 1 },
	{ 13, 1 },
	{ 14, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 15, 1 },
	{ 65, 45 },
	{ 16, 1 },
	{ 17, 1 },
	{ 18, 1 },
	{ 19, 1 },
	{ 35, 20 },
	{ 36, 22 },
	{ 20, 1 },
	{ 66, 45 },
	{ 22, 1 },
	{ 23, 1 },
	{ 24, 1 },
	{ 25, 1 },
	{ 47, 29 },
	{ 45, 28 },
	{ 26, 1 },
	{ 37, 22 },
	{ 46, 28 },
	{ 41, 24 },
	{ 48, 30 },
	{ 50, 31 },
	{ 27, 1 },
	{ 49, 30 },
	{ 63, 43 },
	{ 64, 43 },
	{ 28, 1 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 0 },
	{ 0, 1 },
	{ 36, 22 },
	{ 20, 1 },
	{ 51, 32 },
	{ 22, 1 },
	{ 23, 1 },
	{ 24, 1 },
	{ 25, 1 },
	{ 47, 29 },
	{ 45, 28 },
	{ 26, 1 },
	{ 37, 22 },
	{ 46, 28 },
	{ 41, 24 },
	{ 48, 30 },
	{ 50, 31 },
	{ 27, 1 },
	{ 49, 30 },
	{ 63, 43 },
	{ 64, 43 },
	{ 28, 1 },
	{ 29, 1 },
	{ 30, 1 },
	{ 31, 1 },
	{ 32, 1 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 51, 32 },
	{ 55, 35 },
	{ 56, 36 },
	{ 57, 37 },
	{ 58, 38 },
	{ 0, 0 },
	{ 59, 39 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 55, 35 },
	{ 56, 36 },
	{ 57, 37 },
	{ 58, 38 },
	{ 21, 107 },
	{ 59, 39 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 21, 107 },
	{ 38, 23 },
	{ 60, 40 },
	{ 61, 41 },
	{ 62, 42 },
	{ 39, 23 },
	{ 42, 25 },
	{ 43, 26 },
	{ 67, 46 },
	{ 68, 47 },
	{ 69, 48 },
	{ 70, 49 },
	{ 71, 50 },
	{ 72, 51 },
	{ 73, 56 },
	{ 74, 57 },
	{ 75, 58 },
	{ 76, 59 },
	{ 40, 23 },
	{ 77, 60 },
	{ 78, 61 },
	{ 79, 62 },
	{ 80, 63 },
	{ 81, 64 },
	{ 82, 65 },
	{ 83, 67 },
	{ 84, 68 },
	{ 85, 69 },
	{ 86, 71 },
	{ 87, 72 },
	{ 88, 74 },
	{ 89, 75 },
	{ 90, 76 },
	{ 38, 23 },
	{ 60, 40 },
	{ 61, 41 },
	{ 62, 42 },
	{ 39, 23 },
	{ 42, 25 },
	{ 43, 26 },
	{ 67, 46 },
	{ 68, 47 },
	{ 69, 48 },
	{ 70, 49 },
	{ 71, 50 },
	{ 72, 51 },
	{ 73, 56 },
	{ 74, 57 },
	{ 75, 58 },
	{ 76, 59 },
	{ 40, 23 },
	{ 77, 60 },
	{ 78, 61 },
	{ 79, 62 },
	{ 80, 63 },
	{ 81, 64 },
	{ 82, 65 },
	{ 83, 67 },
	{ 84, 68 },
	{ 85, 69 },
	{ 86, 71 },
	{ 87, 72 },
	{ 88, 74 },
	{ 89, 75 },
	{ 90, 76 },
	{ 91, 80 },
	{ 92, 82 },
	{ 93, 84 },
	{ 94, 85 },
	{ 95, 86 },
	{ 96, 87 },
	{ 97, 88 },
	{ 98, 89 },
	{ 99, 90 },
	{ 100, 91 },
	{ 101, 92 },
	{ 102, 93 },
	{ 103, 94 },
	{ 104, 95 },
	{ 105, 98 },
	{ 106, 105 },
	{ 107, 106 },
	{ 44, 27 },
	{ 33, 15 },
	{ 0, 0 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 15, 15 },
	{ 0, 0 },
	{ 0, 0 },
	{ 91, 80 },
	{ 92, 82 },
	{ 93, 84 },
	{ 94, 85 },
	{ 95, 86 },
	{ 96, 87 },
	{ 97, 88 },
	{ 98, 89 },
	{ 99, 90 },
	{ 100, 91 },
	{ 101, 92 },
	{ 102, 93 },
	{ 103, 94 },
	{ 104, 95 },
	{ 105, 98 },
	{ 106, 105 },
	{ 107, 106 },
	{ 44, 27 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 },
	{ 54, 54 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 107, -9, 0 },
	{ 1, 0, 0 },
	{ 0, 0, 40 },
	{ 0, -17, 1 },
	{ 0, 0, 31 },
	{ 0, 0, 35 },
	{ 0, 0, 27 },
	{ 0, 0, 28 },
	{ 0, 0, 38 },
	{ 0, 0, 36 },
	{ 0, 0, 29 },
	{ 0, 0, 37 },
	{ 0, 0, 30 },
	{ 0, 0, 39 },
	{ 52, 222, 25 },
	{ 0, 0, 26 },
	{ 0, 0, 33 },
	{ 0, 0, 32 },
	{ 0, 0, 34 },
	{ 107, -56, 24 },
	{ 107, 0, 24 },
	{ 107, -17, 24 },
	{ 107, 121, 24 },
	{ 107, -21, 24 },
	{ 107, 109, 24 },
	{ 107, 114, 24 },
	{ 107, 185, 24 },
	{ 107, -6, 24 },
	{ 107, -3, 24 },
	{ 107, -12, 24 },
	{ 107, 4, 24 },
	{ 107, 17, 24 },
	{ 52, -66, 0 },
	{ 54, -41, 0 },
	{ 107, 54, 24 },
	{ 107, 58, 24 },
	{ 107, 55, 24 },
	{ 107, 41, 24 },
	{ 107, 51, 24 },
	{ 107, 108, 24 },
	{ 107, 115, 24 },
	{ 107, 110, 24 },
	{ 107, -11, 24 },
	{ 107, 0, 16 },
	{ 107, -59, 24 },
	{ 107, 114, 24 },
	{ 107, 128, 24 },
	{ 107, 127, 24 },
	{ 107, 127, 24 },
	{ 107, 121, 24 },
	{ 107, 129, 24 },
	{ 0, -43, 25 },
	{ 54, 0, 0 },
	{ 0, 252, 25 },
	{ 107, 0, 15 },
	{ 107, 117, 24 },
	{ 107, 135, 24 },
	{ 107, 136, 24 },
	{ 107, 133, 24 },
	{ 107, 124, 24 },
	{ 107, 121, 24 },
	{ 107, 129, 24 },
	{ 107, 138, 24 },
	{ 107, 129, 23 },
	{ 107, 140, 24 },
	{ 107, 0, 8 },
	{ 107, 123, 24 },
	{ 107, 135, 24 },
	{ 107, 147, 24 },
	{ 107, 0, 3 },
	{ 107, 128, 24 },
	{ 107, 132, 24 },
	{ 107, 0, 22 },
	{ 107, 131, 24 },
	{ 107, 150, 24 },
	{ 107, 133, 24 },
	{ 107, 0, 10 },
	{ 107, 0, 17 },
	{ 107, 0, 13 },
	{ 107, 168, 24 },
	{ 107, 0, 11 },
	{ 107, 184, 24 },
	{ 107, 0, 4 },
	{ 107, 183, 24 },
	{ 107, 169, 24 },
	{ 107, 185, 24 },
	{ 107, 186, 24 },
	{ 107, 187, 24 },
	{ 107, 192, 24 },
	{ 107, 189, 24 },
	{ 107, 175, 24 },
	{ 107, 176, 24 },
	{ 107, 178, 18 },
	{ 107, 193, 24 },
	{ 107, 180, 24 },
	{ 107, 0, 14 },
	{ 107, 0, 2 },
	{ 107, 181, 24 },
	{ 107, 0, 9 },
	{ 107, 0, 5 },
	{ 107, 0, 6 },
	{ 107, 0, 19 },
	{ 107, 0, 7 },
	{ 107, 0, 12 },
	{ 107, 196, 24 },
	{ 107, 183, 20 },
	{ 0, 63, 21 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 104 ".\\mylexer.l"


