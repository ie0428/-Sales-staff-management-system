#include <iostream>
#include"workerManager.h"
using namespace std;

int main()
{
	//实例化管理者对象
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		//调用展示菜单成员函数
		wm.show_menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;//退出系统
		case 1:
			wm.Add_Emp();
			break;//添加职工

		case 2:
			wm.Show_Emp();
			break;//显示职工
		case 3:
			wm.Del_Emp();
			break;//删除职工
		case 4:
			wm.Mod_Emp();
			break;//修改职工
		case 5:
			wm.Find_Emp();
			break;//查找职工
		case 6:
			wm.Clean_File();
			break;//清空文件
		default:
			cout << "输入有误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}