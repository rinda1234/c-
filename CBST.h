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
	// data , pair �� �Ǿ� ����. 
	tPair<T1, T2>	pair; 

	// �θ��� ������
	tBSTNode*		pParent;
	// �ڽĳ�� ������ �ʿ�
	tBSTNode*		pLeftChild;
	tBSTNode*		pRightChild;


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
	// ù���� ������ ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		// first���� ���ؼ� ������ ����, ũ�� ������ ���� ��. 
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
			else // �ܸ����� ���ο� ���� first���� ���� ���(�ߺ��Ǵ� Ű��. �Ϲ����� map�� ������. ��尡 ���͵� ������. ����ϴ� map�� multymap�̶�� ���� ����., multymap�� ����Ű�� ������ ����Ű���� ����. )
			{
				// ���⼱ �ߺ�Ű�� ������� ����. 
				return false;
			}

		}
		
	
	}
}
