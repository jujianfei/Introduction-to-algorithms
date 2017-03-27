// 6611450_AC_0ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <sstream>
#include <deque>
using namespace std;
#define N  10007
#define INF 0x3f3f3f3f
long long a[N];
long long n, m;
long long use[N];

long long cntr=0;
bool can(long long x)
{
    long long sum=0;
    cntr=0;
    for(long long i=0;i<n;i++) {

        if(a[i]>x) return false;
            if(a[i]+sum<=x) {
               sum = sum + a[i];
               if(i==0) cntr++;
            } else {
                sum=a[i];
                cntr++;
            }
    }
    if(cntr<=m) {
        return true;
    }

    else
        return false;
}



void print(long long high_bound)
{
    long long group = 1, sum = 0;
    for(long long i = n-1; i >= 0; i--) {
        if(sum + a[i] > high_bound) {
            use[i] = 1;
            sum = a[i];
            group++;
        } else
            sum += a[i];
        if(m-group == i+1) {
            for(long long j = 0; j <= i; j++)
                use[j] = 1;
            break;
        }
    }
    for(long long i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
        if(use[i]) printf("/ ");
    }
    printf("%d\n", a[n-1]);
}



int main() {
    //("in.txt", "r", stdin);
    long long cases;
    cin >> cases;
    while (cases--) {
        memset(use, 0, sizeof(use));
        cin >> n >> m;
        for (long long i=0;i<n;i++) {
            scanf("%d", a+i);
        }
        long long e = INF, b=0;
        long long cnt = 0;
        while (e-b>1) {
            long long mid = (b+e)/2;
            if (can(mid)) {
                e = mid;
            } else {
                b = mid;
            }
            cnt ++;
        }

        print(e);
}








}

