// 6722594_AC_1500ms_5492kB.cpp
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
#define N (200007) //The size of the array
#define M 100000

int L[N];// 每个数的左边界
int R[N]; //每个数的右边界
int num[N] ;// 每个数的个数
int a[N];
int n,k;
int b,e;


int seg[N*4+10];
int q(int i,int b,int e,int l,int r)
{
    int p1,p2;
    if (l>e || r<b)return -1;
    if (b>=l && e<= r) return seg[i];
    p1=q(2*i,b,(b+e)/2,l,r);
    p2=q(2*i+1,(b+e)/2+1,e,l,r);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(p1>=p2)return p1;
    return  p2;
}

void build(int i,int b,int e)
{
    if(b==e) seg[i]=num[b];
    else{
        build(2*i,b,(b+e)/2);
        build(2*i+1,(b+e)/2+1,e);
        if(seg[2*i]>=seg[2*i+1])
            seg[i]=seg[2*i];
        else
            seg[i]=seg[2*i+1];
    }
}


int query(int b, int e) {
    int l = a[b], r =a[e]; //被查询的两边的数字。左边界和右边界可能相等
    //如果查询的两个数恰好相等
    if (l == r)
        return e - b + 1;
    else if (l+1==r) {
        int numa = R[l] - b;
        int numb = e - L[r] + 1;
        return max(numa, numb);
    } else {
        int numa = R[l] - b;
        int numb = e - L[r] + 1;
        int maxer = q(1, 0, N, l+1, r-1);
        return max(max(numa,numb), maxer);
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    while (scanf("%d", &n) && n) { scanf("%d", &k);
        //cout << "==cases==" << endl;
        memset(L,0, sizeof(L)),memset(R, 0, sizeof(R)), memset(num, 0, sizeof(num));
        int tmpx;
        int last = -INF;
        for (int i=0; i<n; i++) {
            scanf("%d", &tmpx);
            tmpx += M;
            a[i] = tmpx;
            if (tmpx != last) L[tmpx] = i, R[tmpx] = i+1;
            else R[tmpx]= i+1;
            last = tmpx;
        }
        for (int i=0; i<N; i++) { num[i] = R[i]- L[i]; }
        build(1,0,N);
        for (int i=0; i<k; i++) {
            scanf("%d%d", &b, &e);
            printf("%d\n", query(b-1, e-1));
        }
    }
}


