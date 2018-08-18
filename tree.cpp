//
//  main.cpp
//  3
//
//  Created by 宋连涛 on 2018/5/11.
//  Copyright © 2018年 宋连涛. All rights reserved.
//


#include "Default.h"

typedef char TElemType;
#include "ADT_BinaryTree.h"

typedef BiTree QElemType;
#include "ADT_Queue.h"

typedef BiTree SElemType;
#include "ADT_Stack.h"


//递归描述遍历
void RecursionTraverse (BiTree T)
{
    if(T == NULL)
        return;

    printf("%c ", T->data);
    RecursionTraverse(T->lchild);
    RecursionTraverse(T->rchild);

    putchar('\n');
}

//先序遍历非递归描述
void PreOrderTraverse (BiTree T)
{
    BiTree p = T;
    SqStack S;
    InitStack(S);

    while(true)
    {
        while (p) {
            printf("%c ", p->data);
            Push(S, p->rchild);
            p = p->lchild;
        }

        if(StackEmpty(S))
            break;

        Pop(S,p);
    }
    putchar('\n');
}

void PreOrderTraverse2 (BiTree T)
{
    BiTree p = T;
    SqStack S;
    InitStack(S);

    Push(S, T);
    while (true) {
        if(StackEmpty(S))
            break;

        Pop(S,p);
        printf("%c ", p->data);

        if (p->rchild)
            Push(S, p->rchild);
        if (p->lchild)
            Push(S, p->lchild);
    }

    putchar('\n');
}

//中序遍历非递归
void InOrderTraverse (BiTree T)
{
    BiTree p = T;
    SqStack S;
    InitStack(S);

    while(true)
    {
        while(p) {
            Push(S, p);
            p = p->lchild;
        }

        if(StackEmpty(S))
            break;

        Pop(S,p);
        printf("%c ", p->data);
        p = p->rchild;

    }
    putchar('\n');
}

//后序遍历非递归
void PostOrderTraverse (BiTree T)
{
    BiTree p = T, flag = NULL;
    SqStack S;
    InitStack(S);

    while(true) {

        while(p) {
            Push(S, p);
            p = p->lchild;
        }

        if (StackEmpty(S))  break;

        GetTop(S, p); //p can't have a left child or its left child must have already been visited.
        if (p->rchild == NULL || flag == p->rchild){
            Pop(S, p);
            printf("%c ", p->data);
            flag = p;
            p = NULL;
        } else { //have a right child and it doesn't equal to flag.
            p = p->rchild;
        }

    }
}

//利用循环队列设计非递归算法实现二叉树的层次遍历
int h[maxn],maxh;
void Traverse(BiTree T){
    int f, r;
    BiTNode *q[maxn];
    int qt[maxn];

    f = r = 0;
    r = (r + 1) % maxn;
    q[r] = T;
    qt[r] = 1;
    h[1]++;
    maxh = (maxh > qt[r])? maxh: qt[r];
    while(f != r)
    {
        f = (f + 1) % maxn;
        BiTNode *u = q[f];
        printf("%c",u->data);
        if(u->lchild)
        {
            r = (r + 1) % maxn;
            q[r] = u->lchild;
            qt[r] = qt[f] + 1;
            h[qt[r]]++;
            maxh = (maxh > qt[r])? maxh: qt[r];
        }
        if(u->rchild)
        {
            r = (r + 1) % maxn;
            q[r] = u->rchild;
            qt[r] = qt[f] + 1;
            h[qt[r]]++;
            maxh = (maxh > qt[r])? maxh: qt[r];
        }
    }
}

//设计非递归算法求二叉树的宽度(即:每层结点数的最大值)。
void Width(){
    int res = 0;
    for(int i = 1; i <= maxh; i++)
        res = (res > h[i])? res: h[i];
    printf("%d\n", res);
}

//采用二叉链表存储表示，设计算法判断一个二叉树是否为完全二叉树。
void CompleteBiTree(BiTree T)
{
    BiTree p = T;
    SqQueue Q;
    InitQueue(Q);

    while (p->lchild && p->rchild) {
        EnQueue(Q, p->lchild);
        EnQueue(Q, p->rchild);
        DeQueue(Q, p);
    }

    if (!p->lchild && p->rchild){
        printf("不是完全二叉树\n");
        return;
    }
    
    if (p->lchild && !p->rchild)
        EnQueue(Q, p->lchild);
    
    while (!QueueEmpty(Q)) {
        DeQueue(Q, p);
        if (p->lchild || p->rchild) {
            printf("不是完全二叉树\n");
            return;
        }
    }
    printf("是完全二叉树\n");
}

//计算森林中一共有几棵树
void TreeCount (BiTree T)
{
    BiTree p = T;
    int cnt = 1;
    while(p->rchild) {
        cnt++;
        p = p->rchild;
    }
    printf("There are %d trees in the forest.\n", cnt);
}

//求森林中第一棵树的高度
int Bi_Height (BiTree T)
{
    if(!T) return 0;
    return max(Bi_Height(T->lchild)+1, Bi_Height(T->rchild));
}

//树以双亲表示法存放，设计算法求树的高度。
void P_Height(Ptree &tree)
{
    int max=0, height, p=0;

    for(int i=0; i<tree.n; i++)
    {
        height = 1;
        p = tree.nodes[i].parent;

        while(p != -1) {
            p = tree.nodes[p].parent;
            height++;
        }

        if(height > max)
            max = height;
    }
    printf("The depth is %d.\n",max);
}

//设二叉树以二叉链表形式存放，用类C语言设计非递归算法判断一棵根结点为T的二叉树是否为二叉排序树。
void isBinarySortTree(BiTree T)
{
    BiTree p = T;
    SqStack S;
    InitStack(S);
    int pre = 0;

    while (true) {
        while (p) {
            Push(S, p);
            p = p->lchild;
        }
        if (StackEmpty(S))
            break;
        Pop(S, p);
        if (p->data < pre) {
            printf("不是二叉排序树\n");
            return;
        } else {
            pre = p->data;
        }
        p = p->rchild;
    }
    printf("是二叉排序树\n");
}

//设二叉排序树以二叉链表形式存放，用类C语言设计非递归算法从大到小输出一棵根结点为T的二叉树所有不小于k的数据元素。
void largerk (BiTree T, int k)
{
    BiTree p = T;
    SqStack S;
    InitStack(S);

    while(true)
    {
        while(p) {
            Push(S, p);
            p = p->rchild;
        }

        if(StackEmpty(S))
            break;

        Pop(S,p);

        if (p->data >= k) {
            printf("%d ", p->data);
        } else {
            break;
        }

        p = p->lchild;

    }
    putchar('\n');
}

int main()
{
    BiTree Tree;
    printf("Please input the binary tree:\n");
    CreateBiTree(Tree);

    CompleteBiTree(Tree);
//    isBinarySortTree(Tree);
//
//    int k;
//
//    printf("Please input the number k:\n");
//    scanf("%d", &k);
//    printf("These numbers are:\n");
//    largerk(Tree, k);
//
//
//    BiTree T;
//    printf("请输入二叉树先序遍历：");
//    CreateBiTree(T);
//
//    printf("层次遍历的结果为：");
//    Traverse(T);
//    printf("\n");
//
//    printf("二叉树的宽度为：");
//    Width();

    return 0;
}
