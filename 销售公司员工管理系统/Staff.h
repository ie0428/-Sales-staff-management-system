#pragma once

#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�

class Staff
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ڲ������Ʊ��
};
