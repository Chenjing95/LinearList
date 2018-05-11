#ifndef MYLIST_H
#define MYLIST_H

#include <stdio.h>
#include <iostream>

#define MaxLen 1024
typedef int datatype;
using namespace std;

/*===============���Ա��˳��ṹʵ��==================*/
class MyList1
{
public:
	MyList1();
	~MyList1();
	void ClearList1();                        
	bool isEmptyList1();
	int List1Length();
	datatype GetElem1(int i);						 // ��ȡ��i��Ԫ�ص�ֵ
	int LocateElem1(datatype x);                      // ��ȡֵ����x��Ԫ��λ�ã������±�
	bool Insert1(datatype x, int i);                  // �ڵ�i��λ�ò���ֵΪx��Ԫ�أ�����1
	bool Delete1(int i);                      // ɾ����i��λ�õ�Ԫ��
	datatype GetPriorElem1(int i);                 // ȡ���Ա��i��Ԫ�ص�ֱ��ǰ����ֵ
	datatype GetNextElem1(int i);                  // ȡ���Ա��i��Ԫ�ص�ֱ�Ӻ�����ֵ
	void List1Traverse();                     // �����ʾList��ֵ

private:
	int List1Len;             // ���Ա�ĳ���
	datatype *List1_p;        // ָ�����Ա��ָ��

};

/*===============���Ա�ĵ�����ṹʵ��==================*/
template<class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;      // ����ָ����һ��Node���͵�ָ��next
};

template<class DataType>
class MyList2
{
public:
	MyList2();
	// �������вι�����(ͷ�巨)
	MyList2(int n, DataType array[]);
	MyList2(DataType array[], int n);   // β�巨
	~MyList2();
	int List2Length();
	DataType GetElem2(int i);						 // ��ȡ��i��Ԫ�ص�ֵ
	int LocateElem2(DataType x);                      // ��ȡֵ����x��Ԫ��λ�ã������±�
	bool Insert2(DataType x, int i);                  // �ڵ�i��λ�ò���ֵΪx��Ԫ�أ�����1
	bool Delete2(int i);                      // ɾ����i��λ�õ�Ԫ��
	void List2Traverse();                     // �����ʾList��ֵ
	bool List2Invert();                  // ����������

private:
	Node<DataType> *head;          // �������ͷָ��,ͷָ��ָ��ͷ���

};

// �������޲ι�����
template<class DataType>
MyList2<DataType>::MyList2()
{
	head = new Node<DataType>;
	head->next = NULL;
}

// �������вι��캯����ͷ�巨��
template<class DataType>
MyList2<DataType>::MyList2(int n, DataType array[])
{
	// ��ʼ��һ��������������ֻ����һ��ͷ���
	// ͷ������һ���������һ��ͷָ�룬ͷָ��ָ��ͷ���
	// ͷ����ͷָ��ָ���һ�����
	// ͷ���һ����һЩ������Ϣ�����������͵ĳ���
	// ͷ���Ĵ��ڿ��Լ�һЩ����
	head = new Node<DataType>;
	head->next = NULL;
	
	for (int m = 0; m < n; m++)
	{
		Node<DataType> *p = new Node<DataType>;
		p->data = array[m];
		// �������뵽ͷ���֮ǰ
		// ��������½��ָ��գ���ԭ����ͷ���ָ���½��
		p->next = head->next;
		head->next = p;
	}

}

// �������вι��캯����β�巨��
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

// ���������������
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


// ������Ĳ��룬�ڵ�i����㴦����x
template<class DataType>
bool MyList2<DataType>::Insert2(DataType x, int i)
{
	Node<DataType> *p = head->next;    // ����ָ��ָ���һ�����
	int m = 1;
	// ������ָ���Ƶ���i��λ��
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

// ������İ�ֵ���ң�����ָ��Ԫ���ڵ������е���ţ�����Ҳ����ͷ���-1
template<class DataType>
int MyList2<DataType>::LocateElem2(DataType x)
{
	// ���幤��ָ��
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

// ���ص������i��λ�õ�Ԫ��ֵ
template<class DataType>
DataType MyList2<DataType>::GetElem2(int i)
{
	// ���幤��ָ��
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
	// ָ���i-1�����
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
	p = head->next;		// ָ���һ�����
	q = p->next;		// ָ��ڶ������
	while (q != NULL)		// �������������ֻ��һ��Ԫ��
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