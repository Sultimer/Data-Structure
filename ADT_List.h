//
//  ADT_List.h
//  3
//
//  Created by 宋连涛 on 2018/6/14.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#ifndef ADT_List_h
#define ADT_List_h

typedef struct LNode{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;


#endif /* ADT_List_h */
