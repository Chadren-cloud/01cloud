#pragma once
#include <iostream>
#include "workerManager.h"
#include "worker.h"
using namespace std;

class Manager:public Worker	//����һ������ְ����
{
public:
	Manager(int Id, string name, int depId);
	//��ʾ������Ϣ
	virtual void showInfo();	//������ɾ���Ա��ʵ��
	//��ȡ��λ����
	virtual string getDeptName();
};