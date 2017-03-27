// 15282627_AC_407MS_1480K.cc
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#define N 100000+7
using namespace std;
int n,m,p,q;
char t;
int fa[N];
int sex[N];

int getroot(int x){
    if (x != fa[x]){
        fa[x] = getroot(fa[x]);
    }
    return fa[x];
}

bool q_m(int i,int j){
    int m=getroot(i);
    int n=getroot(j);
    if(m==n)
        return true;
    else
        return false;
}
void merger(int i,int j)  {
    fa[getroot(j)]=getroot(i);
}
void Init(){
    for(int i=0;i<N;i++){
        fa[i]=i;
        sex[i]=-1;
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--){
        Init();
        scanf("%d%d",&n,&m);

        for(int i=0;i<m;i++){
            getchar();
            scanf("%c%d%d",&t,&p,&q);
            if(t=='A'){
                if(q_m(p,q)){
                    cout<<"In the same gang."<<endl;
                }else if(q_m(sex[p],q)){
                    cout<<"In different gangs."<<endl;
                }else{
                    cout<<"Not sure yet."<<endl;
                }

            }else{//一定不在同一个集合中了
                if(sex[p]==-1){
                    sex[p]=q;
                }else{
                    merger(sex[p],q);
                }

                if(sex[q]==-1){
                    sex[q]=p;
                }else{
                    merger(sex[q],p);
                }
            }
        }
    }
}
