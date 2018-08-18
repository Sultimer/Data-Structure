//
//  sqlist.cpp
//  3
//
//  Created by 宋连涛 on 2018/6/20.
//  Copyright © 2018年 宋连涛. All rights reserved.
//

#include "Default.h"

typedef int ElemType;
#include "ADT_SqList.h"

void search(SqList L, int x)
{
    L.elem[0] = x;
    
    int k = L.length;
    ElemType *p;
    
    while (true) {
        p = L.elem + k - 1; //p初始指向表尾元素
        
        if (*p == x) {
            printf("%d\n", k);
            return;
        }
        k--;
    }
}

void binarySearch(SqList L, int x)
{
    int low = 0;
    int high = L.length-1;
    int mid;
    
    while (true) {
        if (high < low) {
            printf("查找失败.\n");
            return;
        }
        
        mid = (high + low) >> 1;
        if (*(L.elem + mid) == x) {
            printf("%d", mid+1);
            return;
        } else if (*(L.elem + mid) < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
}

int partition(SqList &L, int low, int high)
{
    L.elem[0] = L.elem[low];
    
    while (low < high) {
        while ((low < high) && (L.elem[high] >= L.elem[0]))
            high--;
        
        if (low < high) {
            L.elem[low] = L.elem[high];
            low++;
        }
        
        while ((low < high) && (L.elem[low] < L.elem[0]))
            low++;
        
        if (low < high) {
            L.elem[high] = L.elem[low];
            high--;
        }
    }
    L.elem[low] = L.elem[0];
    return low;
}

void QuickSort(SqList &L, int low, int high)
{
    int bin;
    if (low < high) {
        bin = partition(L, low, high);
        QuickSort(L, low, bin-1);
        QuickSort(L, bin+1, high);
    }
}

int main(){
    
    SqList L;
    InitList_Sq(L);
    CreatSqList(L);
//    int x;
//    printf("要查找的元素：");
//    scanf("%d", &x);
//    binarySearch(L, x);
    
    QuickSort(L, 1, 7);
    PrintSqList(L);
    
    return 0;
}
