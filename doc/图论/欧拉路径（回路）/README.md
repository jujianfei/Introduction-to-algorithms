如果一个图只是形成一个连通所有节点的链，且每边只走一次，则成为欧拉道路。
具有欧拉回路或欧拉道路的图称为欧拉图（简称E图）。


无向图的欧拉道路充要条件：

图是连通的，每个点的度是偶数，或者最多有两个奇数度的点。

有向图欧拉道路的充要条件：

一个有向图存在欧拉道路的前提条件是这个图是个连通图，其次要求其每个点的入度等于出度，或者其中有一个点的出度比入度大1，另一个点的入度比出度大一这样就存在一条欧拉道路


下面是程序，同时适合于欧拉回路和欧拉道路，但是如果需要打印欧拉道路。
在主程序中调用的时候必须是道路的起点，另外打印的顺序是相反的，因此在真正使用这份代码的时候。
应该将printf换成一条printf语句，压入一个栈中。

```C++
#include <bits/stdc++.h>
using namespace std;

int G[5][5];

int vis[5][5];
int n = 5;

void add(int u, int v) {
    G[u][v] = G[v][u] = 1;
}

void euler(int u) {
    cout << "now " << u << endl;
    for (int v=0; v<n; v++) {
        if (G[u][v] && ! vis[u][v]) {
            vis[u][v] = vis[v][u] = true;
            euler(v);
            cout << u << " " << v << endl;
        }
    }
}

int main() {
    add(0, 1);
    add(1, 2);
    add(2, 3);
    add(3, 4);
    add(4, 2);
    add(2, 0);
    euler(0);
    cout << "he;;0" << endl;
}

```

一开始我怀疑这个算法是错误的，但是经过上述的例子之后，发现没有错，因为最后的结果是倒着输出的。实际第一次遍历到的那个边，不代表最后输出的边。


