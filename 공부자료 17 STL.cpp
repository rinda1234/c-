#include <iostream>
#include <vector> // ǥ������ �������ִ� �����迭
#include <list> //ǥ������ �������ִ� ������ ����Ʈ
#include "TArr.h"

class CTest
{
public:
	int m_i;
public:
	// Ŭ������ �����Ҷ� �̷� �⺻ ������, �⺻�Ҹ���, Ŭ���� ���� �����ϴ� ���Կ����ڴ� �⺻���� ������. (���� �ȸ��� �˾Ƽ� �������
	CTest()
		: m_i(0)
	{
	}
	~CTest() {};
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;
		return *this;
	}

public:
	// ���� ������. 
	// �̰͵� ���� �ȸ��� �ڵ����� �������. 
	// ��������ڵ� ũ�Ժ��� ������ �����ε��̱� ������ ���� �ڵ����� ��������� �ƴ� ���� �̷��� ���� ����� �θ� �⺻ �����ڰ� �ڵ����� �ȸ������. �� �����ڰ� ��������ڹۿ� �ȸ������.
	// ���� �̷��� ��������ڸ� ����� �ѰŸ� �����ڸ� ����������. 
	CTest(const CTest& _other)
		: m_i(_other.m_i)
	{
	}
};



int main()
{
	// �츮�� ���� �Լ� �̸��ϰ� ���� 
	std::vector<int> vecInt; // �̰͵� using std::vector���ָ� ����.
	vecInt.push_back(10);
	vecInt.push_back(20);

	vecInt[0] = 100; // ������ �����ε��� �Ǿ�����
	vecInt.at(1); // Ư�� �ε����� �����ؼ� ���� ���۷��� ��ȯ���ִ°� 
	// �� vecInt[1]; �̶� ����. 
	vecInt.data(); // �迭�� ù��° �ּ� ��ȯ. 
	vecInt.size(); //���� �����迭�ȿ� �����Ͱ� � �� �ִ��� ��ȯ
	vecInt.capacity(); // ���� �����迭�ȿ� �ִ� ��� �����͸� ���� �� �ִ��� ��ȯ

	std::list<int> listInt; //�̰� �տ��� ������ ���� ����Ʈ �̱� ������ 
	listInt.push_back(10);
	listInt.push_front(100);
	listInt.size();
	listInt.begin(); //ù �ּҸ� ����Ŵ. 
	std::list<int>::iterator iter_1 = listInt.begin();
	iter_1 = listInt.insert(iter_1, 100); // iterator�� ����Ű�� �ִ� ���ʿ� �����͸� �߰���. 
	// ����Ʈ�� �ִ� �����͸� ���� ��ȸ�ϰ� ������ 
	// vector�� �̷������� �ϸ� ��. 
	for (size_t i = 0; i < vecInt.size(); ++i ) //size_t�� 8����Ʈ �ڷ�����(long long) vector�� 8����Ʈ�� �����ذ�. 
	{
	std::cout << vecInt[i] << std::endl;
	}


	// ����Ʈ�� ���� ��带 �����ͼ� ���� ���, ���� ��忡 ��� �����ؾ���. 
	// �� ���θ� �� �˰��־���ϴµ� �װ� ����.  �׷��� ���°� �ݺ���
	// iterator
	std::list<int>::iterator iter = listInt.begin(); //iterator�� Ŭ������ .�̷��� Ŭ���� �ȿ� �ִ� Ŭ������ ���� Ŭ����, ���� Ŭ����, �̳� Ŭ������ �θ�. 
	// �� ��ü�� ù�ּҸ� ����Ŵ 
	// begin()�� ��ȯŸ���� iterator��. iter�� �ޱ� ������ .
	int iData = *iter; // �̷��� ù��° �ڷḦ iData�� ������. ��ġ ������ ó�� ����. ������ Ŭ������ ������ ������ �����ε����� *�� ����. �������Ǵµ��� �ϰ�.  

	// �� iterator�� ������ó�� �� �� ����. 
	// iterator ��� �ݺ��ڸ� �̿��ؼ� ���ο� �ִ� �����Ϳ� �����ϰ� ��ȸ�Ҽ� �ְ� �ϴ°� �ݺ��ڴ�. 
	// vector �� list�� �Ѵ� �����Ǿ� ����. �׷��� ���� �ٸ�. vectorŬ���� �ȿ� �����Ǿ� �ִ� iterator Ŭ����, list Ŭ���� �ȿ� �����Ǿ� �ִ� iterator Ŭ����
	// ��κ��� �ڷᱸ���� �����Ǿ� ����. ��������� �ٸ�����(������ �ڷᱸ������ �ϴ� ����� �ٸ��Ƿ�) ����ڰ� ���⿣ ����ϰ� �����Ǿ� ����. 
	// �� �������ϰ� ��밡���ϴ�. 

	// 1. vector����
	std::vector<int>::iterator veciter = vecInt.begin();
	*veciter; // vecint[0] ������. 
	*veciter = 100; // ���ٲٱ� ����. 
	++veciter; // �ּҸ� ������Ŵ. 
	*veciter;// veciter[1] �� ����. 
	
	// vector�� �����迭�̱� ������ ���� iterator�� �Ⱦ��� ���� �Լ��� ������ �� �ִٰ� ������ �� ����. 
	// �׷��� �߰��� �����͸� �����ϰ� ������ iterator�� ��� ����. �����͸� �����ϰ� ������ �� ���ܾ� �ϱ� ������ 
	vecInt.erase(veciter); // ���ڷ� iterator�� ����. iterator �� ����Ű�� �ִ� �κ��� ���� 
	//iterator�� ������ �ڷḦ ������. 



	// 2. list ����
	std::list<int>::iterator liter = listInt.begin();
	*liter = 10;
	++liter; //�ּҰ� 1�þ. 
	*liter; //liter[1]
	// �߰��� �����͸� ����� ������
	listInt.erase(liter); //�̰͵� literator�� ����. �� �ٸ� �ڷᱸ���� �� ����ϴ�. 

	// iterator�� �̿��� ��ȸ
	// iterator�� �̿��� �ּҸ� �ϳ��ϳ� �÷��� �߰��� ���� �����ؾ� ��. 

	for (liter = listInt.begin(); liter != listInt.end() ; ++liter) //end()�� ��Ī�ϴ°� �ڷᰡ ����ִ� �����̳�(�迭�̵�, ����Ʈ��) ������ ����Ʈ(���⼱ ����Ʈ) ���� �ϳ��� ������ ��Ī��.  �� end�� ������ �����͸� ����Ű�°� �ƴ�. 
	{
		//std::cout << *liter << std::endl;
	}


	// Auto Ű����
	// i�ڵ����� Ÿ���� �����ִ� Ű����
	// iterator�� �̷��� ������ �� ����. 
	auto myliter = listInt.begin();

	//int �� �̷��� ������ �� ����. 
	int a = 5;
	auto b = 9; 
	auto c = b;


	std::list<int> ll;
	ll.push_back(10);
	ll.push_back(20);
	ll.push_back(30);
	ll.push_back(40);
	
	std::list<int>::iterator literator = ll.begin();;
	std::cout << ll.size() << " " << * literator << std::endl;
	ll.erase(literator);
	std::cout << ll.size() << std::endl;

	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	std::vector<int>::iterator Myveciter = vec.begin();

	vec.erase(Myveciter);
	std::cout << vec[0] << std::endl;
	
	
	// iterator �����: Tary�� TLinkedList���� ������. 

	CArr<int> myvector;
	myvector.push_back(10);
	myvector.push_back(20);
	myvector.push_back(30);

	CArr<int>::iterator myiter = myvector.begin();
	++(++myiter);
	std::cout << *myiter << std::endl;
	// *myiter;
	// ++(����, ����), --(����, ����), ==, != �̷������ڵ� �ʿ���. 
	// 
	--(--myiter);
	for (; myiter != myvector.end(); ++myiter)
	{
		std::cout << *myiter << std::endl;
	}

	// ���� ����
	myiter = myvector.begin();

	int iData_1 = (*myiter++); //���������� ������� ����ģ �ڿ� ������ �ȴ�. �׷��� ȣ���� ���� ��. ȣ���� �Ǵ��� ������ ���߿� �ϴ� ���ο� �Լ��� �������. 
	// ��������ó�� ���̴� ����.  
	// ���������� �ʿ���� ��ü�� ������ �Ҹ��� ����Ƿ� ��ȿ������. ���� �ظ��ϸ� ��������. 
	// �Լ����ο��� ��ü�� 1�������ѵ� �װ� �����ؼ� ��ȯ�Ҷ� 1�� ������. ���� 2���� ��������� �Ҹ���. 
	
	//���������. : ��ü ������ ������ ���ÿ���. 

	CTest t1;
	t1.m_i = 100;

	CTest t2;
	t2 = t1; //���Կ���. 

	CTest t3(t1); // ���������. 
	
	CTest t4 = t1; // �̰͵� ���������. ���Կ���ó�� �������� �����Ϸ��� �ڵ����� CTest t4(t1)���� �ٲ���. ���� �ܰ���. 
	
	// vector::erase
	std::vector<int> vec1;
	vec1.push_back(100);
	vec1.push_back(200);
	vec1.push_back(300);
	vec1.push_back(400);

	std::vector<int>::iterator veciter1 = vec1.begin();
	veciter1 = vec1.erase(veciter1); // iterator�� �⸮Ű�� �κ��� ����. �����迭 Ư���� �����͵��� �� ������ ������. 
	// �̷������� erase�� ��ȯ�� iterator�� veciter1�� �����ؾ���. 
	int i = *veciter1; //erase�� ��ȯ�ϴ� iterator�� ���� iterator�� �����ϱ� ������ �̰� �ȵ�. �ֳ� ������ ���� ����Ű�� �ֱ� ������. �� 
	
	vec1.clear();// ����ִ� �����͸� ���� ��������. 

	// 1~11�� �־���. 
	for(int i = 0; i < 11; ++i)
	{
		vec1.push_back(i + 1);
	}
/*
	// ¦���� ����
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); ++veciter1)
	{
		if (0 == *veciter1 % 2) 
		{
			// ����
			//vec1.erase(veciter1); //�� iterator�� �ٽ� �� �� ����. �׷��� �ٽ� �ݺ��ؼ� ����ϹǷ� �̷��� �� �� ����. 
			veciter1 = vec1.erase(veciter1); //�̷������� veciter1�� �ٽ� �޾������. 
		}
	}

	// 1 ~ 5 ���� ����
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); veciter1)
	{
		if (1 <= *veciter1 && *veciter1 <= 5)
		{
			// ����
			//vec1.erase(veciter1); //�� iterator�� �ٽ� �� �� ����. �׷��� �ٽ� �ݺ��ؼ� ����ϹǷ� �̷��� �� �� ����. 
			veciter1 = vec1.erase(veciter1); //�̷������� veciter1�� �ٽ� �޾������. 
		}
	}
	// �̷������� �ϸ� ���� ���������� 2�� 4�� �������. 
	// veciter�� erase�� �� ���� ��Ҹ� ����Ű�� �ִ� iterator�� ����. �� ù��° �ڸ��� ����� �� ���� ��Ҹ� ���ܿ´��� �� ����� iterator�� ��ȯ��. 
	// �׷��� �� �ּҿ� ++veciter1���� �� ���� ��Ҹ� ����Ű�� ����� ��������� ���� 2���� �ڸ����� �����ʹ� �˻縦 �ȴ���. ù��° �ڸ��� �Ű�����, ���� 2��° �ڸ��� �˻��� �����̱� ������. 
*/

	// ������ 1~5 ���� ����
	// �̷������� 2���� ���̽��� ������ �ؾߵ�. 
	veciter1 = vec1.begin();
	for (; veciter1 != vec1.end(); )
	{
		if (1 <= *veciter1 && *veciter1 <= 5) // 1. ���ڰ� 1~5�����϶�
		{
			// ���� 
			veciter1 = vec.erase(veciter1);
		}
		else // 1~5���̰� �ƴҶ� veciter1 ����. 
		{
			++veciter1;
		}
	}
	// �̷��� ������ ���� �� ����. ���� �ڵ�� �������� ã�ƶ� �̷��ñ��.
	// �̰� iterator ����� �� ���ʻ��� �� �ϳ���. 
	for (int i = 0; i < vec1.size(); ++i)
	{
		std::cout << vec1[i] << std::endl;
	}
	return 0;


	

}

