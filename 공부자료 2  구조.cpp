#include<iostream>

typedef struct _tagMyST
{
	int a;  //이 자체로 실제하는게 아님. 걍 내가 어떻게 쓸지 명시해 둔거. 
	float f;
}MYST; //이게 자료형이 됨.
//int 랑 float자료형을 같이 묶어서 자료형을 만드는 거임. 8 byte

typedef struct _tagBig
{
	MYST k; //이런식으로 모듈화를 할 수 있음. 다른 구조체에 사용가능.
	int i;		
	char c;
}BIG;
//typedef 은 재정의 해준다는 의미.
typedef int INT; //INT를 int로 사용가능. 

struct NewStruct
{
	int a;
	short s;
};//이런식으로  typedef을 하지 않고 구조체를 만들면 구조체를 사용할때 struct 키워드를 계속붙여야함. 
//하지만 c에서만 이렇고 c++에서는 개선됨. 
int main()
{
	//구조체 
	// 구조체는 사용자가 직접 정의한 자료형. 
	MYST t;
	t.a = 10;
	t.f = 10.2312f; // 이런식으로 구조체 이름에 그 변수에 이름을 적어서 사용.
	struct NewStruct NEWST;
	NewStruct NEWST1; //C++에서는 이런식으로 개선됨. 그러나 타입재정의를 해줘야 c와 c++ 둘에서 범용적으로 사용가능. 
	//구조체 초기화
	MYST ST = { 10, 10.123f }; //이런식으로 배열처럼 초기화 가능. 
	return 0;
}