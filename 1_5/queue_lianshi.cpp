#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LinkNode{ //队列的链式实现
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化队列(带头结点)
void InitQueue(LinkQueue &Q){
    Q.front = Q.rear = (LinkNode*)malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q){
    if (Q.front==Q.rear)
        return true;
    else
        return false; 
}

//新元素入队(带头结点)
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; //新结点插入到rear之后
    Q.rear = s; //修改表尾指针
}

bool DeQueue(LinkQueue &Q,ElemType &x){//出队，带头结点
    if(Q.front==Q.rear){
        return false; //空队
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear==p){//此次时最后一个结点出队
        Q.rear=Q.front;//修改rear指针
    }
    free(p);
    return true;
}

bool Dequeue(LinkQueue &Q,ElemType &x){
    //出队，不带头结点 
    //front-->a1-->a2-->...-->NULL
    if (Q.front==NULL)
    {
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front = p->next;
    if (Q.rear==p)//此处是最后一个结点出队
    {
        Q.front=NULL;
        Q.rear=NULL;
    }
    free(p);
    return true;
    
    
}

void testLinkQueue(){
    LinkQueue Q; //声明一个队列
    InitQueue(Q); //初始化队列
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
