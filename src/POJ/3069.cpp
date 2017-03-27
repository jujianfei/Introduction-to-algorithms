// 14970769_AC_110MS_724K.cc
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
   int r,n;
   while(cin>>r>>n)
   {
    if(n==-1&&r==-1)break;
    vector<int> v;
    int lines=n;
    int tmp;
    while(lines--)
    {

        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());



       int i=0,ans=0;
       while(i<v.size())
       {
        int s=v[i++];
        while(i<v.size()&&v[i]<=s+r)i++;
        //cout<<"is "<<i<<endl;
        int p=v[i-1];
        while(i<v.size()&&v[i]<=p+r)i++;
        ans++;
       }
       cout<<ans<<endl;



   }
}
