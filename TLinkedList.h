#pragma once
// c++ ���ؿ����� ����ü�� Ŭ������ ���̰� �����. �� ����. ����ü�� ������, �Ҹ��� ������. ������ ����ü�� ���� ���� �����ڰ� ������ �⺻���� public��. 
// �� ����ü�� Ŭ������ c++������ �Ȱ���. 

// �̹� ����Ʈ�� ����� ����Ʈ
template<typename T>
struct tListNode // Ŭ������ �����ص� ����� ������ ����� ���� ����, �ܼ��� �����͸� �����صΰ� ���� ����� ������ ����ü�� ��, ���ᵵ ��� ����. 
{
	T				data;
	tListNode<T>*	pPrev; //T���� �ٿ���� ��. ������ ���� ���� ���ο� �ֱ� ������ T�� ��Ī������ �ʾƵ� ��. �ۿ����� ��Ī�������. 
	tListNode<T>*	pNext;

	tListNode() // ������
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) // ������ �����ε�
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{
	}

};

template<typename T>
class CList
{
private:
	tListNode<T>*	m_pHead;
	tListNode<T>*	m_pTail;
	int				m_iCount;
public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_iCount; }
public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(const iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{

	privatd:
		CList<T>* m_pList; // ���� ����Ű�� �ִ� ��尡 �����ִ� ����Ʈ. 
		tListNode* m_pNode; // ��ü������ ���� ����Ű�� �ִ� ���.
		// null�� ���, end iterator�� ����
		bool m_bValid; //��ȿ�� üũ

	public:
		T& operator* () // ������
		{
			return m_pNode->data; //iterator �� ����Ű�� ��尡 ������ �ִ� ��
		}
		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}
		bool operator !=(const iterator& _otheriter)
			return !(*this == _otheriter);
		iterator& operator ++() //���������� ����
		{
			// end���� ++�� ���
			// ��ȿ���� ���� iterator�� ���
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;
		}
		iterator& operator ++(int) // ���������� ����
		{
			iterator copyiter(*this); //����

			++(*this)
			return copyiter;

		}
		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;
		}
		iterator& operator --(int)
		{
			iterator copyiter(*this);
			--(*this);
			return copyiter;
		}
	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{}
		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator();
		{

		}
		friend class CList;
	};

};
template<typename T>
void CList<T>::push_back(const T& _data)
{
	// �Էµ� �����͸� ������ ��带 �����Ҵ� ��. 
	tListNode<T>* pNewNode = new tListNode<T>{ _data, nullptr, nullptr }; // ���� �ʱ�ȭ ���ϰ� �����ڰ� �ʱ�ȭ ��.
	// ó�� �Էµ� �����Ͷ��
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		// ������ 1�� �̻󿡼� �Էµ� ���
		// ����� ����Ʈ�� ������ ���� ���� ������ ������(tail)�� �����ϰ� �ִ� ��尡 
		// ���� ������ ��带 ����Ű�� �Ѵ�. ���� ������ .
		// ����� ����Ʈ�� 1�� ��� pPrev�� ������ ����� pNext�� nullptr�̴�.

		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail; // �ֹ��� ����

		//List �� ������ ����� �ּҰ��� ���� �Էµ� ���� �����Ѵ�. 
		m_pTail = pNewNode;

	}
	// ������ ���� ����
	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>{ _data, nullptr, m_pHead }; // ������ ȣ��ɋ� ������ ��. ���� ���� �ʱ�ȭ ���ϰ� 
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pHead->pPrev = pNewNode;
		m_pHead = pNewNode;
	}

	++m_iCount;
}

template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{
}
template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeletNode = m_pHead;

	while (pDeletNode)
	{
		tListNode<T>* pNext = pDeletNode->pNext;
		delete pDeletNode;
		pDeletNode = pNext;

	}

}
template<typename T>
inline typename CList<T>::iterator CList<T>::begin()
{
	// 1. �����Ͱ� �ƹ��͵� ������ begin�� ��û������
	return iterator(this, m_pHead);
}
template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);// ���� null �����͸� end iterator�� �����ϱ� ������ ��
}

template<typename T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}
	
	if (m_pHead == m_pTail)
	{
		delete m_pNode;
		return end();
	}
	else if (_iter.m_pNode == m_pHead)// ������� ���
	{
		m_pHead = _iter.m_pNode->m_pNext;
		_iter.m_pNode->m_pNext->m_pPrev = nullptr;
	}
	else if(_iter.m_pNode == m_pTail) // tail ����� ���
	{
		m_pTail = _iter.m_pNode->m_pPrev;
		_iter.m_pNode->m_pPrev = nullptr;
	}
	iterator newiter(this, _iter.m_pNode);
	delete _iter.m_pNode;
	--m_iCount;
	return newiter;
}

template<typename T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	// ����Ʈ�� �߰��Ǵ� �����͸� ���� �� Node ����
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator �� ����Ű�� ��尡 ������� ���
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->m_pPrev = pNode;
		pNode->pNext = iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator�� ����Ű�� �ִ� ����� �������� ����
		// ���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����. 
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator �� ����Ű�� �ִ� ����� ������ ���ο� ���� ����
		// ���ο� ����� pNext�� iterator �� ����Ű�� �ִ� ���� ����
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
		++m_iCount;
	}


	return iterator(this, pNode);
}






