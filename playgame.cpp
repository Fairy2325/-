
#include"playgame.h"


extern construction* M_con[8][12];

extern int coin_game;
extern int score_game;
extern int luobo_blood ;

using namespace std;
extern int wave;				//����

extern Monster bond ;		//���� Ѫ�� ������ ������ �ٶ� �÷� ������
extern Monster black;
extern Monster green;
extern Monster icecream ;
extern Monster yellow;
extern Monster Blue;
extern Monster IRON;	//��������



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




extern structure con1_1;//���� �ȼ� ������ ������Χ ���� ����۸� �����۸�
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
extern structure con4_3;	//����������

extern structure BaseCon[12];

extern int bianhao[4];						//���������


extern double xx1 , xx2 , xx3 , xx4 , xx5  , xx6 ,
xx7, xx8, yy1, yy2, LvUp_x1, LvUp_x2 , LvUp_y1, LvUp_y2,
Ruin_x1, Ruin_x2, Ruin_y1, Ruin_y2;

extern double StoreArray[4];

extern double XInterval, YInterval;		//ÿһ������ص㳤��

extern int Array[8][12] ;      //�������Ƿ�װ

extern int ifsound;   //���������Ƿ��
//void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor)
//{
//	HDC dstDC = GetImageHDC(dstimg);
//	HDC srcDC = GetImageHDC(srcimg);
//	int w = srcimg->getwidth();
//	int h = srcimg->getheight();
//
//	// ʹ�� Windows GDI ����ʵ��͸��λͼ
//	TransparentBlt(dstDC, x, y, w, h, srcDC, 0, 0, w, h, transparentcolor);
//};


extern int sign1;
int playgame()
{
	//��ʼ���ֿ�ָ��
	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			M_con[x][y] = NULL;
		}
	}

	//initgraph(1280, 960, SHOWCONSOLE);  // ��ʼ��ͼ�ν���


	Monstergame i[1000];

	int zx = 38;
	int zy = 274;			//��ʼ������

	int tim = 0;			//��ʼ��

	TCHAR num[10];

	int count = 100;		//��¼ˢ�´���

	int num1 = 0;			//��¼��ǰ�����Ѳ�������

	int num2 = 0;			//��¼�������з�����

	map Map;				//�����ͼ����	
	int timecount = 0;		//��¼ʱ��


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

		

		Map.ShowUp(coin_game, timecount, score_game);	//����
		Map.ShouLuoboBlood(luobo_blood);//��ʾ�ܲ�Ѫ��

		cout << tim << endl;		//�����cout    (�²� ���������⣩


		int i3 = 0;			//��ǰ��ͼ����ͼ������


		//��ǰ���в����ķ�������ʶ
		//��ǰ���з���������

		//������
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


		//������
		for (i3 = 0; i3 < num1; i3++)
		{
			//������
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

			//���������
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
					settextstyle(360, 270, _T("����"));
					settextcolor(RED);
					setbkmode(TRANSPARENT);
					drawtext(Tstr, &x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//��ʾ����
					EndBatchDraw();
					
						PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						PlaySound(TEXT("res\\�ܲ�����2.wav"), NULL, SND_FILENAME | SND_ASYNC);

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
		// �ȴ������˳�
	}    _getch();

	closegraph();  // �ر�ͼ�ν���


	return 0;
}