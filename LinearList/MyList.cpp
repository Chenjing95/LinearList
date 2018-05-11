#include "MyList.h"

MyList1::MyList1()
{
	List1_p = new datatype[MaxLen];
	List1Len = 0;
}

MyList1::~MyList1()
{
	delete[]List1_p;
	List1_p = NULL;
}

void MyList1::ClearList1()
{
	List1_p = NULL;
	List1Len = 0;                 //?????Add some ????
}

bool MyList1::isEmptyList1()
{
	if (List1Len == 0)
		return true;
	else
		return false;
}

int MyList1::List1Length()
{
	return List1Len;
}

datatype MyList1::GetElem1(int i)
{
	if (i <= 0 || i > List1Len)
	{
		cout << "Error Input!" << endl;
		return 0;
	}
	else
		return List1_p[i];       // �����±��0��ʼ ���Ա��±��1��ʼ
	
}
// ȷ��ֵΪe��Ԫ�ص�λ�ã��Ҳ�������-1,�ж�����ص�һ��
int MyList1::LocateElem1(datatype x)
{
	if (List1Len == 0)
	{
		cout << "List is null!" << endl;
		return -1;
	}
	else
	{
		for (int m = 1; m <= List1Len; m++)
		{
			if (List1_p[m] == x)
				return m;
		}
	}
	return -1;
	
}
// �ڵ�i��λ�ò���Ԫ�أ���i��λ�ú��Ԫ��ȫ������
bool MyList1::Insert1(datatype x, int i)
{
	if (List1Len == MaxLen)
	{
		cout << "List is full!" << endl;
		return false;
	}
	if (i <= 0 || i > List1Len + 1)
	{
		cout << "Index Boundary!" << endl;
		return false;
	}
	else
	{
		for (int m = List1Len; m >= i; m--)
		{
			List1_p[m+1] = List1_p[m];
		}
		List1_p[i] = x;
		List1Len = List1Len + 1;
		return true;
	}
}
// ɾ����i��λ�õ�Ԫ�أ���i��λ�õ�Ԫ��ȫ��ǰ��
bool MyList1::Delete1(int i)
{
	if (i <= 0 || i > List1Len)
	{
		cout << "Index Boundary!" << endl;
		return false;
	}
	else
	{
		for (int m = i; m <= List1Len; m++)
		{
			List1_p[m] = List1_p[m + 1];
		}
		List1Len = List1Len - 1;
		return true;
	}
}
datatype MyList1::GetPriorElem1(int i)
{
	if (i <= 0 || i > List1Len)
	{
		cout << "Index Boundary!";
		return datatype(0);
	}
	else if (i == 1)
	{
		cout << "No Prior Elem!";
		return datatype(0);
	}
	else
	{
		return List1_p[i - 1];
	}
}

datatype MyList1::GetNextElem1(int i)
{
	if (i <= 0 || i > List1Len)
	{
		cout << "Index Boundary!";
		return datatype(0);
	}
	else if (i == List1Len)
	{
		cout << "No Next Elem!";
		return datatype(0);
	}
	else
	{
		return List1_p[i + 1];
	}
}

void MyList1::List1Traverse()
{
	if (List1Len == 0)
	{
		cout << "List is empty!" << endl;
	}
	cout << "List Elems are as follows:";
	for (int i = 1; i <= List1Len; i++)
	{
		cout << List1_p[i] << " ";
	}
	cout << endl;
}

