#include"Salesman.h"
Salesman::Salesman(int id, string name, int did)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Salesman::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< endl;
}

string Salesman::getDeptName()
{
	return string("����Ա��");
}