//
// Created by DELL on 2022/3/27.
//

#ifndef DATA_STRUCTURE_GRAPH_H
#define DATA_STRUCTURE_GRAPH_H

#include <cstdlib>
#include <cstdio>
#include"../status.h"
typedef char VertexType; /*顶点类型*/
typedef int EdgeType;
#define MAXVEX 100 //最大定点数
#define INFINITY 65535//65535代表∞
typedef struct
{
    VertexType vexs[MAXVEX];//定点表
    EdgeType arc[MAXVEX][MAXVEX];//权值表
    int numVertexes,numEdges;//顶点和边数
}MGraph;
void CreateMGraph(MGraph *G);

/********************邻接表**************************/
typedef struct EdgeNode
{
    int adjvex;
    EdgeType weight;
    struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
    int in;//存储入度
    VertexType data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];

typedef struct
{
    AdjList  adjList;
    int numVertexes,numEdges;
}graphAdjList,*GraphAdjList;

typedef int Boolean;
/*********************临界矩阵DFS**********************/
extern Boolean visited[MAXVEX];
void DFS(MGraph G, int i);
void DFSTraverse(MGraph G);

/*************建立图的邻接表结构********************/
void CreateALGraph(graphAdjList *G);


/*********************邻接表DFS**********************/
void DFS(graphAdjList GL,int i);
void DFSTraverse(graphAdjList GL);
class Queue{

};

void InitQueue(Queue *Q);

void EnQueue(Queue *Q, int i);
Boolean QueueEmpty(Queue Q);
void DeQueue(Queue *Q,int *i);
/*********************邻接矩阵的广度遍历算法************/
void BFSTraverese(MGraph G);


/*******************Prim 普利姆算法最小生成树***********/
/*******************从一个点逐步囊括其他点（选择与生成树的）***********/
void MinSpanTree_Prim(MGraph G);

/*******************Kruskal 克鲁斯卡尔算法*******************/
/*******************将权值排序从小到大排序，不形成环的情况下选择最小边*******************/
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;
void MiniSpanTree_Kruskal(MGraph G);



/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/*****************************迪杰斯特拉算法（Dijkstra）*********************************/
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];
void short_path_dijkstra(MGraph G,int v0, Patharc * P,ShortPathTable * D);
/*一个一个点往里加每次跟新一个点的最短路径其中shortpathtable存的是前序点序号*/
/*****************************迪杰斯特拉算法（Dijkstra）*********************************/
/*****************************佛洛依德算法（floyd）*********************************/
/*****************************D0[v][w]=min{D-1[v][w],D-1[0][w]}**************************/
typedef int Pathmatrix[MAXVEX][MAXVEX];
typedef int ShortPathTable_f[MAXVEX][MAXVEX];
void ShortestPath_Floyd(MGraph G, Pathmatrix *P,ShortPathTable_f *D);
void show_Floyd(int numVertexes,Pathmatrix P,ShortPathTable_f D);
/*****************************佛洛依德算法（floyd）*********************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/



/***********************************拓扑排序***************************************/

/***********************************在AOV中将入度为0的顶点输出删除***************************************/
Status TopologicalSort(GraphAdjList GL);

/***********************************拓扑排序***************************************/
/***********************************AOV中没有入边为始点或源点，没有出边为终点或汇点***************************************/
/***********************************从源点到汇点的最长路径被称作关键路径***************************************/
/***********************************最早发生时间与最晚发生时间一样就是关键活动了***************************************/
/***********************************拓扑排序（关键路径用）***************************************/

extern int * etv,*ltv;
extern int * stack2;
extern int top2;
Status TopologicalSort_cp(GraphAdjList GL);

/***********************************求关键路径***************************************/
void CriticalPath(GraphAdjList GL);

#endif //DATA_STRUCTURE_GRAPH_H
