#include "manager.h"
using namespace std;
/*�������Ϣ*/
Manager::Manager(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Manager::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ܲý��������񣬲��·������Ա��" << endl;
}
string Manager::getDeptName()
{
	return string("����");
}