%{
/****************************************************************************
myparser.y
ParserWizard generated YACC file.

Date: 2018��7��10��
****************************************************************************/
#include "mylexer.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<direct.h>
#include<io.h>

char database[100]={0};	//���ݿ�����
char rootDir[100]={0};	//�ļ�����·��
enum TYPE {INT,CHAR};	//�ֶο�������
//create����е��ֶζ���-------------------------------------------------
struct Createfieldsdef{		
	char		*field;			//�ֶ�����
	enum TYPE	type;			//�ֶ�����
	int			length;		//�ֶγ���
	struct	Createfieldsdef	*next_fdef;	//��һ�ֶ�
};
//type�ֶζ���-----------------------------------------------------------
struct fieldType{
	enum TYPE	type;			//�ֶ�����
	int		length;			//�ֶγ���
};
//create�﷨�����ڵ�-----------------------------------------------------
struct Createstruct{		
	char *table;				  //����������
	struct	Createfieldsdef *fdef;//�ֶζ���
};
//insert�﷨�����ڵ�-----------------------------------------------------
struct insertValue {
    char *value;				  //����ֵ
    struct insertValue *next_Value;		  //��һ����ֵ
};
//select����-------------------------------------------------------------
struct Conditions{
	struct Conditions *left;		//������
	struct Conditions *right;		//�Ҳ�����
	char comp_op;				/* 'a'��and, 'o'��or, '<' , '>' , '=', ��!='  */
	int type;				/* 0���ֶΣ�1���ַ�����2������ */
	char *value;				/* ����type����ֶ������ַ��������� */
	char *table;				/* NULL����� */
}; 
//select�����ѡ�е��ֶ�-------------------------------------------------
struct	Selectedfields{
	char 	*table;				//�ֶ�������
	char 	*field;				//�ֶ�����
	struct 	Selectedfields	*next_sf;	//��һ���ֶ�
};
//select�����ѡ�еı�---------------------------------------------------
struct	Selectedtables{
	char	  *table;			//����������
	struct  Selectedtables  *next_st;	//��һ����
};
//select�﷨���ĸ��ڵ�---------------------------------------------------
struct	Selectstruct{
	struct Selectedfields 	*sf;		//��ѡ�ֶ�
	struct Selectedtables	*st;		//��ѡ������
	struct Conditions	*cons;		//����
};
//set�﷨�����ڵ�--------------------------------------------------------
struct Setstruct{
    char *field;					//������ֶ�
    char *value;					//����ֵ
    struct Setstruct *next_sf;				//�������һ�ֶ�
};

//���������б�
void createDB();//�������ݿ�
void getDB();//��ȡ�������ݿ�����
void useDB();//ѡ�����ݿ�
void dropDB();//ɾ�����ݿ�
void createTable(struct Createstruct *cs_root);//������
void getTable();//��ʾ����Ϣ
void dropTable(char *tableName);//ɾ����
void insertOrder(char *tableName,struct insertValue *values);//��˳���������
void insertNoOrder(char *tableName,struct insertValue *valuesNames,struct insertValue *values);//�Զ���˳���������
int CdtSearch(struct Conditions *conditionRoot, int totField, char allField[][100], char value[][100]);//ƥ������ʽ��ID,�ҵ������/��ѯ����
void freeCdt(struct Conditions *conditionRoot);//�ͷ�conditionָ��
void updateAll(char *tableName,struct Setstruct *setRoot);//�޸���������
void updateCdt(char *tableName,struct Setstruct *setRoot,struct Conditions *conditionRoot);//�޸�ѡ�����Ե�����
void selectNoCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot);//��������ѯ
void selectCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot,struct Conditions *conditionRoot);//��������ѯ
void deleteAll(char *tableName);//ɾ���������������
void deleteCdt(char *tableName,struct Conditions *conditionRoot);//ɾ�������ĳ������
void handle(int read_line[],int count_value[],int all_table,int index);//�ѿ����˻��ݹ�


%}

//-----------------------------------------------------------------------
%union{
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
}
%term CREATE SHOW USE DATABASES DATABASE TABLE TABLES CHAR INT SELECT FROM WHERE OR AND QUOTE INSERT INTO VALUES UPDATE SET DELETE DROP EXIT
%term <yych> ID NUMBER
%nonterm <op> comp_op
%nonterm <yych> table field
%nonterm <fT> type
%nonterm <cfdef_var> fieldsdefinition field_type
%nonterm <cs_var> createsql
%nonterm <is_val> values value
%nonterm <sf_var> fields_star  table_fields  table_field
%nonterm <st_var> tables
%nonterm <cons_var> condition  conditions comp_left comp_right
%nonterm <ss_var> selectsql
%nonterm <s_var> set sets

%left OR
%left AND
//%left "+","-"
//%left "*","/"
%%

//-----------------------------------------------------------------------
start		:statements;
statements	:statements statement|statement;
statement	:createsql|selectsql|usesql|showsql|insertsql|deletesql|dropsql|updatesql|exitsql;
createsql:CREATE TABLE table '(' fieldsdefinition ')' ';'
	  {
		$$=(struct Createstruct *)malloc(sizeof(struct Createstruct));
		$$->table=$3;
		$$->fdef=$5;
		createTable($$);
	  }
	 |CREATE DATABASE ID ';'
	  {
		strcpy(database,$3);
		createDB();
	  };
	  table:ID
	  {
		$$=$1;
	  };
	  fieldsdefinition:field_type
	  {
		$$=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		$$->field=$1->field;
		$$->type=$1->type;
		$$->length=$1->length;
		$$->next_fdef=NULL;
	  }
	 |field_type ',' fieldsdefinition
	  {
		$$=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		$$->field=$1->field;
		$$->type=$1->type;
		$$->length=$1->length;
		$$->next_fdef=$3;
	  };
	  field_type:field type
	  {
		$$=(struct Createfieldsdef *)malloc(sizeof(struct Createfieldsdef));
		$$->field=$1;
		$$->type=$2->type;
		$$->length=$2->length;
	  };
	  field:ID
	  {
		$$=$1;
	  };
	  type:CHAR '(' NUMBER ')'
	  {
		$$=(struct fieldType *)malloc(sizeof(struct fieldType));
		$$->type=CHAR;
		$$->length=atoi($3);
	  }
	 |INT
	  {
		$$=(struct fieldType *)malloc(sizeof(struct fieldType));
		$$->type=INT;
		$$->length=4;
	  };
usesql:USE ID ';'
       {
	    strcpy(database,$2);
	    useDB();
       };
showsql	:SHOW DATABASES ';'
	 {
		printf("Database:\n");
		getDB();
	 }
	|SHOW TABLES ';'
	 {
		printf("Tables:\n");
		getTable();
	 };
selectsql:SELECT fields_star FROM tables ';'
	  {
		selectNoCdt($2,$4);
	  }
	 |SELECT fields_star FROM tables WHERE conditions ';'
	  {
		selectCdt($2,$4,$6);
	  };
	  fields_star:table_fields
	  {
		$$ =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$=$1;
	  }
	 |'*'
	  {
		$$ =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$=NULL;
	  };
	  table_fields:table_field
	  {
		$$ =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$=$1;
	  }
	 |table_field ',' table_fields
	  {
		$$ =(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$->field=$1->field;
		$$->table=$1->table;
		$$->next_sf=$3;
	  };
	  table_field:field
	  {
		$$=(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$->field=$1;
		$$->table=NULL;
		$$->next_sf=NULL;
	  }
	 |table '.' field
	  {
		$$=(struct Selectedfields *)malloc(sizeof(struct Selectedfields));
		$$->field=$3;
		$$->table=$1;
		$$->next_sf=NULL;
	  };
	  tables:table
	  {
		$$=(struct Selectedtables *)malloc(sizeof(struct Selectedtables));
		$$->table=$1;
		$$->next_st=NULL;
	  }
	 |table ',' tables
	  {
		$$=(struct Selectedtables *)malloc(sizeof (struct Selectedtables));
		$$->table=$1;
		$$->next_st=$3;
	  };
	  conditions:condition
	  {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$=$1;
	  }
	 |'('conditions')'
	  {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$=$2;
	  }
	 |conditions AND conditions
	  {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->left=$1;
		$$->right=$3;
		$$->comp_op='a';
	  }
	 |conditions OR conditions
	  {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->left=$1;
		$$->right=$3;
		$$->comp_op='o';
	  };
	  condition:comp_left comp_op comp_right
	  {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->left=$1;
		$$->right=$3;
		$$->comp_op=$2;
	  };
	  comp_left:table_field
	 {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->type=0;
		$$->value=$1->field;
		$$->table=$1->table;
		$$->left=NULL;
		$$->right=NULL;
	 };
	 comp_right:table_field
	 {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->type=0;
		$$->value=$1->field;
		$$->table=$1->table;
		$$->left=NULL;
		$$->right=NULL;
	 }
	|NUMBER
	 {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->type=2;
		$$->value=$1;
		$$->table=NULL;
		$$->left=NULL;
		$$->right=NULL;
	 }
	|QUOTE ID QUOTE
	 {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->type=1;
		$$->value=$2;
		$$->table=NULL;
		$$->left=NULL;
		$$->right=NULL;
	 }
	|QUOTE NUMBER QUOTE
	 {
		$$=(struct Conditions *)malloc(sizeof(struct Conditions));
		$$->type=1;
		$$->value=$2;
		$$->table=NULL;
		$$->left=NULL;
		$$->right=NULL;
	 };
	 comp_op:'<'
	 {
		$$='<';
	 }
	|'>'
	 {
		$$='>';
	 }
	|'='
	 {
		$$='=';
	 }
	|'!''='
	 {
		$$='!';
	 };
insertsql:INSERT INTO table VALUES '(' values ')' ';'
	  {
		insertOrder($3,$6);
	  }
	 |INSERT INTO table '(' values ')' VALUES '(' values ')' ';'
	  {
		insertNoOrder($3,$5,$9);
	  };
	  values:value
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$1->value;
		$$->next_Value=NULL;
	  }
	 |value ',' values
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$1->value;
		$$->next_Value=$3;
	  };
	  value:QUOTE ID QUOTE
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$2;
		$$->next_Value=NULL;
	  }
	 |QUOTE NUMBER QUOTE
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$2;
		$$->next_Value=NULL;
	  }
	 |NUMBER
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$1;
		$$->next_Value=NULL;
	  }
	 |ID
	  {
		$$=(struct insertValue *)malloc(sizeof(struct insertValue));
		$$->value=$1;
		$$->next_Value=NULL;
	  };
deletesql:DELETE FROM table ';'
	  {
		deleteAll($3);
	  }
	 |DELETE FROM table WHERE conditions ';'
	  {
		deleteCdt($3,$5);
	  };
dropsql:DROP TABLE ID ';'
	{
		dropTable($3);
	}
       |DROP DATABASE ID ';'
	{
		strcpy(database,$3);
		dropDB();
	};
updatesql:UPDATE table SET sets ';'
	  {
		updateAll($2,$4);
	  }
	 |UPDATE table SET sets WHERE conditions ';'
	  {
		updateCdt($2,$4,$6);
	  };
	  sets:set
	  {
		$$=$1;
	  }
	 |set ',' sets
	  {
		$$=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		$$->field=$1->field;
		$$->value=$1->value;
		$$->next_sf=$3;
	  };
	  set:ID '=' NUMBER
	  {
		$$=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		$$->field=$1;
		$$->value=$3;
		$$->next_sf=NULL;
	  }
	 |ID '=' QUOTE ID QUOTE
	  {
		$$=(struct Setstruct *)malloc(sizeof(struct Setstruct));
		$$->field=$1;
		$$->value=$4;
		$$->next_sf=NULL;
	  };
exitsql:EXIT ';'
	{
             	printf("Thank you��Glad to see you again!\n");
           	exit(0);
	};		


%%

//-----------------------------------------------------------------------
/* �������ݿ� */
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
		if(_mkdir(database)==-1)//���������ݿ�Ϊ�����ļ���
		{
			printf("Create database failed!\n");
		}
		else
		{
			fp=fopen("database.dat","a+");//��û�д��ļ��򴴽����������ļ�ĩ������ݿ�����
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
/* ��ȡ�������ݿ����� */
void getDB()
{
	FILE *fp;
	char name[100];
	_chdir(rootDir);
	fp=fopen("database.dat","r");//�򿪱������ݿ����ֵ��ļ�
	if(fp==NULL)
	{
		printf("open database.dat failed!\n");
	}
	else
	{
		while(fscanf(fp,"%s",name)!=EOF)
		{
			printf("%s\n",name);//��ӡ���ݿ�����
		}	
	}
	fclose(fp);
	_chdir(rootDir);
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* ѡ�����ݿ� */
void useDB()
{
	char name[100];//������use�����ݿ����·��
	_chdir(rootDir);
	strcpy(name,rootDir);
	strcat(name,"\\");
	strcat(name,database);
	if(_chdir(name)==0)//ת����use�����ݿ������·��
	{
		if(_access(name,0)!=-1)//��������ı�����
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
	strcpy(database,name);//����database
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* ������ */
void createTable(struct Createstruct *cs_root)
{
	struct Createfieldsdef *cfdef=cs_root->fdef;
	int d=4;//INT�͵ĳ���
	int i=0;//��¼�������������Ը���
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		FILE *fp;
		FILE *fp2;
		char name[100];//�����������������
		char table[100];//�����������ļ�������
		strcpy(name,cs_root->table);
		fp=fopen("tables.dat","a+");//�����ܱ�
		if(fp==NULL)
		{
			printf("Open tables.dat failed!\n");
		}
		else
		{
			strcpy(table,name);
			strcat(table,".txt");
			if(_access(table,0)!=-1)//���������ı��Ѵ���
			{
				printf("The table already exist!\n");
			}
			else
			{
				while(cfdef!=NULL)//�������Ϣ�����ܱ�
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
					fprintf(fp2,"%d\n",i);//���ļ���һ��д�������Ը���
					while(cfdef!=NULL)//������ֶδ����ļ�
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
    while(cfdef!= NULL)//�ͷ�ָ��
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
/* ��ʾ����Ϣ */
void getTable()
{
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
	
		FILE *fp;
		char s1[100],s2[100],s3[100];//�������ֶΣ��ֶ�����
		int d;//�ֶγ���
		fp=fopen("tables.dat","r");
		if(fp==NULL)
		{
			printf("Open tables.dat failed!\n");
		}
		else
		{
			fscanf(fp,"%d",&d);//���˵�һ�еı�����Ը���
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
/* ��˳��������� */
void insertOrder(char *tableName,struct insertValue *values)
{
	char name[100];
	_chdir(rootDir);
	strcpy(name,tableName);
	strcat(name,".txt");
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		if(_access(name,0)!=-1)//��������ı�����
		{
			FILE *fp;
			struct insertValue *valuestmp=values;
			fp=fopen(name,"a+");//���ļ�����ĩβ�������
			if(fp==NULL)
			{
				printf("Open %s failed!\n",name);
			}
			else
			{
				while(valuestmp!=NULL)//д������
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
	while(values!=NULL)//�ͷ�ָ��
	{
		struct insertValue *valuestmp=values;
		values=values->next_Value;
		free(valuestmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//-----------------------------------------------------------------------
/* �Զ���˳��������� */
void insertNoOrder(char *tableName,struct insertValue *valuesName,struct insertValue *values)
{
	char name[100];//����д�����ݵ��ļ���
	char select_name[100][100];//��ѡ�ֶ���
	char all_name[100][100];//�����ֶ���
	char select_value[100][100];//�ֶ�ֵ
	int flag=0;//��ѡ�ֶεĸ���
	int flag2=0;//�ֶ�ֵ�ø���
	int N;//�����ֶεĸ���
	int i,j;
	_chdir(rootDir);
	strcpy(name,tableName);
	strcat(name,".txt");
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		if(_access(name,0)!=-1)//��������ı�����
		{
			FILE *fp;
			FILE *fp2;
			struct insertValue *val_Name=valuesName;
			struct insertValue *val_tmp=values;
			while(val_Name!=NULL)//����ѡ�ֶα�����Name������
			{
				strcpy(select_name[flag],val_Name->value);
				flag++;
				val_Name=val_Name->next_Value;
			}
			while(val_tmp!=NULL)//������ֵ������Value������
			{
				strcpy(select_value[flag2],val_tmp->value);
				flag2++;
				val_tmp=val_tmp->next_Value;
			}
			if(flag!=flag2)//�����������޷�����
			{
				printf("Numbers are not equal!\n");
			}
			else
			{
				fp=fopen(name,"r");//���ļ�ֻ��
				if(fp==NULL)
				{
					printf("Open %s failed!\n",name);
				}
				else
				{
					fscanf(fp,"%d\n",&N);//�����һ�еı�����Ը���
					for(i=0;i<N;i++)//�������ֶα�����all_name������
					{
						fscanf(fp,"%s",all_name[i]);
						if(i>=flag)//���N������ѡ�ֶθ�����������Ӧλ�ô�NULL
						{
							strcpy(select_value[i],"NULL");
							strcpy(select_name[i],"NULL");
						}
					}
					strcpy(select_value[i],"NULL");
					strcpy(select_name[i],"NULL");
					for(i=0;i<N;i++)//��Value�������ֵ��λ�ö�Ӧall_name
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
						for(i=0;i<N;i++)//д�����ݣ���δѡ����ֵ��λ������NULL
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
			while(valuesName!=NULL)//�ͷ�ָ��
			{
				struct insertValue *val_Name=valuesName;
				valuesName=valuesName->next_Value;
				free(val_Name);
			}
			while(values!=NULL)//�ͷ�ָ��
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

//ƥ������ʽ��ID,�ҵ������/��ѯ����-------------------------------------
int CdtSearch(struct Conditions *conditionRoot, int totField, char allField[][100], char value[][100])
{
    char comp_op = conditionRoot->comp_op;//������
    int field = 0;
    int field2 = 0;
    int i;
    if (comp_op == 'a')//����AND����������ʽ�ĺͣ�����1��ʾ����ƥ��ɹ�
    {
        return (CdtSearch(conditionRoot->left, totField, allField, value)&&CdtSearch(conditionRoot->right, totField, allField, value));
    }
    else if (comp_op == 'o')//����OR����������ʽ�Ļ򣬷���1��ʾ����ƥ��ɹ�
    {
        return (CdtSearch(conditionRoot->left, totField, allField, value) || CdtSearch(conditionRoot->right, totField, allField, value));
    }
    else//������ʽΪ����
    {
        if(conditionRoot->right->type==0)//����ID=ID�����������ҵ�ƥ����table.field���ֶ��±�
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
			for (i = 0; i < totField; ++i)//ƥ������ֶκͱ����ֶΣ��ɹ����¼�������ڵڼ���
			{
				if (strcmp(allField[i], conditionRoot->left->value) == 0)
				{
					field = i;
					break;
				}
			}
        }
        if (comp_op == '=')//���е�ֵ������ʽ�Ҳ����
        {
            if(conditionRoot->right->type==0)
            {
				for(i=0;i<totField;i++)//�ҵ��Ҳ��ֶ�field�������ֶ�field
				{
					if(strcmp(allField[i+totField],conditionRoot->right->table)==0)
					{
						if(strcmp(allField[field2],allField[i])==0)
						{
							if(strcmp(value[field2],value[i])==0)//������ͬ����ֵ
							{
								return 1;
							}
						}
					}
				}
				if(i==totField)//û�ҵ�����0
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
        else if (comp_op == '>')//���е�ֵ��������ʽ�Ҳ�
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
        else if (comp_op == '<')//���е�ֵС������ʽ�Ҳ�
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
        else if (comp_op == '!')//���е�ֵ����������ʽ�Ҳ�
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

//�ͷ�conditionָ��
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
//�޸���������-----------------------------------------------------------
void updateAll(char *tableName,struct Setstruct *setRoot)
{
	char name[100];//������Ҫ�������ݵ��ļ���
	char copy[100]="copy ";//���渴��name���ļ���system��������
	char del[100]="del copy.txt";//���ݸ�����ɺ�ɾ�������ļ�
	char update_name[100][100];//����ĵ��ֶ���
	char update_value[100][100];//���ĵ��ֶ�ֵ
	char all_name[100][100];//�����ֶ���
	char old_value[100][100];//�ɵ��ֶ�ֵ
	int flag;//�ж�������ֶεı��
	int all_field=0;//�����ֶθ���
	int update_set=0;//����ĵĸ���
	int file_end=0;//�ж��ļ��Ƿ���꣬1��ʾ�Ѷ���
	int i,j,k;
	FILE *fp;//�򿪸����ļ�
	FILE *fp2;//��дname�ļ�
	struct Setstruct *Set_tmp=setRoot;//�����ֶ�ָ��
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//������������ݵı�����
		{
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy name copy.txt"
			while(Set_tmp!=NULL)//����Ҫ�������ݵ��ֶ��Լ��ֶ�ֵ�ֱ𱣴浽update_name��update_value��
			{
				strcpy(update_name[update_set],Set_tmp->field);
				strcpy(update_value[update_set],Set_tmp->value);
				update_set++;
				Set_tmp=Set_tmp->next_sf;
			}
			system(copy);
			fp=fopen("copy.txt","r");//�Ը����ļ�ֻ��
			fp2=fopen(name,"w");//�Ը��ĵı���д
			fscanf(fp,"%d",&all_field);//���������ֶθ���
			fprintf(fp2,"%d\n",all_field);//д�������ֶθ���
			for(i=0;i<all_field;i++)//��name�ļ���д���������ֶ�
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
				for(j=0;j<all_field;j++)//ÿ��ѭ����ȡһ���ֶ�ֵ���������ļ�������������ѭ��
				{
					if(fscanf(fp,"%s",old_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//���ļ����꣬�������������ϣ�����ѭ��
				{
					break;
				}
				for(j=0;j<all_field;j++)
				{
					flag=0;
					for(k=0;k<update_set;k++)//�ҵ�����ĵ��ֶν����ݸ���
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
					if(flag==0)//����Ҫ�������ݵ��ֶν�ԭ����д��
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
		system(del);//ɾ�������ļ�
		printf("Update succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	free(tableName);
	while(setRoot!=NULL)//�ͷ�setָ��
	{
		struct Setstruct *Set_tmp=setRoot;
		setRoot=setRoot->next_sf;
		free(Set_tmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//�޸�ѡ�����Ե�����
void updateCdt(char *tableName,struct Setstruct *setRoot,struct Conditions *conditionRoot)
{
	char name[100];//������Ҫ�������ݵ��ļ���
	char copy[100]="copy ";//���渴��name���ļ���system��������
	char del[100]="del copy.txt";//���ݸ�����ɺ�ɾ�������ļ�
	char update_name[100][100];//����ĵ��ֶ���
	char update_value[100][100];//���ĵ��ֶ�ֵ
	char all_name[100][100];//�����ֶ���
	char old_value[100][100];//�ɵ��ֶ�ֵ
	int condition_flag;//CdtSearch()����ʽ���ص�ֵ
	int flag;//�ж�������ֶεı��
	int all_field=0;//�����ֶθ���
	int update_set=0;//����ĵĸ���
	int file_end=0;//�ж��ļ��Ƿ���꣬1��ʾ�Ѷ���
	int i,j,k;
	FILE *fp;//�򿪸����ļ�
	FILE *fp2;//��дname�ļ�
	struct Setstruct *Set_tmp=setRoot;//�����ֶ�ָ��
	struct Conditions *Cdt_tmp=conditionRoot;//����ָ��
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//������������ݵı�����
		{
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy name copy.txt"
			while(Set_tmp!=NULL)//����Ҫ�������ݵ��ֶ��Լ��ֶ�ֵ�ֱ𱣴浽update_name��update_value��
			{
				strcpy(update_name[update_set],Set_tmp->field);
				strcpy(update_value[update_set],Set_tmp->value);
				update_set++;
				Set_tmp=Set_tmp->next_sf;
			}
			system(copy);
			fp=fopen("copy.txt","r");//�Ը����ļ�ֻ��
			fp2=fopen(name,"w");//�Ը��ĵı���д
			fscanf(fp,"%d",&all_field);//���������ֶθ���
			fprintf(fp2,"%d\n",all_field);//д�������ֶθ���
			for(i=0;i<all_field;i++)//��name�ļ���д���������ֶ�
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
				for(j=0;j<all_field;j++)//ÿ��ѭ����ȡһ���ֶ�ֵ���������ļ�������������ѭ��
				{
					if(fscanf(fp,"%s",old_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//���ļ����꣬�������������ϣ�����ѭ��
				{
					break;
				}
				condition_flag=CdtSearch(conditionRoot,all_field,all_name,old_value);
				if(condition_flag==0)//δƥ��ɹ���������Ҫ���ĵ��У�����ֵ��д��
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
				else//ƥ�䵽����ĵ���
				{
					for(j=0;j<all_field;j++)
					{
						flag=0;
						for(k=0;k<update_set;k++)//�ҵ�����ĵ��ֶν����ݸ���
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
						if(flag==0)//����Ҫ�������ݵ��ֶν�ԭ����д��
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
		system(del);//ɾ�������ļ�
		printf("Update succeed!\n");
		}
		else
		{
			printf("The table doesn't exist!\n");
		}	
	}
	free(tableName);
	freeCdt(conditionRoot);//�ͷ�conditionָ��
	while(setRoot!=NULL)//�ͷ�SETָ��
	{
		struct Setstruct *Set_tmp=setRoot;
		setRoot=setRoot->next_sf;
		free(Set_tmp);
	}
	_chdir(rootDir);
	printf("MySQL>");
}

//��������ѯ-------------------------------------------------------------
void selectNoCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot)
{
	char tableName[100][100];//������ļ�����
	char fileName[100][100];//���������
	int all_table=0;//���б����
	int all_field=0;//���������ֶθ���
	int flag=1;//�жϱ��Ƿ���ڵı�־
	int i,j;
	struct Selectedfields *field_tmp=fieldRoot;
	struct Selectedtables *table_tmp=tableRoot;
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		while(table_tmp!=NULL)//��������Ҫ��ѯ�ı����ֱ�����tableName
		{
			strcpy(fileName[all_table],table_tmp->table);
			strcpy(tableName[all_table],table_tmp->table);
			strcat(tableName[all_table],".txt");
			all_table++;
			table_tmp=table_tmp->next_st;
		}
		if(field_tmp==NULL)//'*'��ѯ
		{
			for(i=0;i<all_table;i++)
			{
				if(_access(tableName[i],0)==-1)//��񲻴���
				{
					printf("The table %s doesn't exist!\n",fileName[i]);
					flag=0;
					break;
				}
			}
			if(flag && (all_table==1))
			{
				FILE *fp;
				char field_value[100][100];//�ֶ�������ֵ
				int i=0;
				int count_value=0;//Ԫ�����(����������)
				fp=fopen(tableName[0],"r");
				fscanf(fp,"%d",&all_field);//��ȡ�����и���
				while(fscanf(fp,"%s",field_value[i])!=EOF)
				{
					if(i==all_field-1)//���һ�е����һ����������i����Ϊ0��������һ�еĴ�ӡ
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
				FILE *file_table[100];//��
				int all_value=0;//����Ԫ�����
				int count_field[100];//ÿ�ű��ֶθ���
				int count_value[100];//ÿ�ű�Ԫ�����(����������)
				char field_values[5][100][100];//����ÿ�ű����ֶ��Լ��ֶ�ֵ
				for(i=0;i<all_table;i++)//ÿ�ű�ֻ��
				{
					file_table[i]=fopen(tableName[i],"r");
				}
				for(i=0;i<all_table;i++)//��ȡÿ�ű�������и���
				{
					fscanf(file_table[i],"%d",&count_field[i]);
				}
				for(i=0;i<all_table;i++)//�ֱ��ӡ��ѯ�ı�
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
				printf("%d Records Selected!\n",all_value);//��ӡ��ѯ��������Ԫ�����
			}
		}
		else//ָ���ֶβ�ѯ
		{
			if(all_table!=1)//��������ָ���ֶβ�ѯֻ���ǵ����ѯ
			{
				printf("Select only one table!\n");
			}
			else
			{
				if(_access(tableName[0],0)==-1)//��񲻴���
				{
					printf("The table %s doesn't exist!\n",tableName[0]);
				}
				else
				{
					FILE *fp;
					char select_field[100][100];//��ѯ���ֶ���
					char all_name[100][100];//�����ֶ���
					char all_values[100][100];//���е�����ֵ
					int count_sel=0;//���ѯ���ֶθ���
					int count_value=0;//��ѯԪ�����
					fp=fopen(tableName[0],"r");
					fscanf(fp,"%d",&all_field);//��ȡ�ֶθ���
					for(i=0;i<all_field;i++)//��ȡ�����ֶ�
					{
						fscanf(fp,"%s",all_name[i]);
					}
					while(field_tmp!=NULL)//��ȡ��Ҫ��ѯ���ֶ�
					{
						strcpy(select_field[count_sel],field_tmp->field);
						count_sel++;
						field_tmp=field_tmp->next_sf;
					}
					for(i=0;i<count_sel;i++)//��ӡ��Ҫ��ѯ���ֶ�
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
					while(fscanf(fp,"%s",all_values[i])!=EOF)//��ӡ��ѯ������ֵ
					{
						for(j=0;j<count_sel;j++)
						{
							if(strcmp(all_name[(i%all_field)],select_field[j])==0)//ƥ���ѯ�ֶ�
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

//�ѿ����˻��ݹ�---------------------------------------------------------
void handle(int read_line[],int count_value[],int all_table,int index)
{  
	read_line[index]++;//�кż�1
    if (read_line[index] > count_value[index])//��indexָ���ı����
    {  
		read_line[index] = 1;//����ָ�ص�һ��
		index--;//����ǰһ����
        if (index >= 0)//�����б�û����
        {  
			handle(read_line,count_value,all_table,index);  
        }  
        index = all_table - 1;//����ָ�����һ����
    }  
} 
 
//��������ѯ-------------------------------------------------------------
void selectCdt(struct Selectedfields *fieldRoot,struct Selectedtables *tableRoot,struct Conditions *conditionRoot)
{
	int all_table=0;//���б����
	int all_field=0;//���������ֶθ���
	int i,j,k;
	int flag=1;//�жϱ����ڵı�־
	int condition_flag;//CdtSearch()����ʽ���ص�ֵ
	int file_end=0;//�ж��ļ��Ƿ���꣬1��ʾ�Ѷ���
	char tableName[100][100];//���������
	char fileName[100][100];//���ļ�������
	char select_name[100][100];//��ѯ�ֶ�
	int count_sel=0;//��ѯ�ֶθ���
	struct Selectedfields *field_tmp=fieldRoot;
	struct Selectedtables *table_tmp=tableRoot;
	struct Conditions *Cdt_tmp=conditionRoot;
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		while(table_tmp!=NULL)//��������Ҫ��ѯ�ı����ֱ�����tableName
		{
			strcpy(tableName[all_table],table_tmp->table);
			strcpy(fileName[all_table],table_tmp->table);
			strcat(fileName[all_table],".txt");
			all_table++;
			table_tmp=table_tmp->next_st;
		}
		for(i=0;i<all_table;i++)
		{
			if(_access(fileName[i],0)==-1)//��񲻴���
			{
				printf("The table %s doesn't exist!\n",fileName[i]);
				flag=0;
				break;
			}
		}
		if(flag && (all_table==1))
		{
			FILE *fp;
			char all_name[100][100];//�����ֶ�
			char all_values[100][100];//��������ֵ
			int count_value=0;//��ѯԪ�����
			fp=fopen(fileName[0],"r");
			fscanf(fp,"%d",&all_field);//��ȡ�����и���
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
				for(j=0;j<all_field;j++)//ÿ��ѭ����ȡһ���ֶ�ֵ���������ļ�������������ѭ��
				{
					if(fscanf(fp,"%s",all_values[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//���ļ����꣬�������������ϣ�����ѭ��
				{
					break;
				}
				condition_flag=CdtSearch(Cdt_tmp,all_field,all_name,all_values);
				if(condition_flag==1)//ƥ�䵽��ѯ����
				{
					for(j=0;j<all_field;j++)
					{
						for(k=0;k<count_sel;k++)//�ҵ���ѯ���ֶν����ݴ�ӡ
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
			FILE *file_table[100];//��
			int all_value=1;//����Ԫ��ѿ����˻�����
			int count_field[100];//ÿ�����ֶθ���
			int count_value[100];//ÿ����Ԫ�����
			int index;//ָ�����±�
			int read_line[100]={1,1,1,1,1};//�������к�
			char field_value[5][100][100];//���������ֶ��Լ�����ֵ
			char Cdt_field[100][100];//��ǰ��ѯ�е��ֶμ�����
			char Cdt_value[100][100];//��ǰ��ѯ�е�����ֵ
			char select_table[100][100];//��ѯ�ֶ����ڵı�
			char print_name[100][100];//��ӡ���ֶ�
			int is_print[100];//�ж��Ƿ�����
			int count_print=0;//���Ԫ��ĸ���
			int l,m;
			for(i=0;i<all_table;i++)//ÿ�ű�ֻ��
			{
				file_table[i]=fopen(fileName[i],"r");
			}
			while(field_tmp!=NULL)//Ҫ��ѯ���ֶΣ���¼�ֶθ���
			{
				strcpy(select_name[count_sel],field_tmp->field);
				strcpy(select_table[count_sel],field_tmp->table);
				count_sel++;
				field_tmp=field_tmp->next_sf;
			}
			for(i=0;i<all_table;i++)
			{
				fscanf(file_table[i],"%d",&count_field[i]);//��ȡÿ�ű���ֶθ���
				j=0;
				k=all_field;
				all_field+=count_field[i];//�����ֶθ���
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
						if(j%count_field[i]==0)//��¼ÿ�ű�Ԫ�����
						{
							count_value[i]++;
						}
					}
					j++;
				}
				fclose(file_table[i]);
				all_value=all_value*count_value[i];//�����ֶεѿ����˻���ĸ���
			}
			for(i=0;i<all_table;i++)//��ǰall_field���ֶ����ڱ�����ָ��ƽ�ȥ
			{
				for(j=0;j<count_field[i];j++)
				{
					strcpy(Cdt_field[k],tableName[i]);
					k++;
				}
			}
			for(i=0;i<all_field;i++)//��ʼ��Ҫ�����value�ı�־
			{
				is_print[i]=0;
			}
			for(i=0;i<count_sel;i++)//ȷ��table.field�ֶ�
			{
				for(j=0;j<all_field;j++)
				{
					if(strcmp(select_name[i],Cdt_field[j])==0)
					{
						if(strcmp(select_table[i],Cdt_field[j+all_field])==0)//��ӡ�ֶ���Ϣ������Ӧ��λ�������ÿ��������ֵ�ı�־
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
			for(i=0;i<all_value;i++)//�ܹ��ж�all_value��
			{
				index=all_table-1;//ָ�����һ����
				k=0;
				for(j=0;j<all_table;j++)//����һ��value����Cdt_value
				{
					for(l=0;l<count_field[j];l++)
					{
						strcpy(Cdt_value[k],field_value[j][read_line[j]*count_field[j]+l]);
						k++;
					}
				}
				condition_flag=CdtSearch(conditionRoot,all_field,Cdt_field,Cdt_value);
				if(condition_flag==1)//��������
				{
					m=0;
					for(l=0;l<all_field;l++)//���is_print��־�������value
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
	freeCdt(conditionRoot);//�ͷ�conditionָ��
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

//ɾ�����ݿ�-------------------------------------------------------------
void dropDB()
{
	_chdir(rootDir);
	if(_access(database,0)!=-1)//�����ݿ����
	{
		char del[100]="rd ";//ɾ����������
		char DB[100][100];//�������е����ݿ�����
		int count_DB=0;//�������ݿ����
		int i;
		FILE *fp;//��database.dat�Ķ�����
		FILE *fp2;//��database.dat��д����
		strcat(del,database);
		fp=fopen("database.dat","r");
		while(fscanf(fp,"%s",DB[count_DB])!=EOF)//�����ݿ����ֶ���
		{
			count_DB++;
		}
		fp2=fopen("database.dat","w");//��дdatabase.dat
		for(i=0;i<count_DB;i++)//�ѳ���ɾ�������ݿ�����д��
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

//ɾ�����---------------------------------------------------------------
void dropTable(char *tableName)
{
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//�ñ�����
		{
			char del[100]="del ";//ɾ����������
			char table_name[100][100];//�������еı������
			int count_table=0;//���б�����
			int i;
			FILE *fp;//��tables.dat�Ķ�����
			FILE *fp2;//��tables.dat��д����
			strcat(del,name);
			fp=fopen("tables.dat","r");
			while(fscanf(fp,"%s",table_name[count_table])!=EOF)//�������ֶ���
			{
				count_table++;
			}
			fp2=fopen("tables.dat","w");
			for(i=0;i<count_table;i=i+4)//������Ҫɾ���ı������Ϣֱ��д��
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

//ɾ���������������-----------------------------------------------------
void deleteAll(char *tableName)
{
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//�ñ�����
		{
			FILE *fp;//�Ա��ֻ��
			FILE *fp2;//�Ա����д
			char field[100][100];//�������ֶ���
			int all_field;//�����ֶθ���
			int i;
			fp=fopen(name,"r");
			fscanf(fp,"%d",&all_field);//�����ֶθ���
			for(i=0;i<all_field;i++)//���������ֶ�
			{
				fscanf(fp,"%s",field[i]);
			}
			fp2=fopen(name,"w");//��д
			fprintf(fp2,"%d\n",all_field);//д���ֶθ���
			for(i=0;i<all_field;i++)//д�������ֶ�
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

//ɾ�������ĳ������
void deleteCdt(char *tableName,struct Conditions *conditionRoot)
{
	_chdir(rootDir);
	if(strlen(database)==0)//δuse���ݿ�
	{
        printf("Please use a database first!\n");
	}
    else if(_chdir(database) == -1)//ת·��ʧ��
	{
        printf("Turn direction failed!\n");
	}
	else
	{
		char name[100];//ɾ�����ݵı��ļ���
		strcpy(name,tableName);
		strcat(name,".txt");
		if(_access(name,0)!=-1)//�ñ�����
		{
			FILE *fp;//�Ա��ֻ��
			FILE *fp2;//�Ա����д
			char copy[100]="copy ";
			char del[100]="del copy.txt";
			char all_name[100][100];//�������ֶ���
			char all_value[100][100];//������������ֵ
			int all_field;//�����ֶθ���
			int file_end=0;//����ȡ��ı�־
			int condition_flag=0;//�ж��Ƿ���������
			int i,j;
			strcat(copy,name);
			strcat(copy," ");
			strcat(copy,"copy.txt");//copy[]:"copy tableName.txt copy.txt"
			system(copy);
			fp=fopen("copy.txt","r");//�Ը����ļ�ֻ��
			fp2=fopen(name,"w");//�Ը��ĵı���д
			fscanf(fp,"%d",&all_field);//���������ֶθ���
			fprintf(fp2,"%d\n",all_field);//д�������ֶθ���
			for(i=0;i<all_field;i++)//��name�ļ���д���������ֶ�
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
				for(j=0;j<all_field;j++)//ÿ��ѭ����ȡһ���ֶ�ֵ���������ļ�������������ѭ��
				{
					if(fscanf(fp,"%s",all_value[j])==EOF)
					{
						file_end=1;
						break;
					}
				}
				if(file_end==1)//���ļ����꣬�������������ϣ�����ѭ��
				{
					break;
				}
				condition_flag=CdtSearch(conditionRoot,all_field,all_name,all_value);
				if(condition_flag==0)//δƥ��ɹ���������Ҫɾ�����У�����ֵ��д��
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
			system(del);//ɾ�������ļ�
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
    printf("*    ��Ŀ3-����ԭ��-С��SQL������     *\n");
    printf("*    Welcome to MiniMySQL by GWC!     *\n");
    printf("*    ���ӿƼ���ѧ 2016�� ��������     *\n");
    printf("*    ���Ĵ�-ѧ��2016060601008         *\n");
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
