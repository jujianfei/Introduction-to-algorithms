// 6643563_AC_0ms_0kB.cpp
//自己对着输出看了好几遍,输出乱码，并不知道原因
#include <bits/stdc++.h>
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;
const int N=33;
LL lef[N+1], up[N+1], down[N+1];
void pre_cal()
{
    memset(lef, 0, sizeof(lef));
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    lef[1]=1;
    for(int i=2; i<=N; i++)
    {
        LL d1=1, d2=1;  //d1为分子，d2为分母
        for(int j=2; j<=i; j++)
        {
            d1=d1*j+d2;
            d2*=j;
            LL p=__gcd(d1, d2);
            d1/=p;
            d2/=p;
        }

        d1*=i;
        LL p=__gcd(d1, d2);
        d1/=p;d2/=p;    //约分

        lef[i]=d1/d2;
        up[i]=d1%d2;
        down[i]=d2;
    }

}


int main()
{
    
    pre_cal();
    int n;
    while(~scanf("%d", &n))
    {
        if(up[n]==0)    printf("%lld\n", lef[n]);
        else
        {
            for(LL i=lef[n]; i>0; i/=10 )    printf(" ");printf(" %lld\n", up[n]);   //****分子

            printf("%lld ", lef[n]);    //****左部
            for(LL i=down[n]; i>0; i/=10)      printf("-");printf("\n");

            for(LL i=lef[n]; i>0; i/=10 )    printf(" ");
            printf(" %lld\n", down[n]); //****分母
        }
    }
    return 0;
}


