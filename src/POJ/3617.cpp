// 15162547_AC_32MS_720K.cc
#include<iostream>
#include<deque>
#include<stdio.h>
using namespace std;
deque<char> d;
int get()
{
    int i=0,j=d.size()-1;
    int x=i,y=j;
    while(x!=y+1)
    {
        if(d[x]>d[y])return 1;
        else if(d[x]<d[y])return -1;
        else {
            x++;y--;
        }
    }
    return 0;
}
int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    int n;
    cin>>n;
    char tmp;
    while(n--)
    {
        cin>>tmp;
        d.push_back(tmp);
    }
    int  cnt=0;
    while(d.empty()==false)
    {
        if(cnt/80>0&&cnt%80==0){cout<<endl;}
        if(get()>0){
            cout<<d.back();
            d.pop_back();
        }
        else{
            cout<<d.front();
            d.pop_front();
        }
        cnt++;
    }

}
