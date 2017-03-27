// 6622864_AC_120ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;
#define N  100007
#define INF 0x3f3f3f3f

struct Node {
    int val; //统计手下的员工的票数
    int num; //用户的id
    Node (int val, int num):val(val), num(num) {}
    Node() {}
    bool operator < (const Node &oth) const { return val < oth.val; }
};

int T;
int n;

vector<Node> a[N];
int dp[N];



int dfs(int i) {
    if (dp[i] != -1) return dp[i];
    if (a[i].size() == 0) return dp[i] = 1;
    int limit = ( a[i].size() * T -1 )/100 + 1;
    sort(a[i].begin(), a[i].end());
    for (int j=0; j<a[i].size(); j++) {
        a[i][j].val = dfs(a[i][j].num);
    }
    sort(a[i].begin(), a[i].end());
    int ans = 0;
    for (int j=0; j<limit; j++) {
        ans += a[i][j].val;
    }
    return dp[i] = ans;

}

int main() {
    int tmp;
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> T) {
        if (n == 0 && T ==0) break;
        for (int i=0; i<N; i++) { a[i].clear(); }
        memset(dp, -1, sizeof(dp));

        for (int i=1; i<=n; i++) {
            scanf("%d", &tmp);
            a[tmp].push_back(Node(-1, i));
        }

        cout  << dfs(0) << endl;


    }
}
