#include <stdio.h>
#include <iostream>
using namespace std;

int MaxSubsequSum2(int A[], int N){ //m2 稍快一点
    int ThisSum, MaxSum = 0;
    int i,j;
    for (i = 0; i < N; i++)
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
    return MaxSum; 
}
int MaxSubsequSum4(int A[], int N){ //在线处理：每输入一个数据就进行及时处理 T(n)=O(n)
//15:30
    
    
    int ThisSum=0,MaxSum=0;
    for (int i = 0; i < N; i++)
    {
        ThisSum+=A[i];
        if(ThisSum>MaxSum){//发现更大和则更新当前结果
            MaxSum = ThisSum;
        }
        else if(ThisSum<0){//若当前子列和为负，不可能使后面的部分和增大，使ThisSum重置为0
            ThisSum=0;
        }
    }
    return MaxSum;
}
void Q2(int A[], int N){
    int start=0,end=0;
    int ThisSum, MaxSum = 0;
    int i,j;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];
            if (ThisSum>MaxSum)
            {
                start = A[i];
                end = A[j];
                MaxSum = ThisSum;
            }
        }
    }
    printf("%d %d %d\n",MaxSum, start, end);
}
int main(int argc, char const *argv[])
{
    int number,cnt=0;
    int element;
    bool flag; //默认false，0
    printf("请输入数组长度大小：");
    cin >> number;
    int n[number];
    while(cnt<number){
        printf("请输入数组元素：");
        cin >> element;
        n[cnt] = element;
        if(element>=0){
            flag=true;
        }
        cnt+=1;
    }
    // int t2 = MaxSubsequSum2(n,cnt);
    // printf("%d\n",t2);

    // int t4 = MaxSubsequSum4(n,cnt);
    // printf("%d\n",t4);
    // printf("\n");
    if(flag==false){
        printf("%d %d\n",n[0],n[number-1]);
        return 0;
    }
    Q2(n,cnt);
    return 0;
}

// int main(){
//     int number,cnt=0;
//     int element;
//     scanf("%d",&number);
//     int n[number];
//     while(cnt<number){
//         scanf("%d",&element);
//         n[cnt] = element;
//         cnt+=1;
//     }
//     int t = MaxSubsequSum2(n,cnt);
//     printf("%d\n",t);
//     return 0;
// }