# 求逆元
ax = 1(MOD m)
存在的条件是 gcd(a, m) == 1

```
int mod_inverse(int a, int m) {
    int x, y;
    exgcd(a, m, x, y);
    return (m + x % m) % m;
}
```

## 求解线性同余方程ax = b (MOD m)的几种方法

- 使用逆元求解

特殊情况：a, m互素

x 同余 [inverse(a) * b ](mod m)

一般情况：设gcd(a, m) = g

x 同余 [inverse(a/g) * (b/g)] mod( m/g)



### 莫比乌斯函数

```

bool isprime[N];
int prime[N];
int mu[N];
int mind[N];




int main() {

    int n = 1000;
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    int tot =0;
    mu[1]=1;
    for(int i=2; i <= n;++i) {
        if(isprime[i]) {
           prime[++tot]= i;
           mu[i]=-1;
           mind[i]= i;
        }
        for(int j=1; j<=tot && prime[j]*i<=n; ++j) {
            isprime[prime[j]*i]=false;
            mind[prime[j]*i] = prime[j];
            if(i % prime[j]==0) break;
            mu[prime[j]* i] =- mu[i];
        }
    }   

}
```
（上面的mu[i]是莫比乌斯函数，prime是质数表，isprime[i]表示i是否为质数，mind[i]表示i的最小质因子）