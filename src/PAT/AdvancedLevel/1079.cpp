// 弱智题目，关键在于理解题意
// 统计一棵树中最深的叶子节点的深度，和具有相同深度的叶子节点的数目
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005

int n;
double h, r;

vector<int> G[N];
int cus[N];
double ret;

void dfs(int root, int depth) {
    if (cus[root] != -1) {
        double tmp = cus[root] * h * pow(1+r/100, depth);
        ret += tmp;
        return ;
    }

    for (int i=0; i<G[root].size(); i++) {
        int ch = G[root][i];
        dfs(ch, depth + 1);
    }

}

int main() {
    //freopen("in.txt", "r", stdin);
    memset(cus, -1, sizeof(cus));

    cin >> n >> h >> r;
    int tmp;
    int root;
    for (int i=0; i<n; i++) {
        cin >> tmp;
        if (tmp == 0) {
            int x;
            cin >> x;
            cus[i] = x;
        } else {

            int chil;
            while (tmp--) {
                cin >> chil;
                G[i].push_back(chil);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f\n", ret);




}

