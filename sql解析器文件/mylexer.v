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
# mylexer.v
# Lex verbose file generated from mylexer.l.
# 
# Date: 07/11/18
# Time: 14:45:40
# 
# ALex Version: 2.07
#############################################################################


#############################################################################
# Expressions
#############################################################################

    1  [ ]+

    2  [Cc][Rr][Ee][Aa][Tt][Ee]

    3  [Uu][Ss][Ee]

    4  [Ss][Hh][Oo][Ww]

    5  [Ii][Nn][Ss][Ee][Rr][Tt]

    6  [Ss][Ee][Ll][Ee][Cc][Tt]

    7  [Uu][Pp][Dd][Aa][Tt][Ee]

    8  [Ss][Ee][Tt]

    9  [Dd][Ee][Ll][Ee][Tt][Ee]

   10  [Dd][Rr][Oo][Pp]

   11  [Ii][Nn][Tt][Oo]

   12  [Vv][Aa][Ll][Uu][Ee][Ss]

   13  [Ff][Rr][Oo][Mm]

   14  [Ww][Hh][Ee][Rr][Ee]

   15  [Aa][Nn][Dd]

   16  [Oo][Rr]

   17  [Ee][Xx][Ii][Tt]

   18  [Tt][Aa][Bb][Ll][Ee]

   19  [Tt][Aa][Bb][Ll][Ee][Ss]

   20  [Dd][Aa][Tt][Aa][Bb][Aa][Ss][Ee]

   21  [Dd][Aa][Tt][Aa][Bb][Aa][Ss][Ee][Ss]

   22  [Cc][Hh][Aa][Rr]

   23  [Ii][Nn][Tt]

   24  [A-Za-z][A-Za-z0-9_]*

   25  [0-9]+("."[0-9]+)?(E[+-]?[0-9]+)?

   26  ";"

   27  "("

   28  ")"

   29  ","

   30  "."

   31  "!"

   32  "="

   33  "<"

   34  ">"

   35  "'"

   36  "+"

   37  "-"

   38  "*"

   39  "/"

   40  "\n"


#############################################################################
# States
#############################################################################

state 1
	INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2e               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41               goto 20
	0x42               goto 21
	0x43               goto 22
	0x44               goto 23
	0x45               goto 24
	0x46               goto 25
	0x47 - 0x48 (2)    goto 21
	0x49               goto 26
	0x4a - 0x4e (5)    goto 21
	0x4f               goto 27
	0x50 - 0x52 (3)    goto 21
	0x53               goto 28
	0x54               goto 29
	0x55               goto 30
	0x56               goto 31
	0x57               goto 32
	0x58 - 0x5a (3)    goto 21
	0x61               goto 20
	0x62               goto 21
	0x63               goto 22
	0x64               goto 23
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 21
	0x69               goto 26
	0x6a - 0x6e (5)    goto 21
	0x6f               goto 27
	0x70 - 0x72 (3)    goto 21
	0x73               goto 28
	0x74               goto 29
	0x75               goto 30
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 21


state 2
	^INITIAL

	0x0a               goto 3
	0x20               goto 4
	0x21               goto 5
	0x27               goto 6
	0x28               goto 7
	0x29               goto 8
	0x2a               goto 9
	0x2b               goto 10
	0x2c               goto 11
	0x2d               goto 12
	0x2e               goto 13
	0x2f               goto 14
	0x30 - 0x39 (10)   goto 15
	0x3b               goto 16
	0x3c               goto 17
	0x3d               goto 18
	0x3e               goto 19
	0x41               goto 20
	0x42               goto 21
	0x43               goto 22
	0x44               goto 23
	0x45               goto 24
	0x46               goto 25
	0x47 - 0x48 (2)    goto 21
	0x49               goto 26
	0x4a - 0x4e (5)    goto 21
	0x4f               goto 27
	0x50 - 0x52 (3)    goto 21
	0x53               goto 28
	0x54               goto 29
	0x55               goto 30
	0x56               goto 31
	0x57               goto 32
	0x58 - 0x5a (3)    goto 21
	0x61               goto 20
	0x62               goto 21
	0x63               goto 22
	0x64               goto 23
	0x65               goto 24
	0x66               goto 25
	0x67 - 0x68 (2)    goto 21
	0x69               goto 26
	0x6a - 0x6e (5)    goto 21
	0x6f               goto 27
	0x70 - 0x72 (3)    goto 21
	0x73               goto 28
	0x74               goto 29
	0x75               goto 30
	0x76               goto 31
	0x77               goto 32
	0x78 - 0x7a (3)    goto 21


state 3
	match 40


state 4
	0x20               goto 4

	match 1


state 5
	match 31


state 6
	match 35


state 7
	match 27


state 8
	match 28


state 9
	match 38


state 10
	match 36


state 11
	match 29


state 12
	match 37


state 13
	match 30


state 14
	match 39


state 15
	0x2e               goto 33
	0x30 - 0x39 (10)   goto 15
	0x45               goto 34

	match 25


state 16
	match 26


state 17
	match 33


state 18
	match 32


state 19
	match 34


state 20
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4d (13)   goto 21
	0x4e               goto 35
	0x4f - 0x5a (12)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 35
	0x6f - 0x7a (12)   goto 21

	match 24


state 21
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 24


state 22
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x47 (7)    goto 21
	0x48               goto 36
	0x49 - 0x51 (9)    goto 21
	0x52               goto 37
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 36
	0x69 - 0x71 (9)    goto 21
	0x72               goto 37
	0x73 - 0x7a (8)    goto 21

	match 24


state 23
	0x30 - 0x39 (10)   goto 21
	0x41               goto 38
	0x42 - 0x44 (3)    goto 21
	0x45               goto 39
	0x46 - 0x51 (12)   goto 21
	0x52               goto 40
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61               goto 38
	0x62 - 0x64 (3)    goto 21
	0x65               goto 39
	0x66 - 0x71 (12)   goto 21
	0x72               goto 40
	0x73 - 0x7a (8)    goto 21

	match 24


state 24
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x57 (23)   goto 21
	0x58               goto 41
	0x59 - 0x5a (2)    goto 21
	0x5f               goto 21
	0x61 - 0x77 (23)   goto 21
	0x78               goto 41
	0x79 - 0x7a (2)    goto 21

	match 24


state 25
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x51 (17)   goto 21
	0x52               goto 42
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 42
	0x73 - 0x7a (8)    goto 21

	match 24


state 26
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4d (13)   goto 21
	0x4e               goto 43
	0x4f - 0x5a (12)   goto 21
	0x5f               goto 21
	0x61 - 0x6d (13)   goto 21
	0x6e               goto 43
	0x6f - 0x7a (12)   goto 21

	match 24


state 27
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x51 (17)   goto 21
	0x52               goto 44
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 44
	0x73 - 0x7a (8)    goto 21

	match 24


state 28
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 45
	0x46 - 0x47 (2)    goto 21
	0x48               goto 46
	0x49 - 0x5a (18)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 45
	0x66 - 0x67 (2)    goto 21
	0x68               goto 46
	0x69 - 0x7a (18)   goto 21

	match 24


state 29
	0x30 - 0x39 (10)   goto 21
	0x41               goto 47
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 47
	0x62 - 0x7a (25)   goto 21

	match 24


state 30
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4f (15)   goto 21
	0x50               goto 48
	0x51 - 0x52 (2)    goto 21
	0x53               goto 49
	0x54 - 0x5a (7)    goto 21
	0x5f               goto 21
	0x61 - 0x6f (15)   goto 21
	0x70               goto 48
	0x71 - 0x72 (2)    goto 21
	0x73               goto 49
	0x74 - 0x7a (7)    goto 21

	match 24


state 31
	0x30 - 0x39 (10)   goto 21
	0x41               goto 50
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 50
	0x62 - 0x7a (25)   goto 21

	match 24


state 32
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x47 (7)    goto 21
	0x48               goto 51
	0x49 - 0x5a (18)   goto 21
	0x5f               goto 21
	0x61 - 0x67 (7)    goto 21
	0x68               goto 51
	0x69 - 0x7a (18)   goto 21

	match 24


state 33
	0x30 - 0x39 (10)   goto 52


state 34
	0x2b               goto 53
	0x2d               goto 53
	0x30 - 0x39 (10)   goto 54


state 35
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x43 (3)    goto 21
	0x44               goto 55
	0x45 - 0x5a (22)   goto 21
	0x5f               goto 21
	0x61 - 0x63 (3)    goto 21
	0x64               goto 55
	0x65 - 0x7a (22)   goto 21

	match 24


state 36
	0x30 - 0x39 (10)   goto 21
	0x41               goto 56
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 56
	0x62 - 0x7a (25)   goto 21

	match 24


state 37
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 57
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 57
	0x66 - 0x7a (21)   goto 21

	match 24


state 38
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 58
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 58
	0x75 - 0x7a (6)    goto 21

	match 24


state 39
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4b (11)   goto 21
	0x4c               goto 59
	0x4d - 0x5a (14)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 59
	0x6d - 0x7a (14)   goto 21

	match 24


state 40
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4e (14)   goto 21
	0x4f               goto 60
	0x50 - 0x5a (11)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 60
	0x70 - 0x7a (11)   goto 21

	match 24


state 41
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x48 (8)    goto 21
	0x49               goto 61
	0x4a - 0x5a (17)   goto 21
	0x5f               goto 21
	0x61 - 0x68 (8)    goto 21
	0x69               goto 61
	0x6a - 0x7a (17)   goto 21

	match 24


state 42
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4e (14)   goto 21
	0x4f               goto 62
	0x50 - 0x5a (11)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 62
	0x70 - 0x7a (11)   goto 21

	match 24


state 43
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x52 (18)   goto 21
	0x53               goto 63
	0x54               goto 64
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 63
	0x74               goto 64
	0x75 - 0x7a (6)    goto 21

	match 24


state 44
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 16


state 45
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4b (11)   goto 21
	0x4c               goto 65
	0x4d - 0x53 (7)    goto 21
	0x54               goto 66
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 65
	0x6d - 0x73 (7)    goto 21
	0x74               goto 66
	0x75 - 0x7a (6)    goto 21

	match 24


state 46
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4e (14)   goto 21
	0x4f               goto 67
	0x50 - 0x5a (11)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 67
	0x70 - 0x7a (11)   goto 21

	match 24


state 47
	0x30 - 0x39 (10)   goto 21
	0x41               goto 21
	0x42               goto 68
	0x43 - 0x5a (24)   goto 21
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 68
	0x63 - 0x7a (24)   goto 21

	match 24


state 48
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x43 (3)    goto 21
	0x44               goto 69
	0x45 - 0x5a (22)   goto 21
	0x5f               goto 21
	0x61 - 0x63 (3)    goto 21
	0x64               goto 69
	0x65 - 0x7a (22)   goto 21

	match 24


state 49
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 70
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 70
	0x66 - 0x7a (21)   goto 21

	match 24


state 50
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4b (11)   goto 21
	0x4c               goto 71
	0x4d - 0x5a (14)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 71
	0x6d - 0x7a (14)   goto 21

	match 24


state 51
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 72
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 72
	0x66 - 0x7a (21)   goto 21

	match 24


state 52
	0x30 - 0x39 (10)   goto 52
	0x45               goto 34

	match 25


state 53
	0x30 - 0x39 (10)   goto 54


state 54
	0x30 - 0x39 (10)   goto 54

	match 25


state 55
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 15


state 56
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x51 (17)   goto 21
	0x52               goto 73
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 73
	0x73 - 0x7a (8)    goto 21

	match 24


state 57
	0x30 - 0x39 (10)   goto 21
	0x41               goto 74
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 74
	0x62 - 0x7a (25)   goto 21

	match 24


state 58
	0x30 - 0x39 (10)   goto 21
	0x41               goto 75
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 75
	0x62 - 0x7a (25)   goto 21

	match 24


state 59
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 76
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 76
	0x66 - 0x7a (21)   goto 21

	match 24


state 60
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4f (15)   goto 21
	0x50               goto 77
	0x51 - 0x5a (10)   goto 21
	0x5f               goto 21
	0x61 - 0x6f (15)   goto 21
	0x70               goto 77
	0x71 - 0x7a (10)   goto 21

	match 24


state 61
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 78
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 78
	0x75 - 0x7a (6)    goto 21

	match 24


state 62
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4c (12)   goto 21
	0x4d               goto 79
	0x4e - 0x5a (13)   goto 21
	0x5f               goto 21
	0x61 - 0x6c (12)   goto 21
	0x6d               goto 79
	0x6e - 0x7a (13)   goto 21

	match 24


state 63
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 80
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 80
	0x66 - 0x7a (21)   goto 21

	match 24


state 64
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4e (14)   goto 21
	0x4f               goto 81
	0x50 - 0x5a (11)   goto 21
	0x5f               goto 21
	0x61 - 0x6e (14)   goto 21
	0x6f               goto 81
	0x70 - 0x7a (11)   goto 21

	match 23


state 65
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 82
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 82
	0x66 - 0x7a (21)   goto 21

	match 24


state 66
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 8


state 67
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x56 (22)   goto 21
	0x57               goto 83
	0x58 - 0x5a (3)    goto 21
	0x5f               goto 21
	0x61 - 0x76 (22)   goto 21
	0x77               goto 83
	0x78 - 0x7a (3)    goto 21

	match 24


state 68
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x4b (11)   goto 21
	0x4c               goto 84
	0x4d - 0x5a (14)   goto 21
	0x5f               goto 21
	0x61 - 0x6b (11)   goto 21
	0x6c               goto 84
	0x6d - 0x7a (14)   goto 21

	match 24


state 69
	0x30 - 0x39 (10)   goto 21
	0x41               goto 85
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 85
	0x62 - 0x7a (25)   goto 21

	match 24


state 70
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 3


state 71
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x54 (20)   goto 21
	0x55               goto 86
	0x56 - 0x5a (5)    goto 21
	0x5f               goto 21
	0x61 - 0x74 (20)   goto 21
	0x75               goto 86
	0x76 - 0x7a (5)    goto 21

	match 24


state 72
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x51 (17)   goto 21
	0x52               goto 87
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 87
	0x73 - 0x7a (8)    goto 21

	match 24


state 73
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 22


state 74
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 88
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 88
	0x75 - 0x7a (6)    goto 21

	match 24


state 75
	0x30 - 0x39 (10)   goto 21
	0x41               goto 21
	0x42               goto 89
	0x43 - 0x5a (24)   goto 21
	0x5f               goto 21
	0x61               goto 21
	0x62               goto 89
	0x63 - 0x7a (24)   goto 21

	match 24


state 76
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 90
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 90
	0x75 - 0x7a (6)    goto 21

	match 24


state 77
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 10


state 78
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 17


state 79
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 13


state 80
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x51 (17)   goto 21
	0x52               goto 91
	0x53 - 0x5a (8)    goto 21
	0x5f               goto 21
	0x61 - 0x71 (17)   goto 21
	0x72               goto 91
	0x73 - 0x7a (8)    goto 21

	match 24


state 81
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 11


state 82
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x42 (2)    goto 21
	0x43               goto 92
	0x44 - 0x5a (23)   goto 21
	0x5f               goto 21
	0x61 - 0x62 (2)    goto 21
	0x63               goto 92
	0x64 - 0x7a (23)   goto 21

	match 24


state 83
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 4


state 84
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 93
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 93
	0x66 - 0x7a (21)   goto 21

	match 24


state 85
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 94
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 94
	0x75 - 0x7a (6)    goto 21

	match 24


state 86
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 95
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 95
	0x66 - 0x7a (21)   goto 21

	match 24


state 87
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 96
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 96
	0x66 - 0x7a (21)   goto 21

	match 24


state 88
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 97
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 97
	0x66 - 0x7a (21)   goto 21

	match 24


state 89
	0x30 - 0x39 (10)   goto 21
	0x41               goto 98
	0x42 - 0x5a (25)   goto 21
	0x5f               goto 21
	0x61               goto 98
	0x62 - 0x7a (25)   goto 21

	match 24


state 90
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 99
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 99
	0x66 - 0x7a (21)   goto 21

	match 24


state 91
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 100
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 100
	0x75 - 0x7a (6)    goto 21

	match 24


state 92
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x53 (19)   goto 21
	0x54               goto 101
	0x55 - 0x5a (6)    goto 21
	0x5f               goto 21
	0x61 - 0x73 (19)   goto 21
	0x74               goto 101
	0x75 - 0x7a (6)    goto 21

	match 24


state 93
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x52 (18)   goto 21
	0x53               goto 102
	0x54 - 0x5a (7)    goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 102
	0x74 - 0x7a (7)    goto 21

	match 18


state 94
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 103
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 103
	0x66 - 0x7a (21)   goto 21

	match 24


state 95
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x52 (18)   goto 21
	0x53               goto 104
	0x54 - 0x5a (7)    goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 104
	0x74 - 0x7a (7)    goto 21

	match 24


state 96
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 14


state 97
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 2


state 98
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x52 (18)   goto 21
	0x53               goto 105
	0x54 - 0x5a (7)    goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 105
	0x74 - 0x7a (7)    goto 21

	match 24


state 99
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 9


state 100
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 5


state 101
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 6


state 102
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 19


state 103
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 7


state 104
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 12


state 105
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x44 (4)    goto 21
	0x45               goto 106
	0x46 - 0x5a (21)   goto 21
	0x5f               goto 21
	0x61 - 0x64 (4)    goto 21
	0x65               goto 106
	0x66 - 0x7a (21)   goto 21

	match 24


state 106
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x52 (18)   goto 21
	0x53               goto 107
	0x54 - 0x5a (7)    goto 21
	0x5f               goto 21
	0x61 - 0x72 (18)   goto 21
	0x73               goto 107
	0x74 - 0x7a (7)    goto 21

	match 20


state 107
	0x30 - 0x39 (10)   goto 21
	0x41 - 0x5a (26)   goto 21
	0x5f               goto 21
	0x61 - 0x7a (26)   goto 21

	match 21


#############################################################################
# Summary
#############################################################################

1 start state(s)
40 expression(s), 107 state(s)


#############################################################################
# End of File
#############################################################################
