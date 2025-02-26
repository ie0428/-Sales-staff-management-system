#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间
#include "Staff.h"
#include"Salesman.h"
#include"SalesManager.h"
#include"manager.h"
#include<fstream>
#define FILENAME "staff.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void show_menu();

	//退出系统
	void exitSystem();

	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	Staff** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空 标志
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();


	//判断职工是否存在
	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
	int IsExist(int id);

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//清空文件
	void Clean_File();

    //析构函数
	~WorkerManager();
};


