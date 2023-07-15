#pragma once
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include<iostream>
#include"Monster_illustrated.h"
#include"Monster_kind.h"
#include"Ima.h"
#include"TowerPage.h"


#include <mmsystem.h>
#include<iostream>
using namespace std;
#pragma comment (lib,"winmm.lib")



void Menu();		//主页面
void ClickMenu();

void StartGame();	//开始游戏

void Book();		//图鉴
void ClickBook();

void Book1();		//塔图鉴

void Book2();		//怪物图鉴

void Sets();		//设置

void Exit();		//退出