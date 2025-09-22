#include "CArr.h"
#include <assert.h>
// cpp������ Ŭ���� ���� ���� �ۿ� ����Ȱű� ������ �տ� CArr�̶�� ��Ī�������. 
CArr::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new int[2]; //c++������ �����Ҵ�. int�ڷ��� 2����ŭ.
}

CArr::~CArr()
{
	delete[] m_pData; //c++������ �����Ҵ� ����
}


void CArr::push_back(int _iData)
{// this ���� ����
	if (this->m_iMaxCount <= this->m_iCount)
	{
		resize(this->m_iMaxCount*2);
	}
	this->m_pData[this->m_iCount++] = _iData;
}

void CArr::resize(int _iResizeCount) // �����迭 ���� ������ ��� ������ �þ�ٵ� 2�辿 ũ�� ���ϰ� ���� ���� �����Լ����� ũ�� �Ҵ��ؼ� ���� ��찡 ����. 
{
	// ���� �ִ� ���뷮 ���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�. 
	int* pNew = new int[_iResizeCount]; // ���� �ִ� ������ 2�踸ŭ �ٽ� ���� �� �ּҰ��� ��������.. 

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��. 
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] m_pData;

	// 4. �迭�� ���� �״�� ������ ����Ű�� �Ѵ�. 
	m_pData = pNew;

	// 5. MaxCount ������ ����
	m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](int idx)
{
	return m_pData[idx];
}
