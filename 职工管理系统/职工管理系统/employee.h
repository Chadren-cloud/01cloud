#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int Id, string name, int depId);
	//��ʾ������Ϣ
	virtual void showInfo();	//������ɾ���Ա��ʵ��
	//��ȡ��λ����
	virtual string getDeptName();
	~Employee();

};