#include "employee.h"
using namespace std;
/*普通员工的信息*/
Employee::Employee(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Employee::showInfo()
{
	cout << "职工编号： " << this->m_Id
		<< " \t职工姓名： " << this->m_Name
		<< " \t岗位：" << this->getDeptName()
		<< " \t岗位职责：完成经理交给的任务" << endl;
}
string Employee::getDeptName()
{
	return string("员工");
}
Employee::~Employee()
{

}
