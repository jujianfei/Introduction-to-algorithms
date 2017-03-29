## 线性同余方程-参考逆元一节

## 线性同余方程组

对于
```
ai * x == bi (mod mi)
```

如果方程有解，那么一定是无穷的解。

可以写成

```
x == b (mod m)

```

因此只要求出 b m 即可。


方法就是代入法。

当gcd(m2, a*m1) 无法整除 b2 - a * b1时，方程组无解。

```
// 返回一个(b. m)的数对

pair<int, int> liner_congruence(const vector<int> & A, 
                                const vector<int> & B, 
                                const vector<int> & M) {
    // 由于开始没有任何限制，所以先把解设为表示所有整数 x==0(mod 1)
    int x = 0, m = 1;
    for (int i=0; i<A.size(); i++) {
        int a = A[i] * m, b = B[i] = A[i] * x, d = gcd(M[i], a);
        if (b % d != 0) return make_pair(0, -1); // 无解
        int t = b / d * mod_inverse(a/d, M[i]/d) % (M[i] / d);
        x = x + m * t;
        m *= M[i] / d;
    }
    return make_pair(x%m, m);

}
```