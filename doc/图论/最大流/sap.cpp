const int MaxN=2005;  
const int MaxE=400005;  
#define INF 0x3f3f3f3f  
struct Edge  
{  
    int u,v,flow,cap,pre;  
    Edge(){}  
    Edge(int u,int v,int cap,int pre) :  
        u(u),v(v),cap(cap),pre(pre) {flow=0;}  
}edge[MaxE];  
  
int head[MaxN],nEdge;  
  
void addEdge(int u,int v,int cap) 
{  
    edge[nEdge]=Edge(u,v,cap,head[u]);  
    head[u]=nEdge++;  
    edge[nEdge]=Edge(v,u,0,head[v]);  
    head[v]=nEdge++;  
}  

void edgeInit() // 添加边之前要先初始化。  
{  
    nEdge=0;  
    memset(head,-1,sizeof(head));  
}  
struct MaxFlow  
{  
    int st,ed,n,mx_flow;// 表示起点，终点，有多少个点，所求的最大流是多少。  
    int dis[MaxN],gap[MaxN],cur[MaxN],aug[MaxN],path[MaxN];  
    // dis表示每个点的距离标记，gap表示距离为i的点有多少个，cur用于当前孤优化，  
    // aug记录找到的增广路流量，path记录找到的增广路的路径。  
    MaxFlow(){}  
    MaxFlow(int st,int ed,int n) :  
        st(st),ed(ed),n(n) { init(); }  
    void init()  
    {  
        for(int i=0;i<MaxN;i++)  
        {  
            aug[i]=gap[i]=dis[i]=0;  
            cur[i]=head[i];  
        }  
        aug[st]=INF;    
        gap[0]=n;  
        mx_flow=0;  
    }  
    int augment(int &point) // 修改找到的增广路上的边的容量，当前点修改为起点。  
    {  
        for(int i=ed;i!=st;i=edge[path[i]].u)  
        {  
            int pair=path[i]^1;  
            edge[ path[i] ].flow+=aug[ed];  
            edge[ pair ].flow-=aug[ed];  
        }  
        point=st;  
        return aug[ed];  
    }  
    int solve()  
    {  
        int u=st;  
        while(dis[st]<n)  
        {  
            if(u==ed) mx_flow+=augment(u);  
  
            bool flag=1;  
            for(int i=head[u];i!=-1;i=edge[i].pre)  
            {  
                int v=edge[i].v;  
                if(edge[i].cap-edge[i].flow>0&&dis[u]==dis[v]+1)  
                {  
                    path[v]=i;  cur[u]=i;  
                    aug[v]=min(aug[u],edge[i].cap-edge[i].flow);  
                    u=v;  
                    flag=0; break;  
                }  
            }  
            if(flag)  
            {  
                if(--gap[dis[u]]==0) return mx_flow;  
                dis[u]=MaxN;  
                for(int i=head[u];i!=-1;i=edge[i].pre)  
                {  
                    int v=edge[i].v;  
                    if(edge[i].cap-edge[i].flow>0) dis[u]=min(dis[u],dis[v]+1);  
                }  
                gap[dis[u]]++;  
                cur[u]=head[u];  
                if(u!=st) u=edge[path[u]].u;  
            }  
        }  
        return mx_flow;  
    }  
}sap;  

