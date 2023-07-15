#include"Monster_kind.h"
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#include"Ima.h"

#define LEN 1280
using namespace std;

Monster_kind::Monster_kind(int id, string name, int blood, double speed, int coin, int score)
{
	this->m_id = id;
	this->m_name = name;
	this->m_blood = blood;
	this->m_speed = speed;
	this->m_coin = coin;
	this->m_score = score;
}

void Monster_kind::m_showInfo()
{

	
	RECT position_name = { LEN - 1050,675,LEN - 750,800 };
	RECT position_blood = { 750,300,1050,425 };
	RECT position_speed = { 750,425,1050,550 };
	RECT position_coin = { 750,550,1050,675 };
	RECT position_score = { 750,675,1050,800 };

	RECT position_blood_text = { 650,300,850,425 };
	RECT position_speed_text = { 650,425,850,550 };
	RECT position_coin_text = { 650,550,850,675 };
	RECT position_score_text = { 650,675,850,800 };

	IMAGE a(180,70), b(270,60), c(300,300);

	loadimage(&a, _T("IMAGE\\NameBg.png"), 180, 70);
	transparentimage(NULL, 360, 700, &a, BLACK);			//显示名称背景框

	loadimage(&b, _T("IMAGE\\ImfBg.png"), 270, 60);
	transparentimage(NULL, 690, 330, &b, BLACK);
	transparentimage(NULL, 690, 455, &b, BLACK);
	transparentimage(NULL, 690, 580, &b, BLACK);
	transparentimage(NULL, 690, 705, &b, BLACK);			//显示信息背景框

	settextstyle(40, 20, _T("楷体"));
	settextcolor(BLACK);

	TCHAR num[10];
	_itot_s(m_id, num, 10);
	//drawtext(num, &position_id, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	switch (m_id)
	{
	case 1:
		outtextxy(380, 720, _T("怪物1号"));
		loadimage(&c, _T("IMAGE\\black.png"), 300, 300);
		break;
	case 2:
		outtextxy(380, 720, _T("怪物2号"));
		loadimage(&c, _T("IMAGE\\green.png"), 300, 300);
		break;
	case 3:
		outtextxy(380, 720, _T("怪物3号"));
		loadimage(&c, _T("IMAGE\\bond.png"), 300, 300);
		break;
	case 4:
		outtextxy(380, 720, _T("怪物4号"));
		loadimage(&c, _T("IMAGE\\yellow.png"), 300, 300);
		break;
	case 5:
		outtextxy(380, 720, _T("怪物5号"));
		loadimage(&c, _T("IMAGE\\Blue.png"), 300, 300);
		break;
	case 6:
		outtextxy(380, 720, _T("怪物6号"));
		loadimage(&c, _T("IMAGE\\IRON.png"), 300, 300);
		break;
	case 7:
		outtextxy(380, 720, _T("怪物7号"));
		loadimage(&c, _T("IMAGE\\icecream.png"), 300, 300);
		break;
	}

	transparentimage(NULL, 300, 350, &c, BLACK);

	drawtext(_T("血量"), &position_blood_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(m_blood, num, 10);
	drawtext(num, &position_blood, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("ATK"), &position_speed_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(m_speed, num, 10);
	drawtext(num, &position_speed, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("价值"), &position_coin_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(m_coin, num, 10);
	drawtext(num, &position_coin, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("分数"), &position_score_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(m_score, num, 10);
	drawtext(num, &position_score, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	//cleardevice();
}
