#include <stdio.h>
void PrintN(int N){
    int i;
    for(int i=1;i<=N;i++){
        printf("%d\n",i);
    }
    return;
}
void PrintN2(int N){
    if(N){
        PrintN2(N-1);
        printf("%d\n",N);
    }
    return;
}
int main(int argc, char const *argv[])
{
    int N=100;
    // scanf("%d",&N);
    PrintN(N);
    // PrintN2(N); //在1000000的时候递归不能用了，对空间占用太大(1000000时候把所有空间消耗掉，但是还不够，就爆了)
    return 0;
}
/*
1. 解决问题的效率和 空间的利用效率有关
2. 解决问题方法的效率和 算法的巧妙程度有关
*/
