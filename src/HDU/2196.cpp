// 4991227_AC_46ms_1840kB.cpp
    #include<cstdio>  
    #include<cstring>  
    using namespace std;  
    #define MAX 10005  
    #define max(a,b) ((a)>(b)?(a):(b))  
    int dp[MAX][3];  
    int edge[MAX<<1];//表示第i条边的终点  
    int next[MAX<<1];//与第i条边同起点的下一条边的位置  
    int head[MAX<<1];//以i为起点的第一条边的储存位置  
    int cost[MAX<<1];  
    void insert(int i,int a,int b,int c)//a起点,b终点  
    {  
        edge[i]=b;  
        next[i]=head[a];  
        head[a]=i;  
        cost[i]=c;  
    }  
    void dp1(int x,int pre)  
    {  
        for(int i=head[x]; i!=-1; i=next[i])  
        {  
            int k=edge[i];  
            if(k!=pre)  
            {  
                dp1(k,x);  
                if(dp[x][0]<cost[i]+dp[k][0])  
                {  
                    dp[x][1]=dp[x][0];//更新次长子树路径  
                    dp[x][0]=cost[i]+dp[k][0];//更新最长子树路径  
                }  
                else if(dp[x][1]<cost[i]+dp[k][0])  
                    dp[x][1]=cost[i]+dp[k][0];//更新次长子树路径  
            }  
        }  
    }  
    void dp2(int x,int pre)  
    {  
        int len=0;  
        for(int i=head[x]; i!=-1; i=next[i])  
            if(edge[i]==pre)  
            {  
                len=cost[i];  
                break;  
            }  
        if(pre!=-1)  
        {  
            dp[x][2]=dp[pre][2];  
            if(dp[x][0]+len==dp[pre][0])  
            {  
                if(dp[pre][1]>dp[x][2]) dp[x][2]=dp[pre][1];  
            }  
            else if(dp[pre][0]>dp[x][2]) dp[x][2]=dp[pre][0];  
            dp[x][2]+=len;  
        }  
        for(int i=head[x]; i!=-1; i=next[i])  
            if(edge[i]!=pre)   dp2(edge[i],x);  
    }  
    int main()  
    {  
        int n;  
        int a,b;  
        for(; ~scanf("%d",&n);)  
        {  
            memset(dp,0,sizeof(dp));  
            memset(head,-1,sizeof(head));  
            memset(next,-1,sizeof(next));  
            for(int i=2,j=1; i<=n; ++i)  
            {  
                scanf("%d%d",&a,&b);  
                insert(j++,i,a,b);  
                insert(j++,a,i,b);  
            }  
            dp1(1,-1);//求子树最长路  
            dp2(1,-1);//求父树最长路  
            for(int i=1; i<=n; ++i)  
                printf("%d\n",max(dp[i][0],dp[i][2]));  
        }  
        return 0;  
    }  