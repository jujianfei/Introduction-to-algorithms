## 证明基于比较的排序算法的下界：

x: 节点的数字
```
n! <= x <= 2^h

==>> h >=O(nlgn)
```

## 计数排序

k代表数组中数字的最大值
```
def COUNTING-SORT(A, B, k):
let C[0..k] be a new array
for i=0 to k:
    C[i] = 0
for j=1 to A.length:
    C[A[j]] = C[A[j]] + 1
// C[i] 现在存放的是和i相同的数字的个数
for i=1 to k:
    C[i] = C[i] + C[i-1]
// 后后往前是为了保证排序的稳定性
for j=A.length down-to 1:
    B[C[A[j]]] = A[j]
    C[A[j]] = C[A[j]] - 1
```

算法复杂度 ==O(n + k)

当 k ==O(n)的时候，一般使用计数排序，时间复杂度是==O(n)。





