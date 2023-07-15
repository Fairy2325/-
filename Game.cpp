#include"Game.h"
#include"playgame.h"

using namespace std;
#define LEN 1280
#define WID 960

construction* M_con[8][12];

int coin_game = 600;
int score_game = 0;
int luobo_blood = 10;
int wave = 1;				//波数
using namespace std;


Monster bond = { "Bond", 1000, 0, 1, 1, 5, 50 };		//名字 血量 防御力 攻击力 速度 得分 掉落金币
Monster black = { "Black", 1000, 0, 1, 1.5, 5, 50 };
Monster green = { "Green", 1000, 0, 1, 1.25, 5, 50 };
Monster icecream = { "Icecream", 99999, 99999, 99999, 99999, 99999,99999 };
Monster yellow = { "Yellow", 1000, 0, 1, 1, 5, 50 };
Monster Blue = { "Blue", 5000, 0, 2, 1, 20, 200 };
Monster IRON = { "IRON", 10000, 0, 5, 1, 40, 300 };	//怪物种类



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




structure con1_1 = { "con1_1", 1, 20, 150, 100, 100, 100 ,1};//名字 等级 攻击力 攻击范围 攻速 建造价格 升级价格 最大攻击目标
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
structure con4_3 = { "con4_3", 3, 20, 1200, 100, 100, 100 ,1};	//防御塔种类

structure BaseCon[12] = { con1_1,con2_1,con3_1,con4_1,con1_2,con1_3,con2_2,con2_3,con3_2,con3_3,con4_2,con4_3 };



int sign1 = 0;

int bianhao[4] = { 2,4,6,8 };						//防御塔编号


double xx1 = 105, xx2 = 255, xx3 = 335, xx4 = 485, xx5 = 565, xx6 = 715,
xx7 = 795, xx8 = 945, yy1 = 875, yy2 = 785, LvUp_x1 = 1025, LvUp_x2 = 1175, LvUp_y1 = 845, LvUp_y2 = 785,
Ruin_x1 = 1025, Ruin_x2 = 1175, Ruin_y1 = 935, Ruin_y2 = 875;

double StoreArray[4] = { xx1,xx3,xx5,xx7 };

double XInterval = 106, YInterval = 70;		//每一格的像素点长宽

int Array[8][12] = {
					  {0,0,0,0,0,0,0,0,0,0,0,0},
					   {1,1,1,0,0,0,0,0,0,1,1,1},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,0,0,0,0,0,0,1,0,0},
					   {0,0,1,1,1,1,1,1,1,1,0,0},
					   {0,0,0,0,0,0,0,0,0,0,0,0}
};      //防御塔是否安装

int ifsound = 1;   //设置声音是否打开
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



TCHAR str[12][20] = { _T("IMAGE\\Tow1-1.png"), _T("IMAGE\\Tow1-2.png"), _T("IMAGE\\Tow1-3.png"),
					  _T("IMAGE\\Tow2-1.png"), _T("IMAGE\\Tow2-2.png"), _T("IMAGE\\Tow2-3.png"),
					  _T("IMAGE\\Tow3-1.png"), _T("IMAGE\\Tow3-2.png"), _T("IMAGE\\Tow3-3.png"),
					  _T("IMAGE\\Tow4-1.png"), _T("IMAGE\\Tow4-2.png"), _T("IMAGE\\Tow4-3.png")};
TCHAR Str[12][20] = { _T("1级A塔"), _T("2级A塔") , _T("3级A塔"),
					  _T("1级B塔"), _T("2级B塔") , _T("3级B塔"),
					  _T("1级C塔"), _T("2级C塔") , _T("3级C塔"),
					  _T("1级D塔"), _T("2级D塔") , _T("3级D塔") };
TowerPage tow[12] = { TowerPage(str[0], Str[0], 20, 150, 100, 80),	TowerPage(str[1], Str[1], 30, 250, 100, 160),	TowerPage(str[2], Str[2], 40, 300, 100, 240),
					  TowerPage(str[3], Str[3], 10, 300, 100, 80),	TowerPage(str[4], Str[4], 15, 350, 100, 160),	TowerPage(str[5], Str[5], 20, 400, 100, 240),		
					  TowerPage(str[6], Str[6], 15, 300, 100, 80),	TowerPage(str[7], Str[7], 25, 400, 100, 160),	TowerPage(str[8], Str[8], 40, 500, 100, 240),
					  TowerPage(str[9], Str[9], 5, 1000, 100, 80),	TowerPage(str[10], Str[10], 10, 1200, 100, 160),TowerPage(str[11], Str[11], 20, 1200, 100, 240) };		//塔图鉴的数据库


//实例化管理者对象
Monster_illustrated mm;

//主菜单
void Menu() {

	IMAGE TitleBg(800, 150), bg(1280, 960), bot(380, 70);
	loadimage(&bg, _T("IMAGE\\bg1.png"));
	putimage(0, 0, &bg);										//设置首页背景
	setbkmode(TRANSPARENT);										 //设置当前设备图案填充和文字输出时的背景模式

	loadimage(&TitleBg, _T("IMAGE\\Title.png"), 800, 150);
	transparentimage(NULL, 240, 85, &TitleBg, BLACK);

	loadimage(&bot, _T("IMAGE\\bot0.png"), 380, 70);
	putimage(450, 280, &bot);
	putimage(450, 430, &bot);
	putimage(450, 580, &bot);
	putimage(450, 730, &bot);		//设置首页按钮

	RECT a = { 50,100,LEN - 50,250 };
	RECT b = { 450,280,LEN - 450,350 };
	RECT c = { 450,430,LEN - 450,500 };
	RECT d = { 450,580,LEN - 450,650 };
	RECT e = { 450,730,LEN - 450,800 };
	settextstyle(80, 60, _T("黑体"));
	settextcolor(RED);
	drawtext(_T("塔防管理系统"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(55, 40, _T("楷体"));
	settextcolor(YELLOW);
	drawtext(_T("开始游戏"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("图鉴"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("关于我们"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("退出游戏"), &e, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ClickMenu();
}

//主菜单鼠标控制
void ClickMenu() {
	ExMessage m;		// 定义消息变量
	while (true)
	{
		// 获取一条鼠标或按键消息
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


//图鉴
void Book()
{
	IMAGE TitleBg(800, 150), bg(1280, 960), bot(380, 70);
	loadimage(&bg, _T("IMAGE\\bg1.png"));
	putimage(0, 0, &bg);										//设置首页背景

	//	setbkmode(TRANSPARENT);										 //设置当前设备图案填充和文字输出时的背景模式

	loadimage(&TitleBg, _T("IMAGE\\Title.png"), 800, 150);
	transparentimage(NULL, 240, 85, &TitleBg, BLACK);

	loadimage(&bot, _T("IMAGE\\bot0.png"), 380, 70);
	putimage(450, 350, &bot);
	putimage(450, 500, &bot);
	putimage(450, 650, &bot);					//设置首页按钮

	RECT a = { 50,100,LEN - 50,250 };
	RECT b = { 450,350,LEN - 450,420 };
	RECT c = { 450,500,LEN - 450,570 };
	RECT d = { 450,650,LEN - 450,720 };
	settextstyle(80, 60, _T("黑体"));
	settextcolor(RED);
	drawtext(_T("塔防管理系统"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextstyle(55, 40, _T("楷体"));
	settextcolor(YELLOW);
	drawtext(_T("塔图鉴"), &b, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("怪物图鉴"), &c, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	drawtext(_T("返回"), &d, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	ClickBook();
}

//图鉴鼠标控制
void ClickBook()
{
	ExMessage m;		// 定义消息变量
	while (true)
	{
		// 获取一条鼠标或按键消息
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

//塔图鉴
void Book1()
{
	ExMessage m;		// 定义消息变量
	int cur = 0;

	while (true) {
		//cleardevice();
		BeginBatchDraw();
		IMAGE  bg(1280, 960), BOOK(900, 700), BackBot(100, 100), Down(100, 200), Up(100, 200);
		loadimage(&bg, _T("IMAGE\\bg1.png"));
		putimage(0, 0, &bg);										//设置首页背景
		setbkmode(TRANSPARENT);										 //设置当前设备图案填充和文字输出时的背景模式

		loadimage(&BOOK, _T("IMAGE\\Page.png"), 900, 700);
		transparentimage(NULL, 190, 180, &BOOK, BLACK);    //设置PAGE

		loadimage(&BackBot, _T("IMAGE\\BackBot.png"), 100, 100);
		putimage(1100, 50, &BackBot);					//设置返回按钮

		loadimage(&Up, _T("IMAGE\\PU.png"), 100, 200);
		transparentimage(NULL, 80, 450, &Up, BLACK);//设置上一页按钮

		loadimage(&Down, _T("IMAGE\\PD.png"), 100, 200);
		transparentimage(NULL, 1100, 450, &Down, BLACK);//设置下一页按钮

		RECT a = { 50,50,LEN - 50,200 };
		settextstyle(80, 60, _T("楷体"));
		settextcolor(RED);
		drawtext(_T("塔图鉴"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		tow[cur].ShowPage();
		EndBatchDraw();
		while (true)
		{
			// 获取一条鼠标或按键消息
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
		// 获取一条鼠标或按键消息
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

//怪物图鉴
void Book2()
{
	ExMessage m;		// 定义消息变量



	int cur = 0;
	while (true) {
		//cleardevice();
		BeginBatchDraw();


		IMAGE  bg(1280, 960), BOOK(900, 700), BackBot(100, 100), Down(100, 200), Up(100, 200);
		loadimage(&bg, _T("IMAGE\\bg1.png"));
		putimage(0, 0, &bg);										//设置首页背景
		setbkmode(TRANSPARENT);										 //设置当前设备图案填充和文字输出时的背景模式

		loadimage(&BOOK, _T("IMAGE\\Page.png"), 900, 700);
		transparentimage(NULL, 190, 180, &BOOK, BLACK);    //设置PAGE

		loadimage(&BackBot, _T("IMAGE\\BackBot.png"), 100, 100);
		putimage(1100, 50, &BackBot);					//设置返回按钮

		loadimage(&Up, _T("IMAGE\\PU.png"), 100, 200);
		transparentimage(NULL, 80, 450, &Up, BLACK);//设置上一页按钮

		loadimage(&Down, _T("IMAGE\\PD.png"), 100, 200);
		transparentimage(NULL, 1100, 450, &Down, BLACK);//设置下一页按钮

		RECT a = { 50,50,LEN - 50,200 };
		settextstyle(80, 60, _T("楷体"));
		settextcolor(RED);
		drawtext(_T("怪物图鉴"), &a, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		mm.array[cur]->m_showInfo();

		EndBatchDraw();

		while (true)
		{
			// 获取一条鼠标或按键消息
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

//设置
void Sets()
{
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "**制作人员：***********************************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "******尹艺**梅星宇**任永康**刘彦均*************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;
	cout << "************************感谢游玩！*************" << endl;
	cout << "***********************************************" << endl;
	cout << "***********************************************" << endl;

	//int choice = 0;//用来存储用户的选项

	//while (true)
	//{
	//	//调用成员函数展示菜单
	//	mm.Show_Menu();

	//	cout << "请输入您的选择：" << endl;
	//	cin >> choice;//接收用户的选项

	//	switch (choice)
	//	{
	//	case 0://退出系统
	//		mm.ExitSystem();
	//		break;
	//	case 1://添加职工
	//		mm.Add();
	//		break;
	//		break;
	//	case 2://删除职工
	//		mm.Delete();
	//		break;
	//	case 3://修改职工
	//		mm.Mod_Mon();
	//		break;
	//	case 4://清空文档
	//		mm.Clean_File();
	//		break;
	//	default:
	//		system("cls");//清屏
	//		break;
	//	}

	//}

	system("pause");
	return;

}

//退出游戏
void Exit()
{

	//_getch();
	exit(0);
}