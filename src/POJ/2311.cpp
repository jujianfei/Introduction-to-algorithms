// 6852868_AC_875ms_832kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (207)
using namespace std;

int dp[N][N];

int w,h;

int dfs(int w, int h) {
    if (dp[w][h] != -1) return dp[w][h];
    set<int> st;
    for (int i=2; w-i>=2; i++) st.insert(dfs(w-i, h) ^ dfs(i, h));
    for (int i=2; h-i>=2; i++) st.insert(dfs(w, h-i) ^ dfs(w, i));
    int res = 0;
    while (st.count(res)!=0) res ++;
    return dp[w][h] = res;
}


int main() {
    memset(dp, -1, sizeof(dp));
    //freopen("in.txt", "r", stdin);
    while (~scanf("%d%d", &w, &h)) {

        if (dfs(w,h)!=0) cout << "WIN" << endl;
        else cout << "LOSE" << endl;
    }
}
