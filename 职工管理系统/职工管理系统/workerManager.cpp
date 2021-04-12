#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
using namespace std;
Workermanager::Workermanager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	/*�ļ�������*/
	if (!ifs.is_open())
	{
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_Empfile = true;
		cout << "�ļ������� �����ԣ�" << endl;
		cout << "==========================================" << endl;
		ifs.close();
		return;
	}
	/*�ļ����ڣ�������Ϊ��*/
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ����ڣ�������!" << endl;
		cout << "==========================================" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_Empfile = true;
		ifs.close();
		return;
	}
	int num = this->Getworker_num();
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker*[this->m_EmpNum];
	this->Init_worker();
}
void Workermanager::Show_menu()
{
	system("cls");
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void Workermanager::exitSystem()
{
	cout << "��ӭ�´��ٴ�ʹ��" << endl;
	system("pause");
	exit(0);
}
void Workermanager::Addemp()
{
	cout << "��������ӵ�Ա������" << endl;
	int addEmp = 0;
	cin >> addEmp;
	if (addEmp > 0)
	{
		int newsize = this->m_EmpNum + addEmp;
		Worker **newarr = NULL;
		newarr = new Worker*[newsize];
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newarr[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addEmp; i++)
		{
			int id;
			string name;
			int sid;
			cout << "������ְ����ţ�" << endl;
			cin >> id;

			cout << "������ְ��������" << endl;
			cin >> name;

			cout << "������ְ����λ��ţ�" << endl;
			cout << "1����ͨԱ�� " << endl;
			cout << "2������ " << endl;
			cout << "3���ܲ� " << endl;
			cin >> sid;

			Worker* worker = NULL;
			switch (sid)
			{
			case 1:
				worker = new Employee(id, name, sid);
			case 2:
				worker = new Manager(id, name, sid);
			case 3:
				worker = new Boss(id, name, sid);
			default:
				break;
			}
			newarr[this->m_EmpNum + i] = worker;
			
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newarr;
		this->m_EmpNum = newsize;

		cout << "�ѽ�" << addEmp << "����ְ�����뵽��ϵͳ" << endl;
		this->m_Empfile = false;
		this->save();
		system("pause");
		system("cls");

	}
	else
	{
		cout << "�û���������" << endl;
		system("pause");
		system("cls");
	}
}
void Workermanager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum ; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}
int Workermanager::Getworker_num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	int Id;
	string name;
	int sId;
	while (ifs >> Id&&ifs >> name&&ifs >> sId)
	{
		num++;
	}
	return num;

}
void Workermanager::Show_worker_Info()
{
	if (this->m_Empfile)
	{
		cout << "�ļ�Ϊ�գ�����ְ����Ϣ��" << endl;
	}
	for (int i = 0; i < this->m_EmpNum ; i++)
	{
		this->m_EmpArray[i]->showInfo();
		cout << "---------------------------------------";
		cout << "------------------------------------------";
		cout << "---------------------------" << endl;
	}
	system("pause");
	system("cls");
}
void Workermanager::Delworker()
{
	if (this->m_Empfile)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		return;
	}
	else
	{
		int index = 0;
		int tem_Id;
		cout << "��������Ҫɾ����ְ�����" << endl;
		cin >> tem_Id;
		int ret=this->Isexist(tem_Id);
		if (ret < 0)
		{
			cout << "ְ�������ڣ�������������������" << endl;
			system("pause");
			system("cls");
		}

		while (tem_Id != (this->m_EmpArray[index]->m_Id))
		{
			index++;
		}

		for (int i = index; i < this->m_EmpNum-1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpArray[this->m_EmpNum-1] = NULL;
		cout << "ɾ���ɹ�" << endl;
		this->m_EmpNum--;
		this->save();
		system("pause");
		system("cls");
	}
}
int Workermanager::Isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum ; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void Workermanager::Init_worker()
{
	fstream ifs;
	ifs.open(FILENAME, ios::in);
	int Id;
	string name;
	int sId;
	int flag = 0;
	Worker* worker = NULL;
	while (ifs >> Id&&ifs >> name&&ifs >> sId)
	{
		if (1 == sId)
		{
			worker=new Employee(Id, name, sId);
		}
		else if (2 == sId)
		{
			worker = new Manager(Id, name, sId);
		}
		else
		{
			worker = new Boss(Id, name, sId);
		}
		this->m_EmpArray[flag++] = worker;
	}
}
void Workermanager::Mod_worker()
{
	if (this->m_Empfile)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	else
	{
		cout << "��������Ҫ����ְ����ְ�����" << endl;
		int id = 0;
		int ret;
		cin >> id;
		Worker* worker = NULL;
		if ((ret=this->Isexist(id)) != -1)
		{
			int newid = 0;
			string name = "";
			int sId = 0;
			delete this->m_EmpArray[ret];
			this->m_EmpArray[ret] = NULL;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newid;

			cout << "��������ְ��������" << endl;
			cin >> name;

			cout << "��������ְ���Ĳ��ű��" << endl;
			cout << "1����ͨԱ�� " << endl;
			cout << "2������ " << endl;
			cout << "3���ܲ� " << endl;
			cin >> sId;

			switch (sId)
			{
			case 1:
				worker = new Employee(newid, name, sId);
				break;
			case 2:
				worker = new Manager(newid, name, sId);
				break;
			case 3:
				worker = new Boss(newid, name, sId);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" << endl;
			this->save();
		}
		else
		{
			cout << "��ְ�������ڣ�����������" << endl;
		}
		system("pause");
		system("cls");
	}

}
void Workermanager::Sort_worker()
{
	Worker* worker = NULL;
	if (this->m_Empfile)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
		return;
	}
	else
	{
		int select = 0;
		cout << "��ѡ������ʽ" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum ; i++)
		{
			for (int j = 0; j < this->m_EmpNum-1-i; j++)
			{
				/*����*/
				if (1 == select)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = this->m_EmpArray[j];
						this->m_EmpArray[j] = worker;
					}
				}
				/*����*/
				else if (2 == select)
				{
					if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j];
						this->m_EmpArray[j] = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = worker;
					}
				}
			}
		}
		cout << "�������!" << endl;
		cout << "==================================================================" << endl;
		this->save();
		this->Show_worker_Info();
	}
}
void Workermanager::Clc_worker()
{
	int select = 0;
	cout << "�Ƿ�ȷ��Ҫɾ��ϵͳ����ְ����Ϣ" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		if (this->m_Empfile)
		{
			cout << "ɾ��ʧ�ܣ��ļ������ڻ��߼�¼Ϊ��" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < this->m_EmpNum ; i++)
			{
				delete this->m_EmpArray[i];
			}
			delete[] this->m_EmpArray;
			cout << "ɾ���ɹ���" << endl;
			this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			this->m_Empfile = true;
			system("pause");
			system("cls");
		}
	}
		break;
	case 2:
		return;
	default:
		cout << "��������" << endl;
		break;
	}

}
void Workermanager::Find_worker()
{
	if (this->m_Empfile)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	cout << "��������Ҫ���ҵķ�ʽ" << endl;
	cout << "1�����ձ�Ų��� " << endl;
	cout << "2�������������� " << endl;
	int select = 0;
	cin >> select;
	/*��Ų���*/
	if (1 == select)
	{
		cout << "��������Ҫ���ҵ�ְ����� " << endl;
		int Id = 0;
		int ret = 0;
		cin >> Id;
		if ((ret = this->Isexist(Id)) != -1)
		{
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "����ʧ�ܣ�ְ��ϵͳ�޴��ˣ�" << endl;
		}
	}
	/*������������*/
	else if (2 == select)
	{
		cout << "��������Ҫ���ҵ�ְ������ " << endl;
		string name = "";
		cout << "��������Ҫ���ҵ�ְ������" << endl;
		cin >> name;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				cout << "���ҳɹ�  ���ҵ���Ϣ���£�" << endl;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		cout << "����ʧ�� ְ��ϵͳ���޴���" << endl;
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
Workermanager::~Workermanager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}