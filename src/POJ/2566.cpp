// 6707465_AC_79ms_2312kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define N 100007
#define INF 0x3f3f3f3f
using namespace std;
int n,k,tmpk;

struct Node {
    int val;
    int id;
    bool operator < (const Node &n) const { return val < n.val; }
};
int a[N];
Node sum[N];
int retsum[N];
void slove(int target) {
    int l=0, r=1;
    int b,e, miner = INF;
    while (l<=n && r <=n) {
        int tmp = sum[r].val - sum[l].val - target;
        if (abs(tmp) < miner) {
            miner = abs(tmp);
            b = sum[l].id;
            e = sum[r].id;
        }
        if (tmp < 0) {
            r ++;
        } else if (tmp > 0) {
            l ++;
        } else {
            break;
        }
        if (l==r) r++;

}

    if (b < e) {
        cout << retsum[e] - retsum[b] << " " << b+1  << " " << e << endl;
    } else if (b > e){
        cout << retsum[e] - retsum[b] << " " << e+1 << " " << b << endl;
    } else {
        cout << "error" << endl;
    }
}

void init() {
    memset(a, 0, sizeof(a));
    memset(sum, 0, sizeof(sum));
    memset(retsum, 0, sizeof(retsum));
}
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w+", stdout);
    while (cin >> n >> k) {
        init();
        //cout << "===case===" << endl;
        if (n==0 && k==0) break;
        sum[0].val = sum[0].id = 0;
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
            retsum[i] = retsum[i-1] + a[i];
            sum[i].val = sum[i-1].val + a[i];
            sum[i].id = i;
        }

        sort(sum, sum+n+1);
//        for (int i=0; i<=n; i++) {
//            cout << sum[i].val << " " << sum[i].id << endl;
//        }
        for (int i=0; i<k; i++) {
            cin >> tmpk;
            slove(tmpk);
        }
    }

}

