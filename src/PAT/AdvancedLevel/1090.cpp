// 统计一棵树中最深的叶子节点的深度，和具有相同深度的叶子节点的数目
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005

int n;
double h, r;

vector<int> G[N];
int maxer = -1;
int number = 0;


void dfs(int root, int depth) {
    if (depth > maxer) {
        maxer = depth;
        number = 1;
    } else if (depth == maxer) {
        number ++;
    }

    for (int i=0; i<G[root].size(); i++) {
        int v = G[root][i];
        dfs(v, depth + 1);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> h >> r;
    int tmp;
    int root;
    for (int i=0; i<n; i++) {

        cin >> tmp;
        if (tmp == -1) root = i;
        else {
            G[tmp].push_back(i);
        }
    }
    dfs(root, 0);
    double ans = h * pow((1+r/100), maxer);
    printf("%.2f %d\n", ans, number);



}
