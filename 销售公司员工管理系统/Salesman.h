#pragma once
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "Staff.h";

//员工类
class Salesman :public Staff
{
public:
	//构造函数
	Salesman(int id, string name, int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位职工名称
	virtual string getDeptName();
};

