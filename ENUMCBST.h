#pragma once

#include<assert.h>
enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END,	// 3 마감
};


template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}
template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2>	pair;

	// 같은 타입이 3개이므로 배열로 묶을 수 있음. 
	tBSTNode* arrNode[(int)NODE_TYPE::END];
	// enum 값을 배열의 인덱스로 볼 수 있음. 
	// 3개의 변수를 1개의 배열로 압축한뒤 enum 값을 인덱스로 봤기 때문에 코드를 줄일 수 있음.
	// 원래는 변수명을 다 지칭해야 했기 떄문에 코드가 김. 

	// iterator 가 가리키는 노드가 부모노드인지 알려주는 함수. 
	bool IsRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	// 부로부터 왼쪽 자식인지 알려주는 함수. (코드가 반복되서 지저분해져서 사용)
	bool IsLeftChild()
	{
		// iterator 가 가리키는 노드가 루트 노드 인경우 부모로 접근하면 문제가 생길 수 있음. iterator 가 루트노드를 가리키는지 확인하는 함수 필요 
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}
	// 부모로부터 오른쪽 자식인지 알려주는 함수. 
	bool IsRightChild()
	{
		// iterator 가 가리키는 노드가 루트 노드 인경우 부모로 접근하면 문제가 생길 수 있음. iterator 가 루트노드를 가리키는지 확인하는 함수 필요 
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}
	bool IsLeaf() //리프노드인지 체크
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}
	bool IsFull() // 자식이 꽉찬 경우
	{
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}
	tBSTNode()
		: pair()
		, arrNode{}
	{}
	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{_pParent, _pLChild, _pRChild}
	{}
};

template <typename T1, typename T2>
class CBST
{
private:
	// 본체인 바이너리 서치 트리는 루트노드만 알면 됨. 
	tBSTNode<T1, T2>* m_pRoot;// 루트 노드 주소
	int m_iCount; //데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);
	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);
private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

	// iterator
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST; // node들을 다 관리하고 있는 CBST 자체를 알고있는게 편함.(루트노드가 뭔지, 등등 알기 위해서) 
		tBSTNode<T1, T2>* m_pNode; // null일 경우 end iterator
	public:
		bool operator ==(const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
				return true;
			return false;
		}
		bool operator !=(const iterator _other)
		{
			return!(*this == _other);
		}
		const tPair<T1, T2>& operator *() // 별은 역참조 할때. (*Iter).first; 구조체를 반환하므로 구조체.first로 접근할 수 있게됨. 
		{
			// m_pNode nullptr 체크(end iterator 인지 아닌지) 
			assert(m_pNode);
			return m_pNode->pair;
		}
		const tPair<T1, T2>* operator ->() //주소값을 반환해야 됨. 화살표는 실제적인 주소 값을 주는 것임. 즉 pair의 주소를 줌. 
		{
			// m_pNode nullptr 체크(end iterator 인지 아닌지) 
			assert(m_pNode);
			return &m_pNode->pair; // 화살표 operator는  Iter->->first; 원래는 이런식으로 접근해야함. 
			// 그래야지 반환된 주소에서 first에 접근이 가능함. 
			// 하지만 화살표 operator는 주소를 반환할 경우 이를 생략가능하게 해줘서 반환된 주소에 first로 바로 접근 가능하게 함. 
			// 즉 문법적으로 보정을 해줌. 
		}
		iterator& operator ++()
		{
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}
	
	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{}
		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{}
		friend class CBST<T1, T2>;
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
	// 첫번쨰 데이터 라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		// first끼리 비교해서 작으면 왼쪽, 크면 오른쪽 으로 감. 
		tBSTNode<T1, T2>* pNode = m_pRoot;

		// 가야할 방향을 enum 값으로 지정
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			//  왼쪽으로 갈지 오른쪽으로 갈지 enum 에 저장. 
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;
			// 기야할 방향을 node_type에 저장했기 때문에 대칭적으로 코드를 만들 필요 없음. 
			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) //중위 후속자. 
{
	// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서 왼쪽 자식이 없을때까지 이동
	
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		// 오른쪽 자식으로 가서 왼쪽 자식이 없을때까지 이동
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	// 2. 없는 경우. 부모로 부터 본인이 왼쪽 자식일 때 까지 위로 올라감. 
	// 그때  부모가 중위 후속자. 
	else
	{
		pSuccessor = _pNode;
		
		while (true)
		{
			// 더이상 위쪽으로 올라갈 수 없다. 
			if (pSuccessor->IsRoot()) // 본인이 마지막 노드
				return nullptr;

			// pSuccessor->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == pSuccessor;
			// 이런 경우 함수가 너무 지저분하므로 node 쪽에서 함수를 지원
			// 부모로부터 왼쪽자식인지 체크
			if (pSuccessor->IsLeftChild())
			{
				// 그때 부모가 후속자. 
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
		}

	}
	
	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin() // 중위순회 기준으로 첫번째, 제일 왼쪽에 있는 노드.  
{	
	tBSTNode<T1, T2>* pNode = m_pRoot;
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{

	return iterator(this, nullptr); // end iterator는 제일 오른쪽이 아니라 null을 가리키면 end iterator 라고 하기로 했기 때문에. 
}


template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	// first끼리 비교해서 작으면 왼쪽, 크면 오른쪽 으로 감. 
	tBSTNode<T1, T2>* pNode = m_pRoot;

	// 가야할 방향을 enum 값으로 지정
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		//  왼쪽으로 갈지 오른쪽으로 갈지 enum 에 저장. 
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// 찾음
			//return iterator(this, pNode);
			break;
		}
			
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// 못찾음. pNode = nullptr ==> enditerator
			//return end();
			pNode = nullptr; 
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
		
	}
	// 반복문 내에서 모든게 끝나고 외부쪽에서의 리턴이 없으면 문제가 생길 수 있음. 
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter) // 노드를 삭제한다 에만 집중하는 함수. iterator 가 가리키는 노드를 제거해서 그 다음을 가리키는 iterator를 반환하는 함수.  
{
	assert(this == _iter.m_pBST); // 같지 않으면 assert가 발동함. 
	
	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode); //중위 후속자를 반환함. 

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	// 삭제되기 전에 미리 중위 후속자를 찾아야함.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. 자식이 하나도 없는 경우
	if (_pTargetNode->IsLeaf())
	{

		// 자식이 하나도 없는 루트노드인 경우(BST 안에 데이터가 1개 밖에 없었다. )
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// 부모노드로 접근, 삭제될 노드인 자식을 가리키는 포인터를 nullptr로 만든다. 
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == nullptr;

		}
		delete _pTargetNode;
		--m_iCount;
	}
	// 2. 자식이 2개인 경우. ( 삭제할 노드의 데이터에 중위 후속자의 데이터를 복사, 그 뒤 중위 후속자를 삭제) 
	else if (_pTargetNode->IsFull())
	{
		// 삭제 될 자리에 중위 후속자의 값을 복사시킨다.
		_pTargetNode->pair = pSuccessor->pair;

		// 중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor); // 중위 후속자의 자식이 2개일 수는 없기 때문에 무한으로 호출되지는 않음. 
		// 이렇게 함수를 여러번 호출하게 되면 데이터 개수 m_iCount가 여러번 빠짐. 따라서 1, 3번 케이스 에서만 빼줘야함. 
		
		// 삭제할 노드가 중위 후속자 노드가 됨. 
		pSuccessor = _pTargetNode;
	}
	// 3. 자식이 1개인 경우
	else
	{
		// 삭제할 노드의 자식이 오른쪽노드인지 왼쪽 노드인지 체크. 
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// 자식이 1개 있는 루트노드가 삭제되는 경우 -> 자식노드가 루트노드가 되면 됨. 
		if (_pTargetNode == m_pRoot)
		{
			// 자식 노드(1개) 를 루트노드로 만든다. 
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] == nullptr;
		}
		else
		{
			// 삭제될 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
			if (_pTargetNode->IsLeftChild())
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}

		delete _pTargetNode;
		--m_iCount;
	}

	// 데이터 개수 맞춰줌( 자식이 2개인 경우 함수를 1번 더 호출하므로 1, 3에만 들어가 있어야함. 
	//--m_iCount;
	return pSuccessor;
}
