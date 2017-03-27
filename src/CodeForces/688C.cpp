#include <bits/stdc++.h>
using namespace std;

#define N 100007

vector<int> G[N];
int m, n;
int clr[N];


int dfs(int i, int c) {

    clr[i] = c;
    for (int k=0; k<G[i].size(); k++) {
        int v = G[i][k];
        if (clr[v] == c) {
            return false;
        } else {
            if (clr[v]== -1 && dfs(v, 1-c) == false) return 0;
        }
    }
    return true;
}





int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    memset(clr, -1, sizeof(clr));
    int a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i=1; i<=n; i++) {
        if (clr[i] == -1) {
            if (dfs(i, 0) == false) {
                cout << "-1"<< endl;
                return 0;
            }
        }

    }

    int A=0, B=0;
    vector<int> va, vb;
    for (int i=1; i<=n; i++) {
        if (G[i].size()==0) continue;
        if (clr[i] == 0) {
            A++;
            va.push_back(i);
        } else if (clr[i] == 1){
            B++;
            vb.push_back(i);
        }
    }


    cout << A << endl;
    for (auto x: va) {
        cout << x << " ";
    } cout << endl;
    cout << B << endl;
    for (auto y: vb) {
        cout << y << " ";
    } cout << endl;




}