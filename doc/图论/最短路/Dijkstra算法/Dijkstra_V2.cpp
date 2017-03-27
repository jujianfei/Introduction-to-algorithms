#include <stdio.h>

int main(){

    int startPoint = 1;
    int limitValue = 999;
    int e[10][10], dis[10], book[10], i, j, m, n, point1, point2, length, u, v, min;
    //n是点数，m是边数
    scanf("%d %d", &n, &m);
    //如果i=j，就是自己到自己的距离，那么就是0，否则，就初始化非正无穷
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i==j)
                e[i][j] = 0;
            else
                e[i][j] = limitValue;
        }
    }

    //边的长度，即点到点的距离
    for(i=1; i<=m; i++){
        scanf("%d %d %d", &point1, &point2, &length);
        e[point1][point2] = length;
    }

    //初始化源点到各点的距离的数组, 我们的源点为1
    for(i=1; i<=n; i++){
        dis[i] = e[startPoint][i];
    }

    //book数组用来标记那个点是已经走过了的。
    for(i=1; i<=n; i++){
        book[i] = 0;
    }

    //从源点开始
    book[startPoint] = 1;

    //以下就是Dijkstra算法的重点，是核心思想
    for(i=1; i<=n-1; i++){
        //找到离远点最近的点
        min = limitValue;
        for(j=1; j<=n; j++){
            if(book[j] == 0 && dis[j] < min){
                min = dis[j];
                u = j;
            }
        }
        book[u] = 1;
        for(v=1; v<=n; v++){
            //如果小于limitValue，则证明点u到点v是有路走的
            if(e[u][v] < limitValue){
                if(dis[v] > dis[u] + e[u][v]){
                    dis[v] = dis[u] + e[u][v];
                }
            }
        }
    }

    //输出

    for(i=0; i<=n; i++){
        printf("%d ", dis[i]);
    }

    return 0;

}

/*
输入：

6 9

1 2 1

1 3 12

2 3 9

2 4 3

3 5 5

4 3 4

4 5 13

4 6 15

5 6 4

输出

0 1 8 4 13 17

这个输出便是点1到各个点的最短距离。



Ps:本算法参考《啊哈！算法》一书。
*/