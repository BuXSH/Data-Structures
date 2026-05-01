#include <stdio.h>
#include <stdlib.h>
#define ElemType int

// 不带头结点的单链表

typedef struct LNode{
    ElemType data; //数据域
    struct LNode *next; //指针域
}LNode,*LinkList;

// 初始化单链表(不带头结点)
int InitList(LinkList *L){
    *L = NULL;
    return 1;
}

// 判断单链表是否为空(不带头结点)
int Empty(LinkList L){
    if(L==NULL){
        return 1;
    } else{
        return 0;
    }
}
int main() {
    LinkList L;
    InitList(&L);
    return 0;
}
