#include "alias.h"
#include <bits/stdc++.h>
using namespace std;
class Digraph {
private:
    int v;                  // number of vertices in this digraph
    int e;                 // number of edges in this digraph
    vector<vector<Integer>> adj_;    // adj[v] = adjacency list for vertex v
    int* indegree;        // indegree[v] = indegree of vertex v
public:
    Digraph(){}
    void init(int V) {
        if (V < 0) throw;
        this->v = V;
        this->e = 0;
        indegree = new int[V];RST(indegree);
        adj_.resize(V);
    }

    Digraph(ifstream &fin) {

        int nodes, lines;
        fin >> nodes >> lines;
        init(nodes);
        for (int i = 0; i < lines; i++) {
            int v,w;
            fin >> v >> w;
            addEdge(v, w);
        }


    }

    int V() {
        return this->v;
    }

    int E() {
        return this->e;
    }



    void addEdge(int v, int w) {
        adj_[v].push_back(w);
        indegree[w]++;
        this->e++;
    }


    Iterable<Integer> adj(int v) {
        return adj_[v];
    }


    int Outdegree(int v) {

        return adj_[v].size();
    }


    int Indegree(int v) {
        return indegree[v];
    }

    Digraph* Reverse() {
        Digraph *R=new Digraph();
        R->init(this->v);
        for (int v = 0; v < this->v; v++) {
            for (int w : adj(v)) {
                R->addEdge(w, v);
                cout<<"adder "<<w<<" "<<v<<endl;
            }
        }

        return R;
    }
    void Show(){
        cout<<"node:"<<this->v<<"  edge"<<this->e<<endl;
        for(int i=0;i<V();i++){
            cout<<i<<": ";
            for(int j=0;j<adj_[i].size();j++){
                cout<<adj_[i][j]<<" ";
            }cout<<endl;
        }
    }
};

// int main(){
//     ifstream fin("tinyDG.txt");
//     Digraph g(fin);
//     g.Show();
//     Digraph *rev=g.Reverse();//这里还是返回一个指针比较合理

// }
