#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (1007)
using namespace std;
#define M (long long)(1e9 + 7)

int x0, y0;
int n;
double timer(int x0, int y0 ,int x1, int y1, int v0) {
    return sqrt((x0- x1)*(x0-x1) + (y0 - y1)*(y0 - y1))/ v0;
}

int main() {
    //freopen("in.txt", "r", stdin);

    while (~scanf("%d%d", &x0, &y0)) {
        scanf("%d", &n);
        double miner = INF;
        int x, y, v;
        for (int i=0; i<n; i++) {
            scanf("%d%d%d", &x, &y, &v);
            miner = min(timer(x0, y0, x, y, v), miner);
        }
        printf("%.15f\n", miner);

    }


}