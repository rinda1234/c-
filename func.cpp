#include "func.h"
#include "common.h"
#include<iostream>
//여기에 함수만듦. 

//정적변수 사용 가능
static int g_iStatic = 0; // 다른 파일에도 이 이름의 변수가 생성되더라도 상관없어짐. 
extern int iExtern = 0; // 이런식으로 초기화 시켜둬야함. 
void Test()
{
	std::cout << 1;
}
int Add(int a, int b)
{
	std::cout << "iExtern의 값은 : " << iExtern << std::endl;

	return a + b;
}

//다만 main 파일에서 정의한 전역변수를 이 파일에서 사용하지 못함. 