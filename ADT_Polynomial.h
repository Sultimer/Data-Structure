//
//  ADT_Polynomial.h
//  3
//
//  Created by 宋连涛 on 2018/6/14.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_Polynomial_h
#define ADT_Polynomial_h


void InitPolyn (LinkList &L)
{
    L = (LinkList) malloc (sizeof(LNode));
    L->data.coef = -1;
    L->data.exp = -1;
    L->next = NULL;
}

void CreatPolyn(LinkList &L)
{
    int coef, exp;
    LinkList p;
    LinkList pre;
    
    int m;
    printf("多项式的项数：");
    scanf("%d",&m);
    
    printf("请输入多项式的系数、指数，中间以空格分开：\n");
    
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &coef, &exp);
        
        if (coef == 0)
            continue;
        
        LinkList newNode = (LinkList) malloc (sizeof(LNode));
        newNode->data.coef = coef;
        newNode->data.exp = exp;
        
        pre = L;
        p = L->next;
        
        while (true) {
            
            if (!p || exp<p->data.exp) { //终止条件：找到合适的位置或者找到头了
                pre->next = newNode;
                newNode->next = p;
                break;
            }
            
            if (exp > p->data.exp) { //位置不合适就后移
                pre = pre->next;
                p = p->next;
                
            } else if (p->data.exp == exp) { //等的情况单独处理
                p->data.coef += coef;
                if (p->data.coef == 0) {
                    pre->next = p->next;
                }
                break;
            }
        }
    }
    
}

void PrintPolyn(LinkList L){
    LNode *p = L->next;
    while(p != NULL)
    {
        if(fabs(fabs(p->data.coef) - 1) > 1e-6)printf("%g", p->data.coef);
        else if(p->data.exp == 0)printf("%g",p->data.coef);
        if(p->data.exp > 1)printf("x^%d", p->data.exp);
        else if (p->data.exp == 1)printf("x");
        if(p->next != NULL && (p->next)->data.coef > 0)printf("+");
        p = p->next;
    }
}

void Reverse(LinkList L)
{
    LinkList p = L->next;
    LinkList q = p->next;
    p->next = NULL;
    
    while (q) {
        LinkList r = q->next;
        L->next = q;
        q->next = p;
        
        p = L->next;
        q = r;
    }
}

void Compute(LinkList L)
{
    int x;
    printf("请输入自变量的值：");
    scanf("%d",&x);
    long sum = 0;
    LinkList p = L->next;
    
    while (p) {
        sum += p->data.coef * pow(x, p->data.exp);
        p = p->next;
    }
    
    printf("函数值为：%ld\n.",sum);
}

void AddPolyn(LinkList A, LinkList B)
{
    LinkList p = A->next;
    LinkList q = B->next;
    LinkList pre = A;
    LinkList u;
    
    while (true) {
        
        if (!q) //逐个取出q中元素
            return;
        
        u = q->next;
        
        while (true) { //处理这个节点
            if (!p || q->data.exp<p->data.exp) {
                pre->next = q;
                q->next = p;
                pre = q;
                break;
            }
            
            if (q->data.exp > p->data.exp) {
                pre = pre->next;
                p = p->next;
                
            } else if (p->data.exp == q->data.exp) {
                p->data.coef += q->data.coef;
                if (p->data.coef == 0) {
                    pre->next = p->next;
                }
                break;
            }
        }
        q = u;
    }
}


#endif /* ADT_Polynomial_h */
