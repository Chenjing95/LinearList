#include "MyList.h"
#include <vector>

void main()
{
	// ���Ա��˳��ʵ�ֽṹ

	cout << "==================���Ա��˳��ʵ�ֽṹ==============" << endl;
	MyList1 mylist1;

	cout << "���Ƿ�Ϊ�գ�";
	cout << mylist1.isEmptyList1() << endl;
	cout << "��ĳ���Ϊ��";
	cout << mylist1.List1Length() << endl;

	mylist1.Insert1(2, 1);
	mylist1.Insert1(0, 2);
	mylist1.Insert1(1, 3);
	mylist1.Insert1(8, 4);
	mylist1.Insert1(4, 5);
	mylist1.Insert1(1, 6);
	mylist1.Insert1(9, 7);

	mylist1.List1Traverse();
	cout << "���Ƿ�Ϊ�գ�";
	cout << mylist1.isEmptyList1() << endl;
	cout << "��ĳ���Ϊ��";
	cout << mylist1.List1Length() << endl;

	cout << "��4��Ԫ��Ϊ��";
	cout << mylist1.GetElem1(4) << endl;

	cout << "1�ڱ��е�λ���ǣ�";
	cout << mylist1.LocateElem1(1) << endl;

	cout << "ɾ����5��Ԫ�غ�";
	mylist1.Delete1(5);
	mylist1.List1Traverse();

	cout << "��7��Ԫ��ǰ�ǣ�";
	cout << mylist1.GetPriorElem1(7) << endl;

	cout << "��2��Ԫ�غ��ǣ�";
	cout << mylist1.GetNextElem1(2) << endl;

	mylist1.ClearList1();
	cout << "������պ�";
	mylist1.List1Traverse();


	// ���Ա�ĵ�����ʵ�ֽṹ
	cout << "==================���Ա�ĵ�����ʵ�ֽṹ==============" << endl;
	int array[] = { 2, 0, 1, 8, 0, 4, 1, 9 };
	
	MyList2<int> mylist2 = MyList2<int>(array, 8);
	cout << "���������";
	mylist2.List2Traverse();
	
	cout << "������ĳ��ȣ�";
	cout << mylist2.List2Length() << endl;

	cout << "�������5��Ԫ���ǣ�" << mylist2.GetElem2(5) << endl;

	cout << "Ԫ��1λ�ڵ������λ���ǣ�" << mylist2.LocateElem2(1) << endl;

	cout << "�ڵ�����ĵ�4��λ�ò���Ԫ��23��" << endl;
	mylist2.Insert2(23, 4);
	mylist2.List2Traverse();
	cout << "������ĳ��ȱ�Ϊ��" << mylist2.List2Length() << endl;

	cout << "ɾ��������ĵ�6��Ԫ�غ�" << endl;
	mylist2.Delete2(6);
	mylist2.List2Traverse();
	cout << "������ĳ��ȱ�Ϊ��" << mylist2.List2Length() << endl;

	cout << "������͵����ú�";
	mylist2.List2Invert();
	mylist2.List2Traverse();




}