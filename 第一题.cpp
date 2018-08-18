#include<cstdio>
#include<iostream>
#include<cstring>
#define maxn 100
using namespace std;
typedef struct BiTNode{
    char data;
    BiTNode *lc, *rc;
}BiTNode, *BiTree;
void CreatTree(BiTree &T){
    char ch;
    scanf("%c", &ch);
    if(ch == '#') T = NULL;
    else {
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = ch;
        CreatTree(T->lc);
        CreatTree(T->rc);
    }
}
bool Check(BiTree T){//时间复杂度O(n)
    //层次遍历检查是否为完全二叉树
    //1.如果该节点无左儿子、有右儿子，则一定不是完全二叉树
    //2.如果该节点为叶子节点，则后面的节点也一定是叶子节点
    //3.如果该节点有左儿子、无右儿子，则后面的节点也一定是叶子节点
    BiTNode *que[maxn];
    if(T == NULL || (!T->lc && !T->rc))return true;
    //如果根节点为空或者只有根节点，则是完全二叉树
    int f, r;
    bool flag = true;//标记
    f = r = 0;
    if(T->lc && !T->rc)flag = false;
    que[r++] = T;
    while(f != r){
        BiTNode *u = que[f++];
        if(flag){
            if(u->lc && u->rc){
                que[r++] = u->lc;
                que[r++] = u->rc;
            }
            else if(!u->lc && u->rc)return false;
            else if((!u->lc && !u->rc) || (u->lc && !u->rc)){
                flag = false;
            }
        }
        else if(u->lc || u->rc)return false;
    }
    return true;
}
int main(){
    BiTree T;
    CreatTree(T);
    printf("%s\n",Check(T)?"Yes":"No");
    return 0;
}
