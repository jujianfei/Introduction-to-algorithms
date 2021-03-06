## 基数排序

这个算法是非常直观的，我们假设n个d位的元素，存放在数组A中，其中1是最低位，d是最高位。

```
def RADIX-SORT(A, d):

for i = 1 to d:
    use a stable sort to sort Array on digit i
```

假如内层的循环使用的是==O(n+k)的算法，那么总的复杂度就是，==O(d(n+k))

特别的当d是常数k ==O(n)的时候，基数排序有线性的复杂度，一般情况下需要灵活处理。

## 引理

考虑这样场景

b = 32 - 32位的数字

r = 8

d = 4

将一个数字分成4组，每组8位数字。

这样可以得算法复杂度。

```
==O((b/r)(n+2^r))
```

那么应该如何调整保证算法复杂度最低呢？

对于给定的b和n，问题是如何选择r？

```
if b < lg(n):
    if r < b:
        (n+2^r) <= O(n)
        选择 r==b 是最优的==O(n)
    else:
        显然不最优？
else: b > lg(n):
    选择 r==floor(lg(n))最优时间代价 ==O(bn/lg(n))

```

详细的证明见CLRS-chapter8


## 选择快排还是基数排序

基数排序每一轮的时间消耗更大

快排更好的利用缓存、内存

b == O(lg(n)) 而且我们选择 r == lg(n) 基数排序的时间复杂度是==O(n) ？

