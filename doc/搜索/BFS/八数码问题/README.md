## 8数码问题


8数码的核心代码是使用bfs实现，关键问题是如何判断，某些状态已经访问过了。

下面STL的实现。

```C++

typedef int State[9];
const int MAXSTATE = 1000000;
State st[MAXSTATE], goal;
int dist[MAXSTATE];

set<int> vis;
void init_lookup_table() { vis.clear(); }
int try_to_insert(int s) {
  int v = 0;
  for(int i = 0; i < 9; i++) v = v * 10 + st[s][i];
  if(vis.count(v)) return 0;
  vis.insert(v);
  return 1;
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int bfs() {
  init_lookup_table();
  int front = 1, rear = 2;  // 队列不使用下标0，因为0视为不存在
  while(front < rear) {
    State& s = st[front];
    if(memcmp(goal, s, sizeof(s)) == 0) return front;
    int z;
    for(z = 0; z < 9; z++) if(!s[z]) break; // 找到0的位置
    int x = z/3, y = z%3;
    for(int d = 0; d < 4; d++) {
      int newx = x + dx[d];
      int newy = y + dy[d];
      int newz = newx * 3 + newy;
      if(newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
        State& t = st[rear];
        memcpy(&t, &s, sizeof(s));
        t[newz] = s[z];
        t[z] = s[newz];
        dist[rear] = dist[front] + 1; // 构造新的状态，尝试插入
        if(try_to_insert(rear)) rear++;
      }
    }
    front++;
  }
  return 0;
}

int main() {
  for(int i = 0; i < 9; i++)
    scanf("%d", &st[1][i]);
  for(int i = 0; i < 9; i++)
    scanf("%d", &goal[i]);
  int ans = bfs();
  if(ans > 0) printf("%d\n", dist[ans]);
  else printf("-1\n");
  return 0;
}

```

因此我们看到关键的问题是状态如何保存。


还有两种解决方案。

- 使用hash，将一个数组hash成为一个整数。

```C++
const int MAXHASHSIZE = 1000003;
int head[MAXHASHSIZE], next[MAXSTATE];
void init_lookup_table() { memset(head, 0, sizeof(head)); }
int hash(State& s) {
  int v = 0;
  for(int i = 0; i < 9; i++) v = v * 10 + s[i];
  return v % MAXHASHSIZE;
}
int try_to_insert(int s) {
  int h = hash(st[s]);
  int u = head[h];
  while(u) {
    if(memcmp(st[u], st[s], sizeof(st[s])) == 0) return 0;
    u = next[u];
  }
  next[s] = head[h];
  head[h] = s;
  return 1;
}
```


- 使用排列组合的编码和解码函数。

目的是将0~8!的数字映射到0-362879之间的数字。

```C++
int vis[362880], fact[9];
void init_lookup_table() {
  fact[0] = 1;
  for(int i = 1; i < 9; i++) fact[i] = fact[i-1] * i;
}
int try_to_insert(int s) {
  int code = 0;
  for(int i = 0; i < 9; i++) {
    int cnt = 0;
    for(int j = i+1; j < 9; j++) if(st[s][j] < st[s][i]) cnt++;
    code += fact[8-i] * cnt;
  }
  if(vis[code]) return 0;
  return vis[code] = 1;
}
```

这种方法很巧妙但是，如果节点的数目非常大，编码也会很大，数组开不下。

