// 5039683_AC_15ms_1604kB.cpp
#include<iostream>
#include<vector>
using namespace std;
int d[201];
int f(vector<pair<int,int>>v)
{
    for(int i=0;i<201;i++)
    {d[i]=0;}
    //cout<<v.size()<<"****";
    for(int k=0;k<v.size();k++)
    {
        int a=min(v[k].first,v[k].second);
        int b=max(v[k].first,v[k].second);

        if(a%2==0)a=a/2;
            else a=(a+1)/2;
        if(b%2==0)b=b/2;
            else b=(b+1)/2;

        for(int i=a;i<=b;i++)
        {
            d[i]++;
        }

    }
    int maxer=-1;

     for(int i=1;i<201;i++)
        {
            if(d[i]>maxer)
            maxer=d[i];
        }
   return maxer*10;
}
int main()
{
    int cases;
    cin>>cases;

    while(cases--)
    {
        int test;
        cin>>test;

        vector<pair<int,int> >info;
        int t1,t2;
        while(test--)
        {

            cin>>t1>>t2;

            info.push_back(make_pair(t1,t2));

        }
        cout<<f(info)<<endl;

    }
}
