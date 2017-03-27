// 15136691_AC_469MS_5096K.cc
    #include<iostream>  
    #include<stdio.h>  
    #include<queue>  
    using namespace std;  
    void bfs(int n)  
    {  
        queue<long long>q;  
        q.push(1);  
        while(!q.empty())  
        {  
            int i;  
            long long x;  
            x=q.front();  
            q.pop();  
            if(x%n==0)  
            {  
                printf("%lld\n",x);  
                return ;  
            }  
            q.push(x*10);  
            q.push(x*10+1);  
        }  
    }  
    int main()  
    {  
        int n;  
        while(scanf("%d",&n)&&n)  
        {  
            bfs(n);  
        }  
        return 0;  
    }  