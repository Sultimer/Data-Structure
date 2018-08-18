//
//  ADT Stack.h
//  3
//
//  Created by 宋连涛 on 2018/5/11.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_Stack_h
#define ADT_Stack_h

#define  STACK_INIT_SIZE  100
#define  STACKINCREMENT   10

typedef struct SqStack{
    SElemType *base;
    SElemType *top;
    int  stacksize;
} SqStack;

Status InitStack (SqStack &S)
{
    S.base = (SElemType*) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

Status StackEmpty (SqStack &S)
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

Status Push (SqStack &S, SElemType e)
{
    if(S.top - S.base >= S.stacksize)
    {
        S.base = (SElemType *) realloc(S.base, (S.stacksize+STACKINCREMENT) * sizeof(SElemType));
        if(!S.base)
            exit (OVERFLOW );
        S.top = S.base + S.stacksize;
        S.stacksize += STACKINCREMENT;
    }
    *S.top++ = e;
    return OK;
}

Status Pop (SqStack &S, SElemType &e)
{
    if (S.top == S.base)
        return ERROR;
    e = *--S.top;
    return OK;
}

Status GetTop (SqStack S, SElemType &e)
{
    if(S.top == S.base)
        return ERROR;
    e = *(S.top-1);
    return OK;
}

#endif /* ADT_Stack_h */
