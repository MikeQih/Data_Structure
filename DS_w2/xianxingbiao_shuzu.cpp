#include <stdio.h>
#include <stdlib.h>
// typedef struct PolyNode *Polynomial;
// struct PolyNode{
//     int coef;
//     int expon;
//     Polynomial link;
// };
#define MAXSIZE 10
typedef struct LNode *List;
typedef int Elemtype;
struct LNode{
    Elemtype Data[MAXSIZE];
    int last;
};

List MakeEmpty(){
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->last = -1;
    return PtrL;
}

int Find(Elemtype X, List PtrL){
    int i=0;
    while(i<=PtrL->last && PtrL->Data[i]!=X){
        i++;
    }
    if (i>PtrL->last){ //没找到的话返回-1
        return -1;
    }
    else{
        return i; //找到后返回存储位置
    }
}//查找成功的平均比较次数为(n+1)/2, 平均时间性能为O(n)。

//插入 平均移动次数为n/2，平均时间性能为O(n)
void Insert(Elemtype X,int i,List PtrL){
    int j;
    if(PtrL->last == MAXSIZE-1){//已满
    printf("表满了");
    return;
    }
    if(i<1 || i>PtrL->last+2){ // 为啥不MAXSIZE-1?? last在哪定义的？？
        printf("位置不合法");
        return;
    }
    for (j = PtrL->last; i >=i-1; j--)
    {
        PtrL->Data[j+1] = PtrL->Data[j]; //倒序向后移动
    }
    PtrL->Data[j-1] = X;
    PtrL->last++; //last仍指向最后元素？？
    return;
}

//删除第i个元素(数组下标i-1) 平均移动次数为(n-1)/2, 平均时间性能为O(n)。
void Delete(int i,List PtrL){
    int j;
    if (i<1 || i>PtrL->last+1)
    {
        printf("不存在第%d个元素",i);
        return;
    }
    for ( j = i; j<=PtrL->last; j++)
    {
        PtrL->Data[j-1] = PtrL->Data[j]; //向前移动
    }
    PtrL->last--; //last仍指向最后元素？
    return;
}


int main(int argc, char const *argv[])
{
    struct LNode L;
    List PtrL;
    return 0;
}
/*
方法1:顺序存储结构直接表示
数组各分量对应多项式系数 eg.f(x)=4x^2-3x^2+1，下标0:1，下标2:-3，下标5:4，其他都是0。（缺点：x系数大时，浪费空间）


方法2:顺序存储结构表示非零项
用结构数组表示
eg.
P1(x) = 9x^12+15x^8+3x^2
下标i 0 1 2
系数a^i 9 15 3
指数i 12 8 2 //按指数的大小有序存储

P2(x) = 26x^19-4x^8-13x^6+82
下标i 0 1 2 3
系数a^i 26 -4 -13 82
指数i 19 8 6 0

P1: (9,12),(15,8),(3,2)
P2: (26,19),(-4,8),(-13,6),(82,0)
P3: (26,19),(9,12),(11,8),(-13,6),(3,2),(82,0)


方法3:链表结构存储非零项
链表中每个节点存储多项式中的一个非零项，包括系数和指数两个数据域以及一个指针域

线性表：由同类型数据元素构成有序序列的线性结构
表中元素个数称为线性表的长度
线性表没有元素时，称为空表
表起始位置是表头，表结束位置是表尾

线性表也可以用链表实现(前面是数组)
不要求逻辑上相邻的两个元素物理上也相邻(数组动一个，别的也要动)，只需要修改链

广义表(Generalized List)（看要不要抄例子 2.1.6）
广义表是线性表的推广
对于线性表而言，n个元素都是基本的单元素
广义表中，这些元素不仅可以是单元素也可以是另一个广义表(union)

多重链表：链表中的节点可能同时隶属于多个链
多重链表的指针域会有多个，如前面例子包含了Next和SubList两个指针域
但包含两个指针域的链表不一定是多重链表，比如双向链表不是多重链表
广泛的用途：基本如树，图这样相对复杂的数据结构都可以采用多重链表存储

2.1.6稀疏矩阵(十字链表还得看 没大懂)
看summary中的线性表(顺序表和链式表的代码 如果上面的出问题了)
看到2.2堆栈

*/
