#pragma once
typedef struct _tabMyst
{
	int* iArr;
	int iCount;
	int iMaxCount;
}MYST;

// 1. �ʱ�ȭ �Լ�
void InItArr(MYST* _pArr);

// 2. ������ �ִ� �Լ�
void PushBack(MYST* _pArr, int _Data);

// 3. �迭 ���� �ø��� �Լ�
void Realloc(MYST* _pArr);
// 4. �Ҹ��Լ�.
void delloc(MYST* pArr);
