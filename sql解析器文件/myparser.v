#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 2 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# myparser.v
# YACC verbose file generated from myparser.y.
# 
# Date: 07/11/18
# Time: 14:45:40
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : start $end

    1  start : statements

    2  statements : statements statement
    3             | statement

    4  statement : createsql
    5            | selectsql
    6            | usesql
    7            | showsql
    8            | insertsql
    9            | deletesql
   10            | dropsql
   11            | updatesql
   12            | exitsql

   13  createsql : CREATE TABLE table '(' fieldsdefinition ')' ';'
   14            | CREATE DATABASE ID ';'

   15  table : ID

   16  fieldsdefinition : field_type
   17                   | field_type ',' fieldsdefinition

   18  field_type : field type

   19  field : ID

   20  type : CHAR '(' NUMBER ')'
   21       | INT

   22  usesql : USE ID ';'

   23  showsql : SHOW DATABASES ';'
   24          | SHOW TABLES ';'

   25  selectsql : SELECT fields_star FROM tables ';'
   26            | SELECT fields_star FROM tables WHERE conditions ';'

   27  fields_star : table_fields
   28              | '*'

   29  table_fields : table_field
   30               | table_field ',' table_fields

   31  table_field : field
   32              | table '.' field

   33  tables : table
   34         | table ',' tables

   35  conditions : condition
   36             | '(' conditions ')'
   37             | conditions AND conditions
   38             | conditions OR conditions

   39  condition : comp_left comp_op comp_right

   40  comp_left : table_field

   41  comp_right : table_field
   42             | NUMBER
   43             | QUOTE ID QUOTE
   44             | QUOTE NUMBER QUOTE

   45  comp_op : '<'
   46          | '>'
   47          | '='
   48          | '!' '='

   49  insertsql : INSERT INTO table VALUES '(' values ')' ';'
   50            | INSERT INTO table '(' values ')' VALUES '(' values ')' ';'

   51  values : value
   52         | value ',' values

   53  value : QUOTE ID QUOTE
   54        | QUOTE NUMBER QUOTE
   55        | NUMBER
   56        | ID

   57  deletesql : DELETE FROM table ';'
   58            | DELETE FROM table WHERE conditions ';'

   59  dropsql : DROP TABLE ID ';'
   60          | DROP DATABASE ID ';'

   61  updatesql : UPDATE table SET sets ';'
   62            | UPDATE table SET sets WHERE conditions ';'

   63  sets : set
   64       | set ',' sets

   65  set : ID '=' NUMBER
   66      | ID '=' QUOTE ID QUOTE

   67  exitsql : EXIT ';'


##############################################################################
# States
##############################################################################

state 0
	$accept : . start $end

	CREATE  shift 1
	SHOW  shift 2
	USE  shift 3
	SELECT  shift 4
	INSERT  shift 5
	UPDATE  shift 6
	DELETE  shift 7
	DROP  shift 8
	EXIT  shift 9

	createsql  goto 10
	selectsql  goto 11
	start  goto 12
	statements  goto 13
	statement  goto 14
	usesql  goto 15
	showsql  goto 16
	insertsql  goto 17
	deletesql  goto 18
	dropsql  goto 19
	updatesql  goto 20
	exitsql  goto 21


state 1
	createsql : CREATE . TABLE table '(' fieldsdefinition ')' ';'
	createsql : CREATE . DATABASE ID ';'

	DATABASE  shift 22
	TABLE  shift 23


state 2
	showsql : SHOW . DATABASES ';'
	showsql : SHOW . TABLES ';'

	DATABASES  shift 24
	TABLES  shift 25


state 3
	usesql : USE . ID ';'

	ID  shift 26


state 4
	selectsql : SELECT . fields_star FROM tables ';'
	selectsql : SELECT . fields_star FROM tables WHERE conditions ';'

	'*'  shift 27
	ID  shift 28

	table  goto 29
	field  goto 30
	fields_star  goto 31
	table_fields  goto 32
	table_field  goto 33


state 5
	insertsql : INSERT . INTO table VALUES '(' values ')' ';'
	insertsql : INSERT . INTO table '(' values ')' VALUES '(' values ')' ';'

	INTO  shift 34


state 6
	updatesql : UPDATE . table SET sets ';'
	updatesql : UPDATE . table SET sets WHERE conditions ';'

	ID  shift 35

	table  goto 36


state 7
	deletesql : DELETE . FROM table ';'
	deletesql : DELETE . FROM table WHERE conditions ';'

	FROM  shift 37


state 8
	dropsql : DROP . TABLE ID ';'
	dropsql : DROP . DATABASE ID ';'

	DATABASE  shift 38
	TABLE  shift 39


state 9
	exitsql : EXIT . ';'

	';'  shift 40


state 10
	statement : createsql .  (4)

	.  reduce 4


state 11
	statement : selectsql .  (5)

	.  reduce 5


state 12
	$accept : start . $end  (0)

	$end  accept


state 13
	start : statements .  (1)
	statements : statements . statement

	CREATE  shift 1
	SHOW  shift 2
	USE  shift 3
	SELECT  shift 4
	INSERT  shift 5
	UPDATE  shift 6
	DELETE  shift 7
	DROP  shift 8
	EXIT  shift 9
	.  reduce 1

	createsql  goto 10
	selectsql  goto 11
	statement  goto 41
	usesql  goto 15
	showsql  goto 16
	insertsql  goto 17
	deletesql  goto 18
	dropsql  goto 19
	updatesql  goto 20
	exitsql  goto 21


state 14
	statements : statement .  (3)

	.  reduce 3


state 15
	statement : usesql .  (6)

	.  reduce 6


state 16
	statement : showsql .  (7)

	.  reduce 7


state 17
	statement : insertsql .  (8)

	.  reduce 8


state 18
	statement : deletesql .  (9)

	.  reduce 9


state 19
	statement : dropsql .  (10)

	.  reduce 10


state 20
	statement : updatesql .  (11)

	.  reduce 11


state 21
	statement : exitsql .  (12)

	.  reduce 12


state 22
	createsql : CREATE DATABASE . ID ';'

	ID  shift 42


state 23
	createsql : CREATE TABLE . table '(' fieldsdefinition ')' ';'

	ID  shift 35

	table  goto 43


state 24
	showsql : SHOW DATABASES . ';'

	';'  shift 44


state 25
	showsql : SHOW TABLES . ';'

	';'  shift 45


state 26
	usesql : USE ID . ';'

	';'  shift 46


state 27
	fields_star : '*' .  (28)

	.  reduce 28


state 28
	table : ID .  (15)
	field : ID .  (19)

	'.'  reduce 15
	.  reduce 19


state 29
	table_field : table . '.' field

	'.'  shift 47


state 30
	table_field : field .  (31)

	.  reduce 31


state 31
	selectsql : SELECT fields_star . FROM tables ';'
	selectsql : SELECT fields_star . FROM tables WHERE conditions ';'

	FROM  shift 48


state 32
	fields_star : table_fields .  (27)

	.  reduce 27


state 33
	table_fields : table_field .  (29)
	table_fields : table_field . ',' table_fields

	','  shift 49
	.  reduce 29


state 34
	insertsql : INSERT INTO . table VALUES '(' values ')' ';'
	insertsql : INSERT INTO . table '(' values ')' VALUES '(' values ')' ';'

	ID  shift 35

	table  goto 50


state 35
	table : ID .  (15)

	.  reduce 15


state 36
	updatesql : UPDATE table . SET sets ';'
	updatesql : UPDATE table . SET sets WHERE conditions ';'

	SET  shift 51


state 37
	deletesql : DELETE FROM . table ';'
	deletesql : DELETE FROM . table WHERE conditions ';'

	ID  shift 35

	table  goto 52


state 38
	dropsql : DROP DATABASE . ID ';'

	ID  shift 53


state 39
	dropsql : DROP TABLE . ID ';'

	ID  shift 54


state 40
	exitsql : EXIT ';' .  (67)

	.  reduce 67


state 41
	statements : statements statement .  (2)

	.  reduce 2


state 42
	createsql : CREATE DATABASE ID . ';'

	';'  shift 55


state 43
	createsql : CREATE TABLE table . '(' fieldsdefinition ')' ';'

	'('  shift 56


state 44
	showsql : SHOW DATABASES ';' .  (23)

	.  reduce 23


state 45
	showsql : SHOW TABLES ';' .  (24)

	.  reduce 24


state 46
	usesql : USE ID ';' .  (22)

	.  reduce 22


state 47
	table_field : table '.' . field

	ID  shift 57

	field  goto 58


state 48
	selectsql : SELECT fields_star FROM . tables ';'
	selectsql : SELECT fields_star FROM . tables WHERE conditions ';'

	ID  shift 35

	table  goto 59
	tables  goto 60


state 49
	table_fields : table_field ',' . table_fields

	ID  shift 28

	table  goto 29
	field  goto 30
	table_fields  goto 61
	table_field  goto 33


state 50
	insertsql : INSERT INTO table . VALUES '(' values ')' ';'
	insertsql : INSERT INTO table . '(' values ')' VALUES '(' values ')' ';'

	'('  shift 62
	VALUES  shift 63


state 51
	updatesql : UPDATE table SET . sets ';'
	updatesql : UPDATE table SET . sets WHERE conditions ';'

	ID  shift 64

	set  goto 65
	sets  goto 66


state 52
	deletesql : DELETE FROM table . ';'
	deletesql : DELETE FROM table . WHERE conditions ';'

	';'  shift 67
	WHERE  shift 68


state 53
	dropsql : DROP DATABASE ID . ';'

	';'  shift 69


state 54
	dropsql : DROP TABLE ID . ';'

	';'  shift 70


state 55
	createsql : CREATE DATABASE ID ';' .  (14)

	.  reduce 14


state 56
	createsql : CREATE TABLE table '(' . fieldsdefinition ')' ';'

	ID  shift 57

	field  goto 71
	fieldsdefinition  goto 72
	field_type  goto 73


state 57
	field : ID .  (19)

	.  reduce 19


state 58
	table_field : table '.' field .  (32)

	.  reduce 32


state 59
	tables : table .  (33)
	tables : table . ',' tables

	','  shift 74
	.  reduce 33


state 60
	selectsql : SELECT fields_star FROM tables . ';'
	selectsql : SELECT fields_star FROM tables . WHERE conditions ';'

	';'  shift 75
	WHERE  shift 76


state 61
	table_fields : table_field ',' table_fields .  (30)

	.  reduce 30


state 62
	insertsql : INSERT INTO table '(' . values ')' VALUES '(' values ')' ';'

	QUOTE  shift 77
	ID  shift 78
	NUMBER  shift 79

	values  goto 80
	value  goto 81


state 63
	insertsql : INSERT INTO table VALUES . '(' values ')' ';'

	'('  shift 82


state 64
	set : ID . '=' NUMBER
	set : ID . '=' QUOTE ID QUOTE

	'='  shift 83


state 65
	sets : set .  (63)
	sets : set . ',' sets

	','  shift 84
	.  reduce 63


state 66
	updatesql : UPDATE table SET sets . ';'
	updatesql : UPDATE table SET sets . WHERE conditions ';'

	';'  shift 85
	WHERE  shift 86


state 67
	deletesql : DELETE FROM table ';' .  (57)

	.  reduce 57


state 68
	deletesql : DELETE FROM table WHERE . conditions ';'

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 90
	comp_left  goto 91


state 69
	dropsql : DROP DATABASE ID ';' .  (60)

	.  reduce 60


state 70
	dropsql : DROP TABLE ID ';' .  (59)

	.  reduce 59


state 71
	field_type : field . type

	CHAR  shift 92
	INT  shift 93

	type  goto 94


state 72
	createsql : CREATE TABLE table '(' fieldsdefinition . ')' ';'

	')'  shift 95


state 73
	fieldsdefinition : field_type .  (16)
	fieldsdefinition : field_type . ',' fieldsdefinition

	','  shift 96
	.  reduce 16


state 74
	tables : table ',' . tables

	ID  shift 35

	table  goto 59
	tables  goto 97


state 75
	selectsql : SELECT fields_star FROM tables ';' .  (25)

	.  reduce 25


state 76
	selectsql : SELECT fields_star FROM tables WHERE . conditions ';'

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 98
	comp_left  goto 91


state 77
	value : QUOTE . ID QUOTE
	value : QUOTE . NUMBER QUOTE

	ID  shift 99
	NUMBER  shift 100


state 78
	value : ID .  (56)

	.  reduce 56


state 79
	value : NUMBER .  (55)

	.  reduce 55


state 80
	insertsql : INSERT INTO table '(' values . ')' VALUES '(' values ')' ';'

	')'  shift 101


state 81
	values : value .  (51)
	values : value . ',' values

	','  shift 102
	.  reduce 51


state 82
	insertsql : INSERT INTO table VALUES '(' . values ')' ';'

	QUOTE  shift 77
	ID  shift 78
	NUMBER  shift 79

	values  goto 103
	value  goto 81


state 83
	set : ID '=' . NUMBER
	set : ID '=' . QUOTE ID QUOTE

	QUOTE  shift 104
	NUMBER  shift 105


state 84
	sets : set ',' . sets

	ID  shift 64

	set  goto 65
	sets  goto 106


state 85
	updatesql : UPDATE table SET sets ';' .  (61)

	.  reduce 61


state 86
	updatesql : UPDATE table SET sets WHERE . conditions ';'

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 107
	comp_left  goto 91


state 87
	conditions : '(' . conditions ')'

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 108
	comp_left  goto 91


state 88
	comp_left : table_field .  (40)

	.  reduce 40


state 89
	conditions : condition .  (35)

	.  reduce 35


state 90
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions
	deletesql : DELETE FROM table WHERE conditions . ';'

	';'  shift 109
	OR  shift 110
	AND  shift 111


state 91
	condition : comp_left . comp_op comp_right

	'!'  shift 112
	'<'  shift 113
	'='  shift 114
	'>'  shift 115

	comp_op  goto 116


state 92
	type : CHAR . '(' NUMBER ')'

	'('  shift 117


state 93
	type : INT .  (21)

	.  reduce 21


state 94
	field_type : field type .  (18)

	.  reduce 18


state 95
	createsql : CREATE TABLE table '(' fieldsdefinition ')' . ';'

	';'  shift 118


state 96
	fieldsdefinition : field_type ',' . fieldsdefinition

	ID  shift 57

	field  goto 71
	fieldsdefinition  goto 119
	field_type  goto 73


state 97
	tables : table ',' tables .  (34)

	.  reduce 34


state 98
	selectsql : SELECT fields_star FROM tables WHERE conditions . ';'
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	';'  shift 120
	OR  shift 110
	AND  shift 111


state 99
	value : QUOTE ID . QUOTE

	QUOTE  shift 121


state 100
	value : QUOTE NUMBER . QUOTE

	QUOTE  shift 122


state 101
	insertsql : INSERT INTO table '(' values ')' . VALUES '(' values ')' ';'

	VALUES  shift 123


state 102
	values : value ',' . values

	QUOTE  shift 77
	ID  shift 78
	NUMBER  shift 79

	values  goto 124
	value  goto 81


state 103
	insertsql : INSERT INTO table VALUES '(' values . ')' ';'

	')'  shift 125


state 104
	set : ID '=' QUOTE . ID QUOTE

	ID  shift 126


state 105
	set : ID '=' NUMBER .  (65)

	.  reduce 65


state 106
	sets : set ',' sets .  (64)

	.  reduce 64


state 107
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions
	updatesql : UPDATE table SET sets WHERE conditions . ';'

	';'  shift 127
	OR  shift 110
	AND  shift 111


state 108
	conditions : '(' conditions . ')'
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	')'  shift 128
	OR  shift 110
	AND  shift 111


state 109
	deletesql : DELETE FROM table WHERE conditions ';' .  (58)

	.  reduce 58


state 110
	conditions : conditions OR . conditions

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 129
	comp_left  goto 91


state 111
	conditions : conditions AND . conditions

	'('  shift 87
	ID  shift 28

	table  goto 29
	field  goto 30
	table_field  goto 88
	condition  goto 89
	conditions  goto 130
	comp_left  goto 91


state 112
	comp_op : '!' . '='

	'='  shift 131


state 113
	comp_op : '<' .  (45)

	.  reduce 45


state 114
	comp_op : '=' .  (47)

	.  reduce 47


state 115
	comp_op : '>' .  (46)

	.  reduce 46


state 116
	condition : comp_left comp_op . comp_right

	QUOTE  shift 132
	ID  shift 28
	NUMBER  shift 133

	table  goto 29
	field  goto 30
	table_field  goto 134
	comp_right  goto 135


state 117
	type : CHAR '(' . NUMBER ')'

	NUMBER  shift 136


state 118
	createsql : CREATE TABLE table '(' fieldsdefinition ')' ';' .  (13)

	.  reduce 13


state 119
	fieldsdefinition : field_type ',' fieldsdefinition .  (17)

	.  reduce 17


state 120
	selectsql : SELECT fields_star FROM tables WHERE conditions ';' .  (26)

	.  reduce 26


state 121
	value : QUOTE ID QUOTE .  (53)

	.  reduce 53


state 122
	value : QUOTE NUMBER QUOTE .  (54)

	.  reduce 54


state 123
	insertsql : INSERT INTO table '(' values ')' VALUES . '(' values ')' ';'

	'('  shift 137


state 124
	values : value ',' values .  (52)

	.  reduce 52


state 125
	insertsql : INSERT INTO table VALUES '(' values ')' . ';'

	';'  shift 138


state 126
	set : ID '=' QUOTE ID . QUOTE

	QUOTE  shift 139


state 127
	updatesql : UPDATE table SET sets WHERE conditions ';' .  (62)

	.  reduce 62


state 128
	conditions : '(' conditions ')' .  (36)

	.  reduce 36


state 129
	conditions : conditions . AND conditions
	conditions : conditions OR conditions .  (38)
	conditions : conditions . OR conditions

	AND  shift 111
	.  reduce 38


state 130
	conditions : conditions AND conditions .  (37)
	conditions : conditions . AND conditions
	conditions : conditions . OR conditions

	.  reduce 37


state 131
	comp_op : '!' '=' .  (48)

	.  reduce 48


state 132
	comp_right : QUOTE . ID QUOTE
	comp_right : QUOTE . NUMBER QUOTE

	ID  shift 140
	NUMBER  shift 141


state 133
	comp_right : NUMBER .  (42)

	.  reduce 42


state 134
	comp_right : table_field .  (41)

	.  reduce 41


state 135
	condition : comp_left comp_op comp_right .  (39)

	.  reduce 39


state 136
	type : CHAR '(' NUMBER . ')'

	')'  shift 142


state 137
	insertsql : INSERT INTO table '(' values ')' VALUES '(' . values ')' ';'

	QUOTE  shift 77
	ID  shift 78
	NUMBER  shift 79

	values  goto 143
	value  goto 81


state 138
	insertsql : INSERT INTO table VALUES '(' values ')' ';' .  (49)

	.  reduce 49


state 139
	set : ID '=' QUOTE ID QUOTE .  (66)

	.  reduce 66


state 140
	comp_right : QUOTE ID . QUOTE

	QUOTE  shift 144


state 141
	comp_right : QUOTE NUMBER . QUOTE

	QUOTE  shift 145


state 142
	type : CHAR '(' NUMBER ')' .  (20)

	.  reduce 20


state 143
	insertsql : INSERT INTO table '(' values ')' VALUES '(' values . ')' ';'

	')'  shift 146


state 144
	comp_right : QUOTE ID QUOTE .  (43)

	.  reduce 43


state 145
	comp_right : QUOTE NUMBER QUOTE .  (44)

	.  reduce 44


state 146
	insertsql : INSERT INTO table '(' values ')' VALUES '(' values ')' . ';'

	';'  shift 147


state 147
	insertsql : INSERT INTO table '(' values ')' VALUES '(' values ')' ';' .  (50)

	.  reduce 50


##############################################################################
# Summary
##############################################################################

37 token(s), 31 nonterminal(s)
68 grammar rule(s), 148 state(s)


##############################################################################
# End of File
##############################################################################
