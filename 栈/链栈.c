#include <stdio.h>
#include <stdlib.h>

// 链栈
#define ElemType int
typedef struct StackNode {
    ElemType data; //数据域
    struct StackNode  *next; //指针域
}StackNode,*StackP;

// 初始化
void InitStack(StackP *top){
    *top=NULL;
}

int Push(StackP *top,ElemType X){
    StackNode *newNode= (StackNode *)malloc(sizeof (StackNode));
    if(newNode==NULL){
        return 0;
    }
    newNode->data=X;
    newNode->next=*top;
    *top=newNode;
    return 1;
}
int main() {
    StackP top;
    InitStack(&top);
    Push(&top,10);
    printf("Hello, World!\n");
    return 0;
}
