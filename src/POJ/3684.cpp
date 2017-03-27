// 6548878_AC_0ms_732kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N  17
#define  N 100+5
int n,H,R,T;
double y[N];
double g=10.0;
double calc(int T)
{
    if(T < 0) return H;
    double t = sqrt(2 * H / g);
    int k=int(T / t);
    if(k%2 == 0){
        double d = T - k*t;
        return H - g*d*d/2;
    }else{
        double d = k*t + t -T;
        return H - g*d*d/2;
    }
}

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        cin>>n>>H>>R>>T;
        for(int i=0;i<n;i++) {
            y[i]=calc(T-i);
        }
        sort(y,y+n);
        for(int i=0;i<n;i++){
            printf("%.2f ",y[i]+2*R*i/100.0);
        }printf("\n");

    }

}