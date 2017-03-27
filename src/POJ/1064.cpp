// 6520874_AC_188ms_256kB.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#define N 10000+7
using namespace std;
int n,k;
double a[N];
bool can(double x)
{
    int cnt=0;
    for(int i=0;i<n;i++) {
        cnt+=int(a[i]/x);
    }
    if(cnt<k)return false;
    else return true;
}
int main()
{
   
    while(scanf("%d%d",&n,&k)!=EOF) {
        double m=-1;
        for(int i=0;i<n;i++) {
            scanf("%lf",&a[i]);
            if(a[i]>m){ m=a[i];}
        }
        double l=0,r=m,mid;
        int cnt=0;
        while(cnt<100)
        {

            mid=(l+r)/2;
            if(can(mid)){
                l=mid;
            }
            else
            {
                r=mid;
            }
            cnt++;
        }
        printf("%.2f\n",floor(l*100)/100);
    }
}