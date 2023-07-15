#include"TowerPage.h"
#include"Ima.h"

TowerPage::TowerPage(TCHAR *ima, TCHAR *name, int a, int r, int u, int s)
{
	Ima = ima;
	Name = name;
	Attack = a;
	Range = r;
	UpCost = u;
	Sell = s;
}

void TowerPage::ShowPage()
{
	RECT position_name = { 230,675,530,800 };

	RECT position_attack = { 750,300,1050,425 };
	RECT position_range = { 750,425,1050,550 };
	RECT position_upcost = { 750,550,1050,675 };
	RECT position_sell = { 750,675,1050,800 };

	RECT position_attack_text = { 650,300,850,425 };
	RECT position_range_text = { 650,425,850,550 };
	RECT position_upcost_text = { 650,550,850,675 };
	RECT position_sell_text = { 650,675,850,800 };

	IMAGE a(180, 70), b(270, 60), c(300, 300);

	loadimage(&a, _T("IMAGE\\NameBg.png"), 180, 70);
	transparentimage(NULL, 360, 700, &a, BLACK);			//显示名称背景框

	loadimage(&b, _T("IMAGE\\ImfBg.png"), 270, 60);
	transparentimage(NULL, 690, 330, &b, BLACK);
	transparentimage(NULL, 690, 455, &b, BLACK);
	transparentimage(NULL, 690, 580, &b, BLACK);
	transparentimage(NULL, 690, 705, &b, BLACK);			//显示信息背景框

	loadimage(&c, Ima, 300, 300);
	transparentimage(NULL, 300, 350, &c, BLACK);

	settextstyle(40, 20, _T("楷体"));
	settextcolor(BLACK);

	outtextxy(390, 720, Name);

	TCHAR num[10];
	drawtext(_T("攻击"), &position_attack_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(Attack, num, 10);
	drawtext(num, &position_attack, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("射程"), &position_range_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(Range, num, 10);
	drawtext(num, &position_range, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("价格"), &position_upcost_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(UpCost, num, 10);
	drawtext(num, &position_upcost, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	drawtext(_T("售价"), &position_sell_text, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	_itot_s(Sell, num, 10);
	drawtext(num, &position_sell, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}