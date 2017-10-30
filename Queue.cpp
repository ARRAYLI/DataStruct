// 队列实现

/*   

#include<iostream>
using namespace std;

// 队列数据域数据类型
typedef char QueueElement;
// 队列结点

typedef struct _Node
{
	QueueElement data;   // 数据域
	struct _Node *next;
}QueueNode;

// 队列结构体

typedef struct _Queue
{
	QueueNode *front;   // 前驱指针；
	QueueNode *rear;    // 后继指针
}Queue;

// 初始化队列
void InitQueue(Queue *q)
{
	q->front = new QueueNode;
	if (NULL==q->front)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}

	q->rear = q->front;
	q->front->next = NULL;
}

// 队列入队操作

void EneterQueue(Queue*q, QueueElement x)
{
	QueueNode *pNew = new QueueNode;

	if (NULL==pNew)
	{
		cout << "动态申请内存失败!" << endl;
		return;
	}

	pNew->data = x;
	pNew->next = NULL;

	q->rear->next = pNew;
	q->rear = pNew;
}

// 队列出对操作

void DeleteQueue(Queue *q,QueueElement*x)
{
	// 将队列q的队头元素出对，并放到x所指的内存空间中

	QueueNode *pNode = NULL;
	if (q->front==q->rear)   // 如果队列的队头指针等于队尾指针，则队空
	{
		cout << "队为空!" << endl;
		return;
	}
	pNode = q->front->next;
	q->front->next = pNode->next;
	if (q->rear==pNode)       // 如果对中只有一个元素p，则p出对后成为空队；
	{
		q->rear = q->front;
	}

	*x = pNode->data;
	delete pNode;
	pNode = NULL;
}

// 显示队列

void Show(Queue *q)
{
	QueueElement x;
	while (q->front!=q->rear)
	{
		DeleteQueue(q, &x);
		cout << x << endl;
	}
	delete q->front;
	q->front = NULL;
}


int main(void)
{
	Queue q;
	InitQueue(&q);

	QueueElement c;
	c = getchar();
	while (c!='#')
	{
		EneterQueue(&q,c);
		c = getchar();
	}

	Show(&q);
	return 0;
}

*/


// 顺序存储循环队列的实现

/*
#include<iostream>
using namespace std;
#define MAXSIZE  50   // 队列的最大长度


typedef int QueueElementType;     // 队列数据类型的定义

// 队列结构体的定义
typedef struct _Queue
{
	QueueElementType element[MAXSIZE];   // 队列的元素空间；
	int front;    // 对头指针
	int rear;    // 队尾指针
}SeQueue;


// 初始化循环队列

void InitQueue(SeQueue *Q)
{
	// 将Q初始化为一个空的循环队列
	Q->front = Q->rear = 0;
}

// 循环队列入队操作

void EnterQueue(SeQueue *Q,QueueElementType x)
{
	// 将元素x入队
	if ((Q->rear+1)%MAXSIZE==Q->front)    // 尾指针加1追上头指针，标志队列已经满了
	{
		cout << "队列已经满了!" << endl;
		return;
	}

	Q->element[Q->rear] = x;     
	Q->rear = (Q->rear + 1) % MAXSIZE;     // 重新设置队尾指针

}

// 队列出对操作

void DeleteQueue(SeQueue *Q,QueueElementType *e) 
{
	// 删除队头元素，用x返回其值
	if (Q->front==Q->rear)   // 队列为空
	{
		cout << "队列为空!" << endl;
		return;
	}

	*e = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;    // 重新设置对头指针
}


int main(void)
{
	SeQueue q;
	InitQueue(&q);
	EnterQueue(&q,1);
	EnterQueue(&q, 2);
	EnterQueue(&q, 3);
	EnterQueue(&q, 4);
	EnterQueue(&q, 5);

	int e;
	for (int i = 0; i < 5; i++)
	{
		DeleteQueue(&q, &e);
		cout << e << "  ";
	}
	cout << endl;



	return 0;
}

*/


// 杨辉三角

/*
#include<iostream>
using namespace std;
#define LEN 20      // 最多能够打印出多的行数


int main(void)
{
	int arr[LEN][LEN] = { 0 };
	int i, j;
	int n = 0;
	cout << "请输入要打印的行数:";
	cin >> n;
	while (n==0||n>=20)
	{
		cin >> n;
	}
		
	// 从第一行开始印
	for (i = 1; i <= n; i++)
		arr[i][1] = arr[i][i]=1;    // 每一列的第一一个元素和最后一个元素相同

	// 从第三行开始，除两端的1外，中间的数字都等于上一列的 arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
	for (i=3;i<=n;i++)
	{
		for (j=2;j<=i-1;j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];    // 除两边的数字1外，其余的数字等于顶端数字之和
		}
	}

	// 打印输出

	for (i=1;i<=n;i++)    // 总共有n行要打印
	{
		for (int k=1;k<=n-i;k++)
		{

			cout << "  ";
		}
		for (j=1;j<=i;j++)
		{
			cout << arr[i][j] <<"    ";
		}
		cout << endl;
	}
	return 0;
}
*/

/*
#include <stdio.h>



// 定义阶乘，在这里可能会想。为什么要用float，当我试第一次的时候，
// 如果用int的话，那么在打印行数多了以后就会出错。
// 这是因为阶乘的数比较大，如果用int就不够用了。下同




float J(int i) {
	int j;
	float k = 1;
	for (j = 1; j <= i; j++)
		k = k*j;
	return(k);
}
float C(int i, int j) {  // 定义组合数
	float k;
	k = J(j) / (J(i)*J(j - i));
	return(k);
}
void main() {
	int i = 0, j, k, n;    // 打印杨辉三角
	while (i <= 0 || i>16) {
		printf("请输入要打印的行数：");
		scanf("%d", &i);
	}
	printf("%d行杨辉三角如下：\n", i);
	for (j = 0; j<i; j++) {
		for (k = 1; k <= (i - j); k++)
			printf("  ");
		for (n = 0; n <= j; n++)
			printf("%4.0f", C(n, j));
		printf("\n");
	}
	printf("\n\n");
}

*/

// 斐波那契数列

/*

#include<iostream>
using namespace std;
#define LEN  100

int Fib(int i)
{
	if (i<2)
	{
		return i == 0 ? 0 : 1;
	}
	return Fib(i - 1) + Fib(i - 2);
}


int main(void)
{
	int arr[LEN] = { 0 };

	int n = 0;
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i=2;i<n;i++)
	{
	//	arr[i] = arr[i - 2] + arr[i - 1];
	
		arr[i] = Fib(i);
	}
	

	for (int j = 0; j < n; j++)
		cout << arr[j] << " ";
	cout << endl;

	return 0;
}
*/


//  递归实现字符串的反序输出

/*

#include<iostream>
#include<string.h>
using namespace std;

void Reverse(void)
{
	char c;
	cin >> c;	//c = getchar();
	if (c != '#')
		Reverse();
	else
		cout << c << endl;//	putchar(c);
}

void Reverse1(char *str)
{

	if (str[0]=='\0')     // 结束条件（边界条件）
	{	
		return;
	}
	else
	{
		Reverse1(&str[1]);    // 反向输出后面的字符
		putchar(str[0]);     //	补回前面的字符
	}
}

int main(void)
{
	char str[100] = "";

	gets_s(str);


	int a = 0;
	Reverse1(str);

	int i = 0;
//	Reverse();
	return 0;
}

*/


// 汉诺塔的实现

/*

#include<iostream>
using namespace std;

int step = 0;
void move(int n,char x,char y,char z)
{
	if (1==n)    // 如果只有一个盘子的话，直接把盘子从A塔上移动到C塔上
	{
		step++;
		cout <<"第"<<step<<"步:  "<< x<<"--->"<<z<< endl;
	}
	else
	{
		move(n-1,x,z,y);    // 把剩下的n-1个盘子，从A盘借助C塔移动到B塔上
		step++;
		cout << "第" << step << "步:  " << x << "--->" << z << endl;    // 将第n个盘子从A塔移动到C塔上
		move(n-1,y,x,z);    // 将n-1个盘子借助A从B塔移动到C上
	}
}

int main(void)
{
	int n=0;
	cout << "请输入要移动的盘子个数：";
	cin >> n;
	move(n,'A','B','C');
	return 0;
}

*/



// 排序

/*

#include<iostream>
using namespace std;

void BubleSort(int *arr, int len)
{
	int i, j;
	//for (i=0;i<len-1;i++)
	//{
	//	for (j = i + 1; j < len; j++)
	//	{
	//		int temp = 0;
	//		if (arr[i] > arr[j])
	//		{
	//			temp = arr[i];
	//			arr[i] = arr[j];
	//			arr[j] = temp;
	//		}
	//	}
	//}

	for (i=0;i<len-1;i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void InsertSort(int *arr,int len)
{
	int i,j,temp=0;
	for (i=1;i<len;i++)
	{
		temp = arr[i];
		j = i - 1;
		while (j>=0&&temp<arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = temp;

	}
}

void SelectSort(int *arr,int len)
{
	int i, j, min;

	for (i=0;i<len-1;i++)
	{
		min = i;

		for (j=i+1;j<len;j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min!=i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}

void ShellSort(int *arr,int len)
{
	int i, j, step,temp=0;
	step = len;

	for (step=len/2;step>0;step/=2)    // 用来控制步长
	{
		for (i=step;i<len;i++)
		{
			temp = arr[i];
			j = i - step;
			while(j>=0&&temp<arr[j])
			{
				arr[j + step] = arr[j];
				j -= step;
			}

			arr[j + step] = temp;
		}
	}








}


int main(void)
{
	int arr[10] = { 6,9,1,3,0,4,2,8,7,5 };
	int len = sizeof(arr)/sizeof(arr[0]);
//	BubleSort(arr,len);
//	SelectSort(arr,len);


	//int d = len;
	//while (d>=1)
	//{
	//	ShellSort2(arr,d, len);
	//	d /= 2;
	//}

	ShellSort(arr,len);

	//	InsertSort(arr,len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

*/

