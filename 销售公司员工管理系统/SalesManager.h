#pragma once
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include "Staff.h";

//�ϰ���
class SalesManager :public Staff
{
public:
	//���캯��
	SalesManager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λְ������
	virtual string getDeptName();
};
