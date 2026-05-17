#include <stdio.h>

#define MaxVerNum 20 // 顶点数目的最大值
// 邻接矩阵存储的无向图结构
typedef struct {
    char Vex[MaxVerNum];            // 顶点表，存储顶点信息（如 'a','b'）
    int Edge[MaxVerNum][MaxVerNum]; // 邻接矩阵，Edge[i][j]=1表示有边，0表示无边
    int vexnum,arcnum;              // vexnum：当前顶点数，arcnum：当前边数
}MGraph;

// 初始化图：顶点数、边数置0，邻接矩阵全置0，顶点数组清空
void InitMGraph(MGraph *G){
    G->arcnum=0;
    G->vexnum=0;
    // 初始化邻接矩阵所有元素为0（表示初始无边）
    for (int i = 0; i < MaxVerNum; ++i) {
        for (int j = 0; j < MaxVerNum; ++j) {
            G->Edge[i][j]=0;
        }
    }
    for (int i = 0; i < MaxVerNum; ++i) {
        G->Vex[i]='\0';
    }
}

// 插入顶点：向图中添加一个顶点
// vale：要插入的顶点的值（如 'a'）
void InsertVertex(MGraph *G,char vale){
    G->Vex[G->vexnum]=vale;  // 将顶点值存入顶点数组
    G->vexnum++;             // 顶点数量+1
}

// 无向图添加一条边(x,y)
// x：边的一个顶点下标
// y：边的另一个顶点下标
void AddEdge(MGraph *G,int x,int y){
    // 1. 合法性判断：下标不能越界（0 ~ 当前顶点数-1）
    if(x < 0 || x >= G->vexnum || y < 0 || y >= G->vexnum){
        printf("AddEdge false:index\n");
        return;
    }
    // 2. 判断两个顶点是否真实存在（已插入）
    if(G->Vex[x] == '\0' || G->Vex[y] == '\0'){
        printf("AddEdge false:vex\n");
        return;
    }
    // 3. 判断是否已经有边，避免重复添加
    if(G->Edge[x][y] == 1){
        printf("AddEdge false:edge\n",x,y);
        return;
    }
    // 4. 无向图核心：边是双向的，对称置1
    G->Edge[x][y] = 1;
    G->Edge[y][x] = 1;
    // 5. 边数+1
    G->arcnum++;
}

int main() {
    MGraph G;
    InitMGraph(&G);

    InsertVertex(&G, 'a');
    InsertVertex(&G, 'b');
    InsertVertex(&G, 'c');

    AddEdge(&G,0,1);
    AddEdge(&G,0,2);
    AddEdge(&G,0,3);
    printf("Hello, World!\n");
    return 0;
}
