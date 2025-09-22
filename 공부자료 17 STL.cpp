#include <iostream>
#include <vector> // 표준으로 제공해주는 가변배열
#include <list> //표준으로 제동해주는 연결형 리스트
#include "TArr.h"

class CTest
{
public:
	int m_i;
public:
	// 클래스를 생성할때 이런 기본 생성자, 기본소멸자, 클래스 끼리 대입하는 대입연산자는 기본으로 생성됨. (내가 안만들어도 알아서 만들어짐
	CTest()
		: m_i(0)
	{
	}
	~CTest() {};
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	// 복사 생성자. 
	// 이것도 내가 안만들어도 자동으로 만들어짐. 
	// 복사생성자도 크게보면 연산자 오버로딩이기 떄문에 만약 자동으로 만들어진게 아닌 내가 이렇게 직접 만들어 두면 기본 생성자가 자동으로 안만들어짐. 즉 생성자가 복사생성자밖에 안만들어짐.
	// 따라서 이렇게 복사생성자를 만들어 둘거면 생성자를 만들어줘야함. 
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{
	}
};



int main()
{
	// 우리가 만든 함수 이름하고 같음 
	std::vector<int> vecInt; // 이것도 using std::vector해주면 편함.
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100; // 연산자 오버로딩도 되어있음
	vecInt.at(1); // 특정 인덱스로 접근해서 값을 레퍼런스 반환해주는것 
	// 즉 vecInt[1]; 이랑 같음. 
	vecInt.data(); // 배열의 첫번째 주소 반환. 
	vecInt.size(); //현재 가변배열안에 데이터가 몇개 들어가 있는지 반환
	vecInt.capacity(); // 현재 가변배열안에 최대 몇개의 데이터를 넣을 수 있는지 반환

	std::list<int> listInt; //이건 앞에도 넣을수 있음 리스트 이기 때문에 
	listInt.push_back(10);
	listInt.push_front(100);
	listInt.size();
	listInt.begin(); //첫 주소를 가리킴. 
	std::list<int>::iterator iter_1 = listInt.begin();
	iter_1 = listInt.insert(iter_1, 100); // iterator가 가리키고 있는 앞쪽에 데이터를 추가함. 
	// 리스트에 있는 데이터를 전부 순회하고 싶을때 
	// vector는 이런식으로 하면 됨. 
	for (size_t i = 0; i < vecInt.size(); ++i ) //size_t는 8바이트 자료형임(long long) vector가 8바이트라 맞춰준거. 
	{
	std::cout << vecInt[i] << std::endl;
	}


	// 리스트는 시작 노드를 꺼내와서 다음 노드, 다음 노드에 계속 접근해야함. 
	// 즉 내부를 잘 알고있어야하는데 그건 힘듬.  그래서 나온게 반복자
	// iterator
	std::list<int>::iterator iter = listInt.begin(); //iterator도 클래스임 .이렇게 클래스 안에 있는 클래스를 포함 클래스, 내부 클래스, 이너 클래스라 부름. 
	// 이 객체가 첫주소를 가리킴 
	// begin()은 반환타입이 iterator다. iter가 받기 때문에 .
	int iData = *iter; // 이러면 첫번째 자료를 iData에 저장함. 마치 포인터 처럼 동작. 하지만 클래스기 때문에 연산자 오버로딩으로 *을 붙임. 역참조되는듯이 하게.  

	// 즉 iterator는 포인터처럼 쓸 수 있음. 
	// iterator 라는 반복자를 이용해서 내부에 있는 데이터에 접근하고 순회할수 있게 하는게 반복자다. 
	// vector 든 list든 둘다 구현되어 있음. 그러나 둘은 다름. vector클래스 안에 구현되어 있는 iterator 클래스, list 클래스 안에 구현되어 있는 iterator 클래스
	// 대부분의 자료구조에 구현되어 있음. 구현방식은 다르더라도(각각의 자료구조마다 하는 방식이 다르므로) 사용자가 쓰기엔 비슷하게 구현되어 있음. 
	// 다 비슷비슷하게 사용가능하다. 

	// 1. vector버전
	std::vector<int>::iterator veciter = vecInt.begin();
	*veciter; // vecint[0] 같은말. 
	*veciter = 100; // 값바꾸기 가능. 
	++veciter; // 주소를 증가시킴. 
	*veciter;// veciter[1] 과 같음. 
	
	// vector는 가변배열이기 때문에 굳이 iterator를 안쓰고 원래 함수로 접근할 수 있다고 생각할 수 있음. 
	// 그러나 중간에 데이터를 삭제하고 싶을때 iterator를 써야 가능. 데이터를 삭제하고 앞으로 다 땅겨야 하기 때문에 
	vecInt.erase(veciter); // 인자로 iterator를 받음. iterator 가 가르키고 있는 부분을 삭제 
	//iterator는 앞으로 자료를 떙겨줌. 



	// 2. list 버전
	std::list<int>::iterator liter = listInt.begin();
	*liter = 10;
	++liter; //주소가 1늘어남. 
	*liter; //liter[1]
	// 중간에 데이터를 지우고 싶을때
	listInt.erase(liter); //이것도 literator를 받음. 즉 다른 자료구조도 다 비슷하다. 

	// iterator를 이용한 순회
	// iterator를 이용해 주소를 하나하나 늘려서 중간에 값에 접근해야 함. 

	for (liter = listInt.begin(); liter != listInt.end() ; ++liter) //end()가 지칭하는건 자료가 들어있는 컨테이너(배열이든, 리스트든) 마지막 리스트(여기선 리스트) 보다 하나더 다음을 지칭함.  즉 end는 마지막 데이터를 가리키는게 아님. 
	{
		//std::cout << *liter << std::endl;
	}


	// Auto 키워드
	// i자동으로 타입을 정해주는 키워드
	// iterator를 이렇게 선언할 수 있음. 
	auto myliter = listInt.begin();

	//int 도 이렇게 정의할 수 있음. 
	int a = 5;
	auto b = 9; 
	auto c = b;


	std::list<int> ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.push_back(40);
	
	std::list<int>::iterator literator = ll.begin();;
	std::cout << ll.size() << " " << * literator << std::endl;
	ll.erase(literator);
	std::cout << ll.size() << std::endl;

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	std::vector<int>::iterator Myveciter = vec.begin();

	vec.erase(Myveciter);
	std::cout << vec[0] << std::endl;
	
	
	// iterator 만들기: Tary와 TLinkedList파일 가보기. 

	CArr<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	CArr<int>::iterator myiter = myvector.begin();
	++(++myiter);
	std::cout << *myiter << std::endl;
	// *myiter;
	// ++(전위, 후위), --(전위, 후위), ==, != 이런연산자도 필요함. 
	// 
	--(--myiter);
	for (; myiter != myvector.end(); ++myiter)
	{
		std::cout << *myiter << std::endl;
	}

	// 후위 연산
	myiter = myvector.begin();

	int iData_1 = (*myiter++); //후위연산은 모든일을 끝마친 뒤에 연산이 된다. 그러나 호출은 먼저 됨. 호출이 되더라도 연산을 나중에 하는 새로운 함수로 해줘야함. 
	// 후위연산처럼 속이는 거임.  
	// 후위연산은 필요없는 객체의 생성과 소멸이 생기므로 비효울적임. 따라서 왠만하면 전위연산. 
	// 함수내부에서 객체를 1번생성한뒤 그걸 복사해서 반환할때 1개 더생김. 따라서 2개가 만들어졌다 소멸함. 
	
	//복사생성자. : 객체 생성과 대입을 동시에함. 

	CTest t1;
	t1.m_i = 100;

	CTest t2;
	t2 = t1; //대입연산. 

	CTest t3(t1); // 복사생성자. 
	
	CTest t4 = t1; // 이것도 복사생성자. 대입연산처럼 보이지만 컴파일러가 자동으로 CTest t4(t1)으로 바꿔줌. 면접 단골문제. 
	
	// vector::erase
	std::vector<int> vec1;
	vec1.push_back(100);
	vec1.push_back(200);
	vec1.push_back(300);
	vec1.push_back(400);

	std::vector<int>::iterator veciter1 = vec1.begin();
	veciter1 = vec1.erase(veciter1); // iterator가 기리키는 부분을 삭제. 가변배열 특성상 데이터들이 다 앞으로 떙겨짐. 
	// 이런식으로 erase가 반환한 iterator를 veciter1에 저장해야함. 
	int i = *veciter1; //erase가 반환하는 iterator를 원래 iterator에 저장하기 전에는 이건 안됨. 왜냐 삭제된 곳을 가리키고 있기 때문에. 즉 
	
	vec1.clear();// 들어있는 데이터를 전부 날려버림. 

	// 1~11을 넣어줌. 
	for(int i = 0; i < 11; ++i)
	{
		vec1.push_back(i + 1);
	}
/*
	// 짝수만 제거
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); ++veciter1)
	{
		if (0 == *veciter1 % 2) 
		{
			// 제거
			//vec1.erase(veciter1); //이 iterator는 다시 쓸 수 없음. 그런데 다시 반복해서 사용하므로 이렇게 쓸 수 없음. 
			veciter1 = vec1.erase(veciter1); //이런식으러 veciter1에 다시 받아줘야함. 
		}
	}

	// 1 ~ 5 숫자 제거
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); veciter1)
	{
		if (1 <= *veciter1 && *veciter1 <= 5)
		{
			// 제거
			//vec1.erase(veciter1); //이 iterator는 다시 쓸 수 없음. 그런데 다시 반복해서 사용하므로 이렇게 쓸 수 없음. 
			veciter1 = vec1.erase(veciter1); //이런식으러 veciter1에 다시 받아줘야함. 
		}
	}
	// 이런식으로 하면 원래 지워져야할 2와 4가 살아있음. 
	// veciter가 erase후 그 다음 요소를 가리키고 있는 iterator를 받음. 즉 첫번째 자리를 지우고 그 다음 요소를 떙겨온다음 그 요소의 iterator를 반환함. 
	// 그런데 그 주소에 ++veciter1으로 그 다음 요소를 가리키게 만들면 결과적으로 원래 2번쨰 자리였던 데이터는 검사를 안당함. 첫번째 자리로 옮겨졌고, 이제 2번째 자리를 검사할 차례이기 때문에. 
*/

	// 보완한 1~5 숫자 제거
	// 이런식으로 2가지 케이스로 나눠서 해야됨. 
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); )
	{
		if (1 <= *veciter1 && *veciter1 <= 5) // 1. 숫자가 1~5사이일때
		{
			// 제거 
			veciter1 = vec.erase(veciter1);
		}
		else // 1~5사이가 아닐땐 veciter1 증가. 
		{
			++veciter1;
		}
	}
	// 이런게 문제로 나올 수 있음. 다음 코드상에 문제점을 찾아라 이런시긍로.
	// 이게 iterator 사용할 때 기초사항 중 하나임. 
	for (int i = 0; i < vec1.size(); ++i)
	{
		std::cout << vec1[i] << std::endl;
	}
	return 0;


	

}

