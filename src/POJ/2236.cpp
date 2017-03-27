// 15234616_AC_1766MS_716K.cc
#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
#define N 1007
struct Node{
    int x,y;
};
Node a[N];
int fa[N];
int mark[N];
int n,d;
int getroot(int x){
    if(x != fa[x]){
        fa[x] = getroot(fa[x]);
    }
    return fa[x];
}
bool q_m(int i,int j){
    int m=getroot(i);
    int n=getroot(j);
    if(m==n)return true;
    else return false;
}

void merger(int i,int j){
    fa[getroot(j)]=getroot(i);
}

void Init(){
    for(int i=0;i<N;i++){
        mark[i]=0;
        fa[i]=i;
    }
}

bool CanCommunicate(const Node& n1,const Node& n2){
    double tardis=d*1.0;
    double dis=sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y));
    if(tardis>=dis)return true;
    else return false;
}


int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&n,&d);
    Init();
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    char ty;
    int fir,sec;

    while(1){
        getchar();
        if(scanf("%c",&ty)==EOF)break;

        if(ty=='O') scanf("%d",&fir);
        else scanf("%d%d",&fir,&sec);

        if(ty=='O'){

            mark[fir]=true;
            for(int i=1;i<=n;i++){
                if(mark[i]==true&&CanCommunicate(a[fir],a[i])&&q_m(fir,i)==false){
                    merger(fir,i);

                }
            }
        }else{

            if(q_m(fir,sec)==true){
                cout<<"SUCCESS"<<endl;
            }else{
                cout<<"FAIL"<<endl;
            }
        }
    }

}
