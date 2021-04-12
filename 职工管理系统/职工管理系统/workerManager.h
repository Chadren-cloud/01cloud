#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "worker.h"
#include <fstream>
using namespace std;

#define FILENAME "WorkerInfo_chart.txt"
class Workermanager
{
public:
	Workermanager();
	void Show_menu();
	void exitSystem();
	void Addemp();
	void Show_worker_Info();
	void save();
	int Isexist(int id);
	int Getworker_num();
	void Delworker();
	void Mod_worker();
	void Find_worker();
	void Sort_worker();
	void Clc_worker();
	int m_EmpNum;
	void Init_worker();
	bool m_Empfile;
	Worker ** m_EmpArray;
	~Workermanager();
};