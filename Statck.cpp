//----------------------------------------------------顺序栈---------------------------------

#if 0
#include<iostream>
using namespace std;
#define Stack_Size 50

// 存储数据类型结构体

typedef int StackElement;

// 顺序栈结构体

typedef struct _Stack
{
	StackElement elem[Stack_Size]; // 用来存放栈中元素的一维数组
	int top;  // 用来存放栈顶元素的下标；
}SeqStack;

// 顺序栈初始化

void InitStack(SeqStack *S)
{
	// 构造一个空栈；
	S->top = -1;
}

// 顺序栈进栈

// 进栈时，首先要判断当前栈是否已满，还要进栈就会发生上溢

bool Push(SeqStack *S,StackElement x)
{
	// 将x置入S栈新栈顶
	if (S->top == Stack_Size)
	{
		return false;
	}
	S->top++;
	S->elem[S->top] = x;
	return true;
}

// 顺序栈出栈

// 出栈时，首先判断当前栈是否为空，如果栈为空，还要出栈的话就会发生下溢

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

// 读栈顶元素

// 顺序栈读栈顶元素

bool GetTop(SeqStack *S,StackElement *x)
{
	// 将栈S栈顶元素读出，放入到x所指的存储空间中，栈顶指针保持不变；
	
	if (S->top==-1)   // 栈为空
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
		cout << "栈中无元素！！" << endl;
	}
	return 0;
}

#endif


//----------------------------------------------------双端顺序栈--------------------------------

#if 0
#include<iostream>
using namespace std;
#define M  100

// 数据域存储的数据类型

typedef int StackElemnet;

// 双端栈结构体

typedef struct
{
	StackElemnet elem[M];  // Stack[M]为栈区
	StackElemnet top[2]; // top[0]和top[1]分别为两个栈顶指示器；
}DqStack;

// 双端顺序栈初始化

void InitStack(DqStack *Dq)
{
	Dq->top[0] = -1;
	Dq->top[1] = M;
}

// 双端顺序栈进栈操作；

bool Push(DqStack *Dq, StackElemnet x,int i)
{
	// 把数据元素x压入i号堆；
	if (Dq->top[0]==Dq->top[1])   // 栈已满
	{
		return false;
	}

	switch (i)
	{
	case 0:         // 0号已满
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


// 双端顺序栈出栈操作

bool Pop(DqStack *Dq, StackElemnet *x, int i)
{
	switch (i)
	{
	case 0:               // 0号栈出栈
		if (Dq->top[0] == -1)   // 判断00号栈是否为空栈
		{
			return false;
		}
		*x=Dq->elem[Dq->top[0]];
		Dq->top[0]--;
		break;
	case 1:     // 1号栈出栈
		if (Dq->top[1] == M)   // 判断1号栈是否为空
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

// 初始化双端顺序栈
	InitStack(&Dq);

// 0号栈元素进栈

	for (i = 0; i < 5; i++)    // 0号栈，元素进栈
	{
		flag = Push(&Dq,i+1,0);
		if (!flag)
		{
			cout << "0号栈已满" << endl;
			break;
		}
	}

// 1号栈，元素进栈
	for (j = 6; j < 10; j++)
	{
		flag = Push(&Dq, j + 1, 1);
		if (!flag)
		{
			cout << "1号栈已满" << endl;
			break;
		}
	}

// 0号栈，元素出栈
	cout << "------------- 0号栈元素出栈-------------------" << endl;
	for (i = 0; Dq.top[0]!=-1; i++)
	{
		bool f=Pop(&Dq,&temp,0);
		if (!f)
		{
			cout << "0号栈为空！" << endl;
			break;
		}
		cout << temp<<" ";
	}

	cout << endl;
	cout << "------------- 1号栈元素出栈-------------------" << endl;

// 1号元素出栈
	for (j = 0; Dq.top[1] != M; j++)
	{
		bool ff = Pop(&Dq, &temp, 1);
		if (!ff)
		{
			cout << "1号栈为空！" << endl;
			break;
		}
		cout << temp << " ";
	}
	cout << endl;
	return 0;
}

#endif


//----------------------------------------------------链栈----------------------------------

#if 0
#include<iostream>
using namespace std;

// 链栈数据域存储类型

typedef int LinkListStackElemType;

// 链栈结构体

typedef struct _LinkListStack
{
	LinkListStackElemType data;   // 数据域；
	struct _LinkListStack *next; // 指针域

}LinkListStackNode,*LinkListStack;

// 初始化链栈

void InitLinkListStack(LinkListStack *Ls)
{
	// 给头结点申请内存空间
	*Ls = new LinkListStackNode;
	(*Ls)->data = 0;
	(*Ls)->next = NULL;
}

// 清空栈

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

// 判断栈是否为空栈

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

// 获得栈顶元素

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

// 链栈进栈
void Push(LinkListStack *Ls, LinkListStackElemType value)
{
	// 将数据元素value压入top中

	LinkListStack pNew = new LinkListStackNode;
	
	if (NULL==pNew)  // 申请内存失败
	{
		return ;
	}

	pNew->data = value;
	pNew->next = (*Ls)->next;   // 将新创建的pNew的指针指向Ls->next;  相当头差法；
	(*Ls)->next = pNew;   // 修改栈顶当前指针
	
}

// 链栈出栈

LinkListStackElemType Pop(LinkListStack* Ls)
{
	// 将栈Ls的栈顶元素弹出，放到x所指的存储空间中；
	LinkListStack nPos = *Ls;

   // 判断链栈是否为空
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

// 销毁栈

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

	// 压入栈
	LinkListStackElemType len = 0;
	cout << "请输入要入栈的元素个数：" << endl;
	cin >> len;
	cout << "请输入压入栈的元素：" << endl;
	for (int i = 0; i < len; i++)
	{
		LinkListStackElemType temp = 0;
		cin >> temp;
	     Push(&Ls,temp);
	}

	// 	获取栈顶元素
	cout << "栈顶元素为：" << GetTop(Ls) << endl;
	// 出栈
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

//----------------------------------------------------多栈运算----------------------------------

#if 0
#include<iostream>
using namespace std;

#define M 10  // M个链栈

#define  StackElementType int


// 链栈结构体

typedef struct _Node
{
	StackElementType data;   // 数据域
	struct _Node *next;   // 指针域
}LinkStackNodde,*LinkStack;

LinkStack top[M];

// 初始化链栈

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

// 第i 号栈进栈操作

void Push(LinkStack top[M], int i, StackElementType x)
{
	// 将元素x进入第i号栈
	LinkStack pNew = new LinkStackNodde;
	if (NULL==pNew)
	{
		return;
	}
	pNew->data = x;

	pNew->next = top[i]->next;
	
	top[i]->next = pNew; // 修改当前指针；

}

// 第i号栈出栈操作

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

// 判断单个链栈是否为空

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

// 销毁单个链栈

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


// 销毁所有链栈

void DestoryLinkListStack(LinkStack *top,int len)
{
	for (int i = 0; i < len; i++)
	{
		DestorySimpleStackLinkst(&top[i]);
	}
}

// 测试程序
void test()
{
	int count = 0;  // 存放链栈的个数
	int num =0;     // 存放每个链栈中的元素个数
	int i,j;

// 栈入栈

	cout << "请输入要使用的链栈的个数：" << endl;
	cin >> count;
	if (count>M||count<=0)
	{
		cout << "您的输入有错误！" << endl;
		return;
	}

	for (i = 0; i < count; i++)   // 链栈个数
	{
		cout << "请输入第" <<i+1<<"号栈的元素个数："<< endl;
		cin >> num;
		cout << "请输入进入第"<<i+1<<"号栈的数据元素："<< endl;
		for (j = 0; j < num; j++)   // 入栈第i个栈的元素
		{
			StackElementType tp;
			cin >> tp;
			Push(top, i, tp);
		}
	}

	// 出栈

	for (i = 0; i <count; i++)
	{
		cout << "第"<<i+1<<"号栈出栈后的数据元素为：" << endl;
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
// 打印出一个菱形

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

// 方法一 分步打印
void rhombus(int len)
{
	int i, j, k;
//	int m = len / 2+1;   // 记录前len/2+1行；   
 // 打印出前len/2+1行
	for (i = 0; i <=len / 2 + 1; i++)
	{
		// 光标移到每行开始输出“ ”的位置
		for (j = 0; j < len / 2 + 1 - i; j++)
		{
			cout<<" ";
		}

		// 开始输出“*”
		for (k = 0; k < 2 * i + 1; k++)
		{
			cout<<"*";
		}
		cout<<endl;
	}

// 打印出后len/2-1行
	for (i = len/2;i>=0; i--)
	{
		// 光标移到每行开始输出“ ”的位置
		for (j = 0; j <=len / 2 - i; j++)
		{
			cout << " ";
		}

		// 开始输出“*”
		for (k = 0; k < 2 * i + 1; k++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

// 方法二：
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

// 方法三：
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

//----------------------------------------------------栈的应用----------------------------------

// 括号匹配问题

#if  0
#include<iostream>
using namespace std;

// 栈数据域存储数据类型

typedef char StackElemType;

//  栈结构体

typedef struct _Stack
{
	StackElemType data;  // 数据域
	struct  _Stack *next;   // 指针域  
}StackNode,*LinkStack;

// 初始化栈

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

// 判断栈是否为空

bool IsEmpty(LinkStack Ls)
{
	if (NULL==Ls->next)
	{
		return true;
	}
	return false;
}

// 元素压入栈

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

// 出栈元素

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

// 获取栈顶元素

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

// 销毁链栈

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

//-----------------------------------------------括号匹配问题--------------------------------------------------

#if 0
// 判断两字符是否匹配

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

// 括号匹配算法

void BrackketMatch(char *str)
{
	//  str[]中为输入的字符串，利用堆栈技术来检查该字符串中的括号是否匹配

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
				cout << "\n右括号多余！" << endl;
				return;
			}
			else
			{
				ch = GetTop(S);
				if (Match(ch, str[i]))   // Match判断两个括号是否匹配
				{
					StackElemType temp = Pop(&S);   //  已匹配的左括号出战
				}
				else
				{
					cout << "\n对应的左右括号不匹配！" << endl;
				}

			}
			break;
		default:
			break;
		}


	}

	if (IsEmpty(S))
	{
		cout << "括号匹配！" << endl;
	}
	else
	{
		cout << "左括号多余！" << endl;
	}
	DestoryLinkStack(&S);
}

int main1(void)
{
	char str[100] = "";
	cout << "请输入括号：" << endl;
	cin >> str;
	BrackketMatch(str);
	return 0;
}

#endif


//-----------------------------------------------表达式求值-----------------------------------------------------

#if 0
// 判断输入的是操作符还是操作数

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



























// 无括号算数表达式处理算法

int ExpEvaluatioin()
{
	// 读入一个简单算数表达式并计算其值。OPTR和OVS分别为运算符栈和运算数栈，OPSet为运算符集合
    
	LinkStack OPTR = NULL;    // 运算符栈
	LinkStack OVS = NULL;   // 运算数栈
	char OPSet[] = { '+','-','*','/','%'};
	char ch;  // 从键盘读入数据或这运算符

	InitStack(&OPTR);
	InitStack(&OVS);

	Push(&OPTR, '#');  // 为了便于操作，首先将# 压入OPTR栈
	cout << "请输入一个表达式(用‘#’结束)：" << endl;

	ch = getchar();

	while (ch != '#' || GetTop(OPTR) != '#')
	{
		if (!In(ch,OPSet))   // 不是操作符，是操作数，进OVS栈
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


// 栈的线性存储应用

// 利用栈实现二进制到十进制，八进制，十六进制之间的转换

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
	ElemntType *base; // 栈底指针
	ElemntType *top;  // 栈顶指针；
	int stackSize;  // 栈容量
}SqStack;

// 初始化栈

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

// 压栈
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

// 出栈

ElemntType Pop(SqStack *Sq)
{
	if (Sq->top==Sq->base)
	{
		return -1;
	}
	return *--Sq->top;
}

// 栈容量

int SqStackLength(SqStack Sq)
{
	return Sq.top - Sq.base;
}

// 二进制转化为十进制测试程序

// 销毁栈

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
	cout << "栈的当前容量是：" << len << endl;
	cout << "输入的数转化为十进制数为：" << sum << endl;

	for (i = 0; i < len; i++)
	{
		Binary->top++;
	}

}

// 二进制转化为八进制测试程序

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
	cout << "二进制栈的当前容量是：" << len << endl;


	int len1 = SqStackLength(*Oct);

	cout << "八进制栈的当前容量是：" << len1<< endl;
	cout << "输入的数转化为八进制数为：";
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

// 二进制转化为十六进制进制测试程序

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
	cout << "二进制栈的当前容量是：" << len << endl;


	int len1 = SqStackLength(*Dec);

	cout << "十六进制栈的当前容量是：" << len1 << endl;
	cout << "输入的数转化为十六进制数为：";

	for (int i = 0; i < len1; i++)
	{
		cout << Pop(Dec);
	}
	cout << endl;

}

int main(void)
{
	SqStack b;  // 存放二进制数据；
	SqStack o;  // 存放八进制数据；
	SqStack h; // 存放十六进制数据；
	InitSqStack(&b);
	InitSqStack(&o);
	InitSqStack(&h);
	ElemntType c;
	int i, len;
	ElemntType temp = '0';
	int sum = 0;
	cout << "请输入二进制数，输入#符号表示结束：" << endl;
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



//-------------------------------------------------递归问题--------------------------------------------

#if 0
#include<iostream>
using namespace std;

int i = 1;
// 汉诺塔
void move(int n, char x, char z)
{
	cout << "第"<<n<<"号盘子从: " << x << " ---> " << z <<"号盘子中" << endl;
}

void hanoi(int n, char x, char y, char z)
{
	// 将塔座x上从上到下编号为1至n，且按直径由小到大叠放的n个原盘，按规则搬到塔座z上，y用作辅助塔

	if (1==n)
	{
		move(1,x,z);
	}
	else
	{
		hanoi(n - 1, x,z,y);   // 先将n-1个盘子借助塔座z移动到塔座y上
		move(n,x,z);  // 将剩下的最后一个n盘子移动到塔座z上
		hanoi(n - 1, y, x, z); // 将剩下的n-1个盘子借助塔座 x移动到z上；
	}
}

// 菲波那锲数列

int Fib(int n)
{
	if (0==n||1==n)
	{
		return n;   // 递归调用出口
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);    // 递归调用
	}

}

int main(void)
{
	char x, y, z;
	x = 'A', y = 'B', z = 'C';
	cout << "请输入要移动的盘子个数：" << endl;
	int count;
	cin >> count;
	hanoi(count,x,y,z);

	for (int i = 1; i <=count; i++)
		cout << Fib(i) << "  ";
	cout << endl;

	return 0;
}

#endif






// wc命令

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




