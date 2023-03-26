#include <stdio.h>
#include <stdlib.h>

struct PolyNode{
    int coef; //系数
    int expon; //指数
    struct PolyNode *link; //指向下一个节点的指针
};
typedef struct PolyNode *Polynomial;
Polynomial P1,P2;

int Compare(int expon1, int expon2){
    if (expon1>expon2){
        return 1;
    }
    if (expon1==expon2){
        return 0;
    }
    if (expon1<expon2){
        return -1;
    }
    
    return expon1 - expon2;
}
void Attach(int c,int e,Polynomial *pRear){ //指针的指针，函数常数值传递
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P; //*号的pRear就是指针了
    *pRear = P; //修改pRear值

}
Polynomial PolyAdd(Polynomial P1, Polynomial P2){
    Polynomial front,rear,temp;
    int sum;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    front = rear;
    while (P1&&P2)
    {
        switch (Compare(P1->expon,P2->expon))
        {
        case 1:
            Attach(P1->coef,P1->expon,&rear);
            P1 = P1->link;
            break;
        case -1:
            Attach(P2->coef,P2->expon,&rear);
            P2 = P2->link;
            break;
        case 0:
            sum = P1->coef+P2->coef;
            if(sum) Attach(sum,P1->expon,&rear); //判断系数和是否为0
            P1 = P1->link;
            P2 = P2->link;
            break;
        }
    }
    for(;P1;P1 = P1->link)Attach(P1->coef,P1->expon,&rear);
    for(;P2;P2 = P2->link)Attach(P2->coef,P2->expon,&rear);
    rear->link = NULL;
    temp = front;
    front = front->link; //另front指向结果多项式第一个非零项
    free(temp);
    return front;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
多项式加法计算：
采用不带头节点的单向链表，按照指数递减的顺序排列各项
算法思路：
两个指针P1,P2分别指向 两个多项式的第一个节点，不断循环
1.P1->expon == P2->expon：系数相加，若不为0，作为结果多项式的系数。P1P2分别指向下一项
2.P1->expon > P2->expon：P1的结果存入当前多项式，P1指向下一项
3.P1->expon < P2->expon：P2的结果存入结果多项式，P2指向下一项
4.当某一多项式处理完时，将另一个多项式所有节点依次复制到结果多项式中
*/
