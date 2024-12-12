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
        cout << "�ļ���ȡʧ��" << endl;
        return;
    }

    string line;
    vertexNum = 0;
    edgeNum = 0;
    unordered_map<string, int> places; // ͨ����ϣ��ȥ��
    while (getline(file, line))
    {
        stringstream ss(line);
        string place1, place2;
        int length;
        getline(ss, place1, ',');
        getline(ss, place2, ',');
        ss >> length;

        // �޳���Ч�ĵ�·(������Ϊ������ʾ��·��ͨ)
        if (length < 0)
        {
            continue;
        }

        // ����ص�

        if (places.find(place1) == places.end())
        {
            places[place1] = vertexNum;
            vertex[vertexNum++] = place1; // �洢�ص�
        }
        if (places.find(place2) == places.end())
        {
            places[place2] = vertexNum;
            vertex[vertexNum++] = place2; // �洢�ص�
        }

        // �洢��·����
        int index1 = places[place1];
        int index2 = places[place2];
        edge[index1][index2] = length;
        edge[index2][index1] = length;
        edgeNum++;
    }

    file.close();
}

// չʾУ����Ϣ
void Navigator::ShowInfo()
{
    cout << "У���������µص�:" << endl;
    for (int j = 0; j < vertexNum; j++)
    {
        cout << vertex[j] << endl;
    }

    cout << endl;

    cout << "У���ڵ�·��Ϣ����:" << endl;
    for (int i = 0; i < vertexNum; i++)
    {
        for (int j = 0; j < vertexNum; j++)
        {
            if (edge[i][j] > 0 && edge[i][j] < 100 && i < j)
            {
                cout << vertex[i] << " ����" << vertex[j] << " ��" << edge[i][j] << "��" << endl;
            }
        }
    }
}
