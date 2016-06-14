#include "Digraph.cpp"
#include <bits/stdc++.h>
using namespace std;
class DirectedDFS {
    boolean* marked;  // marked[v] = true if v is reachable
                               // from source (or sources)
    int count=0;         // number of vertices reachable from s

    DirectedDFS(Digraph &G, int s) {
        marked = new boolean[G.V()];RST(marked);
        dfs(G, s);
    }

    void dfs(Digraph& G, int v) {
        count++;
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) dfs(G, w);
        }
    }


    boolean Marked(int v) {
        return marked[v];
    }


    int Count() {
        return count;
    }

};
int main(){}
