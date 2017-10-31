//	=====================================================栈的实现==========================================================

//	静态顺序栈的实现

#if 0
#include<iostream>
using namespace std;

#define MAXSIZE  20

// 定义顺序栈的数据存储结构

typedef struct SeqStack
{
	int	elem[MAXSIZE];
	int top;
}SeqStack;

// 初始化顺序栈

void InitSeqStack(SeqStack *s)
{
	s->top = 0;
}

// 判断顺序栈是否为空

bool isEmpty(SeqStack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}

// 判断顺序栈是否为满

bool isFull(SeqStack s)
{
	if (s.top >= MAXSIZE)
		return true;
	else
		return false;
}

// 数据压栈

bool PushSeqStack(SeqStack *s,int val)
{
	if (isFull(*s))
		return false;
	s->elem[s->top] = val;
	s->top++;
	return true;
}

// 数据出栈

bool PopSeqStack(SeqStack *s,int *e)
{
	if (isEmpty(*s))
		return false;
	*e=s->elem[s->top-1];
	s->top--;
	return true;
}

// 获取栈顶元素

bool GetSeqStackTop(SeqStack s,int *e)
{
	if (isEmpty(s))
		return false;
	*e = s.elem[s.top-1];
	return true;
}

// 清空栈
void ClearSeqStack(SeqStack *s)
{
	if (!isEmpty)
	{
		for (int i = 0; i < s->top; i++)
			s->elem[i] = 0;
	}
}

// 测试函数

void test(void)
{
	SeqStack s;
	int i;
	InitSeqStack(&s);
	for (i = 0; i < 10; i++)
	{
		int	val;
		cin >> val;
		PushSeqStack(&s,val);
	}

	int top = 0;
	GetSeqStackTop(s,&top);
	cout << "栈顶元素是：" << top << endl;

	for (i = 0; i< 10; i++)
	{
		int t = 0;
		PopSeqStack(&s, &t);
		cout << t << "  ";
	}
	cout << endl;
}

// 递归计算阶乘

int Fac(int n)
{
	if (1 == n)
		return 1;
	else
		return n*Fac(n - 1);
}

// 汉诺塔

void move(char A,int n,char C)
{
	static int i = 0;
	cout << "第"<<i+1<<"次移动：     "<<A << "----->" << C << endl;
	i++;
}

void hanio(int n,char A, char B,char  C)
{
	if (n == 1)
		move(A,1,C);				//	将编号为1的盘子从A柱子移动到C柱子上
	else
	{
		hanio(n-1,A,C,B);			//  将n-1个盘子借助C柱子移动到B柱子上
		move(A,n,C);				// 将第n个盘子借助B柱子移动到C柱子上
		hanio(n-1,B,A,C);					// 将n-1个盘子借助B
	}
}

void test1(void)
{
	char a,b ,c ;
	int n = 0;				// 盘子个数
	cin >> n;
	a = 'A';
	b = 'B';
	c = 'C';
	hanio(n,a,b,c);
}

int main(void)
{
//	test();
//	cout << Fac(5) << endl;
	test1();
	return 0;
}

#endif

// 链栈的实现

#if 0
#include<iostream>
using namespace std;

// 链栈的数据存结构的定义

typedef struct _StackNode
{
	int data;
	struct _StackNode*next;
}StackNode,*Stack;

// 初始化链栈

void InitStack(Stack* s)
{
	*s = new StackNode;
	if (NULL == *s)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}

	(*s)->next = NULL;
	(*s)->data = 0;
}

// 数据压栈

void PushStack(Stack *s,int val)
{
	StackNode* pNew = new StackNode;
	Stack nPos = *s;

	if (NULL==pNew)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}
	pNew->data = val;
	pNew->next = nPos->next;
	(*s)->next = pNew;
}

// 数据出栈

void PopStack(Stack *s,int *e)
{
	Stack nPos = (*s)->next;
	if (nPos != NULL)
	{
		*e = nPos->data;
		(*s)->next = nPos->next;
		delete nPos;
		nPos = NULL;
	}
	else
		return;
}

// 判断栈是否为空

bool isEmpty(Stack s)
{
	if (s->next != NULL)
		return true;
	else
		return false;
}

// 获取栈的栈顶元素

bool GetStackTop(Stack s,int *e)
{
	if (s->next != NULL)
	{
		*e = s->next->data;
		return true;
	}
	else
		return false;
}

// 销毁栈

void DestroyStack(Stack *s)
{
	Stack nPos = *s;

	while (nPos!=NULL)
	{
		Stack t = nPos;
		nPos = t->next;
		delete t;
		t = NULL;
	}
}

// 测试函数

void test()
{
	StackNode *s = NULL;
	InitStack(&s);
	for (int i = 0; i < 10; i++)
	{
		int t = 0;
		cin >> t;
		PushStack(&s,t);
	}

	int top = 0;
	
	PopStack(&s,&top);
	cout << "出栈后的元素是:" <<top <<endl;
	GetStackTop(s,&top);
	cout << "栈顶元素是： "<<top << endl;
	bool res = isEmpty(s);
	if (res)
		cout << "栈不为空!" << endl;
	else
		cout << "栈为空！" << endl;

	DestroyStack(&s);
}

int main(void)
{
	test();
	return 0;
}
#endif

//	=====================================================栈的实现==========================================================



//	=====================================================队列的实现========================================================== 


//	循环队列的实现
#if 0
#include<iostream>
using namespace std;

#define MAXSIZE 20

// 定义顺序队列的数据存储结构

typedef struct
{
	int elem[MAXSIZE];		//	数组用来存放入队列的数值
	int front;				//	对头指针
	int rear;				//队尾指针
}SeQueue;

// 初始化队列

void InitSeQueue(SeQueue *q)
{
	q->front = 0;
	q->rear = q->front;
}

// 元素入对列 

bool EnterQueue(SeQueue *q, int val)
{
	if (q->front == (q->rear + 1) % MAXSIZE)			// 队列已满
	{
		cout << "对列已满!" << endl;
		return false;
	}

	q->elem[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	return true;
}

// 元素出都列

bool DelQueue(SeQueue *q, int *e)
{
	if (q->front == q->rear)
	{
		cout << "队列为空!" << endl;
		return false;
	}
	*e = q->elem[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return true;
}

// 判断栈是否为空

bool isEmpty(SeQueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}

//	获取对头元素

bool GetTop(SeQueue q, int *e)
{
	if (isEmpty(q))
		return false;
	*e = q.elem[q.front];
	return true;
}

// 测试函数

void test()
{
	int val;
	int i = 0;
	SeQueue q;
	InitSeQueue(&q);

	for (i = 0; i<10; i++)
	{
		cin >> val;
		EnterQueue(&q, val);
	}

	int top = 0;
	GetTop(q, &top);
	cout << "栈顶元素是：  " << top << endl;

	for (i = 0; i<10; i++)
	{
		DelQueue(&q, &top);
		cout << top << "  ";
	}
	cout << endl;

	bool res = isEmpty(q);
	if (res)
		cout << "队列为空!" << endl;
	else
		cout << "队列不为空!" << endl;
}

int main(void)
{
	test();
	return 0;
}
#endif


// 链队列
#if 0
#include<iostream>
using namespace std;

// 数据接结点定义

typedef struct _Node
{
	int data;					// 数据域
	struct _Node *next;			//	指针域
}QNode;

// 定义链队列的数据存储结构

typedef struct _Queue
{
	QNode *front;
	QNode *rear;

}LinkQueue;

// 初始化链队列

void InitQueue(LinkQueue *q)
{
	q->front = new QNode;
	if (NULL == q->front)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}
	q->rear = q->front;
	q->front->next = NULL;
}

// 判断队列是否为空

bool isEmpty(LinkQueue *q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}

// 元素入队列

void PushQueue(LinkQueue *q, int *e)
{
	QNode *pNew = new QNode;
	if (NULL == pNew)
	{
		cout << "动态省内存失败！" << endl;
		return;
	}
	else
	{
		pNew->data = *e;
		pNew->next = NULL;
		q->rear->next = pNew;
		q->rear = pNew;
	}
}

//	元素出队列 

void PopQueue(LinkQueue *q, int *e)
{
	if (isEmpty(q))
	{
		cout << "队列为空!" << endl;
		return;
	}

	QNode *p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	delete p;
	p = NULL;
}

// 获取队列对头元素

bool GetQueueTop(LinkQueue *q, int *e)
{
	if (isEmpty(q))
		return false;
	*e = q->front->next->data;
	return true;
}

// 销毁链队列

void DestoryQueue(LinkQueue *q)
{
	while (q->front != NULL)
	{
		q->rear = q->front->next;			//	令队尾指针指向对头的第一个元素
		delete q->front;
		q->front = NULL;
		q->front = q->rear;					// 第一次是头节点，以后是元素结点
	}
	//	q = NULL;
}

// 测试函数

void test()
{
	LinkQueue q;
	InitQueue(&q);
	bool res;
	res = isEmpty(&q);
	if (res)
		cout << "队列为空!" << endl;
	else
		cout << "队列不为空!" << endl;

	for (int i = 0; i < 10; i++)
	{
		int e = i + 1;
		PushQueue(&q, &e);
	}

	res = isEmpty(&q);
	if (res)
		cout << "队列为空!" << endl;
	else
		cout << "队列不为空!" << endl;

	int top = GetQueueTop(&q, &top);
	cout << "对头元素是：" << top << endl;
	for (int i = 0; i<9; i++)
	{
		int e = 0;
		PopQueue(&q, &e);
		cout << e << "  ";
	}
	cout << endl;
	DestoryQueue(&q);
}

int main(void)
{
	test();
	return 0;
}
#endif

/*
	两个栈实现队列的功能。（外部接口是队列）（重点）
*/

#if 0
#include<iostream>
#include<stack>
using namespace std;

//  数据存储结构

typedef struct
{
	int data;		// 数据域
	// 其他信息
}Node;

//	元素出队列

void PushQueue(stack<Node>& s,Node val)
{
	s.push(val);
}

// 元素出队列

void PopQueue(stack<Node>& s,stack<Node>& p, Node *val)
{
	Node temp;
	while (!s.empty())
	{
		temp = s.top();
		s.pop();
		p.push(temp);
	}
	if (!p.empty())
	{
		temp = p.top();
		p.pop();
		*val = temp;
	}
	else
		return;
}

void test()
{
	stack<Node>s; 
	stack<Node>p;
	Node temp;
	int t = 0;
	cin >> t;
	while (t!=-1)
	{
		temp.data =t;
		PushQueue(s, temp);
		cin >>t ;
	}

	cout << "出队列的顺序为:  " << endl;
	for (int i=0;i<10;i++)
	{
		PopQueue(s,p,&temp);
		cout << temp.data << "  ";
	}
	cout << endl;
}

int main(void)
{
	test();
	return 0;
}
#endif

/*
表达式求值
*/

#if 0
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// 计算
int Calculate(double a,char c, double b)
{
	int res = 0;
	switch (c)
	{
	case '+':
		res = b + a;
		break;
	case '-':
		res = b - a;
		break;
	case '*':
		res = b*a;
		break;
	case '/':
		res = b / a;
		if (0==a)
		{
			return -1;
		}
		break;
	default:
		break;
	}

	return res;
}

// 判断输入的数据是否是符号

bool In(char ch,char opSet[],int len)
{
	int i;
	for (i=0;opSet[i]!='\0'; i++)
	{
		if (opSet[i]==ch)
		{
			return true;
		}
	}
	return false;
}

// 判断当前运算符和运算符栈顶元素的大小

char Compare(char c1,char c2)
{
	if (c1 - c2 == 0)
		return '=';
	else if (c1 - c2 > 0)
		return '>';
	else
		return '<';
}

// 输入表达式

void test()
{
	stack<char> optr;		//	运算符栈
	stack<double> ovs;		//	运算数栈
	char str[20]="";
	char* ch;
	optr.push('#');
	char opSet[] = { '+','-','*','/','#','\0' };
	int len = sizeof(opSet) / sizeof(opSet[0]);
	int num1 = 0, num2 = 0,res=0;
	char op;
	cout << "请输入表达式，以#结束输入:    ";
	gets_s(str);
	ch = str;
	while (*ch!='#'||optr.top()!='#')
	{
		if (!In(*ch,opSet,len))			//	如果是运算数，则进符号栈ovs
		{
			double n = *ch - '0';
			ovs.push(n);
			ch++;
		//	cin >> ch;
		}
		else
		{
			switch (Compare(*ch,optr.top()))
			{
			case '>':
				optr.push(*ch);
				ch++;
				break;
			case '=':
			case '<':
				num1=ovs.top();
				ovs.pop();
				num2 = ovs.top();
				ovs.pop();
				op = optr.top();
				optr.pop();
				res= Calculate(num1,op,num2);
				ovs.push(res);
				break;
			default:
				break;
			}
		}
	}
	cout << "运算结果是："<<res << endl;
}

int main(void)
{
	test();
	// 1+2-3#
	return 0;
}
#endif

// 括号匹配

#if 0
#include<iostream>
using namespace std;

#define MAXSIZE  20

// 定义顺序栈的数据存储结构

typedef struct SeqStack
{
	char	elem[MAXSIZE];
	int top;
}SeqStack;

// 初始化顺序栈

void InitSeqStack(SeqStack *s)
{
	s->top = 0;
}

// 判断顺序栈是否为空

bool isEmpty(SeqStack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}

// 判断顺序栈是否为满

bool isFull(SeqStack s)
{
	if (s.top >= MAXSIZE)
		return true;
	else
		return false;
}

// 数据压栈

bool PushSeqStack(SeqStack *s, char val)
{
	if (isFull(*s))
		return false;
	s->elem[s->top] = val;
	s->top++;
	return true;
}

// 数据出栈

bool PopSeqStack(SeqStack *s, char *e)
{
	if (isEmpty(*s))
		return false;
	*e = s->elem[s->top - 1];
	s->top--;
	return true;
}

// 获取栈顶元素

bool GetSeqStackTop(SeqStack s, char *e)
{
	if (isEmpty(s))
		return false;
	*e = s.elem[s.top - 1];
	return true;
}

// 清空栈
void ClearSeqStack(SeqStack *s)
{
	if (!isEmpty(*s))
	{
		for (int i = 0; i < s->top; i++)
			s->elem[i] = '\0';
	}
}

// 进行括号匹配

bool Match(char ch,char str)
{
	if (ch == '('&&str == ')')
	{
		return true;
	}
	else if (ch == '['&&str == ']')
	{
		return true;
	}
	else if (ch == '{'&&str == '}')
	{
		return true;
	}
	else
		return false;
}

void BracketMatch(char *str)
{
	SeqStack s;
	InitSeqStack(&s);
	char ch;
	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			PushSeqStack(&s,str[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (isEmpty(s))
			{
				cout << "右括号多余！" << endl;
				return;
			}
			else
			{
				GetSeqStackTop(s,&ch);
				if (Match(ch, str[i]))				//	 使用Match判断两个括号是否匹配
					PopSeqStack(&s, &ch);			//   已匹配的括号出栈
				else
				{
					cout << "对应的左右括号不匹配！" << endl;
					return;
				}
			}
		}
	}
	if (isEmpty(s))
	{
		cout << "括号匹配!" << endl;
	}
	else
	{
		cout << "左括号多余!" << endl;
	}


}

int main(void)
{
	char str[100] = "";
	cout << "请输入： ";
	gets_s(str);
	BracketMatch(str);
	return 0;
}
#endif












#include <stdio.h>

#define MAXSIZE 50
#define N		7


typedef int QueueElementType;

typedef struct
{
	QueueElementType element[MAXSIZE];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue *Q)
{
	Q->front = Q->rear = 0;
}
void EnterQueue(SeqQueue *Q, QueueElementType x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		printf("队列已满不能入队\n");
		return;
	}
	Q->element[Q->rear] = x;
	Q->rear = (Q->rear + 1) % MAXSIZE;
}
void printQ(SeqQueue Q)
{
	int i;
	i = Q.front;
	while (i != Q.rear)
	{
		if (i == MAXSIZE)
		{
			i = 0;
		}
		printf(" %d ", Q.element[i]);
		i++;
	}
	printf("\n");
}

void DeleteQueue(SeqQueue *Q, QueueElementType *x)
{
	if (Q->front == Q->rear)
	{
		printf("队列为空不能出队\n");
		return;
	}
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}
void GetHead(SeqQueue *Q, QueueElementType *x)
{
	if (Q->front == Q->rear)
	{
		printf("队列为空不能取值\n");
		return;
	}
	*x = Q->element[Q->front];
}

 int main(void)
{
	SeqQueue Q;
	QueueElementType x, temp;
	int n;
	int i;
	InitQueue(&Q);

	EnterQueue(&Q, 1);//第一行元素入队
	for (n = 2; n <= N; n++)//产生第n行元素并入队，同时打印第n-1行的元素
	{
		EnterQueue(&Q, 1);//第n行的第一个元素入队
		for (i = 1; i <= n - 2; i++)//利用队中第n-1行元素产生第n行的中间n-2个元素并入队
		{
			DeleteQueue(&Q, &temp);
			printf(" %d ", temp);//打印第n-1行的元素
			GetHead(&Q, &x);
			temp = temp + x;//利用队中第n-1行元素产生第n行元素
			EnterQueue(&Q, temp);
		}
		DeleteQueue(&Q, &x);
		printf(" %d ", x);//打印第n-1行的最后一个元素
		EnterQueue(&Q, 1);//第n行的最后一个元素入队
		printf("\n");
	}
	while (Q.front != Q.rear)//打印最后一行元素
	{
		DeleteQueue(&Q, &x);
		printf(" %d ", x);
	}
	return 0;
}




//	=====================================================栈的实现==========================================================