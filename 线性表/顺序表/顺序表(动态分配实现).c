#include <stdio.h>
#include <stdlib.h>

// 顺序表的动态分配(SeqList)
// 特点：可增加容量
#define InitSize 10 //顺序表的初始长度
#define ElemType int //元素类型

typedef struct {
    ElemType *data; //动态分配的指针
    int MaxSize; //顺序表最大长度
    int length; //顺序表当前长度
}SeqList;

// 初始化顺序表
void InitList(SeqList *L){
    // 用malloc函数申请一片连续的存储空间
    L->data= (ElemType *)malloc(InitSize*sizeof(ElemType));
    L->length=0;
    L->MaxSize=InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList *L,int len){
    ElemType *p=L->data;
    // 用malloc函数申请一片新的连续的存储空间
    // 新表长度=旧表最大长度+新的长度
    L->data= (ElemType *)malloc((L->MaxSize+len)*sizeof(ElemType));
    // 旧空间的数据赋值给新空间
    for (int i = 0; i < L->length; ++i) {
        L->data[i]=p[i];
    }
    // 顺序表最大长度增加
    L->MaxSize=L->MaxSize+len;
    // 顺序表当前长度并没有增加，所以不用修改
    free(p);
}

// 顺序表的插入(平均时间复杂度：O(n))
// 注意： i是位序，是从1开始的，数组实际下标是从开始
// 参数：(顺序表，位序，值)
int ListInsert(SeqList *L,int i,ElemType e){
    // 1.判断插入位置是否合法
    // 插入逻辑上小于1的位置或者不是连续存储都不合法
    if (i<1 || i>L->length+1) {
        return 0;
    }
    // 当前表长大于等于初始长度，说明没有空间插入
    if (L->length>=L->MaxSize) {
        return 0;
    }
    // 2.将第i个位置之后的元素往后移动
    // 从最后一位元素往后移动
    for (int j = L->length-1; j >= i-1; --j) {
        L->data[j+1]=L->data[j];
    }
    // 3.插入操作
    // 赋值
    L->data[i-1]=e;
    // 表长加1
    L->length++;

    return 1;
}

// 顺序表的删除(平均时间复杂度：O(n))
// 注意： i是位序，是从1开始的，数组实际下标是从开始
// 参数：(顺序表，位序，接收被删除的元素的值(需要*))
int DeleteList(SeqList *L,int i,ElemType *d){
    // 1.判断删除位置是否合法
    // 删除逻辑上小于1的位置或者大于表长的位置都不合法
    if (i<1 || i>L->length) {
        return 0;
    }

    // 2.返回被删除的值
    // 注意：需要修改主函数中的变量，加上*
    *d=L->data[i-1];

    // 3.删除操作
    // 把被删除元素后的元素往前移
    for (int j = i; j < L->length; ++j) {
        L->data[j-1]=L->data[j];
    }
    // 表长减1
    L->length--;

    return 1;
}

// 按值查找(平均时间复杂度：O(n))
// 参数：(顺序表，查找的值)
// 返回值：位序
int LocateElem(SeqList L,int e){
    for (int i = 0; i < L.length; ++i) {
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

// 按位查找(时间复杂度：O(1))
// “随机存取”的特性
// 参数：(顺序表，位序)
// 返回值：值
ElemType GetElem(SeqList L,int i){
    return L.data[i-1];
}

// 输出
void PrintList(SeqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
}

int main() {
    SeqList L;
    InitList(&L);
    IncreaseSize(&L,2);
    L.data[0]=10;
    L.data[1]=20;
    L.data[2]=30;
    L.data[3]=40;
    L.length=4;

    ListInsert(&L,2,22);
    PrintList(L);

    int d;
    DeleteList(&L,5,&d);
    printf("Delete:%d\n",d);
    PrintList(L);

    printf("30 LocateElem:%d\n",LocateElem(L,30));
    printf("1 GetElem:%d\n",GetElem(L,1));
    return 0;
}
