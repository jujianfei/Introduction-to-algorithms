// 6548829_AC_469ms_740kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N  17
int ans = INF;
int m,n;
int origin[N][N];
int G[N][N];
int usesum;
int f[N][N];
int ret[N][N];

const int dx[]={0,1,0,-1,0};
const int dy[]={1,0,-1,0,0};

void flip(int i,int j) {
    for (int k=0;k<5;k++) {
        if (i+dx[k]<=n && i+dx[k]>=1 && j+dy[k]>=1 && j+dy[k]<=m) {
            G[i+dx[k]][j+dy[k]] = 1-G[i+dx[k]][j+dy[k]];
        }
    }
}

bool ok(int bi) { // 0~2^m-1
    usesum = 0;

    memset(f, 0, sizeof(f));
//    if (bi==55) {
//        cout << "check" << endl;
//        for (int i=1;i<=m;i++) {
//            cout << G[1][i] << " ";
//        }cout<<endl;
//    }

    for (int i=1;i<=m;i++) {
        if (bi & (1<<(i-1))) {
            flip(1, i);
            f[1][i] = 1;
            usesum ++;
        }
    }
//    if (bi==55) {
//        cout << "check" << endl;
//        for (int i=1;i<=m;i++) {
//            cout << G[1][i] << " ";
//        }cout<<endl;
//    }
    //利用i行处理第i-1行，让他全部变成白色 0
    for (int i=2;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (G[i-1][j]==1) {
                flip(i, j);
                f[i][j]=1;
                usesum++;
            }
        }
    }
    //检查第n行的颜色是不是全是白的
    for (int i=1;i<=m;i++) {
        if (G[n][i]==1) return false;
    }
    if (usesum < ans) {
        memcpy(ret,f,sizeof(f));
        return true;

    } else if (usesum == ans) {
        //从开始到结尾比较大小
        for (int x=1; x<=n; x++) {
            for (int y=1; y<=m; y++) {
                if (f[x][y] < ret[x][y]) {
                    memcpy(ret,f,sizeof(f));
                    return true;
                } else if (f[x][y] > ret[x][y]) {
                    return true;
                }
            }
        }
    } else {
        return true;
    }
}

int main() {

    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int tmp;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin >> tmp;
            if (tmp==1) {origin[i][j]=1;}
            else origin[i][j] =0;
        }
    }
//    cout << "check in" << endl;
//    for (int i=1;i<=n;i++) {
//        for (int j=1;j<=m;j++) {
//            cout <<G[i][j]<<" ";
//        }cout <<endl;
//    }

    for (int i=0; i<(1<<m); i++) {
        memcpy(G, origin, sizeof(G));
        if (ok(i)) {
            ans = min(ans, usesum);
        }
    }
    if (ans == INF) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                cout << ret[i][j] << " ";
            }cout << endl;
        }
    }



}
