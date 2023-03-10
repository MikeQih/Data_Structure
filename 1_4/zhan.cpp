#include <stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
    ElemType data[MaxSize];
    int top;
}SqStack;

//新元素入栈
bool Push(SqStack &S,ElemType x){
    if (S.top==MaxSize-1){
        return false;
    }
    S.top = S.top+1;
    S.data[S.top] = x; 
    // or S.data[++S.top]=x;
    return true;   
}

//出栈操作
bool Pop(SqStack &S,ElemType &x){
    if (S.top==-1){//如果不是-1(当前元素的位置)而是0的话(指向接下来可以插入数据元素的位置)，就是 --S.top和赋值x反过来顺序
        return false;
    }
    x = S.data[S.top];
    S.top = S.top-1;
    // x = S.data[S.top--];
    return true;
}

//读栈顶元素
bool GetTop(SqStack &S,ElemType &x){
    if (S.top==-1){
        return false;
    }
    x = S.data[S.top]; //x记录栈顶元素
    return true;
}

int main(int argc, char const *argv[])
{
    /* 15:19
    栈(stack)是只允许在一端进行插入或删除操作的线性表
    栈顶：允许插入和删除的一端 
    栈底：不允许插和删的一端 
    空栈
    后进先出(LIFO：Last In First Out)

    增：Push(&S,x) 进栈 若栈S未满，把x放到S栈的栈顶
    删：Pop(&S,&x) 出栈 若栈S非空，则弹出栈顶元素，并用x返回

    顺序栈的缺点：栈的大小不可变

    共享栈：两个栈共享同一片空间
    0号栈栈顶指针，S.top0=-1 (从下)
    1号栈栈顶指针,S.top1=MaxSize (从上)
    栈满的条件：top0+1==top1
    */
    return 0;//看到p21
}
