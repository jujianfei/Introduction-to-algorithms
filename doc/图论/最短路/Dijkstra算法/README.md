
# 最短路

思想很简单：将disto最小的非树顶点加入树中，并且放松这个定点指出去的边

## 基于优先队列的Dijkstar实现

将没有加入生成树的点，放入一个索引优先队列中，索引值是disto，不断的从优先队列中选择出disto最小的定点，加入到生成树中，并且访问这个点，访问过程如下：放松这个点指出的所有的边，如果指向的那个定点，被发现更新了数值，那么就要加入到优先队列中。

当然这样会出现一个问题就是，同一个点，可能加入生成树之后，又被加入到优先队列中去，这里有两中选择方案，一种是在放松的过程中如果发现了已经访问过的点，就不要加入（所谓即时版本），另一种方案是在从优先队列中取出之后检查是不是已经访问过，如果已经访问过，就跳过。（所谓延时版本）

- [即时版本邻接表实现](Dijkstra.cpp)

其实这里的索引优先队列没有必要是使用change过程，因此可以简单的使用Node模拟就行。

- 算法复杂度

一般情况 ElogV 最坏情况 ElogV 额外空间V

- 应用到无向图

上述的代码默认是应用在有向图中的，但是也可以应用在无向图中。

- 局限性

**Dijkstra算法，不能处理负的边构成环的情况**。

理想的实现会导致Dijkstra算法一直停留在环位置的更新，但是我们上述的对于索引实现，虽然不会导致死循环，但是也是会输出错误的结果。

**Dijkstra不能处理边的权值为负的情况**。


为什么不适用呢？其实很容易就可以找到反例。假设一张加权图，有的边长为负数。假设边长最小为-10，我们把所有的边长都加上10，就这就可以得到一张无负值加权图。此时用Dijkstra算法算出一个从节点s到节点t的最短路径L，L共包括n条边，总长为t；那么对于原图，每条边都要减去10，所以原图中L的长度是t-10*n。这是Diskstra算法算出的结果。

那么问题来了：对于加上10之后的图，假设还有一个从s到t的路径M，长度为t1，它共包括n1条边，比L包含的边长多，那么还原回来之后，每条边需要减去10，那么M的总长就是t1-10*n1。那么，是不是M的总长一定比L的总长更长一些呢？不一定。假如n1>n，也就是说M的边数比L的边数更多，那么M减去的要比L减去的更多，那么t1-10*n1<t-10*n是可能的。此时Dijkstra算法是不成立的。



**如果一张图里有负数边，但没有总长为负数的环，此时可以用Bellman-Ford算法计算**。




## [基于邻接矩阵的O(V^2)的朴素实现](Dijkstra_V2.cpp)

## Pr

- POJ-3255-次短路
