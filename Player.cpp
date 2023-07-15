#include"Player.h"

Player::Player()
{
	;
}

Player::~Player()
{
	;
}

void Player::SetName()
{
	initgraph(640, 480);
	wchar_t s[20];
	InputBox(s, 10, L"请输入新名称：");
//	Name = wto;
}

void Player::SetLevel()
{
	wchar_t s[20];
	InputBox(s, 10, L"请输入新等级：");
	int x = _wtoi(s);
	Level = x;
}

void Player::SetMoney()
{

	wchar_t s[20];
	InputBox(s, 10, L"请输入新金币数：");
	int x = _wtoi(s);
	Money = x;
}

void Player::SetRecord()
{

	wchar_t s[20];
	InputBox(s, 10, L"请输入新的记录：");
	int x = _wtoi(s);
	Record = x;
}

string Player::GetName()
{
	return Name;
}

int Player::GetLevel()
{
	return Level;
}

int Player::GetMoney()
{
	return Money;
}

int Player::GetRecord()
{
	return Record;
}