#pragma once
#include<iostream>
#include<string>
#include<graphics.h>
#include <conio.h>

#include"Ima.h"
using namespace std;

class Player
{
	friend class Monstergame;
public:
	Player();
	~Player();
	void SetName();
	void SetLevel();
	void SetMoney();
	void SetRecord();
	string GetName();
	int GetLevel();
	int GetMoney();
	int GetRecord();
private:
	string Name;
	int Score;
	int Level;
	int Money;
	int Record;
};
