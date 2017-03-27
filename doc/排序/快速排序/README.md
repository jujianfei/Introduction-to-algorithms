## 快速排序

```Python
def QUICK-SORT(A, p, r):
if p < r:
    q = PARTITION(A, p, r)
    QUICK-SORT(A, p, q-1)
    QUICK-SORT(A, q+1, r)


def PARTITION(A, p, r):
x = A[r]
i = p - 1
for j = p to r-1:
    if A[j] <= x:
        i = i + 1
        exchange(A[i], A[j])
exchange(A[i+1], A[r])
return i + 1
```

- 维护的情况：

[p, i] -> target <= x
[i+1, j-1] -> target > x
[j, r-1] -> unknow
[r]      -> 就是pivote(x)


- 练习：

实现非递增顺序的快速排序。

- 分析

只要划分是常数比的，都会产生==O(lgn)深度的递归树，因此算法的复杂度是<=O(nlgn)

如果好的划分和坏的划分交替出现最后也是，<=O(nlgn)的复杂度

在数组比较小的时候可以改为插入排序，小于K的时候就进行插入排序，这一个排序的时间复杂度是 <=O(nk + nlg(n/k))

但是k值的选择是难以计算的，需要实验测量。


最坏运行时间 ==O(n^2)

期望运行时间 <=O(nlgn)

某种改进方法，从数组中随机选择三个数字，选择中间大小的数字作为piv。


最初的快排算法是HOARE提出的，实现如下。

```
def PARTITION(A, p, r):
x = A[p]
i = p - 1
j = r + 1
while True:
    repeat
        j = j - 1
    until A[j] <= x
    repeat
        i = i + 1
    until A[i] >= x
    if i < j:
        exchange(A[i], A[j])
    else:
        return j
```

## 三向切分的快速排序

当元素有很多重复的时候使用这个算法

![](http://algs4.cs.princeton.edu/23quicksort/images/partitioning3-overview.png)


```C++
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 10000
int a[maxn];

void exchange( int i,int j )
{
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}


void qsort3way ( int lo,int hi )
{
    if( lo>=hi ) return;  //单个元素或者没有元素的情况
    int lt=lo;
    int i=lo+1;  //第一个元素是切分元素，所以指针i可以从lo+1开始
    int gt=hi;
    int v=a[lo];
    while( i<=gt )
    {
        if( a[i]<v )  //小于切分元素的放在lt左边，因此指针lt和指针i整体右移
            exchange( lt++,i++ );  
        else if ( a[i]>v )  //大于切分元素的放在gt右边，因此指针gt需要左移
            exchange( i,gt-- );
        else
            i++;
    }
    //lt-gt的元素已经排定，只需对it左边和gt右边的元素进行递归求解
    qsort3way( lo,lt-1 );    
    qsort3way( gt+1,hi );
}


int main()
{
    int n;
    cin>>n;
    for( int i=0; i<n; i++  )
        cin>>a[i];
    qsort3way( 0,n-1 );
    for( int i=0; i<n; i++  )
        cout<<a[i];
    cout<<endl;
    return 0;
}
```

算法复杂度是 

[==O(n)] <= x <= [==O(nlgn)]


## 快速排序的空间复杂度是==O(lgN)，因为栈的深度的原因。

因此可以使用尾置递归优化。


```
def TAIL-QSORT(A, p, r):
    while p < r:
        q = PARTATION(A, p, r)
        TAIL-QSORT(A, p, q-1)
        p = q + 1

```

也有可能最坏的情况，也就是递归栈的深度是O(n)，为了避免这种情况，进行优化。

每次分割之后，选择range小的那边进行递归，range大的那边进行迭代。
