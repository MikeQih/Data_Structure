#include <stdio.h>
#define MaxSize 100
#define Elemtype int

struct TreeNode{//二叉树的顺序存储
    Elemtype value;
    bool isEmpty; //结点是否为空
};

TreeNode t[MaxSize];

int main(int argc, char const *argv[])
{
    /*
    空树：结点数为0的树

    非空树的特性：
    有且仅有一个根结点
    没有后继的结点称为”叶子结点”（或终端结点）
    有后继的结点称为“分支结点”（或非终端结点）
    除了根结点外，任何一个结点都有且仅有一个前驱
    每个结点可以有0或多个后继

    属性：
    结点的层次（深度 默认从1开始）（从上往下数）
    结点的高度（从下往上数）
    树的高度（深度）（总共多少层）
    结点的度（有几个孩子（分支））
    树的度（各结点的度的最大值）

    有序树：逻辑上看，树中结点从左至右是有次序的，不能互换
    无序树：从左至右无次序的，可以互换

    森林：森林是m(m>=0)棵互不相交的树的集合 eg.全中国所有人家的家谱
    */

    /*
    树的常考性质：
    结点数=总度数+1 (根结点的1)
    度为m的树：任意结点的度<=m，至少有一个结点度=m，一定是非空树，至少有m+1个结点
    m叉树：任意结点的度<=m，允许所有结点的度都<m，可以是空树
    度为m的树和m叉树 第i层至多有m^(i-1)个结点(i>=1)
    高度为h的m叉树至多有(m^h-1)/(m-1)个结点
    高度为h的m叉树至少有h个结点；高度为h，度为m的树至少有h+m-1个结点
    具有n个结点的m叉树的最小高度为logm(n(m-1)+1)

    二叉树是n个结点的有限集合(n>=0)
    1.或者为空二叉树，n=0
    2.或者由一个根结点和两个互不相交的被称为根的左子树和右子树组成。左子树和右子树又分别是一棵二叉树。
    特点：每个结点最多只有两课子树，左右子树不能颠倒（二叉树是有序树）
    满二叉树：高度为h，结点数2^h-1 特点：只有最后一层有叶子结点，不存在度为1的结点，按层序从1开始编号，结点i的左孩子为2i，右孩子为2i+1，结点i的父结点为i/2
    完全二叉树：当且仅当每个结点都与高度为h的满二叉树的结点一一对应时，称为完全二叉树。特点：只有最后两层可能有叶子结点，最多只有一个度为1的结点，按层序从1开始编号，结点i的左孩子为2i，右孩子为2i+1，结点i的父结点为i/2，i<=|n/2|是分支结点，i>|n/2|为叶子结点

    二叉排序树：左子树所有结点关键字小于根结点，右子树结点关键字大于根结点，左/右子树又各是一棵二叉排序树
    平衡二叉树：树上任意结点的左子树和右子树的深度之差不超过1.    
    */

    /*
    二叉树常考性质：设树中结点总数为n，则:
    n=n0+n1+n2 0结点个数+1的+2的
    n=n1+2n2+1 得出n0=n2+1

    完全二叉树常考性质：具有n个结点的完全二叉树高度h(所在的层次)为log2(n+1)或log2n+1
    完全二叉树只有一个度为1的结点，即n1=0或1，n0=n2+1->n0+n2一定是奇数，
    若完全二叉树有2k(偶数)个结点：n1=1,n0=k,n2=k-1
    若有2k-1(奇数)个结点：n1=0,n0=k,n2=k-1

    */
    return 0;
}
