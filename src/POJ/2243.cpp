// 15130323_AC_63MS_740K.cc
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int a[9][9];
#include<deque>
#include<algorithm>
bool is_legal(int y,int x)
{
    if(x<1||x>8||y<1||y>8)return false;
    if(a[y][x]!=-1)return false;
    else return true;
}
int main()
{
//    ifstream fin("/home/zlq/acming3/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());
    string b,e;
    int fx,fy,gx,gy;
    while(cin>>b>>e)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                a[i][j]=-1;

        fx=b[0]-96;
        fy=b[1]-48;
        gx=e[0]-96;
        gy=e[1]-48;
        //cout<<"fx"<<fx<<" fy"<<fy<<" gx"<<gx<<" gy"<<gy<<endl;
        deque<pair<int,int> >d;
        d.push_back(make_pair(fy,fx));

        a[fy][fx]=0;
        while(d.empty()==false)
        {
            pair<int,int> fro=d.front();
            d.pop_front();
            //cout<<fro.first<<" "<<fro.second<<endl;
            if(fro.first==gy&&fro.second==gx){break;}
            else
            {
                int y=fro.first,x=fro.second;
                if(is_legal(y-2,x+1)){d.push_back(make_pair(y-2,x+1));a[y-2][x+1]=a[y][x]+1;}
                if(is_legal(y-1,x+2)){d.push_back(make_pair(y-1,x+2));a[y-1][x+2]=a[y][x]+1;}
                if(is_legal(y+1,x+2)){d.push_back(make_pair(y+1,x+2));a[y+1][x+2]=a[y][x]+1;}
                if(is_legal(y+2,x+1)){d.push_back(make_pair(y+2,x+1));a[y+2][x+1]=a[y][x]+1;}
                if(is_legal(y+2,x-1)){d.push_back(make_pair(y+2,x-1));a[y+2][x-1]=a[y][x]+1;}
                if(is_legal(y+1,x-2)){d.push_back(make_pair(y+1,x-2));a[y+1][x-2]=a[y][x]+1;}
                if(is_legal(y-1,x-2)){d.push_back(make_pair(y-1,x-2));a[y-1][x-2]=a[y][x]+1;}
                if(is_legal(y-2,x-1)){d.push_back(make_pair(y-2,x-1));a[y-2][x-1]=a[y][x]+1;}
            }

        }
        cout<<"To get from "<<b<<" to "<<e<<" takes "<<a[gy][gx]<<" knight moves."<<endl;

    }
}
