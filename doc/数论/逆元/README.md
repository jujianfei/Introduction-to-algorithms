## 求逆元

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

x 同余 [inverse(a/g) * (b/g)] mod(m/g)

但是如果b不能整除gcd(a, m)那么原方程没有解。

## 费马小定理

在p是素数的情况下，对于任意的整数x都有，x^p == x(mod p)。

其中如果x无法被p整除，有 x^(p-1) == 1(mod p)。

p如果是素数，那么可以通过快速幂求出逆元。
