#include <stdio.h>
#define ElementType int
#define MaxSize 10
#define NotFound 0
typedef struct Node *List;
typedef struct TNode *Position;
typedef Position BinTree; //二叉树类型
struct Node{
    ElementType Element[MaxSize];
    int Length;
};
struct TNode{//二叉树 树节点定义
    ElementType Data; //节点数据
    BinTree Left; //左子树
    BinTree Right; //右子树
};

int PostOrderGetHeight(BinTree BT){
    int HL,HR,MaxH; //比较左右子树的深度
    if (BT){
        HL = PostOrderGetHeight(BT->Left);
        HR = PostOrderGetHeight(BT->Right);
        MaxH = (HL>HR)?HL : HR;
        return (MaxH+1);
    }
    else return 0; //空树深度为0
    
}

void LevelOrderTravel(BinTree BT){
    Queue Q;
    BinTree T;
    if(!BT) return; //如果是空树，直接返回
    Q = CreatQueue(MaxSize);
    AddQ(Q,BT);
    while (!IsEmpty(Q))
    {
        T = DeleteQ(Q);
        printf("%d\n",T->Data);
        if(T->Left) AddQ(Q,T->Left);
        if(T->right) AddQ(Q,T->Right);
    }
    
}
void PreOrderTravel(BinTree BT){ //先序遍历：1.访问根节点 2.先序遍历左子树 3.先序遍历右子树
    // if (BT){
    //     printf("%d",BT->Data);
    //     PreOrderTravel(BT->Left);
    //     PreOrderTravel(BT->Right);
    // } 

    //先序遍历的非递归遍历算法
    BinTree T,BT;
    Stack S = CreateStack(MaxSize);
    while(T || isEmpty(S)){
        while(T){ //一直向左，并把沿途节点压入堆栈
            Push(S,T);
            T = T->left;
        }
        if (!IsEmpty(S)){
            T = Pop(S);
            printf("%5d",T->Data);
            T = T->right;
        }
        
    }
}
void InOrderTravel(BinTree BT){ //中序遍历：1.中序遍历左子树 2.访问根节点 3.中序遍历右子树
    if (BT){
        InOrderTravel(BT->Left);
        printf("%d",BT->Data);
        InOrderTravel(BT->Right);
    } 
}
void PostOrderTravel(BinTree BT){ //后序遍历：1.后序遍历左子树 2.后序遍历右子树 3.访问根节点
    if (BT){
        PostOrderTravel(BT->Left);
        PostOrderTravel(BT->Right);
        printf("%d",BT->Data);
    } 
}
//静态查找 方法1：顺序查找，时间复杂度O(n)
int SequentialSearch(List Tbl,ElementType K){ 
    //在Element[1]~Element[n]中 查找关键字为K的数据
    int i;
    Tbl->Element[0]=K; //建立"哨兵" (“哨兵”：可以在写for循环时，少写一个分支(索引i必须>0)，
    //碰到哨兵就说明循环结束，没找到(K提前被放到了索引为0的位置))
    for (i = Tbl->Length; Tbl->Element[i]!=K; i--);
    return i; //查找成功返回下标，不成功就是0(哨兵)
}

//静态查找 方法2：二分查找，时间复杂度O(log2(n))
//假设n个数据元素满足有序(eg.从小到大)，并且是连续存放(数组)，就可二分查找
int BinarySearch(List Tbl,ElementType K){
    int left,right,mid;
    left = 1;
    right = Tbl->Length;
    while(left<=right){
        mid = (left+right)/2;
        if(Tbl->Element[mid]>K){
            right = mid-1; //如果用right/left = mid的话，中间值始终不变，左右边界的值会一直向中间靠拢，所以不行
        }
        else if(Tbl->Element[mid]<K){
            left = mid+1;
        }
        else{
            return mid;
        }
    }
    return NotFound;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
树
分层次组织在管理上具有更高效率
(也可参考 1_10 shu.cpp / 1_17 - 2_9 的笔记)

查找(Searching)：根据关键字K，从集合R中找出关键字与K相同的记录
1.静态查找：集合中的记录是固定的，没有插入和删除操作，只有查找
2.动态查找：集合中的记录是动态变化的，除了查找还可能发生插入和删除

二分查找判定树
判定树上的每个节点需要的查找次数刚好为该节点所在的层数(从1开始)
查找成功时，查找次数不会超过判定树的深度
n个节点的判定树的深度为 [log2(n)+1] (eg.log2(11)+1 取整后3+1=4 所以4层)
ASL(平均成功查找次数)=(4*4+3*4+2*2+1)/11=3 (见3.1.3的图 第几层，几个树)
最大优点：在树中插入/删除节点，比在数组中 方便的多(快的多)->很好的解决动态查找

树的定义：
树(Tree)：n(n>=0)个节点构成的有限集合
当n=0时，称为空树。
对于任意一棵非空树(n>0)，它具备以下性质：
1.树中有一个称为“根(root)”的特殊节点，用r表示。
2.其余节点可分为m(m>0)个 互不相交 的有限集T1,T2,...,Tm,其中每个集合本身又是一棵树，称为原来树的“子树(SubTree)“

树与非树：
1.子树是不相交的
2.除了根节点外，每个节点有且仅有一个父节点
3.一棵N个节点的树，有N-1条边 (只有根节点头上没有)

基本术语：
1.结点的度(Degree)：节点的子树个数
2.树的度：树的所有节点的度的最大值
3.叶节点(Leaf)：度为0的节点
4.父节点(Parent)：有子树的节点 (是其子树的父节点)
5.子节点(Child)：A是B的父，B就是A的子 (子节点也称孩子节点)
6.兄弟节点(Sibling)：具有同一父节点的各节点，彼此是兄弟节点
7.路径和路径长度：从节点n1到nk的路径，为一个节点序列；路径所含边的个数为路径的长度
8.祖先节点(Ancester)：沿树的根节点到某一节点，路径上所有节点，都是该节点的祖先节点
9.子孙节点(Descendant)：某一节点的子树中所有节点，都是这个节点的子孙
10.结点的层次(Level)：根节点默认为第一层，其他任一节点的层数是其父节点层数加1 (从上往下数)
11.树的深度(Depth)：树中所有节点的最大层数 (总共多少层）

二叉树：度为2的一种树
一个有穷的节点集合，这个集合可以为空；
若不为空，则它是由 根节点和称为其左子树和右子树的两个不相交的二叉树组成

完全二叉树(Complete Binary Tree)：有n个节点的二叉树，对树中节点按从上到下，左到右顺序进行编号，编号为i的(1<=i<=n)节点 与满二叉树中编号为i的节点 在二叉树中位置相同。

操作集：1.IsEmpty 判断是否为空；2.Travelsal 遍历；3.CreatBinTree 创建一个二叉树
先序遍历 PreOrder：根左右(NLR) preoder 第一次路过时访问结点
中序遍历 InOrder：左根右(LNR) inorder 第二次路过时访问结点
后序遍历 PostOrder：左右根(LRN) postorder 第三次路过时访问结点
层次遍历 LevelOrder：从上到下，从左到右(一层一层地看)

层序遍历：
二叉树遍历的核心问题：二维结构的线性化
需要一个存储结构保存暂时不访问的节点
存储结构：堆栈，队列
基本过程：先根节点入队。1.从队列中取出一个元素。2.访问该元素所指节点。3.若该元素所指节点的左，右孩子节点非空，则将其左，右孩子的指针顺序入队。

由两种遍历序列确定二叉树：必须有中序遍历才行。
先序+中序：
1.根据先序遍历序列第一个节点确定根节点
2.根据此节点在中序遍历序列中分割出左右两个字序列
3.对左子树和右子树分别递归使用相同的方法，继续分解

同构：两棵树T1和T2，如果T1可以通过若干次左右孩子交换就变成T2，则称这两棵树是“同构”的。



11:40
*/
