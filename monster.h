#pragma once
#include"Game.h"
#include"Ima.h"
#include"map.h"
using namespace std;

struct Monster
{
	string name;
	int blood;
	int defense;
	int ATK;
	float speed;
	int score;
	int coins;
};
extern Monster bond;
extern Monster black;
extern Monster green;
extern Monster icecream;
extern Monster yellow;
extern Monster Blue;
extern Monster IRON;
extern int sign1;
class Monstergame
{
private:
	Monster aMonster;
	            //����һ������,ÿһ����������֮������
	int zx;
	int zy;
	IMAGE img;
	bool deathflag;               //���״̬
	int blood_max;

public:


	void ShowBlood()
	{
		setfillcolor(RED);
		fillrectangle(zx, zy - 10, zx + 70, zy);
		double rate = (double)aMonster.blood / blood_max;
		setfillcolor(GREEN);
		fillrectangle(zx, zy - 10, zx + (70 * rate), zy);
	}

	int getdeath()
	{
		return deathflag;
	};

	static void LevUp(int wave)
	{

		cout << wave << endl;
		int tenwave = wave % 10;
		if (tenwave  == 0)
		{
			bond.blood++;
			black.blood++;
			green.blood++;
			yellow.blood++;
			Blue.blood++;
			IRON.blood++;		//����������1

			bond.ATK++;
			black.ATK++;
			green.ATK++;
			yellow.ATK++;
			Blue.ATK++;
			IRON.ATK++;		//����������1

			bond.speed += 0.25;
			black.speed += 0.25;
			green.speed += 0.25;
			yellow.speed += 0.25;
			Blue.speed += 0.25;
			IRON.speed += 0.25;		//�ٶ�����0.25

			bond.coins += 10;
			black.coins += 10;
			yellow.coins += 10;
			green.coins += 10;
			Blue.coins += 50;
			IRON.coins += 100;		//Ǯ����

			bond.score += 5;
			black.score += 5;
			yellow.score += 5;
			green.score += 5;
			Blue.score += 10;
			IRON.score += 20;
		}
		bond.blood++;
		black.blood++;
		green.blood++;
		yellow.blood++;
		Blue.blood++;
		IRON.blood++;

	};

	void Appear(int wave)
	{
		int flag = 1;
		deathflag = 1;

		while (flag)
		{


			int sign = rand() % 7;
			if (wave <= 10 && (sign == 5))	//ǰ10�����ܲ���BOSS
			{
				continue;
			}
			if (sign == 6&&wave<=20)		//ǰ20��������icecream
			{
				continue;
			}
			if ((wave % 10 == 0) && (sign1 == 1) && (sign == 5))	//ÿ10������һ��BOSS
			{
				continue;
			}
			if ((wave % 10 == 0) && (sign1 == 0))
			{
				sign = 5;
			}
			if (wave == 1)			//��һ��ֻ����������С��
			{
				sign = 1;
			}

			switch (sign)
			{
			case 0: {this->aMonster = bond; flag = 0; loadimage(&img, _T("res\\bond.png")); break; }
			case 1: { this->aMonster = black; flag = 0; loadimage(&img, _T("res\\black.png"), 62, 75); break; }
			case 2: {this->aMonster = green; flag = 0; loadimage(&img, _T("res\\green1.png"), 62, 75); break; }
			case 3: { this->aMonster = yellow; flag = 0; loadimage(&img, _T("res\\yellow.png"), 62, 75); break; }
			case 4: { this->aMonster = Blue;   flag = 0; loadimage(&img, _T("res\\Blue.png"), 92, 85); break; }
			case 5: { this->aMonster = IRON; flag = 0; sign1 = 1; loadimage(&img, _T("res\\IRON.png"), 152, 85); break; }
			case 6: {this->aMonster = icecream; flag = 0; loadimage(&img, _T("res\\icecream.png"), 62, 75); break; }
			};
			this->ifDeath();

		}

		blood_max = aMonster.blood;

		this->zx = 38;
		this->zy = 274;
	};

	void Give(Monster i, IMAGE im, int x, int y)
	{
		this->aMonster = i;
		this->img = im;
		this->zx = x;
		this->zy = y;
	};
	
	int showX()
	{
		return zx;
	};
	
	int showY()
	{
		return zy;
	};
	
	Monster showM()
	{
		return aMonster;
	};
	
	IMAGE showI()
	{
		IMAGE i;
		i = this->img;
		ShowBlood();
		return i;
	};

	int mount(int wave)
	{
		return wave + 3;      //ÿ������wave+3������
	};
	
	void appearend()	//������һ��BOSS
	{
		sign1 = 0;
	};

	void ifDeath()
	{
		if (aMonster.blood <= 0)
		{
			deathflag = 0;
		}
		else
			deathflag = 1;

	};

	void death()
	{
		//P.Score += aMonster.score;
		//P.Money += aMonster.coins;

	};


	void move(int& luobo_blood)
	{
		string name1;
		name1 = this->aMonster.name;
		//�Բ�ͬ��С��ģ��·�����е���
		int side = 0;
		if (name1 == "IRON")
		{
			side = (152 - 62) / 3;
		}
		else if (name1 == "Blue")
		{
			side = (92 - 62) / 3;
		}

		if (deathflag)
		{
			if (zx >= 38 && zy == 274 && zx <= (268 - side))
			{
				zx += 5;
			}
			if (zx == (268 - side) && zy >= 274 && zy <= 609)
			{
				zy += 5;
			}
			if (zy == 609 && zx <= (953 - side) && zx >= (268 - side))
			{
				zx += 5;
			}
			if (zx == (953 - side) && zy >= 274 && zy <= 609)
			{
				zy -= 5;
			}
			if (zy == 274 && zx < (1183 - side) && zx >= (953 - side))
			{
				zx += 5;
			}
			if (zx >= (1180 - side) && zy <= 274)
			{
				luobo_blood -= this->aMonster.ATK;
				//PlaySound(TEXT("res\\�ܲ�����.wav"), NULL, SND_FILENAME | SND_ASYNC);
				if (luobo_blood <= 0)
				{
					luobo_blood = 0;
				}
				this->aMonster.blood = 0;
			}
		}


	};
	
	Monstergame& operator=(const Monster i)
	{
		this->aMonster.ATK = i.ATK;
		this->aMonster.blood = i.blood;
		this->aMonster.coins = i.coins;
		this->aMonster.defense = i.defense;
		this->aMonster.name = i.name;
		this->aMonster.score = i.score;
		this->aMonster.speed = i.speed;

	}



	friend class construction;
};