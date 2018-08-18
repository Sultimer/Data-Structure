//
//  ADT Queue.h
//  3
//
//  Created by 宋连涛 on 2018/5/11.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_Queue_h
#define ADT_Queue_h


#define MAXQSIZE 100

typedef struct SqQueue {
    QElemType *base;
    int front;
    int rear;
} SqQueue;

Status InitQueue (SqQueue &Q)
{
    Q.base = (QElemType*) malloc(MAXQSIZE * sizeof(QElemType));
    Q.front = Q.rear = 0;
    return OK;
}

Status EnQueue (SqQueue &Q, QElemType e)
{
    if((Q.rear+1) % MAXQSIZE == Q.front)
        return ERROR;
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1) % MAXQSIZE;
    return OK;
}

Status DeQueue (SqQueue &Q, QElemType &e)
{
    if(Q.front == Q.rear)
        return ERROR;
    e = Q.base[Q.front];
    Q.front = (Q.front+1) % MAXQSIZE;
    return OK;
}

Status QueueEmpty (SqQueue Q)
{
    if(Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

#endif /* ADT_Queue_h */
