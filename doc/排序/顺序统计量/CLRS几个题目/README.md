
- Pro 9-3-6

O(klgn)时间内求出所有的K分位数。

![i](http://img.blog.csdn.net/20131231095736921?watermark/2/text/aHR0cDovL2Jsb2cuY3Nkbi5uZXQvbGloZW5haXI=/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70/gravity/SouthEast)

- Pro 9-3-7

设计O(n)的算法，在互异S集合内找最接近中位数的K个元素，

计算出中位数median，将所有数减去median,再取绝对值，用SELECT计算出第k小数字y，遍历数组，取出所有绝对值小于等于y的

- Pro 9-3-8

X[1..n]和Y[1..n]为两个数组，每个都包含n个有序的元素，设计一个O(lgN)时间的算法，找到数组X和Y中，所有2n个元素的中位数。

解：分治。

```
def two_array_median(a, b):
    if len(a) == 1:
        return min(a[0], b[0])

    m = median_index(len(a))
    i = m + 1
    if a[m] < b[m]:
        return two_array_median(a[-i:], b[:i])
    else:
        return two_array_median(a[:i], b[-i:])

def median_index(n):
    if n % 2:
        return n // 2
    else:
        return n // 2 - 1
```

- 拓展

给定一个数组，输出能够导致random-select最好的情况发生的一个划分序列。

```C++
int a[100] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
int n = 10;

void Creat_seq(int lo, int hi) {
    if (lo >= hi) return;
    sort(a+lo, a+hi-1);
    int mid = lo + (hi-lo)/2;
    swap(a[lo], a[mid]);
    Creat_seq(lo+1, mid);
    Creat_seq(mid+1, hi);
}

int main() {
    Creat_seq(0, 9);
    for (int i=0; i<10; i++) cout << a[i] << " "; cout << endl;
}
```