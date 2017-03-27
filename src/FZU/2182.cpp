// 5978839_AC_15ms_232kB.cpp
#include<stdio.h>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;
//string 转化成vector

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

int main(){
    //freopen("D://in.txt","r",stdin);
    string tmp;
    int cases;
    cin>>cases;
    getline(cin,tmp);
    while(cases--){
        getline(cin,tmp);
        vector<string> v=StringToVec<string>(tmp);
        if(v[0].size()>3){
            cout<<"Too hard!"<<endl;
        }else{
            cout<<"Too easy!"<<endl;
        }
    }
}
