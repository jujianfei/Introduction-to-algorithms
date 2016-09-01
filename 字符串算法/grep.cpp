
#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define N 100
int G[N][N];
//构建正则表达式的图

void construct_grep(string t){
    memset(G,0,sizeof(G));
    vector<int> stack;
    int M=t.size();
    for(int i=0;i<M;i++){
        int lp=i;//如果不是左括号的话，那么lp本身就是i

        if(t[i]=='('||t[i]=='|'){
            stack.push_back(i);

        }

        if(t[i]==')'){
            int Or=stack.back();
            stack.pop_back();
            if(t[Or]=='|'){
                lp=stack.back();
                stack.pop_back();
                G[lp][Or+1]=1;
                G[Or][i]=1;
            }else{
                lp=Or;//如果不是'|'的话，那么lp就是前前面的那个左括号
            }
        }

        //看下一个元素是不是*
        if(i<M-1 && t[i+1]=='*'){

            G[lp][i+1]=G[i+1][lp]=1;
        }
        //默认添加一条指向下个元素的一条边
        if(t[i]=='('||t[i]=='*'||t[i]==')'){
            G[i][i+1]=1;
        }
    }
}
bool visit[N];

void dfs(int i,int n){
    visit[i]=1;
    for(int j=0;j<n;j++){
        if(G[i][j]&&!visit[j]){
            dfs(j,n);
        }
    }
}

void dfs_begin(set<int>& s,int n){//最大是n，如果t的个数是x，那么是0-x，因此n=x+1
    memset(visit,0,sizeof(visit));
    for(auto &m:s){
        dfs(m,n);
    }
}

int grep_macth(string s,string t,int n){
    dfs(0,n);
    for(int i=0;i<=s.size();i++){
        set<int> next;

        for(int j=0;j<n;j++){
            if(visit[j]==1){
                if(j==n-1){
                   return true;
                }
                if(s[i]==t[j]){
                    next.insert(j+1);//作为下一次开始位置
                }
            }
        }
        dfs_begin(next,n);
    }
    return false;


}
void show(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<G[i][j]<<" ";
        }cout<<endl;
    }
}
int main(){
    string t="((A*B|AC)D)";
    construct_grep(t);
    show(t.size()+1);
    cout<<t<<endl;
    cout<<grep_macth("AABD",t,t.size()+1);
}
