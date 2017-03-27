# 01背包

```
#include <bits/stdc++.h>
using namespace std;
#define N 107
int dp[N];
int v[N]; // 体积
int w[N]; // 价值
int n, tar;

void ZeroOnePack(int V, int W) {
    for (int v=tar; v>=V; v--)
        dp[v] = max(dp[v-V] + W, dp[v]);
}

int main() {
    // freopen("in.txt", "r", stdin);
    cin >> n >> tar;
    for (int i=1; i<=n; i++)  cin >> w[i] >> v[i];
    for (int i=1; i<=n; i++) {
        ZeroOnePack(v[i], w[i]);
    }


    cout << dp[tar] << endl;

}

```
第i轮的dp[j]的定义：使用前i个物品，重量恰好（或者不超过）j的情况下的最大收益。
如果是恰好装满背包：那么就是除了dp[0]是0之外，其他的都是-INF。
否则：dp所有的值，都是0。

下面相同。

- 补充：

这里如果tar以及v[i]相对较小，w[i]相对较大，那么使用这种方法是合理的，复杂度为O(n*tar)；

但是如果tar以及v[i]相对非常大，w[i]相对较小，那么应当换一种dp的方式。

定义```dp[i][j]```为，前i个物品，简直总和为j的时候，总重量的最小值，不存在的时候就是INF。

因此```dp[0][0] = 0```，而且```dp[0][j] = INF```。

那么状态转移方程就是

```
dp[i][j] = min(dp[i-1][j], dp[j-v[i]] + w[i]);
```


最后的答案

```
int res = 0;
for (int i=0; i<=MAXN * MAXV; i++) if dp[n][i] <= w: res = i;
```

那么复杂度变成了，O(n*(MAX_N * MAX_V))。


# 完全背包

```
void CompletePack(int V, int W) {
    for (int v=V; v<=tar; v++) {
        dp[v] = max(dp[v-V]+W, dp[v]);
    }
}

```

# 多重背包

- 解法一： 转化

这是一个多重背包的模板，也是十分好用的一种模板，因为这个比直接拆除01背包来做要省些时间。

这是为啥呢，首先先由我讲一下为什么能换成01背包吧。

 举个栗子吧。假如给了我们价值为2，但是数量却是10的物品，我们应该把10给拆开。

 要知道二进制可是能够表示任何数的，所以10就是可以有1，2, 4, 8之内的数把它组成，一开始我们选上1了，然后让10-1=9，再选上2，9-2=7，在选上 4，7-4=3，

而这时的3<8了，所以我们就是可以得出 10 由 1, 2, 4, 3 来组成，就是这个数量为1, 2, 3, 4的物品了，那么他们的价值是什么呢，是2, 4, 6, 8。

也就说给我们的价值为2，数量是10的这批货物，已经转化成了价值分别是2, 4, 6, 8元的货物了，每种只有一件哎！！！！这就是二进制优化的思想。

那为什么会有完全背包和01背包的不同使用加判断呢？

原因也很简单啊，当数据很大，大于背包的容纳量时，我们就是在这个物品中取上几件就是了，取得量是不知道的，也就理解为无限的啦，这就是完全背包啦。

反而小于容纳量的就是转化为01背包来处理就是了，可以大量的省时间。

```
#include<string.h>
#include<stdlib.h>
#define N 1000         //物品个数 
#define M 100000000    //所有物品可能的最大价值 
int m[N],c[N],w[N],f[M];
int V;
int max(int a,int b){return a>b?a:b;}
void ZeroOnePack(int cost,int weight) {
    int v;
    for(v=V;v>=cost;v--) f[v]=max(f[v],f[v-cost]+weight);
}
void CompletePack(int cost,int weight) {
    int v;
    for(v=cost;v<=V;v++)
        f[v]=max(f[v],f[v-cost]+weight);
}
void MultiplePack(int cost,int weight,int amount) {
    int k;
    if(cost*amount>=V) {// 转化成了一个无限数量的完全背包。
        CompletePack(cost,weight);
        return;
    }
    k=1;
    while(k<amount) {
        ZeroOnePack(k*cost,k*weight);
        amount=amount-k;
        k=k*2;
    }
    ZeroOnePack(amount*cost,amount*weight);
}
int main() {
    int n,i;
    scanf("%d %d",&n,&V);                           // 两种不同的初始化方式，根据情况自行选择 
    //memset(f,0,sizeof(f[0])*(V+1));               // 只希望价格尽量大 
    //memset(f,-M,sizeof(f[0])*(V+1));f[0]=0;       // 要求恰好装满背包 
    for(i=0;i<n;i++) scanf("%d %d %d",m+i,c+i,w+i);
    for(i=0;i<n;i++) MultiplePack(c[i],w[i],m[i]);
    printf("%d\n",f[V]);
    system("PAUSE");
    return 0;
}

```

- 解法二：单调队列优化


本质是维护一个滑动的窗口，窗口的大小不能超过 m[i]的大小

于是根据w[i]的大小，将原来的j划分成了w[i]个等价类，每个等价类，可以进行单调队列的维护。

将每个等价类维护一遍之后，就是完成了i个物品的工作。

实际上我们可以模仿，01背包问题，进行数组的重复利用。

```
先看一个例子：取m[i] = 2, v[i] = v, w[i] = w, V > 9 * v，
并假设 f(j) = F[i - 1][j]，观察公式右边要求最大值的几项：

j = 6*v:   f(6*v)、f(5*v)+w、f(4*v)+2*w 这三个中的最大值
j = 5*v:   f(5*v)、f(4*v)+w、f(3*v)+2*w 这三个中的最大值
j = 4*v:   f(4*v)、f(3*v)+w、f(2*v)+2*w 这三个中的最大值
显然，右边求最大值的几项随j值改变而改变，但如果将j = 6*v时，每项减去6*w，j=5*v时，每项减去5*w，j=4*v时，每项减去4*w，就得到：
j = 6*v:   f(6*v)-6*w、f(5*v)-5*w、f(4*v)-4*w 这三个中的最大值
j = 5*v:   f(5*v)-5*w、f(4*v)-4*w、f(3*v)-3*w 这三个中的最大值
j = 4*v:   f(4*v)-4*w、f(3*v)-3*w、f(2*v)-2*w 这三个中的最大值

```

因此队列中我们是维护一个单调的函数，但是真正使用的时候，我们对于这个函数进行适当的处理即可。

```C++
#include <iostream>
using namespace std;
#define N 107
int n, tar;
int v[N], w[N], m[N];

int dp[N]; // 滚动数组
int deq[N]; // 单调队列，下标
int deqv[N]; // 单调队列，值

void solve() {
    for (int i=0; i<n; i++) { // 枚举每个物品
        for (int a=0; a<v[i]; a++) { // 一共v[i]个等价类
            int s =0, t = 0; //双端队列的头部和尾部
            for (int j=0; j*v[i] + a<=tar; j++) { // 每个等价类中符合条件的j有哪些
                // 加入j构成的函数的时候，保证队列的单调性
                int val = dp[j * v[i] + a] - j * w[i];
                while (s < t && deqv[t -1] <= val) t--;
                deq[t] = j;
                deqv[t] = val;
                t ++;
                // 从头部取出，t
                dp[j*v[i] + a] = deqv[s] + j * w[i];

                //判断队列的长度是不是过长了
                if (deq[s] == j-m[i]) {
                    s ++;
                }
            }
        }
    }
    cout << dp[tar] << endl;
}
```

# 混合背包

```
for i = 1 to N
    if 第i件物品属于01背包
        ZeroOnePack(F,Ci,Wi)
    else if 第i件物品属于完全背包
        CompletePack(F,Ci,Wi)
    else if 第i件物品属于多重背包
        MultiplePack(F,Ci,Wi,Ni)
```

# 二维费用背包



二维费用的背包问题是指：对于每件物品，具有两种不同的空间耗费，选择这件物品必须同时付出这两种代价。

对于每种代价都有一个可付出的最大值（背包容量）。问怎样选择物品可以得到最大的价值。

设这两种代价分别为代价一和代价二，第i件物品所需的两种代价分别为Ci和Di。

两种代价可付出的最大值（两种背包容量）分别为V 和U。

物品的价值为Wi。


费用加了一维，只需状态也加一维即可。设F [i,v,u]表示前i件物品付出两种代价分别为v和u时可获得的最大价值。

状态转移方程就是：

```
F [i,v,u] = max{F[i − 1, v, u], F[i − 1, v − Ci, u − Di] + Wi}
```

如前述优化空间复杂度的方法，可以只使用二维的数组：

当每件物品只可以取一次时变量v和u采用逆序的循环，当物品有如完全背包问题时采用顺序的循环，当物品有如多重背包问题时拆分物品。

这里就不再给出伪代码了，相信有了前面的基础，读者应该能够自己实现出这个问题的程序。


- 注意费用背包的变形

有时，“二维费用”的条件是以这样一种隐含的方式给出的：最多只能取U件物品。

这事实上相当于每件物品多了一种“件数”的费用，每个物品的件数费用均为1，可以付出的最大件数费用为U。

换句话说，设F[v,u]表示付出费用v、最多选u件时可得到的最大价值，

则根据物品的类型（01、完全、多重）用不同的方法循环更新，最后在f[0...V, 0...U]范围内寻找答案。


# 分组背包



有N件物品和一个容量为V 的背包。

第i件物品的费用是Ci，价值是Wi。

这些物品被划分为K组，每组中的物品互相冲突，最多选一件。

求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

这个问题变成了每组物品有若干种策略：是选择本组的某一件，还是一件都不选。

也就是说设F [k, v]表示前k组物品花费费用v能取得的最大权值，

则有：
```
F [k, v] = max{F [k − 1, v], F [k − 1, v − Ci] + Wi | item i ∈ group k}
```

使用一维数组的伪代码如下：
```
for k = 1 to K
    for v = V to 0
        for item i in group k
            F [v] = max{F [v], F [v − Ci] + Wi}
```
这里三层循环的顺序保证了每一组内的物品最多只有一个会被添加到背包中。

另外，显然可以对每组内的物品优化？
