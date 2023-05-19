#include <stdio.h>
#include <stdio.h>
// #define MAXN 1000                  /* 集合最大元素个数 */
typedef int ElementType;           /* 默认元素可以用非负整数表示 */
typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
// typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */

// typedef struct {
//     ElementType Data;
//     int Parent;
// }SetType;


int Find(int* S,int X){
    if (S[X]<0){
        return X;
    }
    else{
        return S[X] = Find(S,S[X]); //路径压缩 通过不断压缩路径，让树越来越扁
    }
    
}
void Union(int* S,int x1,int x2){
    int root1 = Find(S,x1-1); //计算机编号从1开始的，集合从0开始，所以-1
    int root2 = Find(S,x2-1);
    if (root1==root2)
    {
        S[root2]=root1;
        root1-=root2;
    }
    else{
        //按秩合并
        if (root1<root2){
            S[root2] = root1;
            root1-=root2;
        }
        else{
            S[root1] = root2;
            root2-=root1;
        }
        
    }
}
void Check_Network(int* S,int N){
    int i,counter=0;
    for ( i = 0; i < N; i++){
        if (S[i]<0){
            counter++;
        }
        
    }
    if (counter==1){
        printf("Network is connected");
    }
    else{
        printf("%d are connected",counter);
    }
    
    
}
void Check_connection(int* S){
    int x1,x2;
    scanf("%d %d",&x1,&x2);
    int root1,root2;
    root1 = Find(S,x1-1);
    root2 = Find(S,x2-1);
    if (root1==root2)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }    
    
}
void Input_connection(int* S){
    int x1,x2;
    scanf("%d %d",&x1,&x2);
    Union(S,x1,x2);
}


int main(int argc, char const *argv[])
{
    int N,i;
    char in;
    scanf("%d\n",&N);
    int S[N];
    for ( i = 0; i < N; i++){
        S[i]=-1;
    }
    
    do{
        scanf("%c",&in);
        switch(in){
            case 'I': Input_connection(S);break; //Union(在jihe.cpp中写的)
            case 'C': Check_connection(S);break; //Find
            case 'S': Check_Network(S,N);break; //数集合的根
        }
    } while (in != 'S');
    return 0;
}
/*
小白专场FT.2 连接电脑
I->Input, C->Check

按秩归并 m1:把矮树贴到高树上 m2:把小树贴到大树上(元素个数) 最后时间复杂度是O(logn) 而不是O(n^2)
路径压缩

*/