// ===================================================查找上课代码======================================================================

#define  HomeWork2
#ifdef  SearchClass

#include<iostream>
using namespace std;

#define MAXSIZE 20
//  顺序结构数据的定义
typedef struct
{
	int key;
}Record;

typedef struct
{
	int length;
	Record r[MAXSIZE + 1];
}RecordList;

// 二叉排序树的存储结构

typedef struct _BSTNode
{
	int key;   // 关键字的值；
	struct _BSTNode* lchild, *rchlid;  // 左右指针  
}BSTNode,*BSTree;

// 顺序表查找法
int SeqSearch(RecordList list,int key)
{
	int i = list.length;
	list.r[0].key = key;
	while (list.r[i].key!=key)
	{
		i--;
	}
	return i;
}

// 二分法查找

int InSearch(RecordList list,int key)
{
	int low, mid, high;
	low = 1;
	high = list.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (list.r[mid].key == key)
		{
			return key;
		}
		else if (list.r[mid].key > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid+1;
		}
	}
	return 0;
}

// 二叉排序树的插入递归算法

void  InsertBST(BSTree *bst, int key)    // 若在二叉排序树bst中不存在关键字等于key的元素，插入该元素
{
	BSTNode *s = NULL;
	if (*bst == NULL)    // 递归结束条件
	{
		s = new BSTNode;
		if (NULL == s)
		{
			cout << "动态申请内存失败!" << endl;
			return;
		}
		s->key = key;
		s->lchild = NULL;
		s->rchlid = NULL;
		*bst = s;
	}
	else if (key < (*bst)->key)
	{
		InsertBST(&(*bst)->lchild, key);    // 将s插入左子树
	}
	else
	{
		InsertBST(&(*bst)->rchlid, key);
	}
}

// 创建二叉排序树

void CreatBST(BSTree *bst)
{
	// 从键盘输入元素的值，创建相应的二叉排序树
	int key;
	*bst = NULL;
	cin >> key;
	while (key!=-1)
	{
		InsertBST(bst,key);   //在二叉排序树中插入结点key
		cin >> key;
	}
}

// 二叉排序树查找的递归算法

BSTree SearchBST(BSTree bst, int key)
{
	// 在根指针bst所指的二叉排序树中，递归查找某关键字等于key的元素，若查找成功返回指向关键字的指针；否则，返回NULL

	if (bst == NULL)
	{
		return NULL;
	}
	else if (bst->key == key)  // 如果查找成功返回当前指针
		return bst;
	else if (bst->key > key)
		SearchBST(bst->lchild, key);  // 在左子树继续查找
	else
		SearchBST(bst->rchlid,key);   // 在右子树继续查找
}

// 二叉排序树的非递归算法

BSTree SearchBST1(BSTree bst,int key)
{
	// 在根指针bst所指的二叉排序树bst上，查找关键字等于key的结点，若查找成功，返回指向该元素结点的指针；否则，返回空指针

	BSTree s=bst;
	while (s)
	{
		if (s->key == key)   // 查找成功
			return s;
		else if (s->key > key)  // 在左子树中查找
			s = s->lchild;
		else
			s = s->rchlid; // 在右子树中查找
	}
	return NULL;   // 查找失败
}

// 递归中序遍历算法

void InOrderBSTree(BSTree bst)
{
	if (bst!=NULL)
	{
		InOrderBSTree(bst->lchild);
		cout << bst->key<<"  ";
		InOrderBSTree(bst->rchlid);
	}
}

// 二叉排序树删结点算法

BSTNode* DelBST(BSTree bst,int key)
{
	// 在二叉排序树t中删除去关键字为k 的结点

	BSTNode *f, *s, *q, *p;
	p = bst;
	f = NULL;
	while (p)   // 查找关键字为k的结点p
	{
		if (p->key == key)   break;  // 找到则跳出
		f = p;      // f指向p结点的双亲结点
		if (p->key > key)  p = p->lchild;
		else
			p = p->rchlid;
	}
	if (p==NULL)  // 若找不到返回原来的二叉排序树
	{
		return bst;  
	}
	if (p->lchild==NULL)    // p无左子树
	{
		if (f == NULL)   // p是原来二叉树的根
		{
			bst = p->lchild;
		}
		else if (f->lchild == p)   // 将p的右子树连接到f的左链上
		{
			f->lchild = p->rchlid;
		}
		else
			f->rchlid = p->rchlid;     // 将p的右子树连接到f的右子树上
		delete p;
		p = NULL;
	}
	else     // p有左子树
	{
		q = p;
		s = p->lchild;
		while (s->rchlid)   // 在p的左子树中查找最右下角的点
		{
			q = s;
			s->rchlid;
		}
		if (q==p)
		{
			q->lchild = s->lchild;   // 将s的左子树连接到q上
		}
		else
		{
			q->rchlid = s->lchild;   // 将s的右子树连接到q上
		}
		p->key = s->key;
		delete s;
		s = NULL;
	}
	return bst;
}

int main(void)
{

//	RecordList list = { 10,0,6,1,9,3,5,4,7,8,2,11 };
//	int res;
////	res= SeqSearch(list, 5);
//
//	res = InSearch(list, 100);
//	if (res==0)
//	{
//		cout << "未找到!" << endl;
//	}
//	else
//	{
//		cout <<"30在第"<<res<<"个位置处" << endl;
//	}

	BSTree bst = NULL;
	CreatBST(&bst);
	InOrderBSTree(bst);
	cout << endl;

	BSTree temp = SearchBST(bst, 100);
	if (temp)
		cout << temp->key << endl;
	else
		cout << "未找到!" << endl;
	temp = DelBST(bst,100);
	InOrderBSTree(temp);

	// 20 10 30 90 50 -1
	return 0;
}

#endif // 

// ===================================================查找上课代码======================================================================


// ==================================================查找作业===========================================================================

#ifdef  HomeWork1

//  顺序查找、折半查找、二叉排序树的创建、查找、删除

#include<iostream>
using namespace std;
#define MAXSIZE 20

// 顺序查找数据存储结构

typedef struct
{
	int key;   // 要比较的关键字
}Record;

typedef struct
{
	int length;  
	Record r[MAXSIZE + 1];
}Recordlist;

//  二叉树链表存储结构

typedef struct _BSTNode
{
	int key;   // 要比较的关键字
	struct _BSTNode* lchild, *rchild;
}BSTNode,*BSTree;

// 顺序查找

int SeqSearch(Recordlist list ,int key)
{
	int i = list.length;
	list.r[0].key = key;
	while (list.r[i].key != key&&i >= 1)
	{
		i--;
	}
	if (i >= 1)
		return i;
	else
		return 0;
}

// 折半查找

int InSearch(Recordlist list,int key)
{
	int low = 1, high = list.length;
	int mid = 0;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (list.r[mid].key == key)
			return mid;
		else if (list.r[mid].key > key)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}

// 二叉排序树插入的递归算法

void InsertBST(BSTree *bst,int key)
{
	BSTree s;
	if (*bst==NULL)     // 递归结束条件
	{
		s = new BSTNode;
		if (s==NULL)
		{
			cout << "动态申请内存失败!" << endl;
			exit(0);
		}
		s->key = key;
		s->lchild = NULL;
		s->rchild = NULL;
		*bst = s;
	}
	else if ((*bst)->key<key)
		InsertBST(&((*bst)->rchild),key);
	else
		InsertBST(&(*bst)->lchild, key);
}

// 二叉树的创建

void CreateBSTree(BSTree *bst)
{
	int key = 0;
	cin >> key;
	while (key != -1)
	{
		InsertBST(bst,key);    // 在二叉排序树bst中插入结点key
		cin >> key;
	}
}

// 中序遍历二叉树

void InOrderBST(BSTree bst)
{
	if (bst!=NULL)
	{
		InOrderBST(bst->lchild);
		cout << bst->key<<" ";
		InOrderBST(bst->rchild);
	}
}

// 二叉排序树的查找递归算法

BSTNode* SearchBST(BSTree bst, int key)
{
	if (bst == NULL)    // 递归结束条件
		return NULL;
	else if (bst->key == key)
		return bst;
	else if (bst->key > key)
		SearchBST(bst->lchild, key);
	else
		SearchBST(bst->rchild,key);
}

// 二叉排序树的查找非递归算法

BSTNode *SearchBST1(BSTree bst,int key)
{
	while (bst)
	{
		if (bst->key == key)
			break;
		else if (bst->key > key)
			bst = bst->lchild;
		else
			bst = bst->rchild;
	}
	return bst;
}

// 二叉排序树的删除算法

BSTNode *DelBST(BSTree bst,int key)
{
	BSTNode *p = bst, *q=NULL, *f = NULL, *s = NULL;
	while(p)     // 查找关键字k的待删结点p
	{
		if (p->key == key)
			break;
		f = p;
		 if (p->key > key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (NULL == p)                            // 如果没有找到，则返回根结点 
		return bst;
	if (p->lchild==NULL)                      // p无左孩子
	{
		if (f == NULL)						  // p是原二叉排序树的根     
			bst = p->lchild;
	                             // f指向双亲的结点
		if (f->lchild == p)			          // p是f的左孩子  
			f->lchild= p->rchild;        
		else								  // p是f的右孩子
			f->rchild = p->rchild;			  // 将p的右子树连接到f的右孩子上
		delete p;							  // 释放被删除的p结点 
		p = NULL;						      
	}
	else									  // p有左子树
	{
		q = p;
		s = p->lchild;
		while (s->rchild)					  // 在p的左子树中查找最右下角的结点
		{
			q = s;
			s = s->rchild;
		}
		if (q == p)
			q->lchild = s->lchild;            // 将s的左子树连接到q上
		else
			q->rchild = s->lchild;            
		
		p->key = s->key;                      // 将s的值赋值给p
		delete s;
		s = NULL;
	}
	return bst;
}

int main(void)
{
	Recordlist list = { 10,0,5,9,8,3,7,6,4,1,2,0 };
	int res = SeqSearch(list,100);
	if (!res)
		cout << "没有找到!" << endl;
	else
		cout << "它在第" << res << "位置处"<< endl;



	Recordlist l = { 10,0,1,2,3,4,5,6,7,8,9 };
	int res = InSearch(l,9);
	if (!res)
		cout << "没有找到!" << endl;
	else
		cout << "它在第" << res+1 << "位置处" << endl;
	
	BSTree bst = NULL;
	CreateBSTree(&bst);
	InOrderBST(bst);
	cout << endl;
	BSTree t = SearchBST1(bst,30);
	if (t)
		cout << t->key << endl;
	else
		cout << "没找到!" << endl;

	t=DelBST(bst,5);
	InOrderBST(t);
	cout << endl;
	// 5 3 7 6 4 -1
	return 0;
}

#endif //  HomeWork

// ==================================================查找作业===========================================================================



//  ================================================================平衡二叉树排序树的插入====================================================

//  平衡二叉树四种旋转  

#include<iostream>
using namespace std;

// 平衡二叉排序树的数据存储结构

typedef struct _AVLTNode
{
	int key;   //关键字
	int bf;    // 平衡因子
	struct _AVLTNode *lchild, *rchild;
}AVLTNode,*AVLTree;

// 二叉排序树的插入结点算法
void InsertAVLTree(AVLTree *root, int key)
{
	AVLTNode *s, *p, *fp, *A, *FA, *B, *C;
	s = (AVLTNode*)malloc(sizeof(AVLTNode));
	s->key = key;
	s->lchild = NULL;
	s->rchild = NULL;
	s->bf = 0;
	if (*root == NULL)
	{
		*root = s;
	}
	else
	{
		//查找合适的插入位置
		p = *root;
		fp = NULL;
		A = *root;
		FA = NULL;
		while (p != NULL)
		{
			if (p->bf != 0)//可能存在的失衡点
			{
				A = p;
				FA = fp;
			}

			if (key < p->key)
			{
				fp = p;
				p = p->lchild;
			}
			else if (key>p->key)
			{
				fp = p;
				p = p->rchild;
			}
			else
			{
				return;//遇到相同的节点的时候不添加
			}
		}
		if (key < fp->key)
		{
			fp->lchild = s;
		}
		else
		{
			fp->rchild = s;
		}
		//修改A的平衡因子
		if (key < A->key)
		{
			B = A->lchild;
			A->bf += 1;
		}
		else
		{
			B = A->rchild;
			A->bf -= 1;
		}
		//沿着B继续修改平衡因子
		p = B;
		while (p != s)
		{
			if (key < p->key)
			{
				p->bf = 1;
				p = p->lchild;
			}
			else
			{
				p->bf = -1;
				p = p->rchild;
			}
		}
		if (A->bf == 2 && B->bf == 1)//LL
		{
			B = A->lchild;
			A->lchild = B->rchild;
			B->rchild = A;
			A->bf = 0;
			B->bf = 0;
			if (FA == NULL)
			{
				*root = B;
			}
			else
			{
				if (A == FA->lchild)
				{
					FA->lchild = B;
				}
				else
				{
					FA->rchild = B;
				}
			}
		}
		else if (A->bf == -2 && B->bf == -1)//RR
		{
			B = A->rchild;
			A->rchild = B->lchild;
			B->lchild = A;
			A->bf = 0;
			B->bf = 0;
			if (FA == NULL)
			{
				*root = B;
			}
			else
			{
				if (A == FA->lchild)
				{
					FA->lchild = B;
				}
				else
				{
					FA->rchild = B;
				}
			}
		}
		else if (A->bf == 2 && B->bf == -1)//LR
		{
			B = A->lchild;
			C = B->rchild;
			B->rchild = C->lchild;
			A->lchild = C->rchild;
			C->lchild = B;
			C->rchild = A;
			if (key < C->key)
			{
				A->bf = -1;
				B->bf = 0;
				C->bf = 0;
			}
			else
			{
				A->bf = 0;
				B->bf = 1;
				C->bf = 0;
			}
			if (FA == NULL)
			{
				*root = C;
			}
			else
			{
				if (A == FA->lchild)
				{
					FA->lchild = C;
				}
				else
				{
					FA->rchild = C;
				}
			}
		}
		else if (A->bf == -2 && B->bf == 1)//RL
		{
			B = A->rchild;
			C = B->lchild;
			A->rchild = C->lchild;
			B->lchild = C->rchild;
			C->lchild = A;
			C->rchild = B;
			if (key < C->key)
			{
				A->bf = 0;
				B->bf = -1;
				C->bf = 0;
			}
			else
			{
				A->bf = 1;
				B->bf = 0;
				C->bf = 0;
			}
			if (FA == NULL)
			{
				*root = C;
			}
			else
			{
				if (A == FA->lchild)
				{
					FA->lchild = C;
				}
				else
				{
					FA->rchild = C;
				}
			}
		}
	}
}

// 中序遍历二叉排序树

void InOrderAVL(AVLTree root)
{
	if (root!=NULL)
	{
		InOrderAVL(root->lchild);
		cout << root->key << "  ";
		InOrderAVL(root->rchild);
	}
}

// 判断一棵二叉排序树是平衡二叉树
int Depth(AVLTree root)
{
	return 1;
}

// 判断一棵二叉排序树是平衡二叉树

bool isAVLTree(AVLTree root)
{
	if (root==NULL)
	{
		return 1;
	}
	else
	{
		int hl = Depth(root->lchild);
		int hr = Depth(root->rchild);

		if (hl-hr<-1||hl-hr>1)
		{
			return 0;
		}
		else
		{
			// 判断root的左子树和右子树是否是平衡二叉树
			return (isAVLTree(root->lchild) && isAVLTree(root->rchild));
		}
	}

}

int main(void)
{
	AVLTree root=NULL;

	for(int i=1;i<=7;i++)
	 InsertAVLTree(&root, i);


	InOrderAVL(root);
	cout << endl;
	return 0;
}

//  ================================================================平衡二叉树的插入====================================================