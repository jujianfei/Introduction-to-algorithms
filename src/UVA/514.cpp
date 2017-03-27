// 4711606_AC_106ms_0kB.cpp
#include<iostream>
#include<vector>
using namespace std;
void f(vector<int> &vi,int n)
{
    vector<int> v;
    for(int maxer=n;maxer>=1;maxer--)
        v.push_back(maxer);
    vector<int> mid;
    int flag=0;
    for(auto&mem:vi)
    {
        flag=0;
        if(mid.empty()==false&&mem==mid.back()){mid.pop_back();continue;}
        while(v.back()!=mem&&v.empty()==false)
        {
            mid.push_back(v.back());
            v.pop_back();
        }
        if(v.empty()==true)
        {flag=1;break;}
        else
        {
            v.pop_back();
            continue;
        }

    }
    if(flag)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}
int main()
{
    int num;
    while(cin>>num)
    {
        if(num==0)break;

        while(1)
        {
            int flag=0;
            vector<int> vi;
            int n=num;
            while(n--)
            {
                int t;
                cin>>t;
                if(t==0&&vi.empty())
                {
                    flag=1;
                    break;
                }
                else
                    vi.push_back(t);
            }
            if(flag==1)break;
            f(vi,num);
        }
        cout<<endl;
    }
}
