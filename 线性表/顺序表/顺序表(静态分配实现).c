//顺序表的静态分配(SqList)

#define MaxSize 10 //顺序表的初始长度
#define ElemType int //元素类型

typedef struct {
    ElemType data[MaxSize];
    int length; //顺序表当前长度
}SqList;

//初始化顺序表
void InitList(SqList *L){
    for (int i = 0; i < MaxSize; ++i) {
        L->data[i]=0;
    }
    L->length=0;
}

int main() {
    SqList L;
    InitList(&L);
    return 0;
}