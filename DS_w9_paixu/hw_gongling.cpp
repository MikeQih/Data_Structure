// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     int N,x;
//     scanf("%d",&N);
//     int a[51] ={0};
//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d",&x);
//         a[x]++;
//     }
//     for (int i = 0; i <= 50; i++)
//     {
//         if(a[i]){
//             printf("%d:%d\n",i,a[i]);

//         }
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    int N,x;
    cin>>N;
    int a[51] ={0};
    for (int i = 0; i < N; i++)
    {
        cin>>x;
        a[x]++;
    }
    for (int i = 0; i <= 50; i++)
    {
        if(a[i]){
            cout<<i<<":"<<a[i]<<endl;

        }
    }
    
    
    return 0;
}

