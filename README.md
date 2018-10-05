# LogisticsSystem

# 实验项目名称： 

1、最优物流路线计算实验 

2、多进程多用户文件一致性读写访问设计实现

3、SQL解析器设计实现

4、互联网+智慧物流质询系统设计实现

# 实验原理：

1、数据结构的线性数据结构、树数据结构、图数据结构的运用。

2、利用操作系统中进程并行，互斥和生产消费者问题实现对文件的数据写入和查询访问。

3、词法、语法分析和语义分析知识；运用语法和语义分析知识实现简单SQL解析器

4、综合实验1,2,3的知识，设计实现整体的软件系统

# 实验内容：

## 1、给定物流节点信息，物品信息，节点间代价计算方法要求学生完成以下实验内容。

(1) 根据物品信息综合计算物流物品的优先级别，根据物流优先级别排序物流物品，根据排序结果对物流物品进行逐个发货。

(2) 根据物流物品的物流条件信息，归类物流物品到物流方案类型，物流方案类型可包括：价格最小物流方案，时间最短物流方案、综合最优方案、航空物流方案等。并运用树型结构存储所有的物流物品到划分的物流方案中。

(3) 根据给定的物流节点信息，计算各类物流方案下的物流最短路径

(4) 根据物流最短路径，物流方案和物流优先级发送货物

## 2、实现多用户多进程环境下文件中数据记录的读写、查询操作。主要实验内容如下。

(1)编程实现文件中记录数据的存储、读写和记录的简单查询与索引查询函数。能够实现单用户和进行对文件数据的写入与查询。

(2)设计实现数据表的文件存储方式，能在文件中存储多张数据表，并写入和查询指定  数据表中的记录。

(3)实现多进程对文件记录的互斥写入与查询访问，保证记录数据的一致性。

(4)基于锁机制保障多用户对文件中记录数据的写如与查询一致性操作。

## 3、SQL语句的解析的设计。SQL解释器的实质为制定相关文法规则，对用户输入字符串进行语法语义分析，进而采用相应的操作。本实验要求实现部分SQL语句的功能，包括Select语句，Insert语句和Update，创建表语句的解析并对接实验2中对应的创建表、写入和查询函数实现数据表创建、写入和查询操作。

(1)	构建词法、语法及语义分析程序实现部分SQL语句的解析，包括Select语句， Insert语句和Update语句，创建表语句的解析。

(2)	构建相应的语义子程序。 

(3)	将语义子程序对接底层实验2中所实现的各个数据操作函数，实现增删查改等数据库功能。

## 4、实现智慧物流质询系统，系统具体要求如下。

(1)结合实验3,2构建物流节点信息表，实现物流节点信息的数据库存储

(2)	结合实验3,2，构建物品信息表，实现物品信息的存储

(3)	结合实验3以SQL语句，对物流节点信息进行增删改查

(4)	结合实验3以SQL语句，对物品信息进行增删改查

(5)	结合实验1，实现物品的优先级排序和物流方案分类

(6)	节点信息会动态变化，因此结合实验1，每个物品需要动态计算物流最短路径的实现。

（7）模拟物品的物流状态，用户可以对物件的物流状态进行查询。

# 说明：

sql.exe是SQL解释器

system.py是主系统文件

这两个必须存在 放在同一个路径下

运行时只要运行system.py

如果sql文件夹不存在，会在第一次运行系统时创建，以及自动生成里面的文件

系统是综合了各实验功能的

在系统中按“7”启动了sql.exe进程后会阻塞其它进程

查询（读操作）不阻塞，可以并行
