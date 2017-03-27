// 15157222_AC_79MS_816K.cc
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
string a[10];
int n;
bool can_find(const string& sub)
{
    for(int i=1;i<n;i++)
    {
        if(a[i].find(sub)<=59&&a[i].find(sub)>=0)
            continue;
        else
            return false;
    }
    return true;
}
bool compare(const string&s1,const string&s2)
{
    if(s1.size()>s2.size())return true;
    else if(s1.size()<s2.size())return false;
    else return s1<s2;
}
vector<string> res;
int main()
{
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    int cases;
    cin>>cases;
    while(cases--)
    {
        //cout<<"-------------------------"<<endl;
        cin>>n;
        //cout<<"n_is_"<<n<<endl;
        res.clear();
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        //开始暴力寻找
        string &s=a[0];
        for(int lenth=60;lenth>=3;lenth--)
        {
           for(int b=0;b<=60-lenth;b++)
           {
               if(can_find(string(s.begin()+b,s.begin()+b+lenth)))
               {
                   res.push_back(string(s.begin()+b,s.begin()+b+lenth));
               }
           }
        }
        if(res.size()==0)
        {
            cout<<"no significant commonalities"<<endl;
        }
        else
        {
            sort(res.begin(),res.end(),compare);
            cout<<res[0]<<endl;
        }
    }
}

