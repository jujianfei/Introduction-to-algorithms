// 5936605_AC_0ms_272kB.cpp
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define N 10
int a[N],b[N],n,m;
int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d%d",&m,&n);
        int sum_m=0,sum_n=0;
        for(int i=0;i<m;i++){
            scanf("%d",&a[i]);
            sum_m+=a[i];
        }
        for(int i=0;i<n;i++){
            scanf("%d",&b[i]);
            sum_n+=b[i];
        }
        if(sum_m>sum_n){
            cout<<"Calem"<<endl;
        }else if(sum_m<sum_n){
            cout<<"Serena"<<endl;
        }else{
            cout<<"Draw"<<endl;
        }
    }
}
