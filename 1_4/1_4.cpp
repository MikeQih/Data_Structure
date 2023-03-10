#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinklist;

//初始化双链表
bool InitDLinkList (DLinklist &L){
    L = (DNode *)malloc(sizeof(DNode));//分配一个头结点
    if (L == NULL) //内存不足，分配失败
    {
        return false;
    }
    L->prior = NULL; //头结点的prior永远指向NULL
    L->next = NULL; //头结点之后暂时还没有结点

    // L->prior = L;循环双链表的初始化
    // L->next = L; 头结点prior指向头结点，头结点next指向头结点

    return true;
}

//双链表的插入
bool InsertNextDNode(DNode *p, DNode *s){
    if (p==NULL || s==NULL)//非法参数
    {
        return false;
    }
    s->next = p->next;
    if (p->next!=NULL){//如果p有后继结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    
}

bool DeleteNextDNode(DNode *p){
    if (p==NULL) return false;
    DNode *q = p->next; //找到p的后继结点q
    if (q==NULL) return false; //p没用后继
    p->next = q->next;
    if (q->next!=NULL){ //q结点不是最后一个
        q->next->prior = p;
    }
    free(q); //释放结点空间
    return true;
}

void DestroyList(DLinklist &L){
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L); //释放头结点
    L=NULL; //头指针指向NULL
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
