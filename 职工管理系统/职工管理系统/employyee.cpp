#include "employee.h"
using namespace std;
/*��ͨԱ������Ϣ*/
Employee::Employee(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Employee::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}
string Employee::getDeptName()
{
	return string("Ա��");
}
Employee::~Employee()
{

}
