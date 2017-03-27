// 15186707_AC_110MS_828K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面

#include<vector>
#include<map>
#define AD 200000000
#define ML -200000000
#define INF 0xfffffff
using namespace std;
#define N 70
int n;
int max_dp[107][107];
int min_dp[107][107];

int dfs_min(int from,int to,const vector<int>&v);

int dfs_max(int from,int to,const vector<int> &v){
    if(max_dp[from][to]!=INF)return max_dp[from][to];
    if(from==to)return max_dp[from][to]=v[from];

    int maxer=ML;
    for(int i=from+1;i<to;i=i+2){//遍历每个符号

        if(v[i]==AD){
            int temp_res=0;
            temp_res+=dfs_max(from,i-1,v)+dfs_max(i+1,to,v);
            if(temp_res>maxer){
                maxer=temp_res;
            }
        }

        else if(v[i]==ML){
            int fx=dfs_max(from,i-1,v);
            int fn=dfs_min(from,i-1,v);
            int sx=dfs_max(i+1,to,v);
            int sn=dfs_min(i+1,to,v);

            int res=std::max(fx*sx,std::max(fx*sn,std::max(fn*sx,fn*sn)));
            if(res>maxer){
                maxer=res;
            }
        }
    }

    return max_dp[from][to]=maxer;

}
int dfs_min(int from,int to,const vector<int>&v){
    if(min_dp[from][to]!=INF)return min_dp[from][to];
    if(from==to)return min_dp[from][to]=v[from];

    int miner=AD;
    for(int i=from+1;i<to;i=i+2){//遍历每个符号

        if(v[i]==AD){
            int temp_res=0;
            temp_res+=dfs_min(from,i-1,v)+dfs_min(i+1,to,v);
            if(temp_res<miner){
                miner=temp_res;
            }
        }

        else if(v[i]==ML){
            int fx=dfs_max(from,i-1,v);
            int fn=dfs_min(from,i-1,v);
            int sx=dfs_max(i+1,to,v);
            int sn=dfs_min(i+1,to,v);

            int res=std::min(fx*sx,std::min(fx*sn,std::min(fn*sx,fn*sn)));
            if(res<miner){
                miner=res;
            }
        }
    }

    return min_dp[from][to]=miner;
}

int fx(const vector<int> &v){
    return dfs_max(0,v.size()-1,v);
}



void init(){
    for(int i=0;i<107;i++){
        for(int j=0;j<107;j++){
            max_dp[i][j]=min_dp[i][j]=INF;
        }
    }
}

vector<int> res;
int main(){
    //freopen("D://in.txt","r",stdin);
    cin>>n;
    char c;
    int t;
    vector<int> temp;
    init();

    for(int i=0;i<n;i++){
        cin>>c>>t;
        if(c=='t'){
            temp.push_back(AD);
        }else if(c=='x'){
            temp.push_back(ML);
        }
        temp.push_back(t);
    }
    //移除哪条边构造目标

    int miner=ML;
    for(int i=0;i<temp.size();i=i+2){
        vector<int> v;
        for(int k=i+1;k<temp.size();k++){
            if(temp[k]==ML){ v.push_back(ML); }
            else if(temp[k]==AD){ v.push_back(AD); }
            else v.push_back(temp[k]);
        }
        for(int k=0;k<i;k++){
            if(temp[k]==ML){ v.push_back(ML); }
            else if(temp[k]==AD){ v.push_back(AD); }
            else v.push_back(temp[k]);
        }

        //测试vector
        init();
        int tar=fx(v);


        if(tar>miner){
            res.clear();
            res.push_back((i+2)/2);
            miner=tar;
        }else if(tar==miner){
            res.push_back((i+2)/2);
        }
    }
    cout<<miner<<endl;
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }cout<<endl;


    return 0;
}
