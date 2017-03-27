// 6729500_AC_4125ms_1920kB.cpp
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
#define N (50007) //The size of the array
int segmax[N*4+10];
int seg[N*4+10];
int array[N];
int n,q;
//l,right是最大的区间,b,end是查询的区间
int querymax(int i,int b,int e,int l,int r){
    int p1,p2;
    if (l>e||r<b)return -1;
    if (b>=l&&e<= r)return segmax[i];
    p1=querymax(2*i,b,(b+e)/2,l,r);
    p2=querymax(2*i+1,(b+e)/2+1,e,l,r);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(p1>=p2)return p1;
    return p2;
}

void buildmax(int i,int b,int e){
    if(b==e)segmax[i]=array[b];
    else{
        buildmax(2*i,b,(b+e)/2);
        buildmax(2*i+1,(b+e)/2+1,e);
        if(segmax[2*i]>=segmax[2*i+1])
            segmax[i]=segmax[2*i];
        else
            segmax[i]=segmax[2*i+1];
    }
}

int query(int i,int b,int e,int l,int r)
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
void build(int i,int b,int e)
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


int main()
{
//    array[0]=1,array[1]=-2,array[2]=2,array[3]=4,array[4]=-10,array[5]=3;//这个数组建立之后就没有用了
//    buildmax(1,0,5);//从1节点开始构建数组从0到5的线段树
//    cout<<querymax(1,0,5,1,4)<<endl;//查询1-4上的最小值
//    Updata(1,0,5,4,2);//将4号索引的值加上2（可以变成更新数值）
//    cout<<querymax(1,0,5,1,4)<<endl;
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int i=0; i<n; i++) {
        scanf("%d", &array[i]);
    }
    buildmax(1,0,n);
    build(1,0,n);
    int b,e;
    for (int i=0; i<q; i++) {
        scanf("%d%d", &b, &e);
        int miner = query(1,0,n,b-1,e-1);
        int maxer = querymax(1,0,n,b-1,e-1);
        printf("%d\n", maxer - miner);
    }
}
