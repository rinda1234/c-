#include "CArr.h"
#include <assert.h>
// cpp파일은 클래스 파일 범위 밖에 선언된거기 떄문에 앞에 CArr이라고 지칭해줘야함. 
CArr::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new int[2]; //c++에서의 동적할당. int자료형 2개만큼.
}

CArr::~CArr()
{
	delete[] m_pData; //c++에서의 동적할당 해제
}


void CArr::push_back(int _iData)
{// this 생략 가능
	if (this->m_iMaxCount <= this->m_iCount)
	{
		resize(this->m_iMaxCount*2);
	}
	this->m_pData[this->m_iCount++] = _iData;
}

void CArr::resize(int _iResizeCount) // 가변배열 쓸때 어차피 계속 공간이 늘어날텐데 2배씩 크게 안하고 내가 직접 메인함수에서 크게 할당해서 쓰는 경우가 많음. 
{
	// 현재 최대 수용량 보다 더 적은 수치로 확장하려는 경우
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다. 
	int* pNew = new int[_iResizeCount]; // 원래 최대 개수에 2배만큼 다시 만들어서 그 주소값을 저장해줌.. 

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다. 
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 항당된 공간을 가리키게 한다. 
	m_pData = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pData[idx];
}
