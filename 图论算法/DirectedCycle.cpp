#include <bits/stdc++.h>
#include "Digraph.cpp"
class DirectedCycle {
    boolean* marked;        // marked[v] = has vertex v been marked?
    int* edgeTo;            // edgeTo[v] = previous vertex on path to v
    boolean* onStack;       // onStack[v] = is vertex on the stack?
    Stack<Integer> cycle;    // directed cycle (or null if no such cycle)

    DirectedCycle(Digraph& G) {
        marked  = new boolean[G.V()];RST(marked);
        onStack = new boolean[G.V()];RST(onStack);
        edgeTo  = new int[G.V()];RST(edgeTo);
        for (int v = 0; v < G.V(); v++)
            if (!marked[v] && cycle.size()==0) dfs(G, v);
    }

    // check that algorithm computes either the topological order or finds a directed cycle
    void dfs(Digraph&G, int v) {
        onStack[v] = true;
        marked[v] = true;
        for (int w : G.adj(v)) {

            // short circuit if directed cycle found
            if (cycle.size()!=0) return;

            //found new vertex, so recur
            else if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }

            // trace back directed cycle
            else if (onStack[w]) {

                for (int x = v; x != w; x = edgeTo[x]) {
                    cycle.push(x);
                }
                cycle.push(w);
                cycle.push(v);

            }
        }
        onStack[v] = false;
    }


    boolean hasCycle() {
        return cycle.size()!=0;
    }


    stack<Integer> Cycle() {
        return cycle;
    }

};
