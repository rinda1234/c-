#include<iostream>
// 상속될때 소멸자의 호출
// 소멸자는 호출이랑 실행 모두 자식쪽에서 먼저 이뤄지고 부모가 나중에 됨. 
// 소멸자 호출 실행, 자식 -> 부모 ***
// 중단점 걸어서 보면 보임 ./
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
	{
		std::cout << "부모소멸자" << std::endl;
	}
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
	void Output() 
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
	{
		std::cout << "자식소멸자" << std::endl;
		// 실제로는 보이지 않지만 여기에 부모의 소멸자를 호출하는 코드가 있음. 
	}
};

int main()
{
	CChild child;
	
	return 0;
}