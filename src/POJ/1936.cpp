// 15157254_AC_63MS_904K.cc
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    string s,t;
    while(cin>>s>>t)
    {
        int former=-1;
        int flag=1;
        for(int i=0;i<s.size();i++)
        {
            int x=t.find(s[i],former+1);
            if(x>=t.size()){
                flag=0;break;
            }
            former=x;
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

}

