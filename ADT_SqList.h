//
//  ADT_SqList.h
//  3
//
//  Created by 宋连涛 on 2018/6/20.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_SqList_h
#define ADT_SqList_h

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct {
    int length;
    int listsize;
    ElemType *elem;
} SqList;

Status InitList_Sq(SqList &L)
{
    L.elem = (ElemType*) malloc (LIST_INIT_SIZE * sizeof(ElemType));
    
    if (!L.elem)
        exit(OVERFLOW);
    
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}

void CreatSqList(SqList &L)
{
    int i, elem;
    printf("元素个数：\n");
    scanf("%d", &L.length);
    
    for (i=0; i<L.length; i++) {
        scanf("%d", &elem);
        *(L.elem + i) = elem;
    }
}


int LocationElem(SqList L, ElemType e)
{
    int i = 1;
    ElemType *p = L.elem;
    while (*p!=e && i<=L.length){
        i++;
        p++;
    }
    if (i <= L.length)
        return i;
    else
        return 0;
}


Status ListInsert(SqList &L, int i, ElemType e)
{
    ElemType *p, *q;
    
    if (i<1 || i>L.length+1)
        return ERROR;
    
//    ElemType *newbase;
//    if (L.length == L.listsize)
//    {
//        newbase = (ElemType *) realloc (L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
//        if (!newbase)
//            exit(OVERFLOW);
//        L.elem = newbase;
//        L.listsize += LISTINCREMENT;
//    }
    
    q = &(L.elem[i-1]);
    for (p = &(L.elem[L.length-1]); p>=q; --p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}

Status ListDelete(SqList &L, int i, ElemType &e)
{
    ElemType *p, *q;
    
    if (i<1 || i>L.length)
        return ERROR;
    
    p = L.elem + i - 1;
    e = *p;
    q = L.elem + L.length - 1;
    
    for (++p; p<=q; ++p)
        *(p-1) = *p;
    
    --L.length;
    return OK;
}

void PrintSqList(SqList L)
{
    int i;
    for (i=0; i<L.length; i++) {
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}


#endif /* ADT_SqList_h */
