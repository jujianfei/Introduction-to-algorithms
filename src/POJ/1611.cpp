// 15127514_AC_32MS_964K.cc
#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=30000+7;

int fa[maxn];

int getroot(int x)       //查找x元素所在的集合,回溯时压缩路径
{
    if (x != fa[x])
    {
        fa[x] = getroot(fa[x]);     //回溯时的压缩路径
    }         //从x结点搜索到祖先结点所经过的结点都指向该祖先结点
    return fa[x];
}


void init()
{
    for(int i=0;i<maxn;i++)
    {
        fa[i]=i;
    }
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

int main()
{
    //freopen("/home/zlq/Qtacming/in","r",stdin);
    int n,lines;
    while(~scanf("%d%d",&n,&lines))
    {
        if(n==0&&lines==0){break;}
        init();
        while(lines--)
        {
            int num;
            scanf("%d",&num);
            int a;
            vector<int> v;
            while(num--)
            {
                scanf("%d",&a);
                v.push_back(a);
            }
            for(int i=0;i<v.size()-1;i++)
            {
                if(q_m(v[i],v[i+1])){}
                else
                {
                    merger(v[i],v[i+1]);
//                    cout<<"merger"<<v[i]<<" "<<v[i+1]<<endl
//                    <<fa[v[i]]<<" "<<fa[v[i+1]]<<endl;
                }
            }
        }

        //检查
        int target=getroot(0);
        int cnt=0;
        for(int i=0;i<maxn;i++)
        {
            if(getroot(i)==target){cnt++;}
        }
        printf("%d\n",cnt);
    }
}
