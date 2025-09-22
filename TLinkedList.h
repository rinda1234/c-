#pragma once
// c++ 기준에서는 구조체와 클래스의 차이가 사라짐. 즉 같음. 구조체도 생성자, 소멸자 가능함. 하지만 구조체는 접근 제한 지정자가 없을때 기본값이 public임. 
// 즉 구조체랑 클래스는 c++에서는 똑같음. 

// 이번 리스트는 양방향 리스트
template<typename T>
struct tListNode // 클래스로 선언해도 상관은 없지만 기능이 많이 없는, 단순히 데이터만 저장해두고 많은 기능이 없을때 구조체로 씀, 뭘써도 상관 없음. 
{
	T				data;
	tListNode<T>*	pPrev; //T까지 붙여줘야 함. 하지만 본인 선언 내부에 있기 때문에 T로 지칭해주지 않아도 됨. 밖에서는 지칭해줘야함. 
	tListNode<T>*	pNext;

	tListNode() // 생성자
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext) // 생성자 오버로딩
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
		CList<T>* m_pList; // 내가 가리키고 있는 노드가 속해있는 리스트. 
		tListNode* m_pNode; // 구체적으로 현재 가리키고 있는 노드.
		// null일 경우, end iterator로 간주
		bool m_bValid; //유효성 체크

	public:
		T& operator* () // 역참조
		{
			return m_pNode->data; //iterator 가 가리키는 노드가 가지고 있던 값
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
		iterator& operator ++() //전위연산자 버전
		{
			// end에서 ++한 경우
			// 유효하지 않은 iterator인 경우
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;
		}
		iterator& operator ++(int) // 후위연산자 버전
		{
			iterator copyiter(*this); //복사

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
	// 입력된 데이터를 저장할 노드를 동적할당 함. 
	tListNode<T>* pNewNode = new tListNode<T>{ _data, nullptr, nullptr }; // 따로 초기화 안하고 생성자가 초기화 함.
	// 처음 입력된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		// 데이터 1개 이상에서 입력된 경우
		// 양방향 리스트기 때문에 현재 가장 마지막 데이터(tail)를 저장하고 있는 노드가 
		// 새로 생성된 노드를 가리키게 한다. 새로 생성된 .
		// 양방향 리스트의 1번 노드 pPrev와 마지막 노드의 pNext는 nullptr이다.

		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail; // 쌍방향 연결

		//List 가 마지막 노드의 주소값을 새로 입력된 노드로 갱신한다. 
		m_pTail = pNewNode;

	}
	// 데이터 개수 증가
	++m_iCount;
}

template<typename T>
void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>{ _data, nullptr, m_pHead }; // 생성자 호출될떄 넣으면 됨. 굳이 따로 초기화 안하고 
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
	// 1. 데이터가 아무것도 없을때 begin을 요청했을때
	return iterator(this, m_pHead);
}
template<typename T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);// 차피 null 포인터면 end iterator로 간주하기 때문에 ㅡ
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
	else if (_iter.m_pNode == m_pHead)// 헤드노드인 경우
	{
		m_pHead = _iter.m_pNode->m_pNext;
		_iter.m_pNode->m_pNext->m_pPrev = nullptr;
	}
	else if(_iter.m_pNode == m_pTail) // tail 노드인 경우
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

	// 리스트에 추가되는 데이터를 저장 할 Node 생성
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);

	// iterator 가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == m_pHead)
	{
		_iter.m_pNode->m_pPrev = pNode;
		pNode->pNext = iter.m_pNode;

		m_pHead = pNode;
	}
	else
	{
		// iterator가 가리키고 있는 노드의 이전으로 가서
		// 다음 노드 주소 파트를 새로 생성한 노드로 지정. 
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator 가 가리키고 있는 노드의 이전을 새로운 노드로 지정
		// 새로운 노드의 pNext를 iterator 가 가리키고 있는 노드로 지정
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
		++m_iCount;
	}


	return iterator(this, pNode);
}






