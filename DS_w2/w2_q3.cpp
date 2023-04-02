#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000
#define ElementType int
#define Null -1
typedef struct Node List;
typedef struct Node *PtrNode;

// https://www.cnblogs.com/2018shawn/p/13829050.html
// https://blog.csdn.net/m0_37149062/article/details/105047854

struct Node{
    ElementType data;
    int next;
};

List g_input[MAXSIZE+1];

int CheckLength(int pos,int K){
    if(K<=1){
        return 0;
    }
    pos = g_input[pos].next;
    int counter=0;
    while (counter<K && pos!=Null) //Null 是 -1
    {
        pos = g_input[pos].next;
        counter++;
    }
    if(counter==K){
        return 1;
    }
    return 0;
    
}
int RevertK(int head,int K){
    int counter = 1;
    int pre = g_input[head].next; //?
    int cur = g_input[pre].next;
    int next = g_input[cur].next;

    while(counter<K && cur!=Null){
        next = g_input[cur].next;
        g_input[cur].next = pre;
        pre = cur;
        cur = next;
        counter++;
    }
    //??
    next = g_input[head].next;
    g_input[next].next = cur;
    g_input[head].next = pre;
    return next;

}

void ReverseList(int pos,int K){
    while(CheckLength(pos,K)){
        pos = RevertK(pos,K);
    }
}

void Print(int head,int N){
    int pos = g_input[head].next;
    while (g_input[pos].next!=Null)
    {
        printf("%05d %d %05d\n",pos,g_input[pos].data,g_input[pos].next);
        pos = g_input[pos].next;
    }
    printf("%05d %d %d\n",pos,g_input[pos].data,g_input[pos].next);
    
}
int main(int argc, char const *argv[])
{
    int first,N,K;
    scanf("%d %d %d",&first,&N,&K);
    for (int i = 0; i < N; i++){
        int pos;
        scanf("%d",&pos);
        scanf("%d %d",&g_input[pos].data,&g_input[pos].next);
    }
    int head = MAXSIZE+1;
    g_input[head].next = first;
    ReverseList(head,K); //K：sublist中被reverse的长度
    Print(head,N);
    return 0;
}
//Reversing Linked List Q3 还得看！！不会
//Pop Sequence

