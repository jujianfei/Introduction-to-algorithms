#include<bits/stdc++.h>
using namespace std;
int kmp(string s,string t){
    const int n=t.size();
    int dfa[256][n+1];
    memset(dfa,0,sizeof(dfa));
    dfa[t[0]][0]=1;//设置开始成功状态
    int X=0;//和下一个元素的重启状态
    for(int j=1;j<n;j++){
        for(int i=0;i<256;i++){
            dfa[i][j]=dfa[X][j];//复制上一个重启状态的情况
        }
        dfa[t[j]][j]=j+1;//设置成功的时候的重启状态
        X=dfa[t[j]][X];//设置下一列的重启状态
    }
    //使用dfa
    int next=0;//初始的状态是0
    int i;
    for(i=0;i<s.size();i++){
        if(next==t.size()){
            break;
        }else{
            next=dfa[s[i]][next];
        }
    }
    if(next==t.size())return i-t.size();
    else return -1;
}

int main(){
    string s="zhanglan";
    string t="gla";
    cout<<kmp(s,t)<<endl;
}
