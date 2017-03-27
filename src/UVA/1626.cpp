// 6618470_AC_2630ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <sstream>
#include <deque>
#include <vector>
using namespace std;
#define N  1007
#define INF 0x3f3f3f3f

int dp[N][N];
string tmp;

int cnt;

int dfs(int i,int j) { //前闭后开的区间
    //cout << "now " << i << " " << j << endl;
    if (dp[i][j] != -1) return dp[i][j];
    else if (i==j) return dp[i][j] = 0;
    else if (i+1==j) return dp[i][j] = 1;

    int miner = INF;
    if (tmp[i] == '(' && tmp[j-1] == ')' || tmp[i] == '[' && tmp[j-1] == ']') {
        miner = dfs(i+1, j-1);
    }

    for (int k=i+1; k<j; k++) {
        miner = min(miner, dfs(i,k) + dfs(k,j));
    }
    return dp[i][j] = miner;

}



void print(int i,int j) {
    if (i==j) return;
    if (i+1==j) {
        if (tmp[i]=='(' || tmp[i] == ')') {
            cout << "()"; cnt++;
        } else if (tmp[i]=='[' || tmp[i] == ']') {
            cout << "[]"; cnt++;
        }
        return;
    }
    if ((tmp[i] == '(' && tmp[j-1] == ')' || tmp[i] == '[' && tmp[j-1] == ']') && dfs(i+1,j-1) == dfs(i,j)) {
        cout << tmp[i] ;
        print(i+1, j-1);
        cout << tmp[j-1];
        return;
    }

    for (int k=i+1; k<j ;k++) {
        if (dfs(i,k) + dfs(k,j) == dfs(i,j)) {
            print(i,k); print(k,j);
            return;
        }
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    getline(cin, tmp); //吸收缓冲区的剩余

    while (cases--) {
        getline(cin, tmp);
        memset(dp, -1, sizeof(dp));
        getline(cin, tmp);


        cnt = 0;
        print(0, tmp.size());
        //cout << dfs(0,tmp.size()) << endl;
        if (dfs(0,tmp.size()) != cnt) cout << "error" << endl;

        cout << endl;
        if (cases!=0) cout << endl;


    }
}
