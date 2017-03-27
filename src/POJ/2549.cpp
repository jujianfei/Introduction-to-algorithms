// 6756472_AC_94ms_4492kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N 1000007
using namespace std;


struct Node {
    int val,i,j;
    Node(int val,int i,int j):val(val), i(i), j(j){}
    Node() {}
    bool operator < (const Node & n) const { return val < n.val; }
};

int n;
int a[N];
Node v[N];
int cur;

void init() {
    cur = 0;
}

int main() {
   // freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        //cout << "===cases===" << endl;
        init();
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                v[cur++]= Node(a[i] + a[j], i, j);
            }
        }

        sort(v, v+cur);
        bool ok = false;
        int ans = -1;
        for (int i=n-1; i>=0 && !ok ;i--) {
            for (int j=n-1; j>=0 && !ok; j--) {
                if (i==j)continue;
                Node tmp(a[i]-a[j], -1, -1);
                int fir = lower_bound(v, v+cur, tmp) - v;
                int sec = upper_bound(v, v+cur, tmp) - v;
                if (fir == sec) continue; //没有找到
                else {
                     //这里可能是找到了一个范围
                     for (int k=fir; k!=sec; k++) {
                        if(v[k].i != i && v[k].i != j && v[k].j != i && v[k].j != j) {
                            ok = true;
                            ans = a[i];
                        }
                     }
                }
            }
        }
        if (ok == false) {
            cout << "no solution" << endl;
        } else {
            cout << ans << endl;
        }
    }
}
