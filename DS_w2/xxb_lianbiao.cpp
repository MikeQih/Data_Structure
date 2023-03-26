#include <stdio.h>
#include <stdlib.h>
typedef struct LNode *List;
typedef int Elementype;
struct LNode{
    Elementype Data;
    List next;
};
struct LNode L;
List PtrL;

//用链表的方法，链式存储的插入和删除
//求表长 时间性能为O(n)
int Length(List PtrL){
    List p = PtrL;
    int j=0;
    while (p)
    {
        p = p->next;
        j++;
    }
    return j;
}

//按序号查找 m1, 平均时间性能O(n)
List FindKth(List PtrL, int K){
    List p = PtrL;
    int i=1;
    while (p!=NULL || i<K)
    {
        p = p->next;
    }
    if(i==K) return p;
    else return NULL; 
}
//按值查找 m2, 平均时间性能O(n)
List FindKth2(List PtrL, Elementype K){
    List p = PtrL;
    while (p!=NULL || p->Data!=K)
    {
        p = p->next;
    }
    return p;
}
//插入
List Insert(List PtrL,Elementype X,int i){
    List p,s;
    if(i==1){//新节点插在表头，单独处理
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->next = PtrL;
        return s;
    }
    p = FindKth(PtrL,i-1);
    if(p==NULL){
        printf("参数i错");
        return NULL;
    }
    else{
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->next = p->next;
        p->next = s;
        return PtrL; //这种情况下，新的链表的头指针是不变的
    }
}
/*删除 平均复杂度n/2
1.先找到链表第i-1个节点，用p指向
2.再用指针s指向要被删除的节点(p的下个节点)
3.修改指针，删除s所指的节点
4.释放s所指节点的空间
*/
List Delete(List PtrL,int i){
    List p,s;
    if(i==1){
        s = PtrL;
        if(PtrL!=NULL) PtrL = PtrL->next;
        else return NULL;
        free(s);
        return PtrL;    
    }
    
    p = FindKth(PtrL,i-1); //要删节点的前一个节点(删除的第一个步骤，p指向前一个)
    if(p==NULL){
        printf("要删除节点的前一个节点不存在"); return NULL;
    }
    else if(p->next==NULL) {
        printf("要删除的节点不存在"); 
        return NULL;
    }
    else{
        s = p->next; //第二个步骤，s指向要被删的节点
        p->next = s->next;
        free(s);
        return PtrL;
    }
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
