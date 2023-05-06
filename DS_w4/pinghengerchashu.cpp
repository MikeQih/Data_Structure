#include <stdio.h>
int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
平衡二叉树：
eg.搜索树节点不同插入次序，将导致不同的深度和平均查找长度(ASL)
平衡因子(Balance Factor, BF)：BF(T)=hL-hR。hL和hR分别为T的左右子树的高度
平衡二叉树(Balanced Binary Tree，AVL树(发明者名字缩写))：空树，或任一节点的左，右子树高度差绝对值<=1，即|BF(T)|<=1。

n(h) = n(h-1) + n(h-2) + 1  ->  高度h为3时(4层)，最少需要7个节点(4+2+1)
节点数为n的AVL树的查找效率为log2(n)

看到w4 4.2.2平衡二叉树的调整
*/
