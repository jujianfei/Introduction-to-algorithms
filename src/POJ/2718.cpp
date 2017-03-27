// 15214715_AC_360MS_764K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<sstream>
using namespace std;
#define INF 0xffffff
int a[12];
int visit[12];
int n;
int ans=INF;
int first[12];
int second[12];
int first_cnt=0;
int second_cnt=0;
int whole_cnt=0;

template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while(sout >> tmp){
        res.push_back(tmp);
    }
    return res;
}

void Update(){

    int first_sum=first[0];
    int second_sum=second[0];
    for(int i=1;i<first_cnt;i++){
        first_sum=first_sum*10+first[i];
    }
    for(int i=1;i<second_cnt;i++){
        second_sum=second_sum*10+second[i];
    }
    ans = std::min(ans,abs(first_sum-second_sum));
}


void fun(){
    first_cnt=0;
    second_cnt=0;
    for(int i=0;i<n;i++){
        if(visit[i]){
            first[first_cnt++]=a[i];
        }else{
            second[second_cnt++]=a[i];
        }
    }
    do{
        if(first[0]==0&&first_cnt>1)continue;
        do{
            if(second[0]==0&&second_cnt>1)continue;
            Update();
        }while(next_permutation(second,second+second_cnt));
    }while(next_permutation(first,first+first_cnt));
}


void dfs(int cur,int now_size){
    if(now_size==n/2) {fun();return; }
    if(cur==n) return;
    visit[cur]=1;
    dfs(cur+1,now_size+1);//选择了当前的这一个
    visit[cur]=0;//清除标志
    dfs(cur+1,now_size);
}

void Init(){
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    ans=INF;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    string temp;
    vector<int> t;
    getline(cin,temp);
    while(cases--){
        getline(cin,temp);
        t=StringToVec<int>(temp);
        n=t.size();
        for(int i=0;i<n;i++){
            a[i]=t[i];
        }
        Init();
        dfs(0,0);

        cout<<ans<<endl;
    }

}
