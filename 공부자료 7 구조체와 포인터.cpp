#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

typedef struct _tagMyST
{
	int a; //���
	float f;
}MYST;

int main()
{
	// ����ü�� ������
	MYST s = {};

	MYST* pST = &s; // MYST ������ ���� ���� �ڷ����̱� ������ �����ͷ� ���� �� ����. 

	*pST = { 100, 3.14f }; // ������ �ҰŸ� ��Ȯ�� � ����� �Ұ���  �������.

	(*pST).a = 10;
	(*pST).f = 3.1f;

	pST->a = 300; // ���� �Ȱ��� ����. 
	pST->f = 23.23;
	return 0;
}