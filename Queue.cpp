// ����ʵ��

/*   

#include<iostream>
using namespace std;

// ������������������
typedef char QueueElement;
// ���н��

typedef struct _Node
{
	QueueElement data;   // ������
	struct _Node *next;
}QueueNode;

// ���нṹ��

typedef struct _Queue
{
	QueueNode *front;   // ǰ��ָ�룻
	QueueNode *rear;    // ���ָ��
}Queue;

// ��ʼ������
void InitQueue(Queue *q)
{
	q->front = new QueueNode;
	if (NULL==q->front)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}

	q->rear = q->front;
	q->front->next = NULL;
}

// ������Ӳ���

void EneterQueue(Queue*q, QueueElement x)
{
	QueueNode *pNew = new QueueNode;

	if (NULL==pNew)
	{
		cout << "��̬�����ڴ�ʧ��!" << endl;
		return;
	}

	pNew->data = x;
	pNew->next = NULL;

	q->rear->next = pNew;
	q->rear = pNew;
}

// ���г��Բ���

void DeleteQueue(Queue *q,QueueElement*x)
{
	// ������q�Ķ�ͷԪ�س��ԣ����ŵ�x��ָ���ڴ�ռ���

	QueueNode *pNode = NULL;
	if (q->front==q->rear)   // ������еĶ�ͷָ����ڶ�βָ�룬��ӿ�
	{
		cout << "��Ϊ��!" << endl;
		return;
	}
	pNode = q->front->next;
	q->front->next = pNode->next;
	if (q->rear==pNode)       // �������ֻ��һ��Ԫ��p����p���Ժ��Ϊ�նӣ�
	{
		q->rear = q->front;
	}

	*x = pNode->data;
	delete pNode;
	pNode = NULL;
}

// ��ʾ����

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


// ˳��洢ѭ�����е�ʵ��

/*
#include<iostream>
using namespace std;
#define MAXSIZE  50   // ���е���󳤶�


typedef int QueueElementType;     // �����������͵Ķ���

// ���нṹ��Ķ���
typedef struct _Queue
{
	QueueElementType element[MAXSIZE];   // ���е�Ԫ�ؿռ䣻
	int front;    // ��ͷָ��
	int rear;    // ��βָ��
}SeQueue;


// ��ʼ��ѭ������

void InitQueue(SeQueue *Q)
{
	// ��Q��ʼ��Ϊһ���յ�ѭ������
	Q->front = Q->rear = 0;
}

// ѭ��������Ӳ���

void EnterQueue(SeQueue *Q,QueueElementType x)
{
	// ��Ԫ��x���
	if ((Q->rear+1)%MAXSIZE==Q->front)    // βָ���1׷��ͷָ�룬��־�����Ѿ�����
	{
		cout << "�����Ѿ�����!" << endl;
		return;
	}

	Q->element[Q->rear] = x;     
	Q->rear = (Q->rear + 1) % MAXSIZE;     // �������ö�βָ��

}

// ���г��Բ���

void DeleteQueue(SeQueue *Q,QueueElementType *e) 
{
	// ɾ����ͷԪ�أ���x������ֵ
	if (Q->front==Q->rear)   // ����Ϊ��
	{
		cout << "����Ϊ��!" << endl;
		return;
	}

	*e = Q->element[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;    // �������ö�ͷָ��
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


// �������

/*
#include<iostream>
using namespace std;
#define LEN 20      // ����ܹ���ӡ���������


int main(void)
{
	int arr[LEN][LEN] = { 0 };
	int i, j;
	int n = 0;
	cout << "������Ҫ��ӡ������:";
	cin >> n;
	while (n==0||n>=20)
	{
		cin >> n;
	}
		
	// �ӵ�һ�п�ʼӡ
	for (i = 1; i <= n; i++)
		arr[i][1] = arr[i][i]=1;    // ÿһ�еĵ�һһ��Ԫ�غ����һ��Ԫ����ͬ

	// �ӵ����п�ʼ�������˵�1�⣬�м�����ֶ�������һ�е� arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
	for (i=3;i<=n;i++)
	{
		for (j=2;j<=i-1;j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];    // �����ߵ�����1�⣬��������ֵ��ڶ�������֮��
		}
	}

	// ��ӡ���

	for (i=1;i<=n;i++)    // �ܹ���n��Ҫ��ӡ
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



// ����׳ˣ���������ܻ��롣ΪʲôҪ��float�������Ե�һ�ε�ʱ��
// �����int�Ļ�����ô�ڴ�ӡ���������Ժ�ͻ����
// ������Ϊ�׳˵����Ƚϴ������int�Ͳ������ˡ���ͬ




float J(int i) {
	int j;
	float k = 1;
	for (j = 1; j <= i; j++)
		k = k*j;
	return(k);
}
float C(int i, int j) {  // ���������
	float k;
	k = J(j) / (J(i)*J(j - i));
	return(k);
}
void main() {
	int i = 0, j, k, n;    // ��ӡ�������
	while (i <= 0 || i>16) {
		printf("������Ҫ��ӡ��������");
		scanf("%d", &i);
	}
	printf("%d������������£�\n", i);
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

// 쳲���������

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


//  �ݹ�ʵ���ַ����ķ������

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

	if (str[0]=='\0')     // �����������߽�������
	{	
		return;
	}
	else
	{
		Reverse1(&str[1]);    // �������������ַ�
		putchar(str[0]);     //	����ǰ����ַ�
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


// ��ŵ����ʵ��

/*

#include<iostream>
using namespace std;

int step = 0;
void move(int n,char x,char y,char z)
{
	if (1==n)    // ���ֻ��һ�����ӵĻ���ֱ�Ӱ����Ӵ�A�����ƶ���C����
	{
		step++;
		cout <<"��"<<step<<"��:  "<< x<<"--->"<<z<< endl;
	}
	else
	{
		move(n-1,x,z,y);    // ��ʣ�µ�n-1�����ӣ���A�̽���C���ƶ���B����
		step++;
		cout << "��" << step << "��:  " << x << "--->" << z << endl;    // ����n�����Ӵ�A���ƶ���C����
		move(n-1,y,x,z);    // ��n-1�����ӽ���A��B���ƶ���C��
	}
}

int main(void)
{
	int n=0;
	cout << "������Ҫ�ƶ������Ӹ�����";
	cin >> n;
	move(n,'A','B','C');
	return 0;
}

*/



// ����

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

	for (step=len/2;step>0;step/=2)    // �������Ʋ���
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

