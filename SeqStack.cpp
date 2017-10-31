//	=====================================================ջ��ʵ��==========================================================

//	��̬˳��ջ��ʵ��

#if 0
#include<iostream>
using namespace std;

#define MAXSIZE  20

// ����˳��ջ�����ݴ洢�ṹ

typedef struct SeqStack
{
	int	elem[MAXSIZE];
	int top;
}SeqStack;

// ��ʼ��˳��ջ

void InitSeqStack(SeqStack *s)
{
	s->top = 0;
}

// �ж�˳��ջ�Ƿ�Ϊ��

bool isEmpty(SeqStack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}

// �ж�˳��ջ�Ƿ�Ϊ��

bool isFull(SeqStack s)
{
	if (s.top >= MAXSIZE)
		return true;
	else
		return false;
}

// ����ѹջ

bool PushSeqStack(SeqStack *s,int val)
{
	if (isFull(*s))
		return false;
	s->elem[s->top] = val;
	s->top++;
	return true;
}

// ���ݳ�ջ

bool PopSeqStack(SeqStack *s,int *e)
{
	if (isEmpty(*s))
		return false;
	*e=s->elem[s->top-1];
	s->top--;
	return true;
}

// ��ȡջ��Ԫ��

bool GetSeqStackTop(SeqStack s,int *e)
{
	if (isEmpty(s))
		return false;
	*e = s.elem[s.top-1];
	return true;
}

// ���ջ
void ClearSeqStack(SeqStack *s)
{
	if (!isEmpty)
	{
		for (int i = 0; i < s->top; i++)
			s->elem[i] = 0;
	}
}

// ���Ժ���

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
	cout << "ջ��Ԫ���ǣ�" << top << endl;

	for (i = 0; i< 10; i++)
	{
		int t = 0;
		PopSeqStack(&s, &t);
		cout << t << "  ";
	}
	cout << endl;
}

// �ݹ����׳�

int Fac(int n)
{
	if (1 == n)
		return 1;
	else
		return n*Fac(n - 1);
}

// ��ŵ��

void move(char A,int n,char C)
{
	static int i = 0;
	cout << "��"<<i+1<<"���ƶ���     "<<A << "----->" << C << endl;
	i++;
}

void hanio(int n,char A, char B,char  C)
{
	if (n == 1)
		move(A,1,C);				//	�����Ϊ1�����Ӵ�A�����ƶ���C������
	else
	{
		hanio(n-1,A,C,B);			//  ��n-1�����ӽ���C�����ƶ���B������
		move(A,n,C);				// ����n�����ӽ���B�����ƶ���C������
		hanio(n-1,B,A,C);					// ��n-1�����ӽ���B
	}
}

void test1(void)
{
	char a,b ,c ;
	int n = 0;				// ���Ӹ���
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

// ��ջ��ʵ��

#if 0
#include<iostream>
using namespace std;

// ��ջ�����ݴ�ṹ�Ķ���

typedef struct _StackNode
{
	int data;
	struct _StackNode*next;
}StackNode,*Stack;

// ��ʼ����ջ

void InitStack(Stack* s)
{
	*s = new StackNode;
	if (NULL == *s)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}

	(*s)->next = NULL;
	(*s)->data = 0;
}

// ����ѹջ

void PushStack(Stack *s,int val)
{
	StackNode* pNew = new StackNode;
	Stack nPos = *s;

	if (NULL==pNew)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}
	pNew->data = val;
	pNew->next = nPos->next;
	(*s)->next = pNew;
}

// ���ݳ�ջ

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

// �ж�ջ�Ƿ�Ϊ��

bool isEmpty(Stack s)
{
	if (s->next != NULL)
		return true;
	else
		return false;
}

// ��ȡջ��ջ��Ԫ��

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

// ����ջ

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

// ���Ժ���

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
	cout << "��ջ���Ԫ����:" <<top <<endl;
	GetStackTop(s,&top);
	cout << "ջ��Ԫ���ǣ� "<<top << endl;
	bool res = isEmpty(s);
	if (res)
		cout << "ջ��Ϊ��!" << endl;
	else
		cout << "ջΪ�գ�" << endl;

	DestroyStack(&s);
}

int main(void)
{
	test();
	return 0;
}
#endif

//	=====================================================ջ��ʵ��==========================================================



//	=====================================================���е�ʵ��========================================================== 


//	ѭ�����е�ʵ��
#if 0
#include<iostream>
using namespace std;

#define MAXSIZE 20

// ����˳����е����ݴ洢�ṹ

typedef struct
{
	int elem[MAXSIZE];		//	���������������е���ֵ
	int front;				//	��ͷָ��
	int rear;				//��βָ��
}SeQueue;

// ��ʼ������

void InitSeQueue(SeQueue *q)
{
	q->front = 0;
	q->rear = q->front;
}

// Ԫ������� 

bool EnterQueue(SeQueue *q, int val)
{
	if (q->front == (q->rear + 1) % MAXSIZE)			// ��������
	{
		cout << "��������!" << endl;
		return false;
	}

	q->elem[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	return true;
}

// Ԫ�س�����

bool DelQueue(SeQueue *q, int *e)
{
	if (q->front == q->rear)
	{
		cout << "����Ϊ��!" << endl;
		return false;
	}
	*e = q->elem[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return true;
}

// �ж�ջ�Ƿ�Ϊ��

bool isEmpty(SeQueue q)
{
	if (q.front == q.rear)
		return true;
	else
		return false;
}

//	��ȡ��ͷԪ��

bool GetTop(SeQueue q, int *e)
{
	if (isEmpty(q))
		return false;
	*e = q.elem[q.front];
	return true;
}

// ���Ժ���

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
	cout << "ջ��Ԫ���ǣ�  " << top << endl;

	for (i = 0; i<10; i++)
	{
		DelQueue(&q, &top);
		cout << top << "  ";
	}
	cout << endl;

	bool res = isEmpty(q);
	if (res)
		cout << "����Ϊ��!" << endl;
	else
		cout << "���в�Ϊ��!" << endl;
}

int main(void)
{
	test();
	return 0;
}
#endif


// ������
#if 0
#include<iostream>
using namespace std;

// ���ݽӽ�㶨��

typedef struct _Node
{
	int data;					// ������
	struct _Node *next;			//	ָ����
}QNode;

// ���������е����ݴ洢�ṹ

typedef struct _Queue
{
	QNode *front;
	QNode *rear;

}LinkQueue;

// ��ʼ��������

void InitQueue(LinkQueue *q)
{
	q->front = new QNode;
	if (NULL == q->front)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}
	q->rear = q->front;
	q->front->next = NULL;
}

// �ж϶����Ƿ�Ϊ��

bool isEmpty(LinkQueue *q)
{
	if (q->front == q->rear)
		return true;
	else
		return false;
}

// Ԫ�������

void PushQueue(LinkQueue *q, int *e)
{
	QNode *pNew = new QNode;
	if (NULL == pNew)
	{
		cout << "��̬ʡ�ڴ�ʧ�ܣ�" << endl;
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

//	Ԫ�س����� 

void PopQueue(LinkQueue *q, int *e)
{
	if (isEmpty(q))
	{
		cout << "����Ϊ��!" << endl;
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

// ��ȡ���ж�ͷԪ��

bool GetQueueTop(LinkQueue *q, int *e)
{
	if (isEmpty(q))
		return false;
	*e = q->front->next->data;
	return true;
}

// ����������

void DestoryQueue(LinkQueue *q)
{
	while (q->front != NULL)
	{
		q->rear = q->front->next;			//	���βָ��ָ���ͷ�ĵ�һ��Ԫ��
		delete q->front;
		q->front = NULL;
		q->front = q->rear;					// ��һ����ͷ�ڵ㣬�Ժ���Ԫ�ؽ��
	}
	//	q = NULL;
}

// ���Ժ���

void test()
{
	LinkQueue q;
	InitQueue(&q);
	bool res;
	res = isEmpty(&q);
	if (res)
		cout << "����Ϊ��!" << endl;
	else
		cout << "���в�Ϊ��!" << endl;

	for (int i = 0; i < 10; i++)
	{
		int e = i + 1;
		PushQueue(&q, &e);
	}

	res = isEmpty(&q);
	if (res)
		cout << "����Ϊ��!" << endl;
	else
		cout << "���в�Ϊ��!" << endl;

	int top = GetQueueTop(&q, &top);
	cout << "��ͷԪ���ǣ�" << top << endl;
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
	����ջʵ�ֶ��еĹ��ܡ����ⲿ�ӿ��Ƕ��У����ص㣩
*/

#if 0
#include<iostream>
#include<stack>
using namespace std;

//  ���ݴ洢�ṹ

typedef struct
{
	int data;		// ������
	// ������Ϣ
}Node;

//	Ԫ�س�����

void PushQueue(stack<Node>& s,Node val)
{
	s.push(val);
}

// Ԫ�س�����

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

	cout << "�����е�˳��Ϊ:  " << endl;
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
���ʽ��ֵ
*/

#if 0
#include<iostream>
#include<stack>
#include<string>
using namespace std;

// ����
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

// �ж�����������Ƿ��Ƿ���

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

// �жϵ�ǰ������������ջ��Ԫ�صĴ�С

char Compare(char c1,char c2)
{
	if (c1 - c2 == 0)
		return '=';
	else if (c1 - c2 > 0)
		return '>';
	else
		return '<';
}

// ������ʽ

void test()
{
	stack<char> optr;		//	�����ջ
	stack<double> ovs;		//	������ջ
	char str[20]="";
	char* ch;
	optr.push('#');
	char opSet[] = { '+','-','*','/','#','\0' };
	int len = sizeof(opSet) / sizeof(opSet[0]);
	int num1 = 0, num2 = 0,res=0;
	char op;
	cout << "��������ʽ����#��������:    ";
	gets_s(str);
	ch = str;
	while (*ch!='#'||optr.top()!='#')
	{
		if (!In(*ch,opSet,len))			//	��������������������ջovs
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
	cout << "�������ǣ�"<<res << endl;
}

int main(void)
{
	test();
	// 1+2-3#
	return 0;
}
#endif

// ����ƥ��

#if 0
#include<iostream>
using namespace std;

#define MAXSIZE  20

// ����˳��ջ�����ݴ洢�ṹ

typedef struct SeqStack
{
	char	elem[MAXSIZE];
	int top;
}SeqStack;

// ��ʼ��˳��ջ

void InitSeqStack(SeqStack *s)
{
	s->top = 0;
}

// �ж�˳��ջ�Ƿ�Ϊ��

bool isEmpty(SeqStack s)
{
	if (s.top == 0)
		return true;
	else
		return false;
}

// �ж�˳��ջ�Ƿ�Ϊ��

bool isFull(SeqStack s)
{
	if (s.top >= MAXSIZE)
		return true;
	else
		return false;
}

// ����ѹջ

bool PushSeqStack(SeqStack *s, char val)
{
	if (isFull(*s))
		return false;
	s->elem[s->top] = val;
	s->top++;
	return true;
}

// ���ݳ�ջ

bool PopSeqStack(SeqStack *s, char *e)
{
	if (isEmpty(*s))
		return false;
	*e = s->elem[s->top - 1];
	s->top--;
	return true;
}

// ��ȡջ��Ԫ��

bool GetSeqStackTop(SeqStack s, char *e)
{
	if (isEmpty(s))
		return false;
	*e = s.elem[s.top - 1];
	return true;
}

// ���ջ
void ClearSeqStack(SeqStack *s)
{
	if (!isEmpty(*s))
	{
		for (int i = 0; i < s->top; i++)
			s->elem[i] = '\0';
	}
}

// ��������ƥ��

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
				cout << "�����Ŷ��࣡" << endl;
				return;
			}
			else
			{
				GetSeqStackTop(s,&ch);
				if (Match(ch, str[i]))				//	 ʹ��Match�ж����������Ƿ�ƥ��
					PopSeqStack(&s, &ch);			//   ��ƥ������ų�ջ
				else
				{
					cout << "��Ӧ���������Ų�ƥ�䣡" << endl;
					return;
				}
			}
		}
	}
	if (isEmpty(s))
	{
		cout << "����ƥ��!" << endl;
	}
	else
	{
		cout << "�����Ŷ���!" << endl;
	}


}

int main(void)
{
	char str[100] = "";
	cout << "�����룺 ";
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
		printf("���������������\n");
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
		printf("����Ϊ�ղ��ܳ���\n");
		return;
	}
	*x = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
}
void GetHead(SeqQueue *Q, QueueElementType *x)
{
	if (Q->front == Q->rear)
	{
		printf("����Ϊ�ղ���ȡֵ\n");
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

	EnterQueue(&Q, 1);//��һ��Ԫ�����
	for (n = 2; n <= N; n++)//������n��Ԫ�ز���ӣ�ͬʱ��ӡ��n-1�е�Ԫ��
	{
		EnterQueue(&Q, 1);//��n�еĵ�һ��Ԫ�����
		for (i = 1; i <= n - 2; i++)//���ö��е�n-1��Ԫ�ز�����n�е��м�n-2��Ԫ�ز����
		{
			DeleteQueue(&Q, &temp);
			printf(" %d ", temp);//��ӡ��n-1�е�Ԫ��
			GetHead(&Q, &x);
			temp = temp + x;//���ö��е�n-1��Ԫ�ز�����n��Ԫ��
			EnterQueue(&Q, temp);
		}
		DeleteQueue(&Q, &x);
		printf(" %d ", x);//��ӡ��n-1�е����һ��Ԫ��
		EnterQueue(&Q, 1);//��n�е����һ��Ԫ�����
		printf("\n");
	}
	while (Q.front != Q.rear)//��ӡ���һ��Ԫ��
	{
		DeleteQueue(&Q, &x);
		printf(" %d ", x);
	}
	return 0;
}




//	=====================================================ջ��ʵ��==========================================================