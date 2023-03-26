#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define ElementType int
struct QNode{
    ElementType Data[MaxSize];
    int rear;
    int front;
};
typedef struct QNode *Queue;

struct Node{
    ElementType Data;
    struct Node *Next;
};
struct QNode_LB{//链队列结构
    struct Node *rear; //指向队尾节点
    struct Node *front; //队头
};
typedef struct QNode_LB *Queue_LB;
Queue_LB PtrQ;

//队列的 链式存储 没给add的
ElementType DeleteQ(Queue_LB PtrQ){
    struct Node *FrontCell;
    ElementType FrontElem;
    if (PtrQ->front == NULL){
        printf("队列为空");
        return NULL;
    }
    FrontCell = PtrQ->front;
    if(PtrQ->front==PtrQ->rear){//若队列只有一个元素
        PtrQ->front = PtrQ->rear = NULL; //删除后队列位置为kong
    }
    else{
        PtrQ->front = PtrQ->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

//队列的 顺序存储 //所有方法的完整代码在讲义里 2.3队列
void AddQ(Queue PtrQ,ElementType item){
    if ((PtrQ->rear+1)%MaxSize==PtrQ->front)
    {
        printf("队列已满");
        return;
    }
    PtrQ->rear = (PtrQ->rear+1)%MaxSize;
    PtrQ->Data[PtrQ->rear] = item;
}
ElementType DeleteQ(Queue PtrQ){
    if (PtrQ->front==PtrQ->rear)
    {
        printf("队列空，无法删除");
        return NULL;
    }
    else{
        PtrQ->front = (PtrQ->front+1)%MaxSize;
        return PtrQ->Data[PtrQ->front];
    }
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
Queue (队列)：具有一定操作约束的线性表
只允许在一端插入，另一端删除(食堂打饭，车排队过收费站)
队头：允许删除的一端，队尾：允许插入的一端
队列特点：先进先出(First In First Out, FIFO)
增(插入)：入队，删(删除)：出队

数据对象集：一个有0个或多个元素的有穷线性表
操作集：长度为MaxSize的队列Q 属于Queue；队列元素item 属于ElemenTtype
CreateQueue,IsFull,AddQ,IsEmptyQ,DeleteQ

也是两种方式存储：
1.顺序存储
一维数组，记录队列头元素变量front(第一个元素的前一个)，尾元素rear(实际的最后一个元素的位置)
顺环队列解决方案：a.使用额外标记：Size(记录当前队列元素个数)或tag域(代表最后一次是插入还是删除) b.仅使用n-1个数组空间
2.链式存储
单向链表，插入和删除在两头进行。front 头，rear 尾（起始位置在一起）


和1_5_duilie.cpp差不多

看到2的小白专场
*/
