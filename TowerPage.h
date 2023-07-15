#pragma once
#include <graphics.h>
#include <conio.h>
#include<iostream>

using namespace std;

class TowerPage {
	private:
		TCHAR* Ima = new TCHAR[20];
		TCHAR* Name = new TCHAR[20];
		int Attack;
		int Range;
		int UpCost;
		int Sell;
	public:
		TowerPage(TCHAR* ima, TCHAR* name, int a, int r, int u, int s);
		void ShowPage();
};