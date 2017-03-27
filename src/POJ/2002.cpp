// 6575619_AC_1110ms_744kB.cpp
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
#define N  1007
#define ll long long

struct Node {
    int x, y;
    Node(int x,int y):x(x), y(y) {}
    Node() {}
    bool operator <(const Node & n) const {
        if (x < n.x) return true;
        else if (x > n.x) return false;
        else return y < n.y;
    }
};

int n;
int x,y;

Node a[N];
int cur;

int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d", &n) && n) {
        cur = 0;
        for (int i=0; i<n; i++) {
            scanf("%d%d", &x, &y);
            a[cur++] = Node(x, y);
        }
        sort(a, a+n);
        int cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int x1=a[i].x, y1=a[i].y;
                int x2=a[j].x, y2=a[j].y;

                if (x2 > x1 && y2 >= y1) {
                    int x3 = x1 - (y2-y1);
                    int y3 = y1 + (x2-x1);
                    int x4 = x3 - x1 + x2;
                    int y4 = y3 - y1 + y2;

                    if (upper_bound(a, a+n, Node(x3, y3))-lower_bound(a, a+n, Node(x3, y3)) == 1
                       &&upper_bound(a, a+n, Node(x4, y4))-lower_bound(a, a+n, Node(x4, y4)) == 1
                        )

                    cnt++;
                }
            }
        }
        cout << cnt << endl;

    }
}
