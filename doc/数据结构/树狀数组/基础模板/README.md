## 树狀数组模板

树状数组是线段树的一种优化，动态的更新某个数值，查询某个段的和，并且每次操作都是==O(lg(n))数量级。


问题描述： 
给定一个长度为N的数组A，有M个操作，每个操作为以下两种类型之一：
（1）将A[i]的值增加x
（2）查询A[l],A[l+1],A[l+2]…A[r]的和
输入： 
第一行输入长度N和M； 
第二行输入N个数代表数组A 
接下来M行，代表操作：1 x y 代表把a[x]的值改为y;2 x y代表查询a[x],a[x+1]...a[y]的和 
输出： 
对于每一个操作2,输出答案 
样例输入: 
7 5 
2 3 6 4 7 1 5 
2 1 7 
1 5 2 
2 3 7 
2 1 7 
2 4 6 
样例输出： 
28 
25 
30 
14 
数据范围： 
1<=N<=10^5 
1<=M<=10^5 
注意：为了方便，这里的操作1改为增加X，而不是修改为X 
以下代码为用树状数组的解法。


```C++
#define N (1<<17) //The size of the array  
#include <bits/stdc++.h>  

using namespace std;  

int n,m,x,y,type,a[N],bit[N];  

void update(int x,int val)  
{  
    for(;x<N;x+=x&-x)  
        bit[x]+=val;  
}  

int query(int x)  
{  
    int res=0;  
    for(;x;x-=x&-x)  
        res+=bit[x];  
    return res;  
}  

int main()  
{  
    cin>>n>>m;  
    for(int i=1;i<=n;i++)  
        scanf("%d",a+i),update(i,a[i]);  

    for(int i=1;i<=m;i++)  
    {  
        scanf("%d%d%d",&type,&x,&y);  
        if(type==1)  
            update(x,y);  
        else  
            printf("%d\n",query(y)-query(x-1));  
    }  
}  
```

## Pr

- POJ-1990-MooFest
- POJ-3109-Inner_Vertices
- POJ-2155-Matrix
- POJ-2886-Who_Gets_the_Most_Candies?
