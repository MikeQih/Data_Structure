#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;        /* 边的权值设为整型 */
typedef char DataType;        /* 顶点存储的数据类型设为字符型 */

//边的定义
typedef struct ENode *PtrToENode; //PointerTo
struct ENode{
    Vertex V1,V2; //有向边<V1,V2>
    WeightType Weight;
};
typedef PtrToENode Edge;


//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV; //邻接点下标
    WeightType Weight; //边权重
    PtrToAdjVNode Next;
};

//顶点表头节点的定义
typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    DataType Data; //存顶点的数据

} AdjList[MaxVertexNum];//多少个顶点，这个数组就有多大

//图节点定义
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    AdjList G; //邻接表
};
typedef PtrToGNode LGraph; //把以邻接表方式存储的图类型，定义为指向这个节点的指针

LGraph CreateGraph(int VertexNum){
    Vertex V,W;
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph -> Nv = VertexNum;
    Graph -> Ne = 0;
    //默认顶点编号从0开始，到Graph->Nv-1
    for ( V = 0; V < Graph->Nv; V++){
        Graph->G[V].FirstEdge=NULL; 
    }
    return Graph; 
}

//向LGraph中插入边
void InsertEdge(LGraph Graph,Edge E){
    PtrToAdjVNode NewNode;
    //插入边<V1,V2>
    //为V2建立新的邻接点
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    //将V2插入V1的表头
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    //若是无向图，要插入边<V2,V1>
    //为V1建立新的邻接点(把上面的V1，V2交换就行)
    // NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    // NewNode->AdjV = E->V1;
    // NewNode->Weight = E->Weight;
    // NewNode->Next = Graph->G[E->V2].FirstEdge;
    // Graph->G[E->V2].FirstEdge = NewNode;
}

LGraph BuildGraph(){
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if (Graph->Ne!=0){ //如果有边(读入的边数!=0)
        E = (Edge)malloc(sizeof(struct ENode));
        for ( i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }
    //如果顶点有数据的话，读入数据
    for ( V = 0; V < Graph->Nv; V++){
        scanf("%c",&(Graph->G[V].Data));
    }
    return Graph;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
邻接表：G[N]为指针数组，对应矩阵每行一个链表，只存非0元素



(6.1后的代码都是)

*/