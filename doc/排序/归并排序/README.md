## topdown的归并排序

```
def MERGE-SORT(A, p, r):
    if p < r:
        q = floor((p + r)/2)
        MERGE-SORT(A, p, q)
        MERGE-SORT(A, q+1, r)
        MERGE(A, p, q, r)
```

有哨兵的merge过程
```
def MERGE(A, p, q, r):
    n1 = q - p + 1
    n2 = r - q
    let L[1..n1+1], R[1..n2+1] be new arrays.
    for i=1 to n1:
        L[i] = A[p+i-1]
    for i=1 to n2:
        R[i] = A[q+j]
    L[n1+1] = +oo
    L[n2+1] = +oo
    i, j = 1, 1
    for k = p to r:
        if L[i] <= R[j]:
            A[k] = L[i]
            i = i + 1
        else:
            A[k] = R[j]
            j = j + 1
```

## bottomup的归并排序

- 自底向上的归并排序
  - 说明：最后一个子数组的大小只有是在n的偶数倍的时候才会等于n，否则会比n小
  - 以下算法使用的是闭区间
```C++
void merge(int lo, int mid, int hi) {
    // copy to aux[]
    for (int k = lo; k <= hi; k++) {
        aux[k] = a[k]; 
    }
    // merge back to a[]
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mid)              a[k] = aux[j++];  // this copying is unneccessary
        else if (j > hi)               a[k] = aux[i++];
        else if (aux[j] < aux[i])      a[k] = aux[j++];
        else                           a[k] = aux[i++];
    }
}
void sort() {
    for (int n = 1; n < N; n = n+n) {
        for (int i = 0; i < N-n; i += n+n) {
            int lo = i;
            int m  = i+n-1;
            int hi = min(i+n+n-1, N-1);
            merge(a, aux, lo, m, hi);
        }
    }
}

```


## 如何使用Merge-sort计算数组的逆序数的对数。

在每一步合并的过程中，对于右边的每个数字，统计左边比它大的数字的个数。


## 优化

类似快排，在数组小的时候尝试使用插入排序。

设小数组的大小是k。

在==O(k)时间内排序每个长度为k的n/k个子表。

在==O(nlg(n/k))的时间内合并这些表。

最坏的复杂度是==O(nk + nlg(n/k))。

如何合理的选择k？k = lgn
