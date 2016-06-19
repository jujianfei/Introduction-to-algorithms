#include "Graph.cpp"
#include <bits/stdc++.h>
using namespace std;

class DepthFirstPaths {
public:
    bool*marked;    // marked[v] = is there an s-v path?
    int*edgeTo;        // edgeTo[v] = last edge on s-v path
    int s;         // source vertex

    DepthFirstPaths(Graph &G,int s) {
        this->s=s;
        edgeTo=new int[G.V()];memset(edgeTo,0,sizeof(edgeTo));
        marked=new bool[G.V()];memset(marked,0,sizeof(marked));
        dfs(G,s);
    }

    // depth first search from v
    void dfs(Graph& G,int v){
        marked[v]=true;
        for (int w:G.Adj(v)){
            if (!marked[w]){
                edgeTo[w]=v;
                dfs(G,w);
            }
        }
    }
    bool hasPathTo(int v){return marked[v];}
    vector<int> pathTo(int v){
        vector<int> path;
        if(!hasPathTo(v))return path;
        for(int x=v;x!=s;x=edgeTo[x])
            path.push_back(x);
        path.push_back(s);
        return path;
    }
};
 int main(){
     ifstream infile("tinyG.txt");
     Graph g(infile);
     DepthFirstPaths ans(g,0);
     for(auto &m:ans.pathTo(3)){
        cout<<m<<" "<<endl;
     }
 }
