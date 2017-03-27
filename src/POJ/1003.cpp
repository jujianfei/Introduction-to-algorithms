// 15149088_AC_0MS_748K.cc
#include<iostream>
#include<stdio.h>
int f(double x)
{
    int n=2;
    double sum=0;
    while(1)
    {
        sum+=1.0/n;
        if(sum>x)break;
        n++;
    }
    return n-1;
}

using namespace std;
int main()
{
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    double x;
    while(scanf("%lf",&x)!=EOF&&x!=0.0)
    {
        cout<<f(x)<<" card(s)"<<endl;
    }
}
