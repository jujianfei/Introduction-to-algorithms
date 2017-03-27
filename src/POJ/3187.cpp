// 15214312_AC_94MS_232K.cpp
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,sum;
int a[11];
int b[11];
bool ok(){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    for(int times=0;times<n-1;times++){
        for(int i=0;i<n-1-times;i++){
            b[i]+=b[i+1];
        }
    }

    return b[0]==sum;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    for(int i=0;i<11;i++){
        a[i]=i+1;
    }
    scanf("%d%d",&n,&sum);
    do{
        if(ok()){
            break;
        }
    }while(std::next_permutation(a,a+n));

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
