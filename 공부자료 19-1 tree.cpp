#include<iostream>
// ��ǥ������ Red-Black ����Ž��Ʈ���� �����Ǿ� �ִ� �ڷᱸ��.  
#include<map>
// ����Ž��Ʈ�� ��ݿ� Ž���� ������ �ڷᱸ���� ����� �����̳�
#include<set>
using std::map;
using std::make_pair;

using std::set; // set�� ���� std�� ����. 

using std::wstring; // ���ڿ� Ŭ����.
// map�� �ǻ�� ����
#define MAN 1
#define WOMAN 2


struct tStdInfo //�л�����. 
{
	wchar_t szName[20];
	unsigned char age;
	unsigned char gender;

	tStdInfo() // c++ ������ ����ü�� �����ڸ� ���� �� ����. 
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
		 // ���ڿ� �迭�� ����ü�� ����� ��쿡�� �Ϲ����� �ʱ�ȭ�� �ȵ�. wchar_t* arr[100] = L"aasdf"; �̰� �ȵ�. 
		// ���� _pName�� �ּҿ� �ִ� �����͸� �Ѷ� �Ѷ� �Űܿ;���. 
		wcscpy_s(szName, _pName);// ���ڿ� ���� �Լ�. (������, ����)
	}
};
// pair��� ����ü�� ����
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
	// ����Ž��: ������ ���ݾ� �ٿ����鼭 ã�� ���� 
	// 1. ����Ž���� Ʈ�������� ����� �� �ִ°� �ƴ�. 
	// 2. ���ĵǾ� �ִ� �����Ϳ� ���� ����. 
	
	// ����Ž��Ʈ�� 
	// 1. ����Ž���� ��� �� �� �ְ� ��ȵ� ����Ʈ��
	// 2. ������ �Է½� O(log N) ȿ��
	// 3. Ž��ȿ���� O(log N) 

	// 4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	// - �ڰ� ���� ��� �ʿ�(AVL, Red/Black
	

	// set
	set<int> setInt;

	setInt.insert(100); // ������ ����.  
	// ����Ž��Ʈ���� ���޸𸮿� �����. �� �����̳��� ��ü�� ��Ʈ����� �ּҸ� �����ϸ� ��. 



	// set ���� map�� �� ���� �����. 
	// map
	map<int, float> mapData_1; // map �� type�� 2���� ������. ù��° Ÿ���� �� ����� Ű��, 2���� Ÿ���� ���� ����� �������� �ڷ����� ����. 
	// �������   100
	//          50   150
	// �̷� ����Ž��Ʈ���� ������ 50, 100, 150ó�� �񱳸� ���� ���ڰ� Ű��, ù��° Ÿ����
	// �̷� ����, ������� 50�� ���������� ������ �� 50�̶�� ���ڿ� ����Ǿ� �ִ� ��¥ ������. 2��° Ÿ��.
	//  map<�̸�, ����> �̷��� �˸� ����. 
	// Ű���� �ܼ��� �񱳸� ���� ���ǹǷ� ���������Ϳ� �ٸ��� ������ ���� �� �ǿ�����. 
	
	// map�� �ǻ�� ����
	// �л��� �̸��� ����. 
	map<const wchar_t*, tStdInfo> mapData;
	tStdInfo info(L"ȫ�浿", 18, MAN);
	tStdInfo info2(L"������", 25, WOMAN);

	mapData.insert( make_pair(L"ȫ�浿", info) );
	mapData.insert( make_pair(L"������", info2) );
	// make_pair �Լ�: �γ༮�� ��� 1���� ¦���� ����. ȫ�浿�� Ű���̰� �ű⿡ ���ΰ� info
	// ���ȿ� �̸������� ���� �����ϰ� ���� �����͸� �Ѱ��� pair �� ��. 
	// ���ȿ��� �� pair �� ���� ����. pair �ȿ� �̸��� ������ ��Ʈ�� ������. 
	map< const wchar_t*, tStdInfo>::iterator mapiter;
	// �̷��� �� �༮�� ���� ���� ������ ���߿� ã�� �� ����. 
	mapiter = mapData.find(L"ȫ�浿"); // �� pair�� �̸���Ʈ�� ã�� �� ����.  // �̰� ���ڿ��� �ּҷ� ã������. 
	// �̷��� ã������ ������ ��ü�� �ٷ��ִ°� �ƴ� �ű⸦ ����Ű�� iterator �� ��ȯ��. 
	// �� iterator�� �����ϸ� Ű����, �����͸� ����gk�� ����ü�� ����ִ� pair��� ����ü�� ��ȯ��. 
	
	_wsetlocale(LC_ALL, L"korean");
	// �����͸� ã������.
	if (mapiter == mapData.end())
	{
		std::cout << L"�����͸� ã�� �� ����." << std::endl;
	}
	else
	{
		std::wcout << L"�̸�: " << mapiter->second.szName << std::endl;
		std::wcout << L"����: " << mapiter->second.age << std::endl;
		std::wcout << L"����: ";
		if (MAN == mapiter->second.gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else if (WOMAN == mapiter->second.gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else
		{
			std::wcout << L"�� �� ����" << std::endl;
		}
	}
	(*mapiter).first;
	(*mapiter).second;// �̷������� pair�� ����ü���� ����� ���ٰ���. 
	mapiter->first; //�̷������� �����Ͱ� �ƴ����� ȭ��ǥ�� ǥ���Ҽ� �ְ� �����Ǿ� ����.
	
	// ��� �ణ�� ���ڰ� ����
	// map<const wchar_t*, tStdInfo> mapData; 
	// �̷������� const wchar_t* �������� ���ڿ��� ũ�⸦ ���ϴ°� �³�?
	// ���ڿ��� ũ�⸦ ���ϴ°� �ƴ� ���ڿ��� �ּҰ���ü�� ũ�Ⱚ�� �񱳰���.  
	// ���� �� �����͸� ã������ ���ڿ��� �ּҰ����� ã�Ե�. 
	// ���� pair�� ã���� ã�ƴ޶�� ���� Ű���� L"ȫ�浿" ���� �� ���ڿ��� �ּҰ��� �ƴ� �� ���ڰ� �� �迭�� �ָ� �ȵ�. 
	wchar_t szFind[20] = L"ȫ�浿";
	mapiter = mapData.find(szFind); // �̷��� ���ڿ��� ã�� �; �ּҰ� �ƴϹǷ� �ȵ�. 

	// ���� �츮�� ù���� Ÿ���� ���ڿ��� ���ϰ� ������ ���ڿ��� �ٷ�� Ŭ������ �־���� ��. 
	// std::wstring

	map<wstring, tStdInfo> mapStdInfo;

	mapStdInfo.insert(make_pair(L"ȫ�浿", info));
	
	
	
	// ��ݾ��� ù��° Ű���� ���� ���� Ŭ������ �ִ´ٸ�?
	map<MyClass, tStdInfo> mapMy;
	MyClass a;
	mapMy.insert(make_pair(a, info)); // map�� ���ø� �Լ��̹Ƿ� ���ο� Ÿ�� T �� ���� ���ؼ� ����Ž��Ʈ���� ����� �񱳿����ڰ� ����. 
	// ������ T�ڸ��� ���� ���� Ŭ������ ������ ���� ���� Ŭ���� ���� ���ϴ� ������, ���������� �����Ƿ� �ȵ�. 
	// MyClass ���ο� �� �����ڸ� ����� ��밡����. 
	// 
	// �� �� �����ڰ� �����Ǿ� �ִ� Ŭ������ map�� Ű������ �� �� ����. 


	// wstring �� ���� ������ ����. 
	// �굵 �����Ҵ���. 
	wstring str;
	str = L"asdf"; // �̷��� ��ü�� �����ϸ� �� ���ڿ� ��ü�� ���� ������ ���� ���� ���ڿ��� �״�� ������(�ּҰ� �ƴ�). �� ��ü������ ���ڿ��� ������. 
	str += L"hjkl"; // �̷������� ���̾� ���ϼ��� ����. 
	str[1]; // �̷������� �迭ó�� ��밡��. ������ ����. 
	return 0;
}