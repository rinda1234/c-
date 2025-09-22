// 가변배열 클래스에 내가 만든 구조체, 클래스를 저장하고 싶을때 int 타입으로는 당연히 안됨. 
// 원래는 클래스를 그 타입에 맞게 여러개 만들어야 하지만 템플릿으로 한번에 만들 수 있음. 
#include<iostream>
#include "TArr.h"
#include "TLinkedList.h"
int main()
{
	CArr<int> carr; // 이런식으로 자료형을 알려줘야함. 

	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	CArr<float> farr; // 다른 지료형도 가능해짐. 

	farr.push_back(10);
	farr.push_back(20);
	farr.push_back(30);

	CArr<CArr<int>> caarr; // 다른 지료형도 가능해짐. 

	caarr.push_back(carr);

	// 리스트 템플릿
	CList<float> list;

	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	return 0;
}