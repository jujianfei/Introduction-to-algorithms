// 15288673_AC_94MS_788K.cc
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 5007
struct Node{
    int x,y;
};
int n,x,y;
Node a[N];
int dp[N];
void Init(){
    memset(a,0,sizeof(a));
    memset(dp,0,sizeof(dp));
}
bool compare(const Node& n1,const Node&n2){
    if(n1.x<n2.x)return true;
    else if(n1.x>n2.x)return false;
    else return n1.y<n2.y;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        Init();
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        sort(a,a+n,compare);

        for(int i=0;i<n;i++){
            int maxer=1;
            for(int j=0;j<i;j++){
                if(a[i].y<a[j].y){
                    maxer=std::max(maxer,dp[j]+1);
                }
            }
            dp[i]=maxer;
        }
        int Max=-1;
        for(int i=0;i<=n-1;i++){
            Max=std::max(Max,dp[i]);
        }
        cout<<Max<<endl;

    }
}
