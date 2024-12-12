#include "Navigator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

Navigator::Navigator()
{
    ifstream file("park_infortxt.csv");
    if (!file)
    {
        cout << "文件读取失败" << endl;
        return;
    }

    string line;
    vertexNum = 0;
    edgeNum = 0;
    unordered_map<string, int> places; // 通过哈希表去重
    while (getline(file, line))
    {
        stringstream ss(line);
        string place1, place2;
        int length;
        getline(ss, place1, ',');
        getline(ss, place2, ',');
        ss >> length;

        // 剔除无效的道路(即长度为负，表示此路不通)
        if (length < 0)
        {
            continue;
        }

        // 插入地点

        if (places.find(place1) == places.end())
        {
            places[place1] = vertexNum;
            vertex[vertexNum++] = place1; // 存储地点
        }
        if (places.find(place2) == places.end())
        {
            places[place2] = vertexNum;
            vertex[vertexNum++] = place2; // 存储地点
        }

        // 存储道路长度
        int index1 = places[place1];
        int index2 = places[place2];
        edge[index1][index2] = length;
        edge[index2][index1] = length;
        edgeNum++;
    }

    file.close();
}

// 展示校区信息
void Navigator::ShowInfo()
{
    cout << "校区内有如下地点:" << endl;
    for (int j = 0; j < vertexNum; j++)
    {
        cout << vertex[j] << endl;
    }

    cout << endl;

    cout << "校区内道路信息如下:" << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            if (edge[i][j] > 0 && edge[i][j] < 100 && i < j)
            {
                cout << vertex[i] << " 距离" << vertex[j] << " 有" << edge[i][j] << "米" << endl;
            }
        }
    }
}
