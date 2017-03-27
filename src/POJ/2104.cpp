// 6720340_AC_8688ms_1508kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
#define N (100007) //The size of the array
struct Node {
    int val;
    int id;
    bool operator <(const Node &n) const { return val < n.val; }
};

int n,k;
Node a[N];


int query(int b,int e,int k) {
    for (int i=1; i<=n; i++) {
        if (a[i].id <=e && a[i].id >= b) {
            k--;
        }
        if (!k) return a[i].val;
    }
}

void init() {
    memset(a, 0, sizeof(a));
}
int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >>k) {
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i].val);
            a[i].id = i;
        }
        sort(a+1, a+n+1);
        int b, e, tar;
        for (int i=0; i<k; i++) {
            scanf("%d%d%d", &b, &e, &tar);
            printf("%d\n",query(b, e, tar));
        }

    }
}


