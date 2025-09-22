#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int main()
{
	//const
	const int cint = 100; 
	volatile const int cint_1 = 100; // volatile이라는걸 쓰면 레지스터 연산을 쓰지 말고 명확하게 여기에 들어있는 값을 확인해서 쓰라고 명시해둠. 
	// 상수화
	// r-value : 상수
	// l-value : 변수, 바뀔 수 있는 값

	// const는 문법적으로 수정 못하게 막아주는거지 정말 값이 바뀌지 않는 건 아님. 포인터로 접근해서 바꿔버릴 수 있음. 
	int* k = (int*)&cint; // const int 를 int*로 강제 캐스팅

	*k = 500;
	printf("cint 출력 : %d\n", cint); // cint를 강제 접근해서 500으로 바뀌지만 실제 출력될때는 cpu가 중간에 레지스터에 기억하고 있던 100을 받아서 씀. (레지스터로 연산하기 때문에 중간에 값이 제대로 들어있는지 확인하지 않음. const이기 때문에 )
	// 이게 const이기 때문에 중간에 바뀌지 않을 거라고 생각해서 cpu는 중간에 저장되어있던 100이라는 값을 씀. 바꾼게 잘못이라는 마인드 


	// const 와 포인터
	int a = 0;
	int* pInt = &a;
	*pInt = 1;
	pInt = nullptr; // 원래 이런식으로 주소를 초기화 가능;


	// 1. const 포인터 : const가 포인터를 수식(별보다 앞에 있음.)

	const int* pConstInt = &a; 
	//*pConstInt = 100; // r_value라 변경이 안됨 
	// 다른변수를 가르킬수는 있음.
	int b = 0;
	pConstInt = &b;

	//2. 포인터 const : 변수 자체가 상수화 됨. 주소값을 바꿀 수 없음. 
	//별보다 뒤에 있음. 
	int* const pIntConst = &a;
	*pIntConst = 400; //값을 변경 할 수 있음. 
	//pIntConst = &b; //다른 주소를 받을 수 없음. 

	//초기화 시 가리킨 대상만 기리킴, 가리키는 원본을 수정 할 수 없음. 
	const int* const pConstIntConst = nullptr; 

	// 이건 const 포인터에 해당함. : 별보다 앞에 있기 때문에 
	int const* p = &a;

	//예시
	{
		int a = 0;
		const int* pInt = &a;
		a = 100;//a 로접근할때는 수정 가능. 
		//const 포인터 라 값을 바꿀 수 없지만 포인터로 가르킬때만 수정 불가능한거임.
	
	}
	return 0;
}