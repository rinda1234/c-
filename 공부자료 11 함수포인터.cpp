#include<iostream>
#include"Arr.h"
void Test();
void BubbleSort(int* _pData, int _iCount);
int main()
{
	// 함수의 주소를 받을때
	void(*pFunc)(void) = nullptr;// 이런식으로 받으면 됨. 반환타입이 void 이고 인자가 void 인 그런 함수의 주소를 받겠다 라고 pFunc가 그런 변수가 됨.  
	pFunc = Test;
	pFunc(); //이런식으로 pFunc를 호출하면 Test함수가 호출됨. 
	// 마지막 void가 그 함수의 인자임. 그인자를 가진 함수만 받을 수 있음. 
	// ex) Sort 함수. 
	
	tArr s1 = {};
	InitArr(&s1);
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1,iRand);
	}
	Sort(&s1, &BubbleSort); //여러가지 정렬 방법중에 버블정렬을 사용하겠다. 함수는 이름 자체가 주소이기 떄문에 그냥 BubbleSort로 적어도 됨 
	//Sort(&s1, BubbleSort); 이거랑 같은 말임. 
	return 0;
}

void BubbleSort(int* _pData, int _iCount) // 시작주소와 어디까지 자료가 채워져있는지. 
{
	bool bFinish = true;
	// 예외처리
	if (_iCount <= 1)
		return;

	//오름차순 정렬
	int iLoop = _iCount - 1;
	while (true)
	{
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{


				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}
		if (bFinish)
			break;
	}


}
void Test()
{

}