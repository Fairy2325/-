
#include"playgame.h"


extern construction* M_con[8][12];

extern int coin_game;
extern int score_game;
extern int luobo_blood ;

using namespace std;
extern int wave;				//波数

extern Monster bond ;		//名字 血量 防御力 攻击力 速度 得分 掉落金币
extern Monster black;
extern Monster green;
extern Monster icecream ;
extern Monster yellow;
extern Monster Blue;
extern Monster IRON;	//怪物种类



extern TCHAR con1_1_picture[16];
extern TCHAR con1_2_picture[16];
extern TCHAR con1_3_picture[16];
extern TCHAR con2_1_picture[16];
extern TCHAR con2_2_picture[16];
extern TCHAR con2_3_picture[16];
extern TCHAR con3_1_picture[16];
extern TCHAR con3_2_picture[16];
extern TCHAR con3_3_picture[16];
extern TCHAR con4_1_picture[16];
extern TCHAR con4_2_picture[16];
extern TCHAR con4_3_picture[16];




extern structure con1_1;//名字 等级 攻击力 攻击范围 攻速 建造价格 升级价格
extern structure con2_1;
extern structure con3_1;
extern structure con4_1;
extern structure con1_2;
extern structure con1_3;
extern structure con2_2;
extern structure con3_3;
extern structure con2_3;
extern structure con3_2;
extern structure con4_2;
extern structure con4_3;	//防御塔种类

extern structure BaseCon[12];

extern int bianhao[4];						//防御塔编号


extern double xx1 , xx2 , xx3 , xx4 , xx5  , xx6 ,
xx7, xx8, yy1, yy2, LvUp_x1, LvUp_x2 , LvUp_y1, LvUp_y2,
Ruin_x1, Ruin_x2, Ruin_y1, Ruin_y2;

extern double StoreArray[4];

extern double XInterval, YInterval;		//每一格的像素点长宽

extern int Array[8][12] ;      //防御塔是否安装

extern int ifsound;   //设置声音是否打开
//void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor)
//{
//	HDC dstDC = GetImageHDC(dstimg);
//	HDC srcDC = GetImageHDC(srcimg);
//	int w = srcimg->getwidth();
//	int h = srcimg->getheight();
//
//	// 使用 Windows GDI 函数实现透明位图
//	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
//};


extern int sign1;
int playgame()
{
	//初始化分块指针
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			M_con[x][y] = NULL;
		}
	}

	//initgraph(1280, 960, SHOWCONSOLE);  // 初始化图形界面


	Monstergame i[1000];

	int zx = 38;
	int zy = 274;			//初始化坐标

	int tim = 0;			//初始化

	TCHAR num[10];

	int count = 100;		//记录刷新次数

	int num1 = 0;			//记录当前场上已产生怪物

	int num2 = 0;			//记录场上已有防御塔

	map Map;				//定义地图变量	
	int timecount = 0;		//记录时间


	//int iffirst = 0;

	srand((unsigned)time(NULL));

	Sleep(500);

	while (1)
	{
		BeginBatchDraw();


		if (count % 50 == 0)
		{
			i[num1].Appear(wave);
			num1++;

			if (num1 % 4 == 0)
			{
				sign1 = 0;
				wave++;
				Monstergame::LevUp(wave);
			}
		};

		

		Map.ShowUp(coin_game, timecount, score_game);	//背景
		Map.ShouLuoboBlood(luobo_blood);//显示萝卜血量

		cout << tim << endl;		//神奇的cout    (猜测 缓存区问题）


		int i3 = 0;			//当前地图怪物图像数量


		//当前进行操作的防御塔标识
		//当前含有防御塔数量

		//画建筑
		int i6 = 0;
		for (; i6 < 8; i6++)
		{
			int i7 = 0;
			for (; i7 < 12; i7++)
			{
				if (Array[i6][i7] != 0 && Array[i6][i7] != 1)
				{
					M_con[i6][i7]->showTow();
				}

			}
		}

		int i4 = 0;
		for (i4 = 0; i4 < 8; i4++)
		{
			for (int i5 = 0; i5 < 12; i5++)
			{
				if (Array[i4][i5] != 0 && Array[i4][i5] != 1)
				{

					M_con[i4][i5]->first_flag = 1;

				}
			}
		};


		//画怪物
		for (i3 = 0; i3 < num1; i3++)
		{
			//鼠标操作
			ExMessage click;
			if (MouseHit())
			{

				click = getmessage(EM_MOUSE);

				if (click.x >= LvUp_x1 && click.x <= LvUp_x2 && click.y >= LvUp_y2 && click.y <= LvUp_y1 && click.message == WM_LBUTTONDOWN)
				{
					LvUP(M_con, coin_game);
				}

				if (click.x >= xx1 && click.x <= xx8 && click.y >= yy2 && click.y <= yy1 && click.message == WM_LBUTTONDOWN)
				{
					PurchaseAndSet(M_con, click, coin_game);
				}
				if (click.x >= Ruin_x1 && click.x <= Ruin_x2 && click.y >= Ruin_y2 && click.y <= Ruin_y1 && click.message == WM_LBUTTONDOWN)
				{
					RuinCon(M_con, coin_game);
				}
				Map.clickSOUND(click);

			}

			//如果怪物存活
			i[i3].ifDeath();
			if (i[i3].getdeath())
			{
				for (i4 = 0; i4 < 8; i4++)
				{
					for (int i5 = 0; i5 < 12; i5++)
					{
						if (Array[i4][i5] != 0 && Array[i4][i5] != 1 && i[i3].getdeath() && M_con[i4][i5]->aim_max>=M_con[i4][i5]->first_flag)
						{
							//cout << M_con[i4][i5]->IsMonsterInRange(i[i3]) << endl;

							M_con[i4][i5]->Attack(i[i3], coin_game, score_game);

						}
					}
				};

				zx = i[i3].showX();
				zy = i[i3].showY();
				IMAGE i1;
				i1 = i[i3].showI();
				transparentimage(NULL, zx, zy, &i1, BLACK);
				i[i3].move(luobo_blood);
				if (!luobo_blood)
				{

					TCHAR Tstr[10];
					_itot_s(score_game, Tstr, 10);
					RECT x = { 0,200,1280,760 };
					settextstyle(360, 270, _T("楷书"));
					settextcolor(RED);
					setbkmode(TRANSPARENT);
					drawtext(Tstr, &x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//显示分数
					EndBatchDraw();
					
						PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						PlaySound(TEXT("res\\萝卜被吃2.wav"), NULL, SND_FILENAME | SND_ASYNC);

					Sleep(5000);

					exit(0);
				}
			}

		}

		

		_itot_s(tim, num, 10);



		EndBatchDraw();
		count++;


		tim++;
		Sleep(10);

		timecount = tim / 10;
		// 等待按键退出
	}    _getch();

	closegraph();  // 关闭图形界面


	return 0;
}