// 15126379_AC_266MS_1096K.cc
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
#include<stdio.h>
#define N 50000+7
using namespace std;

int fa[N];
int re[N];
int getroot(int x)
{
    int tmp;
    if(fa[x]==x)return x;
    else
    {
        tmp=fa[x];
        fa[x]=getroot(fa[x]);
        re[x]=(re[x]+re[tmp])%3;
        return fa[x];
    }
}
void merger(int x,int y,int d)
{
    int rx=getroot(x);
    int ry=getroot(y);
    fa[ry]=rx;
    re[ry]=(re[x]-re[y]+d+3)%3;
}

int main()
{
    //freopen("/home/zlq/Qtacming/in","r",stdin);
    for(int i=0;i<N;i++)
    {
        fa[i]=i;
        re[i]=0;
    }
    int n,lines;
    scanf("%d%d",&n,&lines);
    int x,y,d,num=0;
    while(lines--)
    {
        scanf("%d%d%d",&d,&x,&y);
        d--;
        if((d==1&&x==y)||x<1||x>n||y>n||y<1)
        {num++;}
        else
        {
            if(getroot(x)==getroot(y))
            {

                if(d == 1 && ((3 - re[x] + re[y]) % 3 != d))
                {
                    num++;
                    continue;
                }
                if(d == 0 && re[x] != re[y])
                           {
                               num++;
                               continue;
                           }
            }
            else
            {
                merger(x,y,d);
            }
        }
    }
    printf("%d\n",num);

}
