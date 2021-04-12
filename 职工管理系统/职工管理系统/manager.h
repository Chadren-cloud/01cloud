#pragma once
#include <iostream>
#include "workerManager.h"
#include "worker.h"
using namespace std;

class Manager:public Worker	//定义一个抽象职工类
{
public:
	Manager(int Id, string name, int depId);
	//显示个人信息
	virtual void showInfo();	//具体的由具体员工实现
	//获取岗位名称
	virtual string getDeptName();
};