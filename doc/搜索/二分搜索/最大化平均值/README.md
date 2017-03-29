有 n 个物品的重量和价值分别是 wi 和 vi 。从中选出 k 个物品使得单位重量的价值最大
1<=k<=n<=10^4
1<=w[i],v[i]<=10^6

思路：二分
设最后选定物品的集合为S
```
用 sigma(i in S) V[i]   所有的价值和
用 sigma(i in S) W[i]  所有的质量和
ans = sigma(i in S) V[i] /  sigma(i in S) W[i]
```
根据化简得到：
```
sigma(v[i] - ans*w[i] ) >=0 那么我们就二分这个就行 
```

## Pr

- POJ-3111-丢弃珠宝
