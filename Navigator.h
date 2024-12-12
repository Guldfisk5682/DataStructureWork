#pragma once
#include <iostream>
#include <string>
#define MaxSize 20

class Navigator
{
public:
    Navigator(); // ������ͼ��Ϣ����һ�ļ��У���������ʱ���Զ������ļ�����������ݽṹ
    ~Navigator() {};
    void ShortestRoad(std::string place1, std::string place2); // �����������㣬�Ϳ��Եõ��������·
    void ShowInfo();                                           // չʾѧУ�ں��еĵص�
    void ShowLine();                                           // �Զ���������ڵ����ڲ��ظ���������·
    //���ܶٻ�·/��������

private:
    int vertexNum;
    int edgeNum;
    std::string vertex[MaxSize];
    int edge[MaxSize][MaxSize];
};