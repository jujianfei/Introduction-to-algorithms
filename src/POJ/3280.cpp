// 15281123_AC_797MS_36412K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define N 3000+3
using namespace std;
int n,m;
char s[N];
char at(int i){//变成从1开始的索引
    if(s[i-1]>='a')return s[i-1];
    else return 'a';
}

int dp[N][N];
int del[28];
int add[28];

void Init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
}
int get(int i,int j){

    if(i==0||j==0) return 0;//应该不会出现这种情况
    if(dp[i][j]!=-1){return dp[i][j];}
    if(i==j) return dp[i][j]=0;
    if(at(i)==at(j)) return dp[i][j]=get(i+1,j-1);
    int second,first;
    second = std::min(get(i,j-1)+del[at(j)-'a'], get(i,j-1)+add[at(j)-'a']);
    first = std::min(get(i+1,j)+del[at(i)-'a'], get(i+1,j)+add[at(i)-'a']);
    return dp[i][j]=std::min(first,second);
}

int main(){

    Init();
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    scanf("%s",s);
    char c;
    int tmpa,tmpb;
    for(int i=0;i<m;i++){
        getchar();
        scanf("%c",&c);
        scanf("%d%d",&tmpa,&tmpb);

        add[c-'a']=tmpa;
        del[c-'a']=tmpb;
    }
    cout<<get(1,n)<<endl;
}
