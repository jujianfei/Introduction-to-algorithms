// 15157288_AC_360MS_1208K.cc
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#define N 50000+7
using namespace std;
int n,m;
int fa[N];
set<int> res;
int getroot(int x)       //查找x元素所在的集合,回溯时压缩路径
{
    if (x != fa[x])
    {
        fa[x] = getroot(fa[x]);     //回溯时的压缩路径
    }         //从x结点搜索到祖先结点所经过的结点都指向该祖先结点
    return fa[x];
}

bool q_m(int i,int j)
{
    int m=getroot(i);
    int n=getroot(j);
    if(m==n)
        return true;
    else
        return false;
}

void merger(int i,int j)
{
    fa[getroot(j)]=getroot(i);
}

void init()
{
    for(int i=0;i<N;i++){fa[i]=i;}
    res.clear();
}
int main()
{
    int cases=0;
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        cases++;
        init();
        int a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            if(q_m(a,b))
            {}
            else
            {
                merger(a,b);
            }
        }
        for(int i=1;i<=n;i++)
        {
            res.insert(getroot(i));
        }
        cout<<"Case "<<cases<<": "<<res.size()<<endl;

    }

}

