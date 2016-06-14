#include <bits/stdc++.h>
using namespace std;

string s="aacaagtttacaagc";
/**
*求最长重复的子字符串,使用后缀数组的方法.
*/
string common(const string&s,const string&t){
    auto p=0;
    while(p<s.size()&&p<t.size()){
        if(s[p]==t[p])p++;
        else return s.substr(0,p);
    }
    return s.substr(0,p);
}
string lcp(const string&s){
    int n=s.size();
    string *a=new string [n];
    for(int i=0;i<s.size();i++){
        a[i]=s.substr(i,n);
    }
    sort(a,a+n);
    string ans;
    for(int i=0;i<n-1;i++){
        auto tmp=common(a[i],a[i+1]);
        if(tmp.size()>ans.size()){
            ans=tmp;
        }
    }
    return ans;
}

int main(){
    cout<<lcp(s)<<endl;
}
