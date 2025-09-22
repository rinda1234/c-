#include "LinkedList.h"
#include<iostream>
void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 동적할당해서 노드를 생성하지 않으면 이 함수가 종료되고 사라짐. 
	tNode* pNode = (tNode*)malloc(sizeof(tNode));

	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	//list는 첫번쨰 노드의 주소만 저장하므로 지금 만든 노드가 첫번째 노드인지 확인해야함. 
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else // 첫번째 노드가 아니라는 뜻
	{
		// 현재 가장 마지막 노드를 찾아서,
		// 해당 노드의 pNext 를 생성시킨 노드의 주소로 채움. 
		// 단방향 일때에는 처음노드부터 출발해야됨.
		tNode* pCurfinalNode = _pList->pHeadNode; // 이 헤드포인터가 망가지면 안되므로 포인터를 하나 받아서 해줌. 
		while(pCurfinalNode->pNextNode) // nullptr자체가 0이므로 이렇게 적어도 됨. nullptr != pCurfinalNode->pNextNode
		{

			pCurfinalNode = pCurfinalNode->pNextNode; // 현재노드의 nextnode파트가 채워져있으므로 다음 노드의 주소를 받아옴. 이 다음 노드의 주소로 조건문 시작. 

		}
		pCurfinalNode->pNextNode = pNode; // 마지막에서 2번째 노드에 주소를 저장.
	}
	++_pList->iCount;


}
void PushFront(tLinkedList* _pList, int _iData)
{
	// 새로 생성시킨 노드의 다음을 기존의 헤드로 지정한다.
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = _pList->pHeadNode;
	// 리스트의 헤드노드 포인터를 갱신해야 함.
	_pList->pHeadNode = pNode;

	// 데이터 카운트 증가.
	++_pList->iCount;
}
//재귀함수로 구현했을떄
void re_Release(tNode* _pNode)
{
	if (nullptr == _pNode)
	{
		return; // 다음 노드가 없으면 void 반환
	}
	re_Release(_pNode->pNextNode);
	free(_pNode);
}


void ReleaseList(tLinkedList* _pList)
{
	// 주소를 하나하나 해제해야됨. 
	// 재귀함수로 하면 데이터가 많을때 너무 많은 함수가 호출되므로 효율이 안좋음. 
	//re_Release(_pList->pHeadNode); //재귀함수.

	tNode* pDeletNode = _pList->pHeadNode;
	while (pDeletNode)//nullptr != pDeletNode
	{
		tNode* pNext = pDeletNode->pNextNode;
		free(pDeletNode);
		pDeletNode = pNext;
	}// for문으로 바꾸는게 더 간단할 수 있음.
}
