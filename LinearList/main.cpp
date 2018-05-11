#include "MyList.h"
#include <vector>

void main()
{
	// 线性表的顺序实现结构

	cout << "==================线性表的顺序实现结构==============" << endl;
	MyList1 mylist1;

	cout << "表是否为空：";
	cout << mylist1.isEmptyList1() << endl;
	cout << "表的长度为：";
	cout << mylist1.List1Length() << endl;

	mylist1.Insert1(2, 1);
	mylist1.Insert1(0, 2);
	mylist1.Insert1(1, 3);
	mylist1.Insert1(8, 4);
	mylist1.Insert1(4, 5);
	mylist1.Insert1(1, 6);
	mylist1.Insert1(9, 7);

	mylist1.List1Traverse();
	cout << "表是否为空：";
	cout << mylist1.isEmptyList1() << endl;
	cout << "表的长度为：";
	cout << mylist1.List1Length() << endl;

	cout << "第4个元素为：";
	cout << mylist1.GetElem1(4) << endl;

	cout << "1在表中的位置是：";
	cout << mylist1.LocateElem1(1) << endl;

	cout << "删除第5个元素后：";
	mylist1.Delete1(5);
	mylist1.List1Traverse();

	cout << "第7个元素前是：";
	cout << mylist1.GetPriorElem1(7) << endl;

	cout << "第2个元素后是：";
	cout << mylist1.GetNextElem1(2) << endl;

	mylist1.ClearList1();
	cout << "将表清空后：";
	mylist1.List1Traverse();


	// 线性表的单链表实现结构
	cout << "==================线性表的单链表实现结构==============" << endl;
	int array[] = { 2, 0, 1, 8, 0, 4, 1, 9 };
	
	MyList2<int> mylist2 = MyList2<int>(array, 8);
	cout << "输出单链表：";
	mylist2.List2Traverse();
	
	cout << "单链表的长度：";
	cout << mylist2.List2Length() << endl;

	cout << "单链表第5个元素是：" << mylist2.GetElem2(5) << endl;

	cout << "元素1位于单链表的位置是：" << mylist2.LocateElem2(1) << endl;

	cout << "在单链表的第4个位置插入元素23后：" << endl;
	mylist2.Insert2(23, 4);
	mylist2.List2Traverse();
	cout << "单链表的长度变为：" << mylist2.List2Length() << endl;

	cout << "删除单链表的第6个元素后：" << endl;
	mylist2.Delete2(6);
	mylist2.List2Traverse();
	cout << "单链表的长度变为：" << mylist2.List2Length() << endl;

	cout << "单链表就地逆置后：";
	mylist2.List2Invert();
	mylist2.List2Traverse();




}