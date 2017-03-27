// 6527281_AC_7047ms_1900kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
using namespace std;
#define N  100007
#define INF 0xfffffff
int n,k;

double gus;

struct Node {
    int a,b,id;
    Node(int a,int b,int id):a(a), b(b), id(id) {}
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
    for (int i=0; i<k; i++) {
        ans += a[i].a-gus*a[i].b;
    }
    return ans>=0;
}
int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> k) {

        if (n==0 && k==0) break;
        for (int i=0; i<n; i++) {
            scanf("%d%d", &a[i].a, &a[i].b);
            a[i].id = i+1;
        }
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
            for (int i=0;i<k;i++) {
                printf("%d ",a[i].id);
            }printf("\n");
        }
    }

