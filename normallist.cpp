#include "Default.h"

typedef int ElemType;
#include "ADT_List.h"
#include "ADT_normalList.h"

void Uniquify(LinkList &A, LinkList &B, LinkList &C)
{
    LinkList p = A->next;
    LinkList u = B->next;
    LinkList v = C->next;

    LinkList pre = A;
    
    while (true) {
        
        while (true) { //找出B和C中相同的元素
            
            if (!u || !v) //出口1
                return;
            
            if (u->data < v->data) {
                u = u->next;
            } else if (u->data > v->data) {
                v = v->next;
            } else
                break;
        }
        
        while (true) {
            
            if (!p) //出口2
                return;
            
            if (p->data < u->data) { //找到A中合适删除的位置
                pre = pre->next;
                p = p->next;
            } else if (p->data == u->data) { //如果有相同元素，删
                pre->next = p->next;
                p = pre->next;
            } else {
                break;
            }
        }
        
        u = u->next; //进入下一轮循环
        v = v->next;
    }
}

void merge(LinkList &pa, LinkList &pb, LinkList &C)
{
    C = pa;
    LinkList p = pa->next;
    LinkList q = pb->next;
    LinkList temp, u;

    pa->next = NULL;
    
    while (true) {
        if (!p && !q) //p、q都空
            return;
        
        if ((!q && p) || (p && q && p->data <= q->data)) { //q空p不空  或  q不空且p不空
        //if (!q || (p && p->data <= q->data))
            
            if (p->data == q->data)
                q = q->next;
            
            temp = p->next;
            u = pa->next;
            pa->next = p;
            p->next = u;
            p = temp;
            
        } else if ((!p && q) || (p && q && p->data > q->data)) { //p空q不空  或  p不空且q不空
        //else if (!p || (q && p->data > q->data))
            temp = q->next;
            u = pa->next;
            pa->next = q;
            q->next = u;
            q = temp;
        }
    }
}



int main ()
{
    LinkList A, B, C;
    InitList(A);
    InitList(B);
    InitList(C);
    printf("A：\n");
    InPut(A);
    printf("B：\n");
    InPut(B);
    printf("C：\n");
    InPut(C);
//    Uniquify(A, B, C);
    merge(A, B, C);

    OutPut(C);
    return 0;
    
}
