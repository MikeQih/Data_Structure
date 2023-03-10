#include <stdio.h>
#include <string.h>
#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];//每个分量存储一个字符
    int length;//串的实际长度
}SString;

bool SubString(SString &Sub,SString S,int pos,int len){
    //子串范围越界
    if ((pos+len-1)>S.length)
        return false;
    for (int i = pos; i < pos+len; i++){
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length=len;
    return true;
}

int StrCompare(SString S,SString T){
    for (int i = 0; i<=S.length && i<=T.length; i++){
        if(S.ch[i]>T.ch[i])
            return S.ch[i]-T.ch[i];
    }
    return S.length-T.length;
    
}

int Index(SString S,SString T){
    int i=1,n=S.length,m=T.length; //这样等于StrLength()嘛？
    SString sub; //用于暂存子串
    while (i<=n-m+1){
        SubString(sub,S,i,m);
        if (StrCompare(sub,T)!=0) ++i;
        else return i;//返回子串在主串中的位置
    }
    return 0; //S中不存在与T相等的子串
    
}

int main(int argc, char const *argv[])
{
    /*
    串：即字符串(String) eg.S='a1,a2,...,an'
    S是串名，串中字符的个数n称为串的长度，n=0时的串称为空串(用0表示?)
    字符集编码：每个字符在计算机中对应一个二进制数，比较字符的大小其实就是比较二进制数的大小

    eg.S='iPhone 11 Pro Max?'
    子串：串中任意个连续的字符组成的子序列 eg.'iPhone','Pro M'是串T的子序列
    主串：包含子串的串 eg.T是'iPhone'的主串
    字符在主串中的位置：也就是字符在串中的序号，从1开始！ eg.'1'在T中的位置是8
    子串在主串中的位置：字串第一个字符在主串中的位置,'11 Pro'在T中的位置为8

    字符集：
    英文字符：ASCII字符集；中文字符：Unicode字符集
    */

    /*
    串的存储结构
    ch[0]不用，访问字符串是从ch[1]开始访问的，给length在后面分配一点空间
    用链式存储存串的话：推荐每个结点存多个字符，存储密度提高
    */
    return 0;
} //看到p34
