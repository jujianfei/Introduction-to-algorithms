// 6660163_AC_750ms_0kB.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
typedef long long ll;
#define INF 0x3f3f3f3f
#define N 1007
#define M 1000007
#define RST(x) memset(x, 0, sizeof(x))

struct Node {
    int w;
    string b,e;
    bool operator < (const Node& n) const { return w < n.w; }
};

struct State {
    int id;
    int step;
    State(int id, int step):id(id), step(step) {}
    State(){}
    bool operator < (const State& n) const { return step > n.step; }
};

int n, m;
priority_queue<State> pq;
Node a[N];
int step[(1<<21)];
int ans;
int cases = 0;

int apply(int n, Node &nn) {
    string &b = nn.b;
    for (int i=0; i<b.size(); i++) {
        if (b[i]=='-' && (n&(1<<i))) return -1;
        if (b[i]=='+' && (n&(1<<i))==0) return -1;
    }
    string &e = nn.e;
    for (int i=0; i<e.size(); i++) {
        if (e[i]=='-') n = n&~(1<<i);
        else if (e[i]=='+') n = n | (1<<i);
    }
    return n;
}




void init() {
    memset(step, 0x3f, sizeof(step));
    while (pq.size()!=0) pq.pop();
    ans = INF;
}

int main() {

    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    while (1) {
        cases ++ ;

        init();
        if (n==0 &&m==0) break;
        printf("Product %d\n", cases);
        for (int i=0; i<m; i++) {
            cin >> a[i].w >> a[i].b >> a[i].e;
        }
        sort(a, a+m);
        int root = (1<<n) - 1;
        pq.push(State(root, 0));
        step[root] = 0;
        while (pq.size()>0) {

            State fro = pq.top();
            pq.pop();
            //cout << "now fro " << fro.id << " " << fro.step << endl;
            if (fro.id == 0) {
                ans = fro.step;
                break;
            }
            for (int i=0; i<m; i++) {
                int tar = apply(fro.id, a[i]);
                if (tar!=-1 && fro.step + a[i].w <= step[tar]) {
                    pq.push(State(tar, fro.step + a[i].w));
                    step[tar] = fro.step + a[i].w;
                    //cout << "   push " << tar << " " << fro.step + a[i].w << endl;
                }
            }
        }
        if (ans == INF) {
            cout << "Bugs cannot be fixed." << endl;
        } else {
            printf("Fastest sequence takes %d seconds.\n", ans);
        }
        cin >> n >> m;
        //if (n==0 &&m==0) break;
        //else cout << endl;
         cout << endl;
    }
}
