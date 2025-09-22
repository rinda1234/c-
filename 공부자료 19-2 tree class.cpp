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

	(*Iter).first; // ���� pair ����ü��, pair.first
	Iter->first; // ȭ��ǥ�� pair�� �ּҰ��� ��. ������ Iter->->first �� �´¸���. ��ȯ���ּ�->first �Ϸ��� �ؾ� �ּҿ��� first �� �����ϴ� �ǵ� ȭ��ǥ�� �ּҸ� ��ȯ�Ұ�� �̰� ������ �� �ְ� ����. 

	for (Iter = bstint.begin(); Iter != bstint.end(); ++Iter) // ����Ž��Ʈ���� ������ȸ�� �̿���. ���� ++�� ������ȸ�������� �Ǿ���. �� ���� �ļ���(in order successor)�� �̵��ؾ���. 
	{
		wcout << Iter->first << L" " << Iter->second << endl;
	}


	Iter = bstint.find(175); // 25�� ���� ��带 ����. 
	Iter = bstint.erase(Iter); // ������ ������ ����Ű�Ƿ� ���� �ļ��ڸ� ����Ŵ. 

	return 0;
}
// BST ���� �ȿ��� Ư�� ����� ���� �����ڿ� ���� �ļ��ڰ� ������ �� �� �ִ� �ڵ尡 �����Ǿ� �־�� ��. 