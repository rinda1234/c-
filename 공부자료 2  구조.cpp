#include<iostream>

typedef struct _tagMyST
{
	int a;  //�� ��ü�� �����ϴ°� �ƴ�. �� ���� ��� ���� ����� �а�. 
	float f;
}MYST; //�̰� �ڷ����� ��.
//int �� float�ڷ����� ���� ��� �ڷ����� ����� ����. 8 byte

typedef struct _tagBig
{
	MYST k; //�̷������� ���ȭ�� �� �� ����. �ٸ� ����ü�� ��밡��.
	int i;		
	char c;
}BIG;
//typedef �� ������ ���شٴ� �ǹ�.
typedef int INT; //INT�� int�� ��밡��. 

struct NewStruct
{
	int a;
	short s;
};//�̷�������  typedef�� ���� �ʰ� ����ü�� ����� ����ü�� ����Ҷ� struct Ű���带 ��Ӻٿ�����. 
//������ c������ �̷��� c++������ ������. 
int main()
{
	//����ü 
	// ����ü�� ����ڰ� ���� ������ �ڷ���. 
	MYST t;
	t.a = 10;
	t.f = 10.2312f; // �̷������� ����ü �̸��� �� ������ �̸��� ��� ���.
	struct NewStruct NEWST;
	NewStruct NEWST1; //C++������ �̷������� ������. �׷��� Ÿ�������Ǹ� ����� c�� c++ �ѿ��� ���������� ��밡��. 
	//����ü �ʱ�ȭ
	MYST ST = { 10, 10.123f }; //�̷������� �迭ó�� �ʱ�ȭ ����. 
	return 0;
}