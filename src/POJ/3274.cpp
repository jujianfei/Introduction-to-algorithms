// 15159777_AC_1860MS_13260K.cc
#include<iostream>
using namespace std;
#include<stdio.h>
#define N 100000+7
#define prime 1000+7
#include<cmath>
int a[N][31];
int n,k,x,cnt=1,now_max=-1;
int hash[prime];
int next[N];
int abs_(int a,int b)
{
    if(a-b<0)return b-a;
    else return a-b;
}
void get()
{
    for(int i=0;i<k;i++)
    {
        if(x&(1<<i))
            a[cnt][i]=a[cnt-1][i]+1;
        else
            a[cnt][i]=a[cnt-1][i];
    }
}
void compare(int tar,int index)
{
    //cout<<"compare"<<tar<<" "<<index<<endl;
    for(int i=0;i<k-1;i++)
    {
        if(a[tar][i]-a[index][i]!=a[tar][i+1]-a[index][i+1])
            return;
    }
   // cout<<"get!"<<endl;
    if(abs_(tar,index)>now_max)
        now_max=abs_(tar,index);
}
int hashfunction(int index)
{
    int sum=0;
    for(int i=0;i<k-1;i++)
    {
        sum=sum+(a[index][i]-a[index][k-1])*(i+7);
    }
    return (sum & 0x7fffffff) % prime;
}

//能够hash到一块,但是不一定相同

void insert_hash(int x)
{

       int h=hashfunction(x);
       int u=hash[x];
       while(u!=-1)
       {
           u=next[u];
       }
       next[x]=hash[h];
       hash[h]=x;
}

int main()
{
    for(int i=0;i<N;i++)
    {
        next[i]=-1;
        if(i<prime)
            hash[i]=-1;
    }//初始化

    //freopen("/home/zlq/new_acming/in","r",stdin);
    scanf("%d%d",&n,&k);
    insert_hash(0);
    for(int now=1;now<=n;now++)
    {
        scanf("%d",&x);
        get();
        cnt++;
        insert_hash(now);
    }

    //遍历测试
    {

        for(int index=0;index<=n;index++)
        {
            //cout<<"chain...with..."<<index<<endl;
            int get=hashfunction(index);
            int u=hash[get];
            while(u!=-1)
            {
                compare(u,index);
                //cout<<u<<endl;
                u=next[u];
            }
        }
    }
    cout<<now_max<<endl;
}
