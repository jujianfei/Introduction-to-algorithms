// 15242194_AC_516MS_964K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define M 20000+7
#define N 1000+7
#include<set>
int n,m;

struct Edge{
    int b,e,w;
};
Edge a[M];
bool compare(const Edge&n1,const Edge & n2){
    return n1.w<n2.w;
}

int fa[N];
int getroot(int x){
    if (x != fa[x]){
        fa[x] = getroot(fa[x]);
    }
    return fa[x];
}

bool q_m(int i,int j)  {
    int m=getroot(i);
    int n=getroot(j);
    if(m==n)   return true;
    else return false;
}

void merger(int i,int j){
    fa[getroot(j)]=getroot(i);
}

void Init(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
}

int Kruskal(){
    int res=0;
    for(int i=0;i<m;i++){
        int fir=a[i].b,sec=a[i].e;
        if(q_m(fir,sec)==false){
            res+=a[i].w;
            merger(fir,sec);
        }else{}
    }
    return res;
}

int GetIndex(int b,int e,int cnt){
    for(int i=0;i<cnt;i++){
        if((a[i].b==b&&a[i].e==e)||(a[i].b==e&&a[i].e==b)){
            return i;
        }
    }
    return cnt;
}
bool Connected(){
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(getroot(i));
    }
    return s.size()==1;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    Init();
    int aa,bb,cc;
    int now_cnt=0;
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&aa,&bb,&cc);
        cc=-cc;
        int index=GetIndex(aa,bb,now_cnt);
        if(index==now_cnt){
            a[index].b=aa,a[index].e=bb,a[index].w=cc;
            now_cnt++;
        }else{
            if(cc<a[index].w) a[index].w=cc;
        }
    }
    sort(a,a+now_cnt,compare);

    int ans=-Kruskal();
    if(Connected()){
        cout<<ans<<endl;
    }else{
        cout<<-1<<endl;
    }


}
