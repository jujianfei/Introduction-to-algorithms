// 6521783_AC_438ms_636kB.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#include <algorithm>
#define N 100007
using namespace std;
int n,k;
int a[N];

bool can(int x) { // is it ok when mini distance between cow is x
    int last=1;
    int cnt=1;
    for (int i=2; i<=n; i++) {
        if (a[i] - a[last] < x) { continue; }
        else {
            last = i;
            cnt ++;
        }
    }
    return cnt >= k;
}

int main() {
    //freopen("IN", "r", stdin);
    cin >> n >> k;
    for (int i=1;i<=n;i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    int b=0;
    int e=1000000000*2;
    int mid=(b+e)/2;
    while(e-b>1)
    {
        if(can(mid))//如果可以还可以更大
        {
            b=mid;
            mid=(b+e)/2;
        }
        else
        {
            e=mid;
            mid=(b+e)/2;
        }
    }
    cout << b << endl;

}
