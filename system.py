import os
import numpy
import psutil
import random


# 功能：创建文件，随机生成物品和节点数据信息
# 在程序运行最开始被调用，如果目录下对应文件不存在就会创建
def createFile():
    if (os.path.exists("sql") == False):
        os.mkdir("sql")  # 创建名为sql的文件夹
    if (os.path.exists(os.getcwd() + "\\sql\\database.dat") == False):
        with open(os.getcwd() + "\\sql\\database.dat", "w+") as fp:
            fp.write("test\n")  # 创建名为database.dat的数据库记录文件，记录数据库信息test
    if (os.path.exists(os.getcwd() + "\\sql\\test") == False):
        os.mkdir(os.getcwd() + "\\sql\\test")  # 创建sql文件夹下名为test的文件夹
    if (os.path.exists(os.getcwd() + "\\sql\\test\\tables.dat") == False):
        with open(os.getcwd() + "\\sql\\test\\tables.dat", "w+") as fp:  # 创建名为tables.dat的表记录文件，记录表信息items和nodes
            fp.write("nodes\tnode\tINT 4\n")
            for i in range(7):
                fp.write("nodes\tdistance" + str(i + 1) + "\t" + "INT 4\n")
            fp.write("items Id INT 4\n")
            fp.write("items Price INT 4\n")
            fp.write("items Fresh INT 4\n")
            fp.write("items Time INT 4\n")
            fp.write("items VIP INT 4\n")
            fp.write("items Weight INT 4\n")
            fp.write("items Start INT 4\n")
            fp.write("items End INT 4\n")
            fp.write("items Status INT 4\n")
    if (os.path.exists(os.getcwd() + "\\sql\\test\\items.txt") == False):
        with open(os.getcwd() + "\\sql\\test\\items.txt", "w+") as fp:  # 创建items表，随机生成一些数据写入
            fp.write("9\n")
            fp.write("Id\tPrice\tFresh\tTime\tVIP\tWeight\tStart\tEnd\tStatus\n")
            for i in range(10):
                fp.write(
                    str(i + 1) + "\t" + str(random.randint(1, 100)) + "\t" + str(random.randint(0, 1)) + "\t" + str(
                        random.randint(8, 72)) + "\t" + str(random.randint(0, 1)) + "\t" + str(
                        random.randint(1, 100)) + "\t" + str(
                        random.randint(1, 7)) + "\t" + str(random.randint(1, 7)) + "\t" + str(
                        random.randint(1, 3)) + "\n")
    if (os.path.exists(os.getcwd() + "\\sql\\test\\nodes.txt") == False):
        with open(os.getcwd() + "\\sql\\test\\nodes.txt", "w+") as fp:  # 创建nodes表，随机生成一些数据写入
            fp.write("8\n")
            fp.write("node\tdistance1\tdistance2\tdistance3\tdistance4\tdistance5\tdistance6\tdistance7\n")
            for i in range(7):
                fp.write(str(i + 1) + "\t")
                for j in range(7):
                    fp.write(str(0 if i == j else random.randint(50, 500)) + "\t")
                fp.write("\n")


# 功能:读取nodes表文件，将节点信息用int类型矩阵存储并返回
def getNodesMatrix():
    nodesMatrix = numpy.loadtxt(os.getcwd() + "\\sql\\test\\nodes.txt", dtype=int,
                                skiprows=2)
    return nodesMatrix


# 功能:读取nodes表文件，将距离信息用int类型矩阵存储，使矩阵对称化并返回
def getDistanceMatrix():
    distanceMatrix = numpy.loadtxt(os.getcwd() + "\\sql\\test\\nodes.txt",
                                   dtype=int, skiprows=2, usecols=(1, 2, 3, 4, 5, 6, 7))
    for i in range(7):
        for j in range(7):
            distanceMatrix[i][j] = distanceMatrix[j][i]  # 将距离矩阵对称化
    return distanceMatrix


# 功能:读取items表文件，将节点信息用int类型矩阵存储，计算综合权重并返回
def getItemsMatrix():
    itemsMatrix = numpy.loadtxt(os.getcwd() + "\\sql\\test\\items.txt", dtype=int,
                                skiprows=2)
    for i in range(len(itemsMatrix)):
        itemsMatrix[i][5] = itemsMatrix[i][2] * 2000 + itemsMatrix[i][4] * 1000 - itemsMatrix[i][
            3] * 5 - itemsMatrix[i][1] * 2  # 每个物品计算出综合权重
    return itemsMatrix


# 将计算完权重的items表重新写到文件items.txt中
def updateItemsFile(file, itemsMatrix):
    with open(file, "w+") as fp:
        fp.write("9\n")
        fp.write("Id\tPrice\tFresh\tTime\tVIP\tWeight\tStart\tEnd\tStatus\n")
        for i in range(len(itemsMatrix)):
            fp.write(
                str(itemsMatrix[i][0]) + "\t" + str(itemsMatrix[i][1]) + "\t" + str(
                    itemsMatrix[i][2]) + "\t" + str(
                    itemsMatrix[i][3]) + "\t" + str(itemsMatrix[i][4]) + "\t" + str(
                    itemsMatrix[i][5]) + "\t" + str(
                    itemsMatrix[i][6]) + "\t" + str(itemsMatrix[i][7]) + "\t" + str(
                    itemsMatrix[i][8]) + "\n")


# 将距离节点信息对称化的nodes表重新写到文件nodes.txt中
def updateNodesMatrixFile(file, distanceMatrix):
    with open(file, "w+") as fp:
        fp.write("8\n")
        fp.write("node\tdistance1\tdistance2\tdistance3\tdistance4\tdistance5\tdistance6\tdistance7\n")
        for i in range(7):
            fp.write(str(i + 1) + "\t")
            for j in range(7):
                fp.write(str(distanceMatrix[i][j]) + "\t")
            fp.write("\n")


# 按时间从小到大排序并输出
def timeSort(itemsMatrix):
    timeArray = numpy.loadtxt(os.getcwd() + "\\sql\\test\\items.txt", dtype=int,
                              skiprows=2, usecols=3)
    timeArray = sorted(timeArray)  # 按时间从小到大排序
    for j in range(len(timeArray)):  # 匹配对应物品并输出
        for i in range(len(itemsMatrix)):
            if (itemsMatrix[i][3] == timeArray[j]):
                print("ID：" + str(itemsMatrix[i][0]) + "\t" + "Price：" + str(
                    itemsMatrix[i][1]) + "\t" + "Fresh：" + str(
                    itemsMatrix[i][2]) + "\t" + "Time：" + str(itemsMatrix[i][3]) + "\t" + "VIP：" + str(
                    itemsMatrix[i][4]) + "\t" + "Weight：" + str(
                    itemsMatrix[i][5]) + "\t" + "Start：" + str(
                    itemsMatrix[i][6]) + "\t" + "End：" + str(
                    itemsMatrix[i][7]) + "\t" + "Status：" + str(
                    itemsMatrix[i][8]))
                showPath(path, itemsMatrix[i][6], itemsMatrix[i][7])
                if (itemsMatrix[i][8] == 1):
                    print("状态：未发送")
                elif (itemsMatrix[i][8] == 2):
                    print("状态：发送中")
                elif (itemsMatrix[i][8] == 3):
                    print("状态：已送达")


# 按费用从低到高排序并输出
def priceSort(itemsMatrix):
    priceArray = numpy.loadtxt(os.getcwd() + "\\sql\\test\\items.txt", dtype=int,
                               skiprows=2, usecols=1)
    priceArray = sorted(priceArray)  # 按费用从低到高排序
    for j in range(len(priceArray)):  # 匹配对应物品并输出
        for i in range(len(itemsMatrix)):
            if (itemsMatrix[i][1] == priceArray[j]):
                print("ID：" + str(itemsMatrix[i][0]) + "\t" + "Price：" + str(
                    itemsMatrix[i][1]) + "\t" + "Fresh：" + str(
                    itemsMatrix[i][2]) + "\t" + "Time：" + str(itemsMatrix[i][3]) + "\t" + "VIP：" + str(
                    itemsMatrix[i][4]) + "\t" + "Weight：" + str(
                    itemsMatrix[i][5]) + "\t" + "Start：" + str(
                    itemsMatrix[i][6]) + "\t" + "End：" + str(
                    itemsMatrix[i][7]) + "\t" + "Status：" + str(
                    itemsMatrix[i][8]))
                showPath(path, itemsMatrix[i][6], itemsMatrix[i][7])
                if (itemsMatrix[i][8] == 1):
                    print("状态：未发送")
                elif (itemsMatrix[i][8] == 2):
                    print("状态：发送中")
                elif (itemsMatrix[i][8] == 3):
                    print("状态：已送达")


# 按综合权重从高到低排序并输出
def weightSort(itemsMatrix):
    weightArray = numpy.loadtxt(os.getcwd() + "\\sql\\test\\items.txt", dtype=int,
                                skiprows=2, usecols=5)
    weightArray = sorted(weightArray, reverse=True)  # 按综合权重从高到低排序
    for j in range(len(weightArray)):  # 匹配对应物品并输出
        for i in range(len(itemsMatrix)):
            if (itemsMatrix[i][5] == weightArray[j]):
                print("ID：" + str(itemsMatrix[i][0]) + "\t" + "Price：" + str(
                    itemsMatrix[i][1]) + "\t" + "Fresh：" + str(
                    itemsMatrix[i][2]) + "\t" + "Time：" + str(itemsMatrix[i][3]) + "\t" + "VIP：" + str(
                    itemsMatrix[i][4]) + "\t" + "Weight：" + str(
                    itemsMatrix[i][5]) + "\t" + "Start：" + str(
                    itemsMatrix[i][6]) + "\t" + "End：" + str(
                    itemsMatrix[i][7]) + "\t" + "Status：" + str(
                    itemsMatrix[i][8]))
                showPath(path, itemsMatrix[i][6], itemsMatrix[i][7])
                if (itemsMatrix[i][8] == 1):
                    print("状态：未发送")
                elif (itemsMatrix[i][8] == 2):
                    print("状态：发送中")
                elif (itemsMatrix[i][8] == 3):
                    print("状态：已送达")


# 弗洛伊德算法：计算全源最短路径并用矩阵形式存储
def floyd(distanceMatrix):
    temp = numpy.zeros((7, 7))  # 7*7的矩阵用于临时存储和计算
    path = numpy.zeros((7, 7))  # 设置了7个节点

    # 弗洛伊德算法
    for i in range(7):
        for j in range(7):
            temp[i][j] = distanceMatrix[i][j]
            if (i != j and distanceMatrix[i][j] < 1000):
                path[i][j] = i
            else:
                path[i][j] = -1

    for k in range(7):
        for i in range(7):
            for j in range(7):
                if (temp[i][j] > temp[i][k] + temp[k][j]):
                    temp[i][j] = temp[i][k] + temp[k][j]
                    path[i][j] = path[k][j]
    return path


# 输出最短路径节点信息
def showPath(path, from_s, to):
    if (from_s == 1):
        from_ = 1
    elif (from_s == 2):
        from_ = 2
    elif (from_s == 3):
        from_ = 3
    elif (from_s == 4):
        from_ = 4
    elif (from_s == 5):
        from_ = 5
    elif (from_s == 6):
        from_ = 6
    else:
        from_ = 7
    if (to == 1):
        to_ = 1
    elif (to == 2):
        to_ = 2
    elif (to == 3):
        to_ = 3
    elif (to == 4):
        to_ = 4
    elif (to == 5):
        to_ = 5
    elif (to == 6):
        to_ = 6
    else:
        to_ = 7
    if (to_ > 7 or to_ < 1 or from_ > 7 or from_ < 1):
        print("您输入的节点不存在！")
    t = from_ - 1
    f = to_ - 1
    if (t == f):
        print("出发点不能与终点相同")
        return
    print("距离最短的路径为：", end="")
    print(from_, end=" ")
    print("--->", end="")
    path.reshape(7, 7).dtype = int
    while (path[f][t] != f):
        print(chr(int(path[f][t] + ord('1'))), end="")
        print("--->", end="")
        t = int(path[f][t])

    print(to_)


# 功能：检查进程，检测系统中是否有sql.exe进程正在运行
# 若有sql.exe进程，返回True，若没有，返回False
def checkProcess():
    flag = False
    for proc in psutil.process_iter(attrs=['pid', 'name']):
        if (proc.name() == "sql.exe"):
            flag = True
    return flag


if __name__ == '__main__':
    createFile()  # 如果对应文件不存在先创建
    while (True):
        flag = checkProcess()
        if (flag == False):
            choice = input("\n请选择功能：1：查看所有物品 2：查看所有节点 3：航空物流方案 4：时间排序 5：价格排序 6：综合权重排序（降序） 7：SQL输入 8：退出系统\n")
            itemsMatrix = getItemsMatrix()  # 得到物品矩阵
            distanceMatrix = getDistanceMatrix()  # 得到距离矩阵
            path = floyd(distanceMatrix)  # 调用弗洛伊德算法求全源最短路径
            updateItemsFile(os.getcwd() + "\\sql\\test\\items.txt", itemsMatrix)  # 将计算完权重的items表重新写入文件
            updateNodesMatrixFile(os.getcwd() + "\\sql\\test\\nodes.txt", distanceMatrix)  # 将对称化的nodes表重新写入文件
            nodeMatrix = getNodesMatrix()  # 得到节点信息矩阵
            distanceMatrix = getDistanceMatrix()  # 得到距离矩阵
            itemsMatrix = getItemsMatrix()  # 得到物品矩阵
            if (int(choice) == 1):
                flag = checkProcess()
                if (flag == False):
                    for i in range(len(itemsMatrix)):
                        print("ID：" + str(itemsMatrix[i][0]) + "\t" + "Price：" + str(
                            itemsMatrix[i][1]) + "\t" + "Fresh：" + str(
                            itemsMatrix[i][2]) + "\t" + "Time：" + str(itemsMatrix[i][3]) + "\t" + "VIP：" + str(
                            itemsMatrix[i][4]) + "\t" + "Weight：" + str(
                            itemsMatrix[i][5]) + "\t" + "Start：" + str(
                            itemsMatrix[i][6]) + "\t" + "End：" + str(
                            itemsMatrix[i][7]) + "\t" + "Status：" + str(
                            itemsMatrix[i][8]))
                        showPath(path, itemsMatrix[i][6], itemsMatrix[i][7])
                        if (itemsMatrix[i][8] == 1):
                            print("状态：未发送")
                        elif (itemsMatrix[i][8] == 2):
                            print("状态：发送中")
                        elif (itemsMatrix[i][8] == 3):
                            print("状态：已送达")
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 2):
                flag = checkProcess()
                if (flag == False):
                    for i in range(len(nodeMatrix)):
                        print("Node：" + str(nodeMatrix[i][0]) + "\t" + "Distance1：" + str(
                            nodeMatrix[i][1]) + "\t" + "Distance2：" + str(
                            nodeMatrix[i][2]) + "\t" + "Distance3：" + str(
                            nodeMatrix[i][3]) + "\t" + "Distance4：" + str(
                            nodeMatrix[i][4]) + "\t" + "Distance5：" + str(
                            nodeMatrix[i][5]) + "\t" + "Distance6：" + str(
                            nodeMatrix[i][6]) + "\t" + "Distance7：" + str(
                            nodeMatrix[i][7]) + "\n")
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 3):
                flag = checkProcess()
                if (flag == False):
                    print("对生鲜物品要采用航空运输：")
                    for i in range(len(itemsMatrix)):
                        if (int(itemsMatrix[i][2]) == 1):
                            print("ID：" + str(itemsMatrix[i][0]) + "\t" + "Price：" + str(
                                itemsMatrix[i][1]) + "\t" + "Fresh：" + str(
                                itemsMatrix[i][2]) + "\t" + "Time：" + str(
                                itemsMatrix[i][3]) + "\t" + "VIP：" + str(
                                itemsMatrix[i][4]) + "\t" + "Weight：" + str(
                                itemsMatrix[i][5]) + "\t" + "Start：" + str(
                                itemsMatrix[i][6]) + "\t" + "End：" + str(itemsMatrix[i][7]))
                            print("航空直达：" + str(itemsMatrix[i][6]) + "→" + str(itemsMatrix[i][7]))
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 4):
                flag = checkProcess()
                if (flag == False):
                    print("按时间排序：\n")
                    timeSort(itemsMatrix)
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 5):
                flag = checkProcess()
                if (flag == False):
                    print("按价格排序：\n")
                    priceSort(itemsMatrix)
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 6):
                flag = checkProcess()
                if (flag == False):
                    print("按综合权重降序排序：")
                    weightSort(itemsMatrix)
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 7):
                flag = checkProcess()
                if (flag == False):
                    os.system(os.getcwd() + "\\sql.exe")
                else:
                    print("检测到有sql.exe进程正在操作，请等待！")
                    continue
            elif (int(choice) == 8):
                print("欢迎下次使用！再见！")
                break
            else:
                continue
        else:
            print("检测到有sql.exe进程正在操作，请等待！")
