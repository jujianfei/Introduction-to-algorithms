// 15030416_AC_79MS_556K.cc
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=26000;
struct node
{
    int x,y;
}a[MAXN];
int n,T;

bool cmp(node a,node b){return a.x<b.x;}

int main()
{
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    a[n+1].x=0x7fffffff;
    int t=0,tmp=0,ans=0;
    bool f=0;
    for (int i=1;i<=n;++i)
    {
        if (a[i].x<=t+1)
            {
                if (tmp<a[i].y) tmp=a[i].y,f=1;
                if (a[i+1].x>t+1 && f)
                    t=tmp,++ans,f=0;
            }
    }
    if (t<T)
     printf("-1\n"); else printf("%d\n",ans);
}
