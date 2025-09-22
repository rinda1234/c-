#include<iostream>
class CTest
{
private:
	int m_i;


public:
	// 정적멤버함수
	// 객체 없이 호출 가능. 
	static void memcerFunc()
	{
		
	}
};

// 입출력 구현
// <<, >> 은 변수
// endl 은 함수. 
void MyEndL() //endl
{
	wprintf(L"\n");
}
class CMyOstream
{
public:
	CMyOstream& operator << (int _idata)
	{
		wprintf(L"%d", _idata);
		return *this; // 이어서 계속 연산해야 되므로 << 10 << 20 << 3.0; 이런 코드일 경우
	}
	CMyOstream& operator << (const wchar_t* _pSpring) // 2바이트 문자열 출력 오버로딩 
	{
		wprintf(L"%s", _pSpring);
		return *this; 
	}
	CMyOstream& operator >> (int& _idata) // 2바이트 문자열 출력 오버로딩 
	{
		scanf_s("%d", &_idata);
		return *this;
	}
	CMyOstream& operator << (void(*_pFunc)(void)) // endl 출력
	{
		_pFunc();
	}
};


CMyOstream mycout; // 만약 클래스에 아무것도 없는 클래스의 객체를 만들면 그 객체는 1바이트가 들어감. 


using namespace std; // 이 키워드를 만난 이후부터 namespace안에 있는 기능들을 바로 쓸수 있음
// 결과적으로 원래 namespace의 기능을 상실한 것이기 떄문에 썩 좋지만은 않음. 
// 따라서 namespace 전부를 완전 제거 하는게 아니라 특정 부분만 해제할 수 있음

using std::cout; //cout 한정해서 cout로 그냥 쓸 수 있음. 
using std::wcout; //이친구는 문자를 2바이트로 생각하고 출력. 
using std::cin; // cin 한정
using std::endl; //endl 한정


namespace MYSPACE //내가 이름을 MYSPACE 라고 그냥 지음
{
	int g_int;
}
int main()
{
	CTest::memcerFunc(); //이런식으로 객체 없이 호출 가능. 

	// namespace
	//g_int = 0; 이런식으로는 접근 못함
	MYSPACE::g_int = 0; // 이런식으로 namespace의 이름을 붙여서 사용해야 함.  
	
	// namespace를 사용하는 이유
	// 사용자가 이 std 라이브러리에 있는 변수를 그대로 사용할 수도 있기 떄문에
	// 만약 사용자가 cin이라는 변수를 쓰고 싶은데 std라이브러리에도 있어서 겹침
	// namespace로 이름공간을 다르게 해서 변수명중복을 막음. 
	// namespace를 쓰기 싫으면 using이라는 키워드 사용. 
	// std없이 쓸 수 있음. 

	// 같이 작업하는 사람들끼리 변수명이 겹치지 않게 하기 위해서도 사용. 
	cout << 1 << endl;

	// 비주얼 스튜디오가 표준을 쓰다 보니까 한글 설정이 제대로 안되어 있을 수 있음. 
	// 이럴경우 아스키 코드 대응 표를 한글로 바꿔줘야함. 

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean"); // 한글로 바꿔줌

	wcout << L"안녕" << endl; // 2바이트 문자열 
	// 입출력 구현
	mycout << 10;
	int a = 0;
	mycout >> a; // cin
	mycout << 10 << L" " << 20 << L" " << 30 << MyEndL;
	return 0;
}