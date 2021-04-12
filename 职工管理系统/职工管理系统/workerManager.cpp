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
	/*文件不存在*/
	if (!ifs.is_open())
	{
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_Empfile = true;
		cout << "文件不存在 请重试！" << endl;
		cout << "==========================================" << endl;
		ifs.close();
		return;
	}
	/*文件存在，但数据为空*/
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件存在，无数据!" << endl;
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
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
void Workermanager::exitSystem()
{
	cout << "欢迎下次再次使用" << endl;
	system("pause");
	exit(0);
}
void Workermanager::Addemp()
{
	cout << "请输入添加的员工数量" << endl;
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
		//输入新数据
		for (int i = 0; i < addEmp; i++)
		{
			int id;
			string name;
			int sid;
			cout << "请输入职工编号：" << endl;
			cin >> id;

			cout << "请输入职工姓名：" << endl;
			cin >> name;

			cout << "请输入职工岗位编号：" << endl;
			cout << "1、普通员工 " << endl;
			cout << "2、经理 " << endl;
			cout << "3、总裁 " << endl;
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

		cout << "已将" << addEmp << "个新职工加入到该系统" << endl;
		this->m_Empfile = false;
		this->save();
		system("pause");
		system("cls");

	}
	else
	{
		cout << "用户输入有误" << endl;
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
		cout << "文件为空，暂无职工信息！" << endl;
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
		cout << "文件不存在或者记录为空！" << endl;
		return;
	}
	else
	{
		int index = 0;
		int tem_Id;
		cout << "请输入您要删除的职工编号" << endl;
		cin >> tem_Id;
		int ret=this->Isexist(tem_Id);
		if (ret < 0)
		{
			cout << "职工不存在，输入有误，请重新输入" << endl;
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
		cout << "删除成功" << endl;
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
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	else
	{
		cout << "请输入您要更改职工的职工编号" << endl;
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

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newid;

			cout << "请输入新职工的姓名" << endl;
			cin >> name;

			cout << "请输入新职工的部门编号" << endl;
			cout << "1、普通员工 " << endl;
			cout << "2、经理 " << endl;
			cout << "3、总裁 " << endl;
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
			cout << "修改成功！" << endl;
			this->save();
		}
		else
		{
			cout << "该职工不存在，请重新输入" << endl;
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
		cout << "文件不存在或者记录为空" << endl;
		return;
	}
	else
	{
		int select = 0;
		cout << "请选择排序方式" << endl;
		cout << "1、升序" << endl;
		cout << "2、降序" << endl;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum ; i++)
		{
			for (int j = 0; j < this->m_EmpNum-1-i; j++)
			{
				/*升序*/
				if (1 == select)
				{
					if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
					{
						worker = this->m_EmpArray[j + 1];
						this->m_EmpArray[j + 1] = this->m_EmpArray[j];
						this->m_EmpArray[j] = worker;
					}
				}
				/*降序*/
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
		cout << "排序完成!" << endl;
		cout << "==================================================================" << endl;
		this->save();
		this->Show_worker_Info();
	}
}
void Workermanager::Clc_worker()
{
	int select = 0;
	cout << "是否确定要删除系统所有职工信息" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	cin >> select;
	switch (select)
	{
	case 1:
	{
		if (this->m_Empfile)
		{
			cout << "删除失败，文件不存在或者记录为空" << endl;
			return;
		}
		else
		{
			for (int i = 0; i < this->m_EmpNum ; i++)
			{
				delete this->m_EmpArray[i];
			}
			delete[] this->m_EmpArray;
			cout << "删除成功！" << endl;
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
		cout << "输入有误！" << endl;
		break;
	}

}
void Workermanager::Find_worker()
{
	if (this->m_Empfile)
	{
		cout << "文件不存在或者记录为空" << endl;
	}
	cout << "请输入您要查找的方式" << endl;
	cout << "1、按照编号查找 " << endl;
	cout << "2、按照姓名查找 " << endl;
	int select = 0;
	cin >> select;
	/*编号查找*/
	if (1 == select)
	{
		cout << "请输入您要查找的职工编号 " << endl;
		int Id = 0;
		int ret = 0;
		cin >> Id;
		if ((ret = this->Isexist(Id)) != -1)
		{
			this->m_EmpArray[ret]->showInfo();
		}
		else
		{
			cout << "查找失败，职工系统无此人！" << endl;
		}
	}
	/*按照姓名查找*/
	else if (2 == select)
	{
		cout << "请输入您要查找的职工姓名 " << endl;
		string name = "";
		cout << "请输入您要查找的职工姓名" << endl;
		cin >> name;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				cout << "查找成功  查找的信息如下：" << endl;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		cout << "查找失败 职工系统并无此人" << endl;
	}
	else
	{
		cout << "输入有误！" << endl;
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