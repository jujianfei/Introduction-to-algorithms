// 6527163_AC_172ms_752kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;
#define N  1007
#define INF 0x3f3f3f3f
int n,k;

double gus;

struct Node {
    int a,b;
    Node(int a,int b):a(a), b(b) {}
    Node() {}
};
Node a[N];
bool cmp(const Node& n1, const Node& n2) {
    return n1.a*1.0-gus*n1.b*1.0 > n2.a*1.0-gus*n2.b*1.0;
}
bool ok(double x) {
    gus = x;
    sort(a, a+n, cmp);
    double ans = 0.0;
    for (int i=0; i<n-k; i++) {
        ans += a[i].a-gus*a[i].b;
    }
    return ans>=0;
}
int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> k) {

        if (n==0 && k==0) break;
        for (int i=0; i<n; i++)
            scanf("%d", &a[i].a);
        for (int i=0; i<n; i++)
            scanf("%d", &a[i].b);

            double e=INF,b=0.0;
            int cnt=0;
            while (cnt < 100) {
                cnt++;
                double mid = (b+e)/2;
                if (ok(mid)) {
                    b=mid;
                } else {
                    e=mid;
                }
            }
            printf("%.0f\n",b*100);
        }
    }

