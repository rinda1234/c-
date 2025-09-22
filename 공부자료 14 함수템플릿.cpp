#include<iostream>

int Add(int a, int b)
{
	return a + b;
}

float Add(float a, float b)
{
	return a + b;
}
// 이런식으로 똑같은 함수를 자료형에 따라 많이 만들어야하는경우 -> 템플릿
// 템플릿은 템플릿의 typename자리에 어떤게 들어갈지 전달해야 그제서야 함수가 만들어짐. 
// 즉 이 템플릿을 이용해서 함수를 호출해야 그때 함수가 생김
// 만약 int버전 한개를 만들면 그 뒤에 또 int로 호출해도 추가로 함수가 만들어지지는 않음. 
template<typename T> // typename을 class 라고 바꿔도됨.  이건 함수가 아니라 함수를 만들수 있게 하는 틀임. 
T Add(T a, T b)
{
	return a + b;
}

int main()
{
	// 함수 템플릿
	int i = Add<int>(10, 20); //이런식으로 쓸 수 있음. 이때 함수가 만들어짐. 
	
	
	
	return 0;

}