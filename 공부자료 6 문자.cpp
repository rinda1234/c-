#include <stdlib.h>
#include <stdio.h>
#include <wchar.h>
#include <assert.h>
// 메모리 영역
// 1. 스택
// 2. 데이터
// 3. 힙
// 4. ROM(코드) : 실행도중에는 절대 바뀌면 안됨.(read only memory)

// 함수 오버로딩
// 함수 오버라이딩
// 둘의 차이를 구분할 수 있냐 면접 단골질문 알고있기 !!

unsigned int GetLength(const wchar_t*);
unsigned int MyGetLength(const wchar_t* );
void StrCat(wchar_t*, unsigned int, const wchar_t*);
int MyStrCmp(const wchar_t*, const wchar_t*);
int StrCmp(const wchar_t*, const wchar_t*);
int main()
{
	{
	    // 문자 전용 자료열
	    char c = 49; // 1byte 정수, 일반적으로 문자를 나타내는데 특화되어 있음.
	    wchar_t wc = 49; // 2byte의 문자를 나타내는 자료형. 1바이트로 모든 문자를 저장할 수 없기 때문에 이거 사용. 
	    // 아스키 코드에 해당하는 문자를 나타냄. 
	    
	    c = 1;
	    c = '1'; // 이 둘은 다름. 1을 저장 하는 것은 그에 해당하는 문자를 저장하지만. 문자 '1'을 저장하는 것은 '1'을 저장한 것임. 
	    // '4459' 이런식으로 문자를 저장하는 것은 그에 해당하는 아스키 코드가 저장되는 것임. 
	    // 하지만 이런식으로 저장하면 문자가 언제 끝나는지 컴퓨터는 모름. 따라서 컴퓨터는 마지막으로 저장되는 곳에 0을 저장해서 구분 함. 
	    // 따라서 0에 대응하는 문자는 NUL문자라고 함. 
	    
	    
	    
	    // 2바이트로 문자를 나타내고 싶을때는 문자 앞에 L을 붙여줌
	    wchar_t wc_1 = L'a'; // a를 2byte로 나타내고 싶을때; 
	    wchar_t wc_2 = 'a'; // 이건 2byte 자료형이지만 1바이트 표현방식으로 나타남. 위랑 데이터가 다름.  
	    
	    // 문자열
	    //문자열도 같은 방식
	    char szChar[10] = "abcdef"; // 숫자로 저장되어 있다는거 기억.
	    wchar_t szWChar[10] = L"abcdef"; // 문자가 6개지만 마지막에 문자가 끝났다는 것을 표현하기 위한 0이 들어가므로 배열의 개수가 7이상 필요.
	    wchar_t szWChar_1[10] = { 97, 98, 99, 100, 101, 102 }; // 이런식으로 적어도 위랑 같음. 
	    
	    const wchar_t* pChar = L"abcdef"; // 문자열에 정체가 주소값이라 포인터가 받을수 있음..  
	    // L이 붙었기 때문에 2바이트 자료형 포인터로 가리켜야 매칭이 됨
	    // 즉 포인터로 저장할 수 있다. 
	    // 메모리 상에 어딘가에 있는 (코드로 저장됨)내가 작성한 문자열의 시작주소를 포인터에 저장한것임. 
	    // 즉 명령어 자체에 필요한 데이터가 있음.
	    // 문자열에 반환타입이 const 포인터여서 맞춰서 const포인터로 해줘야함. 
	    // 차피 바꾸면 안되기 때문에 const 포인터로 해줘야함. 
	    // 이것도 강제 캐스팅 할 수 있음. 
	    //const wchar_t* pChar_1 = (wchar_t*)L"abcdef";
	    // 하지만 런타임 도중에 오류가 생김. 그러나 컴파일과 링크과정에서 문제를 잡지 못함.  
	    
	    // 포인터와 배열의 차이점
	    // 배열: 문자열에 있는 데이터를 그대로 배열에 옮겨온거임.
	    // 포인터:  포인터 변수로 문자열의 시작 주소를 가리키고 있음. 
	    
	    szWChar[1] = 'z'; //말 그대로 b를 z로 바꾸겠다는 의미
	    //pChar[1] = 'z';// *(pChar + 1) = z; 
	    //포인터를 수정한것이기 때문에 실행되는 중간에 코드를 수정하는 것임. 
	    // 하지만 코드는 중간에 변경되지 못하게 막혀있으므로 오류가 남. 
	    
	    printf("%c\n", szWChar[0]);
	    printf("%c\n", pChar[0]); // 이렇게 단순이 읽기만 하는 것은 가능. 
	    
	    // 멀티 바이트 문자셋 : 문자에 따라 가변 길이로 대응함. 
	    // 단점 표준으로 쓰이진 않음. 
	    char szTest[10] = "abc한글"; // L자가 안붙었지만 "한글"은 2바이트로 저장됨.  
	    // 호환성을 생각했을때 L자를 붙이는 유니코드 시스템을 사용하는게 편함. 
	}

	wchar_t szName[10] = L"Raimond";// 문자의 개수는 7개임
	//문자의 개수(문자열의 길이)를 제공하는 함수
	int ilen = wcslen(szName); //const 포인터타입을 요구, 이 함수가 데이터에 접근해서 문자열의 길이를 세야하므로 문자열의 시작 주소를 주는 것임. 
	int ilen_1 = GetLength(szName);
	
	
	// 문자열 이어 붙이기
	wchar_t szString[100] = L"abc";
	wcscat_s(szString,100, L"def"); // 원형에 소스 문자를 이어 붙이는 거기 때문에 앞은 원본, size , 뒤는 const 포인터 타입임, "def"처럼 문자를 넣어도됨. 문자는 주소값을 반환하기 때문에/
	StrCat(szString, 100, L"defghuijk");// 내가만든 코드

	// 두 문자열이 일치 하는지 확인. 
	int iRet = wcscmp(L"abc", L"abcd"); // 두 문자열이 일치 하는지 확인, 완벽히 일치하면 0을 반환, 왼쪽 문자열이 더 사전순에서 우열이 높아. 그럼 1 반환, 오른쪽이 우열이 더 높으면 -1 반환. ex) abc < cbc, acb > abc
	
	int L = MyStrCmp(L"acc", L"abcdefg");

	return 0;
}
//문자열 길이 반환 함수 직접 만들기

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
	while (_pStr[i] != '\0') //null 문자는 이렇게 적어야함. 
	{
		++i;
	}
	return i;
}

// 문자열 이어 붙이기 함수 직접 만들기
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1) //Null 문자 공간까지 계산
	{
		assert(nullptr);// 특정 상황에 코드를 중단시키고 여기에 추가 인자를 뭘 넣냐에 따라 출력되는 말을 다르게 할 수 있음. 사용자로 하여금 문제를 인식할 수 있게. 

	}
	//1. Dest 문자열의 끝을 확인( 문자열이 이어 붙을 시작 위치
	iDestLen; //Dest 문자열의 끝 인덱스

	//2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	//3. Src 문자열의 끝을 만나면 반복 종료
	for (int i = 0; i < iSrcLen + 1; ++i) //\n문자도 들어가야 하기 때문에 iSrcLen + 1을 함.  
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}

	 //문자를 이어 붙이기
	
}
// 문자열이 일치하는지 확인
// 내가만든거
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
// 예시;
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