// 15621814_AC_0MS_676K.cc
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<string>
#define Min(a,b) a<b?a:b
#define Max(a,b) a>b?a:b
#define CL(a,num) memset(a,num,sizeof(a));
#define maxn  60
#define eps  1e-8
#define inf 100000000
#define mx 1<<60
#define ll   __int64
using namespace std;

struct point
{
    int id ;
    int ord ;
    double x;
    double y;
}p[maxn];
bool vis[maxn] ;
double ans ;
int  n,num ;
int det(int x1,int y1,int x2,int y2)
 {
     return x1*y2 - x2*y1;
 }
 int cross(point a,point b,point c)
 {
     return det(b.x - a.x,b.y - a.y,c.x - a.x,c.y - a.y);
 }
double dis(point a,point b)
{
    double  x1 = a.x;
    double y1 = a.y;
    double x2 = b.x;
    double y2 = b.y ;
    return   (x2 - x1 )*(x2 - x1) + (y2-y1)*(y2 - y1);
}
void dfs(int pre,int num)
{

    if(num == n) return ;
    int mi = 1;
    while(vis[mi])mi++;
    for(int i = mi + 1 ;i <= n;i++)
    {
        if(vis[i])continue ;
        double w = cross(p[pre],p[mi],p[i]);
        if(w  < - eps) mi = i;
        if(w < fabs(eps) && dis(p[pre],p[i]) < dis(p[pre],p[mi])) mi = i;
    }
    p[mi].ord = num + 1;

    vis[mi] = true ;
    dfs(mi,num + 1) ;
}
bool cmp(point a,point b)
{
    return  a.ord < b.ord ;
}
int main()
{
    int i,j;
    //freopen("data.txt","r",stdin);
    int  t;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        CL(vis,false );
        int mi = inf ;
        for(i = 1 ; i<= n;i++)
        {
            scanf("%d%lf%lf",&p[i].id,&p[i].x,&p[i].y);
            if(mi == inf||p[mi].y > p[i].y) mi =  i;
        }
        vis[mi] = true ;

        p[mi].ord = 1 ;
        dfs(mi,1);
        sort(p + 1 ,p + 1 + n,cmp);
        printf("%d",n);
        for(i = 1;i <=n;i++)
        {

            printf(" %d",p[i].id) ;
        }
        printf("\n");
    }
}
