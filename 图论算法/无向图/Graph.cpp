#include<bits/stdc++.h>
using namespace std;
#include "alias.h"
class Graph{
public:
private:
    int e;
    int v;
    vector<vector<int> > _adj;
public:
    void Init(int v);//构建一个含有v个定点但是不含有边的图
    Graph(ifstream&fin);//从输入流中读入数据构建图
    int V(){return this->v;}
    int E(){return this->e;}
    void addEdge(int v,int w);//添加边
    vector<int> Adj(int v){return this->_adj[v];}
    void Tostring();
    int Degree(int v){return _adj[v].size();}
};

void Graph::Init(int v){
    this->v=v;this->e=0;
    _adj.resize(v);
}
Graph::Graph(ifstream&fin){
    int lines;
    int nodes;
    fin>>nodes;
    fin>>lines;
    Init(nodes);
    int a,b;
    while(lines--){
        fin>>a>>b;
        addEdge(a,b);
    }
}
void Graph::addEdge(int v,int w){
    _adj[v].push_back(w);
    _adj[w].push_back(v);
    this->e++;
}
void Graph::Tostring(){
    cout<<this->v<<" "<<this->e<<endl;
    for(int i=0;i<this->v;i++){
        cout<<i<<":";
        for(auto & mem:_adj[i]){
            cout<<mem<<" ";
        }
        cout<<endl;
    }
}

// int main(){
//     ifstream infile ("tinyG.txt");
//     Graph g(infile);
//     g.Tostring();
// }
