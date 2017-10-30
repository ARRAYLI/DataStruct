// =================================================图================================================================
#if 0
#include<iostream>
#include<queue>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	int adj;		// 对于无权图，用0或1表示是否相邻；对带权图，则为权值类型
	// 此处可以定义关于图中边的基本信息
}ArcNode;

typedef struct
{
	char Vertex[MAXSIZE];				// 顶点数组
	ArcNode arcs[MAXSIZE][MAXSIZE];		// 邻接矩阵
	int vexnum;							// 顶点个数
	int arcnum;							// 边个数
}AdjMatrix;								// 领接矩阵

//	=========================

typedef struct Node
{
	int adj;			//	对应的顶点下标
	int weight;			//  边的权值
	struct Node* nextarc;	
}ArcNode2;

typedef struct
{
	char vertexdata;		// 顶点内容
	ArcNode2 *firstArc;		// 第一条弧
}VertexType;

typedef struct
{
	VertexType vertex[MAXSIZE];		// 图的邻接表
	int vexnum;						// 边个数
	int arcnum;						// 顶点个数
}AdjList;

//	=== 图的邻接矩阵创建法

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

void CreatAdj(AdjMatrix *G)				// 领接矩阵创建有向图
{
	int i, j, k;
	char v1, v2;

	//  输入顶点个数和边个数
	cout << "输入顶点个数和边个数:" << endl;
	cin >> G->vexnum >> G->arcnum;

	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = 0;
		}
	}

	// 输入顶点
	cout << "输入顶点："<<endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->Vertex[i];
	}

	// 输入边
	cout << "输入边："<<endl;
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

//	=== 图的邻接表创建法

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

	// 输入顶点个数和边个数
	cout << "输入顶点个数和边个数:" << endl;
	cin >> G->vexnum >> G->arcnum;
	// 输入顶点的同时做初始化
	cout << "输入顶点：" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->vertex[i].vertexdata;
		G->vertex[i].firstArc = NULL;
	}
	// 输入边
	cout << "输入边: " << endl;
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
				cout << "动态申请内存失败!" <<endl;
				return;
			}
			s->adj = j;
			s->nextarc = G->vertex[i].firstArc;
			G->vertex[i].firstArc = s;
		}
	}
}

// 图的邻接表的深度优先遍历

int visited[MAXSIZE];
void DFS(AdjList G,int v0)
{
	cout << G.vertex[v0].vertexdata << " ";
	visited[v0] = 1;
	ArcNode2 *p;
	p = G.vertex[v0].firstArc;
	while (p != NULL)
	{
		// 从firstarc做DFS
		if (visited[p->adj] != 1)
		{
			DFS(G, p->adj);
		}
		// 找到下一个弧nextarc做DFS
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

// 图的邻接矩阵的深度优先遍历

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

// 图的广度优先搜索

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
	cout << "图的邻接据矩阵的是：" << endl;
	for (i=0;i<G.vexnum;i++)
	{
		for (j=0;j<G.vexnum;j++)
		{
			cout << G.arcs[i][j].adj << "  ";
		}
		cout << endl;
	}
	cout << "图的邻接矩阵深度优先遍历的结果是:" << endl;
	TravelMatxDFS(G);
*/
	AdjList G1;
	int i;
	CreatAdjList(&G1);
	ArcNode2 *pp=NULL;
	cout << "图的邻接表的遍历结果是:" << endl;
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

// 普林母算法
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
}AdjMatrix;				// 邻接矩阵

typedef struct
{
	VertexData adjvex;
	int lowcost;
}Closedge;				// 求最小生成树

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

void CreatUDN(AdjMatrix *G)		//	创建一个带权无向图
{
	int i, j, k, weight;
	VertexData v1, v2;
	cout << "输入顶点数，边数:" << endl;
	cin >> G->vexnum >> G->arcnum;
	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	cout << "输入顶点：" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->vertex[i];
	}
	cout << "输入边(a b 1):" << endl;
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

// ======================普里姆算法===========================

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
	// 从顶点u出发，按普里姆算法构造连通网G的最小生成树，并输出生成树的每条边
	int k;
	int k0;
	int i, e;
	VertexData u0, v0;
	Closedge closedge[MAX_VERTEX_NUM];

	k = LocateVex(&G,u);
	closedge[k].lowcost = 0;		// 初始化U={u}
	for (i=0;i<G.vexnum;i++)
	{
		if (i!=k)
		{
			closedge[i].adjvex = u;
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
	}
	for (e=1;e<G.vexnum;e++)		//	找到n-1条边
	{
		k0 = Minium(closedge,G.vexnum);	//closedge[k0]中存有当前最小边(U0,v0)的信息
		u0 = closedge[k0].adjvex;		// u0属于U	
		v0 = G.vertex[k0];				// v0属于V-U
		cout <<"("<<u0 <<"," <<v0 << ") ";	//	输出生成树当前最小边（u0,v0）
		closedge[k0].lowcost = 0;		// 在顶点v0并入U之后，更新closedge[i]
		for (i=0;i<G.vexnum;i++)
		{
			// 如果新边的权值比closedge[v].lowcost小，则将closedge[i].lowcost更新为新边的权值
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
}AdjMatrix;                         //邻接矩阵
typedef struct
{
	VertexData adjvex;
	int lowcost;
}Closedge;                          //求最小生成树

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

void GreatUDN(AdjMatrix *G)         //创建一个无向带权图
{
	int i, j, k, weight;
	VertexData v1, v2;
	printf("输入顶点数，边数：\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i<G->vexnum; i++)
	{
		for (j = 0; j<G->vexnum; j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	printf("输入顶点：\n");
	fflush(stdin);
	for (i = 0; i<G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
	}
	printf("输入边（a b 1）：\n");
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
				printf("∞   ");
			}
			else
			{
				printf(" %d   ", G.arcs[i][j].adj);
			}
		}
		printf("\n");
	}
}
//===================普里姆算法====================
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
	//从顶点u出发，按普里姆算法构造连通网G的最小生成树，并输出生成树的每条边
	int k;
	int k0;
	int i, e;
	VertexData u0, v0;
	Closedge closedge[MAX_VERTEX_NUM];

	k = LocateVex(&G, u);
	closedge[k].lowcost = 0;		//初始化，U={u}
	for (i = 0; i<G.vexnum; i++)
	{
		if (i != k)				//对V-U中的顶点i，初始化closedge[i]
		{
			closedge[i].adjvex = u;
			closedge[i].lowcost = G.arcs[k][i].adj;
		}
	}
	for (e = 1; e<G.vexnum; e++)		//找n-1条边（n = G.vexnum）
	{
		k0 = Minium(closedge, G.vexnum);//closedge[k0]中存有当前最小边(u0 , v0)的信息
		u0 = closedge[k0].adjvex;		 //u0属于U
		v0 = G.vertex[k0];             //v0属于V-U
		printf("(%c,%c) ", u0, v0);    //输出生成树的当前最小边(u0 , v0)
		closedge[k0].lowcost = 0;		 //将顶点v0纳入U集合
		for (i = 0; i<G.vexnum; i++)		 //在顶点v0并入U之后，更新closedge[i]
		{
			if (G.arcs[k0][i].adj<closedge[i].lowcost)
				//如果新边的权值比closedge[v].lowcost小，则将closedge[i].lowcost更新为新边的权值
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
输入顶点数，边数：
6
10
G->vexnum=6,G->arcnum=10
输入顶点：
abcdef
输入边（a b 1）：
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
∞    6    1    5   ∞   ∞
6   ∞    5   ∞    3   ∞
1    5   ∞    5    6    4
5   ∞    5   ∞   ∞    2
∞    3    6   ∞   ∞    6
∞   ∞    4    2    6   ∞
(a,c) (c,f) (f,d) (c,b) (b,e)
*/
#endif

#if 0
#include<stdio.h>
#include<malloc.h>
#include<algorithm>
//克鲁斯卡尔(kruskal)算法--最小生成树
typedef struct Edge
{
	int v;
	int u;
	int w;
}edge;

typedef struct
{
	int nv;   //定点数
	int num;  //边数
			  //edge *e;
	edge e[10];
}Graph;

/*用 法： void qsort(void *base,int nelem,int width,int (*fcmp)(const void *,const void *));
参数： 1 待排序数组首地址
2 数组中待排序元素数量
3 各元素的占用空间大小
4 指向函数的指针，用于确定排序的顺序*/
int cmp(const void *a, const void *b) //按升序排列  
{
	edge * x = (edge *)a;
	edge * y = (edge *)b;
	return (x->w) - (y->w);
}
void kruskal(Graph *g)
{
	int *x = (int *)malloc(sizeof(int)*g->num);//点所在集合
	int i, m, n, c = 0;
	for (i = 0; i < g->nv; i++)
	{
		x[i] = i;
	}
	qsort(g->e, g->num, sizeof(edge), cmp);
	for (i = 0; i<g->num&&c<g->nv; i++)
	{
		//判断边的两点是否在同一个集合
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

// 拓扑排序算法

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

// 迪杰斯特拉算法
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
	int tail;		//表尾位置
}SeqList, VertexSet;	//最短路径的集合

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
//创建有向网
void CreatDN(Adjmatrix *G)
{
	int i, j, k, weight;
	VertexData v1, v2;
	printf("请输入顶点数和边数：\n");
	scanf("%d%d", &G->vexnum, &G->arcnum);
	for (i = 0; i < G->vexnum; i++)
	{
		for (j = 0; j < G->vexnum; j++)
		{
			G->arc[i][j].weight = INFINITY;
		}
		G->arc[i][i].weight = 0;
	}
	printf("请输入顶点信息：（abcdef）\n");
	fflush(stdin);
	for (i = 0; i < G->vexnum; i++)
	{
		scanf("%c", &G->vertex[i]);
	}
	printf("请输入边信息：（ab1）\n");
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
				printf("∞   ");
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
//迪杰斯特拉(Dijkstra)算法求最短路径
void ShortestPath_DJS(Adjmatrix G, int v0, WeightType dist[], VertexSet path[])
{
	//path[i]中存放顶点i的当前最短路径。dist[i]中存放顶点i的当前最短路径长度
	int i, j, k;
	int t;
	int min;
	VertexSet s;	//s为已找到最短路径的终点集合
	for (i = 0; i < G.vexnum; i++)	//初始化dist[i]和path[i]
	{
		path[i].tail = 0;
		path[i].vertex[path[i].tail] = '\0';
		dist[i] = G.arc[v0][i].weight;
		if (dist[i] < INFINITY)
		{
			//将路径添加到表尾
			path[i].vertex[path[i].tail] = G.vertex[v0];
			path[i].tail++;
			path[i].vertex[path[i].tail] = G.vertex[i];
			path[i].tail++;
			path[i].vertex[path[i].tail] = '\0';
		}
	}
	s.tail = 0;
	s.vertex[s.tail] = G.vertex[0];//将v0看成第一个已找到最短路径的终点
	s.tail++;
	for (t = 1; t < G.vexnum; t++)//求v0到其余n-1个顶点的最短路径（n=G.vexnum）
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
		//找到最短的一个路径并将其添加到s里面
		s.vertex[s.tail] = G.vertex[k];
		s.tail++;
		for (i = 0; i < G.vexnum; i++)
		{
			//修正dist[i]，i∈V-S
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
// 关键路径算法
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
	printf("某项目的开始到结束在图中的节点输入<vi,vj,dut>\n");
	printf("如：3,4,9 回车表示第三节点到第四节点之间的活动用了9个单位时间\n");
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
	int* topologystack = (int*)malloc(projectnumber * sizeof(int));//用来保存拓扑排列 
	int* vl = (int*)malloc(projectnumber * sizeof(int));//用来表示在不推迟整个工程的前提下，VJ允许最迟发生的时间 
	int* ve = (int*)malloc(projectnumber * sizeof(int));//用来表示Vj最早发生时间 
	int* l = (int*)malloc(activenumber * sizeof(int));//用来表示活动Ai最迟完成开始时间 
	int* e = (int*)malloc(activenumber * sizeof(int));//表示活动最早开始时间 
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
		printf("\n本程序所建立的图有回路不可计算出关键路径\n");
		printf("将退出本程序\n");
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
	printf("| 起点 | 终点 |  最早开始时间  |  最迟完成时间  | 差值 |  备注  |\n");
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
				printf(" 关键活动 |");
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
	printf("请输入这个工程的化成图形的节点数:");
	scanf("%d", &projectnumber);
	printf("请输入这个工程的活动个数:");
	scanf("%d", &activenumber);
	Graphicmap = (vexnode*)malloc(projectnumber * sizeof(vexnode));
	CreateGraphic(Graphicmap, projectnumber, activenumber);
	SearchMapPath(Graphicmap, projectnumber, activenumber, totaltime);
	printf("整个工程所用的最短时间为：%d个单位时间\n", totaltime);
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
			printf("|             欢迎进入求关键路径算法程序              |");
			for (i = 0; i<80; i++)printf("*");
			printf("%s", "(S)tart开始输入工程的节点数据并求出关键路径\n");
			printf("%s", "(E)xit退出\n");
			printf("%s", "请输入选择:");
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

// =============================================================课后作业===================================

//  分别用图的邻接矩阵表示法和图的邻接表表示法，创建无向带权图
//  写出深度优先遍历和广度优先遍历的程序

#if  1
#include<iostream>
#include<queue>
using namespace std;

#define MAXSIZE  20

typedef struct
{
	int adj;	// 对于无全图，用1或0表示是否相邻;对于带权图，则为权值类型
	// 可以在此处定义一些关于图边的信息
}ArcNode;

typedef struct
{
	char Vertex[MAXSIZE];   // 顶点数组
	ArcNode arcs[MAXSIZE][MAXSIZE];		// 邻接矩阵
	int vexnum;			//	顶点个数
	int arcnum;			// 边个数
}AdjMatrix;				//	图的邻接矩阵表示法

// ========================

// 图的邻接表表示法

typedef struct Node
{
	int adj;	//	对应的顶点下标
	int weight;		// 边的权值
	struct Node* nextarc;	//
}ArcNode2;

typedef struct
{
	char vertexdata;	//	顶点的内容
	ArcNode2 *firstArc;	//	第一条弧
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

// 邻接矩阵创建有向图

void CreatAdj(AdjMatrix *G)
{
	int i, j, k;
	char v1, v2;
	cout << "输入顶点和边的个数:" << endl;
	cin >> G->vexnum >> G->arcnum;
	for (i=0;i<G->vexnum;i++)
	{
		for (j=0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = 0;
		}
	}
	// 输入顶点
	cout << "输入顶点:" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{
		cin >> G->Vertex[i];
	}

	// 输入边
	cout << "输入边:" << endl;
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
// 邻接表创建有向图
void CreatAdjList(AdjList *G)
{
	int i, j, k;
	ArcNode2*s;
	char v1, v2;
	// 输入顶点个数和边数
	cout << "输入顶点个数和边数:" << endl;
	cin >> G->vexnum >> G->arcnum;
	// 输入顶点的同时做初始化
	cout << "输入顶点:" << endl;
	fflush(stdin);
	for (i=0;i<G->vexnum;i++)
	{	
		cin >> G->vertex[i].vertexdata;
		G->vertex[i].firstArc= NULL;
	}
	// 输入边
	cout << "输入边:" << endl;
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
				cout << "动态申请内存失败!" << endl;
				return;
			}
			s->adj = j;
			s->nextarc = G->vertex[i].firstArc;
			G->vertex[i].firstArc = s;
		}
	}
}

int visited[MAXSIZE] = { 0 };

// 邻接表深度优先遍历

void DFS(AdjList G,int v0)
{
	cout << G.vertex[v0].vertexdata << " ";
	visited[v0] = 1;
	ArcNode2 *p;
	p = G.vertex[v0].firstArc;
	while (p!=NULL)
	{
		// 从firstarc做起
		if (visited[p->adj]!=1)
		{
			DFS(G,p->adj);
		}
		// 找下一个弧
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

// 邻接矩阵深度优先遍历

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

// 图的广度优先搜索

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
//	cout << "图的邻接矩阵法表示:" << endl;
//	CreatAdj(&G);
//	TravelMatxDFS(G);
	cout << "图的邻接表表示法:" << endl;
	AdjList G1;
	CreatAdjList(&G1);
	TravelBFS(G1);
	TravelDFS(G1);
	return 0;
}

#endif







// =============================================================课后作业===================================