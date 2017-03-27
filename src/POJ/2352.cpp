// 14965066_AC_422MS_864K.cc
/*
POJ 2352 Stars
就是求每个小星星左小角的星星的个数。坐标按照Y升序，Y相同X升序的顺序给出
由于y轴已经排好序，可以按照x坐标建立一维树状数组
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int MAXN=15010;
const int MAXX=32010;
int c[MAXX];//树状数组的c数组
int cnt[MAXN];//统计结果
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=MAXX)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int x,y;
    while(scanf("%d",&n)!=EOF)
    {
        memset(c,0,sizeof(c));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            //加入x+1，是为了避免0，X是可能为0的
            int temp=sum(x+1);
            cnt[temp]++;
            add(x+1,1);

        }
        for(int i=0;i<n;i++)
         printf("%d\n",cnt[i]);
    }
    return 0;
}