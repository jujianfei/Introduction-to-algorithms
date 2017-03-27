// 6717630_AC_2719ms_14020kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#define INF 0x3f3f3f3f
using namespace std;


#define N (100007) //The size of the array

struct Node
{
    long long l,r,val;
    long long lazy; //若不需要区间更新，则可以去掉;pushdown函数，以及所有对其的调用，也一并去掉
}t[N<<2];

long long n,m,x,y,z,type,a[N];
long long Q;
char typer;
long long b,e,v;


void pushdown(long long i) //lazy标记传递函数
{
    t[i<<1].val+=t[i].lazy*(t[i<<1].r-t[i<<1].l+1);
    t[(i<<1)+1].val+=t[i].lazy*(t[(i<<1)+1].r-t[(i<<1)+1].l+1);
    t[i<<1].lazy+=t[i].lazy,t[(i<<1)+1].lazy+=t[i].lazy,t[i].lazy=0;
}

void build(long long l,long long r,long long i) //建立线段树
{
    t[i].l=l;
    t[i].r=r;
    if(l==r)
        t[i].val=a[l];
    else
    {
        long long mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,(i<<1)+1);
        t[i].val=t[i<<1].val+t[(i<<1)+1].val;
    }
}

void update(long long tl,long long tr,long long l,long long r,long long i,long long val) //区间更新
{
    if(tl<=l && r<=tr)
    {
        t[i].val+=val*(t[i].r-t[i].l+1);
        t[i].lazy+=val;
    }
    else if(tl>r || tr<l)
        return;
    else
    {
        pushdown(i);
        long long mid=(l+r)>>1;
        update(tl,tr,l,mid,i<<1,val),update(tl,tr,mid+1,r,(i<<1)+1,val);
        t[i].val=t[i<<1].val+t[(i<<1)+1].val;
    }
}

long long query(long long tl,long long tr,long long l,long long r,long long i) //区间查询
{
    if(tl<=l && r<=tr) return t[i].val;
    if(tl>r || tr<l) return 0;

    pushdown(i);
    long long mid=(l+r)>>1;
    return query(tl,tr,l,mid,i<<1)+query(tl,tr,mid+1,r,(i<<1)+1);
}



int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%lld%lld", &n, &Q)) {
        memset(a, 0, sizeof(a));
        memset(t, 0, sizeof(t));
        for(long long i=1;i<=n;i++)
        scanf("%lld",a+i);
        build(1,n,1);
        for (long long i=0; i<Q; i++) {
            getchar();
            scanf("%c",&typer);
            if (typer == 'Q') {
                scanf("%lld%lld", &b, &e);
                cout << query(b,e,1,n,1) << endl;
            } else {
                scanf("%lld%lld%lld", &b, &e, &v);
                update(b,e,1,n,1,v);
            }
        }
    }

}


