#pragma once
#include<iostream>
#include<string>
#include<graphics.h>

using namespace std;

class Monster_kind
{
public:

    //���캯��
    Monster_kind(int id, string name, int blood, double speed, int coin, int score);

    //��ʾ������Ϣ
    void m_showInfo();

    //������
    int m_id;

    //��������
    string m_name;

    //����Ѫ��
    int m_blood;

    //��������
    double m_speed;

    //�����������
    int m_coin;

    //������������
    int m_score;

    //ͼ����Ϣ�����ޣ�
    IMAGE a;

};