#include "func.h"
#include "common.h"
#include<iostream>
//���⿡ �Լ�����. 

//�������� ��� ����
static int g_iStatic = 0; // �ٸ� ���Ͽ��� �� �̸��� ������ �����Ǵ��� ���������. 
extern int iExtern = 0; // �̷������� �ʱ�ȭ ���ѵ־���. 
void Test()
{
	std::cout << 1;
}
int Add(int a, int b)
{
	std::cout << "iExtern�� ���� : " << iExtern << std::endl;

	return a + b;
}

//�ٸ� main ���Ͽ��� ������ ���������� �� ���Ͽ��� ������� ����. 