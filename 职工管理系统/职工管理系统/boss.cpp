#include "boss.h"
using namespace std;
/*总裁的信息*/
Boss::Boss(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Boss::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：管理公司事务，并下达任务给经理" << endl;
}
string Boss::getDeptName()
{
	return string("总裁");
}
