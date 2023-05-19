#include <stdio.h>
#define MAXN 1001
#define MINH -10001

int H[MAXN],size;

void Insert(int X){
    int i;
    for ( i = ++size; X < H[i/2]; i/=2)
    {
        H[i] = H[i/2];
    }
    H[i] = X;
}
//堆的初始化，建立一个空堆
void Create(){
    size = 0;
    H[0]=MINH; //岗哨 设在下标0
}

int main(int argc, char const *argv[])
{
    int n,m,x,i,j;
    scanf("%d,%d",&n,&m); //n数字个数，m查询次数
    Create();
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&x); //一个个读数然后插入数组
        Insert(x);
    }
    //读要查询路径的下标，然后输出
    for ( i = 0; i < m; i++)
    {
        scanf("%d",&j);
        printf("%d",H[j]);
        while(j>1){
            j/=2;
            printf("%d",H[j]);
        }
        printf("/n");
    }
    return 0;
}
/*
将一系列给定数字插入一个初始为空的小顶堆H[]，随后对任意给定的下标i，打印从H[i]到根节点的路径
堆用数组表示
*/