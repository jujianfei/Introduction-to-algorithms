## 最大流的实现

- [Dinic解法](dinic.cpp)
- [SAP解法](sap.cpp)


## 最小割

对于给定的网络，为了保证没有路径从s到t，需要删去的边的总容量的最小值是多少？

最小割 == 最大流

## 最大流的变体

有多个源点和汇点，这些点都有最大流入容量和最小流入容量 => 增加一个超级源点和超级汇点，并且附加相应的容量即可。

无向图的情况，把无向图的容量为c的边，当成两条容量为c的有向边即可。

顶点有容量限制 => 拆点。

有最小流量限制

增加新的原点，S和汇点，T.

每条边e=(u, v), 另新的c(e) = c(e) - b(e)

S->v连接容量为b(e)的边，从u->T连接容量为b(e)的边。

S->s == +00

t->T == +oo

这样就转化成了没有最小流量的情况。

新图的最大流是G

原来的图最大流是 F = G - sigma(e <- E) b(e)

## 二分匹配


二分图的最大匹配问题看成是网络流的一种变形。

将原题中的所有无向边，e改成有向边，方向从U->V，容量为1，增加源点和汇点S，T，从S到所有的U点连一条容量是1的边，从所有的V到T连一条容量为1的边。

最大流就是二分图的最大匹配。



## 一般图匹配，略。


## Pr

- POJ-3041-攻击小行星
- POJ-3057-能安全逃脱吗
- POJ-3281-为牛分配食物饮料
- POJ-3469-为CPU分配任务
- POJ-2135-Farm_Tour
- POJ-3713-Transferring_Sylla
- POJ-2987-Firing
- POJ-2914-Minimum_Cut
- POJ-3155-Hard_Life
- POJ-1274-The_Perfect_Stall
- POJ-2112-Optimal_Milking
- POJ-1486-Sorting_Slides
- POJ-1466-Girls_and_Boys
- POJ-3692-Kindergarten
- POJ-2724-Purifying_Machine
- POJ-2226-Muddy_Fields