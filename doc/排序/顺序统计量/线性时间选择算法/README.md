## 最大值和最小值

实际上只需要最多 3 * floor(n/2)次就能找到最小值和最大值。

具体的方法：

传统的方法：每个元素都要和最大值和最小值比较。

改进：两个元素先进行一次比较，那么每两个元素都需要3次比较。


## 期望值为线性的选择算法


这个方法最坏是==O(n^2)的


```
def RANDOM-SELECT(A, p, r, i): // 在A[p..r]中找第i小的元素
    if p == r:
        return A[p]
    q = RANDOMIZED-PARTITATION(A, p, r)
    k = q - p + 1
    if i == k:
        return A[q]
    elif i < k:
        return RANDOM-SELECT(A, p, q-1, i)
    else:
        return RANDOM-SELECT(A, q+1, r, i-k)
```

一个迭代版本的C++实现

```C++
int Sel(int tar) {
    int b = 0, e = 9, k = tar;
    while (1) {
        int piv = partation(b, e);
        if (k == piv-b+1) return a[piv];
        else if(piv-b+1 > k) {
            e = piv - 1;
        } else {
            int tmpb = b;
            b = piv + 1;
            k = k-(piv-tmpb+1);
        }
    }
}
```


关于复杂度的详细证明参考CLRS-chapter9





## 最坏情况是线性时间的选择算法

输入：一系列数a[0]...a[n-1]和一个整数K
输出：这列数中第k小的数

同样的问题在用快速排序模型，我们得到的平均时间复杂度是O(n),但是遗憾的是最坏情况会达到O(n^2)。我们还是使用快速排序的模型，但是改变了划分的方式，这个算法会保准得到一个很好的划分。将该算法叫做Select,具体如下：

```
     1.将输入数组划分为n/5组，每组有5个元素，且剩下的至多有一组的元素小于5个。
     2.寻找这n/5个组中每个组的中位数，可以将每组做一次排序，然后选取每组的第三个元素。
     3.对于第2部找出的n/5个中位数递归的调用Select函数求出其中位数x.（约定偶数个中位数为其较小的中位数）
     4.按照找到的中位数x将数组划分为两个部分，求得小于或者等于x的元素有q个
     5.如果k==q则返回x,若k<q则在x的左区间找第k小的数，否则在x的有区间找第k-q大的数
```

```C++
#include<iostream>
#include<algorithm>
using namespace std;
int Select(int a[], int n,int k);
int main(){
    /*测试*/
    int a[10] = { 8, 4,0, -89, -12, 0, 36, 789, 21, 54 };
    cout << Select(a, 10,5) << endl;
    return 0;
}
int Partition(int a[],int low,int high, int x){  //这里数组a是[low,high)的，注意右边界最多到a[high-1]，
    /*利用x将数组划分为2部分*/
    int i = low;
    high--;
    while (a[i]!= x) i++;
    swap(a[low], a[i]);  //将基准移到首位置
    while (low < high){
        while (low < high&&a[high] >= x) high--;
        a[low] = a[high];
        while (low < high&&a[low] <= x) low++;
        a[high] = a[low];
    }
    a[low] = x;
    return low; 
}
int S_sort(int a[],int low,int high, int k){
    int i, j,x,q,n;
    n = high - low;                                //n为数组a[low...high]元素个数,注意右边最多取到a[high-1]
    if (n < 5){      //元素小于5时候单独处理
        sort(a + low, a + high);
        return a[low +k-1];
    }
    for (i = 0; i <n/ 5; i++){
        sort(a + low+i * 5, a + low+i * 5 + 5);   //对每组数据排序
        swap(a[low+i], a[low+i * 5 + 2]);        //中位数移到前面
    }
    x = S_sort(a, low,low+n/5, n/10+1);          //寻找中位数的中位数、n/10+1非常重要，避免n<10时n/10==0此时会出现问题
    j = Partition(a, low, high, x);             //根据x将数组a划分为2部分，j为x所在数组下标
    q = j - low + 1;                           // q为小于或者等于x元素的个数
    if (q == k)
        return x;
    else if (q>k)
        return S_sort(a, low, j + 1, k);
    else
        return S_sort(a, j + 1, high, k - q);
}
int Select(int a[], int n, int k){
    return S_sort(a, 0, n, k);
}
```

由于每次划分至少有3n/10-6个元素大于x,3n/10-6个元素小于x，从而下次递归调用规模至多为7n/10+6,得到递归式：
T(n)<=T(n/5)+T(7n/10-+6)+O(n),T(1)=O(1).最后解得T(n)=O(n).于是得到了最坏情况为线性时间复杂度。


