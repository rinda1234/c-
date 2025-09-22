#include<iostream>

// 열거형
enum MY_TYPE //enum이라는 것을 정의하고 이 열거형의 이름을 MY_TYPE이라고 정의해줌
{
	TYPE_1,  //0  
	TYPE_2,  //1
	TYPE_3,  //2    // 이런식으로 계속해서 내가 원하는 이름을 나열하면 컴파일러는 이녀석들을 0부터 시작해서 쭉 연속된 숫자라고 받아들임. 
	TYPE_4,	 //3
	TYPE_5 = 100,   // 숫자를 지정해줄수 있음. 
	TYPE_6,  //101	// 그 뒤부터는 지정한 숫자부터 쭉 올라감. 
	TYPE_7,  //102
};

enum OTHER_TYPE
{
	//TYPE_1, // 이런식으로 했을때 MY_TYPE에 TYPE_1인지 OTHER_TYPE에 TYPE_1인지 모름. 
	// 이래서 나온게 enum class
};

enum class MY_DATA
{
	DATA_1,
	DATA_2,
	DATA_3,
	DATA_4,
	DATA_5,
	
};
enum class OTHER_DATA
{
	DATA_1,
	DATA_2,
	DATA_3,
	DATA_4,
	DATA_5,

};
#define CLASS_1 0  //이런 전처리기와 enum은 비슷함. 
// 그러나 전처리기라는 것은 컴파일이 되기 이전에 먼저 실행됨. 컴파일 되면 사실상 코드에 CLASS_1 대신 0이 들어가 있는 것임. 
// 하지만 enum은 enum이라는 이름정보자체가 심볼테이블에 남음. 따라서 디버깅을 할때 a에 단순히 0을집어넣었다고 생각하지 않고 컴파일러가 MY_TYPE enum 타입에 있는 TYPE_1이라는 값을 넣었다고 생각함.
// 따라서 디버깅을 할때 타입이 정확히 잡힘. 어떤 녀석을 넣었는지. 따라서 예외처리를 할때 좀 더 많은 정보를 얻을 수 있음. 
// 예를들어 플레이어 타입을 넣고 싶었는데 몬스터 타입이 들어옴. 
//#define은 그냥 숫자만 a에 숫자가 0이 들어온것만 나옴. 일일히 확인해야됨. 뭘로 정의했는지. 
int main()
{
	int a = TYPE_1; // a 에 0가 들어감. 

	// enum class 를 쓰면 반드시 enum의 몸체까지 알려줘야함. 
	// 또한, 별개의 타입으로 보기 떄문에 정수로 바꾸고 싶을때에는 명시적으로 캐스팅해줘야함. 

	int b = (int)MY_DATA::DATA_1;
	int c = (int)OTHER_DATA::DATA_1;

	// 기존에 enum은 쓰기는 편했지만 이름이 겹칠 수 있음.
	// 따라서 불편함을 감수하더라고 enum class 로 작성하는게 훨씬 명시적이고 이름이 재정의되고 중복되는 문제를 피할 수 있다. 

	return 0;

	// ENUMCBST.h 비교 
}