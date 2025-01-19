#include"workerManager.h"

WorkerManager::WorkerManager()
{
		
		ifstream ifs;
		ifs.open(FILENAME, ios::in);//读文件

		//1.文件不存在
		if (!ifs.is_open())
		{
			//cout << "文件不存在" << endl;//测试输出
			//初始化属性
			this->m_EmpNum = 0;//初始化人数
			this->m_FileIsEmpty = true;//初始化文件为空标志
			this->m_EmpArray = NULL;//初始化数组
			ifs.close();//关闭文件
			return;
		}
		//2.文件存在，并且没有记录
		
		char ch;
		ifs >> ch;//判断文件
		if (ifs.eof())
		{
			//cout << "文件为空" << endl;//测试输出
			//初始化属性
			this->m_EmpNum = 0;//初始化人数
			this->m_FileIsEmpty = true;//初始化文件为空标志
			this->m_EmpArray = NULL;//初始化数组
			ifs.close();//关闭文件
			return;
		}


		//3.文件存在，并且记录数据
		//获取职工个数
		int num = this->get_EmpNum();
		//cout << "职工人数为：" << num << endl;
		this->m_EmpNum = num;
		//根据职工创建数组 开辟空间
		this->m_EmpArray = new Staff * [this->m_EmpNum];
		//初始化职工  将文件中的数据，存到数组中
		 this->init_Emp();

		 //测试代码
		 /*for (int i = 0; i < m_EmpNum; i++)
		 {
			 cout << "职工号： " << this->m_EmpArray[i]->m_Id
				 << " 职工姓名： " << this->m_EmpArray[i]->m_Name
				 << " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
		 }*/
}




//统计员工人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数变量
		num++;
	}
	ifs.close();

	return num;
}


//初始化数组
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Staff* worker = NULL;
		//根据不同部门ID创建不同对象
		if (did == 1)//1.普通员工
		{
			worker = new Salesman(id, name, did);
		}
		else if (did == 2)//2.经理
		{
			worker = new Manager(id, name, did);
		}
		else//3.老板
		{
			worker = new SalesManager(id, name, did);
		}
		//存放在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}
//展示菜单
void WorkerManager::show_menu()
{
	cout << "**************************************" << endl;
	cout << "***欢迎使用销售公司员工管理系统!****" << endl;
	cout << "***********0.退出管理程序*************" << endl;
	cout << "***********1.增加职工信息*************" << endl;
	cout << "***********2.显示职工信息*************" << endl;
	cout << "***********3.删除职工信息*************" << endl;
	cout << "***********4.修改职工信息*************" << endl;
	cout << "***********5.查找职工信息*************" << endl;
	cout << "***********6.清空所有文档*************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入要添加职工的数量：" << endl;

	int addNum = 0;//保存用户的输入数量
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		//计算添加新的空间大小
		int newSize = this->m_EmpNum + addNum;//新空间人数=原来记录人数+新增人数

		//开辟新空间
		Staff** newSpace = new Staff * [newSize];

		//将原来空间下数据拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;

			cout << "请选择该职工的岗位" << endl;
			cout << "1.销售员" << endl;
			cout << "2.经理" << endl;
			cout << "3.销售经理" << endl;
			cin >> dSelect;

			Staff* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Salesman(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker=new SalesManager(id, name, 2);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[]this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		

		//成功添加后 保存到文件中
		this->save();

		//提示信息
		cout << "成功添加" << addNum << "名新职工" << endl;

		//更新职工不为空标志
		this->m_FileIsEmpty = false;
	}
	

	else
	{
		cout << "输入数据有误" << endl;
	}

	//按任意键后，清屏回到上级目录 
	system("pause");
	system("cls");
}

//更新文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件--写文件

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//关闭文件
	ofs.close();
}

//显示职工
void WorkerManager::Show_Emp()
{
	//判断文件是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}


//判断职工是否存在
	//按照职工编号判断职工是否存在,若存在返回职工在数组中位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i <this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;

			break;
		}
	}
	return index;
}


//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工编号" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//说明index上位置数据需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();//删除后同步数据到文件
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}

	system("pause");
	system("cls");
}


//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)//判断文件是否存在
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);//先查询职工是否存在

		if (ret != -1)
		{
			//查找到职工
			delete this->m_EmpArray[ret];//删除原有的职工编号

			//定义新职工
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、销售员" << endl;
			cout << "2、经理" << endl;
			cout << "3、销售经理" << endl;
			cin >> dSelect;

			Staff* worker = NULL;//创建新的职工空间
			switch (dSelect)
			{
			case1:
				worker = new Salesman(newId, newName, dSelect);
				break;
			case2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new SalesManager(newId, newName, dSelect);
				break;
			default:
				break;
			}
			
			//更改数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
		
	}
	//按任意键 清屏
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为："
						<< m_EmpArray[i]->m_Id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}


WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

