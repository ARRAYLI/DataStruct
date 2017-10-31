#if 0
#include<iostream>
using namespace std;

// 数据类型结构体

typedef int ElemType;

// 双向循环链表结构体

typedef struct _DualNode
{
	ElemType data;   // 存储的数据类型
	struct  _DualNode *prior;   // 指向结点的前驱
	struct  _DualNode *next;   // 指向结点的后继
}DualNode, *DuaLinkList;

// 初始化头节点

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

// 获取链表的长度

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

// 判读链表是否为空

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

// 返回第i个元素的值

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

// 销毁头节点函数

void DestroyHeadDNode(DuaLinkList *pHead)
{
	delete *pHead;
	*pHead = NULL;

}

// 头插法建表

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

// 尾插法建表

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

// 双向链表按下标插入元素

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

// 返回第i个元素的地址

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

// 正向显示函数

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

// 逆向显示函数

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

// 双向链表的冒泡排序

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

// 头删函数

void DeleteHeadDuaLinkList(DuaLinkList *pHead)
{
	if ((*pHead)->next != *pHead || (*pHead)->prior != *pHead)    //  判断是否只剩下一个头节点
	{
		DuaLinkList  temp = (*pHead)->next;   // 用临时变量来标记头结点后的第一个节点；
		(*pHead)->next = temp->next;    // 头节点指向删除后的第一个结点
		temp->next->prior = (*pHead);   // 删除后链表的第一个结点的前驱指针指向头节点；
		delete temp;
		temp = NULL;
	}
}

// 尾删函数

void DelTailDualLinkList(DuaLinkList *pHead)
{
	if ((*pHead)->next != *pHead || *pHead != (*pHead)->prior)   //  判断是否只剩下一个头节点
	{
		DuaLinkList temp = (*pHead)->prior;          // 用临时变量来标记头结点所指向的倒数第一个节点；
		
		temp->prior->next=(*pHead);   // 链表中的倒数第一个结点指向头节点；
		(*pHead)->prior = temp->prior;   // 头节点的前驱指针指向倒数第二结点；

		delete temp;     // 释放倒数第一个结点的内存；
		temp= NULL;   
	}
}

// 删除双向链表中第 i 个元素

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
		DuaLinkList temp = nPos;   // 用临时变量记住所要删除的元素

		nPos->prior->next = temp->next;   // 所要删除元素的前一个结点指向删除元素的后继元素
		temp->next->prior = nPos->prior;    // 删除元素的后继元素的前驱指向删除元素的前驱结点
		delete temp;
		temp = NULL;
	}

}

// 清空双向链表（保留头节点）

void ClearDuaLinkList(DuaLinkList *pHead)
{
	DuaLinkList nPos = *pHead;
	while (nPos->next != *pHead || *pHead != nPos->prior)
	{
		DelTailDualLinkList(pHead);
	}
}

// 销毁双向链表（包含销毁头节点）

void DestoryDuaLinkList(DuaLinkList *pHead)
{
	if (*pHead!=(*pHead)->next||*pHead!=(*pHead)->prior)
	{
		ClearDuaLinkList(pHead);
	}
	DestroyHeadDNode(pHead);
}



// 测试程序

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
//函数声明
void InitList(DuLinkList *L);//初始化链表
void ClearList(DuLinkList L);//清空表
void DestroyList(DuLinkList &L);//销毁双向链表
int ListEmpty(DuLinkList L);//判断表是否为空
int ListLength(DuLinkList L);//判断表的长度
int GetElem(DuLinkList L,int i,ElemType *e);//返回第i个元素的值
//返回L中第1个与e满足关系compare()的数据元素的位序
int LocateElem(DuLinkList L,ElemType e,int(*compare)(ElemType,ElemType));
int PriorElem(DuLinkList L,ElemType cur_e,ElemType *pre_e);//前驱判断
int NextElem(DuLinkList L,ElemType cur_e,ElemType *next_e);//后继判断
DuLinkList GetElemP(DuLinkList L,int i);//返回第i个元素的地址
int ListInsert(DuLinkList L,int i,ElemType e);//在表的第i个位置之前插入元素e
int ListDelete(DuLinkList L,ElemType *e);//删除表中第i个元素
void ListTraverse(DuLinkList L,void(*visit)(ElemType));//正序对每个元素调用函数visit()
void ListTraverseBack(DuLinkList L,void(*visit)(ElemType));//逆序对每个元素调用函数visit()

*/


//----------------------------------------------------双向循环链表实践----------------------------------------------

// 双向循环链表实践----魔术师发牌问题

// 要求用户输入一个数，使得26个字母的排列发生变化，例如用户输入3，输出结果为：

// DEFGHIJKLMNOPQRSTUVWXYZABC

// 若用户输入负数，例如用户输入-3，输出结果为：

// XYZABCDEFGHIJKLMNOPQRSTUVW

#if 1
#include<iostream>
using namespace std;

typedef char ElemType;
typedef struct _DualNode
{
	ElemType data;   // 数据类型
	struct  _DualNode *next;   // 后继指针
	struct  _DualNode *prior;   // 前驱指针
}DualNode,*DuaLinkList;

// 初始化函数
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

// 给字母排序
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
	cout << "请输入一整数：" << endl;
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
