## 特别行动队

bzoj1911， http://acm.hust.edu.cn/vjudge/contest/120512#problem/D

朴素的dp状态转移方程

```
dp[i] = max (j from 0 to i-1) ( dp[j] + f( sum[i] - sum[j]) ); 
其中f = a * x *x + b * x  + c;
```

这种题目一般情况下分为**两种情况**，
来源和区别根本上在于题目中的max和min是哪一个。

这道题目是max

```
假设

k < j < i;

如果转移到i，j比k更优，又因为这里是max，越大越好

dp[j] + f(sum[i] - sum[j]) > dp[k] + f(sum[i] - sum[k]) 

```


化简 整理能够，将左边分离出G(j,k)， 右边分离出 g(i)


- 第一种情况 （本题目就是这种情况）
G(j,k) = G(k,j) > g(i)的情况，而且 g(i)是单调递减，或者相等的； （本题目a是负值）


- 第二种情况
G(j,k) = G(k,j) < g(i)的情况 如果是min的话，就是这种情况


## 算法

直接说明算法，然后验证其正确性：
维护一个单调队列：这里维护G（x,y）单调递减的性质， x,y是相邻的。如果考虑斜率，那么斜率就是单调递减的，表现在图像上就是上凸的性质。


为什么要维护单调递减的队列呢？

假设如果G(i, j) ≥ G(j, k)  k<j<i是相邻的，那么j一定不是最优的决策：可以直接排除j

为什么？

1)G(i, j)> g(i) => G(i, j)> g(i0) => 转移到i0, i比j更优
2) G(i, j)≤g(i), all i0 s.t. G(i, j)< g(i0), G(j, k)≤G(i, j)< g(i0) =>
转移到i0,k比j更优
综上，j一定不是转移到i0的唯一最优决策.

```C++
long long a,b,c,n;

long long d[N];
long long dp[N];
long long sum[N];
long long q[N];

long long f(long long x) {
    return a * x * x + b * x + c;
}

long long getDP(long long i,long long j) {
    return dp[j] + f(sum[i]-sum[j]);
}

long long GUP(long long j,long long k) {
    return dp[j]-dp[k] + a * (sum[j] + sum[k]) * (sum[j]-sum[k]);
}

long long GDOWN(long long j, long long k) { // j > k
    return sum[j] - sum[k];
}

long long g(long long i) {
    return 2 * a * sum[i] + b;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    cin >> a >> b >> c;
    for (long long i=1;i<=n;i++) {
        scanf("%d", &d[i]);
    }

    sum[0] =dp[0] = 0;
    for(long long i=1; i<=n; i++)
        sum[i] = sum[i-1] + d[i];

    long long head=0;
    long long tail=0;
    q[tail++]=0;

    for(long long i=1;i<=n;i++)
    {
        while(head+1<tail && GUP(q[head+1],q[head])>=g(i)*GDOWN(q[head+1],q[head]))
            head++;
        dp[i]=getDP(i,q[head]);
        while(head+1<tail && GUP(i,q[tail-1])*GDOWN(q[tail-1],q[tail-2])>=GUP(q[tail-1],q[tail-2])*GDOWN(i,q[tail-1]))
            tail--;
        q[tail++]=i;
    }

    cout << dp[n] << endl;

    return 0;


}

```

这里的GUP(i, j) / GDOWN(i, j)就是那个G函数，


## 更加深入的总结一个这个算法

```
1，用一个单调队列来维护解集。

2，求解时候，从队头开始，如果已有元素a b c，当i点要求解时，如果G[b,a] >= sum[i]，那么说明b点比a点更优，a点可以排除，于是a出队。最后dp[i]=getDp(q[head])。

3，假设队列中从头到尾已经有元素a b c。那么当d要入队的时候，我们维护队列的上凸性质，即如果G[d,c] >= G[c,b]，那么就将c点删除。直到找到G[d,x] < G[x,y]为止，并将d点加入在该位置中。
```

## UVA1415


题意: 

给出一个长度为n的01序列, 要你求出一段至少长度为L的连续子序列, 该子序列的数字的平均值最大, 多解尽量保证长度小, 在保证起点编号尽量小, 求出起点和终点编号.

这题是一道数形结合的问题, 我从《浅谈数形结合思想在信息学竞赛中的应用》学习而得算法.

设Sum[i] = a1+a2+...+ai, 那么平均值ave(i,j) = (sum[j]-sum[i-1])/(j-(i-1));容易发现问题可以转换为: 求函数function(i, Sum[i])的任意两点的最大斜率. 具体可以从学习上面提到的[《浅谈数形结合思想在信息学竞赛中的应用》](http://wenku.baidu.com/link?url=LpNs7M_1a-MDHmfWirrXeLP_ujale5-xyTXv__hNB4S50G7L33Gr49TCA4soYlyw1RR4VmvBMQFTLGdmFy-zM5CsPjLmXxSj0e8PmDjK68W)讲解


```C++
#include <cstdio>  
#include <iostream>  
#include <cstring>  
using namespace std;  
#define MAX 100010  
int n, L;  
  
  
char str[MAX];  
int sum[MAX], qu[MAX];  
double ans;  
inline double getK(int i, int j) {  
 return (sum[j]-sum[i]) * 1.0 / (j-i);  
}  
int main() {  
    freopen("in.txt", "r", stdin);  
    int caseNum, i;  
    scanf("%d", &caseNum);  
    while(caseNum--) {  
        scanf("%d %d", &n, &L);  
        scanf("%s", str+1);  
        memset(sum, 0, sizeof(int)*(n+5));  
        memset(qu, 0, sizeof(int)*(n+5));  
        for(i = 1; i <= n; ++i)  
        sum[i] = sum[i-1] + str[i]-'0';  
  
        /////////////////建立一个初始的值，其实不用非得是一个不存在的值/////////////////  
        ans = getK(0, L);  
        int start = 0, end = L;  
        int len = L;  
        ////////////////////////////////////////////////////////////////////////////////  
  
        int front = 0, rear = -1; //这样写，那么“队列至少有两个元素”这个条件的表示方法就发生了变化。  
  
        for(i = L; i <= n; ++i) {  
            int temp = i-L;  
            //维护下凸曲线  
            while(front < rear && getK(qu[rear], temp) < getK(qu[rear-1], qu[rear])) rear--;  
            qu[++rear] = temp;  
            //为什么，这里的等号不是很关键，因为，加入是相等的话，那么，也会因为下文的front中的  
            //那个等号而抵消。  
      
            //将不是当前最优的点, 从队列里面删除  
            while(front < rear && getK(qu[front], i) <= getK(qu[front+1], i)) front++;  
            //其实这里的等号是非常关键的，因为等号保证了，在平均值相同的情况下，长度尽量的短。  
            double t = getK(qu[front], i);  
            if(t == ans && len > i-qu[front]) {  
                len = i-qu[front];  
                start = qu[front];  
                end = i;  
            } else if(t > ans) {  
                ans = t;  
                len = i-qu[front];  
                start = qu[front];  
                end = i;  
            }  
        }  
        printf("%d %d\n", start+1, end);  
    }  
    return 0;  
}  
```


## Pr

- UVA-1451-平均值
- POJ-3709-K anonymous Sequence
