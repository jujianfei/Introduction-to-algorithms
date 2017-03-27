// 6614752_AC_10ms_0kB.cpp
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
#define N  507
#define INF 0x3f3f3f3f

int t[N];
int has[N][N][2];// last == 1 right . last == 0 left
int n, T;
int dp[N][N];

void init() {
    memset(t, 0, sizeof(t));
    memset(has, 0, sizeof(has));
    memset(dp, 0, sizeof(dp));
}


int main() {
    //freopen("in.txt", "r", stdin);
    int cnt = 0;
    while (cin>> n &&  n) {
        cnt ++;
        init();
        cin >> T;
        for (int i=1; i<n; i++) {
            cin >> t[i];
        }
        int m1 ;
        cin >> m1;
        int tmp;

        for (int i=0; i<m1; i++) {
            cin >> tmp;
            int pos = 1;
            while (tmp <= T && pos <= n) {
                has[tmp][pos][1] = 1;
                tmp += t[pos];
                pos ++;
            }
        }

        int m2 ;
        cin >> m2;
        for (int i=0; i<m2; i++) {
            cin >> tmp;
            int pos = n;
            while (tmp <= T && pos >= 1) {
                has[tmp][pos][0] = 1;
                tmp += t[pos-1];
                pos --;
            }
        }
        for (int i=1; i<=n-1; i++) {
            dp[T][i] = INF;
        }

//        for (int i=0; i<=T; i++) {
//                cout << "Time " << i << ": " ;
//            for (int j=1; j<=n; j++) {
//                cout << has[i][j][1] << " ";
//            } cout << endl;
//        }


        dp[T][n] = 0;

        for (int i=T-1; i>=0; i--) {
            for (int j=1; j<=n; j++) {
                dp[i][j] = dp[i+1][j] + 1;

                if (j < n && has[i][j][1] && i+t[j] <=T) dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);
                if (j > 1 && has[i][j][0] && i+t[j-1] <= T) dp[i][j] = min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }
        cout << "Case Number " << cnt << ": ";
        if (dp[0][1] >= INF) {
            cout << "impossible" << endl;
        } else {
            cout << dp[0][1] << endl;
        }
    }
}
