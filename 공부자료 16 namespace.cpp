#include<iostream>
class CTest
{
private:
	int m_i;


public:
	// ��������Լ�
	// ��ü ���� ȣ�� ����. 
	static void memcerFunc()
	{
		
	}
};

// ����� ����
// <<, >> �� ����
// endl �� �Լ�. 
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
		return *this; // �̾ ��� �����ؾ� �ǹǷ� << 10 << 20 << 3.0; �̷� �ڵ��� ���
	}
	CMyOstream& operator << (const wchar_t* _pSpring) // 2����Ʈ ���ڿ� ��� �����ε� 
	{
		wprintf(L"%s", _pSpring);
		return *this; 
	}
	CMyOstream& operator >> (int& _idata) // 2����Ʈ ���ڿ� ��� �����ε� 
	{
		scanf_s("%d", &_idata);
		return *this;
	}
	CMyOstream& operator << (void(*_pFunc)(void)) // endl ���
	{
		_pFunc();
	}
};


CMyOstream mycout; // ���� Ŭ������ �ƹ��͵� ���� Ŭ������ ��ü�� ����� �� ��ü�� 1����Ʈ�� ��. 


using namespace std; // �� Ű���带 ���� ���ĺ��� namespace�ȿ� �ִ� ��ɵ��� �ٷ� ���� ����
// ��������� ���� namespace�� ����� ����� ���̱� ������ �� �������� ����. 
// ���� namespace ���θ� ���� ���� �ϴ°� �ƴ϶� Ư�� �κи� ������ �� ����

using std::cout; //cout �����ؼ� cout�� �׳� �� �� ����. 
using std::wcout; //��ģ���� ���ڸ� 2����Ʈ�� �����ϰ� ���. 
using std::cin; // cin ����
using std::endl; //endl ����


namespace MYSPACE //���� �̸��� MYSPACE ��� �׳� ����
{
	int g_int;
}
int main()
{
	CTest::memcerFunc(); //�̷������� ��ü ���� ȣ�� ����. 

	// namespace
	//g_int = 0; �̷������δ� ���� ����
	MYSPACE::g_int = 0; // �̷������� namespace�� �̸��� �ٿ��� ����ؾ� ��.  
	
	// namespace�� ����ϴ� ����
	// ����ڰ� �� std ���̺귯���� �ִ� ������ �״�� ����� ���� �ֱ� ������
	// ���� ����ڰ� cin�̶�� ������ ���� ������ std���̺귯������ �־ ��ħ
	// namespace�� �̸������� �ٸ��� �ؼ� �������ߺ��� ����. 
	// namespace�� ���� ������ using�̶�� Ű���� ���. 
	// std���� �� �� ����. 

	// ���� �۾��ϴ� ����鳢�� �������� ��ġ�� �ʰ� �ϱ� ���ؼ��� ���. 
	cout << 1 << endl;

	// ���־� ��Ʃ����� ǥ���� ���� ���ϱ� �ѱ� ������ ����� �ȵǾ� ���� �� ����. 
	// �̷���� �ƽ�Ű �ڵ� ���� ǥ�� �ѱ۷� �ٲ������. 

	setlocale(LC_ALL, "korean");
	_wsetlocale(LC_ALL, L"korean"); // �ѱ۷� �ٲ���

	wcout << L"�ȳ�" << endl; // 2����Ʈ ���ڿ� 
	// ����� ����
	mycout << 10;
	int a = 0;
	mycout >> a; // cin
	mycout << 10 << L" " << 20 << L" " << 30 << MyEndL;
	return 0;
}