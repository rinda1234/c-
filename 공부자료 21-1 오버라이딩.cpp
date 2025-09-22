#include<iostream>
// 오버라이딩

// 중요! 면접 단골 멘트. 오버 로딩과 오버 라이딩의 차이. 

// 오버로딩은 함수명이 똑같은데 인자타입에 차이가 생겨서 컴파일러가 구별할 여지가 생긴것. 동시에 같은 이름의 함수가 여러개 존재할 수 있음. 인자의 타입과 개수가 다르면
// 오버라이딩은 상속관계에서만 발생함. 
// 자식클래스에서 부모 클래스의 함수를 재정의해서 쓸 수 있음. 

// 부모클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다. 

// 상속을 사용하는 상황 예
// 동물이라는 클래스를 상속받은 다양한 동물 클래스가 있는데 어떤 1개의 클래스만 부모클래스의 어떤 함수를 다르게 쓰고 싶을때 사용
class CParent
{
protected:
	int			m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}
	void Output()
	{
		std::cout << "Parent" << std::endl;
	}
public:
	CParent()
		: m_i(0)
	{}
	CParent(int a)
		:m_i(a)
	{}
	~CParent()
	{}
};

class CChild : public CParent 
{
private:
	float		m_f;
public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;  
	}
	void Output() //이런식으로 부모의 함수와 같은 이름으로 덮어 씌울수있음. child에서 Output을 호출하면 자식쪽에서 재정의한 함수가 호출됨. 
	{
		std::cout << "Child" << std::endl;
	}
public:
	CChild() 
		: 
		CParent(1000)
		, m_f(0)
		
	{
		m_i = 0; 
	}
	~CChild()
	{}
};

int main()
{
	CParent parent;
	CChild child;
	parent.Output(); // 이건 부모쪽 Output
	child.Output(); // 이건 자식쪽 Output 호출
	child.CParent::Output(); // 이런식으로 자식 객체에서 부모의 Output을 호출 할 수도 있음. 하지만 안씀.  
	return 0;
}