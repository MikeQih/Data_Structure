#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100 //最大顶点数
typedef char DataType; /* 顶点存储的数据类型设为字符型 */
typedef struct GNode *PtrToGNode;
typedef int WeightType;/* 边的权值设为整型 */

struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum]; //存顶点的数据
};
typedef PtrToGNode MGraph; //以邻接矩阵存储的图类型(MGraph,Maxtrix)
typedef int Vertex; //顶点下标表示顶点，为整型


//向MGraph中插入边
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2; //有向边<V1,V2>
    WeightType Weight; //权重
};
typedef PtrToENode Edge;

void InsertEdge(MGraph Graph,Edge E){
    //插入边<V1,V2>
    Graph->G[E->V1][E->V2] = E->Weight;
    //若是无向图，还要插入边<V2,V1>
    Graph->G[E->V2][E->V1] = E->Weight;

}

MGraph CreateGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph -> Nv = VertexNum;
    Graph -> Ne = 0;
    //默认顶点编号从0开始，到Graph->Nv-1
    for ( V = 0; V < Graph->Nv; V++){
        for ( W = 0; W < Graph->Nv; W++){
            Graph->G[V][W]=0;
        }
    }
    return Graph; 
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if (Graph->Ne!=0){
        E = (Edge)malloc(sizeof(struct ENode));
        for ( i = 0; i < Graph->Ne; i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }
    //如果顶点有数据的话，读入数据
    for ( V = 0; V < Graph->Nv; V++){
        scanf("%c",&(Graph->Data[V]));
    }
    return Graph;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
//邻接矩阵
//看到图(中) 
