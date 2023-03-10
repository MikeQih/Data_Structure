#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
struct ElemType{
    int value;
};

typedef struct BiTNode{//二叉树的链式存储
    ElemType data;
    struct BiTNode *lchild, *rchild;//左，右孩子指针
    struct BiTNode *parent; //父结点指针(加了后就成了三叉链表，方便找父结点)
}BiTNode, *BiTree;

int main(int argc, char const *argv[])
{
    //定义一棵空树
    BiTree root = NULL;

    //插入根结点
    root = (BiTree) malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild=NULL;
    root->rchild=NULL;

    //插入新结点
    BiTNode *p = (BiTNode *)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild = NULL;
    p->rchild = NULL;
    root->lchild = p; //作为根结点的左孩子
    return 0;
}