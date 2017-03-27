// 15122493_AC_750MS_196K.cpp
#include<iostream>
#include<fstream>
using namespace std;
#define N 2000+7
#include<stdio.h>
int sex[2000+7];
int fa[2000+7];
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
    for(int i=0;i<N;i++)
    {
        fa[i]=i;
        sex[i]=-1;
    }
}

int main()
{


    int cases;
    scanf("%d",&cases);
    for(int now=1;now<=cases;now++)
    {
        init();
        int n,lines;
        scanf("%d%d",&n,&lines);
        int a,b;
        int flag=0;
        while(lines--)
        {
            scanf("%d%d",&a,&b);
            if(!q_m(a,b))
            {
                if(sex[a]==-1)
                {
                    sex[a]=b;
                }
                else
                {
                    if(q_m(sex[a],b))
                    {}
                    else
                    {
                        merger(sex[a],b);
                    }
                }
                if(sex[b]==-1)
                {
                    sex[b]=a;
                }
                else
                {
                    if(q_m(sex[b],a))
                    {

                    }
                    else
                    {
                        merger(sex[b],a);
                    }
                }

            }
            else
            {
                flag=1;
            }


        }

        if(flag)
        {
             printf("Scenario #%d:\nSuspicious bugs found!\n\n",now);
        }
        else
              printf("Scenario #%d:\nNo suspicious bugs found!\n\n",now);
    }

}
