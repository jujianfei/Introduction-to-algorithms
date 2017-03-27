
#include<bits/stdc++.h>
using namespace std;
int boyer_moore(string s,string t){
    int rt[256];//出现在最右边的位置
    memset(rt,-1,sizeof(rt));
    for(int i=t.size()-1;i>=0;i--){
        if(rt[t[i]]==-1){
            rt[t[i]]=i;
        }
    }

    //进行匹配
    int i=0,j=0;
    int M=t.size();
    int N=s.size();
    int cbt=0;
    while(i<=N-M){
        int k;
        for(k=M-1;k>=0;){
            if(s[i+k]==t[j+k]){
                k--;
            }else{
                break;
            }
        }
        if(k==-1)return i;
        int index=rt[s[i+k]];
        i+=(k-index);
    }
    return -1;
}


int main(){
    string s="zhang";
    string t="hang";
    cout<<boyer_moore(s,t)<<endl;
}
