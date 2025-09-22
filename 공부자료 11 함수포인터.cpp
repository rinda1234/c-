#include<iostream>
#include"Arr.h"
void Test();
void BubbleSort(int* _pData, int _iCount);
int main()
{
	// �Լ��� �ּҸ� ������
	void(*pFunc)(void) = nullptr;// �̷������� ������ ��. ��ȯŸ���� void �̰� ���ڰ� void �� �׷� �Լ��� �ּҸ� �ްڴ� ��� pFunc�� �׷� ������ ��.  
	pFunc = Test;
	pFunc(); //�̷������� pFunc�� ȣ���ϸ� Test�Լ��� ȣ���. 
	// ������ void�� �� �Լ��� ������. �����ڸ� ���� �Լ��� ���� �� ����. 
	// ex) Sort �Լ�. 
	
	tArr s1 = {};
	InitArr(&s1);
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1,iRand);
	}
	Sort(&s1, &BubbleSort); //�������� ���� ����߿� ���������� ����ϰڴ�. �Լ��� �̸� ��ü�� �ּ��̱� ������ �׳� BubbleSort�� ��� �� 
	//Sort(&s1, BubbleSort); �̰Ŷ� ���� ����. 
	return 0;
}

void BubbleSort(int* _pData, int _iCount) // �����ּҿ� ������ �ڷᰡ ä�����ִ���. 
{
	bool bFinish = true;
	// ����ó��
	if (_iCount <= 1)
		return;

	//�������� ����
	int iLoop = _iCount - 1;
	while (true)
	{
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{


				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;

				bFinish = false;
			}
		}
		if (bFinish)
			break;
	}


}
void Test()
{

}