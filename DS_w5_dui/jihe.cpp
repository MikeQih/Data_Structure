#include <stdio.h>
#define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

typedef struct {
    ElementType Data;
    int Parent;
}SetType;

SetName Find_v2(SetType S, ElementType X){ //简化版
    for(;S[X]>=0;X=S[X]);
    return X;
}

void Union_v2(SetType S,SetName Root1,SetName Root2){
    //默认Root1和Root2是不同集合的根节点
    S[Root2]=Root1;
}

int Find(SetType S,ElementType X){
    int i;
    for ( i = 0; i < MaxSize && S[i].Data != X; i++);
    if (i>=MaxSize){
        return -1; //未找到，返回-1
    }
    for ( ; S[i].Parent >= 0; i = S[i].Parent);
    return i;
    
}

//集合的并运算
//分别找到X1和X2两个元素所在集合的根节点，如果不同根，将其中一个根节点的父节点指针设置成另一个根节点的数组下标
void Union(SetType S[],ElementType X1,ElementType X2){
    int Root1,Root2;
    Root1 = Find(S,X1);
    Root2 = Find(S,X2);
    if (Root1!=Root2){
        S[Root2].Parent = Root1; //不同就合并
    }
    //为改善合并以后的查找性能，可以采用小的集合合并到相对大的集合中(修改Union函数)
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
集合
并查集：集合并，查某元素属于什么集合
双亲表示法：孩子指向双亲


照着给的代码改！好如果后面按着变动来的

*/