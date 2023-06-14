#include <stdio.h>
Index Hash(const char *Key, int TableSize){
    unsigned int h = 0; //散列函数值 初始化为0
    while (*Key!='\0') //位移映射
    {
        h = (h<<5) + *Key++;
        return h % TableSize;
    }
    
}
//平方探测法

int main(int argc, char const *argv[])
{
    
    return 0;
}
/*
左移5位 <<5 相当于*32
*/
