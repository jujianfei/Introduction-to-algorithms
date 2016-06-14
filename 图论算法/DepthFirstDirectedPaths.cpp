#include "Digraph.cpp"
#include <bits/stdc++.h>
using namespace std;
class DepthFirstDirectedPaths {
    boolean* marked;  // marked[v] = true if v is reachable from s
    int* edgeTo;      // edgeTo[v] = last edge on path from s to v
    int s;       // source vertex

public:
    DepthFirstDirectedPaths(Digraph &G, int s) {
        marked = new boolean[G.V()];RST(marked);
        edgeTo = new int[G.V()];RST(edgeTo);
        this->s = s;
        dfs(G, s);
    }

    void dfs(Digraph&G, int v) {
        marked[v] = true;
        for (int w : G.adj(v)) {
            if (!marked[w]) {
                edgeTo[w] = v;
                dfs(G, w);
            }
        }
    }


    boolean hasPathTo(int v) {
        return marked[v];
    }



    Iterable<Integer> pathTo(int v) {
        vector<Integer> path;
        if (!hasPathTo(v)) return path;
        for (int x = v; x != s; x = edgeTo[x])
            path.push_back(x);
        path.push_back(s);
        reverse(path.begin(),path.end());
    }



};
int main(){
    ifstream fin("tinyDG.txt");
    Digraph g(fin);
    DepthFirstDirectedPaths ans(g,0);
    for(int i=0;i<g.V();i++){
        cout<<i<<" : ";
        for(auto &m:ans.pathTo(i)){
            cout<<m<<" ";
        }cout<<endl;
    }
    //g.Show();

}
