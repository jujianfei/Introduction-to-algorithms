// 6455639_AC_30ms_0kB.cpp
#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
const int maxn=10010;  
int sum[maxn]={0};  
//树根水平位置为P  
void build(int p){  
    int v;  
    scanf("%d",&v);  
    if(v==-1)return;  
    sum[p]+=v;  
    build(p-1);  
    build(p+1);  
}  
int init(){  
    int v;  
    scanf("%d",&v);  
    if(v==-1) return false;  
    memset(sum,0,sizeof(sum));  
    sum[5000]=v;  
    build(4999);  
    build(5001);  
    return true;  
}  
int main()  
{  
    int kase=0;  
    while(init()){  
        int p=0;  
        while(!sum[p]) p++;  
        printf("Case %d:\n%d",++kase,sum[p++]);  
        while(sum[p]) printf(" %d",sum[p++]);  
        printf("\n\n");  
    }  
return 0;  
}  