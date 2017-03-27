```
def BUBBLE-SORT(A):
for i = 1 to A.length-1:
    for j = A.length down-to i+1:
        if A[j] < A[j-1]:
            exchange(A[j], A[j-1])
```
优化，如果某次没有发生交换，那么直接退出。

冒泡排序交换元素的次数和逆序数的对数是相同的。