// 15030471_AC_3235MS_908K.cc
    #include<cstdio>  
    #include<cstring>  
    #include<iostream>  
    #include<queue>  
    using namespace std;  
    const int inf=1<<29;  
    const int maxn=510;  
    const int maxm=5e4;  
    int e,dfscolck,head[maxn],pnt[maxm],nxt[maxm],dfn[maxn],low[maxn];  
    int n,m,root;  
    bool lost[maxn];  
    void AddEdge(int u,int v)  
    {  
        pnt[e]=v;nxt[e]=head[u];head[u]=e++;  
    }  
    int DFS(int u,int f,bool &find)  
    {  
        dfn[u]=low[u]=++dfscolck;  
        int child=0;  
        for(int i=head[u];i!=-1;i=nxt[i])  
        {  
            if(lost[pnt[i]])  
                continue;  
            if(!dfn[pnt[i]])  
            {  
                child++;  
                low[u]=min(low[u],DFS(pnt[i],u,find));  
                if(find)  
                    return low[u];  
                if(u==root&&child>1||u!=root&&low[pnt[i]]>=dfn[u])  
                {  
                    find=true;  
                    return low[u];  
                }  
            }  
            else if(dfn[pnt[i]]<dfn[u]&&pnt[i]!=f)  
            {  
                low[u]=min(low[u],dfn[pnt[i]]);  
            }  
        }  
        return low[u];  
    }  
    void solve()  
    {  
        bool is=false;  
        for(int i=0;i<n;i++)  
        {  
            lost[i]=1;  
            dfscolck=0;  
            memset(dfn,0,sizeof(dfn));  
            root=(i+1)%n;  
            DFS(root,-1,is);  
            for(int j=0;j<n;j++)  
                if(j!=i&&!dfn[j])  
                {  
                    is=true;  
                    break;  
                }  
            lost[i]=0;  
            if(is)  
                break;  
        }  
        if(is)  
            printf("NO\n");  
        else  
            printf("YES\n");  
    }  
    int main()  
    {  
        while(scanf("%d%d",&n,&m)&&(n+m))  
        {  
            e=0;  
            memset(head,-1,sizeof(head));  
            for(int i=0;i<m;i++)  
            {  
                int u,v;  
                scanf("%d%d",&u,&v);  
                AddEdge(u,v);  
                AddEdge(v,u);  
            }  
            if(n<=2)  
            {  
                printf("NO\n");  
                continue;  
            }  
            solve();  
        }  
        return 0;  
    }  