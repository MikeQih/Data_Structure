#include <stdio.h>
#include <stdlib.h>
#define ElementType int


void Bubble_Sort(ElementType A[],int N){
    int flag;
    for ( int i = N-1; i >= 0; i--){
        flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (A[j]>A[j+1])
            {
                // Swap(A[j],A[j+1]);
                int tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                flag = 1;
            } 
        }
        if (flag==0){ //全称无交换，就说明已经排出来了
            break;
        }
    }    
}

//希尔排序：按D个间隔来的插入排序
void Shell_Sort(ElementType A[],int N){
    int j,tmp;
    for ( int D = N/2; D > 0; D/=2){ //希尔
        for (int P = D; P<N; P++)//插入
        {
            tmp = A[P];
            for (j=P; j>=D && A[j-D]>tmp;j-=D)
            {
                A[j]=A[j-D];
            }
            A[j] = tmp;
            
        }
    }
}

void ShellSort_SedgeWick(ElementType A[],int N){ //希尔排序 用增量序列
    int Si,D,P,i;
    ElementType Tmp;
    int Sedgewick[] = {929,505,209,109,41,19,5,1,0};
    for (Si=0;Sedgewick[Si]>=N;Si++); //初始增量SedgeWick[Si]不能超过待排序列长度
    for(D=Sedgewick[Si];D>0;D=Sedgewick[++Si]){
        for (P=D;P<N;P++){
            Tmp = A[P];
            for ( i = P; i >= D && A[i-D]>Tmp; i-=D )
            {
                A[i] = A[i-D];
            }
            A[i]=Tmp;
        }
        
    }
}

void Insertion_Sort(ElementType A[],int N){ //插入/快速排序
    ElementType Tmp;
    int P,i;
    for (P = 1; P < N; P++){
        Tmp = A[P]; //摸下一张牌
        for ( i = P; i>0 && A[i-1]>Tmp; i--){
            A[i] = A[i-1]; //移出空位
        }
        A[i] = Tmp; //新牌落位
    }
}

void Swap(int *X,int *Y)
{
	int tmp = *X;
	*X = *Y;
	*Y = tmp;
}

ElementType Median3(ElementType A[], int Left, int Right){
    int Center = (Left+Right)/2;
    if (A[Left]>A[Center]){
        Swap(&A[Left],&A[Center]);
    }
    if (A[Left]>A[Right]){
        Swap(&A[Left],&A[Right]);
    }
    if (A[Center]>A[Right]){
        Swap(&A[Center],&A[Right]); //此时A[Left]<=A[Center]<=A[Right]
    }
    //只需考虑A[Left+1]...A[Right-2]
    return A[Right-1]; //返回基准Pivot
    
}
void QuickSort(ElementType A[],int Left,int Right){
    int Cutoff = 2;
    if(Cutoff<=Right-Left){
        int Pivot = Median3(A,Left,Right);
        int i = Left;
        int j = Right-1;
        for(;;){
            while(A[++i]<Pivot){}
            while(A[--j]>Pivot){}
            if(i<j){
                Swap(&A[i],&A[j]); //如果两边都碰到错误的，就交换位置
            }
            else break;
        }
        Swap(&A[i],&A[Right-1]);
        QuickSort(A,Left,i-1);
        QuickSort(A,i+1,Right);
    }
    else{
        Insertion_Sort(A+Left,Right-Left+1);
    }
}

//快速排序
void Quick_Sort(ElementType A[],int N){ //统一接口
    QuickSort(A,0,N-1);
}


qsort()
int main(int argc, char const *argv[])
{
    int array[] = {1,4,8,5,6};
    // Bubble_Sort(array,5);
    // Insertion_Sort(array,5);
    // ShellSort_SedgeWick(array,5);
    Quick_Sort(array,5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",array[i]);
    }
    
    return 0;
}
//从这从开始算法，之前堆，图什么的都是数据结构
/*
冒泡排序：最好情况：O(N)，最坏：O(N^2)
插入排序：最好情况：O(N)，最坏：O(N^2)

逆序对：对于下标i<j，如果A[i]>A[j]，则称(i,j)是一对逆序对(inversion)

希尔排序：eg.5间隔，3间隔，1间隔 k间隔有序的序列，在执行k-1间隔排序后，仍然是k间隔有序的
如果要排列元素，数量是几万级别的，用希尔排序+SedgeWick增量序列 效果好。
Hibbard增量排序(2^k-1 相邻元素互质)，SedgeWick增量排序({1,5,19,41...} 9*4^i-9*2^i+1 或 4^i-3*2^i+1 ??0不行吗还是) 

归并排序
递归：任何情况的时间复杂度都是 O(NlogN)
非递归算法：再看！！！补代码(归并排序：每两个单独进行一次排序 还不太懂。。。)

快速排序：分而治之
间接排序(表排序)：定义一个指针数组作为“表”(table)
物理排序(在表排序后还想把真实的“书”也排好，不只是排序号)：N个数字的排列由若干个独立的环组成

基数排序：
次位优先(Least Significant Digit) 个位，十位，百位依次比较，然后用链表串起来 eg.排扑克牌，为面值建13个桶，将结果合并，再为花色建4个桶
主位优先(Most Significant Digit)  eg.为花色建4个桶，在每个桶内分别排序，最后合并结果

排序方法总结：
简单选择排序 不稳定
冒泡排序 稳定
直接插入排序 稳定
希尔排序 不稳定
堆排序 不稳定
快速排序 不稳定
归并排序 稳定
基数排序 稳定


散列查找
散列表类型名称：符号表(SymbolTable)
本质：已知对象找位置 -> 有序安排对象：全序，半序；直接“算出”对象位置：散列

两项工作：
1.计算位置：构建散列函数确定关键词存储位置

2.解决冲突：应用某种策略解决多个关键词位置相同的问题 eg. h(keyi)=h(keyj)，当keyi!=keyj，称为冲突(Collision)
a.开放地址法(Open Addressing)：一旦发生冲突(该地址已有其他元素)，就按某种规则寻找另一空地址
线性探测
平方探测法(Quadratic Probing)：如果散列表长度是4k+3的素数时，平方探测法就可以探测到整个散列空间。
分离链表法(Separate Chaining)：将相应位置上冲突的所有关键词存储在同一个单链表中 ？？（这三方法补代码！！）

装填因子(Loading Factor)：设散列表空间大小为m，填入表中元素为n，则 alpha = n/m 为散列表的装填因子

散列函数构造：
1.直接定址法：取关键词的某个线性函数值为散列地址
2.除留余数法：h(key) mod p (p=Tablesize)
3.数字分析法：分析数字关键字在各位的变化情况，取比较随机的位作为散列地址 eg.取11位手机号码key的后4位作为地址
4.折叠法：把关键词分割成位数相同的几个部分，叠加
5.平方取中法：平方，然后 eg.取中间3位

电话狂人例子，补代码

模式匹配 最著名算法：KMP算法

看到9.4.3 非递归算法
看到10.3.1 桶排序，基数排序 代码补
看到sws1 环的分类 
看到KMP算法思路 4:47
*/
