// =================================================ͼ================================================================
#if 0
#include<iostream>
#include<queue>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	int adj;		// ������Ȩͼ����0��1��ʾ�Ƿ����ڣ��Դ�Ȩͼ����ΪȨֵ����
	// �˴����Զ������ͼ�бߵĻ�����Ϣ
}ArcNode;

typedef struct
{
	char Vertex[MAXSIZE];				// ��������
	ArcNode arcs[MAXSIZE][MAXSIZE];		// �ڽӾ���
	int vexnum;							// �������
	int arcnum;							// �߸���
}AdjMatrix;								// ��Ӿ���

//	=========================

typedef struct Node
{
	int adj;			//	��Ӧ�Ķ����±�
	int weight;			//  �ߵ�Ȩֵ
	struct Node* nextarc;	
}ArcNode2;

typedef struct
{
	char vertexdata;		// ��������
	ArcNode2 *firstArc;		// ��һ����
}VertexType;

typedef struct
{
	VertexType vertex[MAXSIZE];		// ͼ���ڽӱ�
	int vexnum;						// �߸���
	int arcnum;						// �������
}AdjList;

//	=== ͼ���ڽӾ��󴴽���

int LocateAdj(AdjMatrix *G,char v)
{
	int i;
	for (i=0;i<G->vexnum;i++)
	{
		if (G->Vertex[i]==v)
		{
			return i;
		}
	}
	return -1;
}

void CreatAdj(AdjMatrix *G)				// ��Ӿ��󴴽�����ͼ
{
	int i, j, k;
	char v1, v2;

	//  ���붥������ͱ߸���
	cout << "���붥������ͱ߸���:" << endl;
	cin >> G->vexnum >> G->arcnum;

	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = 0;
		}
	}

	// ���붥��
	cout << "���붥�㣺"<<endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->Vertex[i];
	}

	// �����
	cout << "����ߣ�"<<endl;
	for (k=0;k<G->arcnum;k++)
	{
		fflush(stdin);
		cin >> v1 >> v2;
		i = LocateAdj(G,v1);
		j = LocateAdj(G,v2);
		if (i!=-1&&j!=-1)
		{
			G->arcs[i][j].adj = 1;
		}
	}
}

//	=== ͼ���ڽӱ�����

int LocateAdjList(AdjList *G,char v)
{
	int i;
	for (i=0;i<G->arcnum;i++)
	{
		if (G->vertex[i].vertexdata==v)
		{
			return i;
		}
	}
	return -1;
}

void CreatAdjList(AdjList *G)
{
	int i, j, k;
	ArcNode2 *s;
	char v1, v2;

	// ���붥������ͱ߸���
	cout << "���붥������ͱ߸���:" << endl;
	cin >> G->vexnum >> G->arcnum;
	// ���붥���ͬʱ����ʼ��
	cout << "���붥�㣺" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->vertex[i].vertexdata;
		G->vertex[i].firstArc = NULL;
	}
	// �����
	cout << "�����: " << endl;
	for (k=0;k<G->arcnum;k++)
	{
	///	fflush(stdin);
		cin >> v1 >> v2;
		i = LocateAdjList(G,v1);
		j = LocateAdjList(G,v2);
		if (i!=-1&&j!=-1)
		{
			s = new ArcNode2;
			if (NULL==s)
			{	
				cout << "��̬�����ڴ�ʧ��!" <<endl;
				return;
			}
			s->adj = j;
			s->nextarc = G->vertex[i].firstArc;
			G->vertex[i].firstArc = s;
		}
	}
}

// ͼ���ڽӱ��������ȱ���

int visited[MAXSIZE];
void DFS(AdjList G,int v0)
{
	cout << G.vertex[v0].vertexdata << " ";
	visited[v0] = 1;
	ArcNode2 *p;
	p = G.vertex[v0].firstArc;
	while (p != NULL)
	{
		// ��firstarc��DFS
		if (visited[p->adj] != 1)
		{
			DFS(G, p->adj);
		}
		// �ҵ���һ����nextarc��DFS
		p = p->nextarc;
	}
}

void TravelDFS(AdjList G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=1)
		{
			DFS(G,i);
		}
	}
	cout << endl;
}

// ͼ���ڽӾ����������ȱ���

void DFSMatx(AdjMatrix G,int v0)
{
	cout << G.Vertex[v0] << "  ";
	visited[v0] = 1;
	int j;
	for (j = 0; j<G.vexnum; j++)
	{
		if (G.arcs[v0][j].adj == 1)
		{
			if (visited[j] != 1)
			{
				DFSMatx(G, j);
			}
		}
	}
}

void TravelMatxDFS(AdjMatrix G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=1)
		{
			DFSMatx(G,i);
		}
	}

	cout <<endl;
}

// ͼ�Ĺ����������

void BFS(AdjList G,int v0)
{
	queue<int>Q;
	int v;
	ArcNode2 *p=NULL;
	Q.push(v0);
	cout << G.vertex[v0].vertexdata << "  ";
	visited[v0] = 1;
	while (!Q.empty())
	{
		v = Q.front();
		Q.pop();
		p = G.vertex[v].firstArc;
		while (p!=NULL)
		{
			if (visited[p->adj]!=1)
			{
				Q.push(p->adj);
				cout << G.vertex[p->adj].vertexdata << " ";
				visited[p->adj] = 1;
			}
			p = p->nextarc;
		}
	}
}

void TravelBFS(AdjList G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=1)
		{
			BFS(G,i);
		}
	}
	cout << endl;
}

int main(void)
{
	/*AdjMatrix G;
	CreatAdj(&G);
	int i, j;
	cout << "ͼ���ڽӾݾ�����ǣ�" << endl;
	for (i=0;i<G.vexnum;i++)
	{
		for (j=0;j<G.vexnum;j++)
		{
			cout << G.arcs[i][j].adj << "  ";
		}
		cout << endl;
	}
	cout << "ͼ���ڽӾ���������ȱ����Ľ����:" << endl;
	TravelMatxDFS(G);
*/
	AdjList G1;
	int i;
	CreatAdjList(&G1);
	ArcNode2 *pp=NULL;
	cout << "ͼ���ڽӱ�ı��������:" << endl;
	for (i=0;i<G1.vexnum;i++)
	{
		cout << G1.vertex[i].vertexdata << " ";
		pp = G1.vertex[i].firstArc;
		while (pp)
		{
			cout << pp->adj << "  ";
			pp = pp->nextarc;
		}
		cout << endl;
	}
//	TravelDFS(G1);
	TravelBFS(G1);
	return 0;
}
#endif

// ����ĸ�㷨
#if 0
#include<iostream>
using namespace std;

#define MAX_VERTEX_NUM 20
#define INFINITY    32768
#define ERROR		-1

typedef enum {DG,DN,UDG,UDN}GraphKind;

typedef char VertexData;
typedef char OtherInfo;
typedef int AdjType;

typedef struct
{
	AdjType adj;
	OtherInfo info;
}ArcNode;

typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum, arcnum;	
	GraphKind kind;
}AdjMatrix;				// �ڽӾ���

typedef struct
{
	VertexData adjvex;
	int lowcost;
}Closedge;				// ����С������

int LocateVex(AdjMatrix *G,VertexData v)
{
	int j = ERROR;
	int k;
	for (k=0;k<G->vexnum;k++)
	{
		if (v==G->vertex[k])
		{
			j = k;
			break;
		}
	}
	return j;
}

void CreatUDN(AdjMatrix *G)		//	����һ����Ȩ����ͼ
{
	int i, j, k, weight;
	VertexData v1, v2;
	cout << "���붥����������:" << endl;
	cin >> G->vexnum >> G->arcnum;
	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	cout << "���붥�㣺" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->vertex[i];
	}
	cout << "�����(a b 1):" << endl;
	for (k=0;k<G->arcnum;k++)
	{
		fflush(stdin);
		cin >> v1 >> v2 >> weight;
	}
	i = LocateVex(G,v1);
	j = LocateVex(G,v2);
	if (i!=ERROR&&j!=ERROR)
	{
		G->arcs[i][j].adj = weight;
		G->arcs[j][i].adj = weight;
	}
}

void printAdjMatrx(AdjMatrix G)
{
	int i, j;
	for (i=0;i<G.vexnum;i++)
	{	
		for (j=0;j<G.vexnum;j++)
		{
			if (G.arcs[i][j].adj==INFINITY)
			{
				cout << "&  ";
			}
			else
			{
				cout << G.arcs[i][j].adj << "  ";
			}
		}
		cout << endl;
	}
}

// ======================����ķ�㷨===========================

int Minium(Closedge closedge[],int L)
{
	int i;
	int k = -1;
	int min = INFINITY;
	for (i=0;i<L;i++)
	{
		if (closedge[i].lowcost>0&&closedge[i].lowcost<min)
		{
			min = closedge[i].lowcost;
			k = i;
		}
	}
	return k;
}

void MiniSpanTree_Prim(AdjMatrix G,VertexData u)
{
	// �Ӷ���u������������ķ�㷨������ͨ��G����С���������������������ÿ����
	int k;
	int k0;
	int i, e;
	VertexData u0, v0;
	Closedge closedge[MAX_VERTEX_NUM];

	k = LocateVex(&G,u);
	closedge[k].lowcost = 0;		// ��ʼ��U={u}
	for (i=0;i<G.vexnum;i++)
	{
		if (i!=k)
		{
			closedge[i].adjvex = u;
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
	}
	for (e=1;e<G.vexnum;e++)		//	�ҵ�n-1����
	{
		k0 = Minium(closedge,G.vexnum);	//closedge[k0]�д��е�ǰ��С��(U0,v0)����Ϣ
		u0 = closedge[k0].adjvex;		// u0����U	
		v0 = G.vertex[k0];				// v0����V-U
		cout <<"("<<u0 <<"," <<v0 << ") ";	//	�����������ǰ��С�ߣ�u0,v0��
		closedge[k0].lowcost = 0;		// �ڶ���v0����U֮�󣬸���closedge[i]
		for (i=0;i<G.vexnum;i++)
		{
			// ����±ߵ�Ȩֵ��closedge[v].lowcostС����closedge[i].lowcost����Ϊ�±ߵ�Ȩֵ
			if (G.arcs[k0][i].adj<closedge[i].lowcost)
			{
				closedge[i].lowcost = G.arcs[k0][i].adj;
				closedge[i].adjvex = v0;
			}
		}
	}
}


int main(void)
{
	AdjMatrix G;
	CreatUDN(&G);
	printAdjMatrx(G);
	MiniSpanTree_Prim(G,G.vertex[0]);
	getchar();
	getchar();
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_VERTEX_NUM  20
#define INFINITY        32768
#define ERROR           -1

typedef enum { DG, DN, UDG, UDN } GraphKind;
typedef char VertexData;
typedef char OtherInfo;
typedef int  AdjType;

typedef struct
{
	AdjType adj;
	OtherInfo info;
}ArcNode;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];
	ArcNode    arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int        vexnum, arcnum;
	GraphKind  kind;
}AdjMatrix;                         //�ڽӾ���
typedef struct
{
	VertexData adjvex;
	int lowcost;
}Closedge;                          //����С������

int LocateVex(AdjMatrix *G, VertexData v)
{
	int j = ERROR;
	int k;
	for (k = 0; k<G->vexnum; k++)
	{
		if (v == G->vertex[k])
		{
			j = k;
			break;
		}
	}
	return j;
}

void GreatUDN(AdjMatrix *G)         //����һ�������Ȩͼ
{
	int i, j, k, weight;
	VertexData v1, v2;
	printf("���붥������������\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i<G->vexnum; i++)
	{
		for (j = 0; j<G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	printf("���붥�㣺\n");
	fflush(stdin);
	for (i = 0; i<G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
	}
	printf("����ߣ�a b 1����\n");
	for (k = 0; k<G->arcnum; k++)
	{
		fflush(stdin);
		scanf("%c %c %d", &v1, &v2, &weight);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (i != ERROR && j != ERROR)
		{
			G->arcs[i][j].adj = weight;
			G->arcs[j][i].adj = weight;
		}
	}
}
void printAdjMatrx(AdjMatrix G)
{
	int i, j;
	for (i = 0; i<G.vexnum; i++)
	{
		for (j = 0; j<G.vexnum; j++)
		{
			if (G.arcs[i][j].adj == INFINITY)
			{
				printf("��   ");
			}
			else
			{
				printf(" %d   ", G.arcs[i][j].adj);
			}
		}
		printf("\n");
	}
}
//===================����ķ�㷨====================
int Minium(Closedge closedge[], int L)
{
	int i;
	int k = -1;
	int min = INFINITY;
	for (i = 0; i<L; i++)
	{
		if (closedge[i].lowcost>0 && closedge[i].lowcost<min)
		{
			min = closedge[i].lowcost;
			k = i;
		}
	}
	return k;
}
void MiniSpanTree_Prim(AdjMatrix G, VertexData u)
{
	//�Ӷ���u������������ķ�㷨������ͨ��G����С���������������������ÿ����
	int k;
	int k0;
	int i, e;
	VertexData u0, v0;
	Closedge closedge[MAX_VERTEX_NUM];

	k = LocateVex(&G, u);
	closedge[k].lowcost = 0;		//��ʼ����U={u}
	for (i = 0; i<G.vexnum; i++)
	{
		if (i != k)				//��V-U�еĶ���i����ʼ��closedge[i]
		{
			closedge[i].adjvex = u;
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
	}
	for (e = 1; e<G.vexnum; e++)		//��n-1���ߣ�n = G.vexnum��
	{
		k0 = Minium(closedge, G.vexnum);//closedge[k0]�д��е�ǰ��С��(u0 , v0)����Ϣ
		u0 = closedge[k0].adjvex;		 //u0����U
		v0 = G.vertex[k0];             //v0����V-U
		printf("(%c,%c) ", u0, v0);    //����������ĵ�ǰ��С��(u0 , v0)
		closedge[k0].lowcost = 0;		 //������v0����U����
		for (i = 0; i<G.vexnum; i++)		 //�ڶ���v0����U֮�󣬸���closedge[i]
		{
			if (G.arcs[k0][i].adj<closedge[i].lowcost)
				//����±ߵ�Ȩֵ��closedge[v].lowcostС����closedge[i].lowcost����Ϊ�±ߵ�Ȩֵ
			{
				closedge[i].lowcost = G.arcs[k0][i].adj;
				closedge[i].adjvex = v0;
			}
		}
	}
}

int main(void)
{
	AdjMatrix G;
	GreatUDN(&G);
	printAdjMatrx(G);
	MiniSpanTree_Prim(G, G.vertex[0]);
	getchar();
	getchar();
	return 0;
}


/*
���붥������������
6
10
G->vexnum=6,G->arcnum=10
���붥�㣺
abcdef
����ߣ�a b 1����
a b 6
a c 1
a d 5
b c 5
b e 3
e c 6
e f 6
c f 4
f d 2
c d 5
��    6    1    5   ��   ��
6   ��    5   ��    3   ��
1    5   ��    5    6    4
5   ��    5   ��   ��    2
��    3    6   ��   ��    6
��   ��    4    2    6   ��
(a,c) (c,f) (f,d) (c,b) (b,e)
*/
#endif

#if 0
#include<stdio.h>
#include<malloc.h>
#include<algorithm>
//��³˹����(kruskal)�㷨--��С������
typedef struct Edge
{
	int v;
	int u;
	int w;
}edge;

typedef struct
{
	int nv;   //������
	int num;  //����
			  //edge *e;
	edge e[10];
}Graph;

/*�� ���� void qsort(void *base,int nelem,int width,int (*fcmp)(const void *,const void *));
������ 1 �����������׵�ַ
2 �����д�����Ԫ������
3 ��Ԫ�ص�ռ�ÿռ��С
4 ָ������ָ�룬����ȷ�������˳��*/
int cmp(const void *a, const void *b) //����������  
{
	edge * x = (edge *)a;
	edge * y = (edge *)b;
	return (x->w) - (y->w);
}
void kruskal(Graph *g)
{
	int *x = (int *)malloc(sizeof(int)*g->num);//�����ڼ���
	int i, m, n, c = 0;
	for (i = 0; i < g->nv; i++)
	{
		x[i] = i;
	}
	qsort(g->e, g->num, sizeof(edge), cmp);
	for (i = 0; i<g->num&&c<g->nv; i++)
	{
		//�жϱߵ������Ƿ���ͬһ������
		for (m = g->e[i].v; m != x[m]; m = x[m])
			x[m] = x[x[m]];
		for (n = g->e[i].u; n != x[n]; n = x[n])
			x[n] = x[x[n]];
		if (m != n)
		{
			x[m] = n;
			c++;
			printf("(%d,%d)->%d\n", g->e[i].v, g->e[i].u, g->e[i].w);
		}
	}
}

void main_kruskal()
{
	Graph g = { 6, 10, 0, 1, 6, 0, 2, 1, 0, 3, 5, 1, 2, 5, 1,4, 3, 2, 3, 5, 2, 4, 6, 2, 5, 4,3, 5, 2, 4, 5, 6 };

	kruskal(&g);

}

int main(void)
{
	main_kruskal();
	return 0;
}
#endif

// ���������㷨

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#define Null 0
#define MAX 20

typedef struct ArcNode
{
	int adjvex;
	int weight;
	struct ArcNode *nextarc;
}ArcNode, *AdjList;

typedef struct Graph
{
	AdjList elem[MAX + 1];
	int vexnum;
	int arcnum;
	int GraphKind;
}Graph;


typedef struct Stack
{
	int s[MAX];
	int top;
}Stack;

void initStack(Stack *s)
{
	(*s).top = 0;
}

int Push(Stack *s, int e)
{
	if ((*s).top >= MAX) return 0;
	else (*s).s[(*s).top++] = e;
}

int Pop(Stack *s, int *e)
{
	if ((*s).top <= 0) return 0;
	else *e = (*s).s[--(*s).top];
}

int StackEmpty(Stack s)
{
	if (s.top == 0)return 1;
	else return 0;
}


void create(Graph *G)
{
	int i, start, end; AdjList p;
	for (i = 0; i <= MAX; i++)
		(*G).elem[i] = Null;
	for (i = 1; i <= (*G).arcnum; i++)
	{
		scanf("%d,%d", &start, &end);
		p = (AdjList)malloc(sizeof(ArcNode));
		p->adjvex = end;
		p->nextarc = (*G).elem[start];
		(*G).elem[start] = p;
		if ((*G).GraphKind == 0)
		{
			p = (AdjList)malloc(sizeof(ArcNode));
			p->adjvex = start;
			p->nextarc = (*G).elem[end];
			(*G).elem[end] = p;
		}
	}
}


int TopoSort(Graph G)
{
	int i, count, indegree[MAX + 1];
	AdjList p; Stack S;
	for (i = 1; i <= G.vexnum; i++)
		indegree[i] = 0;
	initStack(&S);
	for (i = 1; i <= G.vexnum; i++)
		for (p = G.elem[i]; p; p = p->nextarc)
			++indegree[p->adjvex];
	for (i = 1; i <= G.vexnum; i++)
		if (!indegree[i]) Push(&S, i);
	count = 0;
	while (!StackEmpty(S))
	{
		Pop(&S, &i);
		printf("v%d ", i); ++count;
		for (p = G.elem[i]; p; p = p->nextarc)
			if (!(--indegree[p->adjvex])) Push(&S, p->adjvex);
	}
	if (!count) return 1;
}


int main(void)
{
	Graph G;
	printf("Please input the number of vex, arc and GraphKind:");
	scanf("%d,%d,%d", &G.vexnum, &G.arcnum, &G.GraphKind);
	create(&G);
	printf("The outcome of TopoSort is:\n");
	TopoSort(G);
	return 0;
}

#endif

// �Ͻ�˹�����㷨
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INFINITY        65535
#define MAX_VERTEX_NUM  20
#define ERROR           -1
#define TRUE            1
#define FALSE           -1

typedef int Adjtype;
typedef int WeightType;
typedef char VertexData;
typedef enum { DG, DN, UDG, UDN } Graphkind;

typedef struct
{
	Adjtype adj;
	WeightType weight;
}ArcNode;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];
	ArcNode    arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int        vexnum, arcnum;
	Graphkind  kind;
}Adjmatrix;
typedef struct
{
	VertexData vertex[MAX_VERTEX_NUM];
	int tail;		//��βλ��
}SeqList, VertexSet;	//���·���ļ���

int LocateVex(Adjmatrix *G, VertexData v)
{
	int j = ERROR;
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->vertex[i] == v)
		{
			j = i;
			break;
		}
	}
	return j;
}
//����������
void CreatDN(Adjmatrix *G)
{
	int i, j, k, weight;
	VertexData v1, v2;
	printf("�����붥�����ͱ�����\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j].weight = INFINITY;
		}
		G->arc[i][i].weight = 0;
	}
	printf("�����붥����Ϣ����abcdef��\n");
	fflush(stdin);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
	}
	printf("���������Ϣ����ab1��\n");
	for (k = 0; k < G->arcnum; k++)
	{
		fflush(stdin);
		scanf("%c%c%d", &v1, &v2, &weight);
		i = LocateVex(G, v1);
		j = LocateVex(G, v2);
		if (i != ERROR && j != ERROR)
		{
			G->arc[i][j].weight = weight;
		}
	}
}
void printAdjMatrx(Adjmatrix G)
{
	int i, j;
	for (i = 0; i<G.vexnum; i++)
	{
		for (j = 0; j<G.vexnum; j++)
		{
			if (G.arc[i][j].weight == INFINITY)
			{
				printf("��   ");
			}
			else
			{
				printf(" %d   ", G.arc[i][j].weight);
			}
		}
		printf("\n");
	}
}
int Member(VertexData v, VertexSet s)
{
	int j = 0;
	int i;
	for (i = 0; i <= s.tail; i++)
	{
		if (v == s.vertex[i])
		{
			j = TRUE;
			break;
		}
	}
	return j;
}
void add_Pk_to_Pi(VertexSet *pathi, VertexSet pathk, VertexData v)
{
	int i;
	for (i = 0; i <= pathk.tail; i++)
	{
		pathi->vertex[i] = pathk.vertex[i];
	}
	pathi->tail = pathk.tail;
	pathi->vertex[pathi->tail] = v;
	pathi->tail++;
	pathi->vertex[pathi->tail] = '\0';
}
//�Ͻ�˹����(Dijkstra)�㷨�����·��
void ShortestPath_DJS(Adjmatrix G, int v0, WeightType dist[], VertexSet path[])
{
	//path[i]�д�Ŷ���i�ĵ�ǰ���·����dist[i]�д�Ŷ���i�ĵ�ǰ���·������
	int i, j, k;
	int t;
	int min;
	VertexSet s;	//sΪ���ҵ����·�����յ㼯��
	for (i = 0; i < G.vexnum; i++)	//��ʼ��dist[i]��path[i]
	{
		path[i].tail = 0;
		path[i].vertex[path[i].tail] = '\0';
		dist[i] = G.arc[v0][i].weight;
		if (dist[i] < INFINITY)
		{
			//��·����ӵ���β
			path[i].vertex[path[i].tail] = G.vertex[v0];
			path[i].tail++;
			path[i].vertex[path[i].tail] = G.vertex[i];
			path[i].tail++;
			path[i].vertex[path[i].tail] = '\0';
		}
	}
	s.tail = 0;
	s.vertex[s.tail] = G.vertex[0];//��v0���ɵ�һ�����ҵ����·�����յ�
	s.tail++;
	for (t = 1; t < G.vexnum; t++)//��v0������n-1����������·����n=G.vexnum��
	{
		min = INFINITY;
		for (i = 0; i < G.vexnum; i++)
		{
			if ((!Member(G.vertex[i], s)) && dist[i] < min)
			{
				k = i;
				min = dist[i];
			}
		}
		if (INFINITY == min)
		{
			return;
		}
		//�ҵ���̵�һ��·����������ӵ�s����
		s.vertex[s.tail] = G.vertex[k];
		s.tail++;
		for (i = 0; i < G.vexnum; i++)
		{
			//����dist[i]��i��V-S
			if ((!Member(G.vertex[i], s)) && (G.arc[k][i].weight != INFINITY)
				&& (dist[k] + G.arc[k][i].weight < dist[i]))
			{
				dist[i] = dist[k] + G.arc[k][i].weight;
				add_Pk_to_Pi(&path[i], path[k], G.vertex[i]);
				path[i].vertex[path[i].tail] = '\0';
			}
		}
	}
}

void main()
{
	Adjmatrix G;
	WeightType dist[MAX_VERTEX_NUM];
	VertexSet  path[MAX_VERTEX_NUM];
	int i;

	CreatDN(&G);
	printAdjMatrx(G);
	ShortestPath_DJS(G, 0, dist, path);
	for (i = 0; i < G.vexnum; i++)
	{
		printf("%s,%d\n", path[i].vertex, dist[i]);
	}
	getchar();
	getchar();
}

/*
ab50
ac10
ca20
bc15
cd15
db20
ae45
be10
de35
ed30
fd3
*/
#endif

#if 0
// �ؼ�·���㷨
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include<iomanip> 
#include <process.h> 

//#define PROJECTNUMBER 9//10 

//#define PLANNUMBER 11//13 
;
typedef struct node
{
	int adjvex;
	int dut;
	struct node *next;
}edgenode;

typedef struct
{
	int projectname;
	int id;
	edgenode *link;
}vexnode;

//vexnode Graphicmap[PROJECTNUMBER]; 
int SearchMapPath(vexnode* Graphicmap, int projectnumber, int activenumber, int totaltime);
void CreateGraphic(vexnode* Graphicmap, int projectnumber, int activenumber);

void CreateGraphic(vexnode* Graphicmap, int projectnumber, int activenumber)
{
	int begin, end, duttem;
	int i, k;
	edgenode *p;
	for (i = 0; i<projectnumber; i++)
	{
		Graphicmap[i].projectname = i;
		Graphicmap[i].id = 0;
		Graphicmap[i].link = NULL;
	}
	printf("ĳ��Ŀ�Ŀ�ʼ��������ͼ�еĽڵ�����<vi,vj,dut>\n");
	printf("�磺3,4,9 �س���ʾ�����ڵ㵽���Ľڵ�֮��Ļ����9����λʱ��\n");
	for (k = 0; k<activenumber; k++)
	{
		scanf("%d,%d,%d", &begin, &end, &duttem);
		p = (edgenode*)malloc(sizeof(edgenode));
		p->adjvex = end - 1;
		p->dut = duttem;
		Graphicmap[end - 1].id++;
		p->next = Graphicmap[begin - 1].link;
		Graphicmap[begin - 1].link = p;
	}
}

int SearchMapPath(vexnode* Graphicmap, int projectnumber, int activenumber, int totaltime)
{
	int i, j, k, m = 0;
	int front = -1, rear = -1;
	int* topologystack = (int*)malloc(projectnumber * sizeof(int));//���������������� 
	int* vl = (int*)malloc(projectnumber * sizeof(int));//������ʾ�ڲ��Ƴ��������̵�ǰ���£�VJ������ٷ�����ʱ�� 
	int* ve = (int*)malloc(projectnumber * sizeof(int));//������ʾVj���緢��ʱ�� 
	int* l = (int*)malloc(activenumber * sizeof(int));//������ʾ�Ai�����ɿ�ʼʱ�� 
	int* e = (int*)malloc(activenumber * sizeof(int));//��ʾ����翪ʼʱ�� 
	edgenode *p;
	totaltime = 0;
	for (i = 0; i<projectnumber; i++) ve[i] = 0;
	for (i = 0; i<projectnumber; i++)
	{
		if (Graphicmap[i].id == 0)
		{
			topologystack[++rear] = i;
			m++;
		}
	}
	while (front != rear)
	{
		front++;
		j = topologystack[front];
		m++;
		p = Graphicmap[j].link;
		while (p)
		{
			k = p->adjvex;
			Graphicmap[k].id--;
			if (ve[j] + p->dut >ve[k])
				ve[k] = ve[j] + p->dut;
			if (Graphicmap[k].id == 0)
				topologystack[++rear] = k;
			p = p->next;
		}
	}
	if (m<projectnumber)
	{
		printf("\n��������������ͼ�л�·���ɼ�����ؼ�·��\n");
		printf("���˳�������\n");
		return 0;
	}
	totaltime = ve[projectnumber - 1];
	for (i = 0; i<projectnumber; i++)
		vl[i] = totaltime;
	for (i = projectnumber - 2; i >= 0; i--)
	{
		j = topologystack[i];
		p = Graphicmap[j].link;
		while (p)
		{
			k = p->adjvex;
			if ((vl[k] - p->dut)<vl[j])
				vl[j] = vl[k] - p->dut;
			p = p->next;
		}
	}
	i = 0;
	printf("| ��� | �յ� |  ���翪ʼʱ��  |  ������ʱ��  | ��ֵ |  ��ע  |\n");
	for (j = 0; j<projectnumber; j++)
	{
		p = Graphicmap[j].link;
		while (p)
		{
			k = p->adjvex;
			e[++i] = ve[j];
			l[i] = vl[k] - p->dut;
			printf("| %4d | %4d |    %4d    |    %4d    | %4d |", Graphicmap[j].projectname + 1, Graphicmap[k].projectname + 1, e[i], l[i], l[i] - e[i]);
			if (l[i] == e[i])
				printf(" �ؼ�� |");
			printf("\n");
			p = p->next;
		}
	}
	return 1;
}

void seekkeyroot()
{
	int projectnumber, activenumber, totaltime = 0;
	vexnode* Graphicmap;
	system("cls");
	printf("������������̵Ļ���ͼ�εĽڵ���:");
	scanf("%d", &projectnumber);
	printf("������������̵Ļ����:");
	scanf("%d", &activenumber);
	Graphicmap = (vexnode*)malloc(projectnumber * sizeof(vexnode));
	CreateGraphic(Graphicmap, projectnumber, activenumber);
	SearchMapPath(Graphicmap, projectnumber, activenumber, totaltime);
	printf("�����������õ����ʱ��Ϊ��%d����λʱ��\n", totaltime);
	system("pause");
}

int main()
{
	char ch;
	int i;
	for (;;)
	{
		do
		{
			system("cls");
			printf("|             ��ӭ������ؼ�·���㷨����              |");
			for (i = 0; i<80; i++)printf("*");
			printf("%s", "(S)tart��ʼ���빤�̵Ľڵ����ݲ�����ؼ�·��\n");
			printf("%s", "(E)xit�˳�\n");
			printf("%s", "������ѡ��:");
			scanf("%c", &ch);
			ch = toupper(ch);
		} while (ch != 'S'&&ch != 'E');
		switch (ch)
		{
		case'S':
			seekkeyroot();
			break;
		case'E':
			return 1;
		}
	}
}
#endif

// =============================================================�κ���ҵ===================================

//  �ֱ���ͼ���ڽӾ����ʾ����ͼ���ڽӱ��ʾ�������������Ȩͼ
//  д��������ȱ����͹�����ȱ����ĳ���

#if  1
#include<iostream>
#include<queue>
using namespace std;

#define MAXSIZE  20

typedef struct
{
	int adj;	// ������ȫͼ����1��0��ʾ�Ƿ�����;���ڴ�Ȩͼ����ΪȨֵ����
	// �����ڴ˴�����һЩ����ͼ�ߵ���Ϣ
}ArcNode;

typedef struct
{
	char Vertex[MAXSIZE];   // ��������
	ArcNode arcs[MAXSIZE][MAXSIZE];		// �ڽӾ���
	int vexnum;			//	�������
	int arcnum;			// �߸���
}AdjMatrix;				//	ͼ���ڽӾ����ʾ��

// ========================

// ͼ���ڽӱ��ʾ��

typedef struct Node
{
	int adj;	//	��Ӧ�Ķ����±�
	int weight;		// �ߵ�Ȩֵ
	struct Node* nextarc;	//
}ArcNode2;

typedef struct
{
	char vertexdata;	//	���������
	ArcNode2 *firstArc;	//	��һ����
}VertexType;

typedef struct
{
	VertexType vertex[MAXSIZE];
	int vexnum;
	int arcnum;	
}AdjList;

int LocateAdj(AdjMatrix *G,char v)
{
	int i;
	for (i=0;i<G->vexnum;i++)
	{
		if (G->Vertex[i]==v)
		{
			return i;
		}
	}
	return - 1;
}

// �ڽӾ��󴴽�����ͼ

void CreatAdj(AdjMatrix *G)
{
	int i, j, k;
	char v1, v2;
	cout << "���붥��ͱߵĸ���:" << endl;
	cin >> G->vexnum >> G->arcnum;
	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = 0;
		}
	}
	// ���붥��
	cout << "���붥��:" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->Vertex[i];
	}

	// �����
	cout << "�����:" << endl;
	for (k=0;k<G->vexnum;k++)
	{
		fflush(stdin);
		cin >> v1 >> v2;
		i = LocateAdj(G,v1);
		j = LocateAdj(G,v2);
		if (i!=-1&&j!=-1)
		{
			G->arcs[i][j].adj = 1;
		}
	}
}

int LocateAdjList(AdjList *G,char v)
{
	int i;
	for (i=0;i<G->vexnum;i++)
	{
		if (G->vertex[i].vertexdata==v)
		{
			return i;
		}
	}
	return -1;
}
// �ڽӱ�������ͼ
void CreatAdjList(AdjList *G)
{
	int i, j, k;
	ArcNode2*s;
	char v1, v2;
	// ���붥������ͱ���
	cout << "���붥������ͱ���:" << endl;
	cin >> G->vexnum >> G->arcnum;
	// ���붥���ͬʱ����ʼ��
	cout << "���붥��:" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{	
		cin >> G->vertex[i].vertexdata;
		G->vertex[i].firstArc= NULL;
	}
	// �����
	cout << "�����:" << endl;
	for (k=0;k<G->arcnum;k++)
	{
		fflush(stdin);
		cin >> v1 >> v2;
		i = LocateAdjList(G,v1);
		j = LocateAdjList(G,v2);
		if (i!=-1&&j!=-1)
		{
			s = new ArcNode2;
			if (NULL==s)
			{
				cout << "��̬�����ڴ�ʧ��!" << endl;
				return;
			}
			s->adj = j;
			s->nextarc = G->vertex[i].firstArc;
			G->vertex[i].firstArc = s;
		}
	}
}

int visited[MAXSIZE] = { 0 };

// �ڽӱ�������ȱ���

void DFS(AdjList G,int v0)
{
	cout << G.vertex[v0].vertexdata << " ";
	visited[v0] = 1;
	ArcNode2 *p;
	p = G.vertex[v0].firstArc;
	while (p!=NULL)
	{
		// ��firstarc����
		if (visited[p->adj]!=1)
		{
			DFS(G,p->adj);
		}
		// ����һ����
		p = p->nextarc;
	}
}

void TravelDFS(AdjList G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=-1)
		{
			DFS(G,i);
		}
	}
}

// �ڽӾ���������ȱ���

void DFSMatx(AdjMatrix G,int v0)
{
	cout << G.Vertex[v0] << " ";
	visited[v0] = 1;
	int j;
	for (j=0;j<G.vexnum;j++)
	{
		if (G.arcs[v0][j].adj==1)
		{
			if (visited[j]!=1)
			{
				DFSMatx(G,j);
			}
		}
	}
}

void TravelMatxDFS(AdjMatrix G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=1)
		{
			DFSMatx(G,i);
		}
	}
}

// ͼ�Ĺ����������

void BFS(AdjList G,int v0)
{
	queue<int>Q;
	int v;
	ArcNode2 *p;
	Q.push(v0);
	cout << G.vertex[v0].vertexdata <<"  ";
	visited[v0] = 1;
	while(!Q.empty())
	{
		v = Q.front();
		Q.pop();
		p = G.vertex[v].firstArc;
		while (p!=NULL)
		{
			if (visited[p->adj]!=1)
			{
				Q.push(p->adj);
				cout << G.vertex[p->adj].vertexdata << "  ";
				visited[p->adj] = 1;
			}
			p = p->nextarc;
		}
	}
}

void TravelBFS(AdjList G)
{
	int i;
	for (i=0;i<G.vexnum;i++)
	{
		if (visited[i]!=1)
		{
			BFS(G,i);
		}
	}
}

int main(void)
{
//	AdjMatrix G;
//	cout << "ͼ���ڽӾ��󷨱�ʾ:" << endl;
//	CreatAdj(&G);
//	TravelMatxDFS(G);
	cout << "ͼ���ڽӱ��ʾ��:" << endl;
	AdjList G1;
	CreatAdjList(&G1);
	TravelBFS(G1);
	TravelDFS(G1);
	return 0;
}

#endif







// =============================================================�κ���ҵ===================================