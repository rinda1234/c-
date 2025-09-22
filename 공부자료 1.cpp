#include<iostream>
#define HUNGRY 0x001//1��°ĭ
#define THIRSTY 0x002//�� ��Ʈ�� 2��° ĭ�� ���;� �ǹǷ� ���� 2���� ��. 16������ ǥ��. 
#define TIRED 0x004//�� ��Ʈ�� 3��° ĭ�� ���;� �ǹǷ� ���� 4���� ��.
#define COLD 0x008//�� ��Ʈ�� 4��° ĭ�� ���;� �ǹǷ� ���� 8���� ��
#define FIRE 0x010// �� ��Ʈ�� 5���� ĭ�� ���;� �ǹǷ� ���� 16�̿��ߵ�. 
#define POISON 0x020//32
#define FIRE 0x040//64
#define FIRE 0x080 // 128
#define FIRE 0x100//256
#define FIRE 0x200//512

int factorial(int);
int factorial2(int, int);
void PrintArray(const int*, int);


//����
//1. ������
//2. ��������.

int main()
{
	//switch���� ���� break�� �־���� �� �κи� ����ǰ� �ٸ� �κ��� ����ȵ�

	int data = 10;
	switch (10)
	{
	case 10:
		break;
	case 20:
		break;

	default:
		break;
	}
	//���� break�� �ȳ�����
	switch (data)
	{
	case 10:
	case 20:
		break;
	default:
		break;
		//�̷������� data�� 10�� 20�϶� ����ǰ� ���� �� ����. 


	}
	// ���� ������
	data == 20 ? data = 100 : data = 200; //data�� 20�̐� �տ� �ڵ�(data = 100)�� �����ϰ� �ƴϸ� �ڿ� ������ ������
	//��Ʈ������
	//��Ʈ ������ ������ ����ɶ� ���Ǵ� ������
	//1. ��Ʈ ����Ʈ <<, >>(��Ʈ�� ȭ��ǥ�� ����Ű�� �������� ��ĭ���̵� EX) 0001 << 0010) 
	unsigned char byte = 10;
	byte <<= 3; //2^n���
	byte >>= 2; //2^n ���� ��

	//��Ʈ ��(&), ��(|), xor(^) ����(~) 
	//�� ��Ʈ �Ѵ� 1�̾�� 1(0001 & 0011 = 0001)
	//�� �� �� �ϴϸ� 1� 1(0001 | 0011 = 0011)
	//���� ���״�� ��Ʈ�� ������Ŵ (0001 -> 1110)
	//xor �� �ڸ��� ��Ʈ�� ������ 0 �ٸ��� 1(0001 xor 0011 = 0010)
	//��Ʈ ������ ���ӿ��� �ַ� 
	int iStatus = HUNGRY; // 32��Ʈ�� HUNGRY���� ��. 
	//�� 32��Ʈ�� �̿��ؼ� Ư�� ����(���������� ������ ����)�� ǥ���Ҽ�����. �̷� ���¸� ǥ���ϱ� ���ؼ��� ��ġ�� �ʴ� �ڸ��� �ʿ���.
	// 0001(�� ���ڸ��� 1�̸� �谡 �Ȱ��°Ű� 0�̸� ����°�, 2��°ĭ�� 0�̸� �񸶸���, 3��°ĭ�� 0�̸� �ǰ��Ѱ�, �̷������� Ȱ�� ����. 

	iStatus |= THIRSTY; //������鼭 �񸶸� ���� ǥ�� (��Ʈ������ ǥ��)
	//�ǰ��Ե� ǥ���ϰ� ������ 
	iStatus |= TIRED;

	//�̷��� � �������� üũ�Ҷ�(ex) �񸶸��� �ñ��Ҷ�)
	//���� ������ �ڸ����ִ� ��Ʈ�� 1���� Ȯ���ϴ� ���. 
	if (iStatus & THIRSTY) // �񸶸��� ���� �Ѵ�. �̷��� �ڵ带 ���� �� ����. 
	{

	}
	//� ���¸� �����ϰ� ������. Ư���ڸ��� �ִ� ��Ʈ ����. 
	iStatus &= ~THIRSTY; // ������ �ϰ� ���ؾ� �� �κи� ������. 

	// printf
	printf("asdf \n");
	printf("asdf %d  \n", 10); //#d �� �����ʿ��� ������ ã�Ƽ� �ִ°�
	printf("asdf %f  \n", 3.314f); //#f �� �����ʿ��� �Ǽ��� ã�Ƽ� �ִ°�
	for (int i = 0; i < 10; ++i)
	{
		printf("output : %d \n", i);
		std::cout << "out put: " << i << std::endl;
	}
	// scanf
	int iInput = 0;
	scanf_s("%d", &iInput);	

	// �ڷᱸ�� 
	// stack : ���� ����
	// ť : ���� ����

	//�Լ�
	// factirial

	std::cout << factorial(3) << std::endl;
	//�ٸ� ����� factorial
	int i = 3; // factorial �ϰ� ���� ����
	int iValue = 1;
	iValue = factorial2(i, iValue);
	std::cout << iValue;

	int myNumbers[] = { 1,2,3,4,5 };
	PrintArray(myNumbers, 5);
	return 0;
}
int factorial(int n)//recursive (���) 
{
	if (n == 0)
		return 1;
	else
		return(n*factorial(n - 1));
}
int factorial2(int ival, int ivalueval)
{
	for (int j = 0; j < ival - 1; ++j)
	{
		ivalueval *= (j + 2);
	}
	return ivalueval;
}
void PrintArray(const int* numbers, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << numbers[i] << std::endl;
	}
}



//�����
// ������ ���� �ּ�          : ctrl + k, c ��Ʈ�� ������ k c ������
// ������ ���� �ּ� ����     : ctrl + k, u
// alt Drag                  : ���ϴ� ������ �巹�� 

// ����� ���� �����
// ����� ���� : F5  ���� �ߴ��� ���� ����
// �ߴ��� ���� �� ���� : F9
// ����� ��, ���� ���� : F10 �� ���徿 �����ϰ� ������
// ����� ��, �Ѵܰ�� ����: F11  �Լ�����(���� ���� �ܰ�) 
// �� �Լ��� ����, ���� ��Ʈ�� �̵� : F12