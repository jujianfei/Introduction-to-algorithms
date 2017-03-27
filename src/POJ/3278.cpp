// 15130359_AC_63MS_4752K.cc
#include<iostream>
#include<deque>
using namespace std;
#define N 1000000+10
int b,e;
int a[N];
deque<int> d;
bool is_legal(int i)
{
    if(i>100000||i<0)
        return false;
    else if(a[i]!=-1)
        return false;
    else
        return true;
}

int main()
{
    while(cin>>b>>e)
    {
        for(int i=0;i<N;i++){a[i]=-1;}
        d.clear();
        a[b]=0;
        d.push_back(b);
        while(d.empty()==false)
        {
            int tmp=d.front();
            d.pop_front();
            if(tmp==e){break;}
            else
            {
                if(is_legal(tmp+1)){d.push_back(tmp+1);a[tmp+1]=a[tmp]+1;}
                if(is_legal(tmp-1)){d.push_back(tmp-1);a[tmp-1]=a[tmp]+1;}
                if(is_legal(2*tmp)){d.push_back(2*tmp);a[2*tmp]=a[tmp]+1;}
            }
        }
        cout<<a[e]<<endl;
    }
}
