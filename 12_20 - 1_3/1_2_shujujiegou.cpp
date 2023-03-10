//SqList: sequence 顺序，序列
//动态分配
#include <stdio.h>
#include <stdlib.h>
#define InitSize 10 //默认最大长度
typedef struct{
    int *data; //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length; //顺序表当前的长度
}SeqList;

void InitList(SeqList &L){
    //用malloc函数申请一片连续的存储空间
    L.data = (int*)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SeqList &L,int len){
    int *p = L.data;
    L.data = (int*)malloc(sizeof(int)*(InitSize+len));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i]; //把数据复制到新区域
    }
    L.MaxSize = L.MaxSize+len;
    free(p); //释放原来的空间
    
}

bool ListInsert(SeqList &L,int i,int e){
    if(i<1||i>L.length+1){
        return false;
    }
    if(L.length>=L.MaxSize){
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i-1] = e;
    L.length++;
    return true;
}

int GetElem(SeqList L,int i){ //按位查找
    return L.data[i-1];
}
//按值查找
int LocateElem(SeqList L, int e){ //根据ElemType改e的类型
    for (int i = 0; i < L.length; i++){
        if(L.data[i]==e){
            return i+1;
        }
        return 0;
    }
}

bool ListDelete(SeqList &L,int i,int &e){
    if(i<1||i>L.length+1){
        return false;
    }
    e = L.data[i-1]; //把被删除的元素赋值给e
    for (int j = i; j < L.length; j++)//删除最后一个数有bug？？
    {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

int main(int argc, char const *argv[])
{
    SeqList L; //声明一个顺序表
    InitList(L); //初始化顺序表
    // IncreaseSize(L,5);
    int e = -1; //用变量e把删除的元素带回来
    if (ListDelete(L,3,e))
    {
        printf("已删除第3个元素,删除的元素值为%d\n",e);
    }
    else{
        printf("位序i不合法,删除失败\n");
    }
    
    
    return 0;//10:30 1.3
}
