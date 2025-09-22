#include<iostream>
#include"ENUMCBST.h"

using std::cout;
using std::endl;
using std::wcout;
int main()
{
	CBST<int, int> bstint;

	tPair<int, int> pair;
	bstint.insert(make_bstpair(100, 0));      //            100
	bstint.insert(make_bstpair(150, 0));	  //		50      150
	bstint.insert(make_bstpair(50, 0));		  //	  25  75  125  175
	bstint.insert(make_bstpair(25, 0));
	bstint.insert(make_bstpair(75, 0));
	//bstint.insert(make_bstpair(125, 0));
	bstint.insert(make_bstpair(175, 0));

	CBST<int, int>::iterator Iter = bstint.begin();
	Iter = bstint.find(150);

	(*Iter).first; // 별은 pair 구조체를, pair.first
	Iter->first; // 화살표는 pair의 주소값을 줌. 원래는 Iter->->first 가 맞는말임. 반환된주소->first 일렇게 해야 주소에서 first 로 접근하는 건데 화살표는 주소를 반환할경우 이걸 생략할 수 있게 해줌. 

	for (Iter = bstint.begin(); Iter != bstint.end(); ++Iter) // 이진탐색트리는 중위순회를 이용함. 따라서 ++도 중위순회기준으로 되야함. 즉 중위 후속자(in order successor)로 이동해야함. 
	{
		wcout << Iter->first << L" " << Iter->second << endl;
	}


	Iter = bstint.find(175); // 25를 가진 노드를 지정. 
	Iter = bstint.erase(Iter); // 삭제된 다음을 가리키므로 중위 후속자를 가리킴. 

	return 0;
}
// BST 내부 안에는 특정 노드의 중위 선행자와 중위 후속자가 누군지 알 수 있는 코드가 구현되어 있어야 함. 