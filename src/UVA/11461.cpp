// 5699056_AC_0ms_0kB.cpp
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int a,b,i,j;
int is_sqrt(int n){
    int m=floor(sqrt(n)+0.5);
    if(m*m==n)return m;
    else return -1;
}

int main(){


    //freopen("D://in.txt","r",stdin);
    while(~scanf("%d%d",&a,&b)){
        if(a==0&&b==0)break;
        for(i=a;is_sqrt(i)==-1;i++);

        for(j=b;is_sqrt(j)==-1;j--);

        cout<<is_sqrt(j)-is_sqrt(i)+1<<endl;
    }
}
