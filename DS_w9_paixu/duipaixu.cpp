#include <stdio.h>
#define ElementType int
void PercDown(ElementType A[],int p,int N){
    int Parent,Child;
    ElementType X;
    X = A[p];//取出根节点存放的值
    for (Parent=p;(Parent*2+1)<N;Parent=Child)
    {
        Child = Parent*2+1;
        if((Child!=N-1)&&(A[Child]<A[Child+1])){
            Child++; //Child指向左右节点的较大者
        }
        if(X>=A[Child]) break; //找到了合适的位置
        else A[Parent] = A[Child];
    }
    A[Parent]=X;
    
}
void Swap(int *X,int *Y)
{
	int tmp = *X;
	*X = *Y;
	*Y = tmp;
}

void HeapSort(ElementType A[],int N){
    int i;
    for ( i = N/2-1; i >= 0; i--){ //建立最大堆
        PercDown(A,i,N);
    }
    for( i=N-1;i>0;i--){
        //删除最大堆顶
        Swap(&A[0],&A[i]);
        PercDown(A,0,i);
    }
    
}

//有序子列的归并
//L 左边起始，R 右边起始位置，RightEnd 右边终点位置
void Merge(ElementType A[],ElementType TmpA[],int L,int R,int RightEnd){
    int LeftEnd = R-1; //左边终点位置
    int Tmp = L;
    int NumElements = R-L+1;
    while (L<=LeftEnd && R<=RightEnd)
    {
        if (A[L]<A[R]) TmpA[Tmp++]=A[L++];
        else TmpA[Tmp++] = A[R++];
    }
    while (L<=LeftEnd){//复制左边剩下的
        TmpA[Tmp++] = A[L++];
    }
    while (R<=RightEnd){//复制左边剩下的
        TmpA[Tmp++] = A[R++];
    }
    for(int i=0;i<NumElements;i++,RightEnd--){
        //补
    }
    
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,4,8,5,6};
    HeapSort(arr,5);

    printf("%d\n",*(arr));
    printf("%d\n",*(arr+3)); //输出索引为3的元素

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}
