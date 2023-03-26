#include <stdio.h>
#include <iostream>
using namespace std;

int Max3( int A, int B, int C )
{ /* 返回3个整数中的最大值 */
    return A > B ? (A > C ? A : C) : (B > C ? B : C);
}

int DivideAndConquer( int List[], int left, int right )
{ /* 分治法求List[left]到List[right]的最大子列和 */
    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if( left == right )  { /* 递归的终止条件，子列只有1个数字 */
        if( List[left] > 0 )  return List[left];
        else return 0;
    }

    /* 下面是"分"的过程 */
    center = ( left + right ) / 2; /* 找到中分点 */
    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer( List, left, center );
    MaxRightSum = DivideAndConquer( List, center+1, right );

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0; LeftBorderSum = 0;
    for( i=center; i>=left; i-- ) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if( LeftBorderSum > MaxLeftBorderSum )
            MaxLeftBorderSum = LeftBorderSum;
    } /* 左边扫描结束 */

    MaxRightBorderSum = 0; RightBorderSum = 0;
    for( i=center+1; i<=right; i++ ) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if( RightBorderSum > MaxRightBorderSum )
            MaxRightBorderSum = RightBorderSum;
    } /* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3( MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum );
}

int MaxSubseqSum3( int List[], int N )
{ /* 保持与前2种算法相同的函数接口 */
    return DivideAndConquer( List, 0, N-1 );
}

int main(int argc, char const *argv[])
{
    // int number,cnt=0;
    // int element;
    // cin >> number;
    // int n[number];
    // while(cnt<number){
    //     cin >> element;
    //     n[cnt] = element;
        
    //     cnt+=1;
    // }
    int n1[] = {1,-2,3};
    int number1 = 3;
    int r = MaxSubseqSum3(n1,number1);
    printf("%d\n",r);
    return 0;
}


// void Q2(int A[], int N){
//     int start=0,end=0;
//     int ThisSum=0, MaxSum = 0;
//     int i,j;
//     for (i = 0; i < N; i++)
//     {
//         ThisSum = 0;
//         for (j = i; j < N; j++)
//         {
//             ThisSum += A[j];
//             if (ThisSum>MaxSum)
//             {
//                 start = A[i];
//                 end = A[j];
//                 MaxSum = ThisSum;
//             }
//         }
//     }
//     printf("%d %d %d",MaxSum, start, end);
// }

// int main(){
    // int number,cnt=0;
    // int element;
    // cin >> number;
    // int n[number];
    // int flag1 =0;
    // while(cnt<number){
    //     cin >> element;
    //     n[cnt] = element;
    //     if(element<0){
    //         flag1+=1;
    //     }
    //     cnt+=1;
    // }
    
    // if (flag1==number)
    // {
    //     printf("%d %d %d\n",0,n[0],n[number-1]);
    //     return 0;
    // }
    
    // Q2(n,cnt);
    // return 0;
// }