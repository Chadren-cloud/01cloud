#include "boss.h"
using namespace std;
/*�ܲõ���Ϣ*/
Boss::Boss(int Id, string name, int depId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = depId;
}

void Boss::showInfo()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ�𣺹���˾���񣬲��´����������" << endl;
}
string Boss::getDeptName()
{
	return string("�ܲ�");
}
