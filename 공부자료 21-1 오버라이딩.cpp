#include<iostream>
// �������̵�

// �߿�! ���� �ܰ� ��Ʈ. ���� �ε��� ���� ���̵��� ����. 

// �����ε��� �Լ����� �Ȱ����� ����Ÿ�Կ� ���̰� ���ܼ� �����Ϸ��� ������ ������ �����. ���ÿ� ���� �̸��� �Լ��� ������ ������ �� ����. ������ Ÿ�԰� ������ �ٸ���
// �������̵��� ��Ӱ��迡���� �߻���. 
// �ڽ�Ŭ�������� �θ� Ŭ������ �Լ��� �������ؼ� �� �� ����. 

// �θ�Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�. 

// ����� ����ϴ� ��Ȳ ��
// �����̶�� Ŭ������ ��ӹ��� �پ��� ���� Ŭ������ �ִµ� � 1���� Ŭ������ �θ�Ŭ������ � �Լ��� �ٸ��� ���� ������ ���
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
	void Output() //�̷������� �θ��� �Լ��� ���� �̸����� ���� ���������. child���� Output�� ȣ���ϸ� �ڽ��ʿ��� �������� �Լ��� ȣ���. 
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
	parent.Output(); // �̰� �θ��� Output
	child.Output(); // �̰� �ڽ��� Output ȣ��
	child.CParent::Output(); // �̷������� �ڽ� ��ü���� �θ��� Output�� ȣ�� �� ���� ����. ������ �Ⱦ�.  
	return 0;
}