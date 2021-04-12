#include "manager.h"
using namespace std;
/*经理的信息*/
Manager::Manager(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Manager::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成总裁交给的任务，并下发任务给员工" << endl;
}
string Manager::getDeptName()
{
	return string("经理");
}