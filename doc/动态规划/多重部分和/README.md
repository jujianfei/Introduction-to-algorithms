## 多重部分和

n种大小不同的数字 ai，每种各mi个，判断是否可以从这些数字之中选出若干个使他们的和恰好为K。
输入：
n=3;
a={3,5,8}
m={3,2,2}
K=17
输出：
Yes(3*3+8)

思路：

这个问题可以用DP来求解: dp[i][j] := 用前i种数字是否能加和成j

```C++
#include <iostream>
#include <vector>
using namespace std;
int n,K;
const int maxn=100;
const int maxk=100000;
int a[maxn],m[maxn];
bool dp[maxn][maxk];
int main() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>m[i];
    cin>>K;
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<=K;j++)
            for(int k=0;k<=m[i] && k*a[i]<=j;k++)
                dp[i+1][j] |=dp[i][j-k*a[i]];

    if(dp[n][K])cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;               
}
```

这种算法的复杂度是==O(K*sigma(m_i))，同时这种方式也不能充分地利用dp数组的信息，产生很多浪费。

改进：

```
dp[i+1][j]:=前i种数字，加和得到j的时候，剩余多少个，（不能得到j的时候，返回-1）
```

```C++
                
int dp[MAXK+1];
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=K; j++) {
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] || dp[j-a[i]] <= 0) {
                dp[j] = -1;
            } else {
                dp[j] = dp[j-a[i]]-1;
            }
        }
    }
    if (dp[K] >= 0) printf("yes\n");
    else printf("no\n");
}

```