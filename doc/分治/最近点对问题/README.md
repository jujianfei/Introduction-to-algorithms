## 最近点对问题

首先按照x坐标将所有点分成两半，那么最近点对的距离就是下面两者的最小值
(1).点p和点q属于同一边时的距离
(2)点p和点q属于不同边时的距离
其中(1)可以递归计算，记(1)的最小值是d。我们考虑(2)。
假设将点划分成左右两半的直线为l，其x坐标为x0.我们只需要考虑到直线l的距离小于d的点即可。即考虑满足x0-d<x<x0+d的点。
接下来考虑y坐标。
对于每个点，只需要考虑那些y坐标不比自己大的点，另外也没必要考虑y坐标相差大于等于d的点。即对于y'坐标为yp的点，只需考虑yp-d<y<=yp的点即可。
综上，只需要考虑在x0-d<x<x0+d且yp-d<y<=yp的矩形区域内的点。实际上可以证明该矩形区域内的点很少。

为了实现按x坐标划分，我们先对x左边进行排序。另外，为了更高效的检查矩形区域内的点，将待考虑的点按y坐标排序。为此，在递归处理的时候，对y坐标进行归并排序。

时间复杂度为O(nlogn)。



```C++
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#include<cmath>
#include<bitset>
#include<sstream>
using namespace std;
#define INF 0x7fffffff
#define maxn 10005

typedef pair<double,double> P;//first保存x坐标，second保存y坐标

int N;
P A[maxn];

//用于按坐标归并排序的比较函数
bool compare_y(P a,P b)
{
    return a.second<b.second;
}

//传入的a已经按x坐标排好序了
double closest_pair(P *a,int n)
{
    if(n<=1){
        return INF;
    }
    int m=n/2;
    double x=a[m].first;
    double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
    inplace_merge(a,a+m,a+n,compare_y);//归并两个排好序的数列
    //此时a已经按照y排好序

    vector<P> b;//将到直线距离小于d的顶点加入
    for(int i=0;i<n;i++){
        if(fabs(a[i].first-x)>=d) continue;

        //从后往前检查b中y坐标相差小于d的点
        for(int j=0;j<b.size();j++){
            double dx=a[i].first-b[b.size()-j-1].first;
            double dy=a[i].second-b[b.size()-j-1].second;
            if(dy>=d) break;
            d=min(d,sqrt(dx*dx+dy*dy));
        }
        b.push_back(a[i]);
    }
    return d;
}

void solve()
{
    sort(A,A+N);//按照x坐标排序
    double d=closest_pair(A,N);
    if(d>=10000) printf("INFINITY\n");
    else{
        printf("%.4f\n",d);
    }
}
int main()
{

    while(cin>>N&&N){
        for(int i=0;i<N;i++){
            cin>>A[i].first>>A[i].second;
        }
        solve();
    }
    return 0;
}
```
