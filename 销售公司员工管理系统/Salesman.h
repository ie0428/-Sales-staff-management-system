#pragma once
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "Staff.h";

//Ա����
class Salesman :public Staff
{
public:
	//���캯��
	Salesman(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λְ������
	virtual string getDeptName();
};

