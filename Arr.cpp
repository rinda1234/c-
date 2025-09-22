#include "Arr.h"
#include<iostream>

void InitArr(tArr * _pArr)// 초기화 함수.
{
	_pArr->pInt = (int*)malloc(sizeof(int)*2);// int 가 2개 들어감. 8바이트가 아닌 이런식으로 적는게 보기 더 좋음.  
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
}
void Reallocate(tArr* _pArr) // 공간 재할당. 주의! 포인터 배열을 잘못 쓰면 다른 주소를 침범해서 사고가 날 수 있음. 
{
	// 원래 있던 배열의 공간에 추가로 붙일 수 없음. 따라서 처음부터 다시 할당받아서 값을 복사해서 넣어줌; 
	
	// 1. 2베 더 큰 공간을 동적할당 한다. 
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int)); // 원래 최대 개수에 2배만큼 다시 만들어서 그 주소값을 저장해줌.. 
	
	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다. 
	for (int i = 0; i < _pArr->iCount; ++i)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 항당된 공간을 가리키게 한다. 
	_pArr->pInt = pNew;

	// 5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}	
void PushBack(tArr* _pArr, int _iData) //데이터 추가 함수. 
{
	// 현재 데이터의 개수와 최대 개수를 비교해야함. 
	// 힙 영역에 할당한 공간이 다 참
	if (_pArr->iMaxCount <= _pArr-> iCount)
	{
		//재할당
		Reallocate(_pArr); // 여기서는 아래 구현이 되어 있으니까 쓸 수 있음. 하지만 헤더파일에서 지웠으므로 main에서는 사용못함. 
	}
	// 공간이 넉넉해짐.
	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData; //iCount++ 인 이유: 일단 iCount가 쓰인 뒤 ++가 됨. 따라서 추가로 iCount++를 안해도 됨/ 
	
	
}



void ReleaseArr(tArr* _pArr) // 메모리 해제 함수. 
{
	free(_pArr->pInt); //이런식으로 동적할당을 해제해줘야함. 
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int)) // 이 함수가 다른 정렬 함수를 받아서 대신 정렬 해줌. 이게 무슨말이냐. 이 함수로 다른 정렬 함수도 사용 가능. 
{
	SortFunc(_pArr->pInt, _pArr->iCount); 
}

