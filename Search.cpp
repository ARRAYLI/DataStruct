// ===================================================�����Ͽδ���======================================================================

#define  HomeWork2
#ifdef  SearchClass

#include<iostream>
using namespace std;

#define MAXSIZE 20
//  ˳��ṹ���ݵĶ���
typedef struct
{
	int key;
}Record;

typedef struct
{
	int length;
	Record r[MAXSIZE + 1];
}RecordList;

// �����������Ĵ洢�ṹ

typedef struct _BSTNode
{
	int key;   // �ؼ��ֵ�ֵ��
	struct _BSTNode* lchild, *rchlid;  // ����ָ��  
}BSTNode,*BSTree;

// ˳�����ҷ�
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

// ���ַ�����

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

// �����������Ĳ���ݹ��㷨

void  InsertBST(BSTree *bst, int key)    // ���ڶ���������bst�в����ڹؼ��ֵ���key��Ԫ�أ������Ԫ��
{
	BSTNode *s = NULL;
	if (*bst == NULL)    // �ݹ��������
	{
		s = new BSTNode;
		if (NULL == s)
		{
			cout << "��̬�����ڴ�ʧ��!" << endl;
			return;
		}
		s->key = key;
		s->lchild = NULL;
		s->rchlid = NULL;
		*bst = s;
	}
	else if (key < (*bst)->key)
	{
		InsertBST(&(*bst)->lchild, key);    // ��s����������
	}
	else
	{
		InsertBST(&(*bst)->rchlid, key);
	}
}

// ��������������

void CreatBST(BSTree *bst)
{
	// �Ӽ�������Ԫ�ص�ֵ��������Ӧ�Ķ���������
	int key;
	*bst = NULL;
	cin >> key;
	while (key!=-1)
	{
		InsertBST(bst,key);   //�ڶ����������в�����key
		cin >> key;
	}
}

// �������������ҵĵݹ��㷨

BSTree SearchBST(BSTree bst, int key)
{
	// �ڸ�ָ��bst��ָ�Ķ����������У��ݹ����ĳ�ؼ��ֵ���key��Ԫ�أ������ҳɹ�����ָ��ؼ��ֵ�ָ�룻���򣬷���NULL

	if (bst == NULL)
	{
		return NULL;
	}
	else if (bst->key == key)  // ������ҳɹ����ص�ǰָ��
		return bst;
	else if (bst->key > key)
		SearchBST(bst->lchild, key);  // ����������������
	else
		SearchBST(bst->rchlid,key);   // ����������������
}

// �����������ķǵݹ��㷨

BSTree SearchBST1(BSTree bst,int key)
{
	// �ڸ�ָ��bst��ָ�Ķ���������bst�ϣ����ҹؼ��ֵ���key�Ľ�㣬�����ҳɹ�������ָ���Ԫ�ؽ���ָ�룻���򣬷��ؿ�ָ��

	BSTree s=bst;
	while (s)
	{
		if (s->key == key)   // ���ҳɹ�
			return s;
		else if (s->key > key)  // ���������в���
			s = s->lchild;
		else
			s = s->rchlid; // ���������в���
	}
	return NULL;   // ����ʧ��
}

// �ݹ���������㷨

void InOrderBSTree(BSTree bst)
{
	if (bst!=NULL)
	{
		InOrderBSTree(bst->lchild);
		cout << bst->key<<"  ";
		InOrderBSTree(bst->rchlid);
	}
}

// ����������ɾ����㷨

BSTNode* DelBST(BSTree bst,int key)
{
	// �ڶ���������t��ɾ��ȥ�ؼ���Ϊk �Ľ��

	BSTNode *f, *s, *q, *p;
	p = bst;
	f = NULL;
	while (p)   // ���ҹؼ���Ϊk�Ľ��p
	{
		if (p->key == key)   break;  // �ҵ�������
		f = p;      // fָ��p����˫�׽��
		if (p->key > key)  p = p->lchild;
		else
			p = p->rchlid;
	}
	if (p==NULL)  // ���Ҳ�������ԭ���Ķ���������
	{
		return bst;  
	}
	if (p->lchild==NULL)    // p��������
	{
		if (f == NULL)   // p��ԭ���������ĸ�
		{
			bst = p->lchild;
		}
		else if (f->lchild == p)   // ��p�����������ӵ�f��������
		{
			f->lchild = p->rchlid;
		}
		else
			f->rchlid = p->rchlid;     // ��p�����������ӵ�f����������
		delete p;
		p = NULL;
	}
	else     // p��������
	{
		q = p;
		s = p->lchild;
		while (s->rchlid)   // ��p���������в��������½ǵĵ�
		{
			q = s;
			s->rchlid;
		}
		if (q==p)
		{
			q->lchild = s->lchild;   // ��s�����������ӵ�q��
		}
		else
		{
			q->rchlid = s->lchild;   // ��s�����������ӵ�q��
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
//		cout << "δ�ҵ�!" << endl;
//	}
//	else
//	{
//		cout <<"30�ڵ�"<<res<<"��λ�ô�" << endl;
//	}

	BSTree bst = NULL;
	CreatBST(&bst);
	InOrderBSTree(bst);
	cout << endl;

	BSTree temp = SearchBST(bst, 100);
	if (temp)
		cout << temp->key << endl;
	else
		cout << "δ�ҵ�!" << endl;
	temp = DelBST(bst,100);
	InOrderBSTree(temp);

	// 20 10 30 90 50 -1
	return 0;
}

#endif // 

// ===================================================�����Ͽδ���======================================================================


// ==================================================������ҵ===========================================================================

#ifdef  HomeWork1

//  ˳����ҡ��۰���ҡ������������Ĵ��������ҡ�ɾ��

#include<iostream>
using namespace std;
#define MAXSIZE 20

// ˳��������ݴ洢�ṹ

typedef struct
{
	int key;   // Ҫ�ȽϵĹؼ���
}Record;

typedef struct
{
	int length;  
	Record r[MAXSIZE + 1];
}Recordlist;

//  ����������洢�ṹ

typedef struct _BSTNode
{
	int key;   // Ҫ�ȽϵĹؼ���
	struct _BSTNode* lchild, *rchild;
}BSTNode,*BSTree;

// ˳�����

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

// �۰����

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

// ��������������ĵݹ��㷨

void InsertBST(BSTree *bst,int key)
{
	BSTree s;
	if (*bst==NULL)     // �ݹ��������
	{
		s = new BSTNode;
		if (s==NULL)
		{
			cout << "��̬�����ڴ�ʧ��!" << endl;
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

// �������Ĵ���

void CreateBSTree(BSTree *bst)
{
	int key = 0;
	cin >> key;
	while (key != -1)
	{
		InsertBST(bst,key);    // �ڶ���������bst�в�����key
		cin >> key;
	}
}

// �������������

void InOrderBST(BSTree bst)
{
	if (bst!=NULL)
	{
		InOrderBST(bst->lchild);
		cout << bst->key<<" ";
		InOrderBST(bst->rchild);
	}
}

// �����������Ĳ��ҵݹ��㷨

BSTNode* SearchBST(BSTree bst, int key)
{
	if (bst == NULL)    // �ݹ��������
		return NULL;
	else if (bst->key == key)
		return bst;
	else if (bst->key > key)
		SearchBST(bst->lchild, key);
	else
		SearchBST(bst->rchild,key);
}

// �����������Ĳ��ҷǵݹ��㷨

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

// ������������ɾ���㷨

BSTNode *DelBST(BSTree bst,int key)
{
	BSTNode *p = bst, *q=NULL, *f = NULL, *s = NULL;
	while(p)     // ���ҹؼ���k�Ĵ�ɾ���p
	{
		if (p->key == key)
			break;
		f = p;
		 if (p->key > key)
			p = p->lchild;
		else
			p = p->rchild;
	}

	if (NULL == p)                            // ���û���ҵ����򷵻ظ���� 
		return bst;
	if (p->lchild==NULL)                      // p������
	{
		if (f == NULL)						  // p��ԭ�����������ĸ�     
			bst = p->lchild;
	                             // fָ��˫�׵Ľ��
		if (f->lchild == p)			          // p��f������  
			f->lchild= p->rchild;        
		else								  // p��f���Һ���
			f->rchild = p->rchild;			  // ��p�����������ӵ�f���Һ�����
		delete p;							  // �ͷű�ɾ����p��� 
		p = NULL;						      
	}
	else									  // p��������
	{
		q = p;
		s = p->lchild;
		while (s->rchild)					  // ��p���������в��������½ǵĽ��
		{
			q = s;
			s = s->rchild;
		}
		if (q == p)
			q->lchild = s->lchild;            // ��s�����������ӵ�q��
		else
			q->rchild = s->lchild;            
		
		p->key = s->key;                      // ��s��ֵ��ֵ��p
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
		cout << "û���ҵ�!" << endl;
	else
		cout << "���ڵ�" << res << "λ�ô�"<< endl;



	Recordlist l = { 10,0,1,2,3,4,5,6,7,8,9 };
	int res = InSearch(l,9);
	if (!res)
		cout << "û���ҵ�!" << endl;
	else
		cout << "���ڵ�" << res+1 << "λ�ô�" << endl;
	
	BSTree bst = NULL;
	CreateBSTree(&bst);
	InOrderBST(bst);
	cout << endl;
	BSTree t = SearchBST1(bst,30);
	if (t)
		cout << t->key << endl;
	else
		cout << "û�ҵ�!" << endl;

	t=DelBST(bst,5);
	InOrderBST(t);
	cout << endl;
	// 5 3 7 6 4 -1
	return 0;
}

#endif //  HomeWork

// ==================================================������ҵ===========================================================================



//  ================================================================ƽ��������������Ĳ���====================================================

//  ƽ�������������ת  

#include<iostream>
using namespace std;

// ƽ����������������ݴ洢�ṹ

typedef struct _AVLTNode
{
	int key;   //�ؼ���
	int bf;    // ƽ������
	struct _AVLTNode *lchild, *rchild;
}AVLTNode,*AVLTree;

// �����������Ĳ������㷨
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
		//���Һ��ʵĲ���λ��
		p = *root;
		fp = NULL;
		A = *root;
		FA = NULL;
		while (p != NULL)
		{
			if (p->bf != 0)//���ܴ��ڵ�ʧ���
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
				return;//������ͬ�Ľڵ��ʱ�����
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
		//�޸�A��ƽ������
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
		//����B�����޸�ƽ������
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

// �����������������

void InOrderAVL(AVLTree root)
{
	if (root!=NULL)
	{
		InOrderAVL(root->lchild);
		cout << root->key << "  ";
		InOrderAVL(root->rchild);
	}
}

// �ж�һ�ö�����������ƽ�������
int Depth(AVLTree root)
{
	return 1;
}

// �ж�һ�ö�����������ƽ�������

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
			// �ж�root�����������������Ƿ���ƽ�������
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

//  ================================================================ƽ��������Ĳ���====================================================