// 6659342_AC_20ms_0kB.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
typedef long long ll;
#define INF 0x3f3f3f3f
#define N 1007
#define M 1000007
#define RST(x) memset(x, 0, sizeof(x))


int d[N][N];
int n,K,m;
int x,y,w;
int cnt = 0;
void init() {
    memset(d, 0x3f, sizeof(d));
}
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m >> K;
    while (1) {
        cnt ++;
        cout << "Case #" << cnt << endl;
        if (n==0 && m==0 && K == 0) break;
        init();

        for (int i=0; i<m; i++) {
            cin >> x >> y >> w;

            d[x-1][y-1] = d[y-1][x-1] = w;
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
                }
            }
        }
        //cout << " ---- " << endl;
        int b, e;
        for (int i=0; i<K; i++) {
            cin >> b >> e;
            //cout << d[b-1][e-1] << endl;
            if (d[b-1][e-1]==INF) {
                cout << "no path" << endl;
            } else{
                cout << d[b-1][e-1] << endl;
            }
        }
        cin >> n >> m >> K;
        if (n==0 && m==0 && K == 0) break;
        else cout << endl;
    }
}
