思想：

《挑战程序设计竞赛》中介绍的方法。

分桶法：把一排物品或者平面分成桶，每个桶分别维护自己内部的信息，已达到高效计算的目的。
设一共有n个数，每b个分到一个桶里，并对桶内元素进行排序。给定区间，求小于x的数的个数

对于完全包含在区间内的桶，直接二分查找满足条件的个数，每个桶处理需要O(logb)的时间。
剩余的不完全分布在其他桶的数，逐个查找，每个元素处理需要O(1)的时间。
可以看出，应该使桶的个数比桶内元素个数略少一些。

如果b=sqrt(n)，那么这就叫平方分割，查找过程时间复杂度为O(sqrt(n)logn)，如果b=sqrt(nlogn)，那么复杂度为O(sqrt(nlogn))，加上最外面的二分，整体时间复杂度为O(nlogn+m*(sqrt(n))*(logn)^1.5)。




给定一个数列a_1 ~ a_n，每个查询由三个数字组成，输出a_i ~ a_j 的升序排列中的第k个数字。

```C++
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 1e5+5, b = 1200;
int a[maxn], num[maxn];//[) num对于A排序之后的结果
vector<int>v[maxn/b]; // 每个同排序之后的结果
int main (void)
{
    int n, m;scanf("%d%d",&n,&m);
    //int b = floor(sqrt(n));
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        v[i/b].push_back(a[i]);
        num[i] = a[i];
    }
    sort(num, num + n);
    for(int i = 0; i <= n/b; i++)
        sort(v[i].begin(), v[i].end());
    int l, r, mid;
    int lo, ro, k, tl, tr;
    while(m--){
        // 求[tl, tr)区间的第k个数字
        scanf("%d%d%d",&tl,&tr,&k);
        int l = 0, r = n;
        while(l < r - 1){
            int c = 0;
            mid = l + (r - l)/2;
            lo = tl -1, ro = tr;
            // 区间两端多出来的部分
            while(lo<ro && lo%b != 0) if(a[lo++] < num[mid]) c++;
            while(lo<ro && ro%b != 0 )if(a[--ro] < num[mid]) c++;
            for(int i = lo/b; i < ro/b; i++)
                c +=lower_bound(v[i].begin(), v[i].end(), num[mid]) - v[i].begin();
            if(c <= k-1) l = mid;
            else r = mid;
        }
        printf("%d\n",num[l]);
    }
    return 0;
}
```