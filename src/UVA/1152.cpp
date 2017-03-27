// 6564516_AC_2680ms_0kB.cpp
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
#define N  (4007*4007)
int n;

int a[N],b[N],c[N],d[N];
int a_b[N];

int acur,bcur,ccur,dcur,a_bcur;

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d",&cases);
    while (cases--) {
        acur=bcur=ccur=dcur=a_bcur=0;
        scanf("%d",&n);
        int tmpa,tmpb,tmpc,tmpd;
        for (int i=0;i<n;i++) {
            scanf("%d%d%d%d", &tmpa, &tmpb, &tmpc, &tmpd);
            a[acur++]=(tmpa);
            b[bcur++]=(tmpb);
            c[ccur++]=(tmpc);
            d[dcur++]=(tmpd);
        }
        for (int i=0;i<acur;i++) {
            for (int j=0;j<bcur;j++) {
                a_b[a_bcur++]=(a[i] + b[j]);
            }
        }
        sort(a_b, a_b + a_bcur);

        int ans = 0;
        for (int i=0; i<ccur; i++) {
            for (int j=0; j<dcur; j++) {
                int target = - (c[i] + d[j]);
                ans += upper_bound(a_b,a_b + a_bcur,target) - lower_bound(a_b,a_b + a_bcur,target);
            }
        }
        cout << ans << endl;
        if (cases!=0) {
            cout << endl;
        }

    }
}
