#include <stdio.h>
//1.二叉树表示(静态链表)
#define MaxTree 10
#define Null -1 //区分c中的NULL(0),数组也需要下标0，所以用Null表示-1
#define ElementType char
#define Tree int
struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;

}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[]){
    int N; //?
    scanf("%d\n",&N);
    if(N){
        for(int i=0;i<N;i++) check[i]=0;
        for (int i = 0; i < N; i++){
            scanf("%c %c %c\n",&T[i].Element,&cl,&rl);
            if(cl!='-'){
                T[i].Left = cl-'0';
                check[T[i].Left]=1;
            }
            else{
                T[i].Left = Null;
            }    
        }
        for (int i = 0; i < N; i++){
            if(!(check[i]==0)){
                break;
            }
        }
        Root = i;
    }
    return Root;
}
int Isomorphic(Tree R1, Tree R2){
    if (R1==Null && R2==Null){
        return 1;
    }
    if ((R1==Null && !(R2==Null)) || (R2==Null && !(R1==Null)) ){
        return 0;
    }
    if (T1[R1].Element!=T2[R2].Element){
        return 0;
    }
    if ((T1[R1].Left==Null) && (T2[R2].Left==Null) &&
    (T1[T1[R1].Left].Element) == (T2[T2[R2].Left].Element)){
        return (Isomorphic(T1[R1].Left,T2[R2].Left)) && (Isomorphic(T1[R1].Right,T2[R2].Right));
    }
    else{
        return (Isomorphic(T1[R1].Left,T2[R2].Right)) && (Isomorphic(T1[R1].Right,T2[R2].Left));
    }
    
}

int main(int argc, char const *argv[])
{   
    //结构：1.建二叉树1和2 2.判断是否同构(isomorphic)并输出
    //需要设计的函数：1.读取数据并建立二叉树 2.判别是否同构
    Tree R1,R2;
    R1 = BuildTree(T1); //T1,2是全局变量
    R2 = BuildTree(T2);
    if(Isomorphic(R1,R2)){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    
    return 0;
}
//看到：w4 4.1二叉搜索树；做w2 q4
