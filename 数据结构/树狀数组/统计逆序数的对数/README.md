
树狀数组可以方便的求前n项的和。

因此如果有n个数他们之间的关系总个数是（n）（n-1）/2 。

先求非逆序的个数，然后做差即可。

对于第i个数ai，前ai项的和，然后更新一下这个数+1即可。

```C++
int a[N],bit[N];
int n;
void update(int x,int val)
{
    for(;x<N;x+=x&-x)
        bit[x]+=val;
}

int query(int x)
{
    int res=0;
    for(;x;x-=x&-x)
        res+=bit[x];
    return res;
}
void solve(){
    int cnt=0;
    for(int i=0;i<n;i++){
        cnt+=query(a[i]+offset);
        update(a[i]+offset,1);
    }
    cout<<cnt<<endl;
}
```

细节：这里直接是用的是ai作为下标，如果ai很大，需要开很大的数组，因此这种方法并不是很好，如果有负数存在可以加一个offset偏移量让下标变为正数。