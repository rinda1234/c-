#include<iostream>
class CParent
{
protected:
	int			m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}
	virtual void Output() //부모클래스의 오버라이딩된 함수를 가상함수로 만들면 됨.  
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
	virtual ~CParent()
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
	virtual void Output()
	{
		std::cout << "Child" << std::endl;
	}
	void NewFunc()
	{
		this->m_f = 3.14f;
	}
public:
	CChild()
		:
		CParent(1000)
		, m_f(0)
	{
		m_i = 0;
	}
	virtual ~CChild()
	{
		std::cout << "자식소멸자" << std::endl;
		
	}
};
int main()
{
	// 객체지향 언어 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성

	// 다형성
	// 객체지향을 지원하는 언어에는 다 존재
	// 최상위 부모 포인터 타입으로 주소변수를 관리하되 이 주소의 객체가 누구든지 될 수 있음. 자식 클래스이면 

	// 상속 And 포인터
	// 부모포인터 타입으로 자식클래스 주소를 받을수 있음.
	// 하지만 자식클래스 포인터 타입으로 부모클래스 주소를 받을 수 없음. 
	// 이렇게 부모포인터 타입으로 가리키는 자식클래스의 주소를 계속 바꾸면 게속 다른 자식을 가리킬 수 있음. 
	// 하지만 부모 부분까지 밖에 모르기 때문에 실제 어떤 자식의 객체인지 포인터는 모름. 
	// 부모포인터로 자식클래스의 주소를 카리키고 오버라이딩된 함수를 호출했을때 부모클래스의 함수가 호출됨.
	// 이 문제를 해결하기 위한 방법 -> 가상함수(virtual)

	// 가상함수(virtual)
	// 부모클래스의 오버라이딩된 함수를 가상함수로 만들면 자식객체를 가리키는 부모포인터 타입이 오버라이딩된 함수를 호출했을때 실제 객체인 자식클래스의 오버라이딩 된 함수를 호출함. 
	CParent parent;
	CChild child;

	parent.Output();
	child.Output();
	child.SetInt(10);
	
	// 1
	//CParent* pParent = &parent; ---(1) //parent 포인터로 parent를 받아서 문제 없음. 
	//CChild* pChild = &child;	  ---(2)
	
	//2
	//CParent* pParent = &child;  ---(1) // 포인터 앞에 자료형은 이 주소로 접근할때 이 공간의 형태를 CParent 객체로 보기로 함.(이 공간을 parent로 읽고 parent 크기만큼만 접근함. )  
										 // 그런데 child 는 상속받았기 때문에 데이터가 (시작주소)parent child 순으로 저장됨
										 // 따라서 이 포인터로 역참조 했을때 이 공간을 CParent로 보는데 제일 처음 부분이 parent 부분이므로 문제가 없음. 
	
    //CChild* pChild = &parent;	  ---(2) // parent 객체는 데이터가 parent만 있음. 
										 // CChild 객체는 이 포인터가 가리키는 공간을 child로 보고 접근하므로 parent 뒤에 child까지 보게됨. 
										 // 하지만 paretnr객체 뒤에는 child가 당연히 없음. 
										 // 따라서 문법오류 
	
	CParent* pParent = &child;
	pParent; //pParent가 가리키는 자식객체의 주소만 달라지면 어떨떄는 사자고 어떨떄는 개고 이런것이 가능함. 
			 // 하지만 부모 부분까지 밖에 모르기 때문에 실제 어떤 자식의 객체인지 포인터는 모름. 
	
	pParent = &parent;
	pParent->Output();

	pParent = &child; // 이렇게 자식객체를 가리키고 함수를 호출하면 오버라이딩 된 child 의 Output함수가 호출되야 하는데 parent의 output이 호출됨. 
	pParent->Output();// 실제 객체가 child지만 이 포인터는 parent 포인터 타입이기 때문에 부모의 함수를 호출함. 즉 문법적으로 오류만 없던거임.  
					  // 오버라이딩 된 함수를 가상함수로 만들면 문제해결 자식객체의 오버라이딩 된 함수를 호출함. 
					  // 이런 방법으로 부모클래스 포인터가 어떤 자식객체의 주소든 가리킬 수 있게 됨. 
	
	// 가상함수의 호출원리 
	// 상위클래스의 포인터로 자식객체를 다룰때 함수를 호출할때 가상함수면 내가 접근한 객체의 테이블로 가서 거기에 등록되어 있는 함수를 호출함. 
	// 가상함수가 있으면 각자 클래스 정보에 해당 함수들을 등록시켜 놓는데 해당 객체들은 만들어 질때 가상함수테이블 포인터(vptr)가 각자 자기쪽 정보들을 세팅하면서 만들어짐.
	// 이 함수를 호출하게 될 경우 이 테이블을 참조해서 거기 등록되어 있는 함수를 호출함. 그래서 자기 쪽에 구현되어 있는 함수를 호출하게됨.  
	
	
	
	
	// 다형성, 가상함수(virtual)
	// 부모 포인터 타입으로 ,부모 클래스로부터 파생되는 자식클래스 객체들의 주소를 가리킬 수 있다.
	// 모든 객체를 부모클래스 타입으로 인식하게 되기 떄문에, 실제 객체가 무엇인지 알 수 없다.
	// virtual 키워드를 통해서, 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다. 
	// 그 테이블에는 해당 클래스의 가상함수들이 등록

	// 다운캐스팅
	// 부모 클래스에서 선언되지 얺은, 오직 자식쪽에서만 추가된 함수를 호출 하고 싶을 때
	// 자식 포인터 타입으로 일시적으로 캐스팅 해서 호출한다. 
	// 문제가 발생 할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	// RTTI (Run Time Type Identification Information): c++에서 RTTI는 아래와 같이 작동함. 


	((CChild*)pParent)->NewFunc(); // 자식포인터로 캐스팅해 호출, 문제가 있을 수 있ㅇ음. 
	// 만약 pParent가 parent 객체를 가리키고 있으면 자식클래스의 부분이 없으므로 오루가 남. 
	CChild* pChild = dynamic_cast<CChild*>(pParent); 
	if (nullptr != pChild) // 만약 pChild가 이닌 다른 클래스의 객체를 가리키고 있으면 함수가 호출이 안됨. 
	{
		pChild->NewFunc(); // 이렇게 dtnamic_cast로 함수를 작동시키면 런타임 도중에 이 객체가 무슨 클래스인지 알 수 있음. 
							// 이 경우 child 객체가 아니면 작동을 하지 않기 때문에 .
	}
	// 추상화
	// 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야할 내용을 전달하는 상속 목적으로 만들어진 클래스
	// virtual, =0(1개 이상의 순수가상함수를 포함하면 추상클래스가 된다.) 
	return 0;
}