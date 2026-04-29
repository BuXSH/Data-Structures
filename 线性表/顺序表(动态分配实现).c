//顺序表的动态分配(SeqList)

#define InitSize 10 //顺序表的初始长度
#define ElemType int //元素类型

typedef struct {
    ElemType *data; //动态分配的指针
    int MaxSize; //顺序表最大长度
    int length; //顺序表当前长度
}SeqList;

//初始化顺序表
void InitList(SeqList *L){
    //用malloc函数申请存储空间
    L->data= (ElemType *)malloc(InitSize*sizeof(ElemType));
    L->length=0;
    L->MaxSize=InitSize;
}
