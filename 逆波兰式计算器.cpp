// �������ʵ��

/*

#include<iostream>
using namespace std;

typedef struct _Node
{
	int data;
	struct _Node *next;
}Node,*PNode;

//  ͷ�巨����

void InsertByHead(PNode *pHead,int val)
{
	PNode pNew = new Node;
	if (pNew==NULL)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}
	pNew->data = val;
	pNew->next = *pHead;
	*pHead = pNew;
}

// β�巨����

void InsertByTail(PNode *pHead,int val)
{
	if (NULL==*pHead)
	{
		InsertByHead(pHead,val);
	}
	else
	{
		PNode pNew = new Node;
		if (NULL==pNew)
		{
			cout << "��̬�����ڴ�ʧ��!" << endl;
			return;
		}
		else
		{
			pNew->data = val;
			pNew->next = NULL;

			PNode nPos = *pHead;
			while (NULL!=nPos->next)
			{
				nPos = nPos->next;
			}

			nPos->next = pNew;
		}

	}
}

// βɾ

void DeleteByTail(PNode *pHead)
{
	PNode nPos = *pHead;
	
	while (nPos->next->next!=NULL)
	{
		nPos = nPos->next;
	}
	delete nPos->next;
	nPos->next = NULL;
}

// ͷɾ

void DeleteByHead(PNode *pHead)
{
	if (*pHead==NULL)
	{
		return;
	}
	else
	{
		PNode nPos = (*pHead)->next;
		delete *pHead;
		*pHead = NULL;
		*pHead = nPos;
	}
}

// ��������

void DestoryLinkList(PNode *pHead)
{
	while (*pHead!=NULL)
	{
		DeleteByHead(pHead);
	}
}

// ��ȡ������

int GetLength(PNode pHead)
{
	int count = 0;
	while (pHead!=NULL)
	{
		count++;
		pHead = pHead->next;
	}
	return count;
}

// ���±������

void InsertByIndex(PNode *pHead,int val,int index)
{

	if (0==index)
	{
		InsertByHead(pHead,val);
	}
	else if (index<=GetLength(*pHead))
	{
		PNode nPos = *pHead;
		PNode pNew = new Node;
		if (NULL == pNew)
		{
			return;
		}

		pNew->data = val;
		pNew->next = NULL;

		while (index<GetLength(*pHead))
		{
			nPos = nPos->next;
		}
		pNew->next = nPos->next;
		nPos->next = pNew;
	}
	else
	{
		InsertByTail(pHead,val);
	}
}

// ��ʾ

void Show(PNode pHead)
{
	PNode nPos = pHead;
	while (NULL!=nPos)
	{
		cout << nPos->data<<" ";
		nPos = nPos->next;
	}
	cout << endl;
}

int main(void)
{
	PNode pHead = NULL;
	InsertByHead(&pHead,1);
	InsertByHead(&pHead, 2);
	InsertByHead(&pHead, 3);
	Show(pHead);

	cout << GetLength(pHead) << endl;

	InsertByTail(&pHead,4);
	InsertByTail(&pHead, 5);
	InsertByTail(&pHead, 6);
//	Show(pHead);
//	DeleteByHead(&pHead);
	Show(pHead);
//	DeleteByTail(&pHead);
	Show(pHead);

	InsertByIndex(&pHead,9,0);
	InsertByIndex(&pHead, 6, 10);
	InsertByIndex(&pHead, 0, 7);

	Show(pHead);








	DestoryLinkList(&pHead);
	Show(pHead);
	cout << GetLength(pHead) << endl;
	int i = 0;
	return 0;
}

*/

// �沨��ʽ������

/*

#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

#define LEN 100
// ����ջ�ṹ��

typedef struct _Stack
{
	double data;  // ������
	struct _Stack*next;   // ָ����

}*MyStack,Node;

// ����ѹջ
void Push(MyStack *s,double val)
{
	MyStack pNew = new Node;
	if (NULL==pNew)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
	}

	pNew->data = val;
	pNew->next = NULL;
	pNew->next = *s;
	*s = pNew;
}

// ���ݳ�ջ

void Pop(MyStack *s,double *e)
{
	if (*s==NULL)
	{
		cout << "ջ�ѿ�" << endl;
		exit(0);
	}

	*e = (*s)->data;
	MyStack nPos = (*s);
	*s = nPos->next;

	delete nPos;
	nPos = NULL;
}

// ����ջ

void DestoryStack(MyStack *s)
{
	MyStack nPos = *s;
	while (nPos!=NULL)
	{
		MyStack temp = nPos;
		nPos = temp->next;
		delete temp;
		temp = NULL;
	}
}

// ��ʾջ�е�����

void Show(MyStack s)
{
	while (s!=NULL)
	{
		double e = 0;
		Pop(&s,&e);
		cout << e << endl;
	}
}


// ������������

void Calc(void)
{
	MyStack s = NULL;
	char Operator[LEN] = "";
	char c;
	double a, b;

	cout << "�������沨�����ʽ�������Կո������������'#'������" << endl;
	c = getchar();
	while (c != '#')    // ������#����
	{
		int i = 0;
		// �������ݲ������ݽ���ѹջ
		while (isdigit(c) || c == '.')
		{
			Operator[i++] = c;
			Operator[i] = '\0';
			if (i >= 10)
			{
				cout << "����ĵ�������̫��!" << endl;
				return ;
			}
			c = getchar();
			if (c == ' ')
			{
				double t = atof(Operator);
				Push(&s, t);
				i = 0;
				memset(Operator,0,strlen(Operator));
			}
		
		}

		// ���в�����ƥ��

		switch (c)
		{
		case '+':
			Pop(&s,&a);
			Pop(&s, &b);
			Push(&s,a+b);
			break;
		case '-':
			Pop(&s, &a);
			Pop(&s, &b);
			Push(&s, b-a);
			break;
		case '*':
			Pop(&s, &a);
			Pop(&s, &b);
			Push(&s, a * b);
			break;
		case '/':
			Pop(&s, &a);
			Pop(&s, &b);
			if (b==0)
			{
				cout << "��������Ϊ�㣡" << endl;
				return;
			}
			else
				Push(&s, b/ a);
			break;
		default:
			break;
		}
		c = getchar();
	}
	cout << "��������:" << endl;
	Pop(&s, &a);
	cout << a << endl;
}

int main(void)
{

	Calc();
	return 0;
}


// �������          5-(6+7)*8+9/4
// �沨�����ʽ      5  6  7 + 8 * - 9 4 / + #

*/




//  ��׺���ʽת��׺���ʽ������

/*

// #include<iostream>
// using namespace std;

#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE  50

typedef char ElemType;
typedef struct
{
	ElemType *base;
	ElemType *top;
	int stackszie;
}sqstack;

void InitStack(sqstack *s)
{
	s->base = (ElemType*) malloc(sizeof(sqstack)*STACK_INIT_SIZE);
	if (!s->base)
		exit(0);

	s->top = s->base;
	s->stackszie = STACK_INIT_SIZE;
}

void Push(sqstack *s,ElemType e)
{
	// ջ����׷�ӿռ�
	if (s->top-s->base>=s->stackszie)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackszie + STACK_INIT_SIZE) * sizeof(ElemType));
		if (!s->base)
		{
			exit(0);
		}
		s->top = s->base + s->stackszie;
		s->stackszie = s->stackszie + STACK_INIT_SIZE;
	}
	*(s->top) = e;  // �������
	s->top++;
}

void Pop(sqstack *s, ElemType *e)
{
	if (s->base == s->top)
		return;

	*e = *--(s->top);   // ��ջ��ָ�뵯�����޸�ջ��ָ��
}

int StackLen(sqstack s)
{
	return s.top - s.base;
}


void Calc(void)
{
	sqstack s;
	char c, e;

	InitStack(&s);
	printf("��������׺���ʽ����#��Ϊ������־��\n");
	scanf("%c", c);

	while (c != '#')
	{
		if (c >= '0'&&c <= '9')
		{
			printf("%c", c);
		}

		else if (')' == c)
		{
			Pop(&s, &e);
			while ('(' != e)
			{
				printf("%c", e);
				Pop(&s, &e);
			}
		}
		else if ('+' == c || '-' == c)
		{
			if (!StackLen(s))
			{
				Push(&s, c);
			}
			else
			{
				do
				{
					Pop(&s, &e);
					if ('(' == e)
					{
						Push(&s, e);
					}
					else
					{
						printf("%c", e);
					}
				} while (StackLen(s) && '(' != e);
				Push(&s, c);
			}
		}
		else if ('*' == c || '/' == c || '(' == c)
		{
			Push(&s, c);
		}
		else
		{
			printf("\n");
		}
		scanf("%c", c);
	}
}

int main(void)

*/




/*

#include<iostream>
using namespace std;
#define LEN 100

// ����ջ
typedef struct _op
{
	char data; // ���ţ�
	struct _op *next;
}opp,*Op;

// ����ջ
typedef struct _num
{
	double data;  // ������
	struct _num*next;
}num,*pNum;

// ����ջʵ��

void Push(Op *op,char c)
{
	Op pNew = new opp;
	if (NULL==op)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}

	pNew->data = c;
	pNew->next = *op;
	*op = pNew;
}

void Pop(Op *op,char *e)
{
	if (NULL==*op)
	{
		cout << "ջ�ѿ�!" << endl;
		return;
	}

	Op nPos =*op;
	nPos = nPos->next;
	*op = nPos;
	delete nPos;
	nPos = NULL;

}


// ����ջʵ��

void Push(pNum *s,double e)
{
	pNum pNew = new num;
	if (NULL==pNew)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}

	pNew->data = e;
	pNew->next = *s;
	*s = pNew;
}


void Pop(pNum *s,double *e)
{
	if (NULL!=*e)
	{
		cout << "ջ�ѿ�!" << endl;
		return;
	}

	pNum nPos = *s;
	nPos = nPos->next;
	*s = nPos;
	delete nPos;
	nPos = NULL;
}

void Calc(void)
{
	// ��������ջ
	Op oppe = NULL;
	
	// ��������ջ
	pNum s = NULL;
	char c;
	char str[LEN] = "";

	while (c!='#')
	{
		int i = 0;
		while (isdigit(c)||c=='.')
		{
			str[i++] = c;
			str[i] = '\0';
			c = getchar();
		}












	}


}


int main(void)
{
	Calc();
	return 0;
}

*/

