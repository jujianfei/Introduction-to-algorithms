// 6729120_AC_79ms_1496kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
#define N (20007) //The size of the array

long long n;
struct Node {
    long long val,pos;
    bool operator < (const Node &n) const { return val < n.val; }
};

Node a[N];
long long sum[N];

long long bit1[N],bit2[N];
void update1(long long x,long long val){
    for(;x<N;x+=x&-x)
        bit1[x]+=val;
}
long long query1(long long x) {
    long long res=0;
    for(;x;x-=x&-x)
        res+=bit1[x];
    return res;
}
void update2(long long x,long long val){
    for(;x<N;x+=x&-x)
        bit2[x]+=val;
}
long long query2(long long x) {
    long long res=0;
    for(;x;x-=x&-x)
        res+=bit2[x];
    return res;
}



int main() {
    //freopen("in.txt","r", stdin);
    scanf("%d", &n);
    for (long long i=1; i<=n; i++) {
        scanf("%d%d", &a[i].val, &a[i].pos);
    }
    sort(a+1, a+n+1);
    for (long long i=1; i<=n; i++) sum[i] = sum[i-1] + a[i].pos;
    long long ans = 0;
    for (long long i=1; i<=n; i++) {
        //统计比他位置小的个数
        long long aa = query1(a[i].pos);
        //统计比他小的位置的所有位置的和
        long long bb = query2(a[i].pos);

        long long dist1 = aa * a[i].pos - bb;
        long long dist2 = sum[i-1] - bb - (i-1-aa) * a[i].pos;
        long long adddist = dist1 + dist2;
        ans += a[i].val * adddist;

        //cout << "dist1 " << dist1 << " dist2 " << dist2 << " " << a[i].val << endl;



        //更新上述的两个树狀数组
        update1(a[i].pos, 1);
        update2(a[i].pos, a[i].pos);
    }
    cout << ans << endl;

}



