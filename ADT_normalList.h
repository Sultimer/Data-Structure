//
//  ADT_normalList.h
//  3
//
//  Created by 宋连涛 on 2018/6/15.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_normalList_h
#define ADT_normalList_h


void InitList (LinkList &L)
{
    L = (LinkList) malloc (sizeof(LNode));
    L->data = -1;
    L->next = NULL;
}

void InPut(LinkList &L)
{
    int number, data;
    LinkList pre = L;
    LinkList p = L->next;

    printf("链表的元素个数：");
    scanf("%d",&number);
    printf("链表元素:");
    for(int i = 0; i < number; i++)
    {
        scanf("%d", &data);
        LinkList newNode = (LinkList) malloc (sizeof(LNode));
        newNode->data = data;

        pre->next = newNode;
        newNode->next = p;
        pre = pre->next;

    }
}

void OutPut(LinkList L)
{
    LinkList p = L->next;

    printf("去重后元素有：");
    while (p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
}



#endif /* ADT_normalList_h */
