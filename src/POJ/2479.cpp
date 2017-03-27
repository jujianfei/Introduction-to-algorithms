// 15703093_AC_438MS_1708K.cc
#include <iostream>
#include <stdio.h>
using namespace std;
#define N 50007
#include <cstring>
#include <cmath>
#define INF 0x3f3f3f3f
int cases;
int n;
int a[N];
int lt[N];
int rt[N];

int lres[N];
int rres[N];

int solve() {
    lt[0] = a[0];
    for (int i=1; i<n; i++) {
        if (lt[i-1] <= 0) {
            lt[i] = a[i];
        } else {
            lt[i] = lt[i-1] + a[i];
        }
    }

    lres[0] = lt[0];
    for (int i=1; i<n; i++) {
        lres[i] = max(lres[i-1], lt[i]);
    }



    rt[n-1] = a[n-1];
    for (int i=n-2; i>=0; i--) {
        if (rt[i+1] <= 0) {
            rt[i] = a[i];
        } else {
            rt[i] = rt[i+1] + a[i];
        }
    }

    rres[n-1] = rt[n-1];
    for (int i=n-2; i>=0; i--) {
        rres[i] = max(rres[i+1], rt[i]);
    }

    int maxer = -INF;
    //从这两个中间选出那个最大的
    for (int i=0; i<n-1; i++) {
        maxer = max(maxer, lres[i] + rres[i+1]);
    }

    //cout << lres[6] << " " << rres[7] <<endl;
    return maxer;
}


int main() {
    //freopen("in.txt","r",stdin);
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) { scanf("%d", &a[i]); }
        cout << solve() << endl;
    }
}
