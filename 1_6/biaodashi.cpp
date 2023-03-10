#include <stdio.h>


int isNumber(char* token);
int evalRPN(char ** tokens, int tokensSize);
int main(int argc, char const *argv[])
{
    //算术表达式：中（最熟悉的），前，后缀表达式 互相转换
    //前缀/后缀表达式求值

    /*
    灵感：不用界限符也能无歧义地表达运算顺序
    逆波兰表达式=后缀表达式 Reverse Polish notation
    波兰表达式=前缀表达式 Polish notation
    eg. 
    中缀表达式：a+b，后缀：ab+，前：+ab
    a+b-c, ab+c-, -+abc
    a+b-c*d, ab+c*d-, -+ab*cd

    eg2.中缀：A+B*(C-D)-E/F = 后缀：ABCD-*+EF/-(左优先) ABCD-*EF/-+(右优先)
    ("左优先"原则，只要左边的运算符能先计算，就优先算左边的 中缀转后缀)
    后缀表达式手算方法：从左往右扫描，每遇到一个运算符，就让运算符前面最近的两个操作数执行对应运算，合体为一个操作数

    eg3.中缀：A+B*(C-D)-E/F = 前缀：+A-*B-CD/EF(右优先) -+A*B-CD/EF(左优先)
    （"右优先"原则 中缀转前缀）
    */

    /*
    机算（后缀表达式的计算）栈来实现: (做leetcode Q150，逆波兰表达式求值)
    1.左到右扫描下个元素，直到处理完所有元素
    2.扫到操作数就压入栈，并回到1，否则执行3
    3.扫到运算符，则弹出两个栈顶元素，执行相应运算(先出栈的是“右操作数“)，运算结果压回栈顶，回到1

    机算（前缀表达式的计算）：
    1.从右往左扫描下一个元素，直到处理完所有元素
    2.扫到操作数就压入栈，回到1，否则执行3
    3.扫到运算符，则弹出两个栈顶元素，执行相应运算(先出栈的是“左操作数”)，运算结果压回栈顶，回到1
    */


    /*
    中缀表达式转后缀表达式（机算）：
    初始化一个栈，用来保存还不能确定运算顺序的运算符
    从左到右处理各个元素，直到末尾。可能遇到三种情况：
    1.遇到操作数：直接加入后缀表达式
    2.遇到界限符：遇到“(”直接入栈；遇到“)”则依次弹出栈内运算符并加入后缀表达式，直到弹出“(”为止（“(”不加入后缀表达式）
    3.遇到运算符：依次弹出栈中优先级高于或等于当前运算符的所有运算符，并加入后缀表达式，若碰到“(”或栈空则停止。之后再把当前运算符入栈。
    按上述方法处理完运算符后，将栈中剩余运算符依次弹出，并加入后缀表达式。

    中缀表达式计算（机算）：
    初始化两个栈，操作数栈和运算符栈
    扫描到操作数，压入操作数栈
    扫描到运算符或界限符，则按照”中转后缀“相同的逻辑压入运算符栈，
    (期间也会弹出运算符，每当弹出一个运算符时，就需要再弹出两个操作数栈的栈顶元素并执行相应运算，再把运算结果压回操作数栈)

    */

    printf("%d\n",'7'>='8');
    char *tokens[] = {"2","1","+","3","*"};
    int res = evalRPN(tokens,5);
    printf("res = %d\n",res);

    return 0;
}

//逆波兰表达式 看/问怎么解除warning
#include <string.h>
#include <stdlib.h>
int isNumber(char* token){
    return (strlen(token)>1 || (token[0]>='0' && token[0]<='9'));
}

int evalRPN(char ** tokens, int tokensSize){
    int n = tokensSize;
    int stk[n];
    int top=0;
    for(int i=0;i<n;i++){
        char* token = tokens[i];
        if(isNumber(token)){
            stk[top++] = atoi(token);
        }
        else{
            int num2 = stk[--top];
            int num1 = stk[--top];
            switch (token[0]){
                case '+':
                    stk[top++]=num1+num2;
                    break;
                case '-':
                    stk[top++]=num1-num2;
                    break;
                case '*':
                    stk[top++]=num1*num2;
                    break;
                case '/':
                    stk[top++]=num1/num2;
                    break;
            }
        }
    }
    return stk[top-1];
}