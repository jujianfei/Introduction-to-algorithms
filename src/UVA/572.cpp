// 6455966_AC_0ms_0kB.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cstring>
using namespace std;
#define N 107
int m,n;
const int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = { 0, 1, 0, -1, 1, -1, -1, 1};

vector<string> G;
string tmp;
bool islegal (int i, int j) {

    if (i<0 || i>=n || j<0 || j>=m) {return false;}
    if (G[i][j]== '*') return false;
    return true;
}


void dfs(int i,int j) {
    G[i][j]='*';
    for (int k=0; k<8; k++) {
        if (islegal(i+dx[k], j+dy[k])) {
            dfs(i+dx[k], j+dy[k]);
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin>>n>>m && m && n) {
        G.clear();
        for (int i=0;i<n;i++){
            cin>>tmp;
            G.push_back(tmp);
        }
        int counter = 0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (G[i][j] == '@') {
                    dfs(i,j);
                    counter ++;
                }
            }
        }
        cout << counter << endl;
    }
}
