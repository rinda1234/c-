#include<iostream>
// ��ӵɶ� �Ҹ����� ȣ��
// �Ҹ��ڴ� ȣ���̶� ���� ��� �ڽ��ʿ��� ���� �̷����� �θ� ���߿� ��. 
// �Ҹ��� ȣ�� ����, �ڽ� -> �θ� ***
// �ߴ��� �ɾ ���� ���� ./
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
		std::cout << "�θ�Ҹ���" << std::endl;
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
		std::cout << "�ڽļҸ���" << std::endl;
		// �����δ� ������ ������ ���⿡ �θ��� �Ҹ��ڸ� ȣ���ϴ� �ڵ尡 ����. 
	}
};

int main()
{
	CChild child;
	
	return 0;
}