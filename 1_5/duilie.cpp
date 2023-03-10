#include <stdio.h>
#define MaxSize 10

typedef int ElemType;
typedef struct{ 
    ElemType data[MaxSize];
    int front,rear;
    //不浪费存储空间的方法1:int size;//队列当前长度 插入成功：size++，删除成功：size--

    //方法2:int tag;//最近进行的是删除0 / 插入1，只有删除可能导致队空，插入导致队满；
    //初始化时：rear=front=0;tag=0; 
    //队满条件：front==rear&&tag==1,队空条件：front==rear&&tag==0


}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue Q){//判断队列是否为空
    if(Q.rear==Q.front)//队空条件
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q,ElemType x){
    if ((Q.rear+1)%MaxSize==Q.front)//!!很秀 front指针可能不在0
    {
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
    
}

bool DeQueue(SqQueue &Q, ElemType &x){//出队操作
    if (Q.rear==Q.front){
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front+1)%MaxSize;
    return true;
    
}

bool GetHead(SqQueue Q,ElemType &x){
    if (Q.rear==Q.front){
        return false;
    }
    x = Q.data[Q.front];
    return true;
    //队列元素个数：(rear+MaxSize-front)%MaxSize eg.r=3,f=1

    
}
void testQueue(){
    SqQueue Q;
    InitQueue(Q);
}

int main(int argc, char const *argv[])
{
    /*
    Queue：是只允许在一端进行插入，另一端删除的线性表(食堂打饭，车排队过收费站)
    队头：允许删除的一端，队尾：允许插入的一端
    队列特点：先进先出(First In First Out, FIFO)
    增：入队，删：出队
    */
    
    return 0;//到p24
}
