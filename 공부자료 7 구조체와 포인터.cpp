#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>

typedef struct _tagMyST
{
	int a; //멤버
	float f;
}MYST;

int main()
{
	// 구조체와 포인터
	MYST s = {};

	MYST* pST = &s; // MYST 개념이 내가 만든 자료형이기 때문에 포인터로 만들 수 있음. 

	*pST = { 100, 3.14f }; // 역참조 할거면 정확히 어떤 멤버를 할건지  해줘야함.

	(*pST).a = 10;
	(*pST).f = 3.1f;

	pST->a = 300; // 위랑 똑같은 말임. 
	pST->f = 23.23;
	return 0;
}