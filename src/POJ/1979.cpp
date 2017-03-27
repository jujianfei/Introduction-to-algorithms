// 15205248_AC_63MS_736K.cc
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
vector<string> a;
int W,H;
int bx,by;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void Show(){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
}
void FindBegin(){
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(a[i][j]=='@'){
                bx=i,by=j;
            }
        }
    }
}

//访问过的置为*
void dfs(int x,int y){
    if(x<0||x>=H||y<0||y>=W||a[x][y]=='*'||a[x][y]=='#') return;
    a[x][y]='*';
    for(int k=0;k<4;++k){
        dfs(x+dx[k],y+dy[k]);
    }
}
int Count(){
    int res=0;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(a[i][j]=='*'){
                ++res;
            }
        }
    }
    return res;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    while(scanf("%d%d",&W,&H)){
        if(W==0&&H==0)break;
        a.clear();
        string tmp;
        for(int now=0;now<H;now++){
            cin>>tmp;
            a.push_back(tmp);
        }
        FindBegin();
        dfs(bx,by);
        cout<<Count()<<endl;
    }
}
