#pragma once
#include<iostream>
#include<string>
#include<graphics.h>

using namespace std;

class Monster_kind
{
public:

    //构造函数
    Monster_kind(int id, string name, int blood, double speed, int coin, int score);

    //显示个人信息
    void m_showInfo();

    //怪物编号
    int m_id;

    //怪物名称
    string m_name;

    //怪物血量
    int m_blood;

    //怪物移速
    double m_speed;

    //怪物掉落金币数
    int m_coin;

    //怪物死亡分数
    int m_score;

    //图像信息（暂无）
    IMAGE a;

};