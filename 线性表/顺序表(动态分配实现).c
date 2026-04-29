#include <stdio.h>
#include <stdlib.h>
// 顺序表的动态分配(SeqList)

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

int main() {
    SeqList L;
    InitList(&L);
    IncreaseSize(&L,2);
    L.data[0]=10;
    L.length++;
    L.data[1]=20;
    L.length++;
    printf("L.data[1]=%d\n",L.data[1]);
    return 0;
}