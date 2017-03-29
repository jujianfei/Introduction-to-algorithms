## 克鲁斯卡尔（Kruskal）算法（只与边相关）

算法描述：克鲁斯卡尔算法需要对图的边进行访问，所以克鲁斯卡尔算法的时间复杂度只和边又关系，可以证明其时间复杂度为O（eloge）。
算法过程：
1.将图各边按照权值进行排序
2.将图遍历一次，找出权值最小的边，（条件：此次找出的边不能和已加入最小生成树集合的边构成环），若符合条件，则加入最小生成树的集合中。不符合条件则继续遍历图，寻找下一个最小权值的边。
3.递归重复步骤1，直到找出n-1条边为止（设图有n个结点，则最小生成树的边数应为n-1条），算法结束。得到的就是此图的最小生成树。

克鲁斯卡尔（Kruskal）算法因为只与边相关，则适合求稀疏图的最小生成树。而prime算法因为只与顶点有关，所以适合求稠密图的最小生成树。

```C++
struct edge { int u, v, cost; }

bool comp(const edge& n1, const edge& n2) {
    return n1.cost < n2.cost;
}

edge es[MAX_E];
int V, E;

int kruskal() {
    sort(es, es+E, comp);
    init_union_find(V);
    int res = 0;
    for (int i=0; i<E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

```


# Pr

- POJ-3723-conscription