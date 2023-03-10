#include <stdio.h>
#define ElemType int

typedef struct BiTNode{
    //二叉树的结点（链式存储）
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode, *BiTree;

typedef struct ThreadNode{
    //线索二叉树结点
    ElemType data;
    struct ThreadNode *lchild, *rchild;
    int ltag,rtag; //左/右线索标志 tag==0 指针指向孩子，tag==1 表示指针是“线索”
} ThreadNode, *ThreadTree;

//全局变量放在哪？？
ThreadNode *p;
ThreadNode *pre=NULL;
ThreadNode *final = NULL;

// void InOrder(BiTree T){//中序遍历
//     InOrder(T->lchild);
//     visit(T);
//     InOrder(T->rchild);
// }

void visit(ThreadNode *q){
    if (q->lchild==NULL)
    {
        q->lchild=pre;
        q->ltag=1;
    }
    if (pre!=NULL && pre->rchild==NULL)
    {
        pre->rchild=q;
        pre->rtag=1;
    }
    pre=q;
    
}

void InThread(ThreadTree T){//中序遍历
    if(T!= NULL){
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }   
}

// void visit(BiTNode *q){
//     if (q==p)
//         final = pre; //找到p的前驱
//     else    
//         pre = q; //pre指向当前访问的结点
// }


int main(int argc, char const *argv[])
{

    /*
    中/先/后序线索二叉树：(找结点前后驱更方便)
    一个结点的前驱线索（左孩子指针充当）
    后继线索（右孩子指针充当）
    */
    
    return 0;
}
//看到p47 8:07
