// 6456189_AC_0ms_0kB.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cstring>
using namespace std;
#define N 107
int G[N][N];
int in[N];
int m,n;
vector<int> stk;

int main() {
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m)) {
        if (m==0 && n == 0) break;
        memset(G, 0, sizeof(G));
        memset(in, 0, sizeof(in));
        stk.clear();
        int x,y;
        for (int i=0; i<m; i++) {
            scanf("%d%d" ,&x, &y);
            x--;y--;
            G[x][y] = 1;
            in[y] ++;
        }
        for (int i=0; i<n; i++) {
            if (in[i] == 0) {
                stk.push_back(i);
            }
        }
        while (stk.empty() == false) {
            int tmp = stk.back();
            cout << tmp + 1 << " ";
            stk.pop_back();
            for (int i=0; i<n; i++){
                if (G[tmp][i] == 1) {
                    in[i]--;
                    if (in[i]==0) { stk.push_back(i); }
                }
            }
        }cout << endl;
    }
}
