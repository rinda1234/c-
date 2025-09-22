#include<iostream>
#define HUNGRY 0x001//1번째칸
#define THIRSTY 0x002//이 비트가 2번째 칸에 들어와야 되므로 값이 2여야 됨. 16진수로 표현. 
#define TIRED 0x004//이 비트가 3번째 칸에 들어와야 되므로 값이 4여야 됨.
#define COLD 0x008//이 비트가 4번째 칸에 들어와야 되므로 값이 8여야 됨
#define FIRE 0x010// 이 비트가 5번쨰 칸에 들어와야 되므로 값이 16이여야됨. 
#define POISON 0x020//32
#define FIRE 0x040//64
#define FIRE 0x080 // 128
#define FIRE 0x100//256
#define FIRE 0x200//512

int factorial(int);
int factorial2(int, int);
void PrintArray(const int*, int);


//장점
//1. 가독성
//2. 유지보수.

int main()
{
	//switch문은 전부 break를 넣어줘야 그 부분만 실행되고 다른 부분은 실행안됨

	int data = 10;
	switch (10)
	{
	case 10:
		break;
	case 20:
		break;

	default:
		break;
	}
	//만약 break를 안넣으면
	switch (data)
	{
	case 10:
	case 20:
		break;
	default:
		break;
		//이런식으로 data가 10과 20일때 실행되게 만들 수 있음. 


	}
	// 삼항 연산자
	data == 20 ? data = 100 : data = 200; //data가 20이먄 앞에 코드(data = 100)을 실행하고 아니면 뒤에 연산을 실행함
	//비트연산자
	//비트 단위로 연산이 진행될때 사용되는 연산자
	//1. 비트 쉬프트 <<, >>(비트를 화살표가 가르키는 방향으로 한칸씩이동 EX) 0001 << 0010) 
	unsigned char byte = 10;
	byte <<= 3; //2^n배수
	byte >>= 2; //2^n 나눈 몫

	//비트 곱(&), 합(|), xor(^) 반전(~) 
	//곱 비트 둘다 1이어야 1(0001 & 0011 = 0001)
	//합 둘 중 하니만 1어도 1(0001 | 0011 = 0011)
	//반전 말그대로 비트를 반전시킴 (0001 -> 1110)
	//xor 두 자리의 비트가 같으면 0 다르면 1(0001 xor 0011 = 0010)
	//비트 연산은 게임에서 주로 
	int iStatus = HUNGRY; // 32비트에 HUNGRY값이 들어감. 
	//이 32비트를 이용해서 특정 상태(여러종류의 상태의 조합)를 표현할수있음. 이런 상태를 표현하기 위해서는 겹치지 않는 자리가 필요함.
	// 0001(맨 뒷자리가 1이면 배가 안고픈거고 0이면 배고픈거, 2번째칸이 0이면 목마른거, 3번째칸이 0이면 피곤한거, 이런식으로 활용 가능. 

	iStatus |= THIRSTY; //배고프면서 목마른 상태 표현 (비트합으로 표현)
	//피곤함도 표현하고 싶으면 
	iStatus |= TIRED;

	//이러고 어떤 상태인지 체크할때(ex) 목마른지 궁금할때)
	//내가 지정한 자리에있는 비트만 1인지 확인하는 방법. 
	if (iStatus & THIRSTY) // 목마르면 뭐를 한다. 이렇게 코드를 만들 수 있음. 
	{

	}
	//어떤 상태를 제거하고 싶을때. 특정자리에 있는 비트 제거. 
	iStatus &= ~THIRSTY; // 반전을 하고 곱해야 그 부분만 지워짐. 

	// printf
	printf("asdf \n");
	printf("asdf %d  \n", 10); //#d 는 오른쪽에서 정수를 찾아서 넣는거
	printf("asdf %f  \n", 3.314f); //#f 는 오른쪽에서 실수를 찾아서 넣는거
	for (int i = 0; i < 10; ++i)
	{
		printf("output : %d \n", i);
		std::cout << "out put: " << i << std::endl;
	}
	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);	

	// 자료구조 
	// stack : 선입 후출
	// 큐 : 선입 선출

	//함수
	// factirial

	std::cout << factorial(3) << std::endl;
	//다른 방식의 factorial
	int i = 3; // factorial 하고 싶은 숫자
	int iValue = 1;
	iValue = factorial2(i, iValue);
	std::cout << iValue;

	int myNumbers[] = { 1,2,3,4,5 };
	PrintArray(myNumbers, 5);
	return 0;
}
int factorial(int n)//recursive (재귀) 
{
	if (n == 0)
		return 1;
	else
		return(n*factorial(n - 1));
}
int factorial2(int ival, int ivalueval)
{
	for (int j = 0; j < ival - 1; ++j)
	{
		ivalueval *= (j + 2);
	}
	return ivalueval;
}
void PrintArray(const int* numbers, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
}



//단축기
// 지정한 구문 주석          : ctrl + k, c 컨트롤 누르고 k c 누르기
// 지정한 구문 주석 해제     : ctrl + k, u
// alt Drag                  : 원하는 영역만 드레그 

// 디버깅 관련 단축기
// 디버깅 시작 : F5  다음 중단점 까지 실행
// 중단점 생성 및 해제 : F9
// 디버깅 중, 구문 수행 : F10 한 문장씩 수행하고 싶을때
// 디버깅 중, 한단계식 실행: F11  함수진입(가장 낮은 단계) 
// 그 함수의 선언, 정의 파트로 이동 : F12