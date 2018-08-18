//
//  ADT——Gragh.h
//  3
//
//  Created by 宋连涛 on 2018/5/20.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT__Gragh_h
#define ADT__Gragh_h

#define INF 1e9
#define MAX_VERTEX_NUM 20

typedef struct ArcNode{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode ;

typedef struct VNode{
    char data;
    ArcNode *firstarc;
} VNode;

typedef struct ALGraph{
    int vexnum;
    int arcnum;
    VNode vertices[MAX_VERTEX_NUM];  //顶点数组
} ALGraph;

void CreateGraph(ALGraph &G){
    
    scanf("%d%d", &G.vexnum, &G.arcnum);
    getchar();
    
    //先建立不带边的图
    int cnt;
    for(cnt=0; cnt<G.vexnum; cnt++){
        scanf("%c", &G.vertices[cnt].data);
        G.vertices[cnt].firstarc = NULL;
    }
    
    //添加边
    int Source, Destination;
    for(cnt=0; cnt<G.arcnum; cnt++){
        scanf("%d%d", &Source, &Destination);
        ArcNode *newArcNode;
        newArcNode = (ArcNode *) malloc(sizeof(ArcNode));
        newArcNode->adjvex = Destination;
        newArcNode->nextarc = G.vertices[Source].firstarc;
        G.vertices[Source].firstarc = newArcNode;
    }
}

void CreateGraph2(ALGraph &G){
    
    scanf("%d%d", &G.vexnum, &G.arcnum);
    getchar();
    
    //先建立不带边的图
    int cnt;
    for(cnt=0; cnt<G.vexnum; cnt++){
        scanf("%c", &G.vertices[cnt].data);
        G.vertices[cnt].firstarc = NULL;
    }
    
    //添加边
    int Source, Destination, Weight;
    for(cnt=0; cnt<G.arcnum; cnt++){
        scanf("%d%d%d", &Source, &Destination, &Weight);
        ArcNode *newArcNode;
        newArcNode = (ArcNode *) malloc(sizeof(ArcNode));
        newArcNode->adjvex = Destination;
        newArcNode->weight = Weight;
        newArcNode->nextarc = G.vertices[Source].firstarc;
        G.vertices[Source].firstarc = newArcNode;
    }
}

#endif /* ADT__Gragh_h */
