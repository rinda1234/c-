#include<iostream>
// 대표적으로 Red-Black 이진탐색트리가 구현되어 있는 자료구조.  
#include<map>
// 이진탐색트리 기반에 탐색에 용이한 자료구조를 사용한 컴테이너
#include<set>
using std::map;
using std::make_pair;

using std::set; // set에 원래 std가 붙음. 

using std::wstring; // 문자열 클래스.
// map의 실사용 예시
#define MAN 1
#define WOMAN 2


struct tStdInfo //학생정보. 
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo() // c++ 에서는 구조체도 생성자를 만들 수 있음. 
		: szName{}
		, age{ 0 }
		, gender{ 0 }
	{

	}
	tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender)
		: szName{}
		, age{ _age }
		, gender{ _gender }
	{
		 // 문자열 배열이 구조체의 멤버일 경우에는 일반적인 초기화가 안됨. wchar_t* arr[100] = L"aasdf"; 이게 안됨. 
		// 따라서 _pName의 주소에 있는 데이터를 한땀 한땀 옮겨와야함. 
		wcscpy_s(szName, _pName);// 문자열 복사 함수. (목적지, 원본)
	}
};
// pair라는 구조체의 형태
struct pair
{
	const wchar_t* first;
	tStdInfo second;
};

class MyClass
{
private:
	int a;
public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
			return true;
		else
			return false; 
	}
	bool operator > (const MyClass& _other) const
	{
		if (a < _other.a)
			return false;
		else
			return true;
	}
};
int main()
{
	// 이진탐색: 문제를 절반씩 줄여가면서 찾는 행위 
	// 1. 이진탐색은 트리에서만 사용할 수 있는게 아님. 
	// 2. 정렬되어 있는 데이터에 적용 가능. 
	
	// 이진탐색트리 
	// 1. 이진탐색을 사용 할 수 있게 고안된 이진트리
	// 2. 데이터 입력시 O(log N) 효율
	// 3. 탐색효율은 O(log N) 

	// 4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	// - 자가 균형 기능 필요(AVL, Red/Black
	

	// set
	set<int> setInt;

	setInt.insert(100); // 데이터 삽입.  
	// 이진탐색트리는 힙메모리에 저장됨. 이 컨테이너의 객체는 루트노드의 주소만 저장하면 됨. 



	// set 보다 map을 더 많이 사용함. 
	// map
	map<int, float> mapData_1; // map 은 type을 2개를 지정함. 첫번째 타입은 그 노드의 키값, 2번쨰 타입은 실제 노드의 데이터의 자료형을 뜻함. 
	// 예를들어   100
	//          50   150
	// 이런 이진탐색트리가 있을때 50, 100, 150처럼 비교를 위한 숫자가 키값, 첫번째 타입임
	// 이런 숫자, 예를들어 50에 접근했을때 실제로 그 50이라는 숫자에 연결되어 있는 진짜 데이터. 2번째 타입.
	//  map<이름, 정보> 이렇게 알면 편함. 
	// 키값은 단순히 비교를 위해 사용되므로 실제데이터와 다르기 때문에 조금 더 실용적임. 
	
	// map의 실사용 예시
	// 학생의 이름과 정보. 
	map<const wchar_t*, tStdInfo> mapData;
	tStdInfo info(L"홍길동", 18, MAN);
	tStdInfo info2(L"이지혜", 25, WOMAN);

	mapData.insert( make_pair(L"홍길동", info) );
	mapData.insert( make_pair(L"이지혜", info2) );
	// make_pair 함수: 두녀석을 묶어서 1개의 짝으로 만듬. 홍길동이 키값이고 거기에 묶인게 info
	// 노드안에 이름정보와 실제 저장하고 싶은 데이터를 한개의 pair 로 봄. 
	// 노드안에는 이 pair 가 들어가는 거임. pair 안에 이름과 데이터 파트가 있을뿐. 
	map< const wchar_t*, tStdInfo>::iterator mapiter;
	// 이렇게 두 녀석을 묶어 놨기 때문에 나중에 찾을 수 있음. 
	mapiter = mapData.find(L"홍길동"); // 그 pair의 이름파트로 찾을 수 있음.  // 이건 문자열의 주소로 찾은거임. 
	// 이렇게 찾았을때 데이터 자체를 바로주는게 아닌 거기를 가리키는 iterator 를 반환함. 
	// 이 iterator에 접근하면 키값과, 데이터를 저장gk는 구조체가 들어있는 pair라는 구조체를 반환함. 
	
	_wsetlocale(LC_ALL, L"korean");
	// 데이터를 찾지못함.
	if (mapiter == mapData.end())
	{
		std::cout << L"데이터를 찾을 수 없다." << std::endl;
	}
	else
	{
		std::wcout << L"이름: " << mapiter->second.szName << std::endl;
		std::wcout << L"나이: " << mapiter->second.age << std::endl;
		std::wcout << L"성별: ";
		if (MAN == mapiter->second.gender)
		{
			std::wcout << L"남자" << std::endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			std::wcout << L"여자" << std::endl;
		}
		else
		{
			std::wcout << L"알 수 없음" << std::endl;
		}
	}
	(*mapiter).first;
	(*mapiter).second;// 이런식으로 pair의 구조체안의 멤버에 접근가능. 
	mapiter->first; //이런식으로 포인터가 아니지만 화살표로 표현할수 있게 구현되어 있음.
	
	// 사실 약간의 문자가 있음
	// map<const wchar_t*, tStdInfo> mapData; 
	// 이런식으로 const wchar_t* 로했을때 문자열의 크기를 비교하는게 맞나?
	// 문자열의 크기를 비교하는게 아닌 문자열의 주소값자체의 크기값이 비교가됨.  
	// 또한 이 데이터를 찾을때도 문자열의 주소값으로 찾게됨. 
	// 만약 pair를 찾을때 찾아달라고 넣을 키값을 L"홍길동" 같이 그 문자열의 주소값이 아닌 그 문자가 들어간 배열을 주면 안됨. 
	wchar_t szFind[20] = L"홍길동";
	mapiter = mapData.find(szFind); // 이렇게 문자열로 찾고 싶어도 주소가 아니므로 안됨. 

	// 따라서 우리가 첫번쨰 타입을 문자열로 비교하고 싶으면 문자열을 다루는 클래스를 넣어줘야 함. 
	// std::wstring

	map<wstring, tStdInfo> mapStdInfo;

	mapStdInfo.insert(make_pair(L"홍길동", info));
	
	
	
	// 뜬금없이 첫번째 키값에 내가 만든 클래스를 넣는다면?
	map<MyClass, tStdInfo> mapMy;
	MyClass a;
	mapMy.insert(make_pair(a, info)); // map은 템플릿 함수이므로 내부에 타입 T 에 따라 비교해서 이진탐색트리를 만드는 비교연산자가 있음. 
	// 하지만 T자리에 내가 만든 클래스가 들어갔을때 내가 만든 클래스 끼리 비교하는 연산자, 판정기준이 없으므로 안됨. 
	// MyClass 내부에 비교 연산자를 만들면 사용가능함. 
	// 
	// 즉 비교 연산자가 구현되어 있는 클래스만 map의 키값으로 쓸 수 있음. 


	// wstring 에 관한 간략한 설명. 
	// 얘도 동적할당함. 
	wstring str;
	str = L"asdf"; // 이렇게 객체에 저장하면 이 문자열 객체가 가진 공간의 내가 적은 문자열을 그대로 가져옴(주소가 아닌). 즉 자체적으로 문자열을 관리함. 
	str += L"hjkl"; // 이런식으로 뒤이어 붙일수도 있음. 
	str[1]; // 이런식으로 배열처럼 사용가능. 수정도 가능. 
	return 0;
}