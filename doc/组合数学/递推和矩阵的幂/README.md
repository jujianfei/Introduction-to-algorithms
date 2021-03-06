## 引入

对于斐波那契数列，f(n+2) = f(n+1) + f(n);

因此可以转换成矩阵的形式
```
[F(n+2)]  =  [1, 1] * [f(n+1)]
[F(n+1)]     [1, 0] * [f(n)]
```
如果设这个2x2的矩阵是A，那么最后的结果可以化简成
```
[F(n+2)] = A ^ n * [1]
[F(n+1)]           [0]
```

对于矩阵的幂可以使用快速幂的方式。加速。


更通用的方式。

```
a_(n+m) = (for i=0 to m-1) b_i * a_(n+i);
```

可以转化成矩阵的形式。

```

[a_(n+m)  ]           [b_(m-1) ... b_1, b_0]     [a_(m+n-1)]
[a_(n+m-1)]           [1 ...........0,    0]     [a_(m+n-2)]
...             *     [0, 1 ........0,    0]  *  [......]
...                   [0, 0, 1......0,    0]     [......]
[a_(n+1)  ]           [0..0..0......1,    0]     [a_n]

```

这样可以在==O(m^3logn)时间内解决这个问题。

如果上述的公式最后有个常数项的话，会稍微复杂一点，就是下面这样。




再增加一个维度即可。

```
[a_(n+m)  ]           [b_(m-1) ... b_1, b_0, c]     [a_(m+n-1)]
[a_(n+m-1)]           [1 ...........0,    0, 0]     [a_(m+n-2)]
...             *     [0, 1 ........0,    0, 0]  *  [......]
...                   [0, 0, 1......0,    0, 0]     [......]
[a_(n+1)  ]           [0..0..0......1,    0, 0]     [a_n]
[1]                   [0, 0, 0, ....0,    0, 1]     [1]
```

## 如果是求矩阵的和？


```
S_k = I + A + A^2 + A^3 + ... + A^(k-1)
```

那么可以转化成下面的这个矩阵

```
[A^k] = [A, 0] * [A^(k-1)]
[S_k]   [I, I]   [S_(k-1)]
```


## Pr

- POJ-3734-Blocks
- POJ-3233-Matrix_Power_Series
- POJ-3420-Quad_Tiling
- POJ-3735-Training_little_cats
