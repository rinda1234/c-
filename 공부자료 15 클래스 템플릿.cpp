// �����迭 Ŭ������ ���� ���� ����ü, Ŭ������ �����ϰ� ������ int Ÿ�����δ� �翬�� �ȵ�. 
// ������ Ŭ������ �� Ÿ�Կ� �°� ������ ������ ������ ���ø����� �ѹ��� ���� �� ����. 
#include<iostream>
#include "TArr.h"
#include "TLinkedList.h"
int main()
{
	CArr<int> carr; // �̷������� �ڷ����� �˷������. 

	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	CArr<float> farr; // �ٸ� �������� ��������. 

	farr.push_back(10);
	farr.push_back(20);
	farr.push_back(30);

	CArr<CArr<int>> caarr; // �ٸ� �������� ��������. 

	caarr.push_back(carr);

	// ����Ʈ ���ø�
	CList<float> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	return 0;
}