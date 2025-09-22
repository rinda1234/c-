#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <assert.h>
// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ڵ�) : ���൵�߿��� ���� �ٲ�� �ȵ�.(read only memory)

// �Լ� �����ε�
// �Լ� �������̵�
// ���� ���̸� ������ �� �ֳ� ���� �ܰ����� �˰��ֱ� !!

unsigned int GetLength(const wchar_t*);
unsigned int MyGetLength(const wchar_t* );
void StrCat(wchar_t*, unsigned int, const wchar_t*);
int MyStrCmp(const wchar_t*, const wchar_t*);
int StrCmp(const wchar_t*, const wchar_t*);
int main()
{
	{
	    // ���� ���� �ڷ῭
	    char c = 49; // 1byte ����, �Ϲ������� ���ڸ� ��Ÿ���µ� Ưȭ�Ǿ� ����.
	    wchar_t wc = 49; // 2byte�� ���ڸ� ��Ÿ���� �ڷ���. 1����Ʈ�� ��� ���ڸ� ������ �� ���� ������ �̰� ���. 
	    // �ƽ�Ű �ڵ忡 �ش��ϴ� ���ڸ� ��Ÿ��. 
	    
	    c = 1;
	    c = '1'; // �� ���� �ٸ�. 1�� ���� �ϴ� ���� �׿� �ش��ϴ� ���ڸ� ����������. ���� '1'�� �����ϴ� ���� '1'�� ������ ����. 
	    // '4459' �̷������� ���ڸ� �����ϴ� ���� �׿� �ش��ϴ� �ƽ�Ű �ڵ尡 ����Ǵ� ����. 
	    // ������ �̷������� �����ϸ� ���ڰ� ���� �������� ��ǻ�ʹ� ��. ���� ��ǻ�ʹ� ���������� ����Ǵ� ���� 0�� �����ؼ� ���� ��. 
	    // ���� 0�� �����ϴ� ���ڴ� NUL���ڶ�� ��. 
	    
	    
	    
	    // 2����Ʈ�� ���ڸ� ��Ÿ���� �������� ���� �տ� L�� �ٿ���
	    wchar_t wc_1 = L'a'; // a�� 2byte�� ��Ÿ���� ������; 
	    wchar_t wc_2 = 'a'; // �̰� 2byte �ڷ��������� 1����Ʈ ǥ��������� ��Ÿ��. ���� �����Ͱ� �ٸ�.  
	    
	    // ���ڿ�
	    //���ڿ��� ���� ���
	    char szChar[10] = "abcdef"; // ���ڷ� ����Ǿ� �ִٴ°� ���.
	    wchar_t szWChar[10] = L"abcdef"; // ���ڰ� 6������ �������� ���ڰ� �����ٴ� ���� ǥ���ϱ� ���� 0�� ���Ƿ� �迭�� ������ 7�̻� �ʿ�.
	    wchar_t szWChar_1[10] = { 97, 98, 99, 100, 101, 102 }; // �̷������� ��� ���� ����. 
	    
	    const wchar_t* pChar = L"abcdef"; // ���ڿ��� ��ü�� �ּҰ��̶� �����Ͱ� ������ ����..  
	    // L�� �پ��� ������ 2����Ʈ �ڷ��� �����ͷ� �����Ѿ� ��Ī�� ��
	    // �� �����ͷ� ������ �� �ִ�. 
	    // �޸� �� ��򰡿� �ִ� (�ڵ�� �����)���� �ۼ��� ���ڿ��� �����ּҸ� �����Ϳ� �����Ѱ���. 
	    // �� ��ɾ� ��ü�� �ʿ��� �����Ͱ� ����.
	    // ���ڿ��� ��ȯŸ���� const �����Ϳ��� ���缭 const�����ͷ� �������. 
	    // ���� �ٲٸ� �ȵǱ� ������ const �����ͷ� �������. 
	    // �̰͵� ���� ĳ���� �� �� ����. 
	    //const wchar_t* pChar_1 = (wchar_t*)L"abcdef";
	    // ������ ��Ÿ�� ���߿� ������ ����. �׷��� �����ϰ� ��ũ�������� ������ ���� ����.  
	    
	    // �����Ϳ� �迭�� ������
	    // �迭: ���ڿ��� �ִ� �����͸� �״�� �迭�� �Űܿ°���.
	    // ������:  ������ ������ ���ڿ��� ���� �ּҸ� ����Ű�� ����. 
	    
	    szWChar[1] = 'z'; //�� �״�� b�� z�� �ٲٰڴٴ� �ǹ�
	    //pChar[1] = 'z';// *(pChar + 1) = z; 
	    //�����͸� �����Ѱ��̱� ������ ����Ǵ� �߰��� �ڵ带 �����ϴ� ����. 
	    // ������ �ڵ�� �߰��� ������� ���ϰ� ���������Ƿ� ������ ��. 
	    
	    printf("%c\n", szWChar[0]);
	    printf("%c\n", pChar[0]); // �̷��� �ܼ��� �б⸸ �ϴ� ���� ����. 
	    
	    // ��Ƽ ����Ʈ ���ڼ� : ���ڿ� ���� ���� ���̷� ������. 
	    // ���� ǥ������ ������ ����. 
	    char szTest[10] = "abc�ѱ�"; // L�ڰ� �Ⱥپ����� "�ѱ�"�� 2����Ʈ�� �����.  
	    // ȣȯ���� ���������� L�ڸ� ���̴� �����ڵ� �ý����� ����ϴ°� ����. 
	}

	wchar_t szName[10] = L"Raimond";// ������ ������ 7����
	//������ ����(���ڿ��� ����)�� �����ϴ� �Լ�
	int ilen = wcslen(szName); //const ������Ÿ���� �䱸, �� �Լ��� �����Ϳ� �����ؼ� ���ڿ��� ���̸� �����ϹǷ� ���ڿ��� ���� �ּҸ� �ִ� ����. 
	int ilen_1 = GetLength(szName);
	
	
	// ���ڿ� �̾� ���̱�
	wchar_t szString[100] = L"abc";
	wcscat_s(szString,100, L"def"); // ������ �ҽ� ���ڸ� �̾� ���̴� �ű� ������ ���� ����, size , �ڴ� const ������ Ÿ����, "def"ó�� ���ڸ� �־��. ���ڴ� �ּҰ��� ��ȯ�ϱ� ������/
	StrCat(szString, 100, L"defghuijk");// �������� �ڵ�

	// �� ���ڿ��� ��ġ �ϴ��� Ȯ��. 
	int iRet = wcscmp(L"abc", L"abcd"); // �� ���ڿ��� ��ġ �ϴ��� Ȯ��, �Ϻ��� ��ġ�ϸ� 0�� ��ȯ, ���� ���ڿ��� �� ���������� �쿭�� ����. �׷� 1 ��ȯ, �������� �쿭�� �� ������ -1 ��ȯ. ex) abc < cbc, acb > abc
	
	int L = MyStrCmp(L"acc", L"abcdefg");

	return 0;
}
//���ڿ� ���� ��ȯ �Լ� ���� �����

unsigned int MyGetLength(const wchar_t* _pStr)
{
	int i = 0;
	while (_pStr[i] != 0  )
	{
		++i;
	}
	return i;
}
unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0;
	while (_pStr[i] != '\0') //null ���ڴ� �̷��� �������. 
	{
		++i;
	}
	return i;
}

// ���ڿ� �̾� ���̱� �Լ� ���� �����
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1) //Null ���� �������� ���
	{
		assert(nullptr);// Ư�� ��Ȳ�� �ڵ带 �ߴܽ�Ű�� ���⿡ �߰� ���ڸ� �� �ֳĿ� ���� ��µǴ� ���� �ٸ��� �� �� ����. ����ڷ� �Ͽ��� ������ �ν��� �� �ְ�. 

	}
	//1. Dest ���ڿ��� ���� Ȯ��( ���ڿ��� �̾� ���� ���� ��ġ
	iDestLen; //Dest ���ڿ��� �� �ε���

	//2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	//3. Src ���ڿ��� ���� ������ �ݺ� ����
	for (int i = 0; i < iSrcLen + 1; ++i) //\n���ڵ� ���� �ϱ� ������ iSrcLen + 1�� ��.  
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}

	 //���ڸ� �̾� ���̱�
	
}
// ���ڿ��� ��ġ�ϴ��� Ȯ��
// ���������
int MyStrCmp(const wchar_t* _LStr, const wchar_t* _RStr)
{
	int iLSrcLen = GetLength(_LStr);
	int iRSrcLen = GetLength(_RStr);

	int len = 0;
	iLSrcLen >= iRSrcLen ? len = iLSrcLen : len = iRSrcLen;
	int i = 0;
	while(i < len)
	{
		if (_LStr[i] == _RStr[i])
		{
			++i;
		}
		else if (_LStr[i] > _RStr[i])
		{
			return 1;
		}
		else
		{
			return -1;
		}

	}
	return 0;
}
// ����;
int StrCmp(const wchar_t* _left, const wchar_t* _right)
{
	int leftlen = GetLength(_left);
	int rightlen = GetLength(_right);

	int iLoop = 0;
	int iReturn = 0;
	if (leftlen < rightlen)
	{
		iLoop = leftlen;
		iReturn = -1;
	}
	else if (leftlen > rightlen)
	{
		iLoop = rightlen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; ++i)
	{
		if (_left[i] < _right[i])
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	return iReturn;
}