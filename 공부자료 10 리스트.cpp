#include<iostream>
#include "LinkedList.h"
int main()
{
	// 리스트는 가변배열과 비슷하지만 데이터가 다 따로따로 떨어져있음. 데이터가 연속되지 않음. 
	// 따라서 다음 데이터에 접근하는 방법이 특이함. 다음 데이터의 주소가 그 전 데이터에 들어있음. 
	// 리스트에서 데이터 1개를 저장하는 단위를 노드라고 함. 1개의 노드에는 데이터 + 다음 주소가 들어있음.  
	// 리스트에서 데이터를 저장하는 방법은 1개 저장할때마다 새롭게 1칸의 공간을 할당하는 방식.

	tLinkedList list;

	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);

	PushFront(&list, 400);
	PushFront(&list, 500);
	PushFront(&list, 600);

	tNode* pNode = list.pHeadNode; //pHeadNode 가 손상되지 않게 하기 위해.
	for (int i = 0; i < list.iCount; ++i)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}
	ReleaseList(&list);
	return 0;
}