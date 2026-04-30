#include <stdio.h>

// 顺序表的静态分配(SqList)
// 特点：大小固定，不可增加容量
#define MaxSize 10 //顺序表的初始长度
#define ElemType int //元素类型

// 结构体
typedef struct {
    ElemType data[MaxSize]; //申请时数组大小已固定
    int length; //顺序表当前长度
}SqList;

// 初始化顺序表
void InitList(SqList *L){
    for (int i = 0; i < MaxSize; ++i) {
        L->data[i]=0;
    }
    L->length=0;
}

// 顺序表的插入(平均时间复杂度：O(n))
// 注意： i是位序，是从1开始的，数组实际下标是从开始
// 参数：(顺序表，位序，值)
int ListInsert(SqList *L,int i,ElemType e){
    // 1.判断插入位置是否合法
    // 插入逻辑上小于1的位置或者不是连续存储都不合法
    if (i<1 || i>L->length+1) {
        return 0;
    }
    // 当前表长大于等于初始长度，说明没有空间插入
    if (L->length>=MaxSize) {
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
int DeleteList(SqList *L,int i,ElemType *d){
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
int LocateElem(SqList L,int e){
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
ElemType GetElem(SqList L,int i){
    return L.data[i-1];
}

// 输出
void PrintList(SqList L){
    for (int i = 0; i < L.length; ++i) {
        printf("data[%d]=%d\n",i,L.data[i]);
    }
}

int main() {
    SqList L;
    InitList(&L);
    L.data[0]=1;
    L.data[1]=12;
    L.data[2]=23;
    L.data[3]=34;
    L.data[4]=45;
    L.data[5]=56;
    L.data[6]=67;
    L.length=7;

    int e=9;
    int result=ListInsert(&L,1,e);
    printf("result=%d\n",result);

    PrintList(L);

    int d;
    DeleteList(&L,3,&d);
    printf("Delete=%d\n",d);

    PrintList(L);

    printf("56 LocateElem:%d\n",LocateElem(L,56));
    printf("4 GetElem:%d\n",GetElem(L,4));
    return 0;
}
