## 8皇后问题

经过各种优化之后的代码

```C++
#include<cstdio>
#include<cstring>
using namespace std;

int C[50], vis[3][50], tot = 0, n = 8, nc = 0;

// vis的三个数组分别标记了纵向攻击和两个对角线攻击的情况。

void search(int cur) {
  int i, j;
  nc++;
  if(cur == n) {
    tot++;
  } else for(i = 0; i < n; i++) {
    if(!vis[0][i] && !vis[1][cur+i] && !vis[2][cur-i+n]) {
      C[cur] = i;              // C数组用作打印解
      vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 1;
      search(cur+1);
      vis[0][i] = vis[1][cur+i] = vis[2][cur-i+n] = 0;
    }
  }
}

int main() {
  scanf("%d", &n);
  memset(vis, 0, sizeof(vis));
  search(0);
  printf("%d\n", tot);
  printf("%d\n", nc);
  return 0;
}

```

需要额外注意的是，在回溯中使用了全局变量，那么最后的时候，一定要修改回来。

