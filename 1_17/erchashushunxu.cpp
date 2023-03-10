#include <stdio.h>
#define MaxSize 100
#define Elemtype int

struct TreeNode{//二叉树的顺序存储
    Elemtype value;
    bool isEmpty; //结点是否为空
};

int main(int argc, char const *argv[])
{
    TreeNode t[MaxSize];
    for (int i = 0; i < MaxSize; i++)
    {
        t[i].isEmpty=true;
    }
    /*
    完全二叉树中有n个结点，则
    i是否有左孩子 -- 2i<=n?
    i是否有右孩子 -- 2i+1<=n?
    i是否是叶子/分支结点 -- i>(n/2)? (用2i>n更好？)

    结论：二叉树的顺序存储结构，只适合存储完全二叉树
    n个结点的二叉链表共有n+1个空链yu
    */
    
    /*
    先序遍历：根左右(NLR) preoder 第一次路过时访问结点
    中序遍历：左根右(LNR) inorder 第二次路过时访问结点
    后序遍历：左右根(LRN) postorder 第三次路过时访问结点
    (每个结点都会路过三次)

    树的层次遍历算法思想：
    1.初始化一个辅助队列
    2.根结点入队
    3.若队列非空，则队头结点出队，访问该结点，并将其左 右孩子插入队尾(如果有的话)
    4.重复3直到队列为空

    一个中/前/后/层(一层一层) 序遍历序列可能对应多种二叉树形态，前/后/层序序列的两两组合无法唯一确定一棵二叉树
    但前/后/层再加上 中序遍历序列就能确定唯一一棵二叉树
    key: 找到树的根结点，并根据中序序列划分左右子树，再找到左右子树根结点
    */
    return 0;
}
