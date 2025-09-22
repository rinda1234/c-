#include "LinkedList.h"
#include<iostream>
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����Ҵ��ؼ� ��带 �������� ������ �� �Լ��� ����ǰ� �����. 
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	//list�� ù���� ����� �ּҸ� �����ϹǷ� ���� ���� ��尡 ù��° ������� Ȯ���ؾ���. 
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else // ù��° ��尡 �ƴ϶�� ��
	{
		// ���� ���� ������ ��带 ã�Ƽ�,
		// �ش� ����� pNext �� ������Ų ����� �ּҷ� ä��. 
		// �ܹ��� �϶����� ó�������� ����ؾߵ�.
		tNode* pCurfinalNode = _pList->pHeadNode; // �� ��������Ͱ� �������� �ȵǹǷ� �����͸� �ϳ� �޾Ƽ� ����. 
		while(pCurfinalNode->pNextNode) // nullptr��ü�� 0�̹Ƿ� �̷��� ��� ��. nullptr != pCurfinalNode->pNextNode
		{

			pCurfinalNode = pCurfinalNode->pNextNode; // �������� nextnode��Ʈ�� ä���������Ƿ� ���� ����� �ּҸ� �޾ƿ�. �� ���� ����� �ּҷ� ���ǹ� ����. 

		}
		pCurfinalNode->pNextNode = pNode; // ���������� 2��° ��忡 �ּҸ� ����.
	}
	++_pList->iCount;


}
void PushFront(tLinkedList* _pList, int _iData)
{
	// ���� ������Ų ����� ������ ������ ���� �����Ѵ�.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	// ����Ʈ�� ����� �����͸� �����ؾ� ��.
	_pList->pHeadNode = pNode;

	// ������ ī��Ʈ ����.
	++_pList->iCount;
}
//����Լ��� ����������
void re_Release(tNode* _pNode)
{
	if (nullptr == _pNode)
	{
		return; // ���� ��尡 ������ void ��ȯ
	}
	re_Release(_pNode->pNextNode);
	free(_pNode);
}


void ReleaseList(tLinkedList* _pList)
{
	// �ּҸ� �ϳ��ϳ� �����ؾߵ�. 
	// ����Լ��� �ϸ� �����Ͱ� ������ �ʹ� ���� �Լ��� ȣ��ǹǷ� ȿ���� ������. 
	//re_Release(_pList->pHeadNode); //����Լ�.

	tNode* pDeletNode = _pList->pHeadNode;
	while (pDeletNode)//nullptr != pDeletNode
	{
		tNode* pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}// for������ �ٲٴ°� �� ������ �� ����.
}
