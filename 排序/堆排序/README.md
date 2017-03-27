
## 堆

```
def MAX-HEAPFY(A, i):

l = LEFT(i)
r = RIGHT(i)
if l <= A.heap-size and A[l] > A[i]:
    largest = l
else:
    largest = i

if r <= A.heap-size and A[r] > A[largest]:
    largest = r

if largest != i:
    exchange(A[i], A[largest])
    MAX-HEAPFY(A, largest)

```

## 建堆

```
def BUILD-MAX-HEAP(A):
A.heap-size = A.length
for i = A.lenght/2 down to 1:
    MAX-HEAPFY(A, i)
```

## 堆排序


```
def HEAP-SORT(A):
for i = A.length down-to 2:
    exchange(A[1], A[i])
    A.heap-size = A.heap-size - 1
    MAX-HEAPFY(A, 1)
```

不管数组A是已经升序的还是已经降序的，都要花费O(nlgn)的时间。


练习：

- 实现最小堆，以及倒序排序
- 用迭代方式实现MAX-HEAPFY
