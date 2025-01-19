#include"workerManager.h"

WorkerManager::WorkerManager()
{
		
		ifstream ifs;
		ifs.open(FILENAME, ios::in);//���ļ�

		//1.�ļ�������
		if (!ifs.is_open())
		{
			//cout << "�ļ�������" << endl;//�������
			//��ʼ������
			this->m_EmpNum = 0;//��ʼ������
			this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
			this->m_EmpArray = NULL;//��ʼ������
			ifs.close();//�ر��ļ�
			return;
		}
		//2.�ļ����ڣ�����û�м�¼
		
		char ch;
		ifs >> ch;//�ж��ļ�
		if (ifs.eof())
		{
			//cout << "�ļ�Ϊ��" << endl;//�������
			//��ʼ������
			this->m_EmpNum = 0;//��ʼ������
			this->m_FileIsEmpty = true;//��ʼ���ļ�Ϊ�ձ�־
			this->m_EmpArray = NULL;//��ʼ������
			ifs.close();//�ر��ļ�
			return;
		}


		//3.�ļ����ڣ����Ҽ�¼����
		//��ȡְ������
		int num = this->get_EmpNum();
		//cout << "ְ������Ϊ��" << num << endl;
		this->m_EmpNum = num;
		//����ְ���������� ���ٿռ�
		this->m_EmpArray = new Staff * [this->m_EmpNum];
		//��ʼ��ְ��  ���ļ��е����ݣ��浽������
		 this->init_Emp();

		 //���Դ���
		 /*for (int i = 0; i < m_EmpNum; i++)
		 {
			 cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
				 << " ְ�������� " << this->m_EmpArray[i]->m_Name
				 << " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
		 }*/
}




//ͳ��Ա������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int did;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//ͳ����������
		num++;
	}
	ifs.close();

	return num;
}


//��ʼ������
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	int id;
	string name;
	int did;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Staff* worker = NULL;
		//���ݲ�ͬ����ID������ͬ����
		if (did == 1)//1.��ͨԱ��
		{
			worker = new Salesman(id, name, did);
		}
		else if (did == 2)//2.����
		{
			worker = new Manager(id, name, did);
		}
		else//3.�ϰ�
		{
			worker = new SalesManager(id, name, did);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}
}
//չʾ�˵�
void WorkerManager::show_menu()
{
	cout << "**************************************" << endl;
	cout << "***��ӭʹ�����۹�˾Ա������ϵͳ!****" << endl;
	cout << "***********0.�˳��������*************" << endl;
	cout << "***********1.����ְ����Ϣ*************" << endl;
	cout << "***********2.��ʾְ����Ϣ*************" << endl;
	cout << "***********3.ɾ��ְ����Ϣ*************" << endl;
	cout << "***********4.�޸�ְ����Ϣ*************" << endl;
	cout << "***********5.����ְ����Ϣ*************" << endl;
	cout << "***********6.��������ĵ�*************" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "������Ҫ���ְ����������" << endl;

	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		//��������µĿռ��С
		int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ����¼����+��������

		//�����¿ռ�
		Staff** newSpace = new Staff * [newSize];

		//��ԭ���ռ������ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1.����Ա" << endl;
			cout << "2.����" << endl;
			cout << "3.���۾���" << endl;
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
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[]this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		

		//�ɹ���Ӻ� ���浽�ļ���
		this->save();

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;
	}
	

	else
	{
		cout << "������������" << endl;
	}

	//��������������ص��ϼ�Ŀ¼ 
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ�--д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�ر��ļ�
	ofs.close();
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}


//�ж�ְ���Ƿ����
	//����ְ������ж�ְ���Ƿ����,�����ڷ���ְ����������λ�ã������ڷ���-1
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


//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ�����" << endl;
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		if (index != -1)//˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;

			this->save();//ɾ����ͬ�����ݵ��ļ�
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}

	system("pause");
	system("cls");
}


//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)//�ж��ļ��Ƿ����
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);//�Ȳ�ѯְ���Ƿ����

		if (ret != -1)
		{
			//���ҵ�ְ��
			delete this->m_EmpArray[ret];//ɾ��ԭ�е�ְ�����

			//������ְ��
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1������Ա" << endl;
			cout << "2������" << endl;
			cout << "3�����۾���" << endl;
			cin >> dSelect;

			Staff* worker = NULL;//�����µ�ְ���ռ�
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
			
			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
		
	}
	//������� ����
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_EmpArray[i]->m_Id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
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
		cout << "��ճɹ���" << endl;
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

