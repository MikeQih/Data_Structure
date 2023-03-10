#include <stdio.h>
#include <stdlib.h>
int c = 0;
struct ListNode { 
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL && l2==NULL && c==0) return NULL;
    l1 = l1!=NULL? (c+=l1->val,l1=l1->next) :l1;
    l2 = l2!=NULL? (c+=l2->val,l2=l2->next) :l2;
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->val = c%10;
    c/=10;
    cur->next = addTwoNumbers(l1,l2);
    return cur;
}
/*struct ListNode* InitialLize(struct ListNode* l){
    int n,i;
    struct ListNode *head,*p;
    
    head = (struct ListNode*)malloc(sizeof(struct ListNode));//头结点
    p = (struct ListNode*)malloc(sizeof(struct ListNode));//第一个结点
    head->next = p;
    n = 3;
    for ( i = 0; i < n; i++)
    {
        printf("Please enter an element: ");
        scanf("%d",&p->val);
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode)); //申请下个结点
        p = p->next; //将该结点和下个结点连起来
    }
    return l;
}
int print(struct ListNode* p){
    struct ListNode *head,*p;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));//头结点
    p = head->next;
    for ( int i = 0; i < n; i++)
    {
        printf("%d ",p->val);
        p = p->next;
    }
}
*/
int main(int argc, char const *argv[])
{
    int n,i;
    struct ListNode *head,*p;
    struct ListNode *l1,*l2;
    head = (struct ListNode*)malloc(sizeof(struct ListNode));//头结点
    p = (struct ListNode*)malloc(sizeof(struct ListNode));//第一个结点
    head->next = p;
    n = 3;
    for ( i = 0; i < n; i++)
    {
        printf("Please enter an element: ");
        scanf("%d",&p->val);
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode)); //申请下个结点
        p = p->next; //将该结点和下个结点连起来
    }
    
    // InitialLize(l1);
    // InitialLize(l2);
    // print(l1);

    //链表已经复制完成，要把链表移到首结点开始打印
    p = head->next;
    for ( i = 0; i < n; i++)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    return 0;
}
