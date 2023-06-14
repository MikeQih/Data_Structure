#include <stdio.h>
//DFS
void DFS(Vertex V){
    visited[V] = true;
    for ( i = 0; i < count; i++)
    {
        /* code */
    }
    
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
类型名称：图(Graph)
数据对象集：G(V,E)由一个非空的有限顶点集合V和一个有限边集合E组成
表示多对多的关系
包含：
1组顶点：V(Vertex)表示顶点集合
1组边：E(Edge)表示边的集合

边是顶点对：(v,w)属于E；v，w属于V
有向边<v,w>表示从v指向w的边(单行线)
不考虑重边和自回路

常见操作：
eg. Graph Create(); void DFS/BFS(Graph G, Vertex V);(从顶点V出发深度/宽度优先遍历图G)

无向图(方向不重要，图里没方向)；有向图(方向重要，图里有)；边上的数字叫做权重(eg.定义为路线的长度，带权重的图叫 网络)
在程序中表示图：对于网络，只需把G[i][j]的值定义为边<Vi,Vj>的权重即可

“度”：顶点的边的个数。出度：从该点出发的边数。入度：指向该点的边数

邻接矩阵->N个顶点，从0到N-1编号。若<Vi,Vj>是G的边，G[i][j]=1，否则G[i][j]=0。
好处：1.简单好理解 2.方便检查任意一对顶点间是否存在对应边 3.方便找邻接点和度()
坏处：1.浪费空间(存稀疏图时大量无效元素，对稠密图(完全图)很合算) 2.浪费时间(统计稀疏图中共有多少条边)

邻接表
好处：方便找任一顶点的所有“邻接点”；节约稀疏图的空间(需要N个头指针，加2E个节点(每个节点至少两个域))
方便计算任意节点的度？无向图是的，有向图只能计算出度，需构造逆邻接表来计算入度；存稀疏图很合算
坏处：检查任意一对顶点间是否存在边 很麻烦

深度优先搜索(Depth First Search, DFS)：若N个顶点，E条边，时间复杂度是：邻接表存储图 O(N+E)，邻接矩阵存储图 O(N^2)
广度优先搜索(Breadth First Search, BFS)：和DFS一样

连通：如果从V到W存在一条(无向)路径，则称V和W是连通的
路径：V到W的路径是一系列顶点{V,v1,v2,...,vn,W}的集合，其中任意一对顶点间都有图中的边。路径的长度是路径中的边数(如果带权，则是所有边的权重和)。如V到W间所有的顶点都不同，则称简单路径
回路：起点等于终点的路径
连通图：图中任意两顶点均连通

无向图：
连通分量：无向图的极大连通子图(极大顶点数：再加一个顶点就不连通了；极大边数：包含子图中所有顶点相连的所有边)

有向图：
强连通：有向图中顶点V和W间存在双向路径，则V和W是强连通的。
强连通图：有向图中任意两顶点均强连通
强连通分量：有向图的极大强连通子图

六度空间(Six Degree of Separation)：和任何陌生人间所间隔的人不会超过6个

最短路径
1.单源最短路径问题：从某固定源点出发，求其到所有其他顶点的最短路径
(有向)无权图：经过顶点最少的一条路
(有向)有权图：看权重 Dijkstra算法(贪心) 补代码！！
2.多源最短路径问题：求任意两顶点间的最短路径

任意两顶点间最短路径：Floyd算法

最小生成树：
1.是一棵树：无回路，|V|个顶点一定有|V|-1条边
2.是生成树：包含全部顶点，|V|-1条边都在图里 (向生成树中任加一条边都一定构成回路)
3.边的权重和最小

Prim算法 (对稠密图合算)
Kruskal算法 将森林合并成树，一条一条找权重最小的边(对稀疏图合算)

AOV(Activity On Vertex)网络 (一般用于安排项目的工序 左：顶点编号 右上：Earliest最早 完成/发生/开工 时间(算最大) 右下：Latest最晚 完成/发生/开工 时间(算最小) )
拓扑序：如果图中从V到W有一条有向路径，则V一定排在W之前。满足此条件的顶点序列称为一个拓扑序
获得一个拓扑序的过程就是拓扑排序
AOV如果有合理的拓扑序，则必定是有向无环图(Directed Acyclic Graph, DAG)


看到 图下 8.2拓扑排序 c语言代码
图还的看


*/