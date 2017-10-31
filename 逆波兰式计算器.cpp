// 单链表的实现

/*

#include<iostream>
using namespace std;

typedef struct _Node
{
	int data;
	struct _Node *next;
}Node,*PNode;

//  头插法建表

void InsertByHead(PNode *pHead,int val)
{
	PNode pNew = new Node;
	if (pNew==NULL)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}
	pNew->data = val;
	pNew->next = *pHead;
	*pHead = pNew;
}

// 尾插法建表

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
			cout << "动态分配内存失败!" << endl;
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

// 尾删

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

// 头删

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

// 销毁链表

void DestoryLinkList(PNode *pHead)
{
	while (*pHead!=NULL)
	{
		DeleteByHead(pHead);
	}
}

// 获取链表长度

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

// 按下标插入结点

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

// 显示

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

// 逆波兰式计算器

/*

#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

#define LEN 100
// 定义栈结构体

typedef struct _Stack
{
	double data;  // 数据域
	struct _Stack*next;   // 指针域

}*MyStack,Node;

// 数据压栈
void Push(MyStack *s,double val)
{
	MyStack pNew = new Node;
	if (NULL==pNew)
	{
		cout << "动态申请内存失败!" << endl;
	}

	pNew->data = val;
	pNew->next = NULL;
	pNew->next = *s;
	*s = pNew;
}

// 数据出栈

void Pop(MyStack *s,double *e)
{
	if (*s==NULL)
	{
		cout << "栈已空" << endl;
		exit(0);
	}

	*e = (*s)->data;
	MyStack nPos = (*s);
	*s = nPos->next;

	delete nPos;
	nPos = NULL;
}

// 销毁栈

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

// 显示栈中的数据

void Show(MyStack s)
{
	while (s!=NULL)
	{
		double e = 0;
		Pop(&s,&e);
		cout << e << endl;
	}
}


// 计算器处理函数

void Calc(void)
{
	MyStack s = NULL;
	char Operator[LEN] = "";
	char c;
	double a, b;

	cout << "请输入逆波兰表达式，数字以空格结束，输入以'#'结束：" << endl;
	c = getchar();
	while (c != '#')    // 输入以#结束
	{
		int i = 0;
		// 输入数据并对数据进行压栈
		while (isdigit(c) || c == '.')
		{
			Operator[i++] = c;
			Operator[i] = '\0';
			if (i >= 10)
			{
				cout << "输入的单个数据太大!" << endl;
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

		// 进行操作符匹配

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
				cout << "除数不能为零！" << endl;
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
	cout << "计算结果是:" << endl;
	Pop(&s, &a);
	cout << a << endl;
}

int main(void)
{

	Calc();
	return 0;
}


// 例如计算          5-(6+7)*8+9/4
// 逆波兰表达式      5  6  7 + 8 * - 9 4 / + #

*/




//  中缀表达式转后缀表达式计算器

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
	// 栈满，追加空间
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
	*(s->top) = e;  // 存放数据
	s->top++;
}

void Pop(sqstack *s, ElemType *e)
{
	if (s->base == s->top)
		return;

	*e = *--(s->top);   // 将栈顶指针弹出并修改栈顶指针
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
	printf("请输入中缀表达式，以#作为阶数标志：\n");
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

// 符号栈
typedef struct _op
{
	char data; // 符号；
	struct _op *next;
}opp,*Op;

// 数字栈
typedef struct _num
{
	double data;  // 数据域
	struct _num*next;
}num,*pNum;

// 符号栈实现

void Push(Op *op,char c)
{
	Op pNew = new opp;
	if (NULL==op)
	{
		cout << "动态申请内存失败!" << endl;
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
		cout << "栈已空!" << endl;
		return;
	}

	Op nPos =*op;
	nPos = nPos->next;
	*op = nPos;
	delete nPos;
	nPos = NULL;

}


// 数字栈实现

void Push(pNum *s,double e)
{
	pNum pNew = new num;
	if (NULL==pNew)
	{
		cout << "动态申请内存失败!" << endl;
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
		cout << "栈已空!" << endl;
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
	// 创建符号栈
	Op oppe = NULL;
	
	// 创建数字栈
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

