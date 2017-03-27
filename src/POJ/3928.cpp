// 15165799_AC_219MS_1496K.cc
//这里默认的能力值是没有相同的,因为是排名
#define N 20000
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
//数据离散化将1-100000的数据压缩到1-20000,并且保证没有重复的数据产生

int rank[N+2];
int tag[N*5+10];
int n;

int bit1[N+2];//前面扫描
int bit2[N+2];//后边扫描

int fs[N+2];//存放前面小的数
int lb[N+2];//存放后面小的数

void update1(int x,int val){
    for(;x<N;x+=x&-x)
        bit1[x]+=val;
}
int query1(int x){
    int res=0;
    for(;x;x-=x&-x)
        res+=bit1[x];
    return res;
}

void update2(int x,int val){
    for(;x<N;x+=x&-x)
        bit2[x]+=val;
}
int query2(int x){
    int res=0;
    for(;x;x-=x&-x)
        res+=bit2[x];
    return res;
}

//*********************************
void f()//数据离散化
{
    int cnt=1;
    for(int i=1;i<=5*N;i++){
        if(tag[i]!=0){
            rank[tag[i]]=cnt++;
        }
    }
}
void init(){
    memset(fs,0,(N+2)*sizeof(int));
    memset(lb,0,(N+2)*sizeof(int));
    memset(bit1,0,(N+2)*sizeof(int));
    memset(bit2,0,(N+2)*sizeof(int));
    memset(rank,0,(N+2)*sizeof(int));
    memset(tag,0,(N*5+10)*sizeof(int));

}
int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            scanf("%d",&rank[i]);
            tag[rank[i]]=i;//建立相对的映射
        }
        f();

        //统计两遍树状数组即可
        for(int i=1;i<=n;i++){
            update1(rank[i]+1,1);
            fs[i]=query1(rank[i]);//前面比我小的数!

        }
        for(int i=n;i>=1;i--){
            update2(n-(rank[i]-1),1);
            lb[i]=query2(n-rank[i]);//后边比我大的数!

        }

        //测试
//        for(int i=1;i<=n;i++)
//        {
//            cout<<fs[i]<<" ";
//        }cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            cout<<lb[i]<<" ";
//        }cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            cout<<rank[i]-1-fs[i]<<" ";
//        }cout<<endl;
//        for(int i=1;i<=n;i++)
//        {
//            cout<<n-rank[i]-lb[i]<<" ";
//        }cout<<endl;
        long long res=0;
        for(int i=1;i<=n;i++){
            res+=(fs[i]*lb[i]+(rank[i]-1-fs[i])*(n-rank[i]-lb[i]));
        }
        cout<<res<<endl;
    }

}
