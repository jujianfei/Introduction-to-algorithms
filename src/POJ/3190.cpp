// 15229783_AC_250MS_1880K.cc
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define N 50000+7
using namespace std;
struct Cow{
    int b,e,id;
};
bool compare(const Cow&n1,const Cow&n2){
    if(n1.b<n2.b)return true;
    else if(n1.b>n2.b) return false;
    else return n1.e<n2.e;
}

struct Stall{
    int e,id;
    Stall(int e,int id):e(e),id(id){}
    Stall(){}
};
bool operator <(const Stall& n1, const Stall&n2){
    return n1.e>n2.e;
}

int loc[N];
Cow a[N];
int n;
priority_queue<Stall> d;

void Init(){
    for(int i=0;i<N;i++){
        loc[i]=-1;
    }
}

int main(){
    Init();
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n ;i++){
        scanf("%d%d",&a[i].b,&a[i].e);
        a[i].e++;//转化成前闭后开的区间
        a[i].id=i+1;
    }
    sort(a,a+n,compare);
    int cnt=1;
    loc[a[0].id]=1;
    d.push(Stall(a[0].e,cnt++));

    for(int i=1;i<n;i++){
        Stall fro=d.top();
        if(a[i].b>=fro.e){//更新节点
            loc[a[i].id]=fro.id; //记录牛的位置
            d.pop();
            d.push(Stall(a[i].e,fro.id));
        }else{
            d.push(Stall(a[i].e,cnt));
            loc[a[i].id]=cnt;
            cnt++;
        }
    }
    cout<<--cnt<<endl;
    for(int i=1;i<=n;i++){
        cout<<loc[i]<<endl;
    }
}
