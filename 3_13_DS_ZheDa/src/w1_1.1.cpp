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
void MaxSubsequSum1(int A[], int N){ //m1
    int ThisSum, MaxSum = 0;
    int i,j,k;
    for (int i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            for (k = i; k <= j; k++)
            {
                ThisSum += A[k];
            }
            if (ThisSum>MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    printf("%d\n",MaxSum); 
}
void MaxSubsequSum2(int A[], int N){ //m2 稍快一点
    int ThisSum, MaxSum = 0;
    int i,j;
    for (int i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];
            if (ThisSum>MaxSum)
            {
                MaxSum = ThisSum;
            }
        }
    }
    printf("%d\n",MaxSum); 
}
int main(int argc, char const *argv[])
{
    int N=100;
    // scanf("%d",&N);
    // PrintN(N);
    // PrintN2(N); //在1000000的时候递归不能用了，对空间占用太大(1000000时候把所有空间消耗掉，但是还不够，就爆了)

    // int n[] = {1,2,-1,4,6};
    int n[10];
    int cnt=0;
    int element;
    printf("请输入整数，-1停止: ");
    scanf("%d",&element);
    while(element!=-1){
        n[cnt] = element;
        cnt+=1;
        scanf("%d",&element);
        if (element==-1)
        {
            break;
        }
        
    }
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ",n[i]);
    }
    printf("\n找完后的结果：\n");
    // MaxSubsequSum1(n,cnt);
    MaxSubsequSum2(n,cnt);
    return 0;
}
/*
1.1:
1. 解决问题的效率和 空间的利用效率有关
2. 解决问题方法的效率和 算法的巧妙程度有关

抽象：描述数据类型的方法不依赖于具体实现？(?讲义中的再看/抄)

1.2: (可以复习重看)
时间复杂度(S(n))：根据算法写成的程序在执行时 占用存储单元的长度。(Space)
空间复杂度(T(n))：根据算法写成的程序在执行时 耗费时间的长度。(Time)
在分析一般算法的效率时，经常关注最坏情况复杂度(不好定义平均复杂度)
排序：1, logn, n, nlogn, n^2, n^3, 2^n, n!
T1(n)+T2(n) = max(O(f1(n)),O(f2(n)))
T1(n)*T2(n) = O(f1(n)*f2(n))
eg. for循环的时间复杂度=循环体内代码复杂度
eg. if-else机构的复杂度取决于：if的条件判断复杂度，和两个分支部分的复杂度，总体复杂度取三者中最大

1.3
算法3 分而治之
T(n) = 2T(N/2) + cN, T(1) = O(1)  (最后结果的形式，两边的二分，和跨越中间边界的N)
T(n) = 2(2T(N/2^2)+cN/2) + cN  (根据题目，会二分好几次，一直/2来分；每展开一层就多一个cN，所以下一步是ckN)
T(n) = (2^k)O(1) + ckN  (N/2^k =1(N/2 /2...除了k次2后，最终会得到1(就算不是整除，也差不多)))
两个值的复杂度分别是：O(n)和O(Nlog(N))。
相加取大的，所以整个算法的复杂度为：O(Nlog(N))。

(分治法递归的部分还是没懂！尽快弄明白！！)还有一道 二分法链表的题没做！！

看到第二周的

*/
