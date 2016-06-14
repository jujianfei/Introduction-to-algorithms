/*
13 22
0 1
0 5
2 0
6 0
2 3
3 2
3 5
5 4
4 3
4 2
6 4
11 4
7 6
7 8
8 7
6 9
8 9
9 10
9 11
11 12
12 9
10 12
*/

//Ҫ����һ��ͼ��ǿ��ͨ����������ӡ����
#include<bits/stdc++.h>
#include<vector>
#define N 107
using namespace std;
#define RSTVEC(x) for(int i=0;i<N;i++){x[i].clear();}

int n,m;
vector<int> G[N];
vector<int> GR[N];
deque<int> tp;
int visit[N];
int cnt=0;//��ͨ��������
int tag[N];//�������һ����ͨ����
/**
*
*
*
*
*
*
*/

//���ԭͼ����������Ϣ
void input(){
    RSTVEC(G);
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        G[a].push_back(b);
    }
}
//�����ͼ�������GR��
void reverser(){
    RSTVEC(GR);
    for(int i=0;i<n;i++){
        for(int j=0;j<G[i].size();j++){
            GR[j].push_back(i);
        }
    }
}

//�ڷ���ͼ�н���DFS����ͼ�������
//���ʹ��vector��������Ϣ����Ҫ����
//������ôֱ��ʹ��˫�˶��У���������Ϣ�ŵ����׼���
void dfs(int v){
    visit[v]=1;
    for(int i=0;i<GR[v].size();i++){
        if(!visit[GR[v][i]]){
            dfs(GR[v][i]);
        }
    }
    tp.push_front(v);
}

//����ͼ�е��������򣬵���dfs
void topo(){
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(i);
        }
    }
}

/***********************************************/
//��dfs�Ĺ�����Ҫ��Ǳ�ǩ��
void sec_dfs(int v){
    visit[v]=1;
    tag[v]=cnt;
    for(int i=0;i<G[v].size();i++){
        if(!visit[G[v][i]]){
            sec_dfs(G[v][i]);
        }
    }
}
//����tp�����е�˳����ԭͼ�н��еڶ���sec_dfs
void getans(){
    memset(visit,0,sizeof(visit));
    for(int i=0;i<n;i++){
        if(!visit[tp[i]]){
            cnt++;
            sec_dfs(tp[i]);
        }
    }
}

//��ʾ���
void showres(){
    vector<int> G[N];
    int maxer=-1;
    for(int i=0;i<n;i++){
        maxer=std::max(maxer,tag[i]);
        G[tag[i]].push_back(i);
    }
    for(int i=1;i<=maxer;i++){
        cout<<i<<": ";
        for(int j=0;j<G[i].size();j++){
            cout<<G[i][j]<<" ";
        }cout<<endl;
    }

}

int main(){
    freopen("in.txt","r",stdin);
    input();
    reverser();
    topo();
    getans();
    showres();
}
