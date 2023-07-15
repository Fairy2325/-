#pragma once
#include"monster.h"
using namespace std;

struct structure
{
	string name;
	int lv;
	int  damage;
	double radius;		//攻击半径
	double s;			//导弹速度
	double SetCost;		//花费
	double UpCost;		//升级费用
	int aim_max;
};

extern int Array[8][12];//地图分块

extern double xx1, xx2, xx3, xx4, xx5, xx6, xx7, xx8, yy1, yy2, LvUp_x1, LvUp_x2, LvUp_y1, LvUp_y2, Ruin_x1, Ruin_x2, Ruin_y1, Ruin_y2;
extern double XInterval, YInterval;
extern double StoreArray[4];
extern int bianhao[4];
extern structure con1_1;
extern structure con2_1;
extern structure con3_1;
extern structure con4_1;
extern structure con1_2;
extern structure con2_2;
extern structure con2_3;
extern structure con3_2;
extern structure con3_3;
extern structure con4_2;
extern structure con4_3;
extern structure BaseCon[12];


class construction
{
public:

	construction(int i, int j, int k);

	structure aStructure;

	int x;			//坐标
	int y;			//	
	//Player player;
	IMAGE Con;			//建筑图像
	IMAGE buttle;		//	子弹图像
	TCHAR picture[16]; //图像地址

	int first_flag;
	int aim_max;

	friend class Monstergame;

	//计算防御塔与怪物之间距离
	double Distance(Monstergame  mon)
	{

		return sqrt((mon.showX() - this->x) * (mon.showX() - this->x) + (mon.showY() - this->y) * (mon.showY() - this->y));
	}

	//判断怪物是否在攻击范围内
	bool IsMonsterInRange(Monstergame mon)
	{
		if (Distance(mon) <= this->aStructure.radius)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	void Attack(Monstergame& mon, int& coin_game, int& score_game)
	{
		if (IsMonsterInRange(mon))                //判断距离
		{
			mon.aMonster.blood = mon.aMonster.blood - aStructure.damage;
			
			int x1 = mon.zx + 40, y1 = mon.zy + 30, x2 = x + 40, y2 = y + 30;
			setlinecolor(BLUE);
			setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 20);
			line(x1, y1, x2, y2);
			setlinecolor(WHITE);
			setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 5);
			line(x1, y1, x2, y2);
			setlinecolor(BLACK);
			setlinestyle(PS_SOLID, 1);
			this->first_flag++;
			mon.ifDeath();
			if (!mon.getdeath())
			{
				coin_game += mon.aMonster.coins;
				score_game += mon.aMonster.score;
			}
		}
	
	};


	IMAGE picPicture()										  //挑选防御塔
	{
		IMAGE img;

		if (aStructure.name == "con1_1")
		{

			loadimage(&this->Con, _T("res\\Tow1-1"), 100, 100);

		}


		if (aStructure.name == "con1_2")
		{
			loadimage(&this->Con, _T("res\\Tow1-2"), 100, 100);

		}
		if (aStructure.name == "con1_3")
		{
			loadimage(&this->Con, _T("res\\Tow1-3"), 100, 100);

		}
		if (aStructure.name == "con2_1")
		{
			loadimage(&this->Con, _T("res\\Tow2-1"), 100, 100);

		}
		if (aStructure.name == "con2_2")
		{
			loadimage(&this->Con, _T("res\\Tow2-2"), 100, 100);

		}
		if (aStructure.name == "con2_3")
		{
			loadimage(&this->Con, _T("res\\Tow2-3"), 100, 100);

		}
		if (aStructure.name == "con3_1")
		{
			loadimage(&this->Con, _T("res\\Tow3-1"), 100, 100);

		}
		if (aStructure.name == "con3_2")
		{
			loadimage(&this->Con, _T("res\\Tow3-2"), 100, 100);

		}
		if (aStructure.name == "con3_3")
		{
			loadimage(&this->Con, _T("res\\Tow3-3"), 100, 100);

		}
		if (aStructure.name == "con4_1")
		{
			loadimage(&this->Con, _T("res\\Tow4-1"), 100, 100);

		}
		if (aStructure.name == "con4_2")
		{
			loadimage(&this->Con, _T("res\\Tow4-2"), 100, 100);

		}
		if (aStructure.name == "con4_3")
		{
			loadimage(&this->Con, _T("res\\Tow4-3"), 100, 100);
		}

	};


	void ShowPicture()                                        //展示防御塔
	{
		IMAGE img;
		img = this->picPicture();
		putimage(this->x, this->y, &img);
	};
	void showTow()
	{
		transparentimage(NULL, x, y, &Con, BLACK);
	}
};


//防御塔升级
void LvUP(construction* M_con[8][12], int& coin_game);

//放置防御塔
void PurchaseAndSet(construction* M_con[8][12], ExMessage m, int& coin_game);
void RuinCon(construction* M_con[8][12], int& coin_game);

int countNum(int Array[8][12]);
