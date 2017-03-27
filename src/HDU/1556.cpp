// 6506872_AC_1357ms_8260kB.cpp

#define N (100007) //The size of the array
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int l,r,val;
    int lazy; //若不需要区间更新，则可以去掉;pushdown函数，以及所有对其的调用，也一并去掉
}t[N<<2];

int n,m,x,y,z,type,a[N];

void pushdown(int i) //lazy标记传递函数
{
    t[i<<1].val+=t[i].lazy*(t[i<<1].r-t[i<<1].l+1);
    t[(i<<1)+1].val+=t[i].lazy*(t[(i<<1)+1].r-t[(i<<1)+1].l+1);
    t[i<<1].lazy+=t[i].lazy,t[(i<<1)+1].lazy+=t[i].lazy,t[i].lazy=0;
}

void build(int l,int r,int i) //建立线段树
{
    t[i].l=l;
    t[i].r=r;
    if(l==r)
        t[i].val=a[l];
    else
    {
        int mid=(l+r)>>1;
        build(l,mid,i<<1);
        build(mid+1,r,(i<<1)+1);
        t[i].val=t[i<<1].val+t[(i<<1)+1].val;
    }
}

void update(int x,int l,int r,int i,int val) //单点更新
{
    if(l==r)
        t[i].val=val;
    else
    {
        pushdown(i);
        int mid=(l+r)>>1;
        if(x<=mid)
            update(x,l,mid,i<<1,val);
        else
            update(x,mid+1,r,(i<<1)+1,val);
        t[i].val=t[i<<1].val+t[(i<<1)+1].val;
    }
}

void update(int tl,int tr,int l,int r,int i,int val) //区间更新
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
        int mid=(l+r)>>1;
        update(tl,tr,l,mid,i<<1,val),update(tl,tr,mid+1,r,(i<<1)+1,val);
        t[i].val=t[i<<1].val+t[(i<<1)+1].val;
    }
}

int query(int tl,int tr,int l,int r,int i) //区间查询
{
    if(tl<=l && r<=tr) return t[i].val;
    if(tl>r || tr<l) return 0;

    pushdown(i);
    int mid=(l+r)>>1;
    return query(tl,tr,l,mid,i<<1)+query(tl,tr,mid+1,r,(i<<1)+1);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    while(scanf("%d", &n) && n) {

        memset(t, 0, sizeof(t));
        memset(a, 0, sizeof(a));
        build(1,n,1);



        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            update(x,y,1,n,1,1);
        }

        for (int i=1;i<=n-1;i++) {
            cout<<query(i,i,1,n,1)<<" ";
        }cout << query(n,n,1,n,1) << endl;

    }

}
