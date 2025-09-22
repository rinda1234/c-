#pragma once
// 리스트의 장점
// 배열이였으면 PushFront처럼 앞에 데이터를 넣고 싶을떄 모든 데이터를 한칸씩 뒤로 이동시켜야 하지만 연결형 리스트는 쉽게 할 수 있음. 
// 중간이너 처음에 데이터를 끼워넣기 좋음


// 리스트의 단점. 
// 가변배열은 메모리 구조가 특정 위치에 접근하는 과정에서 데이터 개수가 영향을 끼치지 않는데 리스트는 영향을 끼침. 
typedef struct _tagNode
{
	int iData;
	_tagNode* pNextNode; //다른 노드에 주소를 가리켜야함. //이 구조체 내에서는 아직 _tagNode의 이름을 tNode라고 재정의 하기 전이므로 원래 이름으로 사용해야 함. 
}tNode; // 리스트에는 노드라는 개념이 필요하므로 

// 이 아래에서 부터는 tNode로 적어도 됨

typedef struct _tagList // 연결형 리스트 (단방향) 마지막 주소를 모름. 
{
	tNode* pHeadNode; // 리스트는 첫번쨰 노드의 주소는 알고 있어야 함.
	int iCount; // 노드의 개수
	//int iMaxCount; // 얘는 1개의 데이터를 저장할때마다 1개의 공간을 새롭게 할당하므로 최대크기의 개념이 필요 없음. 

}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList); // 초기화를 할떄 아직 아무 노드도 생성되지 않았으므로 첫번째 노드의 주소를 가르키지 않고 카운트도 0이여야 함.

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);

// 제일 앞쪽에 데이터 넣기
void PushFront(tLinkedList * _pList, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);

