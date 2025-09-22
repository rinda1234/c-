#include "func.h"
#include "common.h"
//헤더파일 사용 방법
int main()
{
	int a = 0;
	Test();
	iExtern = 100;
	Add(0, 0); // 외부변수를 사용한 예시. main.cpp 에서 100의 값을 넣었는데 func에서 그걸 출력 함. 
	return 0;
}