#if 0
#include<iostream>
using namespace std;

// �������ͽṹ��

typedef int ElemType;

// ˫��ѭ������ṹ��

typedef struct _DualNode
{
	ElemType data;   // �洢����������
	struct  _DualNode *prior;   // ָ�����ǰ��
	struct  _DualNode *next;   // ָ����ĺ��
}DualNode, *DuaLinkList;

// ��ʼ��ͷ�ڵ�

void InitDualLinkList(DuaLinkList *pHead)
{
	*pHead = new DualNode;
	if (NULL==*pHead)
	{
		return;
	}
	(*pHead)->prior=*pHead;
	(*pHead)->next = *pHead;
}

// ��ȡ����ĳ���

int GetDualLInkListLength(DuaLinkList pHead)
{
	int count = 0;
	DuaLinkList nPos = pHead;

	while (nPos->next!=pHead)
	{
		nPos = nPos->next;
		count++;
	}
	return count;
}

// �ж������Ƿ�Ϊ��

bool IsEmpty(DuaLinkList pHead)
{
	if (pHead->next==pHead||pHead->prior==pHead)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ���ص�i��Ԫ�ص�ֵ

ElemType GetElem(DuaLinkList pHead,int index)
{

	if (index<=0||index>GetDualLInkListLength(pHead))
	{
		return -1;
	}


	for (int i = 0; i<index; i++)
	{
		pHead = pHead->next;
	}
	return pHead->data;
}

// ����ͷ�ڵ㺯��

void DestroyHeadDNode(DuaLinkList *pHead)
{
	delete *pHead;
	*pHead = NULL;

}

// ͷ�巨����

void InsertHeadDualLinkList(DuaLinkList *pHead, ElemType value)
{
	DuaLinkList pNew = new DualNode;
	
	if (NULL==pNew)
	{
		return;
	}
	pNew->data = value;

	if (*pHead ==(*pHead)->next|| *pHead ==(*pHead)->prior)
	{
		(*pHead)->next = pNew;
		(*pHead)->prior = pNew;
		pNew->next = (*pHead);
		pNew->prior = (*pHead);
	}
	else
	{
		(*pHead)->next->prior = pNew;
		pNew->next = (*pHead)->next;
		(*pHead)->next = pNew;
		pNew->prior = (*pHead);
	}
}

// β�巨����

void InsertTailDualLinkList(DuaLinkList *pHead, ElemType value)
{

	if ((*pHead)->next==*pHead||(*pHead)==(*pHead)->prior)
	{
		InsertHeadDualLinkList(pHead,value);
	}
	else
	{
		DuaLinkList pNew = new DualNode;
		if (NULL == pNew)
		{
			return;
		}
		pNew->data = value;
		
		pNew->prior = (*pHead)->prior;
		(*pHead)->prior->next = pNew;
		pNew->next = *pHead;
		(*pHead)->prior = pNew;
	}
}

// ˫�������±����Ԫ��

void  InsertByIndex(DuaLinkList *pHead,int pos, ElemType value)
{
	if (0==pos)
	{
		return;
	}
	if (pos>GetDualLInkListLength(*pHead))
	{
		InsertTailDualLinkList(pHead,value);
		return;
	}
	//if (1==pos)
	//{
	//	InsertHeadDualLinkList(pHead,value);
	//	return;
	//}

	DuaLinkList nPos = *pHead;
	for (int i = 0; i < pos; i++)
	{
		nPos = nPos->next;
	}

	DuaLinkList pNew = new DualNode;
	if (NULL==pNew)
	{
		return;
	}
	pNew->data = value;
    
	DuaLinkList temp = nPos;
	pNew->prior = temp->prior;
	temp->prior->next = pNew;
	pNew->next =temp;
	temp->prior = pNew;
}

// ���ص�i��Ԫ�صĵ�ַ

DuaLinkList GetElemAddress(DuaLinkList *pHead,int index)
{
	if (index<=0||index>GetDualLInkListLength(*pHead))
	{
		return NULL;
	}

	DuaLinkList nPos = *pHead;
	for (int i = 0; i < index; i++)
	{
		nPos = nPos->next;
	}
	return nPos;
}

// ������ʾ����

void ShowDuaLinkList(DuaLinkList pHead)
{
	DuaLinkList nPos = pHead;
	while (nPos->next!=pHead)
	{
		nPos = nPos->next;
		cout << nPos->data<<"   ";
	}
	cout << endl;
}

// ������ʾ����

void ReverseShowDualLinkList(DuaLinkList pHead)
{
	DuaLinkList nPos = pHead;
	while (pHead!= nPos->prior)
	{
		nPos = nPos->prior;
		cout << nPos->data << "   ";

	}
	cout << endl;
}

// ˫�������ð������

void BubleSort(DuaLinkList *pHead)
{
	DuaLinkList nPos = (*pHead)->next;
//	DuaLinkList pNext = nPos->next;
	int len = GetDualLInkListLength(*pHead);

	/*	for (int i = 0; i <len; i++)
		{
			for (int j = 0; j < len - i - 1; j++)
			{
				if (nPos->data>nPos->next->data)
				{
					DuaLinkList temp = nPos;

					nPos->prior->next = temp->next;
					temp->next->prior = nPos->prior;

					nPos = temp->next;
					DuaLinkList tp = nPos;

					nPos->next = temp;
					temp->prior = nPos;
					temp->next = tp;
					tp->prior = temp;
					//temp->next->prior = nPos->prior;

				}

			}
		}
	*/

	while (len>1) 
	{
		while (nPos->next!=*pHead)
		{
			if (nPos->data>nPos->next->data)
			{
				ElemType temp;
				temp = nPos->data;
				nPos->data = nPos->next->data;
				nPos->next->data = temp;

			}
			nPos = nPos->next;
		}
		len--;
		nPos = (*pHead)->next;
	}
}

// ͷɾ����

void DeleteHeadDuaLinkList(DuaLinkList *pHead)
{
	if ((*pHead)->next != *pHead || (*pHead)->prior != *pHead)    //  �ж��Ƿ�ֻʣ��һ��ͷ�ڵ�
	{
		DuaLinkList  temp = (*pHead)->next;   // ����ʱ���������ͷ����ĵ�һ���ڵ㣻
		(*pHead)->next = temp->next;    // ͷ�ڵ�ָ��ɾ����ĵ�һ�����
		temp->next->prior = (*pHead);   // ɾ��������ĵ�һ������ǰ��ָ��ָ��ͷ�ڵ㣻
		delete temp;
		temp = NULL;
	}
}

// βɾ����

void DelTailDualLinkList(DuaLinkList *pHead)
{
	if ((*pHead)->next != *pHead || *pHead != (*pHead)->prior)   //  �ж��Ƿ�ֻʣ��һ��ͷ�ڵ�
	{
		DuaLinkList temp = (*pHead)->prior;          // ����ʱ���������ͷ�����ָ��ĵ�����һ���ڵ㣻
		
		temp->prior->next=(*pHead);   // �����еĵ�����һ�����ָ��ͷ�ڵ㣻
		(*pHead)->prior = temp->prior;   // ͷ�ڵ��ǰ��ָ��ָ�����ڶ���㣻

		delete temp;     // �ͷŵ�����һ�������ڴ棻
		temp= NULL;   
	}
}

// ɾ��˫�������е� i ��Ԫ��

void DelElemByIndex(DuaLinkList *pHead, int index)
{
	if (index <= 0 || 0 == GetDualLInkListLength(*pHead))
	{
		return;
	}

	if (index>GetDualLInkListLength(*pHead))
	{
		DelTailDualLinkList(pHead);
	}
	else
	{
		DuaLinkList nPos = *pHead;
		for (int i = 0; i < index; i++)
		{
			nPos = nPos->next;
		}
		DuaLinkList temp = nPos;   // ����ʱ������ס��Ҫɾ����Ԫ��

		nPos->prior->next = temp->next;   // ��Ҫɾ��Ԫ�ص�ǰһ�����ָ��ɾ��Ԫ�صĺ��Ԫ��
		temp->next->prior = nPos->prior;    // ɾ��Ԫ�صĺ��Ԫ�ص�ǰ��ָ��ɾ��Ԫ�ص�ǰ�����
		delete temp;
		temp = NULL;
	}

}

// ���˫����������ͷ�ڵ㣩

void ClearDuaLinkList(DuaLinkList *pHead)
{
	DuaLinkList nPos = *pHead;
	while (nPos->next != *pHead || *pHead != nPos->prior)
	{
		DelTailDualLinkList(pHead);
	}
}

// ����˫��������������ͷ�ڵ㣩

void DestoryDuaLinkList(DuaLinkList *pHead)
{
	if (*pHead!=(*pHead)->next||*pHead!=(*pHead)->prior)
	{
		ClearDuaLinkList(pHead);
	}
	DestroyHeadDNode(pHead);
}



// ���Գ���

void test()
{
	DuaLinkList DL = NULL;
	InitDualLinkList(&DL);


	//InsertTailDualLinkList(&DL,7);
	//InsertTailDualLinkList(&DL, 8);
	//InsertTailDualLinkList(&DL, 9);
	//InsertTailDualLinkList(&DL, 10);
	//ShowDuaLinkList(DL);
	//ReverseShowDualLinkList(DL);



//-------------------------------------------------------------test-----------------------------------------
/*
    InsertTailDualLinkList(&DL, 1);
	InsertTailDualLinkList(&DL, 2);
	InsertTailDualLinkList(&DL, 3);
	InsertTailDualLinkList(&DL, 4);
	InsertTailDualLinkList(&DL, 5);
	ShowDuaLinkList(DL);
	cout << GetDualLInkListLength(DL) << endl;
	cout << IsEmpty(DL) << endl;

	DelTailDualLinkList(&DL);
	ShowDuaLinkList(DL);
	//DelTailDualLiinkList(&DL);
	//ShowDuaLinkList(DL);
	//DelTailDualLiinkList(&DL);
	//ShowDuaLinkList(DL);
	//DelTailDualLiinkList(&DL);
	//ShowDuaLinkList(DL);
	//DelTailDualLiinkList(&DL);
	//ShowDuaLinkList(DL);
	//ShowReverseDualLinkList(DL);

	//DuaLinkList temp= GetElemAddress(&DL,3);
	//cout << temp << endl;

	//cout << GetElem(DL,3) << endl;

	//DelElemByIndex(&DL,5);
	//ShowDuaLinkList(DL);
	//ShowReverseDualLinkList(DL);
//	ClearDuaLinkList(&DL);

*/
//-------------------------------------------------------------test-----------------------------------------
	InsertTailDualLinkList(&DL,6);
	InsertTailDualLinkList(&DL, 5);
	InsertTailDualLinkList(&DL, 4);
	InsertTailDualLinkList(&DL, 3);
	InsertTailDualLinkList(&DL, 1);
	InsertTailDualLinkList(&DL, 2);
	ShowDuaLinkList(DL);
	ReverseShowDualLinkList(DL);
	cout << endl;
	
	BubleSort(&DL);
	ShowDuaLinkList(DL);
	ReverseShowDualLinkList(DL);
	DestoryDuaLinkList(&DL);
	int i=0;
}

int add(int a,int b)
{
	int jw = a&b;
	int jg = a^b;
	while (jw)
	{
		int t_a = jg;
		int t_b = jw << 1;
		jw = t_a&t_b;
		jg = t_a^t_b;
	}
	return jg;
}

int add2(int a,int b)
{
	int t;
	do
	{
		t = a^b;
		a = (a&b) << 1;
		b = a&t;
	} while (a);
	return b;
}



int add1(int a,int b)
{
	if (0==b)
	{
		return a;
	}
	int sum, carry;
	sum = a^b;
	carry = (a&b) << 1; 
	return add1(sum,carry);
}




int main(void)
{
	
	test();


	return  0;
}

#endif

/*
//��������
void InitList(DuLinkList *L);//��ʼ������
void ClearList(DuLinkList L);//��ձ�
void DestroyList(DuLinkList &L);//����˫������
int ListEmpty(DuLinkList L);//�жϱ��Ƿ�Ϊ��
int ListLength(DuLinkList L);//�жϱ�ĳ���
int GetElem(DuLinkList L,int i,ElemType *e);//���ص�i��Ԫ�ص�ֵ
//����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType));
int PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);//ǰ���ж�
int NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);//����ж�
DuLinkList GetElemP(DuLinkList L,int i);//���ص�i��Ԫ�صĵ�ַ
int ListInsert(DuLinkList L,int i,ElemType e);//�ڱ�ĵ�i��λ��֮ǰ����Ԫ��e
int ListDelete(DuLinkList L,ElemType *e);//ɾ�����е�i��Ԫ��
void ListTraverse(DuLinkList L,void(*visit)(ElemType));//�����ÿ��Ԫ�ص��ú���visit()
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));//�����ÿ��Ԫ�ص��ú���visit()

*/


//----------------------------------------------------˫��ѭ������ʵ��----------------------------------------------

// ˫��ѭ������ʵ��----ħ��ʦ��������

// Ҫ���û�����һ������ʹ��26����ĸ�����з����仯�������û�����3��������Ϊ��

// DEFGHIJKLMNOPQRSTUVWXYZABC

// ���û����븺���������û�����-3��������Ϊ��

// XYZABCDEFGHIJKLMNOPQRSTUVW

#if 1
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct _DualNode
{
	ElemType data;   // ��������
	struct  _DualNode *next;   // ���ָ��
	struct  _DualNode *prior;   // ǰ��ָ��
}DualNode,*DuaLinkList;

// ��ʼ������
void InitDualNode(DuaLinkList *pHead)
{
	DuaLinkList p, pNew;
	*pHead = new DualNode;

	if (NULL == (*pHead))
	{
		return ;
	}
	(*pHead)->next = (*pHead)->prior = NULL;
	p = *pHead;
	int i;
	for (i = 0; i < 26; i++)
	{
		 pNew = new DualNode;
		if (NULL==pNew)
		{
			return ;
		}
		pNew->data = 'A' + i;
		pNew->prior = p;
		pNew->next = p->next;
		p->next = pNew;

		p = pNew;
	}
	DuaLinkList temp = *pHead;
	p->next = temp->next;
	temp->next->prior = p;
	*pHead = temp->next;
	delete temp;
	temp = NULL;
}

// ����ĸ����
void Sort(DuaLinkList *pHead,int i)
{

	if (i>0)
	{
		do
		{
			*pHead = (*pHead)->next;
			--i;
		} while (i);
	}

	if (i<0)
	{
		do
		{
			*pHead = (*pHead)->prior;
			++i;
		} while (i);
	}
}

int main(void)
{
	DuaLinkList L = NULL;
	InitDualNode(&L);

	int num = 0;
	cout << "������һ������" << endl;
	cin >> num;
	Sort(&L, num);

	for (int i = 0; i < 26; i++)
	{
		cout << L->data << ",";
		L = L->next;
	}
	cout << "\b;" << endl;
	return 0;
}





#endif
