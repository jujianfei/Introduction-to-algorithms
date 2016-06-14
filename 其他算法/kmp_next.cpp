#include <bits/stdc++.h>
using namespace std;
//构建next数组
vector<int> get_next(const string&s){
    vector<int> next(s.size());
    int i=0,j=-1;
    next[0]=-1;
    while(i<s.size()){
        if(j==-1||s[i]==s[j]){
            ++i,++j;
            next[i]=j;
        }else{
            j=next[j];//这一步很关键
        }
    }
    return next;
}

//使用next数组进行匹配

bool kmp(const string&s,const string&t){
    int i=-1,j=-1;
    if(s.size()<t.size())return false;
    vector<int> next=get_next(t);
    //注意size()是unsigned类型的，和int类型的比较的时候，会全部转化成无符号类型的。
    int sn=s.size(),tn=t.size();

    while(i<sn&&j<tn){
        if(j==-1||s[i]==t[j]){
            ++i,++j;
        }else{
            j=next[j];
        }
    }
    return j==t.size();
}

int main(){
    const string s="zhanglanqing";
    const string t="qinh";
    cout<<kmp(s,t)<<endl;
}
