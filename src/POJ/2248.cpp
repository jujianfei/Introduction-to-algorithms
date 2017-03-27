// 15150181_AC_32MS_708K.cc
#include <cstdio>
#include <iostream>
using namespace std;
int n,page, ans, a[101], r[101], d[202];
void dfs(int);
void print();
void init();

int main()
{
     //freopen("/home/zlq/Desktop/in","r",stdin);
     while(scanf("%d", &n) && n)
     {
        init();
        page=0;
        dfs(0);
        print();
     }
        return 0;
}
void init()
{
     int i;
     ans = n;
     a[0] = 1;
     for(i = n; i <= n + n; i ++)
         d[i] = 0;
     for(i = n - 1; i > 0; i --)
         d[i] = d[i + i] + 1;          //d[i]中存放到给定数字的最短的距离数
}

void print()
{
     int i;
     for(i = 0; i < ans; i ++)
     {
        printf("%d ", r[i]);
     }
     printf("%d\n", n);
}
void dfs(int l)
{
     int i, k;
     if(l + d[a[l]] >= ans)
     {
         //cout<<"al is "<<a[l]<<" and d[al] "<<d[a[l]]<<endl;
         return;
     }
     if(a[l] == n)
     {
        ans = l;
        for(i = 0; i < l; i ++)
        {
            r[i] = a[i];
        }
        return;
     }
     for(i = l; i >= 0; i --)           //此两层循环即为循环所有算符，以找到新的状态
     {
        for(k = i; k >= 0; k --)
        {
            a[l + 1] = a[i] + a[k];   //后一个数由前两个个值之和得到
            if(a[l + 1] > a[l] && a[l + 1] <= n)   //排除不符合的情况
            {
                //cout<<"dfs..."<<l+1<<" "<<a[l+1]<<endl;
                dfs(l + 1);
            }
        }
     }
}
