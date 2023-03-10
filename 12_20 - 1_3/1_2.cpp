//静态链表 p71 11:00am
//游标实现法 data:存放数据元素 cur:next指针
#include <stdio.h>
#define MAXSIZE 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0 //p53有别的定义
typedef int ElemType;
typedef int Status;
typedef struct{
    ElemType data;
    int cur;
}Component,StaticLinkList[MAXSIZE];

Status InitList (StaticLinkList space){
    //space[0].cur为头指针，“0”表示空指针

    int i;
    for ( i = 0; i < MAXSIZE-1; i++){
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur = 0;//目前静态链表为空，最后一个元素的cur为0
    return OK;
    
}
int main(int argc, char const *argv[])
{
    // StaticLinkList c;
    // c[0].cur=0;
    // printf("%d\n",c[0].cur); //输出0
    return 0;
}

