#pragma once

#include<assert.h>
enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END,	// 3 ����
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

	// ���� Ÿ���� 3���̹Ƿ� �迭�� ���� �� ����. 
	tBSTNode* arrNode[(int)NODE_TYPE::END];
	// enum ���� �迭�� �ε����� �� �� ����. 
	// 3���� ������ 1���� �迭�� �����ѵ� enum ���� �ε����� �ñ� ������ �ڵ带 ���� �� ����.
	// ������ �������� �� ��Ī�ؾ� �߱� ������ �ڵ尡 ��. 

	// iterator �� ����Ű�� ��尡 �θ������� �˷��ִ� �Լ�. 
	bool IsRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	// �ηκ��� ���� �ڽ����� �˷��ִ� �Լ�. (�ڵ尡 �ݺ��Ǽ� ������������ ���)
	bool IsLeftChild()
	{
		// iterator �� ����Ű�� ��尡 ��Ʈ ��� �ΰ�� �θ�� �����ϸ� ������ ���� �� ����. iterator �� ��Ʈ��带 ����Ű���� Ȯ���ϴ� �Լ� �ʿ� 
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}
	// �θ�κ��� ������ �ڽ����� �˷��ִ� �Լ�. 
	bool IsRightChild()
	{
		// iterator �� ����Ű�� ��尡 ��Ʈ ��� �ΰ�� �θ�� �����ϸ� ������ ���� �� ����. iterator �� ��Ʈ��带 ����Ű���� Ȯ���ϴ� �Լ� �ʿ� 
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}
	bool IsLeaf() //����������� üũ
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}
	bool IsFull() // �ڽ��� ���� ���
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
	// ��ü�� ���̳ʸ� ��ġ Ʈ���� ��Ʈ��常 �˸� ��. 
	tBSTNode<T1, T2>* m_pRoot;// ��Ʈ ��� �ּ�
	int m_iCount; //������ ����

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
		CBST<T1, T2>* m_pBST; // node���� �� �����ϰ� �ִ� CBST ��ü�� �˰��ִ°� ����.(��Ʈ��尡 ����, ��� �˱� ���ؼ�) 
		tBSTNode<T1, T2>* m_pNode; // null�� ��� end iterator
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
		const tPair<T1, T2>& operator *() // ���� ������ �Ҷ�. (*Iter).first; ����ü�� ��ȯ�ϹǷ� ����ü.first�� ������ �� �ְԵ�. 
		{
			// m_pNode nullptr üũ(end iterator ���� �ƴ���) 
			assert(m_pNode);
			return m_pNode->pair;
		}
		const tPair<T1, T2>* operator ->() //�ּҰ��� ��ȯ�ؾ� ��. ȭ��ǥ�� �������� �ּ� ���� �ִ� ����. �� pair�� �ּҸ� ��. 
		{
			// m_pNode nullptr üũ(end iterator ���� �ƴ���) 
			assert(m_pNode);
			return &m_pNode->pair; // ȭ��ǥ operator��  Iter->->first; ������ �̷������� �����ؾ���. 
			// �׷����� ��ȯ�� �ּҿ��� first�� ������ ������. 
			// ������ ȭ��ǥ operator�� �ּҸ� ��ȯ�� ��� �̸� ���������ϰ� ���༭ ��ȯ�� �ּҿ� first�� �ٷ� ���� �����ϰ� ��. 
			// �� ���������� ������ ����. 
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
	// ù���� ������ ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		// first���� ���ؼ� ������ ����, ũ�� ������ ���� ��. 
		tBSTNode<T1, T2>* pNode = m_pRoot;

		// ������ ������ enum ������ ����
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			//  �������� ���� ���������� ���� enum �� ����. 
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;
			// ����� ������ node_type�� �����߱� ������ ��Ī������ �ڵ带 ���� �ʿ� ����. 
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
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode) //���� �ļ���. 
{
	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ���� ���� �ڽ��� ���������� �̵�
	
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		// ������ �ڽ����� ���� ���� �ڽ��� ���������� �̵�
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	// 2. ���� ���. �θ�� ���� ������ ���� �ڽ��� �� ���� ���� �ö�. 
	// �׶�  �θ� ���� �ļ���. 
	else
	{
		pSuccessor = _pNode;
		
		while (true)
		{
			// ���̻� �������� �ö� �� ����. 
			if (pSuccessor->IsRoot()) // ������ ������ ���
				return nullptr;

			// pSuccessor->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == pSuccessor;
			// �̷� ��� �Լ��� �ʹ� �������ϹǷ� node �ʿ��� �Լ��� ����
			// �θ�κ��� �����ڽ����� üũ
			if (pSuccessor->IsLeftChild())
			{
				// �׶� �θ� �ļ���. 
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
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin() // ������ȸ �������� ù��°, ���� ���ʿ� �ִ� ���.  
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

	return iterator(this, nullptr); // end iterator�� ���� �������� �ƴ϶� null�� ����Ű�� end iterator ��� �ϱ�� �߱� ������. 
}


template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	// first���� ���ؼ� ������ ����, ũ�� ������ ���� ��. 
	tBSTNode<T1, T2>* pNode = m_pRoot;

	// ������ ������ enum ������ ����
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		//  �������� ���� ���������� ���� enum �� ����. 
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// ã��
			//return iterator(this, pNode);
			break;
		}
			
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// ��ã��. pNode = nullptr ==> enditerator
			//return end();
			pNode = nullptr; 
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
		
	}
	// �ݺ��� ������ ���� ������ �ܺ��ʿ����� ������ ������ ������ ���� �� ����. 
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter) // ��带 �����Ѵ� ���� �����ϴ� �Լ�. iterator �� ����Ű�� ��带 �����ؼ� �� ������ ����Ű�� iterator�� ��ȯ�ϴ� �Լ�.  
{
	assert(this == _iter.m_pBST); // ���� ������ assert�� �ߵ���. 
	
	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode); //���� �ļ��ڸ� ��ȯ��. 

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	// �����Ǳ� ���� �̸� ���� �ļ��ڸ� ã�ƾ���.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. �ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->IsLeaf())
	{

		// �ڽ��� �ϳ��� ���� ��Ʈ����� ���(BST �ȿ� �����Ͱ� 1�� �ۿ� ������. )
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// �θ���� ����, ������ ����� �ڽ��� ����Ű�� �����͸� nullptr�� �����. 
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == nullptr;

		}
		delete _pTargetNode;
		--m_iCount;
	}
	// 2. �ڽ��� 2���� ���. ( ������ ����� �����Ϳ� ���� �ļ����� �����͸� ����, �� �� ���� �ļ��ڸ� ����) 
	else if (_pTargetNode->IsFull())
	{
		// ���� �� �ڸ��� ���� �ļ����� ���� �����Ų��.
		_pTargetNode->pair = pSuccessor->pair;

		// ���� �ļ��� ��带 �����Ѵ�.
		DeleteNode(pSuccessor); // ���� �ļ����� �ڽ��� 2���� ���� ���� ������ �������� ȣ������� ����. 
		// �̷��� �Լ��� ������ ȣ���ϰ� �Ǹ� ������ ���� m_iCount�� ������ ����. ���� 1, 3�� ���̽� ������ �������. 
		
		// ������ ��尡 ���� �ļ��� ��尡 ��. 
		pSuccessor = _pTargetNode;
	}
	// 3. �ڽ��� 1���� ���
	else
	{
		// ������ ����� �ڽ��� �����ʳ������ ���� ������� üũ. 
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// �ڽ��� 1�� �ִ� ��Ʈ��尡 �����Ǵ� ��� -> �ڽĳ�尡 ��Ʈ��尡 �Ǹ� ��. 
		if (_pTargetNode == m_pRoot)
		{
			// �ڽ� ���(1��) �� ��Ʈ���� �����. 
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] == nullptr;
		}
		else
		{
			// ������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
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

	// ������ ���� ������( �ڽ��� 2���� ��� �Լ��� 1�� �� ȣ���ϹǷ� 1, 3���� �� �־����. 
	//--m_iCount;
	return pSuccessor;
}
