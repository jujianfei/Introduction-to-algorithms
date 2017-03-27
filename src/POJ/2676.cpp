// 15149632_AC_1391MS_760K.cc
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<fstream>

using namespace std;
int a[10][10];
int sum;
pair<int,int> be(int x)
{
    if(x>=1&&x<=3)return pair<int,int>(1,3);
    if(x>=4&&x<=6)return pair<int,int>(4,6);
    if(x>=7&&x<=9)return pair<int,int>(7,9);
}

pair<int,int> next_blank(int x,int y)
{
    for(int i=1;i<10;i++)
    {
        for(int j=1;j<10;j++)
        {
            if(((i==x&&j>y)||i>x)&&a[i][j]==0)
                return pair<int,int>(i,j);
        }
    }
    return pair<int,int>(0,0);
}

bool dfs(int depth,int x,int y)//在这里x,y是目前的位置
{
    //cout<<"now_depth "<<depth<<" in"<<x<<" "<<y<<endl;
    if(depth==sum+1)return true;

    bool have[10];
    memset(have,0,10*sizeof(bool));
    //同行的
    for(int i=1;i<10;i++)
    {
        have[a[x][i]]=true;
    }
    //同列的
    for(int j=1;j<10;j++)
    {
        have[a[j][y]]=true;
    }
    //同方格
    for(int i=be(x).first;i<=be(x).second;i++)
       for(int j=be(y).first;j<=be(y).second;j++)
       {
           have[a[i][j]]=true;
       }
    bool flag=false;
    for(int i=1;i<=9;i++)
    {
        if(have[i]==false)
        {
            a[x][y]=i;
            pair<int,int> next=next_blank(x,y);
            if(dfs(depth+1,next.first,next.second))
            {
                flag=true;
                break;
            }
        }
    }
    if(flag)return true;
    else
    {
        a[x][y]=0;
        return false;
    }
}
void input()
{
    sum=0;
    string tmp;
    for(int i=1;i<10;i++)
    {
        cin>>tmp;
        for(int j=0;j<9;j++)
        {
            a[i][j+1]=tmp[j]-48;
            if(a[i][j+1]==0)
                sum+=1;
        }
    }
}

int main()
{
    int cases;
//    ifstream fin("/home/zlq/Desktop/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    cin>>cases;
    for(int ii=1;ii<=cases;ii++)
    {
        input();
        //cout<<sum<<endl;
        pair<int,int> next;
        next=next_blank(0,0);
        //cout<<"first blank"<<endl;
        //cout<<next.first<<" "<<next.second<<endl;
        dfs(1,next.first,next.second);


        for(int i=1;i<=9;i++)
        {
            for(int j=1;j<=9;j++)
             {
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}
