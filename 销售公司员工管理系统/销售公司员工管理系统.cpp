#include <iostream>
#include"workerManager.h"
using namespace std;

int main()
{
	//ʵ���������߶���
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		//����չʾ�˵���Ա����
		wm.show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;//�˳�ϵͳ
		case 1:
			wm.Add_Emp();
			break;//���ְ��

		case 2:
			wm.Show_Emp();
			break;//��ʾְ��
		case 3:
			wm.Del_Emp();
			break;//ɾ��ְ��
		case 4:
			wm.Mod_Emp();
			break;//�޸�ְ��
		case 5:
			wm.Find_Emp();
			break;//����ְ��
		case 6:
			wm.Clean_File();
			break;//����ļ�
		default:
			cout << "������������������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}