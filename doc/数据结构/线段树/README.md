
## Sum线段树

可以区间更新，可以修改某个数的值

问题描述： 
    给定一个长度为N的数组A，有M个操作，每个操作为以下两种类型之一： 
    （1）将A[i]的值修改为x 
    （2）查询A[l],A[l+1],A[l+2]…A[r]的和 
     
    输入： 
    第一行输入长度N和M； 
    第二行输入N个数代表数组A 
    接下来M行，代表操作：1 x y 代表把a[x]的值改为y;2 x y代表查询a[x],a[x+1]...a[y]的和 
     
    输出： 
    对于每一个操作2,输出答案 
     
    样例输入: 
    7 5 
    2 3 6 4 7 1 5 
    2 1 7 
    1 5 9 
    2 3 7 
    2 1 7 
    2 4 6 
     
    样例输出： 
    28 
    25 
    30 
    14 
     
    数据范围： 
    1<=N<=10^5 
    1<=M<=10^5 
     
    以下代码中为用线段树的解法。另外添加了与本问题无关的区间更新的函数。 
    代表的意义为，对区间中的每一个数，都加上一个值val。 
    仅为了能够覆盖所有线段树的常用操作的实现。 
    一些更不常有的操作，不在以下代码之列，诸位可自行百度。

```
#define N (1<<17) // The size of the array  
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
  
void update(int x,int l,int r,int i,int val) //单点更新,lri固定为1,n,1
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
  
void update(int tl,int tr,int l,int r,int i,int val) //区间更新,lri固定为1,n,1
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
    cin>>n>>m;  
    for(int i=1;i<=n;i++)  
        scanf("%d",a+i);  
    build(1,n,1);  
    for(int i=1;i<=m;i++)  
    {  
        scanf("%d%d%d",&type,&x,&y);  
        if(type==1)  
            update(x,1,n,1,y);  
        else if(type==2)  
            printf("%d\n",query(x,y,1,n,1));  
    }  
}
```


## RMQ也可以使用线段树实现



```
#include <iostream>
using namespace std;
#define N 256
int seg[N*4+10];
int array[N];
int query(int i,int b,int e,int l,int r) // i,b,e固定为1, 0, n-1
{
    int p1,p2;
    if (l>e||r<b)return -1;
    if (b>=l&&e<= r)return seg[i];
    p1=query(2*i,b,(b+e)/2,l,r);
    p2=query(2*i+1,(b+e)/2+1,e,l,r);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(p1<=p2)return p1;
    return  p2;
}

void build(int i,int b,int e)//i,b,e固定为1,0,n-1
{
    if(b==e)seg[i]=array[b];
    else{
        build(2*i,b,(b+e)/2);
        build(2*i+1,(b+e)/2+1,e);
        if(seg[2*i]<=seg[2*i+1])
            seg[i]=seg[2*i];
        else
            seg[i]=seg[2*i+1];
    }
}

void Updata(int i,int b,int e,int ind,int add)//i,b,e固定为1,0,n-1
{
    if(b==e){
        seg[i]+=add;
        return ;
    }
    int m=(b+e)>>1;
    if(ind<=m)Updata(i*2,b,m,ind,add);
    else Updata(i*2+1,m+1,e,ind,add);
    seg[i]=min(seg[i*2],seg[i*2+1]);
}


int main()
{
    // n = 6; array下标是从0开始的
    array[0]=1,array[1]=-2,array[2]=2,array[3]=4,array[4]=-10,array[5]=3;
    build(1,0,5);//从1节点开始构建数组从0到5的线段树
    cout<<query(1,0,5,1,4)<<endl;//查询1-4上的最小值
    Updata(1,0,5,4,2);//将4号索引的值加上2（可以变成更新数值）
    cout<<query(1,0,5,1,4)<<endl;
}
```

## 其他有偏序关系，如gcd大多也可以使用线段树维护。
