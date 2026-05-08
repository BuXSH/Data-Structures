#include <stdio.h>

// 顺序栈
// 容量不能增加，会栈溢出
#define MaxSize 20
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top; //栈顶指针
}SqStack;

// 初始化栈
// 需要修改栈S
void InitStack(SqStack *S){
    S->top=-1; //栈顶指针为-1表示空栈
}

// 判断栈是否为空
// 不需要修改栈S
int StackEmpty(SqStack S){
    return S.top==-1;
}

// 入栈操作
// 需要修改栈S
// 参数X：入栈的元素
int Push(SqStack *S,ElemType X){
    if(S->top==MaxSize-1){
        return 0;
    }
    S->top++;
    S->data[S->top]=X;
    return 1;
}

// 出栈操作
// 需要修改栈S
// 参数X：保存出栈的元素的值 注意：传进来的是内存地址
// 逻辑上删除了栈顶元素，但在实际的内存中数据仍然存在
int Pop(SqStack *S,ElemType *X){
    if(S->top==-1){
        return 0;
    }
    *X=S->data[S->top]; //注意*
    S->top--;
    return 1;
}

// 读栈顶元素
// 不需要修改栈S
// 参数X：保存栈顶元素的值 注意：传进来的是内存地址
int GetTop(SqStack S,ElemType *X){
    if(S.top==-1){
        return 0;
    }
    *X=S.data[S.top];
    return 1;
}

int main() {
    SqStack S;
    InitStack(&S);
    printf("%d\n",StackEmpty(S));
    Push(&S,12);
    Push(&S,1);
    Push(&S,2);
    Push(&S,3);
    int a;
    Pop(&S,&a);
    printf("%d\n",a);
    return 0;
}
