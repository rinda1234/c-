#pragma once

template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};
template<typename T1, typename T2>
struct tBSTNode
{
	// data , pair 로 되어 있음. 
	tPair<T1, T2>	pair; 

	// 부모노드 포인터
	tBSTNode*		pParent;
	// 자식노드 포인터 필요
	tBSTNode*		pLeftChild;
	tBSTNode*		pRightChild;


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
public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>();
	pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;
	// 첫번쨰 데이터 라면
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		// first끼리 비교해서 작으면 왼쪽, 크면 오른쪽 으로 감. 
		tBSTNode<T1, T2>* pNode = m_pRoot;
		while (true) 
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				if (nullptr == pNode->pRightChild)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pRightChild;
				}
			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (nullptr == pNode->pLeftChild)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			else // 단말노드랑 새로운 노드랑 first값이 같은 경우(중복되는 키값. 일반적인 map은 허용안함. 노드가 들어와도 무시함. 허용하는 map은 multymap이라고 따로 있음., multymap은 같은키면 옆에다 같은키끼리 묶음. )
			{
				// 여기선 중복키를 허용하지 않음. 
				return false;
			}

		}
		
	
	}
}
