// 6651584_AC_160ms_0kB.cpp
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define MAXN 1100
struct point{int x,y;};
struct edge
{
    int s,e;
    int dis;
};
point p[MAXN];
edge l[MAXN*MAXN];
vector<int> g[10];
int c[10];
int set[MAXN];
int n,m,q;
bool cmp(edge a,edge b) {return a.dis<b.dis; }
void init(int n) { for(int i=0;i<=n;i++) set[i]=i; }
int find (int x) {
    int r=x;
    while(r!=set[r])r=set[r];
    int i=x,j;
    while(set[i]!=r) {
        j=set[i];
        set[i]=r;
        i=j;
    }
    return r;
}
bool merge(int a,int b) {
    int x=find(a);
    int y=find(b);
    if(x==y) return false;
    set[x]=y; return true;
}
int kruscal() {
    int num=0,sum=0;
    for(int i=0;i<m&&num<n-1;i++) {
        if(merge(l[i].s,l[i].e)) {
            sum+=l[i].dis;
            num++;
        }
    }
    return sum;
}
int distances(point a,point b) { return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }
void solve() {
    int ans;
    init(n);
    ans=kruscal();//原始解
    //cout << "init " << ans << endl;
    for(int s=0;s<(1<<q);s++)//枚举，q种套餐一共2的q次方，选或不选
    {
        int cost=0;
        init(n);//每次记得清零集合
        for(int j=0;j<q;j++)
        {
            if(((s>>j)&1)) continue;//利用二进制枚举，很好的一个算法
            cost+=c[j];
            for(int k=1;k<g[j].size();k++)
                merge(g[j][k],g[j][0]);
        }
        ans=min(cost+kruscal(),ans);
    }
    printf("%d\n",ans);
}
int main() {
    //freopen("in.txt", "r", stdin);
    int t,cas=1;
    scanf("%d",&t);
    while(t--){
        if(cas>1) printf("\n");//UVA独特的输出格式
        cas++;
        scanf("%d%d",&n,&q);
        //while(scanf("%d%d",&n,&q)!=EOF){ 这是POJ的格式
        for(int i=0;i<q;i++)
        {
            int tmp,cnt;
            g[i].clear();
            scanf("%d",&cnt);
            scanf("%d",&c[i]);
            for(int j=0;j<cnt;j++)
            {
                scanf("%d",&tmp);
                g[i].push_back(tmp);
            }
        }//存入套餐
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        m=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
            {
                l[m].s=i;l[m].e=j;
                l[m++].dis=distances(p[i],p[j]);
            }
        sort(l,l+m,cmp);
        solve();
    }
}
