#pragma once
#include"Monster_kind.h"
#include<iostream>
#include<graphics.h>
#include<string>
#include<fstream>
#define FILENAME "MonFile.txt"
using namespace std;

class Monster_illustrated
{
public:
	//构造函数
	Monster_illustrated();

	//展示菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//记录怪物种类
	int kind_num;

	//怪物数组指针
	Monster_kind** array;

	//添加怪物
	void Add();

	//保存文件
	void save();

	//判断文件是否为空
	bool FileIsEmpty;

	//统计文件中怪物种类
	int get_kindnum();

	//初始化怪物
	void init();

	//删除怪物
	void Delete();

	//判断怪物是否存在
	int IsExist(int id);

	//修改怪物
	void Mod_Mon();

	//清空文件
	void Clean_File();

	//析构函数
	~Monster_illustrated();
};