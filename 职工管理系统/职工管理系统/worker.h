#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Worker	//����һ������ְ����
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;	//������ɾ���Ա��ʵ��
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ������Ʊ��
};