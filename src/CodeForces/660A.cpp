#include<stdio.h>
#include<iostream>
#include<list>
#define N 1007
using namespace std;
int n;
int a[N];
struct Node{
    int pos;
    int val;
};
Node res[N];
int gcd(int a,int b){
    int m=std::max(a,b);
    int n=std::min(a,b);
    if(m%n==0)return n;
    else return gcd(n,m%n);
}
bool is_co_prim(int a,int b){
    return gcd(a,b)==1;
}
int get(int a,int b){
    int m=std::min(a,b);
    int n=std::max(a,b);
    for(int i=m+1;;i++){
        if(i!=n&&gcd(a,i)==1&&gcd(b,i)==1){
            return i;
        }
    }
}
int main(){
    //freopen("in","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(int i=0;i<n-1;i++){
        if(is_co_prim(a[i],a[i+1])){
            ;
        }else{
            res[cnt].pos=i+1;
            res[cnt].val=1;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    int now=0;
    for(int i=0;i<cnt;i++){
        while(now!=res[i].pos){
            cout<<a[now]<<" ";
            now++;
        }
        cout<<res[i].val<<" ";
        now=res[i].pos;
    }
    while(now<n){
        cout<<a[now]<<" ";
        now++;
    }
}
