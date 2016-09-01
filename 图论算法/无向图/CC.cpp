#include "Graph.cpp"
#include<bits/stdc++.h>
using namespace std;

class CC {
private:
    boolean*marked;   // marked[v] = has vertex v been marked?
    int*id;           // id[v] = id of connected component containing v
    int*size;         // size[id] = number of vertices in given component
    int count=0;          // number of connected components

public:
    CC(Graph&G){
        marked=new boolean[G.V()];RST(marked);
        id=new int[G.V()];RST(id);
        size=new int[G.V()];RST(size);
        for(int v=0;v<G.V();v++){
            if(!marked[v]){
                dfs(G,v);
                count++;
            }
        }
    }

    // depth-first search
    void dfs(Graph &G,int v){
        marked[v]=true;
        id[v]=count;
        size[count]++;
        for(int w:G.adj(v)){
            if(!marked[w]){
                dfs(G,w);
            }
        }
    }

    int Id(int v){return id[v];}
    int Size(int v){return size[id[v]];}
    int Count(){return count;}
    boolean connected(int v,int w) {return Id(v)==Id(w);}
};

int main(){
     ifstream infile ("tinyG.txt");
     Graph g(infile);
     CC ans(g);
}
