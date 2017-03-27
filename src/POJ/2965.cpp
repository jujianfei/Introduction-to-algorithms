// 16063706_AC_985MS_1516K.cc
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

string G[4];
int root = 0;
int visit[1<<16];
int fa[1<<16];
int opr[1<<16];
vector<int> fir,sec;

int transformer(int state, int k) {
    int i = k / 4;
    int j = k % 4;
    state = state ^ (1<<k);
    //col
    int m, n;
    for (int x=0; x<4; x++) {
        m = x * 4 + j;
        n = i * 4 + x;
        state = state ^ (1<<m);
        state = state ^ (1<<n);
    }

    return state;
}

int main() {
    //freopen("in.txt", "r", stdin);
    for (int i=0; i<4; i++) cin >> G[i];

    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            int k = i*4 + j;
            if (G[i][j] == '+') root = root | (1<<k);
        }
    }

    deque<int> pq;
    memset(visit, -1, sizeof(visit));
    memset(fa, -1, sizeof(fa));
    memset(opr, -1, sizeof(opr));

    pq.push_back(root);
    visit[root] = 0;

    while (pq.empty()==false) {
        int tmp = pq.front();
        pq.pop_front();
        if (tmp == 0) {
            cout << visit[tmp] << endl;
            int pa = fa[tmp];
            while (pa!=-1) {
                //cout << opr[tmp] / 4 + 1 << " " << opr[tmp] % 4 + 1 << endl;
                fir.push_back(opr[tmp] / 4 + 1);
                sec.push_back(opr[tmp] % 4 + 1);
                tmp = pa;
                pa = fa[pa];
            }

            for (int i=fir.size()-1; i>=0; i--) {
                cout << fir[i] << " " << sec[i] << endl;
            }
            return 0;
        }

        for (int k=0; k<16; k++) {
            int next = transformer(tmp, k);
            if (visit[next]==-1) {
                visit[next] = visit[tmp] + 1;
                pq.push_back(next);
                opr[next] = k;
                fa[next] = tmp;
            }
        }
    }



}
