#include"structure.h"

construction::construction(int i, int j, int k)
{
	this->aStructure.name = BaseCon[i].name;
	this->aStructure.lv = 1;
	this->aStructure.damage = BaseCon[i].damage;
	this->aStructure.radius = BaseCon[i].radius;
	this->aStructure.s = BaseCon[i].s;
	this->aStructure.SetCost = BaseCon[i].SetCost;
	this->y = j * YInterval + 200;
	this->x = k * XInterval;
	this->aStructure.UpCost = BaseCon[i].UpCost;
	this->aim_max = BaseCon[i].aim_max;
	x -= (x - 640) * 0.075;
	x += 13;


	switch (i)
	{
	case 0: {loadimage(&Con, _T("res\\Tow1-1.png"), 80, 70); break;	}
	case 1: {loadimage(&Con, _T("res\\Tow2-1.png"), 80, 70); break;	}
	case 2: {loadimage(&Con, _T("res\\Tow3-1.png"), 80, 70); break;	}
	case 3: {loadimage(&Con, _T("res\\Tow4-1.png"), 80, 70); break;	}
	}

}

void LvUP(construction* M_con[8][12], int& coin_game)
{

	while (1)
	{
		ExMessage m;
		if (MouseHit())
		{
			m = getmessage(EM_MOUSE);
			if (m.message == WM_RBUTTONDOWN)            //如果右键按下则取消
			{
				break;
			}


			if (m.message == WM_LBUTTONDOWN)           //左键按下
			{
				int k = m.x / XInterval, j = (m.y - 200) / YInterval;

				if (Array[j][k] == 2 || Array[j][k] == 4 || Array[j][k] == 6 || Array[j][k] == 8)//位置检测
				{
					if (M_con[j][k]->aStructure.UpCost <= 1000 && M_con[j][k]->aStructure.lv < 3 && coin_game>=100)         //金钱判断和等级判断     player.coins 
					{
						M_con[j][k]->aStructure.lv += 1;
						M_con[j][k]->aStructure.damage += 2;
						M_con[j][k]->aStructure.s += 50;
						M_con[j][k]->aStructure.radius += 5;
						
						//付钱
						coin_game -= 100;

					
							if (M_con[j][k]->aStructure.lv == 2 && Array[j][k] == 2)
							{
								loadimage(&M_con[j][k]->Con, _T("res\\Tow1-2.png"), 80, 70);
								M_con[j][k]->aStructure.name = "con1_2";

								M_con[j][k]->aStructure.damage += 10;
								M_con[j][k]->aStructure.s += 0;
								M_con[j][k]->aStructure.radius += 100;
								M_con[j][k]->aim_max += 0;
							}
						if (M_con[j][k]->aStructure.lv == 3 && Array[j][k] == 2)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow1-3.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con1_3";

							M_con[j][k]->aStructure.damage += 10;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 50;
							M_con[j][k]->aim_max += 0;
						}
						if (M_con[j][k]->aStructure.lv == 2 && Array[j][k] == 4)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow2-2.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con2_2";

							M_con[j][k]->aStructure.damage += 5;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 50;
							M_con[j][k]->aim_max += 2;
						}
						if (M_con[j][k]->aStructure.lv == 3 && Array[j][k] == 4)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow2-3.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con2_3";

							M_con[j][k]->aStructure.damage += 5;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 50;
							M_con[j][k]->aim_max += 2;
						}
						if (M_con[j][k]->aStructure.lv == 2 && Array[j][k] == 6)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow3-2.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con3_2";

							M_con[j][k]->aStructure.damage += 10;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 100;
							M_con[j][k]->aim_max += 1;
						}
						if (M_con[j][k]->aStructure.lv == 3 && Array[j][k] == 6)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow3-3.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con3_3";

							M_con[j][k]->aStructure.damage += 15;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 100;
							M_con[j][k]->aim_max += 1;
						}
						if (M_con[j][k]->aStructure.lv == 2 && Array[j][k] == 8)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow4-2.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con4_2";

							M_con[j][k]->aStructure.damage += 5;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 200;
							M_con[j][k]->aim_max += 0;
						}
						if (M_con[j][k]->aStructure.lv == 3 && Array[j][k] == 8)
						{
							loadimage(&M_con[j][k]->Con, _T("res\\Tow4-3.png"), 80, 70);
							M_con[j][k]->aStructure.name = "con4_3";

							M_con[j][k]->aStructure.damage += 10;
							M_con[j][k]->aStructure.s += 0;
							M_con[j][k]->aStructure.radius += 0;
							M_con[j][k]->aim_max += 0;

						}



						break;


					}
					else
					{
						printf("\a");
						break;
					}
				}
			}
		}

	}



};

void RuinCon(construction* M_con[8][12], int& coin_game)
{

	while (1)
	{
		ExMessage m;
		if (MouseHit())
		{
			m = getmessage(EM_MOUSE);
			if (m.message == WM_RBUTTONDOWN)            //如果右键按下则取消
			{
				break;
			}


			if (m.message == WM_LBUTTONDOWN)           //左键按下
			{
				int k = m.x / XInterval, j = (m.y - 200) / YInterval;

				if (Array[j][k] == 2 || Array[j][k] == 4 || Array[j][k] == 6 || Array[j][k] == 8)//位置检测
				{
					if (1)
					{


						//给钱
						coin_game += 80 * M_con[j][k]->aStructure.lv;
						delete M_con[j][k];
						M_con[j][k] = NULL;
						Array[j][k] = 0;
						break;


					}
					else
					{
						break;
					}
				}
				else
				{
					printf("\a");
				}
			}
		}

	}
}

int countNum(int Array[8][12])
{
	int num = 0;
	int i = 0;
	for (i = 0; i < 8; i++)
	{
		for (int j = 0; i < 12; j++)
		{
			if (Array[i][j] != 0 && Array[i][j] != 1)
			{
				num++;
			}
		}
	}
	return num;
}

void PurchaseAndSet(construction* M_con[8][12], ExMessage m, int& coin_game)
{
	ExMessage sec;
	while (1)
	{

		sec = getmessage(EM_MOUSE);

		if (sec.message == WM_RBUTTONDOWN || sec.message == WM_LBUTTONDOWN)            //如果左右键则结束循环
		{
			break;
		}

	}

	int i;
	if (m.x >= 105 && m.x <= 255 && m.y >= 785 && m.y <= 785 + 150)
	{
		i = 0;
	}
	if (m.x >= 335 && m.x <= 485 && m.y >= 785 && m.y <= 785 + 150)
	{
		i = 1;
	}
	if (m.x >= 565 && m.x <= 715 && m.y >= 785 && m.y <= 785 + 150)
	{
		i = 2;
	}
	if (m.x >= 795 && m.x <= 945 && m.y >= 785 && m.y <= 785 + 150)
	{
		i = 3;
	}
	if (100 > coin_game)	//BaseCon[i].SetCost >player.coins
	{
		//显示金币不足
		printf("\a");
		return;
	}
	else
	{
		if (sec.message == WM_LBUTTONDOWN && !(sec.x >= 0 && sec.x <= 1280 && sec.y <= 960 && sec.y >= 760))
		{

			int k = sec.x / XInterval, j = (sec.y - 200) / YInterval;
			if (Array[j][k] == 0)
			{
				M_con[j][k] = new construction(i, j, k);

				Array[j][k] = bianhao[i];
				//更新玩家信息!!!!!!
				coin_game -= 100;
				//break;
			}
			else
			{
				//提示错误
				printf("\a");
			}
			IMAGE xxx(120, 120);

		}
	}

}



