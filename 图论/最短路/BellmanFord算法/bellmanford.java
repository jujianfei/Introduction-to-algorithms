/**
* 实现过程中将队列中出队的点进行放松操作，我们这里修改了放松的操作，
* 将放松的边的指向的点，加入队列，但是队列中不要重复出现相同的点，
* 并且周期性的检查已经修改好的图中是否存在环，检查周期是每当放松的数量能被V整除的时候。
*/

public BellmanFordSP(EdgeWeightedDigraph G, int s) {
        distTo  = new double[G.V()];
        edgeTo  = new DirectedEdge[G.V()];//存放已经修改好的图的信息
        onQueue = new boolean[G.V()];
        for (int v = 0; v < G.V(); v++)
            distTo[v] = Double.POSITIVE_INFINITY;
        distTo[s] = 0.0;

        // Bellman-Ford algorithm
        queue = new Queue<Integer>();
        queue.enqueue(s);
        onQueue[s] = true;
        while (!queue.isEmpty() && !hasNegativeCycle()) {
            int v = queue.dequeue();
            onQueue[v] = false;
            relax(G, v);
        }
    }

private void relax(EdgeWeightedDigraph G, int v) {
    for (DirectedEdge e : G.adj(v)) {
        int w = e.to();
        if (distTo[w] > distTo[v] + e.weight()) {
            distTo[w] = distTo[v] + e.weight();
            edgeTo[w] = e;
            if (!onQueue[w]) {
                queue.enqueue(w);
                onQueue[w] = true;
            }
        }
        if (cost++ % G.V() == 0) {
            findNegativeCycle();
            if (hasNegativeCycle()) return;  // found a negative cycle
        }
    }
}

// findNegativeCycle()使用有向图中的寻找环算法实现
