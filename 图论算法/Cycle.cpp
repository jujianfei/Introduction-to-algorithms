#include "Graph.cpp"
#include <bits/stdc++.h>
class Cycle{
private:
    boolean* marked;
    int* edgeTo;
    Stack<Integer> cycle;
public:
    Cycle(Graph& G) {

        marked = new boolean[G.V()]; RST(marked);
        edgeTo = new int[G.V()]; RST(edgeTo);
        for (int v = 0; v < G.V(); v++)
            if (!marked[v])
                dfs(G, -1, v);
    }

    // does this graph have two parallel edges?
    // side effect: initialize cycle to be two parallel edges
    boolean hasParallelEdges(Graph &G) {
        marked = new boolean[G.V()];RST(marked);
         while(cycle.size()!=0){cycle.pop();}
        for (int v = 0; v < G.V(); v++) {

            // check for parallel edges incident to v
            for (int w : G.adj(v)) {
                if (marked[w]) {

                    cycle.push(v);
                    cycle.push(w);
                    cycle.push(v);
                    return true;
                }
                marked[w] = true;
            }

            // reset so marked[v] = false for all v
            for (int w : G.adj(v)) {
                marked[w] = false;
            }
        }
        return false;
    }


    boolean hasCycle() {
        return cycle.size()!=0;
    }


    Stack<Integer> retcycle() {
        return this->cycle;
    }

    void dfs(Graph& G, int u, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            // short circuit if cycle already found
            if (cycle.empty()==false) return;
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, v, w);
            }
            // check for cycle (but disregard reverse of edge leading to v)
            else if (w != u) {
                for (int x = v; x != w; x = edgeTo[x]) {
                    cycle.push(x);
                }
                cycle.push(w);
                cycle.push(v);
            }
        }
    }
};

 int main(){
     ifstream infile ("mediumG.txt");
     Graph g(infile);
     Cycle c(g);
     auto tmp=c.retcycle();
     while(tmp.size()!=0){
        cout<<tmp.top()<<endl;
        tmp.pop();
     }
 }

