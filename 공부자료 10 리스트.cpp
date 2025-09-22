#include<iostream>
#include "LinkedList.h"
int main()
{
	// ����Ʈ�� �����迭�� ��������� �����Ͱ� �� ���ε��� ����������. �����Ͱ� ���ӵ��� ����. 
	// ���� ���� �����Ϳ� �����ϴ� ����� Ư����. ���� �������� �ּҰ� �� �� �����Ϳ� �������. 
	// ����Ʈ���� ������ 1���� �����ϴ� ������ ����� ��. 1���� ��忡�� ������ + ���� �ּҰ� �������.  
	// ����Ʈ���� �����͸� �����ϴ� ����� 1�� �����Ҷ����� ���Ӱ� 1ĭ�� ������ �Ҵ��ϴ� ���.

	tLinkedList list;

	InitList(&list);

	PushBack(&list, 100);
	PushBack(&list, 200);
	PushBack(&list, 300);

	PushFront(&list, 400);
	PushFront(&list, 500);
	PushFront(&list, 600);

	tNode* pNode = list.pHeadNode; //pHeadNode �� �ջ���� �ʰ� �ϱ� ����.
	for (int i = 0; i < list.iCount; ++i)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}
	ReleaseList(&list);
	return 0;
}