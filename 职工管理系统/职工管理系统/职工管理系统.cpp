#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

int main()
{
	Workermanager wm;
	int choice = 0;
#if(0)
	Worker* worker = new Employee(1, "Tom", 1);;
	worker->showInfo();
	delete worker;
	worker = new Manager(2, "Tom", 2);;
	worker->showInfo();
	delete worker;
	worker = new Boss(2, "Tom", 2);;
	worker->showInfo();
	delete worker;
#endif
	while (true)
	{
		wm.Show_menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.Addemp();
			break;
		case 2:
			wm.Show_worker_Info();
			break;
		case 3:
			wm.Delworker();
			break;
		case 4:
			wm.Mod_worker();
			break;
		case 5:
			wm.Find_worker();
			break;
		case 6:
			wm.Sort_worker();
			break;
		case 7:
			wm.Clc_worker();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}