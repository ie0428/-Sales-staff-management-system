#include"SalesManager.h"
SalesManager::SalesManager(int id, string name, int did)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void SalesManager::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< endl;
}

string SalesManager::getDeptName()
{
	return string("���۾���");
}