#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define ElementType int
typedef struct SNode *Stack;
typedef struct SNode_Lianbiao *Stack_Lianbiao;
struct SNode{
    ElementType Data[MaxSize];
    int Top;
};
struct DStack{
    ElementType Data[MaxSize];
    int Top1; //堆栈1栈顶指针
    int Top2; //堆栈2的栈顶指针
}S;
struct SNode_Lianbiao{
    ElementType Data;
    struct SNode_Lianbiao *Next;
};
//链表实现
Stack_Lianbiao CreateStack(){
    Stack_Lianbiao S_L;
    S_L = (Stack_Lianbiao) malloc(sizeof(Stack_Lianbiao));
    S_L->Next = NULL;
    return S_L;
}
int IsEmpty(Stack_Lianbiao S_L){
    return (S_L->Next==NULL); //为空返回1
}
void Push_L_S(ElementType item, Stack_Lianbiao S_L){ //因为是栈，所以就是往头插入一个节点
    struct SNode_Lianbiao *TmpCell;
    TmpCell = (struct SNode_Lianbiao *)malloc(sizeof(struct SNode_Lianbiao));
    TmpCell->Data = item;
    TmpCell->Next = S_L->Next;
    S_L->Next = TmpCell;
}

ElementType Pop_L_S(Stack_Lianbiao S_L){
    struct SNode_Lianbiao *FirstCell;
    ElementType TopElem;
    if(IsEmpty(S_L)){
        printf("堆栈为空，无法Pop");
        return NULL;
    }
    else{
        FirstCell = S_L->Next;
        S_L->Next = FirstCell->Next; //S_L一开始指向默认，S_L->Next是要删的节点；所以要指向next next
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}

//1.数组实现 入栈
void Push(Stack PtrS, ElementType item){
    if(PtrS->Top==MaxSize-1){
        printf("栈已满，添加失败");
        return;
    }
    else{
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

//2.出栈
ElementType Pop(Stack PtrS){
    if(PtrS->Top==-1){
        printf("栈中没有元素,pop失败");
        return NULL;
    }
    else{
        return (PtrS->Data[(PtrS->Top)--]);
        
    }
}

//eg.数组实现两个堆栈：两个栈从数组的两头开始向中间生长，当两个栈的栈顶指针相遇时，表示两个栈都满了
void Push_2(struct DStack *PtrS, ElementType item, int Tag){
    if(PtrS->Top2-PtrS->Top1==1){
        printf("堆栈已满");
        return;
    }
    if(Tag==1){
        PtrS->Data[++(PtrS->Top1)] = item;
    }
    else{
        PtrS->Data[--(PtrS->Top2)] = item;
    }
}
ElementType Pop_2(struct DStack *PtrS, ElementType item, int Tag){
    if(Tag==1){
        if (PtrS->Top1==-1){
            printf("堆栈1为空");
            return NULL;
        }
        else{
            return (PtrS->Data[PtrS->Top1]--);
        }
    }
    else{
        if (PtrS->Top2==MaxSize){
            printf("堆栈2为空");
            return NULL;
        }
        else{
            return (PtrS->Data[PtrS->Top2]++);

        }
    }
}

int main(int argc, char const *argv[])
{
    S.Top1 = -1;
    S.Top2 = MaxSize;
    return 0;
}
/*
堆栈(Stack)：具有一定操作约束的线性表
数据对象集：一个有0或多个元素的有穷线性表
操作集：长度为MaxSize的堆栈S 属于Stack，堆栈元素item 属于ElementType
只在一端(栈顶，Top)做插入(入栈 Push)，删除(出栈 Pop)
后入先出(Last in first out，LIFO)

5个操作：push,pop比较重要
1.Stack CreateStack(int MaxSize); 生成空堆栈，最大长度为MaxSize
2.int IsFull(Stack S, int MaxSize); 判断堆栈S是否已满
3.void Push(Stack S, ElementType item);将元素item压入堆栈
4.int IsEmpty(Stack S);判断堆栈是否为空
5.ElementType Pop(Stack S);删除并返回栈顶元素


堆栈的链式存储实现(见以上 带L_S的代码)：
栈的链式存储实际上就用个单链表，叫做链栈。
插入和删除只能在链栈的栈顶进行。

堆栈的其他应用：函数调用及递归实现；深度优先搜索；回溯算法


中缀表达式：a+b*c-d/e
后缀表达式：abc*+de/-
(和1_6 biaodashi.cpp内容差不多)

中缀表达式求值 策略：
将中缀转化为后缀(需要存储"等待中"的运算符号，将当前符号与"等待中”的最后一个运算符号比较)
1.运算数：直接输出
2.左括号：压入堆栈
3。右括号：将栈顶运算符弹出并输出，直到遇到左括号(出栈，不输出)
4.运算符：优先级>栈顶运算符，压栈；<栈顶，将栈顶运算符弹出并输出；
再比较新的栈顶运算符，直到该运算符大于栈顶运算符优先级为止，然后将该运算符压栈
5.若各对象处理完毕，则把堆栈中存留的运算符一并输出
eg. 2*(9+6/3-5)+4 -> 2 9 6 3 / + 5 - * 4 +


看到2.3 队列 2.3.1
*/