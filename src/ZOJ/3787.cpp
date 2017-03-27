// 5938357_AC_310ms_508kB.cpp
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
#define N 20000+7
int StringTo(const std::string s){
    return (s[0]-'0')*10+s[1]-'0';
}
struct Node{
    int val;
    int index;
};
bool cmp(const Node&n1,const Node&n2){
    return n1.val<n2.val;
}
Node a[N];
int ans[N];
int tran(const string&s){
    int res=0;
    res+=StringTo(string(s.end()-2,s.end()));
    res+=60*StringTo(string(s.end()-5,s.end()-3));
    res+=3600*StringTo(string(s.end()-8,s.end()-6));
    return res;
}

int main(){
    int cases;
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&cases);
    string tmp;
    while(cases--){

        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            cin>>tmp;
            a[i].val=tran(tmp);
            a[i].index=i+1;
        }
        sort(a,a+n,cmp);
        int cnt=0;
        ans[cnt++]=a[0].index;
        int last=a[0].val;
        for(int i=1;i<n;i++){
            if(a[i].val-last>=m){
                ans[cnt++]=a[i].index;
                last=a[i].val;
            }else{
                continue;
            }
        }
        cout<<cnt<<endl;
        sort(ans,ans+cnt);
        for(int i=0;i<cnt;i++){
            if(i==cnt-1){
                cout<<ans[i];
            }else
            cout<<ans[i]<<" ";
        }cout<<endl;

    }
}
