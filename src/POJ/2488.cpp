// 15133400_AC_16MS_756K.cc
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;
int a[27][27];

int m,n;
int dfs(int i,int  x,int y)
{
    //cout<<"dfsing "<<x<<" "<<y<<endl;
    if(x<1||x>n||y<1||y>m)
        return false;
    if(a[x][y]!=0)
        return false;

   a[x][y]=i;//将xy位置标记为访问过

   if(i==m*n) return true;

   int res=dfs(i+1,x-1,y-2)||dfs(i+1,x+1,y-2)||dfs(i+1,x-2,y-1)||
           dfs(i+1,x+2,y-1)||dfs(i+1,x-2,y+1)||dfs(i+1,x+2,y+1)||
           dfs(i+1,x-1,y+2)||dfs(i+1,x+1,y+2);
   if(res==false)
   {
       a[x][y]=0;//如果失败将标记去掉
   }
   return res;

}

int main()
{
//    ifstream fin("/home/zlq/acming6/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());
    int cases;
    cin>>cases;
    for(int now=1;now<=cases;now++)
    {
      cout<<"Scenario #"<<now<<":"<<endl;
      for(int i=0;i<27;i++)
          for(int j=0;j<27;j++)
              a[i][j]=0;
      cin>>n>>m;
      if(dfs(1,1,1)==0)
      {
          cout<<"impossible"<<endl<<endl;
      }
      else
      {
//          for(int i=1;i<=4;i++)
//            {
//              for(int j=1;j<=3;j++)
//              {
//                  cout<<a[i][j]<<" ";
//              }
//              cout<<endl;
//          }

          string res;
          for(int target=1;target<=m*n;target++)
          {

              for(int i=1;i<=n;i++)
              {
                  for(int j=1;j<=m;j++)
                  {
                     if(a[i][j]==target)
                     {
                         res+=(j+64);
                         res+=(i+48);
                     }
                  }
              }

          }
          cout<<res<<endl<<endl;

      }
    }

}
