#pragma once


// Ŭ������ �̿��� �����迭

class CArr
{
private: // private�� ����� �⺻�� private��. 
	int* m_pData; // �밡���� ǥ���. ���������� �����Ǳ� ���ػ�� �տ� m �ٿ��ֱ�
	int m_iCount;
	int m_iMaxCount;
public:
	// �����ڸ� public�� ������ ��ü�� ���� �����Ϸ��� �����ڸ� ȣ���� �� ����. 
	// ������Ͽ��� �����ڸ� �������� �ʰ� ���Ǹ� ����. 
	CArr();
	~CArr();
public:
	void push_back(int _iData);// ���ʿ� �� Ŭ������ ����Լ��̱� ������ ��ü�� ���ڷ� ���� �ʿ䰡 ����. 
	void resize(int _iResizeCount);// �̹����� ����ڰ� ������ �ø� �� ����. 

	// ������ �����ε�
	int& operator[](int idx);
};

