#pragma once
#include <iostream>
#include <string>
#define MaxSize 20

class Navigator
{
public:
    Navigator(); // 将导游图信息存入一文件中，程序运行时可自动读入文件建立相关数据结构
    ~Navigator() {};
    void ShortestRoad(std::string place1, std::string place2); // 输入两个景点，就可以得到其最短线路
    void ShowInfo();                                           // 展示学校内含有的地点
    void ShowLine();                                           // 自动给出从入口到出口不重复游览的线路
    //哈密顿回路/旅商问题

private:
    int vertexNum;
    int edgeNum;
    std::string vertex[MaxSize];
    int edge[MaxSize][MaxSize];
};