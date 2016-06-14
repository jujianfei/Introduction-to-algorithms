#include <bits/stdc++.h>
using namespace std;
#define N 1007
int n=100;
default_random_engine e;
int a[N];
int next[N];
int f[10][2];//f[8].front & f[8].tail

void init(){
    for(int i=0;i<n;i++){//一共有n-1个数
        a[i]=e()%1000;
        next[i]=i+1;
    }
    next[n-1]=-1;
    memset(f,-1,sizeof(f));
}

void sort(){
    auto gx=[](const int &n, int n)->int {
        return (n/static_cast<int>(pow(10,n-1)))%10;
    };
    int begin=0;
    for(int i=1;i<=3;i++){//这里假设关键字的个数是3
        for(int j=begin;j!=-1;j=next[j]){
            if(f[gx(a[j],i)][0]==-1&&f[gx(a[j],i)][1]==-1){
                f[gx(a[j],i)][0]=f[gx(a[j],i)][1]=j;
            }else{
                next[j]=f[gx(a[j],i)][0];
                f[gx(a[j],i)][0]=j;
            }
        }
        begin=f[0][0];
        //TODO:FIXME
    }

}

void test(){

}
int main(){

}
