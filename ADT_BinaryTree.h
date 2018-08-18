//
//  ADT_BinaryTree.h
//  3
//
//  Created by 宋连涛 on 2018/5/11.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_BinaryTree_h
#define ADT_BinaryTree_h

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

Status CreateBiTree (BiTree &T)
{
    char ch;
    scanf("%c",&ch);
    
    if(ch=='#')
        T = NULL;
    else {
        if(!(T = (BiTNode *) malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree (T->lchild);
        CreateBiTree (T->rchild);
    }
    return OK;
}

typedef struct PTNode
{
    TElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAXSIZE];
    int n;
} Ptree;

void InitPNode(Ptree &tree)
{
    int i,j;
    char ch;
    printf("The number of nodes:\n");
    scanf("%d",&(tree.n));
    
    printf("The data of nodes and their parents' number:\n");
    for(i=0; i<tree.n; i++)
    {
        getchar();
        scanf("%c,%d",&ch,&j);
        tree.nodes[i].data = ch;
        tree.nodes[i].parent = j;
    }
    tree.nodes[0].parent = -1;
}


#endif /* ADT_BinaryTree_h */
