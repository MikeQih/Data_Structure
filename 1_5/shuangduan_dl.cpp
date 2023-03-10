#include <stdio.h>

#define MaxSize 10
typedef struct{
    char data[MaxSize];
    int top;
}SqStack;

bool bracketCheck(char str[],int length){
    SqStack S;
    int cnt=0;
    for (int i = 0; i < MaxSize; i++)
    {
        if (str[i]=='('||str[i]=='['||str[i]=='{')
        {
            // printf("str[i] = %c",str[i]);
            S.data[i]=str[i];
            cnt++;
        }
        else{
            if(cnt==0) return false;//扫描到右括号，且当前栈空
            if (str[i]==')' && S.data[cnt-1]!='(')//栈顶元素出栈
            {
                return false;
            }
            if (str[i]==']' && S.data[cnt-1]!='[')//栈顶元素出栈
            {
                return false;
            }
            if (str[i]=='}' && S.data[cnt-1]!='{')//栈顶元素出栈
            {
                return false;
            }
        }  
    }
    return (length%2==0);
}

int main(int argc, char const *argv[])
{
    /*
    队列：一端插入，另一端删除
    
    栈：一端插入和删除
    卡特兰数合法出栈序列：
    Cm(m在上),n(n在下) = n!/(m!(n-m)!)
    (1/(n+1))*(n!/(m!(n-m)!))
    eg.1,2,3,4  8!/(4!*(8-4)!*(4+1))=14

    双端队列：只允许从两端插入，两端删除的线性表(栈中合法的序列，双端队列中一定也合法)
    输入受限的sddl：一端插入，两端删除
    输出受限的sddl：两端插入，一端删除
    */

    //栈在括号匹配的应用
    char str1[] = {"{[()]}"}; //不对写的 改！
    int res = bracketCheck(str1,4);
    printf("answer is: %d\n",res);
    
    return 0;
}
