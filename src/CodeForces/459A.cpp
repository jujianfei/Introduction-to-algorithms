#include<stdio.h>
#include<iostream>
#include<list>
#define N 107
using namespace std;
int n,a,b;
int now;
int main(){
    scanf("%d%d%d",&n,&a,&b);
    now=a;
    if(b>0){
        for(int i=0;i<b;i++){
            if(now==n){
                now=1;
            }else{
                now++;
            }
        }
    }else{
        b=-b;
        for(int i=0;i<b;i++){
            if(now==1){
                now=n;
            }else{
                now--;
            }
        }
    }
    cout<<now<<endl;
}
