// 6523287_AC_157ms_1568kB.cpp
#include<iostream>
#include<stdio.h>
#include<math.h>
#include <algorithm>
#define N 50007
#include <vector>
#include <cstring>
#include <deque>
using namespace std;

int d[N];
int fa[N];
vector<int> G[N];
int n, target;

int bfs() {
    deque<int>  pq;
    pq.push_back(1);
    d[1]=0;
    while (pq.empty()==false) {
        int fro = pq.front();
        pq.pop_front();
        if (fro == target) {

            return d[fro];
        } else {
            for (int i=0;i<G[fro].size();i++) {
                if (d[G[fro][i]]==-1){
                    d[G[fro][i]]=d[fro] + 1;
                    pq.push_back(G[fro][i]);
                    fa[G[fro][i]] = fro;
                }
            }
        }
    }
    return -1;
}

void print(int fro) {
    vector<int> vec;
    while (fa[fro]!=-1) {
        vec.push_back(fro);
        fro=fa[fro];
    }
    vec.push_back(1);
    for(int i=vec.size()-1; i>=0; i--) {
        cout << vec[i] << endl;
    }
}

int main() {
    //freopen("IN", "r", stdin);
    cin >> n >> target;
    memset(d,-1,sizeof(d));
    memset(fa,-1,sizeof(fa));
    for (int i=0;i<N;i++) { G[i].clear(); }
    int x,y;
    for (int i=0;i<n;i++) {
        cin >> x >> y;
        G[x].push_back(y);
    }
    int ans = bfs() + 1;
    if (ans!=0) {
        cout << ans << endl;
        print(target);
    } else {
        cout << -1 << endl;
    }

}
