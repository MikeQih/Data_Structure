#include <stdio.h>
#include <stdlib.h>
typedef TreeNode *HuffmanTree;
struct TreeNode{
    int Weight;
    HuffmanTree Left,Right;
};

HuffmanTree Huffman(MinHeap H){
    int i;
    HuffmanTree T;
    BuildMinHeap(H);
    for ( i = 1; i < H->Size; i++){
        //建新树，取最小左右节点
        T = malloc(sizeof(struct TreeNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight; //计算新权值
        Insert(H,T);
    }
    T = DeleteMin(H); //根节点
    return T;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
哈夫曼树(Huffman Tree)：设二叉树有n个叶子节点，每个叶子节点带有权值Wk，从根节点到每个叶子节点的长度为lk，则每个叶子节点的带权路径长度之和就是 WPL=Wklk (k=1 -> k=n)
最优二叉树/哈夫曼树：WPL最小的二叉树 (WPL, Weighted Path Length of Tree)
eg. 用判定树将百分制的考试成绩转换为五分制的成绩

构造：每次把权值最小的两棵二叉树合并！！！
特点：
1.没有度为1的节点
2.n个叶节点的哈夫曼树共有2n-1个节点 (n2=n0-1，因为没有n1。所以n0+n2= ntotal = 2n0-1)
3.任意非叶节点的左右子树交换后仍是哈夫曼树
4.同一组权值，存在不同构的哈夫曼树，但WPL值是一致的

避免二义性：前缀码(prefix code), 任何字符的编码都不是另一字符编码的前缀
solution：用二叉树编码，字符只在叶节点上 -> 构造一个哈夫曼树


小测验再看
3 2 4 2 1
(1 2) -》3

3 2 4 3
(2) 3 -》5

5 4 3
(3 4) -》7

5 7
5 7 -》12

3+6+4+6+8=27




*/