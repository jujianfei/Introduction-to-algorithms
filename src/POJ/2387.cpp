// 14972174_AC_79MS_4324K.cc

#include<stdio.h>
const int inf = 1<<20;
const int NV = 1006;
int dis[NV];
int map1[NV][NV];
bool mark[NV];
int m,n;

void dijkstra(int src)
{
    int i, k, j,minf;
    for( i = 0; i < n; ++i)
    {
        mark[i] = false;
        dis[i] = map1[src][i];
    }
    dis[src] = 0;
    mark[src] = true;
    for( i = 1; i < n; ++i)
    {
        minf = inf;
        k = src;
        for(j = 0; j < n; ++j)
        {
            if(dis[j] < minf && (!mark[j]))
            {
                minf = dis[j];
                k = j;
            }
        }
        mark[k] = true;
        for(j = 0; j < n; j++)
        {
            int temp = dis[k] + map1[k][j];
            if(!mark[j] && temp < dis[j])
                dis[j] = temp;
        }
    }
    return;
}
int main()
{
        scanf("%d%d",&m,&n);

        for(int i = 0; i < n; ++i)
        {
            map1[i][i] = inf;
            for(int j = i + 1; j < n; j++)
            {
                map1[i][j] = inf;
                map1[j][i] = inf;
            }
        }
        while(m--)
        {
            int v1,v2,t;
            scanf("%d%d%d", &v1, &v2, &t);
            if(map1[v1 - 1][v2 - 1] > t)
            {
                map1[v1 - 1][v2 - 1] = t;
                map1[v2 - 1][v1 - 1] = t;
            }
        }
        dijkstra(0);
        printf("%d\n",dis[n - 1]);
}



