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
	//显示个人信息
	virtual void showInfo();	//具体的由具体员工实现
	//获取岗位名称
	virtual string getDeptName();
	~Employee();

};