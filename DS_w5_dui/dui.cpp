#include <stdio.h>
#include <stdlib.h>
// #define ElementType char //这的type是啥
typedef struct HeapStruct *MaxHeap;
struct HeapStruct{
    ElementType *Elements;
    int Size;
    int Capacity;
};

ElementType DeleteMax(MaxHeap H){
    //从最大堆H中取出键值为最大的元素，并删除一个节点
    int Parent,Child;
    ElementType MaxItem,temp;
    if(IsEmpty(H)){
        printf("最大值为空");
        return;
    }
    MaxItem = H->Elements[1];//取出根节点最大值
    temp = H->Elements[H->Size--];
    for (Parent=1; Parent*2 <= H->Size; Parent = Child){
        Child = Parent*2;
        if ((Child!=H->Size && H->Elements[Child] < H->Elements[Child+1])){
            Child++; //child指向左右节点的较大者
        }
        if (temp >= H->Elements[Child]) break;
        else{
            H->Elements[Parent] = H->Elements[Child];
        } 
    }
    H->Elements[Parent] = temp;
    return MaxItem;
    
    

}
void Insert(MaxHeap H,ElementType item){
    //H->Elements[0]已经定义为哨兵
    int i;
    if(IsFull(H)){
        printf("最大堆已满");
        return;
    }
    i = ++H->Size; //i指向插入后堆中的最后一个元素的位置
    for ( ; H->Elements[i/2]<item; i/=2){ //和上面的父节点比
        H->Elements[i] = H->Elements[i/2];
    }
    H->Elements[i] = item; //将item插入

    
}
MaxHeap Create(int MaxSize){
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData; //哨兵，后面讲
    return H;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
优先队列(Priority Queue)：特殊的“队列”，取出元素的顺序依照元素的优先权(关键字大小)，而不是元素进入队列的先后顺序

堆 两个特性：
1.结构性：数组表示的完全二叉树
2.有序性：任一节点的关键字(节点值) 是其子树所有节点的最大值(或最小值)
(最大堆(MaxHeap)，"大顶堆"，最大值；最小堆(MinHeap)，"小顶堆"，最小值)

最大堆：
H属于MaxHeap，元素item属于ElementType
主要操作：Create,IsFull,Insert,IsEmpty,DeleteMax





看到w5 5.1.4 堆的建立

14:10
*/
