#include "Arr.h"
#include<iostream>

void InitArr(tArr * _pArr)// �ʱ�ȭ �Լ�.
{
	_pArr->pInt = (int*)malloc(sizeof(int)*2);// int �� 2�� ��. 8����Ʈ�� �ƴ� �̷������� ���°� ���� �� ����.  
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}
void Reallocate(tArr* _pArr) // ���� ���Ҵ�. ����! ������ �迭�� �߸� ���� �ٸ� �ּҸ� ħ���ؼ� ��� �� �� ����. 
{
	// ���� �ִ� �迭�� ������ �߰��� ���� �� ����. ���� ó������ �ٽ� �Ҵ�޾Ƽ� ���� �����ؼ� �־���; 
	
	// 1. 2�� �� ū ������ �����Ҵ� �Ѵ�. 
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int)); // ���� �ִ� ������ 2�踸ŭ �ٽ� ���� �� �ּҰ��� ��������.. 
	
	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��. 
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. ���� ������ �޸� ����
	free(_pArr->pInt);

	// 4. �迭�� ���� �״�� ������ ����Ű�� �Ѵ�. 
	_pArr->pInt = pNew;

	// 5. MaxCount ������ ����
	_pArr->iMaxCount *= 2;
}	
void PushBack(tArr* _pArr, int _iData) //������ �߰� �Լ�. 
{
	// ���� �������� ������ �ִ� ������ ���ؾ���. 
	// �� ������ �Ҵ��� ������ �� ��
	if (_pArr->iMaxCount <= _pArr-> iCount)
	{
		//���Ҵ�
		Reallocate(_pArr); // ���⼭�� �Ʒ� ������ �Ǿ� �����ϱ� �� �� ����. ������ ������Ͽ��� �������Ƿ� main������ ������. 
	}
	// ������ �˳�����.
	// ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData; //iCount++ �� ����: �ϴ� iCount�� ���� �� ++�� ��. ���� �߰��� iCount++�� ���ص� ��/ 
	
	
}



void ReleaseArr(tArr* _pArr) // �޸� ���� �Լ�. 
{
	free(_pArr->pInt); //�̷������� �����Ҵ��� �����������. 
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int)) // �� �Լ��� �ٸ� ���� �Լ��� �޾Ƽ� ��� ���� ����. �̰� �������̳�. �� �Լ��� �ٸ� ���� �Լ��� ��� ����. 
{
	SortFunc(_pArr->pInt, _pArr->iCount); 
}

