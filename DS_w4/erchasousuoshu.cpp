#include <stdio.h>
#include <stdlib.h>
#define ElementType int
typedef struct TNode *Position;
typedef Position BinTree; //二叉树类型
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

Position IterFind(ElementType X, BinTree BST){//找特定元素
    while(BST){
        if(X>BST->Data){
            BST = BST->Right;
        }
        else if(X<BST->Data){
            BST = BST->Left;
        }
        else{
            return BST;
        }
    }
    return NULL; //查找失败
}

Position FindMin(BinTree BST){
    if(!BST){ //空的二叉搜索树，返回0
        return NULL;
    }
    else if(!BST->Left){
        return BST; //已经是最左边，最小的了
    }
    else{
        return FindMin(BST->Left);
    }
}

Position FindMax(BinTree BST){ //这个为什么不和上面一样？
    if(BST){
        while(BST->Right){
            BST = BST->Right;
        }
    }
    return BST;
}

BinTree Insert(ElementType X, BinTree BST){
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else{
        if(X<BST->Data){
            BST->Left = Insert(X, BST->Left);
        }
        else if(X>BST->Data){
            BST->Right = Insert(X, BST->Right);
        }
    }
    return BST;
}

BinTree Delete(ElementType X, BinTree BST){ //再看！大致明白了
    Position Tmp;
    if(!BST) printf("要删除的元素未找到");
    else if(X<BST->Data){
        BST->Left = Delete(X,BST->Left);
    }
    else if(X>BST->Data){
        BST->Right = Delete(X,BST->Right);
    }
    else{ //找到要删除的节点
        if(BST->Left && BST->Right){
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Data,BST->Right);
        }
        else{ //被删除节点有一个或无子节点
            Tmp = BST;
            if(!BST->Left){
                BST = BST->Right;
            }
            else if(!BST->Right){
                BST = BST->Left;
            }
            free(Tmp);
        }
    }
    return BST;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
//14:50
/*
二叉搜索树(BST, Binary Search Tree)：
1.非空左子树的所有键值 小于 其根节点的键值
2.非空右子树的所有键值 大于 其根节点的键值
3.左/右子树都是二叉搜索树

特别函数：
Find,FindMin,FindMax,Insert,Delete
(delete:如果要删除的节点有左，右两棵子树。用另一节点替代被删除节点：右子树的最小元素，或左子树的最大元素)

*/
