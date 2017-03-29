## 优先队列

```Python
def HEAP-MAXIMUM(A):
    return A[1]
```

```Python
def HEAP-EXTRACT-MAX(A):
if A.heap-size < 1:
    ERROR
max = A[1]
A[1] = A[A.heap-size]
A.heap-size -= 1
MAX-HEAPFY(A, 1)
return max
```

```Python
def HEAP-INCREASE-KEY(A, i, key):
if key < A[i]:
    ERROR: must be bigger
A[i] = key
while i > 1 and A[parent(i)] < A[i]:
    exchange(A[i], A[parent(i)])
    i = parent(i)
```


```Python
def MAX-HEAP-INSERT(A, key):
A.heap-size = A.heap-size + 1
A[A.heap-size] = -oo
HEAP-INCRESE-KEY(A, A.heap-size, key)
````


```Python
def HEAP-DELETE(A, i):
if A[i] < A[A.heap-size]
    HEAP-INCREASE-KEY(A, i, A[A.heap-size])
    A.heap-size -= 1
else
    A[i] = A[A.heap-size]
    A.heap-size -= 1
    MAX-HEAPIFY(A,i)
```

[上述算法合理性的详细解释](https://github.com/gzc/CLRS/blob/master/C06-Heapsort/6.5.md)


如何使用优先队列实现队列和栈==只要相应的改变优先级即可。


## [索引优先队列实现](indexpriorityqueue.cpp)



## Pr

- POJ-3614-Sunscreen
- POJ-2010-Moo_University_Financial_Aid
