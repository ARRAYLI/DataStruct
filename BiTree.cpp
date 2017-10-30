#include<iostream>
#include<stack>
using namespace std;

// 定义树结构体

typedef struct _BiTree
{
	char data;    // 数据域
	struct _BiTree *Lchild;  // 左孩子结点指针
	struct _BiTree *Rchlid;  // 右孩子指针
}BiNode,*BiTree;

// 递归先序遍历二叉树

void PreOrder(BiTree root)
{
	if (NULL!=root)
	{
		cout << root->data<<" ";
		PreOrder(root->Lchild);
		PreOrder(root->Rchlid);
	}
}

// 递归中序遍历二叉树

void InOrder(BiTree root)
{
	if (NULL != root)
	{
		InOrder(root->Lchild);
		cout << root->data << " ";
		InOrder(root->Rchlid);
	}
}

// 递归后序遍历二叉树

void PostOrder(BiTree root)
{
	if (NULL!=root)
	{
		PostOrder(root->Lchild);
		PostOrder(root->Rchlid);
		cout << root->data<<" ";
	}
}

// 创建二叉树

void CreateBiTree(BiTree *root)
{
	char ch;
	cin >> ch;
	if (ch=='.')
	{
		*root = NULL;
	}
	else
	{
		*root = new BiNode;
		if (NULL==*root)
		{
			cout << "动态申请内存失败!" << endl;
			return;
		}
		(*root)->data = ch;
		CreateBiTree(&((*root)->Lchild));
		CreateBiTree(&((*root)->Rchlid));
	}
}

// 后序遍历求二叉树高度的递归算法

int PostTreeDepth(BiTree root)
{
	int hl = 0; // 求左子树的高度
	int hr = 0; // 求右子树的高度
	int max = 0; // 记录左右子树中最大的树的高度
	if (root == NULL)
	{
		return 0;
	}
	else 
	{

		hl = PostTreeDepth(root->Lchild);
		hr = PostTreeDepth(root->Rchlid);
		max = hl > hr ? hl : hr;
		return max + 1;
	}
}

// 非递归先序遍历二叉树

void PreOrder1(BiTree root)
{
	stack<BiNode*>s;   // 创建栈
	BiTree p = root;
//	BiTree q = NULL;
	while (p!=NULL||!s.empty())
	{
		if (p!=NULL)
		{
			cout << p ->data << "  ";
			s.push(p);
			p = p->Lchild;
		}
		else
		{
			p = s.top();  // 记录当前栈顶元素
			s.pop();  // 栈顶元素出栈
			p = p->Rchlid;
		}
	}
}

// 非递归中序遍历二叉树

void InOrder1(BiTree root)
{
	stack<BiNode*>s;
	BiNode *p = root;
//	BiNode *q = NULL;

	while (p != NULL | !s.empty())
	{
		if (NULL != p)
		{
			s.push(p);
			p = p->Lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data << "  ";
			p = p->Rchlid;
		}
	}
}

// 非递归后序遍历二叉树

void PostOrder1(BiTree root)
{
	stack<BiNode*>s;
	BiNode *p = root;
	BiNode *q = NULL;

	while (p!=NULL||!s.empty())
	{
		while (p!=NULL)
		{
			s.push(p);
			p = p->Lchild;
		}

		if (!s.empty())
		{
			p = s.top();
			if (p->Rchlid == NULL || p->Rchlid == q)
			{
				cout << p->data << "  ";
				s.pop();
				q = p;
				p = NULL;

			}
			else
			{
				p = p->Rchlid;
			}
		}
	}
}

int main(void)
{
	BiTree btree = NULL;
	CreateBiTree(&btree);
	PreOrder(btree);
	cout << endl;
	InOrder(btree);
	cout << endl;
	PostOrder(btree);
	cout << endl;

//	int n = PostTreeDepth(btree);
//	cout << n << endl;


	PreOrder1(btree);
	cout << endl;

	InOrder1(btree);
	cout << endl;

	PostOrder1(btree);
	cout << endl;

// AB.DF..G..C.E.H..
	return 0;
}