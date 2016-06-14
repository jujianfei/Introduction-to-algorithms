#include<bits/stdc++.h>
using namespace std;
#define N 100
#define INF 0x3f3f3f
//这里我们假设图已经是一个DAG图
struct Node{
    int t,e,l;//活动(边)持续的时间，最早开始的时间，和最晚开始的时间
};
int in[N];//入度
int sort_res[N];//存放拓扑排序的结果
int Ee[N];//记录事件(顶点)最早发生的时间
int El[N];//记录事件(顶点)最晚发生的时间
Node G[N][N];//采用邻接矩阵索引从0开始
int m,n,b,e,w,cnt;

void Input(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&b,&e,&w);
        G[b][e].t=w;
        in[e]++;
    }
}


void Init(){
    memset(sort_res,0,sizeof(sort_res));
    memset(in,0,sizeof(in));
    memset(Ee,0,sizeof(Ee));
    memset(El,0,sizeof(El));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            G[i][j].e=G[i][j].t=0;
            G[i][j].l=0;
        }
    }
}



bool topsort(){
    cnt=0;
    vector<int> stack;//在拓扑排序算法中，可以使用队列或栈来存储入度为 0 的顶点
    int begin=-1;
    for(int i=0;i<n;i++){
        if(!in[i]){
            begin=i;break;
        }
    }
    if(begin==-1)return false;//连第一个都找不到
    stack.push_back(begin);
    while(stack.empty()==false){
        int tmp=stack.back();
        stack.pop_back();
        sort_res[cnt++]=tmp;
        for(int i=0;i<n;i++){
            if(G[tmp][i].t!=0){
                --in[i];
                if(!in[i])
                    stack.push_back(i);
            }
        }
    }
    return cnt==n;
}


void solve_aov(){
    for(int i=0;i<n;i++){//对于拓扑排序之后的元素进行操作
        int k=sort_res[i];
        if(i==0){
            Ee[k]=0;
            continue;
        }
        int maxer=-1;
        for(int j=0;j<i;j++){
            int m=sort_res[j];
            if(G[m][k].t!=0&&Ee[m]+G[m][k].t>maxer){
                maxer=Ee[m]+G[m][k].t;
            }
        }
        Ee[k]=maxer;
    }


    for(int i=n-1;i>=0;i--){
        int k=sort_res[i];
        if(i==n-1){
            El[k]=Ee[k];
            continue;
        }
        int miner=INF;
        for(int j=n-1;j>i;j--){
            int m=sort_res[j];
            if(G[k][m].t!=0&&El[m]-G[k][m].t<miner){
                miner=El[m]-G[k][m].t;
            }
        }
        El[k]=miner;
    }

    cout<<"-----show-Ee------"<<endl;
    for(int i=0;i<n;i++){
        cout<<Ee[i]<<" ";
    }cout<<endl;

    cout<<"-----show-El------"<<endl;
    for(int i=0;i<n;i++){
        cout<<El[i]<<" ";
    }cout<<endl;

    //求每条边的e,l;
    cout<<"-----show_Important_Road-----"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(G[i][j].t!=0){
                G[i][j].e=Ee[i];
                G[i][j].l=El[j]-G[i][j].t;
                if(G[i][j].l==G[i][j].e){
                    cout<<"Important_road"<<i<<"->"<<j<<endl;
                }
            }
        }
    }
}

//只需要找到一条关键路径即可
void easyer_solve(){
    int dist[N];
    int pre[N];
    memset(dist,-1,sizeof(dist));
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<n;i++){//对于拓扑排序之后的元素进行操作
        int k=sort_res[i];
        if(i==0){
            dist[k]=0;
            continue;
        }
        int maxer=-1;
        int ret=-1;
        for(int j=0;j<i;j++){
            m=sort_res[j];
            if(G[m][k].t!=0&&dist[m]+G[m][k].t>maxer){
                maxer=dist[m]+G[m][k].t;
                ret=m;
            }
        }
        dist[k]=maxer;
        pre[k]=ret;
    }
    int begin=n-1;
    while(begin!=-1){
        cout<<begin<<"--";
        begin=pre[begin];
    }
}

int main(){
    freopen("topoin.txt","r",stdin);
    Init();
    Input();
    if(!topsort()){
        cout<<"It's not a DAG"<<endl;
    }else{
        solve_aov();
    }
    cout<<endl;
    easyer_solve();

}
