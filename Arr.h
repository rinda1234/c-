#pragma once

typedef struct _tabArr // 가변배열 자료형
{
	int* pInt;//데이터를 저장할 곳의 시작주소를 알고 있어야 함.malloc으로 힙메모리에 공간을 만들기때문에  
	int iCount;//데이터를 넣어줄때 다음들어갈 데이터의 주소
	int iMaxCount;//iCount 값이 한계치( malloc(100) 이런식으로 공간을 만들었을때 끝까지 다 찼을때 공간을 늘려야 함으로.
}tArr; // 이렇게 3가지 멤버가 필수임.

// 초기화 함수
void InitArr(tArr* _pArr); // 바로 함수 원형 만드는 단축키 ctrrl + '+' + .

// 데이터 추가 함수
void PushBack(tArr* _pArr, int iData);

// 공간 추가 확장
//void Reallocate(tArr* pArr); // 나는 이걸 공간이 가득 찼을떄 실행시키고 싶은데 main함수에서 이 함수를 그냥 사용할 수 있음. 
// 헤더파일에서 지워버리면 main에서는 이것을 모르기 때문에 원치않는 접근을 차단할 수 있음. 

// 배열 메모리 해제 함수. 
void ReleaseArr(tArr* _pArr);

void Sort(tArr* _pArr, void(*SortFunc)(int*, int)); // 데이터 정렬 함수. // 정렬 기능 함수를 인자로 받음. 

//함수의 주소를 받는 방법은. 