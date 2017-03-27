## 小于n，且与n互素的整数的个数

原理是容斥原理，这里不展开论述，可以参考刘汝佳第二版。

公式经过变形之后

首先设n的素数分解之后是：

n = p1^a1 * p2^a2 * ... pk^ak.

```
phi(n) = n * (1-(1/p1)) * (1-(1/p2)) ... * (1-1/pk)
```

这样算法复杂度降低到O(k).

但是仍然可以优化，只要找到每个素因子之后把它除干净，即可保证所有找到的因子都是素数。


那么求一个数字的欧拉函数如下
```C++
int euler_phi(int n) {
    int m = (int) sqrt(n+0.5);
    int ans = n;
    for (int i=2; i<=m; i++) {
        if (n%i == 0) {
            ans = ans / i * (i-1);
            while (n%i == 0) n/=i;
        }
    }
    if (n>1) ans = ans / n * (n-1);
    return ans;
}
```

如果是求1~n中的所有欧拉函数，直接使用类似筛选法的算法即可，原理自行体会，算法复杂度==O(nlglgn)

```C++
void init() {
    for (int i=0; i<N; i++) phi[i] = 0;
    phi[1] = 1;
    for (ll i=2; i<N; i++) if (phi[i] == 0) {
        for (ll j=i; j<N; j+=i) {
            if (phi[j] == 0) phi[j] = j;
            phi[j] = phi[j] / i * (i-1);
        }
    }
}
```