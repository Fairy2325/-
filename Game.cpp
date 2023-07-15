#include"Game.h"
#include"playgame.h"

using namespace std;
#define LEN 1280
#define WID 960

construction* M_con[8][12];

int coin_game = 600;
int score_game = 0;
int luobo_blood = 10;
int wave = 1;				//����
using namespace std;


Monster bond = { "Bond", 1000, 0, 1, 1, 5, 50 };		//���� Ѫ�� ������ ������ �ٶ� �÷� ������
Monster black = { "Black", 1000, 0, 1, 1.5, 5, 50 };
Monster green = { "Green", 1000, 0, 1, 1.25, 5, 50 };
Monster icecream = { "Icecream", 99999, 99999, 99999, 99999, 99999,99999 };
Monster yellow = { "Yellow", 1000, 0, 1, 1, 5, 50 };
Monster Blue = { "Blue", 5000, 0, 2, 1, 20, 200 };
Monster IRON = { "IRON", 10000, 0, 5, 1, 40, 300 };	//��������



TCHAR con1_1_picture[16] = _T("res\\Tow1-1");
TCHAR con1_2_picture[16] = _T("res\\Tow1-2");
TCHAR con1_3_picture[16] = _T("res\\Tow1-3");
TCHAR con2_1_picture[16] = _T("res\\Tow2-1");
TCHAR con2_2_picture[16] = _T("res\\Tow2-2");
TCHAR con2_3_picture[16] = _T("res\\Tow2-3");
TCHAR con3_1_picture[16] = _T("res\\Tow3-1");
TCHAR con3_2_picture[16] = _T("res\\Tow3-2");
TCHAR con3_3_picture[16] = _T("res\\Tow3-3");
TCHAR con4_1_picture[16] = _T("res\\Tow4-1");
TCHAR con4_2_picture[16] = _T("res\\Tow4-2");
TCHAR con4_3_picture[16] = _T("res\\Tow4-3");




structure con1_1 = { "con1_1", 1, 20, 150, 100, 100, 100 ,1};//���� �ȼ� ������ ������Χ ���� ����۸� �����۸� ��󹥻�Ŀ��
structure con2_1 = { "con2_1", 1, 10, 300, 100, 100, 100 ,1};
structure con3_1 = { "con3_1", 1, 15, 300, 100, 100, 100 ,1};
structure con4_1 = { "con4_1", 1, 5, 1000, 100, 100, 100 ,1};

structure con1_2 = { "con1_2", 2, 30, 250, 100, 100, 100 ,1};
structure con2_2 = { "con2_2", 2, 15, 350, 100, 100, 100 ,3};
structure con3_2 = { "con3_2", 2, 25, 400, 100, 100, 100 ,2};
structure con4_2 = { "con4_2", 2, 10, 1200, 100, 100, 100 ,1};

structure con1_3 = { "con1_3", 3, 40, 300, 100, 100, 100 ,1};
structure con2_3 = { "con2_3", 3, 20, 400, 100, 100, 100 ,5};
structure con3_3 = { "con3_3", 3, 40, 500, 100, 100, 100 ,3};
structure con4_3 = { "con4_3", 3, 20, 1200, 100, 100, 100 ,1};	//����������

structure BaseCon[12] = { con1_1,con2_1,con3_1,con4_1,con1_2,con1_3,con2_2,con2_3,con3_2,con3_3,con4_2,con4_3 };



int sign1 = 0;

int bianhao[4] = { 2,4,6,8 };						//���������


double xx1 = 105, xx2 = 255, xx3 = 335, xx4 = 485, xx5 = 565, xx6 = 715,
xx7 = 795, xx8 = 945, yy1 = 875, yy2 = 785, LvUp_x1 = 1025, LvUp_x2 = 1175, LvUp_y1 = 845, LvUp_y2 = 785,
Ruin_x1 = 1025, Ruin_x2 = 1175, Ruin_y1 = 935, Ruin_y2 = 875;

double StoreArray[4] = { xx1,xx3,xx5,xx7 };

double XInterval = 106, YInterval = 70;		//ÿһ������ص㳤��

int Array[8][12] = {
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					   {1,1,1,0,0,0,0,0,0,1,1,1},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,1,1,1,1,1,1,1,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0}
};      //�������Ƿ�װ

int ifsound = 1;   //���������Ƿ��
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



TCHAR str[12][20] = { _T("IMAGE\\Tow1-1.png"), _T("IMAGE\\Tow1-2.png"), _T("IMAGE\\Tow1-3.png"),
					  _T("IMAGE\\Tow2-1.png"), _T("IMAGE\\Tow2-2.png"), _T("IMAGE\\Tow2-3.png"),
					  _T("IMAGE\\Tow3-1.png"), _T("IMAGE\\Tow3-2.png"), _T("IMAGE\\Tow3-3.png"),
					  _T("IMAGE\\Tow4-1.png"), _T("IMAGE\\Tow4-2.png"), _T("IMAGE\\Tow4-3.png")};
TCHAR Str[12][20] = { _T("1��A��"), _T("2��A��") , _T("3��A��"),
					  _T("1��B��"), _T("2��B��") , _T("3��B��"),
					  _T("1��C��"), _T("2��C��") , _T("3��C��"),
					  _T("1��D��"), _T("2��D��") , _T("3��D��") };
TowerPage tow[12] = { TowerPage(str[0], Str[0], 20, 150, 100, 80),	TowerPage(str[1], Str[1], 30, 250, 100, 160),	TowerPage(str[2], Str[2], 40, 300, 100, 240),
					  TowerPage(str[3], Str[3], 10, 300, 100, 80),	TowerPage(str[4], Str[4], 15, 350, 100, 160),	TowerPage(str[5], Str[5], 20, 400, 100, 240),		
					  TowerPage(str[6], Str[6], 15, 300, 100, 80),	TowerPage(str[7], Str[7], 25, 400, 100, 160),	TowerPage(str[8], Str[8], 40, 500, 100, 240),
					  TowerPage(str[9], Str[9], 5, 1000, 100, 80),	TowerPage(str[10], Str[10], 10, 1200, 100, 160),TowerPage(str[11], Str[11], 20, 1200, 100, 240) };		//��ͼ�������ݿ�


//ʵ���������߶���
Monster_illustrated mm;

//���˵�
void Menu() {

	IMAGE TitleBg(800, 150), bg(1280, 960), bot(380, 70);
	loadimage(&bg, _T("IMAGE\\bg1.png"));
	putimage(0, 0, &bg);										//������ҳ����
	setbkmode(TRANSPARENT);										 //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ

	loadimage(&TitleBg, _T("IMAGE\\Title.png"), 800, 150);
	transparentimage(NULL, 240, 85, &TitleBg, BLACK);

	loadimage(&bot, _T("IMAGE\\bot0.png"), 380, 70);
	putimage(450, 280, &bot);
	putimage(450, 430, &bot);
	putimage(450, 580, &bot);
	putimage(450, 730, &bot);		//������ҳ��ť

	RECT a = { 50,100,LEN - 50,250 };
	RECT b = { 450,280,LEN - 450,350 };
	RECT c = { 450,430,LEN - 450,500 };
	RECT d = { 450,580,LEN - 450,650 };
	RECT e = { 450,730,LEN - 450,800 };
	settextstyle(80, 60, _T("����"));
	settextcolor(RED);
	drawtext(_T("��������ϵͳ"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(55, 40, _T("����"));
	settextcolor(YELLOW);
	drawtext(_T("��ʼ��Ϸ"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("ͼ��"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("��������"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("�˳���Ϸ"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ClickMenu();
}

//���˵�������
void ClickMenu() {
	ExMessage m;		// ������Ϣ����
	while (true)
	{
		// ��ȡһ�����򰴼���Ϣ
		m = getmessage(EX_MOUSE);

		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x<450 || m.x>LEN - 450) continue;
			else if (m.y >= 280 && m.y <= 350) {
				playgame();
			}
			else if (m.y >= 430 && m.y <= 500) {
				Book();
			}
			else if (m.y >= 580 && m.y <= 650) {
				Sets();
			}
			else if (m.y >= 730 && m.y <= 800) {
				Exit();
			}
			break;
		}
	}
}


//ͼ��
void Book()
{
	IMAGE TitleBg(800, 150), bg(1280, 960), bot(380, 70);
	loadimage(&bg, _T("IMAGE\\bg1.png"));
	putimage(0, 0, &bg);										//������ҳ����

	//	setbkmode(TRANSPARENT);										 //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ

	loadimage(&TitleBg, _T("IMAGE\\Title.png"), 800, 150);
	transparentimage(NULL, 240, 85, &TitleBg, BLACK);

	loadimage(&bot, _T("IMAGE\\bot0.png"), 380, 70);
	putimage(450, 350, &bot);
	putimage(450, 500, &bot);
	putimage(450, 650, &bot);					//������ҳ��ť

	RECT a = { 50,100,LEN - 50,250 };
	RECT b = { 450,350,LEN - 450,420 };
	RECT c = { 450,500,LEN - 450,570 };
	RECT d = { 450,650,LEN - 450,720 };
	settextstyle(80, 60, _T("����"));
	settextcolor(RED);
	drawtext(_T("��������ϵͳ"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(55, 40, _T("����"));
	settextcolor(YELLOW);
	drawtext(_T("��ͼ��"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("����ͼ��"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("����"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ClickBook();
}

//ͼ��������
void ClickBook()
{
	ExMessage m;		// ������Ϣ����
	while (true)
	{
		// ��ȡһ�����򰴼���Ϣ
		m = getmessage(EX_MOUSE);

		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x<450 || m.x>LEN - 450) continue;
			else if (m.y >= 350 && m.y <= 420) {
				Book1();
				return;
			}
			else if (m.y >= 500 && m.y <= 570) {
				Book2();
				return;
			}
			else if (m.y >= 650 && m.y <= 720) {
				return;
			}
		}
	}
	return;
}

//��ͼ��
void Book1()
{
	ExMessage m;		// ������Ϣ����
	int cur = 0;

	while (true) {
		//cleardevice();
		BeginBatchDraw();
		IMAGE  bg(1280, 960), BOOK(900, 700), BackBot(100, 100), Down(100, 200), Up(100, 200);
		loadimage(&bg, _T("IMAGE\\bg1.png"));
		putimage(0, 0, &bg);										//������ҳ����
		setbkmode(TRANSPARENT);										 //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ

		loadimage(&BOOK, _T("IMAGE\\Page.png"), 900, 700);
		transparentimage(NULL, 190, 180, &BOOK, BLACK);    //����PAGE

		loadimage(&BackBot, _T("IMAGE\\BackBot.png"), 100, 100);
		putimage(1100, 50, &BackBot);					//���÷��ذ�ť

		loadimage(&Up, _T("IMAGE\\PU.png"), 100, 200);
		transparentimage(NULL, 80, 450, &Up, BLACK);//������һҳ��ť

		loadimage(&Down, _T("IMAGE\\PD.png"), 100, 200);
		transparentimage(NULL, 1100, 450, &Down, BLACK);//������һҳ��ť

		RECT a = { 50,50,LEN - 50,200 };
		settextstyle(80, 60, _T("����"));
		settextcolor(RED);
		drawtext(_T("��ͼ��"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		tow[cur].ShowPage();
		EndBatchDraw();
		while (true)
		{
			// ��ȡһ�����򰴼���Ϣ
			m = getmessage(EX_MOUSE);

			if (m.message == WM_LBUTTONDOWN)
			{
				if (m.x >= 80 && m.x <= 180 && m.y >= 200 && m.y <= 650 && cur > 0) {
					cur--;
					break;
				}
				if (m.x >= 1100 && m.x <= 1200 && m.y >= 200 && m.y <= 650 && cur < 11) {
					cur++;
					break;
				}
				if (m.x >= 1100 && m.x <= 1200 && m.y >= 50 && m.y <= 150) {
					Book();
					return;
				}

			}
		}
	}



	while (true)
	{
		// ��ȡһ�����򰴼���Ϣ
		m = getmessage(EX_MOUSE);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 1100 && m.x <= 1200 && m.y >= 50 && m.y <= 150) {
				Book();
				return;
			}
			else if (m.y >= 350 && m.y <= 420) {
				Book1();
				return;
			}
			else if (m.y >= 500 && m.y <= 570) {
				Book2();
				return;
			}
			else if (m.y >= 650 && m.y <= 720) {
				return;
			}
		}
	}
	return;
}

//����ͼ��
void Book2()
{
	ExMessage m;		// ������Ϣ����



	int cur = 0;
	while (true) {
		//cleardevice();
		BeginBatchDraw();


		IMAGE  bg(1280, 960), BOOK(900, 700), BackBot(100, 100), Down(100, 200), Up(100, 200);
		loadimage(&bg, _T("IMAGE\\bg1.png"));
		putimage(0, 0, &bg);										//������ҳ����
		setbkmode(TRANSPARENT);										 //���õ�ǰ�豸ͼ�������������ʱ�ı���ģʽ

		loadimage(&BOOK, _T("IMAGE\\Page.png"), 900, 700);
		transparentimage(NULL, 190, 180, &BOOK, BLACK);    //����PAGE

		loadimage(&BackBot, _T("IMAGE\\BackBot.png"), 100, 100);
		putimage(1100, 50, &BackBot);					//���÷��ذ�ť

		loadimage(&Up, _T("IMAGE\\PU.png"), 100, 200);
		transparentimage(NULL, 80, 450, &Up, BLACK);//������һҳ��ť

		loadimage(&Down, _T("IMAGE\\PD.png"), 100, 200);
		transparentimage(NULL, 1100, 450, &Down, BLACK);//������һҳ��ť

		RECT a = { 50,50,LEN - 50,200 };
		settextstyle(80, 60, _T("����"));
		settextcolor(RED);
		drawtext(_T("����ͼ��"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		mm.array[cur]->m_showInfo();

		EndBatchDraw();

		while (true)
		{
			// ��ȡһ�����򰴼���Ϣ
			m = getmessage(EX_MOUSE);

			if (m.message == WM_LBUTTONDOWN)
			{
				if (m.x >= 80 && m.x <= 180 && m.y >= 200 && m.y <= 650 && cur > 0) {
					cur--;
					break;
				}
				if (m.x >= 1100 && m.x <= 1200 && m.y >= 200 && m.y <= 650 && cur < 6) {
					cur++;
					break;
				}
				if (m.x >= 1100 && m.x <= 1200 && m.y >= 50 && m.y <= 150) {
					Book();
					return;
				}

			}
		}
	}

	return;
}

//����
void Sets()
{
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "**������Ա��***********************************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "******����**÷����**������**�����*************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "************************��л���棡*************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;

	//int choice = 0;//�����洢�û���ѡ��

	//while (true)
	//{
	//	//���ó�Ա����չʾ�˵�
	//	mm.Show_Menu();

	//	cout << "����������ѡ��" << endl;
	//	cin >> choice;//�����û���ѡ��

	//	switch (choice)
	//	{
	//	case 0://�˳�ϵͳ
	//		mm.ExitSystem();
	//		break;
	//	case 1://���ְ��
	//		mm.Add();
	//		break;
	//		break;
	//	case 2://ɾ��ְ��
	//		mm.Delete();
	//		break;
	//	case 3://�޸�ְ��
	//		mm.Mod_Mon();
	//		break;
	//	case 4://����ĵ�
	//		mm.Clean_File();
	//		break;
	//	default:
	//		system("cls");//����
	//		break;
	//	}

	//}

	system("pause");
	return;

}

//�˳���Ϸ
void Exit()
{

	//_getch();
	exit(0);
}