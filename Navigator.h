#pragma once
#include <iostream>

template <typename T>
class Navigator
{
public:
    MGraph(T a[], int n, int e);    //将导游图信息存入一文件中，程序运行时可自动读入文件建立相关数据结构
    ~MGraph(){};                                         
    void Floyd(int v);      // 最小化路径 (输入两个景点，就可以得到其最短线路)
    void ShowInfo();
    void Line(T place1,T place2);        //输入两个景点，就可以得到其最短线路,显示线路时应同时显示路径长度

private:
    T vertex[MaxSize];   
    int edge[MaxSize][MaxSize]; 
    int vertexNum, edgeNum;     

    int MinEdge(int r[], int n); 
};