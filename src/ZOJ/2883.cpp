// 5042341_AC_80ms_528kB.cpp
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int nums;
        cin>>nums;
          vector<int>v;
            int tmp;
        while(nums--)
        {
          cin>>tmp;
          v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        const int k=v.size();
        int total=0;
        int i=k;
        while(i-3>=0)
        {
            total=total+v[i-3];
            i=i-3;
        }
        cout<<total<<endl;
    }
}
