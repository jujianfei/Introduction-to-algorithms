#include <bits/stdc++.h>
using namespace std;
#define N 31

string a[N];

int hashfun(string s){
    int res=0;
    for(int i=0;i<s.size();i++) res+=s[i];
    return res%N;
}

void put(string s){
    int i=hashfun(s);
    for(;a[i]!="";i=(i+1)%N){
        if(a[i]==s)return;
    }
    a[i]=s;
    return;
}
void deleter(string s){
    int i=hashfun(s);
    while(a[i]!=s){
        i=(i+1)%N;
    }
    a[i]="";

    //将右边的元素重新放置

    i=(i+1)%N;
    while(a[i]!=""){
        auto tmp=a[i];
        a[i]="";
        put(tmp);//重新放置的元素一定不会出现在当前i指针的后面
        i=(i+1)%N;
    }
}

int main(){
}
