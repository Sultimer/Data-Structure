//
//  polynomial.cpp
//  3
//
//  Created by 宋连涛 on 2018/6/14.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#include "Default.h"

typedef struct {
    float coef;
    int exp;
} polynomial;

typedef polynomial ElemType;
#include "ADT_List.h"
#include "ADT_Polynomial.h"

int main()
{
//    LinkList L;
//    InitPolyn(L);
//    CreatPolyn(L);
//    PrintPolyn(L);
//
//    Reverse(L);
//    printf("逆置后的");
//    PrintPolyn(L);
//    Compute(L);

    LinkList A, B;
    printf("需要您输入两个多项式，");
    InitPolyn(A);
    CreatPolyn(A);

    InitPolyn(B);
    CreatPolyn(B);

    
    AddPolyn(A, B);
    PrintPolyn(A);
    
    return 0;
}
