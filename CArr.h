#pragma once


// 클래스를 이용한 가변배열

class CArr
{
private: // private를 안적어도 기본이 private임. 
	int* m_pData; // 헝가리안 표기법. 지역변수랑 구별되기 위해사용 앞에 m 붙여주기
	int m_iCount;
	int m_iMaxCount;
public:
	// 생성자를 public에 만들어야 객체를 통해 컴파일러가 생성자를 호출할 수 있음. 
	// 헤더파일에서 생성자를 구현하지 않고 정의만 해줌. 
	CArr();
	~CArr();
public:
	void push_back(int _iData);// 애초에 이 클래스의 멤버함수이기 때문에 객체를 인자로 받을 필요가 없음. 
	void resize(int _iResizeCount);// 이번에는 사용자가 공간을 늘릴 수 있음. 

	// 연산자 오버로딩
	int& operator[](int idx);
};

