#include"Salesman.h"
Salesman::Salesman(int id, string name, int did)
{
	this->m_Id = id;
	this->m_DeptId = did;
	this->m_Name = name;
}

void Salesman::showInfo()
{
	cout << "职工编号:" << this->m_Id
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< endl;
}

string Salesman::getDeptName()
{
	return string("销售员工");
}