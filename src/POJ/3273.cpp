// 6526308_AC_79ms_1128kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
using namespace std;
#define N  100007
#define INF 0x3f3f3f3f
int a[N];
int n, m;

bool can(int x)
{
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++) {
        if(a[i]>x) return false;
            if(a[i]+sum<=x) {
               sum = sum + a[i];
               if(i==0) cnt++;
            } else {
                sum=a[i];
                cnt++;
            }
    }

    if(cnt<=m)return true;
    else return false;
}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0;i<n;i++) {
        scanf("%d", a+i);
    }
    int e = INF, b=0;
    int cnt = 0;
    while (e-b>1) {
        int mid = (b+e)/2;
        if (can(mid)) {
            e = mid;
        } else {
            b = mid;
        }
        cnt ++;
    }
    cout  << e << endl;






}
