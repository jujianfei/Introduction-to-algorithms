## 桶排序


假设数据服从均匀分布，平均情况下它的时间代价为O(n)。

桶排序假设输入是一个随机过程产生的额，这个过程将数据独立均匀的分部在[0,1]区间上。

假设分为n组，需要一个临时数组，B[0..n-1]存放链表。
```Python
def BUCKET-SORT(A):
n = A.length
let B[0..n-1] be a new array
for i=0 to n-1:
    make B[i] an empty bucket
for i=1 to n:
    insert A[i] to list B[floor(A[i] * n)]
for i=0 to n-1:
    sort list B[i] with insertion sort(or merge sort)

concatenate the lists B[0], B[1] ... B[n-1] together in order.
```

- 分析

桶排序的期望运行时间是==O(n)

详细证明参考CLRS-chapter8

## 所有排序算法的稳定性分析

不稳定的：

选择排序，希尔排序，快速排序，三向快排，堆排序，桶排序。


改进：

为了让不稳定的算法变得稳定，可以给每个item都增加一个原始index属性，最后相同的元素根据index再排一次。需要O(n)的额外空间。
