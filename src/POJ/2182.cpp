// 15127866_AC_94MS_800K.cc
#include<iostream>
#include<fstream>
#include<set>
#include<map>
#include<stdio.h>
#include<vector>
#define N 8000
using namespace std;
int bit[N];
int a[N];
int res[N];
//树状数组的应用,bit用于保存树状数组的信息
void update(int x,int val)
{
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}
//查询前x项的和
int query(int x)
{
    int res=0;
    for(;x>0;x-=x&-x)
        res+=bit[x];
    return res;
}

int function_(int index)
{
    return index-query(index);
}

int binary_find_rank(int rank,int l,int r)
{
    //cout<<"finding rank.."<<rank<<endl;
    int mid,mid_res;
    while(l<r)
    {
        //注意这种解法,lower_bound找第一个符合题意的解
        mid=(l+r)/2;
        mid_res=function_(mid);

        if(mid_res<rank)
        {
           l=mid+1;
        }
        else
        {
            r=mid;
        }

    }
    return l;
}

int main()
{
    //freopen("/home/zlq/Qtacming/in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d",a+i);
    }

    for(int i=n-1;i>=0;i--)
    {
        int rank=a[i]+1;
        int x=binary_find_rank(rank,1,n+1);
        //cout<<"find.."<<x<<endl;
        update(x,1);
        res[i]=x;
    }

    for(int i=0;i<n;i++)
    {
        printf("%d\n",res[i]);
    }


}
