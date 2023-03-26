#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAXN 10
#define CLK_TCK CLOCKS_PER_SEC
#define MAXK 200
clock_t start,stop; //clock_t是clock()函数返回的 变量类型
double duration; //记录被测函数运行时间，以秒为单位

double f1(int n,double a[], double x);
double f2(int n,double a[], double x);
double f3(int n,double x, int a);
double f4(int n,double x, int a);


int main(int argc, char const *argv[])
{
    int i;
    double a[MAXN]; //存储多项式的系数
    for(i=0;i<MAXN;i++) a[i] = (double)i;

    start = clock();   //不在测试范围内的准备工作，写在调用clock()之前
    for(i=0;i<MAXK;i++){
        f1(MAXN-1,a,1.1);
    }

    stop = clock();
    // duration = ((double)(stop-start)) / CLK_TCK;//常数CLK_TCK：机器时钟每秒所走的打点数
    duration = ((double)(stop-start)) / CLK_TCK / MAXK;
    printf("ticks1 = %f\n",(double)(stop-start));
    printf("duration1 = %6.2e\n",duration);

    start = clock();
    for(i=0;i<MAXK;i++){
        f2(MAXN-1,a,1.1);
    }
    
    stop = clock();
    // duration = ((double)(stop-start)) / CLK_TCK;
    duration = ((double)(stop-start)) / CLK_TCK / MAXK;
    printf("ticks2 = %f\n",(double)(stop-start));
    printf("duration2 = %6.2e\n",duration);
    printf("\n");

    //1.3练习
    start = clock();
    double r = f3(5,1.1,1);
    printf("%f\n",r);
    stop = clock();
    duration = ((double)(stop-start)) / CLK_TCK;
    printf("duration2 = %6.2e\n",duration);

    start = clock();
    double r2;
    r2 = f4(5,1.1,1); //更快
    printf("%f\n",r2);
    stop = clock();
    duration = ((double)(stop-start)) / CLK_TCK;
    printf("duration2 = %6.2e\n",duration);
    
    return 0;
}

double f1(int n,double a[], double x){ //做了 (n^2+n)/2次乘法
    int i;
    double p = a[0];
    for(i=1;i<=n;i++){
        p += (a[i]*pow(x,i));
    }
    return p;
}
double f2(int n,double a[], double x){//更快 //做了n次乘法 (加减比乘除快很多，可忽略不计)
    int i;
    double p = a[n];
    for(i=n;i>0;i--){
        p += a[i-1]+x*p;
    }
    return p;
}
double f3(int n,double x, int a){//1.3
    int i;
    double p = a;
    for(i=1;i<=n;i++){
        p += pow(x,i)*1.0 / i;
    }
    return p;
}
double f4(int n,double x, int a){//1.3 m2
    int i;
    double p = 1.0/n;
    for(i=n;i>1;i--){
        p = 1.0/(i-1) + x*p;
    }
    return a+x*p;
}

/*
19:00
*/