#include "Graph.cpp"
#include <bits/stdc++.h>

using namespace std;
class BreadthFirstPaths {
private:
    bool* marked;  // marked[v] = is there an s-v path
    int* edgeTo;      // edgeTo[v] = previous edge on shortest s-v path
    int* distTo;      // distTo[v] = number of edges shortest s-v path
public:
    BreadthFirstPaths(Graph &G, int s) {
        marked = new bool[G.V()];RST(marked);
        distTo = new int[G.V()];RST(distTo);
        edgeTo = new int[G.V()];RST(edgeTo);
        bfs(G, s);

    }
    // breadth-first search from a single source
    void bfs(Graph &G, int s) {
        deque<int> q;
        for (int v = 0; v < G.V(); v++)
            distTo[v] = INFINITY;
        distTo[s] = 0;
        marked[s] = true;
        q.push_back(s);
        while (q.size()!=0) {
            int v = q.front();
            q.pop_front();
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    edgeTo[w] = v;
                    distTo[w] = distTo[v] + 1;
                    marked[w] = true;
                    q.push_back(w);
                }
            }
        }
    }
    bool hasPathTo(int v) {
        return marked[v];
    }
    int DistTo(int v) {
        return distTo[v];
    }
    vector<Integer> pathTo(int v) {
        vector<Integer> path;
        if (!hasPathTo(v)) return path;
        int x;
        for (x = v; distTo[x] != 0; x = edgeTo[x])
            path.push_back(x);
        path.push_back(x);
        return path;
    }
};

int main(){
    ifstream infile ("tinyG.txt");
     Graph g(infile);
     BreadthFirstPaths ans(g,0);
     for(auto &m:ans.pathTo(3)){
        cout<<m<<" "<<endl;
     }
}
