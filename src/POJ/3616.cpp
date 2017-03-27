// 15261203_AC_16MS_740K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 1000+7
using namespace std;
struct Node{
    int b,e,w;
    Node(int b,int e,int w):b(b),e(e),w(w){}
    Node(){}
};
Node a[N];
int dp[N];
int n,m,r;
bool compare(const Node&n1,const Node&n2){
    return n1.e<n2.e;
}
int f(int x){//得到一个最近的不相交的区间
    for(int i=x-1;i>0;i--){
        if(a[i].e+r<=a[x].b){
            return i;
        }
    }
    return 0;//与所有区间都相交
}


const int M = 1000000000;
int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d%d",&m,&n,&r);
    for(int i=1;i<=n;i++){//下标从一开始
        scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].w);
    }
    std::sort(a+1,a+n+1,compare);

    dp[0]=0;
    for(int i=1;i<=n;i++){
        int index=f(i);

        if(f(i)==i-1){
            dp[i]=dp[i-1]+a[i].w;
        }else{
            dp[i]=std::max(dp[index]+a[i].w,dp[i-1]);
        }
    }
    cout<<dp[n]<<endl;
}
