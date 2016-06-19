#include "Digraph.cpp"
#include <bits/stdc++.h>
using namespace std;

class BreadthFirstDirectedPaths {
    boolean*marked;  // marked[v] = is there an s->v path?
    int*edgeTo;      // edgeTo[v] = last edge on shortest s->v path
    int*distTo;      // distTo[v] = length of shortest s->v path

public:
    BreadthFirstDirectedPaths(Digraph &G,int s){
        marked=new boolean[G.V()];RST(marked);
        distTo=new int[G.V()];RST(distTo);
        edgeTo=new int[G.V()];RST(edgeTo);
        for(int v=0;v<G.V();v++)
            distTo[v]=INFINITY;
        bfs(G,s);
    }

    // BFS from single source
    void bfs(Digraph& G,int s){
        deque<Integer> q;
        marked[s]=true;
        distTo[s]=0;
        q.push_back(s);
        while(q.size()!=0){
            int v=q.front();
            q.pop_front();
            for (int w:G.adj(v)){
                if (!marked[w]){
                    edgeTo[w]=v;
                    distTo[w]=distTo[v]+1;
                    marked[w]=true;
                    q.push_back(w);
                }
            }
        }
    }


    boolean hasPathTo(int v){return marked[v];}
    int DistTo(int v){return distTo[v];}
    Iterable<Integer> pathTo(int v){
        vector<Integer> path;
        if(!hasPathTo(v))return path;
        int x;
        for(x=v;distTo[x]!=0;x=edgeTo[x])
            path.push_back(x);
        path.push_back(x);
        return path;
    }

};
int main(){
    ifstream fin("tinyDG.txt");
    Digraph g(fin);
    BreadthFirstDirectedPaths ans(g,0);
    for(int i=0;i<g.V();i++){
        cout<<i<<" : ";
        //cout<<ans.DistTo(i)<<endl;
        for(auto &m:ans.pathTo(i)){
            cout<<m<<" ";
        }cout<<endl;
    }
    //g.Show();
}
