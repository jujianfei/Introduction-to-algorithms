#include<bits/stdc++.h>
using namespace std;
#define PRIME 100007
//为了方便这里假设是26个小写字母的
int hash_fun(string s){
    int n=s.size();
    int res=0;
    for(int i=0;i<n;i++){
        res=(res*26+s[i]-'a')%PRIME;
    }
    return res;
}
bool match(string s,string t){

    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i])return false;
    }
    return true;
}

int rabin_karp(string s,string t){
    int code=hash_fun(t);
    if(s.size()<t.size())return -1;
    for(int i=0;i<=s.size()-t.size();i++){

        if(hash_fun(string(s.begin()+i,s.begin()+i+t.size()))==code&&match(string(s.begin()+i,s.begin()+i+t.size()),t)){
            return i;
        }
    }
    return -1;
}

int main(){
        cout<<rabin_karp("zhang","ang");
}
