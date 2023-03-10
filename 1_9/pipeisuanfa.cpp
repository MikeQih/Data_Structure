#include <stdio.h>
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];//每个分量存储一个字符
    int length;//串的实际长度
}SString;

int Index(SString S, SString T){ //朴素模式匹配算法，从S中找和T匹配的
    int k=1;
    int i=k,j=1;
    while (i<=S.length && j<=T.length){
        if(S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        }
        else{
            k++;
            i = k;
            j = 1;
        }
    }
    if (j>T.length) 
        return k;
    else    
        return 0;
}

int Index_KMP(SString S,SString T,int next[]){
    int i=1,j=1;
    while (i<=S.length && j<=T.length)
    {
        if (j==0||S.ch[i]==T.ch[j])
        {
            ++i;
            ++j;
        }
        else{
            j=next[j]; //模式串向右移动 (next数组)
        }
    }
    if (j>T.length)
        return i-T.length; //匹配成功 ？？
    else
        return 0;
    
    
}

int main(int argc, char const *argv[])
{
    /*
    KMP算法，朴素模式匹配算法的优化
    next[j]=S的最长相等前后缀长度+1，前缀：包含第一个字符，且不包含最后一个字符的子串；后缀：包含最后一个字符，且不包含第一个字符的子串

    eg.模式串：‘ababaa’
    next[1]=0;
    next[2]=1;
    序号j: 1 2 3 4 5 6
    模式串: a b a b a a
    next[j]:0 1 1 2 3 4
    KMP算法优化：当子串和模式串不匹配时，j=nextval[j]
    nextval[j]: 0 1 0 1 0 4 (eg.j=2, next是1, b!=a, 所以b的next[j]不变，为1)
    */
    return 0;//看到p38
}
