- 随机排列数组方法

```
def permute-by-sorting(A):
    n = A.length
    let P[1..n] be a new array
    for i=1 to n:
        P[i] = Random(1, n^3)
    sort A using P as sort keys.
```

这里假设P是不同的，如果是相同的，那么重新生成即可。


- 就地随机排列

```
def random-inplace(A):
    n = A.length
    for i=1 to n:
        swap(A[i], A[random(i, n)])

```


- 礼券收集者问题

b个箱子的编号1-b，每次投球都是独立的，n个球。

需要投多少次球，才能让每个箱子至少有一个球。

```
bln(b)
```

一个人想收集b种礼券中的每一种，至少需要blnb张随机得到的礼券。

详细证明见CLRS-chapter05
