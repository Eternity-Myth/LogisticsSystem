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
* myparser.c
* C source file generated from myparser.y.
* 
* Date: 07/11/18
* Time: 14:45:40
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\myparser.y"

/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018年7月10日
****************************************************************************/
#include "mylexer.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>
#include<io.h>

char database[100]={0};	//数据库名称
char rootDir[100]={0};	//文件保存路径
enum TYPE {INT,CHAR};	//字段可用类型
//create语句中的字段定义-------------------------------------------------
struct Createfieldsdef{		
	char		*field;			//字段名称
	enum TYPE	type;			//字段类型
	int			length;		//字段长度
	struct	Createfieldsdef	*next_fdef;	//下一字段
};
//type字段定义-----------------------------------------------------------
struct fieldType{
	enum TYPE	type;			//字段类型
	int		length;			//字段长度
};
//create语法树根节点-----------------------------------------------------
struct Createstruct{		
	char *table;				  //基本表名称
	struct	Createfieldsdef *fdef;//字段定义
};
//insert语法树根节点-----------------------------------------------------
struct insertValue {
    char *value;				  //插入值
    struct insertValue *next_Value;		  //下一插入值
};
//select条件-------------------------------------------------------------
struct Conditions{
	struct Conditions *left;		//左部条件
	struct Conditions *right;		//右部条件
	char comp_op;				/* 'a'是and, 'o'是or, '<' , '>' , '=', ‘!='  */
	int type;				/* 0是字段，1是字符串，2是整数 */
	char *value;				/* 根据type存放字段名、字符串或整数 */
	char *table;				/* NULL或表名 */
}; 
//select语句中选中的字段-------------------------------------------------
struct	Selectedfields{
	char 	*table;				//字段所属表
	char 	*field;				//字段名称
	struct 	Selectedfields	*next_sf;	//下一个字段
};
//select语句中选中的表---------------------------------------------------
struct	Selectedtables{
	char	  *table;			//基本表名称
	struct  Selectedtables  *next_st;	//下一个表
};
//select语法树的根节点---------------------------------------------------
struct	Selectstruct{
	struct Selectedfields 	*sf;		//所选字段
	struct Selectedtables	*st;		//所选基本表
	struct Conditions	*cons;		//条件
};
//set语法树根节点--------------------------------------------------------
struct Setstruct{
    char *field;					//需更改字段
    char *value;					//更改值
    struct Setstruct *next_sf;				//需更改下一字段
};

//函数声明列表：
void createDB();//创建数据库
void getDB();//获取所有数据库名字
void useDB();//选择数据库
void dropDB();//删除数据库
void createTable(struct Createstruct *cs_root);//创建表
void getTable();//显示表信息
void dropTable(char *tableName);//删除表
void insertOrder(char *tableName,struct insertValue *values);//按顺序插入数据
void insertNoOrder(char *tableName,struct insertValue *valuesNames,struct insertValue *values);//自定义顺序插入数据
int CdtSearch(struct Conditions *conditionRoot, int totField, char allField[][100], char value[][100]);//匹配条件式的ID,找到需更新/查询的行
void freeCdt(struct Conditions *conditionRoot);//释放condition指针
void updateAll(char *tableName,struct Setstruct *setRoot);//修改所有数据
void updateCdt(char *tableName,struct Setstruct *setRoot,struct Conditions *conditionRoot);//修改选定属性的数据
void selectNoCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot);//无条件查询
void selectCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot,struct Conditions *conditionRoot);//有条件查询
void deleteAll(char *tableName);//删除表格内所有数据
void deleteCdt(char *tableName,struct Conditions *conditionRoot);//删除表格内某个数据
void handle(int read_line[],int count_value[],int all_table,int index);//笛卡尔乘积递归



#line 135 "myparser.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\myparser.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 139 ".\\myparser.y"

		yyval.cs_var=(struct Createstruct *)malloc(sizeof(struct Createstruct));
		yyval.cs_var->table=yyattribute(3 - 7).yych;
		yyval.cs_var->fdef=yyattribute(5 - 7).cfdef_var;
		createTable(yyval.cs_var);
	  
#line 266 "myparser.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 146 ".\\myparser.y"

		strcpy(database,yyattribute(3 - 4).yych);
		createDB();
	  
#line 282 "myparser.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 151 ".\\myparser.y"

		yyval.yych=yyattribute(1 - 1).yych;
	  
#line 297 "myparser.c"
			}
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 155 ".\\myparser.y"

		yyval.cfdef_var=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		yyval.cfdef_var->field=yyattribute(1 - 1).cfdef_var->field;
		yyval.cfdef_var->type=yyattribute(1 - 1).cfdef_var->type;
		yyval.cfdef_var->length=yyattribute(1 - 1).cfdef_var->length;
		yyval.cfdef_var->next_fdef=NULL;
	  
#line 316 "myparser.c"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 163 ".\\myparser.y"

		yyval.cfdef_var=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		yyval.cfdef_var->field=yyattribute(1 - 3).cfdef_var->field;
		yyval.cfdef_var->type=yyattribute(1 - 3).cfdef_var->type;
		yyval.cfdef_var->length=yyattribute(1 - 3).cfdef_var->length;
		yyval.cfdef_var->next_fdef=yyattribute(3 - 3).cfdef_var;
	  
#line 335 "myparser.c"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 171 ".\\myparser.y"

		yyval.cfdef_var=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		yyval.cfdef_var->field=yyattribute(1 - 2).yych;
		yyval.cfdef_var->type=yyattribute(2 - 2).fT->type;
		yyval.cfdef_var->length=yyattribute(2 - 2).fT->length;
	  
#line 353 "myparser.c"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 178 ".\\myparser.y"

		yyval.yych=yyattribute(1 - 1).yych;
	  
#line 368 "myparser.c"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 182 ".\\myparser.y"

		yyval.fT=(struct fieldType *)malloc(sizeof(struct fieldType));
		yyval.fT->type=CHAR;
		yyval.fT->length=atoi(yyattribute(3 - 4).yych);
	  
#line 385 "myparser.c"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 188 ".\\myparser.y"

		yyval.fT=(struct fieldType *)malloc(sizeof(struct fieldType));
		yyval.fT->type=INT;
		yyval.fT->length=4;
	  
#line 402 "myparser.c"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 194 ".\\myparser.y"

	    strcpy(database,yyattribute(2 - 3).yych);
	    useDB();
       
#line 418 "myparser.c"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 199 ".\\myparser.y"

		printf("Database:\n");
		getDB();
	 
#line 434 "myparser.c"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 204 ".\\myparser.y"

		printf("Tables:\n");
		getTable();
	 
#line 450 "myparser.c"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 209 ".\\myparser.y"

		selectNoCdt(yyattribute(2 - 5).sf_var,yyattribute(4 - 5).st_var);
	  
#line 465 "myparser.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 213 ".\\myparser.y"

		selectCdt(yyattribute(2 - 7).sf_var,yyattribute(4 - 7).st_var,yyattribute(6 - 7).cons_var);
	  
#line 480 "myparser.c"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 217 ".\\myparser.y"

		yyval.sf_var =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var=yyattribute(1 - 1).sf_var;
	  
#line 496 "myparser.c"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 222 ".\\myparser.y"

		yyval.sf_var =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var=NULL;
	  
#line 512 "myparser.c"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 227 ".\\myparser.y"

		yyval.sf_var =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var=yyattribute(1 - 1).sf_var;
	  
#line 528 "myparser.c"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 232 ".\\myparser.y"

		yyval.sf_var =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var->field=yyattribute(1 - 3).sf_var->field;
		yyval.sf_var->table=yyattribute(1 - 3).sf_var->table;
		yyval.sf_var->next_sf=yyattribute(3 - 3).sf_var;
	  
#line 546 "myparser.c"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 239 ".\\myparser.y"

		yyval.sf_var=(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var->field=yyattribute(1 - 1).yych;
		yyval.sf_var->table=NULL;
		yyval.sf_var->next_sf=NULL;
	  
#line 564 "myparser.c"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 246 ".\\myparser.y"

		yyval.sf_var=(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		yyval.sf_var->field=yyattribute(3 - 3).yych;
		yyval.sf_var->table=yyattribute(1 - 3).yych;
		yyval.sf_var->next_sf=NULL;
	  
#line 582 "myparser.c"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 253 ".\\myparser.y"

		yyval.st_var=(struct Selectedtables *)malloc(sizeof(struct Selectedtables));
		yyval.st_var->table=yyattribute(1 - 1).yych;
		yyval.st_var->next_st=NULL;
	  
#line 599 "myparser.c"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 259 ".\\myparser.y"

		yyval.st_var=(struct Selectedtables *)malloc(sizeof (struct Selectedtables));
		yyval.st_var->table=yyattribute(1 - 3).yych;
		yyval.st_var->next_st=yyattribute(3 - 3).st_var;
	  
#line 616 "myparser.c"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 265 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var=yyattribute(1 - 1).cons_var;
	  
#line 632 "myparser.c"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 270 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var=yyattribute(2 - 3).cons_var;
	  
#line 648 "myparser.c"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 275 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->left=yyattribute(1 - 3).cons_var;
		yyval.cons_var->right=yyattribute(3 - 3).cons_var;
		yyval.cons_var->comp_op='a';
	  
#line 666 "myparser.c"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 282 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->left=yyattribute(1 - 3).cons_var;
		yyval.cons_var->right=yyattribute(3 - 3).cons_var;
		yyval.cons_var->comp_op='o';
	  
#line 684 "myparser.c"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 289 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->left=yyattribute(1 - 3).cons_var;
		yyval.cons_var->right=yyattribute(3 - 3).cons_var;
		yyval.cons_var->comp_op=yyattribute(2 - 3).op;
	  
#line 702 "myparser.c"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 296 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->type=0;
		yyval.cons_var->value=yyattribute(1 - 1).sf_var->field;
		yyval.cons_var->table=yyattribute(1 - 1).sf_var->table;
		yyval.cons_var->left=NULL;
		yyval.cons_var->right=NULL;
	 
#line 722 "myparser.c"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 305 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->type=0;
		yyval.cons_var->value=yyattribute(1 - 1).sf_var->field;
		yyval.cons_var->table=yyattribute(1 - 1).sf_var->table;
		yyval.cons_var->left=NULL;
		yyval.cons_var->right=NULL;
	 
#line 742 "myparser.c"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 314 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->type=2;
		yyval.cons_var->value=yyattribute(1 - 1).yych;
		yyval.cons_var->table=NULL;
		yyval.cons_var->left=NULL;
		yyval.cons_var->right=NULL;
	 
#line 762 "myparser.c"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 323 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->type=1;
		yyval.cons_var->value=yyattribute(2 - 3).yych;
		yyval.cons_var->table=NULL;
		yyval.cons_var->left=NULL;
		yyval.cons_var->right=NULL;
	 
#line 782 "myparser.c"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 332 ".\\myparser.y"

		yyval.cons_var=(struct Conditions *)malloc(sizeof(struct Conditions));
		yyval.cons_var->type=1;
		yyval.cons_var->value=yyattribute(2 - 3).yych;
		yyval.cons_var->table=NULL;
		yyval.cons_var->left=NULL;
		yyval.cons_var->right=NULL;
	 
#line 802 "myparser.c"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 341 ".\\myparser.y"

		yyval.op='<';
	 
#line 817 "myparser.c"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 345 ".\\myparser.y"

		yyval.op='>';
	 
#line 832 "myparser.c"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 349 ".\\myparser.y"

		yyval.op='=';
	 
#line 847 "myparser.c"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 353 ".\\myparser.y"

		yyval.op='!';
	 
#line 862 "myparser.c"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[9];
			yyinitdebug(yya, 9);
#endif
			{
#line 357 ".\\myparser.y"

		insertOrder(yyattribute(3 - 8).yych,yyattribute(6 - 8).is_val);
	  
#line 877 "myparser.c"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[12];
			yyinitdebug(yya, 12);
#endif
			{
#line 361 ".\\myparser.y"

		insertNoOrder(yyattribute(3 - 11).yych,yyattribute(5 - 11).is_val,yyattribute(9 - 11).is_val);
	  
#line 892 "myparser.c"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 365 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(1 - 1).is_val->value;
		yyval.is_val->next_Value=NULL;
	  
#line 909 "myparser.c"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 371 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(1 - 3).is_val->value;
		yyval.is_val->next_Value=yyattribute(3 - 3).is_val;
	  
#line 926 "myparser.c"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 377 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(2 - 3).yych;
		yyval.is_val->next_Value=NULL;
	  
#line 943 "myparser.c"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 383 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(2 - 3).yych;
		yyval.is_val->next_Value=NULL;
	  
#line 960 "myparser.c"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 389 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(1 - 1).yych;
		yyval.is_val->next_Value=NULL;
	  
#line 977 "myparser.c"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 395 ".\\myparser.y"

		yyval.is_val=(struct insertValue *)malloc(sizeof(struct insertValue));
		yyval.is_val->value=yyattribute(1 - 1).yych;
		yyval.is_val->next_Value=NULL;
	  
#line 994 "myparser.c"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 401 ".\\myparser.y"

		deleteAll(yyattribute(3 - 4).yych);
	  
#line 1009 "myparser.c"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[7];
			yyinitdebug(yya, 7);
#endif
			{
#line 405 ".\\myparser.y"

		deleteCdt(yyattribute(3 - 6).yych,yyattribute(5 - 6).cons_var);
	  
#line 1024 "myparser.c"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 409 ".\\myparser.y"

		dropTable(yyattribute(3 - 4).yych);
	
#line 1039 "myparser.c"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[5];
			yyinitdebug(yya, 5);
#endif
			{
#line 413 ".\\myparser.y"

		strcpy(database,yyattribute(3 - 4).yych);
		dropDB();
	
#line 1055 "myparser.c"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 418 ".\\myparser.y"

		updateAll(yyattribute(2 - 5).yych,yyattribute(4 - 5).s_var);
	  
#line 1070 "myparser.c"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 422 ".\\myparser.y"

		updateCdt(yyattribute(2 - 7).yych,yyattribute(4 - 7).s_var,yyattribute(6 - 7).cons_var);
	  
#line 1085 "myparser.c"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 426 ".\\myparser.y"

		yyval.s_var=yyattribute(1 - 1).s_var;
	  
#line 1100 "myparser.c"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 430 ".\\myparser.y"

		yyval.s_var=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		yyval.s_var->field=yyattribute(1 - 3).s_var->field;
		yyval.s_var->value=yyattribute(1 - 3).s_var->value;
		yyval.s_var->next_sf=yyattribute(3 - 3).s_var;
	  
#line 1118 "myparser.c"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 437 ".\\myparser.y"

		yyval.s_var=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		yyval.s_var->field=yyattribute(1 - 3).yych;
		yyval.s_var->value=yyattribute(3 - 3).yych;
		yyval.s_var->next_sf=NULL;
	  
#line 1136 "myparser.c"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[6];
			yyinitdebug(yya, 6);
#endif
			{
#line 444 ".\\myparser.y"

		yyval.s_var=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		yyval.s_var->field=yyattribute(1 - 5).yych;
		yyval.s_var->value=yyattribute(4 - 5).yych;
		yyval.s_var->next_sf=NULL;
	  
#line 1154 "myparser.c"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 451 ".\\myparser.y"

             	printf("Thank you！Glad to see you again!\n");
           	exit(0);
	
#line 1170 "myparser.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\'!\'", 33 },
	{ "\'(\'", 40 },
	{ "\')\'", 41 },
	{ "\'*\'", 42 },
	{ "\',\'", 44 },
	{ "\'.\'", 46 },
	{ "\';\'", 59 },
	{ "\'<\'", 60 },
	{ "\'=\'", 61 },
	{ "\'>\'", 62 },
	{ "error", 256 },
	{ "CREATE", 257 },
	{ "SHOW", 258 },
	{ "USE", 259 },
	{ "DATABASES", 260 },
	{ "DATABASE", 261 },
	{ "TABLE", 262 },
	{ "TABLES", 263 },
	{ "CHAR", 264 },
	{ "INT", 265 },
	{ "SELECT", 266 },
	{ "FROM", 267 },
	{ "WHERE", 268 },
	{ "OR", 269 },
	{ "AND", 270 },
	{ "QUOTE", 271 },
	{ "INSERT", 272 },
	{ "INTO", 273 },
	{ "VALUES", 274 },
	{ "UPDATE", 275 },
	{ "SET", 276 },
	{ "DELETE", 277 },
	{ "DROP", 278 },
	{ "EXIT", 279 },
	{ "ID", 280 },
	{ "NUMBER", 281 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: start",
	"start: statements",
	"statements: statements statement",
	"statements: statement",
	"statement: createsql",
	"statement: selectsql",
	"statement: usesql",
	"statement: showsql",
	"statement: insertsql",
	"statement: deletesql",
	"statement: dropsql",
	"statement: updatesql",
	"statement: exitsql",
	"createsql: CREATE TABLE table \'(\' fieldsdefinition \')\' \';\'",
	"createsql: CREATE DATABASE ID \';\'",
	"table: ID",
	"fieldsdefinition: field_type",
	"fieldsdefinition: field_type \',\' fieldsdefinition",
	"field_type: field type",
	"field: ID",
	"type: CHAR \'(\' NUMBER \')\'",
	"type: INT",
	"usesql: USE ID \';\'",
	"showsql: SHOW DATABASES \';\'",
	"showsql: SHOW TABLES \';\'",
	"selectsql: SELECT fields_star FROM tables \';\'",
	"selectsql: SELECT fields_star FROM tables WHERE conditions \';\'",
	"fields_star: table_fields",
	"fields_star: \'*\'",
	"table_fields: table_field",
	"table_fields: table_field \',\' table_fields",
	"table_field: field",
	"table_field: table \'.\' field",
	"tables: table",
	"tables: table \',\' tables",
	"conditions: condition",
	"conditions: \'(\' conditions \')\'",
	"conditions: conditions AND conditions",
	"conditions: conditions OR conditions",
	"condition: comp_left comp_op comp_right",
	"comp_left: table_field",
	"comp_right: table_field",
	"comp_right: NUMBER",
	"comp_right: QUOTE ID QUOTE",
	"comp_right: QUOTE NUMBER QUOTE",
	"comp_op: \'<\'",
	"comp_op: \'>\'",
	"comp_op: \'=\'",
	"comp_op: \'!\' \'=\'",
	"insertsql: INSERT INTO table VALUES \'(\' values \')\' \';\'",
	"insertsql: INSERT INTO table \'(\' values \')\' VALUES \'(\' values \')\' \';\'",
	"values: value",
	"values: value \',\' values",
	"value: QUOTE ID QUOTE",
	"value: QUOTE NUMBER QUOTE",
	"value: NUMBER",
	"value: ID",
	"deletesql: DELETE FROM table \';\'",
	"deletesql: DELETE FROM table WHERE conditions \';\'",
	"dropsql: DROP TABLE ID \';\'",
	"dropsql: DROP DATABASE ID \';\'",
	"updatesql: UPDATE table SET sets \';\'",
	"updatesql: UPDATE table SET sets WHERE conditions \';\'",
	"sets: set",
	"sets: set \',\' sets",
	"set: ID \'=\' NUMBER",
	"set: ID \'=\' QUOTE ID QUOTE",
	"exitsql: EXIT \';\'"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 1, -1 },
	{ 2, 2, -1 },
	{ 2, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 3, 1, -1 },
	{ 4, 7, 0 },
	{ 4, 4, 1 },
	{ 5, 1, 2 },
	{ 6, 1, 3 },
	{ 6, 3, 4 },
	{ 7, 2, 5 },
	{ 8, 1, 6 },
	{ 9, 4, 7 },
	{ 9, 1, 8 },
	{ 10, 3, 9 },
	{ 11, 3, 10 },
	{ 11, 3, 11 },
	{ 12, 5, 12 },
	{ 12, 7, 13 },
	{ 13, 1, 14 },
	{ 13, 1, 15 },
	{ 14, 1, 16 },
	{ 14, 3, 17 },
	{ 15, 1, 18 },
	{ 15, 3, 19 },
	{ 16, 1, 20 },
	{ 16, 3, 21 },
	{ 17, 1, 22 },
	{ 17, 3, 23 },
	{ 17, 3, 24 },
	{ 17, 3, 25 },
	{ 18, 3, 26 },
	{ 19, 1, 27 },
	{ 20, 1, 28 },
	{ 20, 1, 29 },
	{ 20, 3, 30 },
	{ 20, 3, 31 },
	{ 21, 1, 32 },
	{ 21, 1, 33 },
	{ 21, 1, 34 },
	{ 21, 2, 35 },
	{ 22, 8, 36 },
	{ 22, 11, 37 },
	{ 23, 1, 38 },
	{ 23, 3, 39 },
	{ 24, 3, 40 },
	{ 24, 3, 41 },
	{ 24, 1, 42 },
	{ 24, 1, 43 },
	{ 25, 4, 44 },
	{ 25, 6, 45 },
	{ 26, 4, 46 },
	{ 26, 4, 47 },
	{ 27, 5, 48 },
	{ 27, 7, 49 },
	{ 28, 1, 50 },
	{ 28, 3, 51 },
	{ 29, 3, 52 },
	{ 29, 5, 53 },
	{ 30, 2, 54 }
};

int YYNEAR YYDCDECL yytokenaction_size = 235;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 50, YYAT_SHIFT, 62 },
	{ 108, YYAT_SHIFT, 128 },
	{ 66, YYAT_SHIFT, 85 },
	{ 60, YYAT_SHIFT, 75 },
	{ 52, YYAT_SHIFT, 67 },
	{ 13, YYAT_SHIFT, 1 },
	{ 13, YYAT_SHIFT, 2 },
	{ 13, YYAT_SHIFT, 3 },
	{ 146, YYAT_SHIFT, 147 },
	{ 137, YYAT_SHIFT, 77 },
	{ 107, YYAT_ERROR, 0 },
	{ 91, YYAT_SHIFT, 112 },
	{ 116, YYAT_SHIFT, 132 },
	{ 143, YYAT_SHIFT, 146 },
	{ 13, YYAT_SHIFT, 4 },
	{ 0, YYAT_SHIFT, 1 },
	{ 0, YYAT_SHIFT, 2 },
	{ 0, YYAT_SHIFT, 3 },
	{ 137, YYAT_SHIFT, 78 },
	{ 137, YYAT_SHIFT, 79 },
	{ 13, YYAT_SHIFT, 5 },
	{ 83, YYAT_SHIFT, 104 },
	{ 116, YYAT_SHIFT, 133 },
	{ 13, YYAT_SHIFT, 6 },
	{ 0, YYAT_SHIFT, 4 },
	{ 13, YYAT_SHIFT, 7 },
	{ 13, YYAT_SHIFT, 8 },
	{ 13, YYAT_SHIFT, 9 },
	{ 107, YYAT_SHIFT, 127 },
	{ 2, YYAT_SHIFT, 24 },
	{ 0, YYAT_SHIFT, 5 },
	{ 83, YYAT_SHIFT, 105 },
	{ 2, YYAT_SHIFT, 25 },
	{ 0, YYAT_SHIFT, 6 },
	{ 141, YYAT_SHIFT, 145 },
	{ 0, YYAT_SHIFT, 7 },
	{ 0, YYAT_SHIFT, 8 },
	{ 0, YYAT_SHIFT, 9 },
	{ 91, YYAT_SHIFT, 113 },
	{ 91, YYAT_SHIFT, 114 },
	{ 91, YYAT_SHIFT, 115 },
	{ 132, YYAT_SHIFT, 140 },
	{ 132, YYAT_SHIFT, 141 },
	{ 77, YYAT_SHIFT, 99 },
	{ 77, YYAT_SHIFT, 100 },
	{ 71, YYAT_SHIFT, 92 },
	{ 71, YYAT_SHIFT, 93 },
	{ 8, YYAT_SHIFT, 38 },
	{ 8, YYAT_SHIFT, 39 },
	{ 1, YYAT_SHIFT, 22 },
	{ 1, YYAT_SHIFT, 23 },
	{ 140, YYAT_SHIFT, 144 },
	{ 136, YYAT_SHIFT, 142 },
	{ 129, YYAT_SHIFT, 111 },
	{ 126, YYAT_SHIFT, 139 },
	{ 125, YYAT_SHIFT, 138 },
	{ 123, YYAT_SHIFT, 137 },
	{ 117, YYAT_SHIFT, 136 },
	{ 112, YYAT_SHIFT, 131 },
	{ 111, YYAT_SHIFT, 87 },
	{ 104, YYAT_SHIFT, 126 },
	{ 103, YYAT_SHIFT, 125 },
	{ 101, YYAT_SHIFT, 123 },
	{ 100, YYAT_SHIFT, 122 },
	{ 99, YYAT_SHIFT, 121 },
	{ 98, YYAT_SHIFT, 120 },
	{ 96, YYAT_SHIFT, 57 },
	{ 95, YYAT_SHIFT, 118 },
	{ 92, YYAT_SHIFT, 117 },
	{ 90, YYAT_SHIFT, 109 },
	{ 84, YYAT_SHIFT, 64 },
	{ 81, YYAT_SHIFT, 102 },
	{ 80, YYAT_SHIFT, 101 },
	{ 74, YYAT_SHIFT, 35 },
	{ 73, YYAT_SHIFT, 96 },
	{ 72, YYAT_SHIFT, 95 },
	{ 65, YYAT_SHIFT, 84 },
	{ 64, YYAT_SHIFT, 83 },
	{ 63, YYAT_SHIFT, 82 },
	{ 59, YYAT_SHIFT, 74 },
	{ 54, YYAT_SHIFT, 70 },
	{ 53, YYAT_SHIFT, 69 },
	{ 49, YYAT_SHIFT, 28 },
	{ 43, YYAT_SHIFT, 56 },
	{ 42, YYAT_SHIFT, 55 },
	{ 39, YYAT_SHIFT, 54 },
	{ 38, YYAT_SHIFT, 53 },
	{ 36, YYAT_SHIFT, 51 },
	{ 33, YYAT_SHIFT, 49 },
	{ 31, YYAT_SHIFT, 48 },
	{ 29, YYAT_SHIFT, 47 },
	{ 28, YYAT_REDUCE, 15 },
	{ 26, YYAT_SHIFT, 46 },
	{ 25, YYAT_SHIFT, 45 },
	{ 24, YYAT_SHIFT, 44 },
	{ 22, YYAT_SHIFT, 42 },
	{ 12, YYAT_ACCEPT, 0 },
	{ 9, YYAT_SHIFT, 40 },
	{ 7, YYAT_SHIFT, 37 },
	{ 5, YYAT_SHIFT, 34 },
	{ 4, YYAT_SHIFT, 27 },
	{ 3, YYAT_SHIFT, 26 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 66, YYAT_SHIFT, 86 },
	{ 60, YYAT_SHIFT, 76 },
	{ 52, YYAT_SHIFT, 68 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 108, YYAT_SHIFT, 110 },
	{ 108, YYAT_SHIFT, 111 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 50, YYAT_SHIFT, 63 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ -242, 1, YYAT_ERROR, 0 },
	{ -212, 1, YYAT_ERROR, 0 },
	{ -231, 1, YYAT_ERROR, 0 },
	{ -179, 1, YYAT_ERROR, 0 },
	{ 58, 1, YYAT_DEFAULT, 49 },
	{ -174, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 74 },
	{ -169, 1, YYAT_ERROR, 0 },
	{ -214, 1, YYAT_ERROR, 0 },
	{ 38, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 4 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 96, 1, YYAT_ERROR, 0 },
	{ -252, 1, YYAT_REDUCE, 1 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ 0, 0, YYAT_REDUCE, 10 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ -185, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 74 },
	{ 35, 1, YYAT_ERROR, 0 },
	{ 34, 1, YYAT_ERROR, 0 },
	{ 33, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 28 },
	{ 45, 1, YYAT_REDUCE, 19 },
	{ 44, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ -178, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ 44, 1, YYAT_REDUCE, 29 },
	{ 0, 0, YYAT_DEFAULT, 74 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ -189, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 74 },
	{ -194, 1, YYAT_ERROR, 0 },
	{ -195, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 67 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ 25, 1, YYAT_ERROR, 0 },
	{ 43, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ 0, 0, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_REDUCE, 22 },
	{ 0, 0, YYAT_DEFAULT, 96 },
	{ 0, 0, YYAT_DEFAULT, 74 },
	{ -198, 1, YYAT_ERROR, 0 },
	{ -40, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 84 },
	{ -55, 1, YYAT_ERROR, 0 },
	{ 22, 1, YYAT_ERROR, 0 },
	{ 21, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_DEFAULT, 96 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ 35, 1, YYAT_REDUCE, 33 },
	{ -56, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ 0, 0, YYAT_DEFAULT, 137 },
	{ 38, 1, YYAT_ERROR, 0 },
	{ 16, 1, YYAT_ERROR, 0 },
	{ 32, 1, YYAT_REDUCE, 63 },
	{ -57, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 57 },
	{ 0, 0, YYAT_DEFAULT, 111 },
	{ 0, 0, YYAT_REDUCE, 60 },
	{ 0, 0, YYAT_REDUCE, 59 },
	{ -219, 1, YYAT_ERROR, 0 },
	{ 34, 1, YYAT_ERROR, 0 },
	{ 30, 1, YYAT_REDUCE, 16 },
	{ -207, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_DEFAULT, 111 },
	{ -237, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 56 },
	{ 0, 0, YYAT_REDUCE, 55 },
	{ 31, 1, YYAT_ERROR, 0 },
	{ 27, 1, YYAT_REDUCE, 51 },
	{ 0, 0, YYAT_DEFAULT, 137 },
	{ -250, 1, YYAT_ERROR, 0 },
	{ -210, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 61 },
	{ 0, 0, YYAT_DEFAULT, 111 },
	{ 0, 0, YYAT_DEFAULT, 111 },
	{ 0, 0, YYAT_REDUCE, 40 },
	{ 0, 0, YYAT_REDUCE, 35 },
	{ 10, 1, YYAT_DEFAULT, 107 },
	{ -22, 1, YYAT_ERROR, 0 },
	{ 28, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ 8, 1, YYAT_ERROR, 0 },
	{ -214, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 34 },
	{ 6, 1, YYAT_DEFAULT, 107 },
	{ -207, 1, YYAT_ERROR, 0 },
	{ -208, 1, YYAT_ERROR, 0 },
	{ -212, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 137 },
	{ 20, 1, YYAT_ERROR, 0 },
	{ -220, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 65 },
	{ 0, 0, YYAT_REDUCE, 64 },
	{ -31, 1, YYAT_DEFAULT, 108 },
	{ -40, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 58 },
	{ 0, 0, YYAT_DEFAULT, 111 },
	{ 19, 1, YYAT_DEFAULT, 49 },
	{ -3, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 45 },
	{ 0, 0, YYAT_REDUCE, 47 },
	{ 0, 0, YYAT_REDUCE, 46 },
	{ -259, 1, YYAT_DEFAULT, 49 },
	{ -224, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ 0, 0, YYAT_REDUCE, 53 },
	{ 0, 0, YYAT_REDUCE, 54 },
	{ 16, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 52 },
	{ -4, 1, YYAT_ERROR, 0 },
	{ -217, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 62 },
	{ 0, 0, YYAT_REDUCE, 36 },
	{ -217, 1, YYAT_REDUCE, 38 },
	{ 0, 0, YYAT_REDUCE, 37 },
	{ 0, 0, YYAT_REDUCE, 48 },
	{ -239, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 42 },
	{ 0, 0, YYAT_REDUCE, 41 },
	{ 0, 0, YYAT_REDUCE, 39 },
	{ 11, 1, YYAT_ERROR, 0 },
	{ -262, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 49 },
	{ 0, 0, YYAT_REDUCE, 66 },
	{ -220, 1, YYAT_ERROR, 0 },
	{ -237, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ -28, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 43 },
	{ 0, 0, YYAT_REDUCE, 44 },
	{ -51, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 50 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 54;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 13, 41 },
	{ 13, 10 },
	{ 116, 29 },
	{ 137, 143 },
	{ 137, 81 },
	{ 116, 30 },
	{ 110, 129 },
	{ 13, 15 },
	{ 13, 16 },
	{ 13, 11 },
	{ 74, 59 },
	{ 111, 88 },
	{ 116, 134 },
	{ 111, 130 },
	{ 111, 89 },
	{ 111, 91 },
	{ 111, -1 },
	{ 116, 135 },
	{ 102, 124 },
	{ 13, 17 },
	{ 91, 116 },
	{ 74, 97 },
	{ 13, 18 },
	{ 13, 19 },
	{ 13, 20 },
	{ 49, 61 },
	{ 49, 33 },
	{ 13, 21 },
	{ 96, 119 },
	{ 96, 73 },
	{ 96, 71 },
	{ 49, -1 },
	{ 0, 12 },
	{ 0, 13 },
	{ 0, 14 },
	{ 84, 106 },
	{ 84, 65 },
	{ 4, 31 },
	{ 4, 32 },
	{ 87, 108 },
	{ 86, 107 },
	{ 82, 103 },
	{ 76, 98 },
	{ 71, 94 },
	{ 68, 90 },
	{ 62, 80 },
	{ 56, 72 },
	{ 51, 66 },
	{ 48, 60 },
	{ 47, 58 },
	{ 37, 52 },
	{ 34, 50 },
	{ 23, 43 },
	{ 6, 36 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 31, 13 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 24, 49 },
	{ 0, -1 },
	{ 48, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 47, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 46, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 45, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 41, -1 },
	{ 32, 74 },
	{ 11, 116 },
	{ 0, -1 },
	{ 19, 84 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 40, 96 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 22, 137 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 27, 111 },
	{ 0, -1 },
	{ 0, -1 },
	{ 34, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 5, -1 },
	{ 0, -1 },
	{ 25, 111 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 18, 137 },
	{ 0, -1 },
	{ 7, -1 },
	{ 0, -1 },
	{ 23, 111 },
	{ 22, 111 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -1, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 22, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -5, 137 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -11, 111 },
	{ -4, 116 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -3, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -20, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 457 ".\\myparser.y"


//-----------------------------------------------------------------------
/* 创建数据库 */
void createDB()
{
	FILE *fp;
	_chdir(rootDir);
	if(_access(database,0)!=-1)
	{
		printf("The database already exist!\n");
	}
	else
	{
		if(_mkdir(database)==-1)//创建以数据库为名的文件夹
		{
			printf("Create database failed!\n");
		}
		else
		{
			fp=fopen("database.dat","a+");//若没有此文件则创建，有则在文件末添加数据库名字
			if(fp==NULL)
			{
				printf("open database.dat error!\n");
			}
			else
			{
				fprintf(fp,"%s\n",database);
				printf("Create database %s succeed!\n",database);
				fflush(fp);
				fclose(fp);
			}
		}
	}
	strcpy(database,"\0");
	_chdir(rootDir);
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* 获取所有数据库名字 */
void getDB()
{
	FILE *fp;
	char name[100];
	_chdir(rootDir);
	fp=fopen("database.dat","r");//打开保存数据库名字的文件
	if(fp==NULL)
	{
		printf("open database.dat failed!\n");
	}
	else
	{
		while(fscanf(fp,"%s",name)!=EOF)
		{
			printf("%s\n",name);//打印数据库名字
		}	
	}
	fclose(fp);
	_chdir(rootDir);
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* 选择数据库 */
void useDB()
{
	char name[100];//保存需use的数据库绝对路径
	_chdir(rootDir);
	strcpy(name,rootDir);
	strcat(name,"\\");
	strcat(name,database);
	if(_chdir(name)==0)//转到需use的数据库的所在路径
	{
		if(_access(name,0)!=-1)//若所插入的表格存在
		{
			printf("Current database:%s\n",database);
			_chdir(rootDir);
		}
		else
		{
			printf("The database doesn't exist!\n");
		}
	}
	else
	{
		printf("Use %s failed!\n",database);
	}
	strcpy(database,name);//更新database
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* 创建表 */
void createTable(struct Createstruct *cs_root)
{
	struct Createfieldsdef *cfdef=cs_root->fdef;
	int d=4;//INT型的长度
	int i=0;//记录所创建表格的属性个数
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		FILE *fp;
		FILE *fp2;
		char name[100];//保存所创建表的名字
		char table[100];//保存所创建文件的名字
		strcpy(name,cs_root->table);
		fp=fopen("tables.dat","a+");//更新总表
		if(fp==NULL)
		{
			printf("Open tables.dat failed!\n");
		}
		else
		{
			strcpy(table,name);
			strcat(table,".txt");
			if(_access(table,0)!=-1)//若所创建的表已存在
			{
				printf("The table already exist!\n");
			}
			else
			{
				while(cfdef!=NULL)//将表的信息存入总表
				{
					fprintf(fp,"%s ",name);
					if(cfdef->type==CHAR)
					{
						fprintf(fp,"%s ",cfdef->field);
						fprintf(fp,"CHAR %d\n",(int)cfdef->length);
					}
					else if(cfdef->type==INT)
					{
						fprintf(fp,"%s INT %d\n",cfdef->field,d);
					}
					i++;
					cfdef=cfdef->next_fdef;
				}
				fclose(fp);
				fp2=fopen(table,"w");
				if(fp2==NULL)
				{
					printf("Open %s failed!\n",table);
				}
				else
				{
					cfdef=cs_root->fdef;
					fprintf(fp2,"%d\n",i);//在文件第一行写入表格属性个数
					while(cfdef!=NULL)//将表的字段存入文件
					{
						if(cfdef->next_fdef==NULL)
						{
							fprintf(fp2,"%s\n",cfdef->field);
						}
						else
						{
							fprintf(fp2,"%s\t",cfdef->field);
						}
						cfdef=cfdef->next_fdef;
					}
					fclose(fp2);
				}
				printf("Create succeed!\n");
			}
		}
	}
	cfdef=cs_root->fdef;
    while(cfdef!= NULL)//释放指针
    {
        struct Createfieldsdef *cfdeftmp=cfdef;
        cfdef=cfdef->next_fdef;
        free(cfdeftmp);
    }
    free(cs_root);
    _chdir(rootDir);
    printf("MySQL>");
}

//-----------------------------------------------------------------------
/* 显示表信息 */
void getTable()
{
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
	
		FILE *fp;
		char s1[100],s2[100],s3[100];//表名，字段，字段类型
		int d;//字段长度
		fp=fopen("tables.dat","r");
		if(fp==NULL)
		{
			printf("Open tables.dat failed!\n");
		}
		else
		{
			fscanf(fp,"%d",&d);//过滤第一行的表格属性个数
			while(fscanf(fp,"%s %s %s %d",s1,s2,s3,&d)!=EOF)
			{
				if(strcmp(s3,"CHAR")==0)
				{
					printf("%s %s %s %d\n",s1,s2,s3,d);
				}
				else if(strcmp(s3,"INT")==0)
				{
					printf("%s %s %s\n",s1,s2,s3);
				}
			}
			fclose(fp);
			_chdir(rootDir);
			printf("MySQL>");
		}
	}
}

//-----------------------------------------------------------------------
/* 按顺序插入数据 */
void insertOrder(char *tableName,struct insertValue *values)
{
	char name[100];
	_chdir(rootDir);
	strcpy(name,tableName);
	strcat(name,".txt");
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		if(_access(name,0)!=-1)//若所插入的表格存在
		{
			FILE *fp;
			struct insertValue *valuestmp=values;
			fp=fopen(name,"a+");//打开文件并在末尾添加数据
			if(fp==NULL)
			{
				printf("Open %s failed!\n",name);
			}
			else
			{
				while(valuestmp!=NULL)//写入数据
				{
					if(valuestmp->next_Value==NULL)
					{
						fprintf(fp,"%s\n",valuestmp->value);
					}
					else
					{
						fprintf(fp,"%s\t",valuestmp->value);
					}
					valuestmp=valuestmp->next_Value;
				}
				fclose(fp);
				printf("Insert succeed!\n");
			}
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	while(values!=NULL)//释放指针
	{
		struct insertValue *valuestmp=values;
		values=values->next_Value;
		free(valuestmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* 自定义顺序插入数据 */
void insertNoOrder(char *tableName,struct insertValue *valuesName,struct insertValue *values)
{
	char name[100];//保存写入数据的文件名
	char select_name[100][100];//所选字段名
	char all_name[100][100];//所有字段名
	char select_value[100][100];//字段值
	int flag=0;//所选字段的个数
	int flag2=0;//字段值得个数
	int N;//所有字段的个数
	int i,j;
	_chdir(rootDir);
	strcpy(name,tableName);
	strcat(name,".txt");
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		if(_access(name,0)!=-1)//若所插入的表格存在
		{
			FILE *fp;
			FILE *fp2;
			struct insertValue *val_Name=valuesName;
			struct insertValue *val_tmp=values;
			while(val_Name!=NULL)//将所选字段保存在Name数组里
			{
				strcpy(select_name[flag],val_Name->value);
				flag++;
				val_Name=val_Name->next_Value;
			}
			while(val_tmp!=NULL)//将插入值保存在Value数组里
			{
				strcpy(select_value[flag2],val_tmp->value);
				flag2++;
				val_tmp=val_tmp->next_Value;
			}
			if(flag!=flag2)//若个数不等无法插入
			{
				printf("Numbers are not equal!\n");
			}
			else
			{
				fp=fopen(name,"r");//打开文件只读
				if(fp==NULL)
				{
					printf("Open %s failed!\n",name);
				}
				else
				{
					fscanf(fp,"%d\n",&N);//读入第一行的表格属性个数
					for(i=0;i<N;i++)//将所有字段保存在all_name数组里
					{
						fscanf(fp,"%s",all_name[i]);
						if(i>=flag)//如果N大于所选字段个数，则在相应位置存NULL
						{
							strcpy(select_value[i],"NULL");
							strcpy(select_name[i],"NULL");
						}
					}
					strcpy(select_value[i],"NULL");
					strcpy(select_name[i],"NULL");
					for(i=0;i<N;i++)//将Value数组里的值的位置对应all_name
					{
						for(j=0;j<flag;j++)
						{
							if(strcmp(all_name[i],select_name[j])==0)
							{
								strcpy(select_name[j],select_name[i]);
								strcpy(select_name[i],all_name[i]);
								strcpy(select_value[N],select_value[i]);
								strcpy(select_value[i],select_value[j]);
								strcpy(select_value[j],select_value[N]);
								break;
							}
						}
					}
					fclose(fp);
					fp2=fopen(name,"a+");
					if(fp2==NULL)
					{
						printf("Open %s failed!\n",name);
					}
					else
					{
						for(i=0;i<N;i++)//写入数据，在未选插入值的位置上填NULL
						{
							if(i==N-1)
							{
								fprintf(fp2,"%s\n",select_value[i]);
							}
							else
							{
								fprintf(fp2,"%s\t",select_value[i]);
							}
						}
						fclose(fp2);
						printf("Insert succeed!\n");
					}
				}
			}
			while(valuesName!=NULL)//释放指针
			{
				struct insertValue *val_Name=valuesName;
				valuesName=valuesName->next_Value;
				free(val_Name);
			}
			while(values!=NULL)//释放指针
			{
				struct insertValue *val_tmp=values;
				values=values->next_Value;
				free(val_tmp);
			}	
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//匹配条件式的ID,找到需更新/查询的行-------------------------------------
int CdtSearch(struct Conditions *conditionRoot, int totField, char allField[][100], char value[][100])
{
    char comp_op = conditionRoot->comp_op;//操作符
    int field = 0;
    int field2 = 0;
    int i;
    if (comp_op == 'a')//若是AND则求多个条件式的和，返回1表示属性匹配成功
    {
        return (CdtSearch(conditionRoot->left, totField, allField, value)&&CdtSearch(conditionRoot->right, totField, allField, value));
    }
    else if (comp_op == 'o')//若是OR则求多个条件式的或，返回1表示属性匹配成功
    {
        return (CdtSearch(conditionRoot->left, totField, allField, value) || CdtSearch(conditionRoot->right, totField, allField, value));
    }
    else//若条件式为单个
    {
        if(conditionRoot->right->type==0)//若是ID=ID的条件，先找到匹配左部table.field的字段下标
        {
			for(i=0;i<totField;i++)
			{
				if(strcmp(allField[i+totField],conditionRoot->left->table)==0)
				{
					if(strcmp(allField[i], conditionRoot->left->value)==0)
					{
						field2=i;
						break;
					}
				}
			}
        }
        else
        {
			for (i = 0; i < totField; ++i)//匹配更改字段和表中字段，成功则记录属性所在第几列
			{
				if (strcmp(allField[i], conditionRoot->left->value) == 0)
				{
					field = i;
					break;
				}
			}
        }
        if (comp_op == '=')//表中的值和条件式右部相等
        {
            if(conditionRoot->right->type==0)
            {
				for(i=0;i<totField;i++)//找到右部字段field等于左部字段field
				{
					if(strcmp(allField[i+totField],conditionRoot->right->table)==0)
					{
						if(strcmp(allField[field2],allField[i])==0)
						{
							if(strcmp(value[field2],value[i])==0)//连接相同属性值
							{
								return 1;
							}
						}
					}
				}
				if(i==totField)//没找到返回0
				{
					return 0;
				}
            }
            else if (strcmp(value[field], conditionRoot->right->value) == 0)
            {
                return 1;
            }
            else
            {
                return 0;
			}
        }
        else if (comp_op == '>')//表中的值大于条件式右部
        {
            if (conditionRoot->right->type == 2)
            {	
				if (atoi(value[field]) > atoi(conditionRoot->right->value))
                {
					return 1;
				}
				else
				{
					return 0;
				}
            }
            else 
            {
                return 0;
            }
        }
        else if (comp_op == '<')//表中的值小于条件式右部
        {
            if (conditionRoot->right->type == 2)
            {	
				if (atoi(value[field]) < atoi(conditionRoot->right->value))
                {
					return 1;
				}
				else
				{
					return 0;
				}
            }
            else 
            {
                return 0;
            }
        }
        else if (comp_op == '!')//表中的值不等于条件式右部
        {
            if (conditionRoot->right->type == 2)
            {	
				if (atoi(value[field]) != atoi(conditionRoot->right->value))
                {
					return 1;
				}
				else
				{
					return 0;
				}
            }
            else if(conditionRoot->right->type == 1)
            {
				if(strcmp(value[field],conditionRoot->right->value)!=0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
            }
            else 
            {
                return 0;
            }
        }
    }
}

//释放condition指针
void freeCdt(struct Conditions *conditionRoot)
{
	if (conditionRoot->left != NULL)
	{
        freeCdt(conditionRoot->left);
    }
    else if (conditionRoot->right != NULL)
    {    
		freeCdt(conditionRoot->right);
    }
    else
    {
		free(conditionRoot);
	}
}
//修改所有数据-----------------------------------------------------------
void updateAll(char *tableName,struct Setstruct *setRoot)
{
	char name[100];//保存需要更改数据的文件名
	char copy[100]="copy ";//保存复制name的文件的system操作命令
	char del[100]="del copy.txt";//数据更新完成后删除复制文件
	char update_name[100][100];//需更改的字段名
	char update_value[100][100];//更改的字段值
	char all_name[100][100];//所有字段名
	char old_value[100][100];//旧的字段值
	int flag;//判断需更改字段的标记
	int all_field=0;//所有字段个数
	int update_set=0;//需更改的个数
	int file_end=0;//判断文件是否读完，1表示已读完
	int i,j,k;
	FILE *fp;//打开复制文件
	FILE *fp2;//重写name文件
	struct Setstruct *Set_tmp=setRoot;//更改字段指针
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//若所需更改数据的表格存在
		{
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy name copy.txt"
			while(Set_tmp!=NULL)//将需要更改数据的字段以及字段值分别保存到update_name和update_value中
			{
				strcpy(update_name[update_set],Set_tmp->field);
				strcpy(update_value[update_set],Set_tmp->value);
				update_set++;
				Set_tmp=Set_tmp->next_sf;
			}
			system(copy);
			fp=fopen("copy.txt","r");//对复制文件只读
			fp2=fopen(name,"w");//对更改的表重写
			fscanf(fp,"%d",&all_field);//读出所有字段个数
			fprintf(fp2,"%d\n",all_field);//写入所有字段个数
			for(i=0;i<all_field;i++)//对name文件重写所有属性字段
			{
				fscanf(fp,"%s",all_name[i]);
				if(i==all_field-1)
				{
					fprintf(fp2,"%s\n",all_name[i]);
				}
				else
				{
					fprintf(fp2,"%s\t",all_name[i]);
				}
			}
			for(i=0;1;i++)
			{
				file_end=0;
				for(j=0;j<all_field;j++)//每次循环读取一行字段值，若碰到文件结束符，跳出循环
				{
					if(fscanf(fp,"%s",old_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//若文件读完，代表更改数据完毕，跳出循环
				{
					break;
				}
				for(j=0;j<all_field;j++)
				{
					flag=0;
					for(k=0;k<update_set;k++)//找到需更改的字段将数据更新
					{
						if(strcmp(update_name[k],all_name[j])==0)
						{
							if(j==all_field-1)
							{
								fprintf(fp2,"%s\n",update_value[k]);
							}
							else
							{
								fprintf(fp2,"%s\t",update_value[k]);
							}
							flag=1;
							break;
						}
					}
					if(flag==0)//不需要更改数据的字段将原数据写入
					{
						if(j==all_field-1)
						{
							fprintf(fp2,"%s\n",old_value[j]);
						}
						else
						{
							fprintf(fp2,"%s\t",old_value[j]);
						}
					}
				}
			}
		fclose(fp2);
		fclose(fp);
		system(del);//删除复制文件
		printf("Update succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	free(tableName);
	while(setRoot!=NULL)//释放set指针
	{
		struct Setstruct *Set_tmp=setRoot;
		setRoot=setRoot->next_sf;
		free(Set_tmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//修改选定属性的数据
void updateCdt(char *tableName,struct Setstruct *setRoot,struct Conditions *conditionRoot)
{
	char name[100];//保存需要更改数据的文件名
	char copy[100]="copy ";//保存复制name的文件的system操作命令
	char del[100]="del copy.txt";//数据更新完成后删除复制文件
	char update_name[100][100];//需更改的字段名
	char update_value[100][100];//更改的字段值
	char all_name[100][100];//所有字段名
	char old_value[100][100];//旧的字段值
	int condition_flag;//CdtSearch()条件式返回的值
	int flag;//判断需更改字段的标记
	int all_field=0;//所有字段个数
	int update_set=0;//需更改的个数
	int file_end=0;//判断文件是否读完，1表示已读完
	int i,j,k;
	FILE *fp;//打开复制文件
	FILE *fp2;//重写name文件
	struct Setstruct *Set_tmp=setRoot;//更改字段指针
	struct Conditions *Cdt_tmp=conditionRoot;//条件指针
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//若所需更改数据的表格存在
		{
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy name copy.txt"
			while(Set_tmp!=NULL)//将需要更改数据的字段以及字段值分别保存到update_name和update_value中
			{
				strcpy(update_name[update_set],Set_tmp->field);
				strcpy(update_value[update_set],Set_tmp->value);
				update_set++;
				Set_tmp=Set_tmp->next_sf;
			}
			system(copy);
			fp=fopen("copy.txt","r");//对复制文件只读
			fp2=fopen(name,"w");//对更改的表重写
			fscanf(fp,"%d",&all_field);//读出所有字段个数
			fprintf(fp2,"%d\n",all_field);//写入所有字段个数
			for(i=0;i<all_field;i++)//对name文件重写所有属性字段
			{
				fscanf(fp,"%s",all_name[i]);
				if(i==all_field-1)
				{
					fprintf(fp2,"%s\n",all_name[i]);
				}
				else
				{
					fprintf(fp2,"%s\t",all_name[i]);
				}
			}
			for(i=0;1;i++)
			{
				condition_flag=0;
				file_end=0;
				for(j=0;j<all_field;j++)//每次循环读取一行字段值，若碰到文件结束符，跳出循环
				{
					if(fscanf(fp,"%s",old_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//若文件读完，代表更改数据完毕，跳出循环
				{
					break;
				}
				condition_flag=CdtSearch(conditionRoot,all_field,all_name,old_value);
				if(condition_flag==0)//未匹配成功，不是需要更改的行，将旧值重写入
				{
					for(j=0;j<all_field;j++)
					{
						if(j==all_field-1)
						{
							fprintf(fp2,"%s\n",old_value[j]);
						}
						else
						{
							fprintf(fp2,"%s\t",old_value[j]);
						}
					}
				}
				else//匹配到需更改的行
				{
					for(j=0;j<all_field;j++)
					{
						flag=0;
						for(k=0;k<update_set;k++)//找到需更改的字段将数据更新
						{
							if(strcmp(update_name[k],all_name[j])==0)
							{
								if(j==all_field-1)
								{
									fprintf(fp2,"%s\n",update_value[k]);
								}
								else
								{
									fprintf(fp2,"%s\t",update_value[k]);
								}
								flag=1;
								break;
							}
						}
						if(flag==0)//不需要更改数据的字段将原数据写入
						{
							if(j==all_field-1)
							{
								fprintf(fp2,"%s\n",old_value[j]);
							}
							else
							{
								fprintf(fp2,"%s\t",old_value[j]);
							}
						}
					}
				}
			}
		fclose(fp2);
		fclose(fp);
		system(del);//删除复制文件
		printf("Update succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	free(tableName);
	freeCdt(conditionRoot);//释放condition指针
	while(setRoot!=NULL)//释放SET指针
	{
		struct Setstruct *Set_tmp=setRoot;
		setRoot=setRoot->next_sf;
		free(Set_tmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//无条件查询-------------------------------------------------------------
void selectNoCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot)
{
	char tableName[100][100];//保存表文件名字
	char fileName[100][100];//保存表名字
	int all_table=0;//所有表个数
	int all_field=0;//所有属性字段个数
	int flag=1;//判断表是否存在的标志
	int i,j;
	struct Selectedfields *field_tmp=fieldRoot;
	struct Selectedtables *table_tmp=tableRoot;
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		while(table_tmp!=NULL)//将所有需要查询的表名字保存在tableName
		{
			strcpy(fileName[all_table],table_tmp->table);
			strcpy(tableName[all_table],table_tmp->table);
			strcat(tableName[all_table],".txt");
			all_table++;
			table_tmp=table_tmp->next_st;
		}
		if(field_tmp==NULL)//'*'查询
		{
			for(i=0;i<all_table;i++)
			{
				if(_access(tableName[i],0)==-1)//表格不存在
				{
					printf("The table %s doesn't exist!\n",fileName[i]);
					flag=0;
					break;
				}
			}
			if(flag && (all_table==1))
			{
				FILE *fp;
				char field_value[100][100];//字段与属性值
				int i=0;
				int count_value=0;//元组个数(包括属性行)
				fp=fopen(tableName[0],"r");
				fscanf(fp,"%d",&all_field);//读取属性列个数
				while(fscanf(fp,"%s",field_value[i])!=EOF)
				{
					if(i==all_field-1)//输出一行的最后一个，计数器i重新为0，进行下一行的打印
					{
						printf("%-20s\n",field_value[i]);
						count_value++;
						i=0;
					}
					else
					{
						printf("%-20s",field_value[i]);
						i++;
					}
				}
				fclose(fp);
				printf("%d Records Selected!\n",count_value-1);
			}
			else if(flag && (all_table>1))
			{
				FILE *file_table[100];//表
				int all_value=0;//所有元组个数
				int count_field[100];//每张表字段个数
				int count_value[100];//每张表元组个数(包括属性行)
				char field_values[5][100][100];//保存每张表内字段以及字段值
				for(i=0;i<all_table;i++)//每张表只读
				{
					file_table[i]=fopen(tableName[i],"r");
				}
				for(i=0;i<all_table;i++)//读取每张表的属性列个数
				{
					fscanf(file_table[i],"%d",&count_field[i]);
				}
				for(i=0;i<all_table;i++)//分别打印查询的表
				{
					j=0;
					count_value[i]=0;
					printf("Select table %s:\n",tableName[i]);
					while(fscanf(file_table[i],"%s",field_values[i][j])!=EOF)
					{
						if(j==count_field[i]-1)
						{
							printf("%-20s\n",field_values[i][j]);
							count_value[i]++;
							j=0;
						}
						else
						{
							printf("%-20s",field_values[i][j]);
							j++;
						}
					}
				}
				for(i=0;i<all_table;i++)
				{
					all_value+=count_value[i]-1;
					fclose(file_table[i]);
				}
				printf("%d Records Selected!\n",all_value);//打印查询到的所有元组个数
			}
		}
		else//指定字段查询
		{
			if(all_table!=1)//无条件的指定字段查询只能是单表查询
			{
				printf("Select only one table!\n");
			}
			else
			{
				if(_access(tableName[0],0)==-1)//表格不存在
				{
					printf("The table %s doesn't exist!\n",tableName[0]);
				}
				else
				{
					FILE *fp;
					char select_field[100][100];//查询的字段名
					char all_name[100][100];//所有字段名
					char all_values[100][100];//所有的属性值
					int count_sel=0;//需查询的字段个数
					int count_value=0;//查询元组个数
					fp=fopen(tableName[0],"r");
					fscanf(fp,"%d",&all_field);//读取字段个数
					for(i=0;i<all_field;i++)//读取所有字段
					{
						fscanf(fp,"%s",all_name[i]);
					}
					while(field_tmp!=NULL)//读取需要查询的字段
					{
						strcpy(select_field[count_sel],field_tmp->field);
						count_sel++;
						field_tmp=field_tmp->next_sf;
					}
					for(i=0;i<count_sel;i++)//打印需要查询的字段
					{
						if(i==count_sel-1)
						{
							printf("%-20s\n",select_field[i]);
						}
						else
						{
							printf("%-20s",select_field[i]);
						}
					}
					i=0;
					while(fscanf(fp,"%s",all_values[i])!=EOF)//打印查询的属性值
					{
						for(j=0;j<count_sel;j++)
						{
							if(strcmp(all_name[(i%all_field)],select_field[j])==0)//匹配查询字段
							{
								if(j==count_sel-1)
								{
									printf("%-20s\n",all_values[i]);
									count_value++;
								}
								else
								{
									printf("%-20s",all_values[i]);	
								}
							}	
						}
						i++;	
					}
					fclose(fp);
					printf("%d Records Selected!\n",count_value);
				}
			}
		}
	}
	field_tmp = fieldRoot;
    table_tmp = tableRoot;
    while(fieldRoot != NULL)
    {
        field_tmp = fieldRoot;
        fieldRoot = fieldRoot->next_sf;
        free(field_tmp);
    }
    while(tableRoot != NULL)
    {
        table_tmp = tableRoot;
        tableRoot = tableRoot->next_st;
        free(table_tmp);
    }
    _chdir(rootDir);
    printf("MySQL>");
}

//笛卡尔乘积递归---------------------------------------------------------
void handle(int read_line[],int count_value[],int all_table,int index)
{  
	read_line[index]++;//行号加1
    if (read_line[index] > count_value[index])//当index指代的表读完
    {  
		read_line[index] = 1;//重新指回第一行
		index--;//返回前一个表
        if (index >= 0)//当还有表没读完
        {  
			handle(read_line,count_value,all_table,index);  
        }  
        index = all_table - 1;//重新指代最后一个表
    }  
} 
 
//有条件查询-------------------------------------------------------------
void selectCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot,struct Conditions *conditionRoot)
{
	int all_table=0;//所有表个数
	int all_field=0;//所有属性字段个数
	int i,j,k;
	int flag=1;//判断表格存在的标志
	int condition_flag;//CdtSearch()条件式返回的值
	int file_end=0;//判断文件是否读完，1表示已读完
	char tableName[100][100];//保存表名字
	char fileName[100][100];//表文件的名字
	char select_name[100][100];//查询字段
	int count_sel=0;//查询字段个数
	struct Selectedfields *field_tmp=fieldRoot;
	struct Selectedtables *table_tmp=tableRoot;
	struct Conditions *Cdt_tmp=conditionRoot;
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		while(table_tmp!=NULL)//将所有需要查询的表名字保存在tableName
		{
			strcpy(tableName[all_table],table_tmp->table);
			strcpy(fileName[all_table],table_tmp->table);
			strcat(fileName[all_table],".txt");
			all_table++;
			table_tmp=table_tmp->next_st;
		}
		for(i=0;i<all_table;i++)
		{
			if(_access(fileName[i],0)==-1)//表格不存在
			{
				printf("The table %s doesn't exist!\n",fileName[i]);
				flag=0;
				break;
			}
		}
		if(flag && (all_table==1))
		{
			FILE *fp;
			char all_name[100][100];//所有字段
			char all_values[100][100];//所有属性值
			int count_value=0;//查询元组个数
			fp=fopen(fileName[0],"r");
			fscanf(fp,"%d",&all_field);//读取属性列个数
			for(i=0;i<all_field;i++)
			{
				fscanf(fp,"%s",all_name[i]);
			}
			while(field_tmp!=NULL)
			{
				strcpy(select_name[count_sel],field_tmp->field);
				count_sel++;
				field_tmp=field_tmp->next_sf;
			}
			for(i=0;i<count_sel;i++)
			{
				if(i==count_sel-1)
				{
					printf("%-20s\n",select_name[i]);
				}
				else
				{
					printf("%-20s",select_name[i]);
				}
			}
			for(i=0;1;i++)
			{
				condition_flag=0;
				file_end=0;
				for(j=0;j<all_field;j++)//每次循环读取一行字段值，若碰到文件结束符，跳出循环
				{
					if(fscanf(fp,"%s",all_values[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//若文件读完，代表更改数据完毕，跳出循环
				{
					break;
				}
				condition_flag=CdtSearch(Cdt_tmp,all_field,all_name,all_values);
				if(condition_flag==1)//匹配到查询的行
				{
					for(j=0;j<all_field;j++)
					{
						for(k=0;k<count_sel;k++)//找到查询的字段将数据打印
						{
							if(strcmp(select_name[k],all_name[j])==0)
							{
								if(k==count_sel-1)
								{
									printf("%-20s\n",all_values[j]);
									count_value++;
								}
								else
								{
									printf("%-20s",all_values[j]);
								}
								break;
							}
						}
					}
				}
			}
			fclose(fp);
			printf("%d Records Selected!\n",count_value);
		}
		else if(flag && (all_table>1))
		{
			FILE *file_table[100];//表
			int all_value=1;//所有元组笛卡尔乘积个数
			int count_field[100];//每个表字段个数
			int count_value[100];//每个表元组个数
			int index;//指向表的下标
			int read_line[100]={1,1,1,1,1};//所读的行号
			char field_value[5][100][100];//保存所有字段以及属性值
			char Cdt_field[100][100];//当前查询行的字段及表名
			char Cdt_value[100][100];//当前查询行的属性值
			char select_table[100][100];//查询字段所在的表
			char print_name[100][100];//打印的字段
			int is_print[100];//判断是否可输出
			int count_print=0;//输出元组的个数
			int l,m;
			for(i=0;i<all_table;i++)//每张表只读
			{
				file_table[i]=fopen(fileName[i],"r");
			}
			while(field_tmp!=NULL)//要查询的字段，记录字段个数
			{
				strcpy(select_name[count_sel],field_tmp->field);
				strcpy(select_table[count_sel],field_tmp->table);
				count_sel++;
				field_tmp=field_tmp->next_sf;
			}
			for(i=0;i<all_table;i++)
			{
				fscanf(file_table[i],"%d",&count_field[i]);//读取每张表的字段个数
				j=0;
				k=all_field;
				all_field+=count_field[i];//所有字段个数
				count_value[i]=0;
				while(fscanf(file_table[i],"%s",field_value[i][j])!=EOF)
				{
					if(j<count_field[i])
					{
						strcpy(Cdt_field[k],field_value[i][j]);
						k++;
					}
					else
					{
						if(j%count_field[i]==0)//记录每张表元组个数
						{
							count_value[i]++;
						}
					}
					j++;
				}
				fclose(file_table[i]);
				all_value=all_value*count_value[i];//所有字段笛卡尔乘积后的个数
			}
			for(i=0;i<all_table;i++)//将前all_field个字段所在表的名字复制进去
			{
				for(j=0;j<count_field[i];j++)
				{
					strcpy(Cdt_field[k],tableName[i]);
					k++;
				}
			}
			for(i=0;i<all_field;i++)//初始化要输出的value的标志
			{
				is_print[i]=0;
			}
			for(i=0;i<count_sel;i++)//确定table.field字段
			{
				for(j=0;j<all_field;j++)
				{
					if(strcmp(select_name[i],Cdt_field[j])==0)
					{
						if(strcmp(select_table[i],Cdt_field[j+all_field])==0)//打印字段信息并在相应的位置上设置可输出属性值的标志
						{
							is_print[j]=1;
							strcpy(print_name[i],select_table[i]);
							strcat(print_name[i],".");
							strcat(print_name[i],select_name[i]);
							if(i==count_sel-1)
							{
								printf("%-20s\n",print_name[i]);
							}
							else
							{
								printf("%-20s",print_name[i]);
							}
						}
					}
				}
			}
			for(i=0;i<all_value;i++)//总共判断all_value次
			{
				index=all_table-1;//指向最后一个表
				k=0;
				for(j=0;j<all_table;j++)//读出一行value存入Cdt_value
				{
					for(l=0;l<count_field[j];l++)
					{
						strcpy(Cdt_value[k],field_value[j][read_line[j]*count_field[j]+l]);
						k++;
					}
				}
				condition_flag=CdtSearch(conditionRoot,all_field,Cdt_field,Cdt_value);
				if(condition_flag==1)//满足条件
				{
					m=0;
					for(l=0;l<all_field;l++)//输出is_print标志可输出的value
					{
						if(is_print[l]==1)
						{
							if(m==count_sel-1)
							{
								printf("%-20s\n",Cdt_value[l]);
								count_print++;
								break;
							}
							else
							{
								printf("%-20s",Cdt_value[l]);
							}
							m++;
						}
					}
				}
				handle(read_line,count_value,all_table,index);
			}
			printf("%d Records Selected!\n",count_print);
		}
	}
	freeCdt(conditionRoot);//释放condition指针
	field_tmp = fieldRoot;
    table_tmp = tableRoot;
    while(fieldRoot != NULL)
    {
        field_tmp = fieldRoot;
        fieldRoot = fieldRoot->next_sf;
        free(field_tmp);
    }
    while(tableRoot != NULL)
    {
        table_tmp = tableRoot;
        tableRoot = tableRoot->next_st;
        free(table_tmp);
    }
    _chdir(rootDir);
    printf("MySQL>");
}

//删除数据库-------------------------------------------------------------
void dropDB()
{
	_chdir(rootDir);
	if(_access(database,0)!=-1)//该数据库存在
	{
		char del[100]="rd ";//删除操作参数
		char DB[100][100];//保存已有的数据库名字
		int count_DB=0;//已有数据库个数
		int i;
		FILE *fp;//对database.dat的读操作
		FILE *fp2;//对database.dat的写操作
		strcat(del,database);
		fp=fopen("database.dat","r");
		while(fscanf(fp,"%s",DB[count_DB])!=EOF)//将数据库名字读出
		{
			count_DB++;
		}
		fp2=fopen("database.dat","w");//重写database.dat
		for(i=0;i<count_DB;i++)//把除了删除了数据库名字写入
		{
			if(strcmp(DB[i],database)!=0)
			{
				fprintf(fp2,"%s\n",DB[i]);
			}
		}
		fclose(fp2);
		fclose(fp);
		system(del);
		printf("Delete Database succeed!\n");
	}
	else
	{
		printf("The database doesn't exist!\n");
	}
	_chdir(rootDir);
    printf("MySQL>");
}

//删除表格---------------------------------------------------------------
void dropTable(char *tableName)
{
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//该表格存在
		{
			char del[100]="del ";//删除操作参数
			char table_name[100][100];//保存已有的表格名字
			int count_table=0;//已有表格个数
			int i;
			FILE *fp;//对tables.dat的读操作
			FILE *fp2;//对tables.dat的写操作
			strcat(del,name);
			fp=fopen("tables.dat","r");
			while(fscanf(fp,"%s",table_name[count_table])!=EOF)//将表名字读出
			{
				count_table++;
			}
			fp2=fopen("tables.dat","w");
			for(i=0;i<count_table;i=i+4)//若不是要删除的表格，则将信息直接写入
			{
				if(strcmp(table_name[i],tableName)!=0)
				{
					fprintf(fp2,"%s\t",table_name[i]);
					fprintf(fp2,"%s\t",table_name[i+1]);
					fprintf(fp2,"%s\t",table_name[i+2]);
					fprintf(fp2,"%s\n",table_name[i+3]);
				}
			}
			fclose(fp2);
			fclose(fp);
			system(del);
			printf("Delete table Succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}
	}
	_chdir(rootDir);
    printf("MySQL>");
}

//删除表格内所有数据-----------------------------------------------------
void deleteAll(char *tableName)
{
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//该表格存在
		{
			FILE *fp;//对表格只读
			FILE *fp2;//对表格重写
			char field[100][100];//保存表的字段名
			int all_field;//所有字段个数
			int i;
			fp=fopen(name,"r");
			fscanf(fp,"%d",&all_field);//读出字段个数
			for(i=0;i<all_field;i++)//读出所有字段
			{
				fscanf(fp,"%s",field[i]);
			}
			fp2=fopen(name,"w");//重写
			fprintf(fp2,"%d\n",all_field);//写入字段个数
			for(i=0;i<all_field;i++)//写入所有字段
			{
				if(i==all_field-1)
				{
					fprintf(fp2,"%s\n",field[i]);
				}
				else
				{
					fprintf(fp2,"%s\t",field[i]);
				}
			}
			fclose(fp2);
			fclose(fp);
			printf("Delete data Succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}
	}
	_chdir(rootDir);
    printf("MySQL>");
}

//删除表格内某个数据
void deleteCdt(char *tableName,struct Conditions *conditionRoot)
{
	_chdir(rootDir);
	if(strlen(database)==0)//未use数据库
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//转路径失败
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];//删除数据的表文件名
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//该表格存在
		{
			FILE *fp;//对表格只读
			FILE *fp2;//对表格重写
			char copy[100]="copy ";
			char del[100]="del copy.txt";
			char all_name[100][100];//保存表的字段名
			char all_value[100][100];//保存所有属性值
			int all_field;//所有字段个数
			int file_end=0;//表格读取完的标志
			int condition_flag=0;//判断是否满足条件
			int i,j;
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy tableName.txt copy.txt"
			system(copy);
			fp=fopen("copy.txt","r");//对复制文件只读
			fp2=fopen(name,"w");//对更改的表重写
			fscanf(fp,"%d",&all_field);//读出所有字段个数
			fprintf(fp2,"%d\n",all_field);//写入所有字段个数
			for(i=0;i<all_field;i++)//对name文件重写所有属性字段
			{
				fscanf(fp,"%s",all_name[i]);
				if(i==all_field-1)
				{
					fprintf(fp2,"%s\n",all_name[i]);
				}
				else
				{
					fprintf(fp2,"%s\t",all_name[i]);
				}
			}
			for(i=0;1;i++)
			{
				file_end=0;
				for(j=0;j<all_field;j++)//每次循环读取一行字段值，若碰到文件结束符，跳出循环
				{
					if(fscanf(fp,"%s",all_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//若文件读完，代表更改数据完毕，跳出循环
				{
					break;
				}
				condition_flag=CdtSearch(conditionRoot,all_field,all_name,all_value);
				if(condition_flag==0)//未匹配成功，不是需要删除的行，将旧值重写入
				{
					for(j=0;j<all_field;j++)
					{
						if(j==all_field-1)
						{
							fprintf(fp2,"%s\n",all_value[j]);
						}
						else
						{
							fprintf(fp2,"%s\t",all_value[j]);
						}
					}
				}
			}
			fclose(fp2);
			fclose(fp);
			system(del);//删除复制文件
			printf("Delete data succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}
	}
	free(tableName);
	freeCdt(conditionRoot);
	_chdir(rootDir);
    printf("MySQL>");
}
//-----------------------------------------------------------------------
void main()
{
    printf("***************************************\n");
    printf("*    项目3-编译原理-小型SQL解析器     *\n");
    printf("*    Welcome to MiniMySQL by GWC!     *\n");
    printf("*    电子科技大学 2016级 互联网加     *\n");
    printf("*    关文聪-学号2016060601008         *\n");
    printf("***************************************\n");
    printf("MySQL>");
    _getcwd(rootDir, sizeof(rootDir));
    strcat(rootDir, "\\sql");
    //printf("%s\n",rootDir);
    while(1)
    {
		yyparse();
    }
    
}

void yyerror(const char *str)
{
    fprintf(stderr,"error:%s\n",str);
}
int yywrap()
{
    return 1;
}

