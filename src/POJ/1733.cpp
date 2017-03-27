// 15127319_AC_141MS_1248K.cc
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
#include<stdio.h>
#define N 40000
using namespace std;
map<int,int> tr;
int fa[N];
int re[N];
int cnt=0;

int getroot(int x)
{
    int tmp;
    if(fa[x]==x)return x;
    else
    {
        tmp=fa[x];
        fa[x]=getroot(fa[x]);
        re[x]=(re[x]+re[tmp])%2;
        return fa[x];
    }
}
void merger(int x,int y,int d)
{
    int rx=getroot(x);
    int ry=getroot(y);
    fa[ry]=rx;
    re[ry]=(re[x]-re[y]+d+2)%2;
}

int main()
{
    //freopen("/home/zlq/Qtacming/in","r",stdin);
    for(int i=0;i<N;i++){
        fa[i]=i;
        re[i]=0;
    }
    int n,lines;
    scanf("%d%d",&n,&lines);
    int a,b,d,flag=1,pos;
    char s[11];
    for(int now=1;now<=lines;now++)
    {
       scanf("%d%d%s",&a,&b,s);
       //printf("%d,%d,%s\n",a,b,s);
       if(s[0]=='e'){d=0;}else{d=1;}
       b++;
       if(tr.find(a)==tr.end()){tr[a]=cnt++;}
       if(tr.find(b)==tr.end()){tr[b]=cnt++;}
       int i=tr[a],j=tr[b];
       int m=getroot(i),n=getroot(j);

       if(flag==0)continue;

       if(m!=n)
       {
           merger(i,j,d);
       }
       else
       {
           if(re[i]!=(re[j]+d)%2)
           {
               pos=now-1;
               flag=0;
           }
       }
    }
    if(flag)printf("%d\n",lines);
    else printf("%d\n",pos);

}
