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
	//���캯��
	Monster_illustrated();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//��¼��������
	int kind_num;

	//��������ָ��
	Monster_kind** array;

	//��ӹ���
	void Add();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool FileIsEmpty;

	//ͳ���ļ��й�������
	int get_kindnum();

	//��ʼ������
	void init();

	//ɾ������
	void Delete();

	//�жϹ����Ƿ����
	int IsExist(int id);

	//�޸Ĺ���
	void Mod_Mon();

	//����ļ�
	void Clean_File();

	//��������
	~Monster_illustrated();
};