#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList; //LinkList等价于LNode，前者强调是链表，后者强调这是结点

//初始化一个单链表，带头结点
bool InitList(LinkList &L){
    L = (LNode *)malloc(sizeof(LNode));//分配一个头结点
    if(L==NULL){//内存不足，分配失败
        return false;
    }
    L->next = NULL; //头结点之后暂时还没有结点
    return true;
}

LinkList List_TailInsert(LinkList &L){//尾插法建立单链表
    L = (LinkList)malloc(sizeof(LNode));//分配一个头结点
    LNode *s,*r =L; //r为表尾指针
    int x;
    printf("Please enter an element:");
    scanf("%d",&x);
    while (x!=-1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s; //让r指向最后一个结点
        printf("Please enter an element:");
        scanf("%d",&x);
    }
    r -> next = NULL;
    return L;
}

LinkList List_HeadInsert(LinkList &L){ //头插法 联系链表逆置
    LNode *s;
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("Please enter an element:");
    scanf("%d",&x);
    while (x!=-1)
    {
        s = (LNode*)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        printf("Please enter an element:");
        scanf("%d",&x);
    }
    return L;
    }//eg. input:10 16 27; node output: 27 16 10
    

bool InsertNextNode(LNode *p,ElemType e){
    if (p==NULL){ //i值不合法
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; //将结点s连到p之后
    return true; //插入成功
}

LNode * GetElem(LinkList L,int i){//按位查找
    if(i<0)
        return NULL;
    LNode *p; //指针p指向当前扫描到的结点
    int j = 0; //当前p指向的是第几个结点
    p = L; //L指向头结点，头结点是第0个结点（不存数据）
    while (p!=NULL && j<i-1){//循环找到第i-1个结点
        p = p->next;
        j++;
    }
    return p;
}

bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1){
        return false;
    }
    LNode *p = GetElem(L,i-1);//找到第i-1个结点
    return InsertNextNode(p,e);  
}

bool InsertPriorNode(LNode *p,ElemType e){
    if (p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s==NULL)
    {
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//删除指定结点 有bug，单链表的局限性，无法逆向检索，有时候确实不方便
/*
bool DeleteNode(LNode *p){
    if (p==NULL)
    {
        return false;
    }
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true; 
}
*/
int Length(LinkList L){
    int len = 0;
    LNode *p = L;
    while(p->next!=NULL){
        p = p->next;
        len++;
    }
    return len;
}

bool ListDelete(LinkList &L, int i, ElemType &e){
    if (i<1){
        return false;
    }
    LNode *p = GetElem(L,i-1);
    if (p==NULL){ //i值不合法
        return false;
    }
    if(p->next == NULL){
        return false;
    }
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(p);
    return true; 
}

// void print(LinkList &L){ //啥问题？？
//     int p;
//     for (p = L->data; L; L=L->next)
//     {
//         printf("%d",p);
//     }
//     printf("\n");
    
// }
int main(int argc, char const *argv[])
{
    /*单链表 两种实现：
    1带头结点，空表判断：L==NULL，写代码不方便
    2不带头结点，空表判断：L->next==NULL，写代码更方便（头结点不存数据，只是为了操作方便）
    */
    //单链表的建立：1.初始化一个单链表，2.每次取一个数据元素，插入到表尾/表头
    LinkList l;
    List_TailInsert(l); // 10 20 30 40，-1
    // print(l);
    return 0;
}
