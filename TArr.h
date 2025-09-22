#pragma once
// 뭐든지 다 저장할 수 있는 가변배열 클래스
#include <assert.h>
// 포인터는 8바이트, 즉 이 클래스의 객체를 생성하면 16바이트를 사용함. (이너 클래스는 객체안에 있는게 아니라 클래스 안에 있는거기 떄문에 따로 이너클래스의 객체를 만드는게 아니면 공간이 잡히지 않는다.)
// 만약 이너 클래스도 객체를 만들면  36바이트를 만듬. 


// 이너 클래스의 특징
// 1. 범위지정연산자로 CArr::iterator 이런식으로 사용해야됨. 
// 2. 이너 클래스가 선언되어 있는 원래 클래스(CArr)의 private 멤버에 접근 가능함. 
// 3. 반대로 원래 클래스(CArr)이 이너클래스의 private 멤버에 접근할 수 없음. 
template<typename T>
class CArr
{
private: 
	T* m_pData; // 단축기 ctrl rr : 단어 한번에 바꾸기
	int m_iCount; // 이거는 개수를 기록하는 거기 떄문에 바꿀 필요 없음. 
	int m_iMaxCount;

public:
	void push_back(const T& _iData); // 이거는 바꿔줘야함. 들어오는 데이터가 다르기 때문에 
	// 이 가변배열은 T에 따른 자료형을 저장하는데 이게 클래스면 저장하는 데이터 타입이 얼마나 클지 모름. 
	// 엄청 큰 데이터를 저장할 수 있기 떄문에 데이터 복사는 비효율적. 따라서 레퍼런스(참조자)로 바꿔주는게 좋음. 또한 원본을 바꾸면 안되기 때문에 const 도 붙여줌.  
	void resize(int _iResizeCount); // 이것도  int여도 상관없음.  
	T* data() { return m_pData; }
	int size() { m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);
	void Clear()
	{
		m_iCount = 0; // 이러면 다시 처음부터 채워지기 때문에 원래 있던 데이터는 의미가 없어짐. 대신 엄청 많은 데이터를 넣었다가 clear하면 공간이 많이 늘어난 상태로 처음부터 다시 채워 넣음. 	}
	}

	// 아직 iterator라는 클래스가 구현되기 전이므로 한번 명시해줘야 함. 
	class iterator;
	iterator begin(); //begin()이 iterator를 반환하기 때문에 . 
	iterator end();
	iterator erase(iterator& _iter);
public:

	CArr();
	~CArr();
	// iterator 클래스 만들기
	// 이너 클래스 이므로 클래스 내부에 선언
	class iterator // 이 클래스는 이너 클래스이기 때문에 CArr의 객체를 만들어도 이 클래스의 객체는 안만들어짐. 따로 만들어 줘야 함. 
	{ // 템플릿 안에 만들어 졌으므로 얘도 템플릿적용됨. 
	private:
		CArr* m_pArr; // iterator 가 기리킬 데이터를 관리하는 가변배열 주소.   이걸 알고 있으면 어차피 안에 데이터가 들어있으므로 T* mpData를 알 필요가 없음. 
		T* m_pData; // 데이터들의 시작 주소
		
		// 위의 변수를 넣고 안놓고는 설계 방향성의 차이가 있음.
		
		// 1. 안넣음
		// 안넣었을때엔 가변배열의 공간이 다 차서 사이즈가 증가됐을때 iterator는 자동으로 변경된 주소를 가리킴. 그냥 벡터에 m_idx 부분을 기리키면 되므로 . 
		
		// 2. 넣음.
		// 넣으면 가변배열의 공간이 다 차서 사이즈가 증가됐을때 iterator가 원래 자신이 가지고 있던 주소와 해당 주소가 다르므로 문제가 있다고 생각함. 우리가 따라하는 vector는 이런 방식임. 따라서 vector에서 iterator는 배열을 더이상 키우지 않을때 해야됨.  
		int m_iIdx;	// 그게 그 vector의 몇번째인지 저장해야됨. vector[i}
		// m_iIdx가 -1일떄를 end iterator 라고 봄. 

		// iterator 삭제할때 쓰임. 
		bool m_bValid; //iterator 유효성 체크. ㅇ

	// 연산자 오버로딩
	public:
		T& operator *() // 그냥 T로 하면 값을 바꿀 수 없으므로 레퍼런스를  해줌 .
		{
			// iterator 가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator인 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)// false = m_bValid랑 같은말. 
				assert(nullptr);


			return m_pData[m_iIdx];
		}
		// 전위
		iterator& operator ++() // 반환타입이 자기 자신이 되어야 증감 연산을 한 뒤 계속 연산이 가능함.  
		{
			// 1. end iterator 인 경우
			// 2. iterator 가 알고있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우(공간 확장으로 주소가 달라진 경우)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
				assert(nullptr);

			// 3. iterator 가 마지막 데이터를 가리키고 있는 경우
			if (m_pArr->m_iCount - 1 == m_iIdx)
			{
				m_iIdx = -1;
				return *this;
			}


			++m_iIdx;
			return *this; //this는 해당 객체의 주소를 반환하기 때문에 역참조해서 리턴해야 객체가 리턴됨. 
		}
		iterator& operator --() 
		{
			// 1. iterator가 알고 있는 주소와, 가변 배열이 알고있는 주소가 달라진 경우
			// 2. iterator가 첫번째 데이터를 가리키고 있을 경우
			if (m_pArr->m_pData != m_pData || 0 == m_iIdx)
			{
				assert(nullptr);
			}
			--m_iIdx;

			return *this; 
		}

		// 후위
		// 자기 자신을 반환하면 절대 후위 연산자 처럼 동작할 수 없음. 반환하면 다음 대상을 가리키게 이미 되버린거기때문에. 
		// 따라서 복사본을 줌. 
		iterator operator ++(int)// 인자가 있지만 없는거임. 저 인자로 후위연산이라고 컴파일러가 생각하는거임. 
		{
			// 호출되자 마자지역변수로 iterator하나를 또만듬
			iterator copy_iter = *this; // 후위연산을 호출한 객체랑 같아짐. 복사생성자가 호출됨. 

			++(*this); //후위연산을 호출한 객체를 증가시켜줌. 
			// 내가 반환하는건 복사본임. 
			return copy_iter; // 증가시키기전 카피본을 반환하므로 후위연산인것처럼 작동함. 
		}
		iterator operator --(int)
		{
			iterator copy_iter = *this;
			--(*this);

			return copy_iter;
		}

		// 비교 연산자 ==. !=
		bool operator ==(const iterator& _otheriter) // 비교 연산이기 때문에 반환타입이 bool임
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator !=(const iterator& _otheriter) // 비교 연산이기 때문에 반환타입이 bool임
		{
			/*
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return false;
			}
			return true;
			*/
			// 위의 식을 좀더 간결하게 정리하면 
			return !(*this == _otheriter);
		} 
	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1) //아무것도 가리키고 있지 않다는 의미
			, m_bValid(false)
		{
		}
		iterator(CArr* _pArr, T* _pData, int iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(iIdx) //아무것도 가리키고 있지 않다는 의미
			, m_bValid(false) 
		{
			// 제대로된 가변배열 안에 특정부분을 가리키고 있으면 
			if (nullptr != _pArr && 0 <= iIdx)
			{
				m_bValid = true; // iterator 유효.
			}
		}
		~iterator()
		{
		}
		// friend 키워드
		friend class CArr; // 사적인 private 까지 접근가능. 
						   // A가 B의 friend라고 B가 A의 friend는 아님. 
						   // A가 B의 friend이고 B가 C의 friend라고 A가 C의 friend는 아님. 
						   // friend가 적힌 클래스의 private에 접근 가능e. 
						   // 귀찮다고 다 friend 선언하면 장기적으로 유지보수나 다른 문제가 생길 수 있음. 
						   // 따라서 멤버함수만 friend 선언해서 private에 접근할 수 있게 하는게 좋음. 
	};

};

// template는 cpp 파일에 구현되어 있으면 안되고 헤더파일에 있어야함. 
// main함수에서 템플릿으로 함수를 호출할때 헤더파일에 T부분만 원하는 자료형으로 바꿈.  따라서 cpp파일은 안바뀜. 근데 maincpp에서는 이를 모름. 
// TArr.cpp파일은 안바뀜. 


template<typename T>
CArr<T>::CArr() // 생성자는 생성자인데 CArr 클래스에 T버전 안에 구현되어 있는 생성자. 
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];
}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _iData)
{// this 생략 가능
	if (this->m_iMaxCount <= this->m_iCount)
	{
		resize(this->m_iMaxCount * 2);
	}
	this->m_pData[this->m_iCount++] = _iData;
}
template<typename T>
void CArr<T>::resize(int _iResizeCount)
{

	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다. 
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다. 
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] m_pData;

	// 4. 배열이 새로 항당된 공간을 가리키게 한다. 
	m_pData = pNew;

	// 5. MaxCount 변경점 적용
	m_iMaxCount = _iResizeCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin() //앞에 tyoename을 붙인 이유. 반환타입이 이너 클래스인 경우(여기서는 iterator), CArr 안에 있는 이너 클래스, iterator라는 타입이다는 것을 알려주기 위해 적음. 
{
	// 시작을 기리키는 iterator를 만들어서 반환해줌. 
	// CArr클래스 멤버에 iterator 객체가 안만들어 졌으므로 반환타입이 레퍼런스면 안됨.
	// iterator iter;
	// iter.m_pData = this->m_pData; //this 생략 가능. m_pData가 시작주소를 기리키므로 iter.m_pData에 저장.
	// iter.m_iIdx = 0;
	
	
	// 이럴거면 생성자로 만드는 게 나음. 

	//iterator iter(m_pData, 0);
	// 그런데 어차피 바로 반환하기 떄문에 임시객체라고 변수명을 적지않고 바로 반환 가능. 

	// 만약 데이터가 하나도 없을경우(배열안에)
	if (0 == m_iCount)
		return iterator(this, m_pData, -1); // 데이터가 없는 경우, begin() == end() // end iterator
	else
		return iterator(this ,m_pData, 0); //iterator 반환. 
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// 끝의 다음을 기리키는 iterator 를 만들어서 반환해줌
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter) // 반환타입이 iterator임.  // 수정할 여지가 있으므로 iterator&를 인자로 받음
{
	// 이 함수는 CArr의 멤버함수이므로 iterator의 private에 접근할 수 없음. 
	// iterator 가 자신의 private 부분을 얻어올 수 있게 해주는 멤버함수를 제공하거나
	// 혹은 terator와 가변배열 쌍방향으로 private를 공유하려면 friend 키워드 사용. 


	// 예외처리.
	// 1. iterator 가 다른 가변배열의 index의 위치를 가리키고 있음 : iterator가 다른 Arr 쪽 요소를 가리키는 경우
	// 2. iterator 가 end iterator를 가리키고 있음
	// 3. iterator 가 내가 가진 데이터의 카운터보다 접근하는 인덱스가 더 큼. (인덱스기 때문에 카운터랑 같아도 안됨. ))
	if (_iter.m_pArr != this || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}

	// iterator 가 기리키는 부분 제거
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);
	for (int i = 0; i <= iLoopCount; ++i)
	{
		m_pData[_iter.m_iIdx + i] = m_pData[_iter.m_iIdx + 1 + i];// 이런식으로 하면 실수할 가능성이 높음. 메모리 오버해서 접근해기 쉬움. 이런거 할때 여러번 테스트 하는 게 좋음. 
	}
	_iter.m_bValid = false; // 이 iterator를 삭제하기 때문에 유효하지 않은 iterator라는 것을 표시. //반환하는 iterator는 생성자에서 유효해짐.  

	// 카운트 감소. 
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx); //  return되는 iterator가 바로 삭제된 다음 요소를 가르키는 iterator를 다시 주겠다. 따라서 veciter1 = vec1.erase(veciter1) 이런식으로 다시 iterator를 받아야 됨. 
	// 가변배열에서는 어차피 데이터가 앞으로 떙겨지는 것이므로 iterator가 바뀌지 않음. 따라서 다음 요소를 가리킬 필요가 없음. 
}