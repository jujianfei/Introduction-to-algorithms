// 15136214_AC_0MS_872K.cc
#include<iostream>
#include<stdio.h>
#include<deque>
#include<vector>
using namespace std;
int m,n,target,res_x,res_y;
#define N 106
#define FILL1 1
#define FILL2 2
#define DROP1 3
#define DROP2 4
#define POUR1 5
#define POUR2 6
struct Node
{
  int fax;
  int fay;
  int op;
  Node(int x,int y,int o):fax(x),fay(y),op(o){}
  Node(){
        op=0;
        fax=-1;
        fay=-1;
  }
};
Node a[N][N];
vector<int> res;
pair<int,int> f(int op,int x,int y)
{
    if(op==DROP1)
    {return pair<int,int>(0,y);}
    if(op==DROP2)
    {return pair<int,int>(x,0);}
    if(op==FILL1)
    {return pair<int,int>(n,y);}
    if(op==FILL2)
    {return pair<int,int>(x,m);}
    if(op==POUR2)
    {
        if(y+x>=n){return pair<int,int>(n,(x+y-n));}
        else{return pair<int,int>(x+y,0);}
    }
    if(op==POUR1)
    {
        if(x+y>=m){return pair<int,int>(x+y-m,m);}
        else{return pair<int,int>(0,x+y);}
    }
}
void init()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            a[i][j]=Node();
    res_x=res_y=0;
    res.clear();
}
int main()
{
    //freopen("/home/zlq/acming7/in","r",stdin); 
    scanf("%d%d%d",&n,&m,&target);

       init();
       deque<pair<int,int> >d;
       d.push_back(make_pair(0,0));
       a[0][0].fax=-2,a[0][0].fay=-2;
       int flag=0;
       while(d.empty()==false)
       {
           pair<int,int> fro=d.front();
           d.pop_front();
           int x=fro.first,y=fro.second;
           //cout<<"x&y "<<x<<" "<<y<<endl;
           if(x==target||y==target){flag=1;res_x=x;res_y=y;break;}
           pair<int,int> res;
           for(int op=1;op<=6;op++)
           {
               res=f(op,x,y);
               if(a[res.first][res.second].fax==-1&&a[res.first][res.second].fay==-1)
               {
                   a[res.first][res.second].fax=x;
                   a[res.first][res.second].fay=y;
                   a[res.first][res.second].op=op;
                   d.push_back(make_pair(res.first,res.second));
                   //cout<<"has put in "<<res.first<<" "<<res.second<<endl;
               }

           }
       }
       if(flag)
       {

           int tmp_x=res_x,tmp_y=res_y;
           while(!(a[tmp_x][tmp_y].fax==-2&&a[tmp_x][tmp_y].fay==-2))
           {
               res.push_back(a[tmp_x][tmp_y].op);
               int fx=a[tmp_x][tmp_y].fax;
               int fy=a[tmp_x][tmp_y].fay;
               tmp_x=fx;tmp_y=fy;
           }
           cout<<res.size()<<endl;
           for(int i=res.size()-1;i>=0;i--)
           {
               switch (res[i]) {
               case DROP1:cout<<"DROP(1)"<<endl;
                   break;
               case DROP2:cout<<"DROP(2)"<<endl;
                   break;
               case POUR1:cout<<"POUR(1,2)"<<endl;
                   break;
               case POUR2:cout<<"POUR(2,1)"<<endl;
                   break;
               case FILL1:cout<<"FILL(1)"<<endl;
                   break;
               case FILL2:cout<<"FILL(2)"<<endl;
                   break;
               case 0:cout<<"error"<<endl;
                   break;
               }
           }
       }
       else
       {
           cout<<"impossible"<<endl;
       }
    }

