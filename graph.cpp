//
//  7.cpp
//  3
//
//  Created by 宋连涛 on 2018/5/17.
//  Copyright © 2018年 宋连涛. All rights reserved.
//


#include "Default.h"
#include "ADT_Gragh.h"

typedef int QElemType;
#include "ADT_Queue.h"


//第9题：设表达式采用有向无环图表示，设计算法求表达式的逆波兰式。

void RPN(ALGraph G, int vertex){
    
    for(ArcNode *p = G.vertices[vertex].firstarc; p != NULL; p = p->nextarc){
        int w = p->adjvex;
        RPN(G, w);
    }
    printf("%c", G.vertices[vertex]. data);
}

//第10题：图采用邻接表存放，设计算法求图中顶点i到顶点j的最短路径（说明：路径长度为路径上边的数量）。
void Minist(ALGraph G, int i, int j){
    
    int cnt, vertex;
    int Dist[MAX_VERTEX_NUM], Pre[MAX_VERTEX_NUM];
    
    for(cnt=0; cnt<G.vexnum; cnt++){
        Dist[cnt] = -1;
        Pre[cnt] = -1;
    }
    Dist[i] = 0;
    
    SqQueue Q;
    InitQueue(Q);
    EnQueue(Q, i);
    
    while (true) {
        
        if (QueueEmpty(Q))
            break;
        
        DeQueue(Q, vertex);
        
        for(ArcNode *p=G.vertices[vertex].firstarc; p!= NULL; p = p->nextarc){
            
            if (Dist[p->adjvex]==-1) {
                Dist[p->adjvex] = Dist[vertex] + 1;
                Pre[p->adjvex] = vertex;
                EnQueue(Q, p->adjvex);
            }
            
        }
    }
    printf("最短路径长度为%d。\n", Dist[j]);
}

//习题集7.22：通过深度优先搜索判断顶点i与j之间是否存在路径。
/*
 DFS（顶点v）
 {
    标记v为已遍历；
    for（对于每一个邻接v且未标记遍历的点u）
        DFS（u）;
 }
 */

void DFS(ALGraph G, int vertex, bool visit[]){
    
    visit[vertex] = true;
    
    for(ArcNode *p = G.vertices[vertex].firstarc; p != NULL; p = p->nextarc){
        if(!visit[p->adjvex])
            DFS(G, p->adjvex, visit);
    }
}

void isPath(ALGraph G, int i, int j){
    
    bool visit[MAX_VERTEX_NUM];
    memset(visit, false, sizeof(visit));
    DFS(G, i, visit);
    
    if(visit[j])
        printf("存在路径。\n");
    else
        printf("不存在路径。\n");
}

void Prim(ALGraph G){
    
    bool visit[MAX_VERTEX_NUM];
    int dist[MAX_VERTEX_NUM];
    
    int i, j=0, k=0, cnt, min;
    ArcNode *p;
    
    for (i=0; i<G.vexnum; i++) {
        visit[i] = false;
        dist[i] = INF;
    }
    visit[0] = true;
    dist[0] = 0;
    
    for (cnt=0; cnt<G.vexnum; cnt++) {

        printf("%d", k);
        p = G.vertices[j].firstarc;
        while (true) {
            if (!p)
                break;
            dist[p->adjvex] = (p->weight < dist[p->adjvex]) ? p->weight : dist[p->adjvex];
            p = p->nextarc;
        }
        
        k = 1;
        min = dist[1];
        for (i=1; i<G.vexnum; i++) {
            if (!visit[i] && dist[i]<min) {
                k = i;
                min = dist[i];
            }
        }
        
        visit[k] = true;
        j = k;
    }
    putchar('\n');
}


//习题集7.42：以邻接表作为存储结构实现求从源点到其余各点的最短路径的Dijkstra算法。
int ShortestPath_DIJ(ALGraph G, int s, int t){

    bool visit[MAX_VERTEX_NUM];
    int dist[MAX_VERTEX_NUM];
    int pre[MAX_VERTEX_NUM];
    
    int i, j, k=s;
    for(i = 0; i < G.vexnum; i++){
        visit[i] = false;
        dist[i] = INF;
    }
    dist[s] = 0;
    pre[s] = -1;
    
    for(i = 0; i < G.vexnum; i++)
    {
        int min = INF;
        
        for(j = 0; j < G.vexnum; j++) {
            if(!visit[j] && dist[j] < min){
                k = j;
                min = dist[j];
            }
        }
        visit[k] = true;
    
        for(ArcNode *p = G.vertices[k].firstarc; p != NULL; p = p->nextarc) {
            if(!visit[p->adjvex] && dist[p->adjvex] > dist[k]+p->weight) {
                dist[p->adjvex] = dist[k]+p->weight;
                pre[p->adjvex] = k;
            }
        }
    }
    return dist[t];
}


void Floyd(int G[10][10], int N)
{
    int i, j, k, D[10][10], path[10][10];
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++) {
            D[i][j] = G[i][j];
            path[i][j] = -1;
        }

    for(k = 0; k < N; k++)
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                if( D[i][k] + D[k][j] < D[i][j] ) {
                    D[i][j] = D[i][k] + D[k][j];
                    path[i][j] = k;
                }
}

int main(){
    ALGraph G;
    
    CreateGraph(G);
    RPN(G, 0);
    printf("\n");
//    Minist(G, 1, 11);
//    isPath(G, 3, 11);
    
//    CreateGraph2(G);
//    Prim (G);
//    Dijkstra(G, 0);

    return 0;
}

