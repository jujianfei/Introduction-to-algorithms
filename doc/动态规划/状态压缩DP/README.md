## 状态压缩解决旅行商问题

假设现在已经访问过的节点集合是S，当前所在的顶点是v，用```dp[S][v]```表示从v出发，访问剩余的点的所有顶点，最终回到顶点0的路径的权重总和的最小值。

因此有下面的递推公式。

```
dp[V(all)][0] = 0;
dp[S][v] = min{dp[S ^ {u}][u] + d(u, v) | u not <- S};

```

记忆化搜索的实现如下

```C++

int n;
int d[MAX_N][MAX_N];

int dp[1<<MAX_N][MAX_N]; // 记忆化搜索使用的数组

int rec(int S, int v) {
    if (dp[S][v] >= 0) {
        return dp[S][v];
    }
    if (S == (1<<n) - 1 && v == 0) {
        return dp[S][v] = 0;
    }
    int res = INF;
    for (int u = 0; u < n; u ++) {
        if (!(S >> u & 1)) {
            res = min(res, rec(S | 1<<u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

void solve() {
    
    memset(dp, -1, sizeof(dp));
    int res = rec(0, 0);
}

```

也可以使用迭代递推的方法[实现。](iter.cpp)

## [铺砖问题](http://www.hankcs.com/program/algorithm/poj-3420-quad-tiling.html)

## Pr

- POJ-2686-骑马旅行问题
- POJ-2441-Arrange_the_Bulls
- POJ-3254-Corn_Fields
- POJ-2836-Rectangular_Covering
- POJ-1795-DNA_Laboratory
- POJ-3411-Paid_Roads

