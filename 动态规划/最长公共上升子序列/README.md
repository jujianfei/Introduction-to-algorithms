
## 最长公共子序列：

```
dp[i][j] = max(dp[i][j-1], dp[i-1][j]) if s[i] != s[j];
dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1] + 1) if s[i] == s[j];
```

## 最长上升子序列

- 方法一：

定义
```
dp[i]:= 以a_i为结尾的最长上升子序列。

dp[i]:= max{1, dp[j] + 1 | j < i && a_j < a_i};
```

这种算法的复杂度是==O(n^2)。

- 方法二：

定义

```
dp[i]:= 长度为i+1的上升子序列中末尾元素的最小值。（不存在的话，就是INF）
```

```C++
int dp[MAX_N];
void solve() {
    fill(dp, dp+n, INF);
    for (int i=0; i<n; i++) {
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    int result = lower_bound(dp, dp+n, INF) - dp;
}
```


## 最长公共上升子序列

- 定义状态

```F[i][j]```表示以a串的前i个整数与b串的前j个整数且以b[j]为结尾构成的LCIS的长度。

状态转移方程：

```
①F[i][j] = F[i-1][j] (a[i] != b[j])

②F[i][j] = max(F[i-1][k]+1) (1 <= k <= j-1 && b[j] > b[k])
```

现在我们来说为什么会是这样的状态转移方程呢？

对于①，因为F[i][j]是以b[j]为结尾的LCIS，如果F[i][j]>0那么就说明a[1]..a[i]中必然有一个整数a[k]等于b[j],因为a[k]!=a[i]，那么a[i]对F[i][j]没有贡献，于是我们不考虑它照样能得出F[i][j]的最优值。所以在a[i]!=b[j]的情况下必然有F[i][j]=F[i-1][j]。

对于②，前提是a[i] == b[j],我们需要去找一个最长的且能让b[j]接在其末尾的LCIS。之前最长的LCIS在哪呢？首先我们要去找的F数组的第一维必然是i-1。因为i已经拿去和b[j]配对去了，不能用了。并且也不能是i-2，因为i-1必然比i-2更优。第二维呢？那就需要枚举b[1]...b[j-1]了，因为你不知道这里面哪个最长且哪个小于b[j]。这里还有一个问题，可不可能不配对呢？也就是在a[i]==b[j]的情况下，需不需要考虑F[i][j]=F[i-1][j]的决策呢？答案是不需要。因为如果b[j]不和a[i]配对，那就是和之前的a[1]...a[j-1]配对（假设F[i-1][j]>0，等于0不考虑），这样必然没有和a[i]配对优越。（为什么必然呢？因为b[j]和a[i]配对之后的转移是max(F[i-1][k])+1，而和之前的i`配对则是max(F[i`-1][k])+1。


以Hdu 1423 Greatest Common Increasing Subsequence为例。

```C++
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
using namespace std;  
const int MAXN = 1001;  
int a[MAXN], b[MAXN];  
int f[MAXN][MAXN];  
int n, m;  
void init()  
{  
    memset(f, 0, sizeof(f));  
}  

void dp()  
{  
    init();  
    int i, j, k;  
    for(i = 1; i <= n; i++)  
    {  
        for(j = 1; j <= m; j++)  
        {  
            f[i][j] = f[i-1][j]; // if(a[i] != b[j])  
            if(a[i] == b[j])  
            {  
                int MAX = 0;  
                for(k = 1; k <= j-1; k++) if(b[j] > b[k]) //枚举最大的f[i-1][k]   
                {  
                    MAX = max(MAX, f[i-1][k]);  
                }  
                f[i][j] = MAX+1;  
            }  
        }  
    }  
    int ans = 0;  
    for(int i = 1; i <= m; i++) ans = max(ans, f[n][i]);  
    printf("%d\n", ans);  
}  

以上的代码的时间复杂度是O(n^3)，那我们怎么去优化呢？

通过思考发现，第三层循环找最大值是否可以优化呢？

我们能否直接把枚举最大的f[i-1][k]值直接算出来呢？

假设存在这么一个序列a[i] == b[j],我们继续看状态转移方程②，会发现b[j] > b[k]，即当a[i] == b[j]时，可以推出a[i] > b[k]，那么有了这个表达式我们可以做什么呢？

可以发现，我们可以维护一个MAX值来储存最大的f[i-1][k]值。即只要有a[i] > a[j]的地方，那么我们就可以更新最大值，所以，当a[i] == b[j]的时候，f[i][j] = MAX+1，即可。

```C++
void dp()  
{  
    for(int i = 1; i <= n; i++)  
    {  
        int MAX = 0; //维护最大值   
        for(int j = 1; j <= m; j++)  
        {  
            f[i][j] = f[i-1][j]; //a[i] != b[j]  
            if(a[i] > b[j]) MAX = max(MAX, f[i-1][j]);  
            if(a[i] == b[j]) f[i][j] = MAX+1;  
        }  
    }  
    int ans = 0;  
    for(int i = 1; i <= m; i++) ans = max(ans, f[n][i]);  
    printf("%d\n", ans);  
}  
```

可以发现，其实上面的代码有些地方与0/1背包很相似，即每次用到的只是上一层循环用到的值，即f[i-1][j]，那么我们可以像优化0/1背包问题利用滚动数组来优化空间。


```C++
void dp()  
{  
    init();  
    for(int i = 1; i <= n; i++)  
    {  
        int MAX = 0;  
        for(int j = 1; j <= n; j++)  
        {  
            if(a[i] > b[j]) MAX = max(MAX, f[j]);  
            if(a[i] == b[j]) f[j] = MAX+1;  
        }  
    }  
    int ans = 0;  
    for(int j = 1; j <= m; j++) ans = max(ans, f[j]);  
    printf("%d\n", ans);  
}  
```

如果是求最长公共下降子序列呢？很明显嘛，把状态定义改动一下，即f[i][j]表示以a串的前i个整数与b串的前j个整数且以b[j]为结尾构成的LCDS的长度。

具体实现的时候只要把a[i] > b[j]改为a[i] < b[j]就可以啦。

扩展阅读：http://wenku.baidu.com/view/3e78f223aaea998fcc220ea0.html
