#pragma once
typedef struct _tabMyst
{
	int* iArr;
	int iCount;
	int iMaxCount;
}MYST;

// 1. 초기화 함수
void InItArr(MYST* _pArr);

// 2. 데이터 넣는 함수
void PushBack(MYST* _pArr, int _Data);

// 3. 배열 길이 늘리는 함수
void Realloc(MYST* _pArr);
// 4. 소멸함수.
void delloc(MYST* pArr);
