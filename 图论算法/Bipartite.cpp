 #include "Graph.cpp"
 #include <bits/stdc++.h>
 class Bipartite {
 public:

    boolean isBipartite;   // is the graph bipartite?
    boolean* color;       // color[v] gives vertices on one side of bipartition
    boolean* marked;      // marked[v] = true if v has been visited in DFS
    int* edgeTo;          // edgeTo[v] = last edge on path to v
    Stack<Integer> cycle;  // odd-length cycle


    Bipartite(Graph&G) {
        isBipartite = true;
        color  = new boolean[G.V()];RST(color);
        marked = new boolean[G.V()];RST(marked);
        edgeTo = new int[G.V()];RST(edgeTo);

        for (int v = 0; v < G.V(); v++) {
            if (!marked[v]) {
                dfs(G, v);
            }
        }

    }

    void dfs(Graph &G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {

            // short circuit if odd-length cycle found
            if (cycle.empty()!=false) return;

            // found uncolored vertex, so recur
            if (!marked[w]) {
                edgeTo[w] = v;
                color[w] = !color[v];
                dfs(G, w);
            }

            ///* if v-w create an odd-length cycle, find it
            else if (color[w] == color[v]) {
                isBipartite = false;
                cycle.push(w);  // don't need this unless you want to include start vertex twice
                for (int x = v; x != w; x = edgeTo[x]) {
                    cycle.push(x);
                }
                cycle.push(w);
            }
        }
    }
    boolean IsBipartite() {
        return isBipartite;
    }
    boolean Color(int v) {
        if (!isBipartite)
            throw;
        return color[v];
    }
    stack<Integer> oddCycle() {
        return cycle;
    }
 };
