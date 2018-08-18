#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100
using namespace std;

typedef struct  CSNode{
    char data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
void CreatTree(CSTree &T){
    char ch;
    scanf("%c", &ch);
    if(ch == '#') T = NULL;
    else {
        T = (CSTree)malloc(sizeof(CSNode));
        T->data = ch;
        CreatTree(T->firstchild);
        CreatTree(T->nextsibling);
    }
}

void InorderTraverse(CSTree T){
    CSNode *sta[maxn], *p;
    int top = -1;
    p = T;
    while(p || top != -1){
        while(p){sta[++top] = p; p = p->firstchild;}
        if(top != -1){
            p = sta[top--];
            printf("%c",p->data);
            p = p->nextsibling;
        }
    }
}
int ClacNumOfLeafNode(CSTree T){
    int res = 0;
    if(!T->firstchild) res++;
    if(T->firstchild) res += ClacNumOfLeafNode(T->firstchild);
    if(T->nextsibling) res += ClacNumOfLeafNode(T->nextsibling);
    return res;
}
int ClacNumOfTree(CSTree T){
    int res = 0;
    while(T){
        res++;
        T = T->nextsibling;
    }
    return res;
}
int DFS(CSTree T){
    int LDep = 1, RDep = 1;
    if(T->firstchild) LDep = DFS(T->firstchild) + 1;
    if(T->nextsibling) RDep = DFS(T->nextsibling);
    return max(LDep, RDep);
}
int ClacHeiOfFirTree(CSTree T){
    int res = 1;
    if(!T)return 0;
    res += DFS(T->firstchild);
    return res;
}

int main(){
    CSTree BigTree;
    printf("请输入BigTree:");
    CreatTree(BigTree);
    printf("森林的中序遍历:");
    InorderTraverse(BigTree);
    printf("\n");
    int NumOfLeafNode = ClacNumOfLeafNode(BigTree);
    int NumOfTree = ClacNumOfTree(BigTree);
    int HeiOfFirTree = ClacHeiOfFirTree(BigTree);
    printf("森林的叶子节点数:%d\n",NumOfLeafNode);
    printf("森林中树的颗数:%d\n",NumOfTree);
    printf("森林的第一颗树的高度:%d\n",HeiOfFirTree);
    return 0;
}


