// 6663411_AC_670ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;
#define N 157
#define INF 0x3f3f3f3f
template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while(sout >> tmp){
        res.push_back(tmp);
    }
    return res;
}

int n,m,s;
int st[N];
int c[N];
string line;
int dp[N][1<<9][1<<9];

int dfs(int i, int s0, int s1, int s2) {
    if (i==m+n) return s2 == ( 1<< s) - 1 ? 0 : INF;
    int & ans = dp[i][s1][s2];
    if (ans >= 0) return ans;
    ans = INF;
    if (i >= m) ans = dfs(i+1, s0, s1, s2);
    int m0 = st[i] & s0;
    int m1 = st[i] & s1;
    s0 ^= m0, s1 = (s1 ^ m1) | m0; s2 |= m1;
    ans = min(ans, c[i] + dfs(i+1, s0,s1,s2));
    return ans;
}


void init() {
    memset(dp, -1, sizeof(dp));
}
int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> s >> m >> n) {
        if (m==0 && n==0) break;
        init();
        getline(cin, line);
        for (int i=0; i<m+n; i++) {
            getline(cin, line);
            //cout << line << endl;
            vector<int> v = StringToVec<int>(line);
            c[i]=v[0];
            int ans = 0;
            for (int k=1; k<v.size(); k++) {
                ans = ans | (1<<(v[k]-1));
            }
            st[i]=ans;
        }
        cout <<dfs(0, (1<<s)-1, 0, 0) <<endl;

    }
}
