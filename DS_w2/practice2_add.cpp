#include <stdio.h>
#include <stdlib.h>
typedef struct PolyNode *Polynomial;
#define ElementType int
struct PolyNode{
    int coef;
    int expon;
    Polynomial link;
};

void Attach(int c,int e,Polynomial *pRear){
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P; //修改pRear值
}

Polynomial ReadPoly(){
    Polynomial P,Rear,temp;
    int N,c,e;
    printf("请输入数据的组数：");
    scanf("%d",&N); //数据的组数
    P = (Polynomial)malloc(sizeof(struct PolyNode)); //链表头空节点
    P->link = NULL;
    Rear = P;
    printf("请依次输入数据(coef,expon)：\n");
    while(N--){
        scanf("%d %d",&c,&e);
        Attach(c,e,&Rear);
    }
    temp = P; //p当前指向的是NULL
    P = P->link;
    free(temp);
    return P;

}
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

Polynomial Add(Polynomial P1, Polynomial P2){
    //与practice add.cpp相同？
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
    for(;P1;P1=P1->link){
        Attach(P1->coef,P1->expon,&rear);
    }
    for(;P2;P2=P2->link){
        Attach(P2->coef,P2->expon,&rear);
    }
    rear->link = NULL;
    temp = front;
    front = front->link; //另front指向结果多项式第一个非零项
    free(temp);
    return front;
}
Polynomial Mult(Polynomial P1, Polynomial P2){
    Polynomial P,Rear,t1,t2,t;
    int c,e;
    if (!P1||!P2){
        return NULL; //有一个多项式是空的，就return NULL
    }
    t1 = P1;
    t2 = P2;
    P = (Polynomial) malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    while(t2){
        Attach(t1->coef*t2->coef,t1->expon+t2->expon,&Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while(t1){
        t2 = P2;
        Rear = P;
        while (t2){
            e = t1->expon+t2->expon;
            c = t1->coef*t2->coef;
            while(Rear->link && Rear->link->expon > e){
                Rear = Rear->link;
            }
            if(Rear->link && Rear->link->expon==e){
                if (Rear->link->coef+c){
                    Rear->link->coef += c;
                }
                else{ //系数等于0时，把它删掉
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else{ //如果系数不想等，需要申请一个新的节点
                t = (Polynomial) malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);
    return P;
}

void PrintPoly(Polynomial P){
    int flag=0;
    if (!P){
        printf("0 0\n");
        return;
    }
    while(P){
        if (!flag){
            flag=1;
        }
        else{
            printf(" "); //第一组数据前没有空格，所以第一个以后flag都是1，中间都加一个" "。
        }
        printf("%d %d",P->coef,P->expon);
        P = P->link;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Polynomial P1,P2,PP,PS;
    P1 = ReadPoly(); //返回P1的指针？
    P2 = ReadPoly();
    PP = Mult(P1,P2);
    PrintPoly(PP);
    PS = Add(P1,P2);
    PrintPoly(PS);

    return 0;
}
/*
题意理解：
设计函数分别求多项式的乘积与和
输出第一行：乘积结果
第二行：相加

多项式的表示：仅表示非零项
1.数组：
优点：简单，调试容易；
缺点：需要事先确定数组大小

2.链表：
优点：动态性强
缺点：编程略为复杂，调试比较困难

main函数中：
读入多项式1
读入多项式2
乘法运算并输出
加法运算并输出

所以需要设计的函数：
1.读一个多项式
2.两多项式相乘:
a.乘法运算转为加法运算，attach(coef相乘，expon相加)
b.逐项插入，将P1当前项(c1,e1)xP2当前项(c2,e2)，并插入到结果多项式中
3.两多项式相加
4.多项式输出

看到小白专场的3 加法乘及多项式输出 5:10

*/