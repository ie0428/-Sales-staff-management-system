#pragma once
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "Staff.h";

//������
class Manager :public Staff
{
public:
	//���캯��
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λְ������
	virtual string getDeptName();
};
