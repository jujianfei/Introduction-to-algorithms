```C++
#include<iostream>    
using namespace std;    
    
     
    
int n, ans;    
int cap[Max][Max], pre[Max];    
int cost[Max][Max], dis[Max];    
int que[Max];    
bool vis[Max];    
    
     
    
bool spfa(){                  //  源点为0，汇点为n。    
    int i, head = 0, tail = 1;    
    for(i = 0; i <= n; i ++){    
        dis[i] = inf;    
        vis[i] = false;    
    }    
    dis[0] = 0;    
    que[0] = 0;    
    
    vis[u] = true;    
    
    while(tail != head){      //  循环队列。    
        int u = que[head];    
    
        for(i = 0; i <= n; i ++)    
            if(cap[u][i] && dis[i] > dis[u] + cost[u][i]){    //  存在路径，且权值变小。    
                dis[i] = dis[u] + cost[u][i];    
                pre[i] = u;    
                if(!vis[i]){    
                    vis[i] = true;    
                    que[tail ++] = i;    
                    if(tail == Max) tail = 0;    
                }    
            }    
        vis[u] = false;    
        head ++;    
        if(head == Max) head = 0;    
    }    
    if(dis[n] == inf) return false;    
    return true;    
}    
    
     
    
void end(){    
    int i, sum = inf;    
    for(i = n; i != 0; i = pre[i])    
        sum = min(sum, cap[pre[i]][i]);    
    for(i = n; i != 0; i = pre[i]){    
        cap[pre[i]][i] -= sum;    
        cap[i][pre[i]] += sum;    
        ans += cost[pre[i]][i] * sum;   //  cost[][]记录的为单位流量费用，必须得乘以流量。    
    }    
}    
    
     
    
int main(){    
    ....    
    ans = 0;    
    while(spfa()) end();    
    ....    
    return 0;    
}    
```

针对带权的图的最大权的完美匹配；
原图中所有的边的费用是权值的负数，然后，其他边的费用是0， 求一个从s到t的最小费用，最大流，
如果从s出发的边，不是 流量都等于容量，那么说明完美匹配不存在，
否则原图中所有流量为1的边对应最大权完美匹配。