// =========================================================================�Ͽδ���=======================================================
#define  __Run__
#ifdef  ClassCode
#include<iostream>
#include<stack>
using namespace std;

#define N 20
#define M 2*N-1
#define INF 65535
typedef char* HuffmanCode[N + 1];

typedef struct _BiNode
{
	char data;   // ������
	struct _BiNode *LChlid;  // ����ָ����
	struct _BiNode *RChlid;  // �Һ���ָ����
}BiNode,*BiTree;

typedef struct
{
	int weight;//�ڵ��Ȩֵ
	int parent;//˫�׽ڵ��±�
	int LChild;//��ڵ��±�
	int RChild;//�ҽڵ��±�
}HTNode, HuffmanTree[M + 1];//0�ŵ�Ԫ����


// �������

void PreOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		cout <<bt->data <<" ";
		PreOrder(bt->LChlid);
		PreOrder(bt->RChlid);
	}
}

// �ݹ��������
void InOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		InOrder(bt->LChlid);
		cout <<bt->data <<" ";
		InOrder(bt->RChlid);
	}
}

// �ݹ�������

void PostOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		PostOrder(bt->LChlid);
		PostOrder(bt->RChlid);
		cout << bt->data<<" ";
	}
}

// �ݹ����򴴽�������

void CreatBiTree(BiTree *bt)
{
	char ch;
	cin >> ch;
	if (ch=='.')
	{
		*bt = NULL;
	}
	else
	{
		*bt = new BiNode;
		if (NULL==bt)
		{
			cout << "��̬�����ڴ�ʧ�ܣ�" << endl;
			return;
		}

		(*bt)->data = ch;
		CreatBiTree(&((*bt)->LChlid));
		CreatBiTree(&((*bt)->RChlid));
	}
}

// �����������

int PostBiTreeDepth(BiTree bt)
{
	int hl = 0;
	int hr = 0;
	int max = 0;

	if (NULL==bt)
	{
		return 0;
	}
	else
	{
		hl = PostBiTreeDepth(bt->LChlid);
		hr = PostBiTreeDepth(bt->RChlid);
		max = hl > hr ? hl : hr;
		return max + 1;
	}
}

// �ǵݹ鷨�������������

void PreOrder1(BiTree bt)
{
	stack<BiNode*>s;
	BiNode *p = bt;

	while (p != NULL||!s.empty())
	{
		if (p!=NULL)
		{
			cout <<p->data<< "  ";
			s.push(p);
			p = p->LChlid;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->RChlid;
		}
	}
}

// �ǵݹ��������������

void InOrder1(BiTree bt)
{
	stack<BiNode*>  s;
	BiNode *p = bt;
	while (p!= NULL||!s.empty())
	{
		if (p!=NULL)
		{
			s.push(p);
			p = p->LChlid;
		}
		else
		{
			p = s.top();
			s.pop();
			cout <<p->data <<"  ";
			p = p->RChlid;
		}
	}
}

// �ǵݹ�������������

void PostOrder1(BiTree bt)
{
	stack<BiNode*> s;
	BiNode *p = bt;
	BiNode *q = NULL;

	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->LChlid;
		}

		if (!s.empty())
		{
			p = s.top();
			
			if(p->RChlid == NULL || p->RChlid == q)
			{
				s.pop();
				cout << p->data << "  ";
				q = p;
				p = NULL;
			}
			else
			{
			   p = p->RChlid;
			}

		}
	}

}

//=========��������===========
void select(HuffmanTree ht, int n, int *s1, int *s2)
{
	int min1 = INF;
	int min2 = INF;
	int i;
	*s2 = 0;
	*s1 = 0;
	for (i = 1; i <= n; i++)
	{
		if (ht[i].weight <= min1 && ht[i].parent == 0)
		{
			min1 = ht[i].weight;
			*s1 = i;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (ht[i].weight <= min2 && ht[i].parent == 0 && i != *s1)
		{
			min2 = ht[i].weight;
			*s2 = i;
		}
	}
}
void CrtHuffmanTree(HuffmanTree ht, int w[], int n)
{
	int i;
	int m;
	int s1, s2;
	//1-n�ŵ�Ԫ���Ҷ�ӽڵ㣬��ʼ��
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	//n+1��m�ŵ�Ԫ��ŷ�Ҷ�ӽڵ㣬��ʼ��
	m = 2 * n - 1;
	for (i = n + 1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{//������������
		select(ht, i - 1, &s1, &s2);//��0����i-1������ѡ��С������ֵ
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
	}
}
void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{
	char *cd;
	int i;
	int c;
	int start;
	int p;
	cd = (char*)malloc((n + 1) * sizeof(char));//���䵱ǰ����Ĺ����ռ�
	cd[n - 1] = '\0';//����������λ��ű��룬���ȴ�ű��������
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//cd�е�λ��
		c = i;//�ڼ�����
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c)
			{//���֧��0
				cd[start] = '0';
			}
			else
			{//�ҷ�֧��1
				cd[start] = '1';
			}
			c = p;
			p = ht[p].parent;
		}
		//Ϊ��i���������ռ�
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);//�ѱ��븴�Ƶ�hc[i]����
	}
}

//����������򴴽�������
char *PreArray = "abdfgceh"; //��������
char InArray[] = "bfdgaceh";//��������
void PreInCreateTree(BiTree &root, int PreIndex, int InIndex, int subTreeLen)
{
	if (subTreeLen <= 0)
	{
		root = NULL;
		return;
	}
	else
	{
		root = (BiTree)malloc(sizeof(BiNode));
		//���������Ӧ�ĸ��ڵ�
		root->data = PreArray[PreIndex];

		//�ҵ��ýڵ������������е�λ�ã������������л���Ϊ������������
		//strchr(InArray,PreArray[PreIndex])���ص��Ǹýڵ������������еĵ�ַ
		int index = strchr(InArray, PreArray[PreIndex]) - InArray;
		//�������ĳ���
		int LenF = index - InIndex;
		//����������
		PreInCreateTree(root->LChlid, PreIndex + 1, InIndex, LenF);
		//�������ĳ��� = �ܳ��� - ���������� - һ�����ڵ�
		int LenR = subTreeLen - LenF - 1;
		//������������������ַ�λ�ô��������͸��ڵ���濪ʼ�������λ�ôӵ�ǰ���ڵ�����һ��λ�ÿ�ʼ
		PreInCreateTree(root->RChlid, PreIndex + LenF + 1, index + 1, LenR);
	}
}


int main(void)
{
/*	
	BiTree bt = NULL;
	CreatBiTree(&bt);
	PreOrder(bt);
	cout << endl;
	InOrder(bt);
	cout << endl;
	PostOrder(bt);
	cout << endl;

	int n = PostBiTreeDepth(bt);
	cout << n << endl;

	PreOrder1(bt);
	cout << endl;

	InOrder1(bt);
	cout << endl;

	PostOrder1(bt);
	cout << endl;

	// AB.DF..G..C.E.H..
*/


	//=======��������=========
	int n = 5;
	int i;
	int w[5] = { 5,7,3,2,8 };
	HuffmanTree ht;
	HuffmanCode hc;
	CrtHuffmanTree(ht, w, n);
	CrtHuffmanCode(ht, hc, n);
	for (i = 1; i <= 9; i++)
	{
		printf("%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%s\n", hc[i]);
	}
	BiTree root2;
	PreInCreateTree(root2, 0, 0, strlen(InArray));
	PostOrder(root2);
	getchar();
	getchar();


	return 0;
}

#endif 
// =========================================================================�Ͽδ���=======================================================



// =========================================================================�κ���ҵ=======================================================

#define __BiTree

#ifdef __BiTree

#include<iostream>
#include<stack>
#include<queue>
#include<string>
#define NUM  20
using namespace std;

// �������Ķ���

typedef struct _BiNode
{
	char data;  // ������ 
	struct _BiNode*LChlid;  // ����ָ��
	struct _BiNode*RChlid;   // �Һ���ָ��
	int LeftMaxLength;  // �����������
	int RightMaxLength;  // �����������
}BiNode,*BiTree;


// �ݹ��������

void PreOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		cout << bt->data << " ";
		PreOrder(bt->LChlid);
		PreOrder(bt->RChlid);
	}
}

// �ݹ��������

void InOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		InOrder(bt->LChlid);
		cout <<bt->data <<" ";
		InOrder(bt->RChlid);
	}
}

// �ݹ�������

void PostOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		PostOrder(bt->LChlid);
		PostOrder(bt->RChlid);
		cout << bt->data<<" ";
	}
}

// �������������

int PostBiTreeDepth(BiTree bt)
{
	int hr = 0, hl = 0, max = 0;
	if (bt != NULL)
	{
		hl = PostBiTreeDepth(bt->LChlid);
		hr = PostBiTreeDepth(bt->RChlid);
		max = hr > hl ? hr : hl;
		return max + 1;
	}
	return 0;
}

// �ݹ����򴴽�������

void CreatBiTree(BiTree *bt)
{
	char ch;
	cin >> ch;
	if (ch=='.')
	{
		*bt = NULL;
	}
	else
	{
		*bt = new BiNode;
		if (NULL==bt)
		{
			cout << "��̬�����ڴ�ʧ�ܣ�" << endl;
			return;
		}
		(*bt)->data = ch;
		CreatBiTree(&((*bt)->LChlid));
		CreatBiTree(&((*bt)->RChlid));
	}
}

// �ǵݹ������������������

void PreOrder1(BiTree bt)
{
	stack<BiNode*>s;
	BiNode *p = bt;

	while (p!=NULL||!s.empty())
	{
		if (p!=NULL)
		{
			cout <<p->data <<"  ";
			s.push(p);
			p = p->LChlid;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->RChlid;
		}
	}
}

// �ǵݹ��������������

void InOrder1(BiTree bt)
{
	stack<BiNode *>s;
	BiNode *p = bt;
	while (p != NULL || !s.empty())
	{
		if (p!=NULL)
		{
			s.push(p);
			p = p->LChlid;
		}
		else
		{
			p = s.top();
			s.pop();
			cout <<p->data << "  ";
			p = p->RChlid;
		}
	}
}

// �ǵݹ�������������

void PostOrder1(BiTree bt)
{
	stack<BiNode*>s;
	BiNode *p = bt;
	BiNode *q = NULL;

	while(p!=NULL||!s.empty())
	{
		while (p!=NULL)
		{
			s.push(p);
			p = p->LChlid;
		}
		if (!s.empty())
		{
			p = s.top();
			if (p->RChlid==NULL||p->RChlid==q)
			{
				cout << p->data << "  ";
				s.pop();
				q = p;
				p = NULL;
			}
			else
			{
				p = p->RChlid;
			}
		}

	
	}




}

//  ��������Ҷ�ӽ�����

int GetLeafNodeNumber(BiTree bt)
{
	int NodeCount = 0;
	if (bt==NULL)
	{
		return 0;
	}
	else if (bt->LChlid==NULL&&bt->RChlid==NULL)
	{
		return 1;
	}
	else
	{
		return GetLeafNodeNumber(bt->LChlid)+GetLeafNodeNumber(bt->RChlid);
	}
}

// �������Ĳ������

void LayerOrder(BiTree bt)
{
	queue<BiNode*>q;
	BiNode* p = NULL;
	if (NULL == bt)
	{
		return;   // ����Ϊ�յĻ�����Ϊ��������������
	}
	else
	{
		q.push(bt);  // �ȰѶ�ͷԪ�������
		while (!q.empty())   // ������Ϊ�ǿյĻ��������δ��������������
		{
			p = q.front();   // ��ͷԪ�س��Ӳ�����
			q.pop();
			cout << p->data<<"  ";
			if (p->LChlid!=NULL)
			{
				q.push(p->LChlid);
			}
			if (p->RChlid!=NULL)
			{
				q.push(p->RChlid);
			}
		}
	}

}

// ����ݹ����ٶ�����

void PostDeStoryBiTree(BiTree *bt)
{
	if (*bt==NULL)
	{
		return;
	}
	else
	{
		PostDeStoryBiTree(&(*bt)->LChlid);
		PostDeStoryBiTree(&(*bt)->RChlid);
		delete *bt;
		*bt = NULL;
	}
}

// ����������򴴽�������

char *PreArray = "abdfgceh"; //��������
char InArray[] = "bfdgaceh";//��������

void CreatPreInOrderBiTree(BiTree &bt,int PreIndex,int InIndex,int subTreeLen)
{
	if (subTreeLen<=0)
	{
		bt = NULL;
		return;
	}
	else
	{
		// ���������Ӧ�ĸ��ڵ�
		bt = new BiNode;
		if (NULL==bt)
		{
			cout <<"��̬�����ڴ�ʧ��!" <<endl;
			exit(1);
		}
		bt->data = PreArray[PreIndex];

		// �ҵ��ýڵ������������е�λ�ã������������л���Ϊ��������
		// strchr(InArray,PreArray[PreIndex]) ���ص��ǽ�������������еĵ�ַ

		int index = strchr(InArray,PreArray[PreIndex])-InArray;

		// �������ĳ���
		int LenF = index - InIndex;
		// ����������

		CreatPreInOrderBiTree(bt->LChlid,PreIndex+1,InIndex,LenF);

		// �������ĳ���=�ܳ���-�������ĳ���-һ�����ڵ�
		int LenR = subTreeLen - LenF - 1;

		// ������������������ַ�λ�ô��������͸������濪ʼ�������λ�ôӵ�ǰ���ڵ�ĺ����һ��λ�ÿ�ʼ
		CreatPreInOrderBiTree(bt->RChlid,PreIndex+LenF+1,index+1,LenR);
	}

}

// �ж����Ŷ������Ƿ�����

bool JudgeBiTreeLike(BiTree bt1,BiTree bt2)
{
	bool like1, like2;
	if (bt1==NULL&&bt2==NULL)
	{
		return true;
	}
	else
	{
		if (bt1==NULL||bt2==NULL)
		{
			return false;
		}
		else
		{
			like1=JudgeBiTreeLike(bt1->LChlid,bt2->LChlid);
			like2 = JudgeBiTreeLike(bt1->RChlid,bt2->RChlid);
			return like1&&like2;
		}
	}
}

// ��������ڵ��������

void FindMaxLen(BiTree bt,int *maxLen)
{
	// ������Ҷ�ӽ�㷵��
	if (bt==NULL)
	{
		return;
	}

	// ���������Ϊ�գ���ô�ýڵ���������Ϊ0
	if (bt->LChlid==NULL)
	{
		bt->LeftMaxLength = 0;
	}
	// ���������Ϊ�գ���ô�ýڵ��ұ������Ϊ0
	if (bt->LChlid == NULL)
	{
		bt->RightMaxLength= 0;
	}

	// �����������Ϊ�գ��ݹ�Ѱ�������������
	if (bt->LChlid!=NULL)
	{
		FindMaxLen(bt->LChlid,maxLen);
	}

	// �����������Ϊ�գ��ݹ�Ѱ�������������
		if (bt->RChlid!= NULL)
			FindMaxLen(bt->RChlid, maxLen);

	//�����������о�����ڵ�������    
	if (bt->LChlid!=NULL)
	{
		if (bt->LChlid->LeftMaxLength > bt->LChlid->RightMaxLength)
		{
			bt->LeftMaxLength=bt->LChlid->LeftMaxLength + 1;
		}
		else
			bt->LeftMaxLength = bt->LChlid->RightMaxLength + 1;
	}

	//�����������о�����ڵ�������    
	if (bt->RChlid != NULL)
	{
		if (bt->RChlid->LeftMaxLength > bt->RChlid->RightMaxLength)
		{
			bt->RightMaxLength=bt->RChlid->LeftMaxLength + 1;
		}
		else
			bt->RightMaxLength = bt->RChlid->RightMaxLength + 1;
	}

	//���������    
	
	if (bt->LeftMaxLength+bt->RightMaxLength>*maxLen)
	{
		*maxLen = bt->LeftMaxLength + bt->RightMaxLength;
	}
}

// ��Ӹ���㵽ĳ�����·��

void path(BiTree bt,BiNode *r)
{
	BiNode  *p, *q;
	int i, find = 0, top = 0;
	BiNode *s[NUM];
	q = NULL;   /* ��q����ձ������Ľ�� */
	p = bt;
	while ((p != NULL || top != 0) && !find)
	{
		while (p != NULL)
		{
			top++;
			s[top] = p;
			p = p->LChlid;
		}                /* ���������� */
		if (top > 0)
		{
			p = s[top];       /* ����� */
			if (p->RChlid == NULL || p->RChlid == q)
			{
				if (p == r)   /*�ҵ�r��ָ��㣬����ʾ�Ӹ���㵽r��ָ���֮���·��*/
				{
					for (i = 1; i <= top; i++)
						//	printf("%c  ", s[i]->data);
						cout << s[i]->data<<"  ";
						find = 1;
				}
				else
				{
					q = p;        /* ��q����ձ������Ľ�� */
					top--;
					p = NULL;    /* ����ǰ���������������ջ */
				}
			}
			else
				p = p->RChlid;     /* ���������� */
		}
	}

	cout << endl;

}

// ��������������������Ĺ�������

BiNode *GetCommPa(BiTree bt,BiTree x,BiTree y)
{
	if (bt==NULL)
	{
		return NULL;
	}

	if (x==bt||y==bt)
	{
		return bt;
	}

	BiTree Left = NULL, Right = NULL;
	Left = GetCommPa(bt->LChlid,x,y);
	Right = GetCommPa(bt->RChlid,x,y);

	if (Left==NULL)
	{
		return Right;
	}
	if (Right==NULL)
	{
		return Left;
	}
	return bt;
}

int main(void)
{
	BiTree bt = NULL;
	CreatBiTree(&bt);
	BiTree bt1 = NULL;
	CreatBiTree(&bt1);

	cout << JudgeBiTreeLike(bt,bt1) << endl;

//	PreOrder(bt);
//	cout << endl;
//	InOrder(bt);
//	cout << endl;
//	PostOrder(bt);
//	cout << endl;
//
//	int n = PostBiTreeDepth(bt);
//	cout << n << endl;
//
//	PreOrder1( bt);
//	cout <<endl;
//	InOrder1(bt);
//	cout << endl;
//	PostOrder1(bt);
//	cout << endl;
//	cout << GetLeafNodeNumber(bt) << endl;
//
//	LayerOrder(bt);
//	cout << endl;
//	// AB.DF..G..C.E.H..
//
//	int i = 0;
//
//	PostDeStoryBiTree(&bt);
//
//
//	BiTree bt1 = NULL;
////	PreInCreateTree1(bt1,0,0,strlen(PreArray));
//	CreatPreInOrderBiTree(bt1, 0, 0, strlen(PreArray));
//	
//	PostOrder(bt1);
//	cout << endl;
//	PostDeStoryBiTree(&bt1);
	int count = 0;
	FindMaxLen(bt,&count);
	cout << count << endl;
	path(bt,bt->LChlid->RChlid);
	
	BiNode *p = GetCommPa(bt,bt->LChlid->RChlid,bt->RChlid->RChlid);
	cout << p->data << endl;
	return 0;
}
#endif // !BiTree


// ����������

#ifdef __CrtHuffmanTree



#include<iostream>
using namespace std;
#define N 20                // Ҷ�ӽ������ֵ
#define M 2*N-1             // ����Ҷ�ӽ������ֵ 
#define  INF 65535  
// �����������
typedef struct _HNode
{
	int weight;             // ����Ȩֵ
	int parent;             // ˫�׵��±�
	int LChild;             // ���ӽ����±�
	int RChlid;             // �Һ��ӽ����±�
}HNode,HuffmanTree[M+1];    // HuffmanTree��һ���ṹ���������ͣ�0�ŵ�Ԫ������

typedef char*HuffmanCode[M + 1];    // �洢���������봮��ͷָ������

// ��ht[1]--ht[i-1]�ķ�Χ������˫��Ϊparent=0,����weight��С�ĵ㣬���Ҹ�ֵ��s1,s2;

void select(HuffmanTree ht,int n,int *s1,int *s2)
{
	int min1 = INF;
	int min2 = INF;
	int i;
	*s1 = 0;
	*s2 = 0;
	for (i = 1; i <= n; i++)
	{
		if (ht[i].weight <= min1&&ht[i].parent == 0)
		{
			min1 = ht[i].weight;
			*s1 = i;
		}
	}

	for (i=1;i<=n;i++)
	{
		if (ht[i].weight <= min2&&ht[i].parent == 0&&i!=*s1)
		{
			min2 = ht[i].weight;
			*s2 = i;
		}
	}

}

// ������������

void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
	int i;
	int m;
	int s1, s2;
	// 1-n�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
	for (i=1;i<=n;i++)
	{
		ht[i].weight = w[i-1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChlid = 0;
	}
	m = 2 * n - 1;
	// n+1-m�ŵ�Ԫ���Ҷ�ӽ�㣬��ʼ��
	for (i=n+1;i<=m;i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChlid = 0;
	}
	
	// ������������
	for (i=n + 1; i <= m; i++)
	{
		select(ht,i-1,&s1,&s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChlid = s2;
	}
}
	
// ����������

void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	int i;
	char *cd;
	int start = 0;
	int p;
	int c = 0;
	cd = new char((n +1)* sizeof(char));   // ���䵱ǰ����Ĺ����ռ�
	cd[n - 1] = '\0';  // ��������λ��ű��룬���ȴ�ű��������

	for (i=1;i<=n;i++)    // ��n��Ҷ�ӽ��Ĺ���������
	{
		start = n - 1;     // ��ʼ����ʼ����ָ��
		c = i; p = ht[i].parent;      // ��Ҷ�ӽ�㿪ʼ���ϵ���
		while (p!=NULL)
		{
			--start;  
			if (ht[i].LChild == c)
				cd[start] = '0';      // ����֧��0
 			else
				cd[start] = '1';      // �ҷ�֧��1
			c =p;p;   p = ht[p].parent;       // ���ϵ���
		}

		//Ϊ��i���������ռ�
		hc[i] = new char(sizeof(n - start)*(n - start));   
		strcpy(hc[i],&cd[start]);
	}
}

// ����������Ĵ�ȫ·������

int GetHuffmanTreeWidgetPathLengt(HuffmanTree ht,int len)   // len��ʼ��Ϊ0
{
	int WPL = 0;
	int index = 0;
	for (int i = 1; i <=len; i++)
	{
		int count = 0;
		index = ht[i].parent;
		while (index)
		{
			count++;
			index = ht[index].parent;
		}

		if (ht[i].LChild==0&&ht[i].RChlid==0)
		{
			WPL += count*ht[i].weight;
		}

	}
	return WPL;
}


int main(void)
{
	HuffmanTree ht;
	HuffmanCode hc;
	int n = 5;
	int w[5] = { 3,8,7,5,2 };
	int i;
	CrtHuffmanTree(ht,w,n);
	CrtHuffmanCode(ht,hc,n);
	for (i=1;i<=9;i++)
	{
		cout << ht[i].weight << "  " << ht[i].parent << "  " << ht[i].LChild << "  " << ht[i].RChlid << endl;
	}

	for (i=1;i<=5;i++)
	{
		cout << hc[i] << endl;
	}

	int s = GetHuffmanTreeWidgetPathLengt(ht, 5);
	cout << s << endl;

	/*HuffmanTree ht;
	HuffmanCode hc;
	int i;
	int n = 5;
	int w[5] = { 3,8,7,5,2 };
	CrtHuffmanTree(ht, w, n);
	CrtHuffmanCode(ht, hc, n);
	for (i = 1; i <= 9; i++)
	{
		printf("%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChlid);
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%s\n", hc[i]);
	}
	printf("\n");*/

	return 0;
}
#endif // CrtHuffmanTree


#ifdef DEBUG

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<stack>

#define N 20
#define M 2*N-1
#define INF 65535
using namespace std;

typedef char* HuffmanCode[N + 1];
typedef struct Node
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}BiTNode, *BiTree;

typedef struct
{
	int weight;//�ڵ��Ȩֵ
	int parent;//˫�׽ڵ��±�
	int LChild;//��ڵ��±�
	int RChild;//�ҽڵ��±�
}HTNode, HuffmanTree[M + 1];//0�ŵ�Ԫ����
void PreOrder(BiTree root)
{
	if (root != NULL)
	{
		printf(" %c ", root->data);
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}
void InOrder(BiTree root)
{
	if (root != NULL)
	{
		InOrder(root->lchild);
		printf(" %c ", root->data);
		InOrder(root->rchild);
	}
}
void PostOrder(BiTree root)
{
	if (root != NULL)
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		printf(" %c ", root->data);
	}
}
void CreatBiTree(BiTree *root)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '.')
	{
		*root = NULL;
	}
	else
	{
		*root = (BiTNode*)malloc(sizeof(BiTNode));
		(*root)->data = ch;
		CreatBiTree(&((*root)->lchild));
		CreatBiTree(&((*root)->rchild));
	}
}
int PostTreeDepth(BiTree root)
{
	int hl, hr, max;
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		hl = PostTreeDepth(root->lchild);
		hr = PostTreeDepth(root->rchild);
		max = hl > hr ? hl : hr;
		return max + 1;
	}
}
void PreOrder1(BiTree root)//�ǵݹ�����
{
	stack<BiTNode*> s;
	BiTNode *p;
	p = root;
	while (p != NULL || !s.empty())
	{
		if (p != NULL)
		{
			printf("%c ", p->data);
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
void InOrder1(BiTree root)
{
	stack<BiTNode*> s;
	BiTNode *p;
	p = root;
	while (p != NULL || !s.empty())
	{
		if (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			printf("%c ", p->data);
			s.pop();
			p = p->rchild;
		}
	}
}
void PostOrder1(BiTree root)
{
	stack<BiTNode*> s;
	BiTNode *p, *q;
	p = root;
	q = NULL;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			if (p->rchild == NULL || p->rchild == q)
			{
				printf("%c ", p->data);
				s.pop();
				q = p;
				p = NULL;
			}
			else
			{
				p = p->rchild;
			}
		}
	}
}
//����������򴴽�������
char *PreArray = "abdfgceh"; //��������
char InArray[] = "bfdgaceh";//��������
void PreInCreateTree(BiTree &root, int PreIndex, int InIndex, int subTreeLen)
{
	if (subTreeLen <= 0)
	{
		root = NULL;
		return;
	}
	else
	{
		root = (BiTree)malloc(sizeof(BiTNode));
		//���������Ӧ�ĸ��ڵ�
		root->data = PreArray[PreIndex];

		//�ҵ��ýڵ������������е�λ�ã������������л���Ϊ������������
		//strchr(InArray,PreArray[PreIndex])���ص��Ǹýڵ������������еĵ�ַ
		int index = strchr(InArray, PreArray[PreIndex]) - InArray;
		//�������ĳ���
		int LenF = index - InIndex;
		//����������
		PreInCreateTree(root->lchild, PreIndex + 1, InIndex, LenF);
		//�������ĳ��� = �ܳ��� - ���������� - һ�����ڵ�
		int LenR = subTreeLen - LenF - 1;
		//������������������ַ�λ�ô��������͸��ڵ���濪ʼ�������λ�ôӵ�ǰ���ڵ�����һ��λ�ÿ�ʼ
		PreInCreateTree(root->rchild, PreIndex + LenF + 1, index + 1, LenR);
	}
}
void select(HuffmanTree ht, int n, int *s1, int *s2)
{
	int min1 = INF;
	int min2 = INF;
	int i;
	*s2 = 0;
	*s1 = 0;
	for (i = 1; i <= n; i++)
	{
		if (ht[i].weight <= min1 && ht[i].parent == 0)
		{
			min1 = ht[i].weight;
			*s1 = i;
		}
	}
	for (i = 1; i <= n; i++)
	{
		if (ht[i].weight <= min2 && ht[i].parent == 0 && i != *s1)
		{
			min2 = ht[i].weight;
			*s2 = i;
		}
	}
}
void CrtHuffmanTree(HuffmanTree ht, int w[], int n)
{
	int i;
	int m;
	int s1, s2;
	//1-n�ŵ�Ԫ���Ҷ�ӽڵ㣬��ʼ��
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	//n+1��m�ŵ�Ԫ��ŷ�Ҷ�ӽڵ㣬��ʼ��
	m = 2 * n - 1;
	for (i = n + 1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{//������������
		select(ht, i - 1, &s1, &s2);//��0����i-1������ѡ��С������ֵ
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
	}
}
void CrtHuffmanCode(HuffmanTree ht, HuffmanCode hc, int n)
{
	char *cd;
	int i;
	int c;
	int start;
	int p;
	cd = (char*)malloc((n + 1) * sizeof(char));//���䵱ǰ����Ĺ����ռ�
	cd[n - 1] = '\0';//����������λ��ű��룬���ȴ�ű��������
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//cd�е�λ��
		c = i;//�ڼ�����
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c)
			{//���֧��0
				cd[start] = '0';
			}
			else
			{//�ҷ�֧��1
				cd[start] = '1';
			}
			c = p;
			p = ht[p].parent;
		}
		//Ϊ��i���������ռ�
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);//�ѱ��븴�Ƶ�hc[i]����
	}

}
int main(void)
{
	BiTree root;
	//CreatBiTree(&root);
	//PreOrder(root);
	//printf("\n");
	//InOrder(root);
	//printf("\n");
	//PostOrder(root);
	//printf("\n");
	////printf("%d\n", PostTreeDepth(root));
	//PreOrder1(root);
	//printf("\n");
	//InOrder1(root);
	//printf("\n");
	//PostOrder1(root);
	//PreInCreateTree(root, 0, 0, strlen(PreArray));
	//PreOrder(root);
	HuffmanTree ht;
	HuffmanCode hc;
	int i;
	int n = 5;
	int w[5] = { 3,8,7,5,2 };
	CrtHuffmanTree(ht, w, n);
	CrtHuffmanCode(ht, hc, n);
	for (i = 1; i <= 9; i++)
	{
		printf("%d %d %d %d\n", ht[i].weight, ht[i].parent, ht[i].LChild, ht[i].RChild);
	}
	for (i = 1; i <= 5; i++)
	{
		printf("%s\n", hc[i]);
	}
	printf("\n");
	return 0;
}





#endif // DEBUG


/*

3 6 0 0
8 8 0 0
7 8 0 0
5 7 0 0
2 6 0 0
5 7 5 1
10 9 6 4
15 9 3 2
25 0 7 8
001
11
10
01
000

*/