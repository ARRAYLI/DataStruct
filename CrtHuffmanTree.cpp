// =========================================================================上课代码=======================================================
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
	char data;   // 数据域
	struct _BiNode *LChlid;  // 左孩子指阵域
	struct _BiNode *RChlid;  // 右孩子指阵域
}BiNode,*BiTree;

typedef struct
{
	int weight;//节点的权值
	int parent;//双亲节点下标
	int LChild;//左节点下标
	int RChild;//右节点下标
}HTNode, HuffmanTree[M + 1];//0号单元不用


// 先序遍历

void PreOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		cout <<bt->data <<" ";
		PreOrder(bt->LChlid);
		PreOrder(bt->RChlid);
	}
}

// 递归中序遍历
void InOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		InOrder(bt->LChlid);
		cout <<bt->data <<" ";
		InOrder(bt->RChlid);
	}
}

// 递归后序遍历

void PostOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		PostOrder(bt->LChlid);
		PostOrder(bt->RChlid);
		cout << bt->data<<" ";
	}
}

// 递归先序创建二叉树

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
			cout << "动态申请内存失败！" << endl;
			return;
		}

		(*bt)->data = ch;
		CreatBiTree(&((*bt)->LChlid));
		CreatBiTree(&((*bt)->RChlid));
	}
}

// 二叉树的深度

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

// 非递归法先序遍历二叉树

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

// 非递归中序遍历二叉树

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

// 非递归后序遍历二叉树

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

//=========哈夫曼树===========
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
	//1-n号单元存放叶子节点，初始化
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	//n+1—m号单元存放非叶子节点，初始化
	m = 2 * n - 1;
	for (i = n + 1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{//创建哈夫曼树
		select(ht, i - 1, &s1, &s2);//从0至（i-1）行中选最小的两个值
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
	cd = (char*)malloc((n + 1) * sizeof(char));//分配当前编码的工作空间
	cd[n - 1] = '\0';//从右向左逐位存放编码，首先存放编码结束符
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//cd中的位置
		c = i;//第几个点
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c)
			{//左分支标0
				cd[start] = '0';
			}
			else
			{//右分支标1
				cd[start] = '1';
			}
			c = p;
			p = ht[p].parent;
		}
		//为第i个编码分配空间
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);//把编码复制到hc[i]里面
	}
}

//给先序和中序创建二叉树
char *PreArray = "abdfgceh"; //先序序列
char InArray[] = "bfdgaceh";//中序序列
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
		//创建先序对应的根节点
		root->data = PreArray[PreIndex];

		//找到该节点在中序序列中的位置，并将中序序列划分为左右两个子树
		//strchr(InArray,PreArray[PreIndex])返回的是该节点在中序序列中的地址
		int index = strchr(InArray, PreArray[PreIndex]) - InArray;
		//左子树的长度
		int LenF = index - InIndex;
		//创建左子树
		PreInCreateTree(root->LChlid, PreIndex + 1, InIndex, LenF);
		//右子树的长度 = 总长度 - 左子树长度 - 一个根节点
		int LenR = subTreeLen - LenF - 1;
		//创建右子树，先序的字符位置从左子树和根节点后面开始，中序的位置从当前根节点后面的一个位置开始
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


	//=======哈夫曼树=========
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
// =========================================================================上课代码=======================================================



// =========================================================================课后作业=======================================================

#define __BiTree

#ifdef __BiTree

#include<iostream>
#include<stack>
#include<queue>
#include<string>
#define NUM  20
using namespace std;

// 二叉树的定义

typedef struct _BiNode
{
	char data;  // 数据域 
	struct _BiNode*LChlid;  // 左孩子指针
	struct _BiNode*RChlid;   // 右孩子指针
	int LeftMaxLength;  // 左子树最长距离
	int RightMaxLength;  // 右子树最长距离
}BiNode,*BiTree;


// 递归先序遍历

void PreOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		cout << bt->data << " ";
		PreOrder(bt->LChlid);
		PreOrder(bt->RChlid);
	}
}

// 递归中序遍历

void InOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		InOrder(bt->LChlid);
		cout <<bt->data <<" ";
		InOrder(bt->RChlid);
	}
}

// 递归后序遍历

void PostOrder(BiTree bt)
{
	if (bt!=NULL)
	{
		PostOrder(bt->LChlid);
		PostOrder(bt->RChlid);
		cout << bt->data<<" ";
	}
}

// 后序求树的深度

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

// 递归先序创建二叉树

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
			cout << "动态申请内存失败！" << endl;
			return;
		}
		(*bt)->data = ch;
		CreatBiTree(&((*bt)->LChlid));
		CreatBiTree(&((*bt)->RChlid));
	}
}

// 非递归先序遍历创建二叉树

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

// 非递归中序遍历二叉树

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

// 非递归后序遍历二叉树

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

//  二叉树的叶子结点个数

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

// 二叉树的层序遍历

void LayerOrder(BiTree bt)
{
	queue<BiNode*>q;
	BiNode* p = NULL;
	if (NULL == bt)
	{
		return;   // 若树为空的话，则为空树，结束遍历
	}
	else
	{
		q.push(bt);  // 先把对头元素入队列
		while (!q.empty())   // 若队列为非空的话，则遍历未结束，继续进行
		{
			p = q.front();   // 对头元素出队并访问
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

// 后序递归销毁二叉树

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

// 给先序和中序创建二叉树

char *PreArray = "abdfgceh"; //先序序列
char InArray[] = "bfdgaceh";//中序序列

void CreatPreInOrderBiTree(BiTree &bt,int PreIndex,int InIndex,int subTreeLen)
{
	if (subTreeLen<=0)
	{
		bt = NULL;
		return;
	}
	else
	{
		// 创建先序对应的根节点
		bt = new BiNode;
		if (NULL==bt)
		{
			cout <<"动态申请内存失败!" <<endl;
			exit(1);
		}
		bt->data = PreArray[PreIndex];

		// 找到该节点在中序序列中的位置，并将中序序列划分为两个子树
		// strchr(InArray,PreArray[PreIndex]) 返回的是结点在中序序列中的地址

		int index = strchr(InArray,PreArray[PreIndex])-InArray;

		// 左子树的长度
		int LenF = index - InIndex;
		// 创建左子树

		CreatPreInOrderBiTree(bt->LChlid,PreIndex+1,InIndex,LenF);

		// 右子树的长度=总长度-左子树的长度-一个根节点
		int LenR = subTreeLen - LenF - 1;

		// 创建右子树，先序的字符位置从左子树和根结点后面开始，中序的位置从当前根节点的后面的一个位置开始
		CreatPreInOrderBiTree(bt->RChlid,PreIndex+LenF+1,index+1,LenR);
	}

}

// 判断两颗二叉树是否相似

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

// 求二叉树节点的最大距离

void FindMaxLen(BiTree bt,int *maxLen)
{
	// 遍历到叶子结点返回
	if (bt==NULL)
	{
		return;
	}

	// 如果左子树为空，那么该节点左边最长距离为0
	if (bt->LChlid==NULL)
	{
		bt->LeftMaxLength = 0;
	}
	// 如果右子树为空，那么该节点右边最长距离为0
	if (bt->LChlid == NULL)
	{
		bt->RightMaxLength= 0;
	}

	// 如果左子树不为空，递归寻找左子树最长距离
	if (bt->LChlid!=NULL)
	{
		FindMaxLen(bt->LChlid,maxLen);
	}

	// 如果右子树不为空，递归寻找右子树最长距离
		if (bt->RChlid!= NULL)
			FindMaxLen(bt->RChlid, maxLen);

	//计算左子树中距离根节点的最长距离    
	if (bt->LChlid!=NULL)
	{
		if (bt->LChlid->LeftMaxLength > bt->LChlid->RightMaxLength)
		{
			bt->LeftMaxLength=bt->LChlid->LeftMaxLength + 1;
		}
		else
			bt->LeftMaxLength = bt->LChlid->RightMaxLength + 1;
	}

	//计算右子树中距离根节点的最长距离    
	if (bt->RChlid != NULL)
	{
		if (bt->RChlid->LeftMaxLength > bt->RChlid->RightMaxLength)
		{
			bt->RightMaxLength=bt->RChlid->LeftMaxLength + 1;
		}
		else
			bt->RightMaxLength = bt->RChlid->RightMaxLength + 1;
	}

	//更新最长距离    
	
	if (bt->LeftMaxLength+bt->RightMaxLength>*maxLen)
	{
		*maxLen = bt->LeftMaxLength + bt->RightMaxLength;
	}
}

// 求从根结点到某结点间的路径

void path(BiTree bt,BiNode *r)
{
	BiNode  *p, *q;
	int i, find = 0, top = 0;
	BiNode *s[NUM];
	q = NULL;   /* 用q保存刚遍历过的结点 */
	p = bt;
	while ((p != NULL || top != 0) && !find)
	{
		while (p != NULL)
		{
			top++;
			s[top] = p;
			p = p->LChlid;
		}                /* 遍历左子树 */
		if (top > 0)
		{
			p = s[top];       /* 根结点 */
			if (p->RChlid == NULL || p->RChlid == q)
			{
				if (p == r)   /*找到r所指结点，则显示从根结点到r所指结点之间的路径*/
				{
					for (i = 1; i <= top; i++)
						//	printf("%c  ", s[i]->data);
						cout << s[i]->data<<"  ";
						find = 1;
				}
				else
				{
					q = p;        /* 用q保存刚遍历过的结点 */
					top--;
					p = NULL;    /* 跳过前面左遍历，继续退栈 */
				}
			}
			else
				p = p->RChlid;     /* 遍历右子树 */
		}
	}

	cout << endl;

}

// 求二叉树中最近的两个点的公共祖先

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


// 哈夫曼编码

#ifdef __CrtHuffmanTree



#include<iostream>
using namespace std;
#define N 20                // 叶子结点的最大值
#define M 2*N-1             // 所有叶子结点的最大值 
#define  INF 65535  
// 定义哈夫曼树
typedef struct _HNode
{
	int weight;             // 结点的权值
	int parent;             // 双亲的下标
	int LChild;             // 左孩子结点的下标
	int RChlid;             // 右孩子结点的下标
}HNode,HuffmanTree[M+1];    // HuffmanTree是一个结构体数组类型，0号单元不可用

typedef char*HuffmanCode[M + 1];    // 存储哈夫曼编码串的头指针数组

// 在ht[1]--ht[i-1]的范围内两个双亲为parent=0,并且weight最小的点，并且赋值给s1,s2;

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

// 创建哈夫曼树

void CrtHuffmanTree(HuffmanTree ht,int w[],int n)
{
	int i;
	int m;
	int s1, s2;
	// 1-n号单元存放叶子结点，初始化
	for (i=1;i<=n;i++)
	{
		ht[i].weight = w[i-1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChlid = 0;
	}
	m = 2 * n - 1;
	// n+1-m号单元存放叶子结点，初始化
	for (i=n+1;i<=m;i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChlid = 0;
	}
	
	// 创建哈夫曼树
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
	
// 哈夫曼编码

void CrtHuffmanCode(HuffmanTree ht,HuffmanCode hc,int n)
{
	int i;
	char *cd;
	int start = 0;
	int p;
	int c = 0;
	cd = new char((n +1)* sizeof(char));   // 分配当前编码的工作空间
	cd[n - 1] = '\0';  // 从左到右逐位存放编码，首先存放编码结束符

	for (i=1;i<=n;i++)    // 求n个叶子结点的哈夫曼编码
	{
		start = n - 1;     // 初始化起始编码指针
		c = i; p = ht[i].parent;      // 从叶子结点开始向上倒推
		while (p!=NULL)
		{
			--start;  
			if (ht[i].LChild == c)
				cd[start] = '0';      // 做分支标0
 			else
				cd[start] = '1';      // 右分支标1
			c =p;p;   p = ht[p].parent;       // 向上倒推
		}

		//为第i个编码分配空间
		hc[i] = new char(sizeof(n - start)*(n - start));   
		strcpy(hc[i],&cd[start]);
	}
}

// 求哈夫曼树的带全路径长度

int GetHuffmanTreeWidgetPathLengt(HuffmanTree ht,int len)   // len初始化为0
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
	int weight;//节点的权值
	int parent;//双亲节点下标
	int LChild;//左节点下标
	int RChild;//右节点下标
}HTNode, HuffmanTree[M + 1];//0号单元不用
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
void PreOrder1(BiTree root)//非递归先序
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
//给先序和中序创建二叉树
char *PreArray = "abdfgceh"; //先序序列
char InArray[] = "bfdgaceh";//中序序列
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
		//创建先序对应的根节点
		root->data = PreArray[PreIndex];

		//找到该节点在中序序列中的位置，并将中序序列划分为左右两个子树
		//strchr(InArray,PreArray[PreIndex])返回的是该节点在中序序列中的地址
		int index = strchr(InArray, PreArray[PreIndex]) - InArray;
		//左子树的长度
		int LenF = index - InIndex;
		//创建左子树
		PreInCreateTree(root->lchild, PreIndex + 1, InIndex, LenF);
		//右子树的长度 = 总长度 - 左子树长度 - 一个根节点
		int LenR = subTreeLen - LenF - 1;
		//创建右子树，先序的字符位置从左子树和根节点后面开始，中序的位置从当前根节点后面的一个位置开始
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
	//1-n号单元存放叶子节点，初始化
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i - 1];
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	//n+1—m号单元存放非叶子节点，初始化
	m = 2 * n - 1;
	for (i = n + 1; i <= m; i++)
	{
		ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].LChild = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++)
	{//创建哈夫曼树
		select(ht, i - 1, &s1, &s2);//从0至（i-1）行中选最小的两个值
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
	cd = (char*)malloc((n + 1) * sizeof(char));//分配当前编码的工作空间
	cd[n - 1] = '\0';//从右向左逐位存放编码，首先存放编码结束符
	for (i = 1; i <= n; i++)
	{
		start = n - 1;//cd中的位置
		c = i;//第几个点
		p = ht[i].parent;
		while (p != 0)
		{
			--start;
			if (ht[p].LChild == c)
			{//左分支标0
				cd[start] = '0';
			}
			else
			{//右分支标1
				cd[start] = '1';
			}
			c = p;
			p = ht[p].parent;
		}
		//为第i个编码分配空间
		hc[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);//把编码复制到hc[i]里面
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