#include<iostream>

void Output(const int*);
int main()
{
	
	int a = 100;
	Output(&a);

	// void 키워드
	// void는 반환타입이 존재하지 않는다는 의미. 
	void* pVoid = nullptr; //포인트 앞에 자료형에 의미가 역참조에 단위, 원본의 타입을 이 자료형으로 보겠다는 의미.
	// 따라서 void 로 보겠다는 의미. 
	//여기서는 원본으로 접근을 했을때 원본의 형태를 어떤 타입으로 볼지 정하지 않음.
	// 그러므로 어떤 변수의 주소도 다 받을 수 있음.
	{
		int a = 0;
		float f = 0.f;
		double d = 0.;
		long long ll = 0;

		pVoid = &a;
		pVoid = &f;
		pVoid = &d;
		pVoid = &ll;
		// 원본의 형태를 어떤 타입으로 볼지 정하지 않았으므로 역참조가 안됨.
		// 주소를 증가시키는 것도 안됨. 
		//예시
		//*pVoid;
		//pVoid + 1;
	}

	//void 포인터 정리
	// 1. 원본의 자료형을 정하지 않음. 
	// 2. 어떠한 타입의 변수의 주소든 다 저장 가능.
	// 3. 역참조 불가능
	// 4. 주소 연산 불가능. 

	return 0;
}
void Output(const int* pI) // 원본 데이터만 읽고 데이터를 수정하지는 않음.
{
	int i = *pI;
	// *pI = 100; //값을 수정할 수 는 없음. 
	// 강제 캐스팅으로 바꿀 수 있지만 하면 안됨. 
	// 예시
	int* pInt = (int*)pI;
	*pInt = 100;
}
//협업 할때 오해하지 못하도록 const로 명시해둬야함. 나는 데이터를 읽기만 하고 수정하진는 않을 거라고 명시해둬야함. 
// 단축기 
// ctrl + shift + space : 함수의 원형띄우기