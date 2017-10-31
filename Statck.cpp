//----------------------------------------------------˳��ջ---------------------------------

#if 0
#include<iostream>
using namespace std;
#define Stack_Size 50

// �洢�������ͽṹ��

typedef int StackElement;

// ˳��ջ�ṹ��

typedef struct _Stack
{
	StackElement elem[Stack_Size]; // �������ջ��Ԫ�ص�һά����
	int top;  // �������ջ��Ԫ�ص��±ꣻ
}SeqStack;

// ˳��ջ��ʼ��

void InitStack(SeqStack *S)
{
	// ����һ����ջ��
	S->top = -1;
}

// ˳��ջ��ջ

// ��ջʱ������Ҫ�жϵ�ǰջ�Ƿ���������Ҫ��ջ�ͻᷢ������

bool Push(SeqStack *S,StackElement x)
{
	// ��x����Sջ��ջ��
	if (S->top == Stack_Size)
	{
		return false;
	}
	S->top++;
	S->elem[S->top] = x;
	return true;
}

// ˳��ջ��ջ

// ��ջʱ�������жϵ�ǰջ�Ƿ�Ϊ�գ����ջΪ�գ���Ҫ��ջ�Ļ��ͻᷢ������

bool Pop(SeqStack *S,StackElement *x)
{
	if (S->top==-1)
	{
		return false;
	}
	else
	{
		*x = S->elem[S->top];
		S->top--;
		return true;
	}

}

// ��ջ��Ԫ��

// ˳��ջ��ջ��Ԫ��

bool GetTop(SeqStack *S,StackElement *x)
{
	// ��ջSջ��Ԫ�ض��������뵽x��ָ�Ĵ洢�ռ��У�ջ��ָ�뱣�ֲ��䣻
	
	if (S->top==-1)   // ջΪ��
	{
		return false;
	}
	else
	{
		*x = S->elem[S->top];
		return true;
	}
}

int main(void)
{
	SeqStack s;
	
	InitStack(&s);
	for (int i = 0; i < 10; i++)
	{
		bool flag;
		flag=Push(&s,i+1);
		if (!flag)
		{
			break;
		}
	}

	int temp = 0;
	int flag=GetTop(&s,&temp);
	if (flag)
	{
		cout << temp << endl;
	}
	flag=Pop(&s,&temp);
	while (flag)
	{
		cout << temp <<"   ";
		flag = Pop(&s, &temp);
	}
	cout << endl;

	int x = 0;
	flag = GetTop(&s, &x);
	if (flag)
	{
		cout << temp << endl;
	}
	else
	{
		cout << "ջ����Ԫ�أ���" << endl;
	}
	return 0;
}

#endif


//----------------------------------------------------˫��˳��ջ--------------------------------

#if 0
#include<iostream>
using namespace std;
#define M  100

// ������洢����������

typedef int StackElemnet;

// ˫��ջ�ṹ��

typedef struct
{
	StackElemnet elem[M];  // Stack[M]Ϊջ��
	StackElemnet top[2]; // top[0]��top[1]�ֱ�Ϊ����ջ��ָʾ����
}DqStack;

// ˫��˳��ջ��ʼ��

void InitStack(DqStack *Dq)
{
	Dq->top[0] = -1;
	Dq->top[1] = M;
}

// ˫��˳��ջ��ջ������

bool Push(DqStack *Dq, StackElemnet x,int i)
{
	// ������Ԫ��xѹ��i�Ŷѣ�
	if (Dq->top[0]==Dq->top[1])   // ջ����
	{
		return false;
	}

	switch (i)
	{
	case 0:         // 0������
		Dq->top[0]++;
		Dq->elem[Dq->top[0]] = x;
		break;
	case 1:
		Dq->top[1]--;
		Dq->elem[Dq->top[1]] = x;
		break;
	default:
		return false;
	}
	return true;
}


// ˫��˳��ջ��ջ����

bool Pop(DqStack *Dq, StackElemnet *x, int i)
{
	switch (i)
	{
	case 0:               // 0��ջ��ջ
		if (Dq->top[0] == -1)   // �ж�00��ջ�Ƿ�Ϊ��ջ
		{
			return false;
		}
		*x=Dq->elem[Dq->top[0]];
		Dq->top[0]--;
		break;
	case 1:     // 1��ջ��ջ
		if (Dq->top[1] == M)   // �ж�1��ջ�Ƿ�Ϊ��
		{
			return false;
		}
		*x=Dq->elem[Dq->top[1]];
		Dq->top[1]++;
		break;
	default:
		return false;
	}

	return true;
}


int main(void)
{
	DqStack Dq;
	StackElemnet temp = 0;
	bool flag;
	int i, j;

// ��ʼ��˫��˳��ջ
	InitStack(&Dq);

// 0��ջԪ�ؽ�ջ

	for (i = 0; i < 5; i++)    // 0��ջ��Ԫ�ؽ�ջ
	{
		flag = Push(&Dq,i+1,0);
		if (!flag)
		{
			cout << "0��ջ����" << endl;
			break;
		}
	}

// 1��ջ��Ԫ�ؽ�ջ
	for (j = 6; j < 10; j++)
	{
		flag = Push(&Dq, j + 1, 1);
		if (!flag)
		{
			cout << "1��ջ����" << endl;
			break;
		}
	}

// 0��ջ��Ԫ�س�ջ
	cout << "------------- 0��ջԪ�س�ջ-------------------" << endl;
	for (i = 0; Dq.top[0]!=-1; i++)
	{
		bool f=Pop(&Dq,&temp,0);
		if (!f)
		{
			cout << "0��ջΪ�գ�" << endl;
			break;
		}
		cout << temp<<" ";
	}

	cout << endl;
	cout << "------------- 1��ջԪ�س�ջ-------------------" << endl;

// 1��Ԫ�س�ջ
	for (j = 0; Dq.top[1] != M; j++)
	{
		bool ff = Pop(&Dq, &temp, 1);
		if (!ff)
		{
			cout << "1��ջΪ�գ�" << endl;
			break;
		}
		cout << temp << " ";
	}
	cout << endl;
	return 0;
}

#endif


//----------------------------------------------------��ջ----------------------------------

#if 0
#include<iostream>
using namespace std;

// ��ջ������洢����

typedef int LinkListStackElemType;

// ��ջ�ṹ��

typedef struct _LinkListStack
{
	LinkListStackElemType data;   // ������
	struct _LinkListStack *next; // ָ����

}LinkListStackNode,*LinkListStack;

// ��ʼ����ջ

void InitLinkListStack(LinkListStack *Ls)
{
	// ��ͷ��������ڴ�ռ�
	*Ls = new LinkListStackNode;
	(*Ls)->data = 0;
	(*Ls)->next = NULL;
}

// ���ջ

void  ClearStack(LinkListStack *Ls)
{
	LinkListStack nPos = *Ls;
	while (NULL != nPos->next)
	{
		LinkListStack temp = (*Ls)->next;
		if (NULL != temp)
		{
			nPos->next = temp->next;
			delete temp;
			temp = NULL;
		}
	}
}

// �ж�ջ�Ƿ�Ϊ��ջ

bool IsEmptyStack(LinkListStack Ls)
{
	LinkListStack nPos = Ls->next;
	int count = 0;
	while (nPos!= NULL)
	{
		nPos = nPos->next;
		count++;
	}

	if (0 == count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ���ջ��Ԫ��

LinkListStackElemType GetTop(LinkListStack Ls)
{
	LinkListStack nPos = Ls->next;
	if (nPos != NULL)
	{
		return  nPos->data;
	}
	else
	{
		return -1;
	}
}

// ��ջ��ջ
void Push(LinkListStack *Ls, LinkListStackElemType value)
{
	// ������Ԫ��valueѹ��top��

	LinkListStack pNew = new LinkListStackNode;
	
	if (NULL==pNew)  // �����ڴ�ʧ��
	{
		return ;
	}

	pNew->data = value;
	pNew->next = (*Ls)->next;   // ���´�����pNew��ָ��ָ��Ls->next;  �൱ͷ���
	(*Ls)->next = pNew;   // �޸�ջ����ǰָ��
	
}

// ��ջ��ջ

LinkListStackElemType Pop(LinkListStack* Ls)
{
	// ��ջLs��ջ��Ԫ�ص������ŵ�x��ָ�Ĵ洢�ռ��У�
	LinkListStack nPos = *Ls;

   // �ж���ջ�Ƿ�Ϊ��
	if (IsEmptyStack(*Ls))
	{
		return -1;
	}
	else
	{
		LinkListStack nPos = (*Ls)->next;
		LinkListStackElemType temp;
		if (nPos==NULL)
		{
			(*Ls)->next = NULL;
			 temp= nPos->data;
			delete nPos;
			nPos = NULL;
		}
		else
		{
			temp=nPos->data;
			(*Ls)->next = nPos->next;
			delete nPos;
			nPos = NULL;
		}

		return temp;
	}

}

// ����ջ

void DestoryStack(LinkListStack *Ls)
{
	if (!IsEmptyStack(*Ls))
	{
		ClearStack(Ls);
	}
		delete *Ls;
		*Ls = NULL;
}

int main(void)
{
	LinkListStack Ls=NULL;
	InitLinkListStack(&Ls);

	// ѹ��ջ
	LinkListStackElemType len = 0;
	cout << "������Ҫ��ջ��Ԫ�ظ�����" << endl;
	cin >> len;
	cout << "������ѹ��ջ��Ԫ�أ�" << endl;
	for (int i = 0; i < len; i++)
	{
		LinkListStackElemType temp = 0;
		cin >> temp;
	     Push(&Ls,temp);
	}

	// 	��ȡջ��Ԫ��
	cout << "ջ��Ԫ��Ϊ��" << GetTop(Ls) << endl;
	// ��ջ
	for (int j = 0; Ls->next != NULL; j++)
	{
		LinkListStackElemType temp=Pop(&Ls);
		cout << temp << "   ";
	}
	cout << endl;
	DestoryStack(&Ls);
	return 0;
}

#endif

//----------------------------------------------------��ջ����----------------------------------

#if 0
#include<iostream>
using namespace std;

#define M 10  // M����ջ

#define  StackElementType int


// ��ջ�ṹ��

typedef struct _Node
{
	StackElementType data;   // ������
	struct _Node *next;   // ָ����
}LinkStackNodde,*LinkStack;

LinkStack top[M];

// ��ʼ����ջ

void InitLinkListSatck(LinkStack top[M],int len)
{
	for (int i = 0; i < len; i++)
	{
		top[i] = new LinkStackNodde;
//		LinkStack pHead = new LinkStackNodde;
		if (NULL== top[i])
		{
			return;
		}
		top[i]->data = 0;
		top[i]->next = NULL;
	}
}

// ��i ��ջ��ջ����

void Push(LinkStack top[M], int i, StackElementType x)
{
	// ��Ԫ��x�����i��ջ
	LinkStack pNew = new LinkStackNodde;
	if (NULL==pNew)
	{
		return;
	}
	pNew->data = x;

	pNew->next = top[i]->next;
	
	top[i]->next = pNew; // �޸ĵ�ǰָ�룻

}

// ��i��ջ��ջ����

StackElementType LinkListPop(LinkStack top[M], int i)
{
	LinkStack temp = top[i]->next;
	if (temp==NULL)
	{
		return -1;
	}
	top[i]->next = temp->next;
	StackElementType t = temp->data;
	delete temp;
	temp = NULL;
	return t;
}

// �жϵ�����ջ�Ƿ�Ϊ��

bool IsEmpty(LinkStack pHead)
{
	if (pHead->next!= NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ���ٵ�����ջ

void DestorySimpleStackLinkst(LinkStack *pHead)
{
	LinkStack nPos;
	nPos = (*pHead)->next;
	while (nPos!=NULL)
	{
		(*pHead)->next = nPos->next;
		delete nPos;
		nPos = NULL;
		nPos = (*pHead)->next;
	}
	if (nPos==NULL)
	{
		delete *pHead;
		*pHead = NULL;
	}
}


// ����������ջ

void DestoryLinkListStack(LinkStack *top,int len)
{
	for (int i = 0; i < len; i++)
	{
		DestorySimpleStackLinkst(&top[i]);
	}
}

// ���Գ���
void test()
{
	int count = 0;  // �����ջ�ĸ���
	int num =0;     // ���ÿ����ջ�е�Ԫ�ظ���
	int i,j;

// ջ��ջ

	cout << "������Ҫʹ�õ���ջ�ĸ�����" << endl;
	cin >> count;
	if (count>M||count<=0)
	{
		cout << "���������д���" << endl;
		return;
	}

	for (i = 0; i < count; i++)   // ��ջ����
	{
		cout << "�������" <<i+1<<"��ջ��Ԫ�ظ�����"<< endl;
		cin >> num;
		cout << "����������"<<i+1<<"��ջ������Ԫ�أ�"<< endl;
		for (j = 0; j < num; j++)   // ��ջ��i��ջ��Ԫ��
		{
			StackElementType tp;
			cin >> tp;
			Push(top, i, tp);
		}
	}

	// ��ջ

	for (i = 0; i <count; i++)
	{
		cout << "��"<<i+1<<"��ջ��ջ�������Ԫ��Ϊ��" << endl;
		for (int j=0;IsEmpty(top[i]); j++)
		{
			StackElementType temp = LinkListPop(top,i);
			cout << temp <<"    ";
		}
		cout << endl;
	}
	DestoryLinkListStack(top, M);
}


int main(void)
{
	InitLinkListSatck(top,M);
	int i;
	test();
	return 0;
}
#endif



#if 0
// ��ӡ��һ������

#include<iostream>
using namespace std;
void diomand(int r)
{
	for (int x=0; x <= 2 * r; x++)
	{
		for (int y=0; y <= 2 * r; y++)
		{
			if (y==x+r||y==x-r||y==-x+r||y==-x+3*r)
			{
				printf("*");

			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

// ����һ �ֲ���ӡ
void rhombus(int len)
{
	int i, j, k;
//	int m = len / 2+1;   // ��¼ǰlen/2+1�У�   
 // ��ӡ��ǰlen/2+1��
	for (i = 0; i <=len / 2 + 1; i++)
	{
		// ����Ƶ�ÿ�п�ʼ����� ����λ��
		for (j = 0; j < len / 2 + 1 - i; j++)
		{
			cout<<" ";
		}

		// ��ʼ�����*��
		for (k = 0; k < 2 * i + 1; k++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

// ��ӡ����len/2-1��
	for (i = len/2;i>=0; i--)
	{
		// ����Ƶ�ÿ�п�ʼ����� ����λ��
		for (j = 0; j <=len / 2 - i; j++)
		{
			cout << " ";
		}

		// ��ʼ�����*��
		for (k = 0; k < 2 * i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// ��������
void rhombus1(int len)
{

	for (int i=0; i <len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i+j<=2||(j-i>=4||i-j>=4)||i+j>=10)
			{

				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

// ��������
void rhombus2(int len)
{
	for (int i = 0; i <len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i + j <= len/2-1 || (j - i >= len/2+1 || i - j >= len/2+1) || i + j >=len+len/2)
			{

				cout << " ";
			}
			else
			{
				cout << "*";
			}
		}
		cout << endl;
	}
}

int main(void)
{
	int r = 0;
	int m = 0;
	cin >> r;

//	rhombus2(r);
	
//		diomand(r);
//	rhombus(r);
//	rhombus1(r);
//	cin >> m;
	rhombus2(r);
	return 0;
}
#endif

//----------------------------------------------------ջ��Ӧ��----------------------------------

// ����ƥ������

#if  0
#include<iostream>
using namespace std;

// ջ������洢��������

typedef char StackElemType;

//  ջ�ṹ��

typedef struct _Stack
{
	StackElemType data;  // ������
	struct  _Stack *next;   // ָ����  
}StackNode,*LinkStack;

// ��ʼ��ջ

void InitStack(LinkStack *Ls)
{
	*Ls = new StackNode;
	if (NULL==*Ls)
	{
		return;
	}
	//(*Ls)->data = -1;
	(*Ls)->next = NULL;
}

// �ж�ջ�Ƿ�Ϊ��

bool IsEmpty(LinkStack Ls)
{
	if (NULL==Ls->next)
	{
		return true;
	}
	return false;
}

// Ԫ��ѹ��ջ

void Push(LinkStack *Ls,StackElemType x)
{
	LinkStack pNew = new StackNode;
	if (NULL==pNew)
	{
		return;
	}
	pNew->data = x;

	pNew->next = (*Ls)->next;

	(*Ls)->next = pNew;
}

// ��ջԪ��

StackElemType  Pop(LinkStack *Ls)
{
	StackElemType temp = -1;
	if (IsEmpty(*Ls))
	{
		return temp;
	}
	else
	{
		LinkStack nPos = (*Ls)->next;

		(*Ls)->next = nPos->next;

		temp = nPos->data;
		delete nPos;
		nPos = NULL;
		return temp;
	}
}

// ��ȡջ��Ԫ��

StackElemType GetTop(LinkStack Ls)
{
	if (IsEmpty(Ls))
	{
		return -1;

	}
	else
	{
		return Ls->next->data;
	}
}

// ������ջ

void DestoryLinkStack(LinkStack *Ls)
{

	while (!IsEmpty(*Ls))
	{
		LinkStack temp = (*Ls)->next;

		(*Ls)->next = temp->next;

		delete temp;
		temp = NULL;
	}

	if (IsEmpty(*Ls))
	{
		delete *Ls;
		*Ls = NULL;
	}
}
#endif

//-----------------------------------------------����ƥ������--------------------------------------------------

#if 0
// �ж����ַ��Ƿ�ƥ��

bool Match(char rec,char dest)
{
	if (rec==dest)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// ����ƥ���㷨

void BrackketMatch(char *str)
{
	//  str[]��Ϊ������ַ��������ö�ջ�����������ַ����е������Ƿ�ƥ��

	LinkStack  S = NULL;
	int i;
	char ch;
	InitStack(&S);

	for (i = 0; str[i] != '\0'; i++)
	{

		switch (str[i])
		{
		case '(':
		case '[':
		case '{':
			Push(&S, str[i]);
			break;
		case ')':
		case ']':
		case '}':
			if (IsEmpty(S))
			{
				cout << "\n�����Ŷ��࣡" << endl;
				return;
			}
			else
			{
				ch = GetTop(S);
				if (Match(ch, str[i]))   // Match�ж����������Ƿ�ƥ��
				{
					StackElemType temp = Pop(&S);   //  ��ƥ��������ų�ս
				}
				else
				{
					cout << "\n��Ӧ���������Ų�ƥ�䣡" << endl;
				}

			}
			break;
		default:
			break;
		}


	}

	if (IsEmpty(S))
	{
		cout << "����ƥ�䣡" << endl;
	}
	else
	{
		cout << "�����Ŷ��࣡" << endl;
	}
	DestoryLinkStack(&S);
}

int main1(void)
{
	char str[100] = "";
	cout << "���������ţ�" << endl;
	cin >> str;
	BrackketMatch(str);
	return 0;
}

#endif


//-----------------------------------------------���ʽ��ֵ-----------------------------------------------------

#if 0
// �ж�������ǲ��������ǲ�����

bool In(char dest,char *rec)
{
	switch (dest)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
		return true;
	default:
		return false;
	}
}



























// �������������ʽ�����㷨

int ExpEvaluatioin()
{
	// ����һ�����������ʽ��������ֵ��OPTR��OVS�ֱ�Ϊ�����ջ��������ջ��OPSetΪ���������
    
	LinkStack OPTR = NULL;    // �����ջ
	LinkStack OVS = NULL;   // ������ջ
	char OPSet[] = { '+','-','*','/','%'};
	char ch;  // �Ӽ��̶������ݻ��������

	InitStack(&OPTR);
	InitStack(&OVS);

	Push(&OPTR, '#');  // Ϊ�˱��ڲ��������Ƚ�# ѹ��OPTRջ
	cout << "������һ�����ʽ(�á�#������)��" << endl;

	ch = getchar();

	while (ch != '#' || GetTop(OPTR) != '#')
	{
		if (!In(ch,OPSet))   // ���ǲ��������ǲ���������OVSջ
		{
			int n;
			n = GetNumber(ch);
			Push(&OVS,n);

		}






		








	}














}


int main(void)
{




	return 0;
}
#endif


// ջ�����Դ洢Ӧ��

// ����ջʵ�ֶ����Ƶ�ʮ���ƣ��˽��ƣ�ʮ������֮���ת��

#if 0
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define STACK_INIT_SIZE 5
#define STACKINCREMENT  10
typedef char ElemntType;
typedef struct _SqStack
{
	ElemntType *base; // ջ��ָ��
	ElemntType *top;  // ջ��ָ�룻
	int stackSize;  // ջ����
}SqStack;

// ��ʼ��ջ

void InitSqStack(SqStack *Sq)
{
	Sq->base = new ElemntType[STACK_INIT_SIZE];
	if (!Sq->base)
	{
		return ;
	}
	Sq->top = Sq->base;
	Sq->stackSize = STACK_INIT_SIZE;
}

// ѹջ
void Push(SqStack *Sq,ElemntType x)
{
	if (Sq->top-Sq->base>=Sq->stackSize)
	{
		Sq->base = new ElemntType[STACKINCREMENT];
		if (!Sq->base)
		{
			return;
		}
	}
	*Sq->top = x;
	Sq->top++;
    //  10110
	//  101011
}

// ��ջ

ElemntType Pop(SqStack *Sq)
{
	if (Sq->top==Sq->base)
	{
		return -1;
	}
	return *--Sq->top;
}

// ջ����

int SqStackLength(SqStack Sq)
{
	return Sq.top - Sq.base;
}

// ������ת��Ϊʮ���Ʋ��Գ���

// ����ջ

void DestorySqStack(SqStack *Sq)
{
	delete Sq->base;
	Sq->base= NULL;
}

void BinaryToDec(SqStack *Binary,int len)
{
	int i, sum = 0;

	for (int i = 0; i < len; i++)
	{
		ElemntType temp = Pop(Binary);
		sum += (temp - 48)*pow(2, i);
	}
	getchar();
	cout << "ջ�ĵ�ǰ�����ǣ�" << len << endl;
	cout << "�������ת��Ϊʮ������Ϊ��" << sum << endl;

	for (i = 0; i < len; i++)
	{
		Binary->top++;
	}

}

// ������ת��Ϊ�˽��Ʋ��Գ���

void BinaryToOct(SqStack *Binary,SqStack *Oct, int len)
{
	
	int i;
	ElemntType temp = '0';
	int sum = 0;
	for (int i = 1; i <= len / 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			temp = Pop(Binary);
			sum += (temp - 48)*pow(2, j);
		}

		Push(Oct, '0' + sum);
		temp = '0';
		sum = 0;
	}

	if (len % 3 != 0)
	{
		for (int j = 0; j < len % 3; j++)
		{
			temp = Pop(Binary);
			sum += (temp - 48)*pow(2, j);
		//	Binary->top++;
		}
		Push(Oct, '0' + sum);
	}
	
	getchar();
	cout << "������ջ�ĵ�ǰ�����ǣ�" << len << endl;


	int len1 = SqStackLength(*Oct);

	cout << "�˽���ջ�ĵ�ǰ�����ǣ�" << len1<< endl;
	cout << "�������ת��Ϊ�˽�����Ϊ��";
	for (int i = 0; i < len1; i++)
	{
		cout << Pop(Oct);
	}
	cout << endl;
	for (i = 0; i < len; i++)
	{
		Binary->top++;
	}
//	DestorySqStack(&s);
//	DestorySqStack(&m);
	// 11001001#
}

// ������ת��Ϊʮ�����ƽ��Ʋ��Գ���

void BinaryToHex(SqStack *Binary,SqStack *Dec, int len)
{
	ElemntType c;
	int i;
	ElemntType temp = '0';
	int sum = 0;

	for (int i = 1; i <= len / 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{

			temp = Pop(Binary);
			sum += (temp - 48)*pow(2, j);
		}
		if (sum>=10&&sum<=15)
		{
			sum -= 10;
			Push(Dec, 'A' + sum);
		}
		else
		{
			Push(Dec, '0' + sum);
		}
		
		temp = '0';
		sum = 0;
	}

	if (len % 4 != 0)
	{
		for (int j = 0; j < len % 4; j++)
		{
			temp = Pop(Binary);
			sum += (temp - 48)*pow(2, j);
		}
		Push(Dec, '0' + sum);
	}

	getchar();
	cout << "������ջ�ĵ�ǰ�����ǣ�" << len << endl;


	int len1 = SqStackLength(*Dec);

	cout << "ʮ������ջ�ĵ�ǰ�����ǣ�" << len1 << endl;
	cout << "�������ת��Ϊʮ��������Ϊ��";

	for (int i = 0; i < len1; i++)
	{
		cout << Pop(Dec);
	}
	cout << endl;

}

int main(void)
{
	SqStack b;  // ��Ŷ��������ݣ�
	SqStack o;  // ��Ű˽������ݣ�
	SqStack h; // ���ʮ���������ݣ�
	InitSqStack(&b);
	InitSqStack(&o);
	InitSqStack(&h);
	ElemntType c;
	int i, len;
	ElemntType temp = '0';
	int sum = 0;
	cout << "�������������������#���ű�ʾ������" << endl;
	cin >> c;
	while (c != '#')
	{
		Push(&b, c);
		cin >> c;
	}
	len = SqStackLength(b);
	BinaryToDec(&b,len);

	BinaryToOct(&b,&o,len);

	BinaryToHex(&b,&h,len);
	
	
	DestorySqStack(&b);

	DestorySqStack(&o);
	DestorySqStack(&h);
	return 0;
}

#endif



//-------------------------------------------------�ݹ�����--------------------------------------------

#if 0
#include<iostream>
using namespace std;

int i = 1;
// ��ŵ��
void move(int n, char x, char z)
{
	cout << "��"<<n<<"�����Ӵ�: " << x << " ---> " << z <<"��������" << endl;
}

void hanoi(int n, char x, char y, char z)
{
	// ������x�ϴ��ϵ��±��Ϊ1��n���Ұ�ֱ����С������ŵ�n��ԭ�̣�������ᵽ����z�ϣ�y����������

	if (1==n)
	{
		move(1,x,z);
	}
	else
	{
		hanoi(n - 1, x,z,y);   // �Ƚ�n-1�����ӽ�������z�ƶ�������y��
		move(n,x,z);  // ��ʣ�µ����һ��n�����ƶ�������z��
		hanoi(n - 1, y, x, z); // ��ʣ�µ�n-1�����ӽ������� x�ƶ���z�ϣ�
	}
}

// �Ʋ���������

int Fib(int n)
{
	if (0==n||1==n)
	{
		return n;   // �ݹ���ó���
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);    // �ݹ����
	}

}

int main(void)
{
	char x, y, z;
	x = 'A', y = 'B', z = 'C';
	cout << "������Ҫ�ƶ������Ӹ�����" << endl;
	int count;
	cin >> count;
	hanoi(count,x,y,z);

	for (int i = 1; i <=count; i++)
		cout << Fib(i) << "  ";
	cout << endl;

	return 0;
}

#endif






// wc����

#if 0
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(void)
{

	char c;

	int cnt_char = 0;
	int cnt_word = 0;
	int cnt_line = 0;
	int flag = 0;
	while ((c = getchar())!= EOF)
	{
		cnt_char++;

		if ('\n' == c)
		{
			cnt_line++;
		}

		if (!isspace(c) && flag == 0)
		{
			cnt_word++;
			flag = 1;

		}

		if (isspace(c))
		{
			flag = 0;


			//  printf("%c %d\n",c,flag);
		}

	}

	printf("char =%d,word=%d,line=%d\n", cnt_char, cnt_word, cnt_line);

	return 0;
}

#endif




