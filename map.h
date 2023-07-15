#pragma once
#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
#include <graphics.h>	
#include <conio.h>
#include"Ima.h"
#pragma comment( lib, "MSIMG32.LIB")
extern int ifsound;
void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg, UINT transparentcolor);
class map
{
public:

	void clickSOUND(ExMessage click)
	{

		if (click.x >= 1000 && click.x <= 1100 && click.y >= 60 && click.y <= 160 && click.message == WM_LBUTTONDOWN)
		{

			if (ifsound)
			{
				PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				ifsound = 0;
			}
			else
			{
				PlaySound(TEXT("res\\bgm.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				ifsound = 1;
			}

		}

		if (click.x >= 1150 && click.x <= 1250 && click.y >= 60 && click.y <= 160 && click.message == WM_LBUTTONDOWN)
		{
			

			while (1)
			{
				IMAGE tmp(100, 100);
				loadimage(&tmp, _T("IMAGE\\GoOn.png"), 100, 100);
				transparentimage(NULL, 1150, 60, &tmp, BLACK);
				EndBatchDraw();
				ExMessage click1;
				click1 = getmessage(EM_MOUSE);
				if (click1.x >= 1150 && click1.x <= 1250 && click1.y >= 60 && click1.y <= 160 && click1.message == WM_LBUTTONDOWN)
				{
					
					loadimage(&tmp, _T("IMAGE\\Pause.png"), 100, 100);
					transparentimage(NULL, 1150, 60, &tmp, BLACK);
					EndBatchDraw();

					break;
				}
			}
		}

	};


	void showMap()
	{
		IMAGE image(1280, 960);
		//IMAGE img1;
		loadimage(&image, _T("res\\map.jpg"), 1280, 560);
		putimage(0, 200, &image);
	}


	void AddButtoms(int SoundOn) {
		IMAGE bot1(100, 100), bot2(100, 100);



		if (SoundOn == 1)
			loadimage(&bot1, _T("res\\SoundOn.png"), 100, 100);
		else
			loadimage(&bot1, _T("res\\SoundOff.png"), 100, 100);

		transparentimage(NULL, 1000, 60, &bot1, BLACK);				//设置声音开关按钮


		loadimage(&bot2, _T("res\\Pause.png"), 100, 100);
		transparentimage(NULL, 1150, 60, &bot2, BLACK);				//设置暂停按钮
	}

	void AddUp() {
		IMAGE a(641, 200);
		loadimage(&a, _T("res\\map1.jpg"), 641, 200);
		putimage(0, 0, &a);
		putimage(640, 0, &a);
	}

	void AddClock(int time) {
		IMAGE a(400, 90), b(140, 140);

		loadimage(&a, _T("res\\Clockbg.png"), 400, 90);
		transparentimage(NULL, 480, 70, &a, BLACK);				//放置时间背景色

		loadimage(&b, _T("res\\Clock1.png"), 140, 140);
		transparentimage(NULL, 420, 40, &b, BLACK);				//放置时钟图案

		int min = time / 60, sec = time % 60;
		TCHAR Tmin[10], Tsec[10];
		_itot_s(min, Tmin, 10);
		_itot_s(sec, Tsec, 10);
		RECT x = { 500,50,680,170 };
		RECT y = { 680,37,720,170 };
		RECT z = { 720,50,900,170 };
		settextstyle(80, 60, _T("行书"));
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		drawtext(Tmin, &x, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
		drawtext(_T(":"), &y, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(Tsec, &z, DT_LEFT | DT_VCENTER | DT_SINGLELINE);//显示时间
	}

	void ShowCoin(int Money) {
		IMAGE a(240, 60), b(80, 80);

		loadimage(&a, _T("res\\Coinbg.png"), 240, 60);
		transparentimage(NULL, 80, 20, &a, BLACK);				//放置金币背景色

		loadimage(&b, _T("res\\Coin.png"), 80, 80);
		transparentimage(NULL, 50, 10, &b, BLACK);				//放置金币图案

		TCHAR Tstr[10];
		_itot_s(Money, Tstr, 10);
		RECT x = { 120,12,320,82 };
		settextstyle(48, 36, _T("楷书"));
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		drawtext(Tstr, &x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//显示金币数
	}

	void ShowScore(int Score) {
		IMAGE a(240, 60), b(80, 80);

		loadimage(&a, _T("res\\Coinbg.png"), 240, 60);
		transparentimage(NULL, 80, 110, &a, BLACK);				//放置背景色

		loadimage(&b, _T("res\\Score.png"), 80, 80);
		transparentimage(NULL, 45, 100, &b, BLACK);				//放置图案

		TCHAR Tstr[10];
		_itot_s(Score, Tstr, 10);
		RECT x = { 120,102,320,172 };
		settextstyle(48, 36, _T("楷书"));
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		drawtext(Tstr, &x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//显示分数
	}

	void ShowStore() {

		IMAGE a(641, 200);
		loadimage(&a, _T("res\\map1.jpg"), 641, 200);
		putimage(0, 760, &a);
		putimage(640, 760, &a);      //显示商店背景

		IMAGE bot1(150, 150), bot2(150, 60);

		loadimage(&bot1, _T("res\\Store.png"), 150, 150);
		transparentimage(NULL, 105, 785, &bot1, BLACK);
		transparentimage(NULL, 335, 785, &bot1, BLACK);
		transparentimage(NULL, 565, 785, &bot1, BLACK);
		transparentimage(NULL, 795, 785, &bot1, BLACK);			//设置塔按钮

		loadimage(&bot2, _T("res\\Store.png"), 150, 60);
		transparentimage(NULL, 1025, 785, &bot2, BLACK);
		transparentimage(NULL, 1025, 875, &bot2, BLACK);        //设置升级、出售按钮


		IMAGE tow1(120, 120), tow2(120, 120), tow3(120, 120), tow4(120, 120);
		loadimage(&tow1, _T("res\\tow1-1.png"), 120, 120);
		loadimage(&tow2, _T("res\\tow2-1.png"), 120, 120);
		loadimage(&tow3, _T("res\\tow3-1.png"), 120, 120);
		loadimage(&tow4, _T("res\\tow4-1.png"), 120, 120);
		transparentimage(NULL, 120, 800, &tow1, BLACK);
		transparentimage(NULL, 350, 800, &tow2, BLACK);
		transparentimage(NULL, 580, 800, &tow3, BLACK);
		transparentimage(NULL, 810, 800, &tow4, BLACK);			//放置塔贴图

		RECT LevelUp = { 1025, 785, 1175, 845 };
		RECT Sell = { 1025, 875, 1175, 935 };
		settextstyle(40, 30, _T("楷体"));
		settextcolor(YELLOW);
		setbkmode(TRANSPARENT);
		drawtext(_T("升级"), &LevelUp, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		drawtext(_T("出售"), &Sell, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	}

	void ShouLuoboBlood(int luobo_blood)
	{
		TCHAR Tstr[10];
		_itot_s(luobo_blood, Tstr, 10);
		settextstyle(48, 36, _T("楷书"));
		settextcolor(RED);
		outtextxy(1180, 274, Tstr);
	}

	void ShowUp(int Money, int time, int score) {
		showMap();
		AddUp();
		ShowStore();
		ShowCoin(Money);
		AddClock(time);
		AddButtoms(ifsound);
		ShowScore(score);

	}




};

