#pragma once
// ������ �� ������ �� �ִ� �����迭 Ŭ����
#include <assert.h>
// �����ʹ� 8����Ʈ, �� �� Ŭ������ ��ü�� �����ϸ� 16����Ʈ�� �����. (�̳� Ŭ������ ��ü�ȿ� �ִ°� �ƴ϶� Ŭ���� �ȿ� �ִ°ű� ������ ���� �̳�Ŭ������ ��ü�� ����°� �ƴϸ� ������ ������ �ʴ´�.)
// ���� �̳� Ŭ������ ��ü�� �����  36����Ʈ�� ����. 


// �̳� Ŭ������ Ư¡
// 1. �������������ڷ� CArr::iterator �̷������� ����ؾߵ�. 
// 2. �̳� Ŭ������ ����Ǿ� �ִ� ���� Ŭ����(CArr)�� private ����� ���� ������. 
// 3. �ݴ�� ���� Ŭ����(CArr)�� �̳�Ŭ������ private ����� ������ �� ����. 
template<typename T>
class CArr
{
private: 
	T* m_pData; // ����� ctrl rr : �ܾ� �ѹ��� �ٲٱ�
	int m_iCount; // �̰Ŵ� ������ ����ϴ� �ű� ������ �ٲ� �ʿ� ����. 
	int m_iMaxCount;

public:
	void push_back(const T& _iData); // �̰Ŵ� �ٲ������. ������ �����Ͱ� �ٸ��� ������ 
	// �� �����迭�� T�� ���� �ڷ����� �����ϴµ� �̰� Ŭ������ �����ϴ� ������ Ÿ���� �󸶳� Ŭ�� ��. 
	// ��û ū �����͸� ������ �� �ֱ� ������ ������ ����� ��ȿ����. ���� ���۷���(������)�� �ٲ��ִ°� ����. ���� ������ �ٲٸ� �ȵǱ� ������ const �� �ٿ���.  
	void resize(int _iResizeCount); // �̰͵�  int���� �������.  
	T* data() { return m_pData; }
	int size() { m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);
	void Clear()
	{
		m_iCount = 0; // �̷��� �ٽ� ó������ ä������ ������ ���� �ִ� �����ʹ� �ǹ̰� ������. ��� ��û ���� �����͸� �־��ٰ� clear�ϸ� ������ ���� �þ ���·� ó������ �ٽ� ä�� ����. 	}
	}

	// ���� iterator��� Ŭ������ �����Ǳ� ���̹Ƿ� �ѹ� �������� ��. 
	class iterator;
	iterator begin(); //begin()�� iterator�� ��ȯ�ϱ� ������ . 
	iterator end();
	iterator erase(iterator& _iter);
public:

	CArr();
	~CArr();
	// iterator Ŭ���� �����
	// �̳� Ŭ���� �̹Ƿ� Ŭ���� ���ο� ����
	class iterator // �� Ŭ������ �̳� Ŭ�����̱� ������ CArr�� ��ü�� ���� �� Ŭ������ ��ü�� �ȸ������. ���� ����� ��� ��. 
	{ // ���ø� �ȿ� ����� �����Ƿ� �굵 ���ø������. 
	private:
		CArr* m_pArr; // iterator �� �⸮ų �����͸� �����ϴ� �����迭 �ּ�.   �̰� �˰� ������ ������ �ȿ� �����Ͱ� ��������Ƿ� T* mpData�� �� �ʿ䰡 ����. 
		T* m_pData; // �����͵��� ���� �ּ�
		
		// ���� ������ �ְ� �ȳ���� ���� ���⼺�� ���̰� ����.
		
		// 1. �ȳ���
		// �ȳ־������� �����迭�� ������ �� ���� ����� ���������� iterator�� �ڵ����� ����� �ּҸ� ����Ŵ. �׳� ���Ϳ� m_idx �κ��� �⸮Ű�� �ǹǷ� . 
		
		// 2. ����.
		// ������ �����迭�� ������ �� ���� ����� ���������� iterator�� ���� �ڽ��� ������ �ִ� �ּҿ� �ش� �ּҰ� �ٸ��Ƿ� ������ �ִٰ� ������. �츮�� �����ϴ� vector�� �̷� �����. ���� vector���� iterator�� �迭�� ���̻� Ű���� ������ �ؾߵ�.  
		int m_iIdx;	// �װ� �� vector�� ���°���� �����ؾߵ�. vector[i}
		// m_iIdx�� -1�ϋ��� end iterator ��� ��. 

		// iterator �����Ҷ� ����. 
		bool m_bValid; //iterator ��ȿ�� üũ. ��

	// ������ �����ε�
	public:
		T& operator *() // �׳� T�� �ϸ� ���� �ٲ� �� �����Ƿ� ���۷�����  ���� .
		{
			// iterator �� �˰��ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator�� ���
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)// false = m_bValid�� ������. 
				assert(nullptr);


			return m_pData[m_iIdx];
		}
		// ����
		iterator& operator ++() // ��ȯŸ���� �ڱ� �ڽ��� �Ǿ�� ���� ������ �� �� ��� ������ ������.  
		{
			// 1. end iterator �� ���
			// 2. iterator �� �˰��ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ���(���� Ȯ������ �ּҰ� �޶��� ���)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);

			// 3. iterator �� ������ �����͸� ����Ű�� �ִ� ���
			if (m_pArr->m_iCount - 1 == m_iIdx)
			{
				m_iIdx = -1;
				return *this;
			}


			++m_iIdx;
			return *this; //this�� �ش� ��ü�� �ּҸ� ��ȯ�ϱ� ������ �������ؼ� �����ؾ� ��ü�� ���ϵ�. 
		}
		iterator& operator --() 
		{
			// 1. iterator�� �˰� �ִ� �ּҿ�, ���� �迭�� �˰��ִ� �ּҰ� �޶��� ���
			// 2. iterator�� ù��° �����͸� ����Ű�� ���� ���
			if (m_pArr->m_pData != m_pData || 0 == m_iIdx)
			{
				assert(nullptr);
			}
			--m_iIdx;

			return *this; 
		}

		// ����
		// �ڱ� �ڽ��� ��ȯ�ϸ� ���� ���� ������ ó�� ������ �� ����. ��ȯ�ϸ� ���� ����� ����Ű�� �̹� �ǹ����ű⶧����. 
		// ���� ���纻�� ��. 
		iterator operator ++(int)// ���ڰ� ������ ���°���. �� ���ڷ� ���������̶�� �����Ϸ��� �����ϴ°���. 
		{
			// ȣ����� �������������� iterator�ϳ��� �Ǹ���
			iterator copy_iter = *this; // ���������� ȣ���� ��ü�� ������. ��������ڰ� ȣ���. 

			++(*this); //���������� ȣ���� ��ü�� ����������. 
			// ���� ��ȯ�ϴ°� ���纻��. 
			return copy_iter; // ������Ű���� ī�Ǻ��� ��ȯ�ϹǷ� ���������ΰ�ó�� �۵���. 
		}
		iterator operator --(int)
		{
			iterator copy_iter = *this;
			--(*this);

			return copy_iter;
		}

		// �� ������ ==. !=
		bool operator ==(const iterator& _otheriter) // �� �����̱� ������ ��ȯŸ���� bool��
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator !=(const iterator& _otheriter) // �� �����̱� ������ ��ȯŸ���� bool��
		{
			/*
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return false;
			}
			return true;
			*/
			// ���� ���� ���� �����ϰ� �����ϸ� 
			return !(*this == _otheriter);
		} 
	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) //�ƹ��͵� ����Ű�� ���� �ʴٴ� �ǹ�
			, m_bValid(false)
		{
		}
		iterator(CArr* _pArr, T* _pData, int iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(iIdx) //�ƹ��͵� ����Ű�� ���� �ʴٴ� �ǹ�
			, m_bValid(false) 
		{
			// ����ε� �����迭 �ȿ� Ư���κ��� ����Ű�� ������ 
			if (nullptr != _pArr && 0 <= iIdx)
			{
				m_bValid = true; // iterator ��ȿ.
			}
		}
		~iterator()
		{
		}
		// friend Ű����
		friend class CArr; // ������ private ���� ���ٰ���. 
						   // A�� B�� friend��� B�� A�� friend�� �ƴ�. 
						   // A�� B�� friend�̰� B�� C�� friend��� A�� C�� friend�� �ƴ�. 
						   // friend�� ���� Ŭ������ private�� ���� ����e. 
						   // �����ٰ� �� friend �����ϸ� ��������� ���������� �ٸ� ������ ���� �� ����. 
						   // ���� ����Լ��� friend �����ؼ� private�� ������ �� �ְ� �ϴ°� ����. 
	};

};

// template�� cpp ���Ͽ� �����Ǿ� ������ �ȵǰ� ������Ͽ� �־����. 
// main�Լ����� ���ø����� �Լ��� ȣ���Ҷ� ������Ͽ� T�κи� ���ϴ� �ڷ������� �ٲ�.  ���� cpp������ �ȹٲ�. �ٵ� maincpp������ �̸� ��. 
// TArr.cpp������ �ȹٲ�. 


template<typename T>
CArr<T>::CArr() // �����ڴ� �������ε� CArr Ŭ������ T���� �ȿ� �����Ǿ� �ִ� ������. 
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _iData)
{// this ���� ����
	if (this->m_iMaxCount <= this->m_iCount)
	{
		resize(this->m_iMaxCount * 2);
	}
	this->m_pData[this->m_iCount++] = _iData;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�. 
	T* pNew = new T[_iResizeCount];

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
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin() //�տ� tyoename�� ���� ����. ��ȯŸ���� �̳� Ŭ������ ���(���⼭�� iterator), CArr �ȿ� �ִ� �̳� Ŭ����, iterator��� Ÿ���̴ٴ� ���� �˷��ֱ� ���� ����. 
{
	// ������ �⸮Ű�� iterator�� ���� ��ȯ����. 
	// CArrŬ���� ����� iterator ��ü�� �ȸ���� �����Ƿ� ��ȯŸ���� ���۷����� �ȵ�.
	// iterator iter;
	// iter.m_pData = this->m_pData; //this ���� ����. m_pData�� �����ּҸ� �⸮Ű�Ƿ� iter.m_pData�� ����.
	// iter.m_iIdx = 0;
	
	
	// �̷��Ÿ� �����ڷ� ����� �� ����. 

	//iterator iter(m_pData, 0);
	// �׷��� ������ �ٷ� ��ȯ�ϱ� ������ �ӽð�ü��� �������� �����ʰ� �ٷ� ��ȯ ����. 

	// ���� �����Ͱ� �ϳ��� �������(�迭�ȿ�)
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // �����Ͱ� ���� ���, begin() == end() // end iterator
	else
		return iterator(this ,m_pData, 0); //iterator ��ȯ. 
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ���� ������ �⸮Ű�� iterator �� ���� ��ȯ����
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter) // ��ȯŸ���� iterator��.  // ������ ������ �����Ƿ� iterator&�� ���ڷ� ����
{
	// �� �Լ��� CArr�� ����Լ��̹Ƿ� iterator�� private�� ������ �� ����. 
	// iterator �� �ڽ��� private �κ��� ���� �� �ְ� ���ִ� ����Լ��� �����ϰų�
	// Ȥ�� terator�� �����迭 �ֹ������� private�� �����Ϸ��� friend Ű���� ���. 


	// ����ó��.
	// 1. iterator �� �ٸ� �����迭�� index�� ��ġ�� ����Ű�� ���� : iterator�� �ٸ� Arr �� ��Ҹ� ����Ű�� ���
	// 2. iterator �� end iterator�� ����Ű�� ����
	// 3. iterator �� ���� ���� �������� ī���ͺ��� �����ϴ� �ε����� �� ŭ. (�ε����� ������ ī���Ͷ� ���Ƶ� �ȵ�. ))
	if (_iter.m_pArr != this || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}

	// iterator �� �⸮Ű�� �κ� ����
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);
	for (int i = 0; i <= iLoopCount; ++i)
	{
		m_pData[_iter.m_iIdx + i] = m_pData[_iter.m_iIdx + 1 + i];// �̷������� �ϸ� �Ǽ��� ���ɼ��� ����. �޸� �����ؼ� �����ر� ����. �̷��� �Ҷ� ������ �׽�Ʈ �ϴ� �� ����. 
	}
	_iter.m_bValid = false; // �� iterator�� �����ϱ� ������ ��ȿ���� ���� iterator��� ���� ǥ��. //��ȯ�ϴ� iterator�� �����ڿ��� ��ȿ����.  

	// ī��Ʈ ����. 
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx); //  return�Ǵ� iterator�� �ٷ� ������ ���� ��Ҹ� ����Ű�� iterator�� �ٽ� �ְڴ�. ���� veciter1 = vec1.erase(veciter1) �̷������� �ٽ� iterator�� �޾ƾ� ��. 
	// �����迭������ ������ �����Ͱ� ������ �������� ���̹Ƿ� iterator�� �ٲ��� ����. ���� ���� ��Ҹ� ����ų �ʿ䰡 ����. 
}