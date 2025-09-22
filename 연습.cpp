#include "¿¬½À.h"
#include<iostream>
void InItArr(MYST* _pArr)
{
	_pArr->iArr = (int*)malloc(sizeof(int) * 2);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}

void PushBack(MYST* _pArr, int _Data)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		Realloc(_pArr);
	}
	_pArr->iArr[_pArr->iCount++] = _Data;
}

void Realloc(MYST* _pArr)
{
	int* NewArr = (int*)malloc(sizeof(int) * 2 * _pArr->iMaxCount);
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		NewArr[i] = _pArr->iArr[i];
	}
	free(_pArr->iArr);
	_pArr->iArr = NewArr;
	_pArr->iMaxCount *= 2;
}

void delloc(MYST* _pArr)
{
	free(_pArr->iArr);
	_pArr->iArr = nullptr;
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;

}
