// 15134892_AC_0MS_836K.cc
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<deque>
using namespace std;

int end_x,end_y;
int m,n;
int left_cnt=0;
int right_cnt=0;
struct Node
{
  int r,c,dir;
  Node(int r_,int c_,int dir_){
      r=r_,c=c_,dir=dir_;
  }
  Node(){r=c=dir=-99;}
};

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

Node walk_left(Node &u, int turn) {
int dir = u.dir;
if(turn == 1) dir = (dir + 3) % 4; //左转
if(turn == 3) dir = (dir + 1) % 4; //右转
if(turn == 2) {}//前进
if(turn == 4) dir = (dir + 2) % 4;//后退
return Node(u.r + dr[dir], u.c + dc[dir], dir);

}
Node walk_right(Node &u, int turn) {
int dir = u.dir;
if(turn == 3) dir = (dir + 3) % 4; //左转
if(turn == 1) dir = (dir + 1) % 4; //右转
if(turn == 2) {}//前进
if(turn == 4) dir = (dir + 2) % 4;//后退
return Node(u.r + dr[dir], u.c + dc[dir], dir);

}
//漂亮!!

char c[51][51];
int a[51][51];
void init()
{
    for(int i=1;i<=50;i++)
        for(int j=1;j<=50;j++)
            c[i][j]=' ',a[i][j]=-2;
    left_cnt=right_cnt=0;
}

bool dfs(Node now)
{
    int x=now.r;
    int y=now.c;
    if(x<0||x>=n||y<0||y>=m||c[x][y]=='#')
        return false;

    left_cnt++;
    //cout<<" now"<<now.r<<" "<<now.c<<endl;
    if(now.r==end_x&&now.c==end_y)
    {
        return true;
    }


    return dfs(walk_left(now,1))||dfs(walk_left(now,2))||
            dfs(walk_left(now,3))||dfs(walk_left(now,4));
}

bool dfs_2(Node now)
{
    int x=now.r;
    int y=now.c;
    if(x<0||x>=n||y<0||y>=m||c[x][y]=='#')
        return false;

    right_cnt++;
    //cout<<" now"<<now.r<<" "<<now.c<<endl;
    if(now.r==end_x&&now.c==end_y)
    {
        return true;
    }


    return dfs_2(walk_right(now,1))||dfs_2(walk_right(now,2))||
            dfs_2(walk_right(now,3))||dfs_2(walk_right(now,4));
}

bool is_legal(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m)
        return false;
    if(a[x][y]==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //freopen("/home/zlq/acming6/in","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        init();
        scanf("%d%d",&m,&n);
        getchar();
        for(int now=0;now<n;now++)
        {
            gets(c[now]);
        }
        Node begin;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='S')
                {
                    begin.c=j,begin.r=i;
                    if(i==0){begin.dir=3;}
                    else if(i==n-1){begin.dir=1;}
                    else if(j==0){begin.dir=2;}
                    else if(j==m-1){begin.dir=0;}
                    else cout<<"inital error"<<endl;
                }
                if(c[i][j]=='E')
                {
                    end_x=i,end_y=j;
                }
            }
        }
        //cout<<"begin_is"<<begin.r<<" "<<begin.c<<endl;
        //cout<<"end_is"<<end_x<<" "<<end_y<<endl;
        dfs(begin);
        dfs_2(begin);
        cout<<left_cnt<<" "<<right_cnt<<" ";

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(c[i][j]=='#')
                {}
                else
                {
                    a[i][j]=-1;//代表可以访问的
                }


            }
        }

        deque<pair<int,int> > d;
        d.push_back(make_pair(begin.r,begin.c));

        a[begin.r][begin.c]=1;
       // cout<<end_x<<" "<<end_y<<endl;
        while(d.empty()==false)
        {
            pair<int,int> fro=d.front();
            d.pop_front();
            //cout<<" "<<fro.first<<" "<<fro.second<<" "<<a[fro.first][fro.second]<<endl;
            if(fro.first==end_x&&fro.second==end_y){break;}
            else
            {
                int _x=fro.first,_y=fro.second;
                if(is_legal(_x-1,_y)){d.push_back(make_pair(_x-1,_y));a[_x-1][_y]=a[_x][_y]+1;}
                if(is_legal(_x+1,_y)){d.push_back(make_pair(_x+1,_y));a[_x+1][_y]=a[_x][_y]+1;}
                if(is_legal(_x,_y+1)){d.push_back(make_pair(_x,_y+1));a[_x][_y+1]=a[_x][_y]+1;}
                if(is_legal(_x,_y-1)){d.push_back(make_pair(_x,_y-1));a[_x][_y-1]=a[_x][_y]+1;}
            }
        }
        cout<<a[end_x][end_y]<<endl;



    }



}
