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
* myparser.h
* C header file generated from myparser.y.
* 
* Date: 07/11/18
* Time: 14:45:40
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MYPARSER_H
#define _MYPARSER_H

#include <yypars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 97 ".\\myparser.y"

	//����create�﷨��������--------------------
	char op;
	char *yych;				//������
	struct Createfieldsdef *cfdef_var;	//�ֶζ���
	struct fieldType *fT;			//type����
	struct Createstruct *cs_var;		//����create���
	//����insert���﷨��------------------------
	struct insertValue *is_val;
	//����select�﷨��������--------------------
	struct Selectedfields	*sf_var;	//��ѡ�ֶ�
	struct Selectedtables	*st_var;	//��ѡ���
	struct Conditions	*cons_var;	//�������
	struct Selectstruct	*ss_var;	//����select���
	//����update���﷨��------------------------
	struct Setstruct *s_var;

#line 53 "myparser.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

extern YYSTYPE YYNEAR yylval;

#define CREATE 257
#define SHOW 258
#define USE 259
#define DATABASES 260
#define DATABASE 261
#define TABLE 262
#define TABLES 263
#define CHAR 264
#define INT 265
#define SELECT 266
#define FROM 267
#define WHERE 268
#define OR 269
#define AND 270
#define QUOTE 271
#define INSERT 272
#define INTO 273
#define VALUES 274
#define UPDATE 275
#define SET 276
#define DELETE 277
#define DROP 278
#define EXIT 279
#define ID 280
#define NUMBER 281
#endif
