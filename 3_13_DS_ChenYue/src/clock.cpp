#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define CLK_TCK CLOCKS_PER_SEC
#define MAXK 1e7
clock_t start,stop; //clock_t是clock()函数返回的 变量类型
double duration; //记录被测函数运行时间，以秒为单位

double f1(int n,double a[], double x);
double f2(int n,double a[], double x);
// double f1(int n,double x);
// double f2(int n,double x);

int main(int argc, char const *argv[])
{
    int i;
    double a[MAXN]; //存储多项式的系数
    for(i=0;i<MAXN;i++) a[i] = (double)i;

    start = clock();   //不在测试范围内的准备工作，写在调用clock()之前
    for(i=0;i<MAXK;i++){
        f1(MAXN-1,a,1.1);
        // f1(MAXN-1,1.1);
    }
    // f1(MAXN-1,a,1.1);
    // f1(MAXN-1,1.1);

    stop = clock();
    // duration = ((double)(stop-start)) / CLK_TCK;//常数CLK_TCK：机器时钟每秒所走的打点数
    duration = ((double)(stop-start)) / CLK_TCK / MAXK;
    printf("ticks1 = %f\n",(double)(stop-start));
    printf("duration1 = %6.2e\n",duration);

    start = clock();
    for(i=0;i<MAXK;i++){
        // f2(MAXN-1,1.1);
        f2(MAXN-1,a,1.1);
    }
    // f2(MAXN-1,a,1.1);
    // f2(MAXN-1,1.1);
    stop = clock();
    // duration = ((double)(stop-start)) / CLK_TCK;
    duration = ((double)(stop-start)) / CLK_TCK / MAXK;
    printf("ticks2 = %f\n",(double)(stop-start));
    printf("duration2 = %6.2e\n",duration);

    return 0;
}

double f1(int n,double a[], double x){
    int i;
    double p = a[0];
    for(i=1;i<=n;i++){
        p += (a[i]*pow(x,i));
    }
    return p;
}
double f2(int n,double a[], double x){//更快
    int i;
    double p = a[n];
    for(i=n;i>0;i--){
        p += a[i-1]+x*p;
    }
    return p;
}
// double f1(int n, double x){
//     int i;
//     double p = 0;
//     for(i=1;i<=n;i++){
//         p += ((pow(x,i))/i);
//     }
//     return p;
// }
// double f2(int n, double x){//更快
//     int i;
//     double p = 1.0/n;
//     for(i=n;i>0;i--){
//         p += (1.0/(i-1)+x*p);
//     }
//     return x*p;
// }
/*
看到 讨论1.3 把代码改改，不用a[]，测更大的数据

*/