//
// Created by DELL on 2022/3/27.
//



#include "graph.h"
int * etv,*ltv;
int * stack2;
int top2;
void InitQueue(Queue *Q)
{
    return ;
}

void EnQueue(Queue *Q, int i)
{
    return ;
}
Boolean QueueEmpty(Queue Q)
{
    return true;
}
void DeQueue(Queue *Q,int *i)
{
    return ;
}
void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("输入顶点数和边数:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for(i = 0;i<G->numVertexes;i++)
        scanf(&G->vexs[i]);
    for(i = 0;i<G->numVertexes;i++)
        for(j = 0;j<G->numVertexes;j++)
            if(i != j)
                G->arc[i][j] = INFINITY;//为什么vexs要取地址这里不用
    for(k = 0;k<G->numEdges;k++)
    {
        printf("输入边（vi，vj）的i和j和权w\n");
        scanf("%d,%d,%d",&i,&j,&w);
        G->arc[i][j] = w;
        G->arc[i][j] = w;//无向图，对称矩阵
    }
}

void CreateALGraph(graphAdjList *G)
{
    int i,j,w,k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);
    for(i = 0;i<G->numVertexes;i++)
    {
        scanf(&G->adjList[i].data);
        G->adjList[i].firstedge = NULL;//边表置空
    }
    for(k = 0;k<G->numEdges;k++)
    {
        printf("输入边（vi，vj）的i，j以及权重w");
        scanf("%d,%d,%d",&i,&j,&w);

        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjList[i].firstedge;
        G->adjList[i].firstedge = e;

        e=(EdgeNode*)malloc(sizeof(EdgeNode));
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjList[j].firstedge;
        G->adjList[j].firstedge = e;
    }
}


/*********************临界矩阵**********************/
Boolean visited[MAXVEX];
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = true;
    printf("%c",G.vexs[i]);
    for(j = 0;j < G.numVertexes;j++)
    {
        if(G.arc[i][j] == 1 && !visited[j])
        {
            DFS(G,j);
        }
    }
}
void DFSTraverse(MGraph G)
{
    int i;
    for(i = 0;i < G.numVertexes;i++)
    {
        visited[i] = false;
    }
    for(i = 0;i < G.numVertexes;i++)
    {
        if(!visited[i])
        {
            DFS(G,i);
        }
    }
}

/*********************邻接表DFS**********************/
void DFS(graphAdjList GL,int i)
{
    EdgeNode  *p;
    visited[i] = true;
    printf("%c",GL.adjList[i].data);
    p = GL.adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
        {
            DFS(GL,p->adjvex);
        }
        p = p->next;
    }
}
void DFSTraverse(graphAdjList GL)
{
    int i;
    for(i = 0;i < GL.numVertexes;i++)
    {
        visited[i] = false;
    }
    for(i = 0;i < GL.numVertexes;i++){
        if(!visited[i])
        {
            DFS(GL,i);
        }
    }
}


/*********************邻接矩阵的广度遍历算法************/
void BFSTraverese(MGraph G)
{
    int i , j;
    Queue Q;//Queue 需要实现
    for(i = 0;i < G.numVertexes;i++)
    {
        visited[i] = false;
    }
    InitQueue(&Q);
    for(i = 0;i < G.numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            printf("%c ",G.vexs[i]);
            EnQueue(&Q,i);
            while(!QueueEmpty(Q))
            {
                DeQueue(&Q,&i);
                for(j = 0;j < G.numVertexes;j++)
                {
                    if(G.arc[i][j] == 1 && !visited[j])
                    {
                        visited[i] = true;
                        printf("%c ",G.vexs[j]);
                        EnQueue(&Q,j);
                    }
                }
            }
        }
    }
}

void MinSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX];//相关顶点下标
    int lowcost[MAXVEX];//顶点间边的权值
    lowcost[0] = 0;//第一个权值为0，V0加入生成树
    adjvex[0] = 0;//第一个定点下标为0
    for(i = 1;i < G.numVertexes;i++)
    {
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    for(i = 1; i < G.numVertexes; i++)
    {
        min = INFINITY;
        j = 1;
        k = 0;
        while(j < G.numVertexes)//循环全部顶点
        {
            if(lowcost[j] != 0 && lowcost[j] < min)
            {
                min = lowcost[j];//如果当前权值不为0且小于min
                k = j;//将当前最小值的下标存入k
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k] = 0;
        for(j = 1; j < G.numVertexes; j++)
        {
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}
/********************冒泡排序实现weight排序***************/
void sorte(Edge * e, int k)
{
    Edge temp;
    for(int i = 0; i < k-1; i++)
    {
        for(int j = i; j < k-1; j++)
        {
            if(e[j].weight < e[j+1].weight)
            {
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }
}

int Find(int *parent, int f)/*查找连线顶点的尾部下表*/
{
    while(parent[f] > 0)
    {
        f = parent[f];
    }
    return f;
}


void MiniSpanTree_Kruskal(MGraph G)
{
    int i, n, m;
    int MAXEDGE = G.numVertexes*G.numVertexes;
    Edge edges[MAXEDGE];
    int parent[MAXVEX];/*用来判断是否形成环路*/
    int k = 0;
    for(int q = 0;q < G.numVertexes;q++){
        for(int p = q+1 ;p < G.numVertexes;p++) {
            if (G.arc[p][q] < INFINITY) {
                edges[k].begin = q;
                edges[k].end = p;
                edges[k].weight = G.arc[p][q];
                k++;
            }
        }
    }
    /*采用冒牌排序实现weight排序*/
    sorte(edges,k);
    for(i = 0; i < G.numVertexes; i++){
        parent[i] = 0;/*初始化为0*/
    }
    for(i = 0; i < G.numVertexes; i++)/*循环每一条边*/{
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        if(n != m)/*如果n与m不相等，说明没有形成环路*/{
            parent[n] = m;/*将结尾顶点放入起点的parent中，表示顶点已经在生成树集合中*/
            printf("(%d,%d) %d ", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
void short_path_dijkstra(MGraph G,int v0, Patharc * P,ShortPathTable * D){
    int v,w,k,min;
    int final[MAXVEX] = {0};/*final[w] = 1表示w已经求得最短路径 */
    for(v = 0; v < G.numVertexes; v++){
        (*D)[v] = G.arc[v0][v];
        (*P)[v] = 0;
    }
    (*D)[v0] = 0;
    final[v0] = 1;
    for(v = 1; v < G.numVertexes; v++){
        min = INFINITY;
        for(w = 0; w < G.numVertexes; w++){
            if(!final[w] && (*D)[w] < min) {
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1;
        for(w = 0; w < G.numVertexes; w++){
            /*如果找到v的路径比现在短*/
            if(!final[w] && (min + G.arc[k][w] < (*D)[w])){
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}


void ShortestPath_Floyd(MGraph G, Pathmatrix *P,ShortPathTable_f *D){
    int v, w, k;
    for(v = 0; v < G.numVertexes; ++v){//初始化
        for(w = 0; w < G.numVertexes; ++w){
            (*D)[v][w] = G.arc[v][w];
            (*P)[v][w] = w;
        }
        for(k = 0; k < G.numVertexes; ++k){
            for(v = 0; v < G.numVertexes; ++v){
                for(w = 0; w < G.numVertexes; ++w){
                    if((*D)[v][w] > (*D)[v][k] + (*D)[k][v]){
                        (*D)[v][w] = (*D)[v][k] + (*D)[k][v];
                        (*P)[v][w] = (*P)[v][k];
                    }
                }
            }
        }
    }
}

void show_Floyd(int numVertexes,Pathmatrix P,ShortPathTable_f D){
    int v, w, k;
    for(v = 0; v < numVertexes; ++v){
        for(w = v+1; w <numVertexes; ++w){
            printf("v%d-v%d weight: %d",v,w,D[v][w]);
            k = P[v][w];
            printf(" path:%d,v");
            while(k != w){
                printf(" -> %d",k);
                k = P[k][w];
            }
            printf(" -> %d\n",w);
        }
        printf("\n");
    }
}
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/
/***********************************最短路径问题***************************************/

/***********************************拓扑排序***************************************/

/***********************************在AOV中将入度为0的顶点输出删除***************************************/
Status TopologicalSort(GraphAdjList GL){
    EdgeNode  *e;
    int i,k,gettop;
    int top = 0;/*栈下标*/
    int count = 0;/*统计输出点的个数*/
    int * stack = (int *)malloc(GL->numVertexes * sizeof (int));
    for( i = 0; i < GL->numVertexes; ++i){
        if(GL->adjList[i].in == 0){
            stack[++top] = i;
        }
    }
    while(top != 0){
        gettop = stack[top--];
        printf("%d -> ",GL->adjList[gettop].data);
        count++;
        for(e = GL->adjList[gettop].firstedge; e ;e=e->next){
            k = e->adjvex;
            if(!(--GL->adjList[k].in)){
                stack[++top] = k;
            }
        }
    }
    if(count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}

/***********************************拓扑排序***************************************/
/***********************************拓扑排序关键路径用***************************************/
Status TopologicalSort_cp(GraphAdjList GL){
    EdgeNode  *e;
    int i,k,gettop;
    int top = 0;/*栈下标*/
    int count = 0;/*统计输出点的个数*/
    int * stack = (int *)malloc(GL->numVertexes * sizeof (int));
    for( i = 0; i < GL->numVertexes; ++i){
        if(GL->adjList[i].in == 0){
            stack[++top] = i;
        }
    }
    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof (int));
    for( i = 0; i < GL->numVertexes; ++i){
        etv[i] = 0;
    }
    stack2 = (int *)malloc(GL->numVertexes * sizeof (int));

    while(top != 0){
        gettop = stack[top--];
        printf("%d -> ",GL->adjList[gettop].data);
        count++;
        stack2[++top2] = gettop;
        for(e = GL->adjList[gettop].firstedge; e ;e=e->next){
            k = e->adjvex;
            if(!(--GL->adjList[k].in)){
                stack[++top] = k;
            }
            if((etv[gettop]+e->weight > etv[k]))
                etv[k] = etv[gettop] + e->weight;
        }
    }
    if(count < GL->numVertexes)
        return ERROR;
    else
        return OK;
}
/****************************求最短路径************************/
void CriticalPath(GraphAdjList GL){
    EdgeNode *e;
    int i, gettop, k, j;
    int ete, lte;/*记录最早发生时间和最晚发生时间的变量*/
    TopologicalSort_cp(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof (int));
    for(i = 0; i < GL->numVertexes; ++i){
        ltv[i] = etv[GL->numVertexes-1];
    }
    while(top2!=0){
        gettop = stack2[top2--];
        for(e = GL->adjList[gettop].firstedge; e ; e = e->next){
            /*求最迟发生时间ltv*/
            k = e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
        for(j = 0; j < GL->numVertexes; ++j){/*求ete，lte和关键活动*/
            for(e = GL->adjList[j].firstedge; e; e = e->next){
                k = e->adjvex;
                ete = etv[j];
                lte = ltv[k] - e->weight;
                if( ete == lte)
                    printf("<v%d,v%d> length: %d , ", GL->adjList[j].data, GL->adjList[k].data, e->weight);
            }
        }
    }
}