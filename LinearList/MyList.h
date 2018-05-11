#ifndef MYLIST_H
#define MYLIST_H

#include <stdio.h>
#include <iostream>

#define MaxLen 1024
typedef int datatype;
using namespace std;

/*===============线性表的顺序结构实现==================*/
class MyList1
{
public:
	MyList1();
	~MyList1();
	void ClearList1();                        
	bool isEmptyList1();
	int List1Length();
	datatype GetElem1(int i);						 // 获取第i个元素的值
	int LocateElem1(datatype x);                      // 获取值等于x的元素位置，返回下标
	bool Insert1(datatype x, int i);                  // 在第i个位置插入值为x的元素，表长加1
	bool Delete1(int i);                      // 删除第i个位置的元素
	datatype GetPriorElem1(int i);                 // 取线性表第i个元素的直接前趋的值
	datatype GetNextElem1(int i);                  // 取线性表第i个元素的直接后趋的值
	void List1Traverse();                     // 输出显示List的值

private:
	int List1Len;             // 线性表的长度
	datatype *List1_p;        // 指向线性表的指针

};

/*===============线性表的单链表结构实现==================*/
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;      // 定义指向下一个Node类型的指针next
};

template<class DataType>
class MyList2
{
public:
	MyList2();
	// 单链表有参构造器(头插法)
	MyList2(int n, DataType array[]);
	MyList2(DataType array[], int n);   // 尾插法
	~MyList2();
	int List2Length();
	DataType GetElem2(int i);						 // 获取第i个元素的值
	int LocateElem2(DataType x);                      // 获取值等于x的元素位置，返回下标
	bool Insert2(DataType x, int i);                  // 在第i个位置插入值为x的元素，表长加1
	bool Delete2(int i);                      // 删除第i个位置的元素
	void List2Traverse();                     // 输出显示List的值
	bool List2Invert();                  // 单链表逆置

private:
	Node<DataType> *head;          // 单链表的头指针,头指针指向头结点

};

// 单链表无参构造器
template<class DataType>
MyList2<DataType>::MyList2()
{
	head = new Node<DataType>;
	head->next = NULL;
}

// 单链表有参构造函数（头插法）
template<class DataType>
MyList2<DataType>::MyList2(int n, DataType array[])
{
	// 初始化一个空链表，空链表只包括一个头结点
	// 头结点包含一个数据域和一个头指针，头指针指向头结点
	// 头结点的头指针指向第一个结点
	// 头结点一般存放一些特殊信息，如数据类型的长度
	// 头结点的存在可以简化一些操作
	head = new Node<DataType>;
	head->next = NULL;
	
	for (int m = 0; m < n; m++)
	{
		Node<DataType> *p = new Node<DataType>;
		p->data = array[m];
		// 将结点插入到头结点之前
		// 即插入的新结点指向空，而原来的头结点指向新结点
		p->next = head->next;
		head->next = p;
	}

}

// 单链表有参构造函数（尾插法）
template<class DataType>
MyList2<DataType>::MyList2( DataType array[], int n)
{
	
	head = new Node<DataType>;
	head->next = NULL;

	Node<DataType> *r = head;   

	for (int m = 0; m < n; m++)
	{
		Node<DataType> *p = new Node<DataType>;
		p->data = array[m];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

// 单链表的析构函数
template<class DataType>
MyList2<DataType>::~MyList2()
{
	Node<DataType> *p;
	while (head->next != NULL)
	{
		p = head;
		head = head->next;
		delete p;
	}
}


template<class DataType>
int MyList2<DataType>::List2Length()
{
	Node<DataType> *p = head->next;
	int m = 0;
	while (p != NULL)
	{
		p = p->next;
		m = m + 1;
	}
	return m;
}


// 单链表的插入，在第i个结点处插入x
template<class DataType>
bool MyList2<DataType>::Insert2(DataType x, int i)
{
	Node<DataType> *p = head->next;    // 工作指针指向第一个结点
	int m = 1;
	// 将工作指针移到第i个位置
	while (p != NULL && m < i-1)
	{
		p = p->next;
		m = m + 1;

	}
	if (p == NULL)
	{
		cout << "Error Insert Position!" << endl;
		return false;

	}
	else
	{
		Node<DataType> *s = new Node<DataType>;
		s->data = x;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

// 单链表的按值查找，返回指定元素在单链表中的序号，如果找不到就返回-1
template<class DataType>
int MyList2<DataType>::LocateElem2(DataType x)
{
	// 定义工作指针
	Node<DataType> *p = head->next;
	int m = 1;
	while (p->next != NULL)
	{
		if (p->data == x)
			return m;
		p = p->next;
		m++;
	}
	return -1;
}

// 返回单链表第i个位置的元素值
template<class DataType>
DataType MyList2<DataType>::GetElem2(int i)
{
	// 定义工作指针
	Node<DataType> *p = head->next;
	int m = 1;
	while (p != NULL&&m != i)
	{
		p = p->next;
		m = m + 1;
	}
	if (p == NULL)
	{
		cout << "Error Input Position!" << endl;
		return DataType(-1);
	}
	else
	{
		return p->data;
	}
	
}

template<class DataType>
bool MyList2<DataType>::Delete2(int i)
{
	Node<DataType> *p = head->next;
	int m = 1;
	// 指向第i-1个结点
	while (p != NULL && m < i - 1)
	{
		p = p->next;
		m = m + 1;
	}
	if (p == NULL)
	{
		cout << "Error Input Position!" << endl;
		return false;
	}
	else
	{
		Node<DataType> *q = p->next;
		p->next = q->next;
		delete q;
		return true;
	}

}

template<class DataType>
void MyList2<DataType>::List2Traverse()
{
	Node<DataType> *p = head->next;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

template<class DataType>
bool MyList2<DataType>::List2Invert()
{
	Node<DataType> *p, *q, *r;
	p = head->next;		// 指向第一个结点
	q = p->next;		// 指向第二个结点
	while (q != NULL)		// 如果该链表并不是只有一个元素
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	head->next->next = NULL;
	head->next = p;
	return true;
}


#endif