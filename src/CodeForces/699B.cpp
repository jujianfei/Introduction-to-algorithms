#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 2007
int n,m;

int row[N],col[N];
int total;
string G[N];
int main() {

    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        G[i].resize(1002);
        cin >> G[i];
        for (int j=0; j<m; j++) {
            if (G[i][j]=='*') {
                row[i]++;
                col[j]++;
                total++;
            }

        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int flag=0;
            if (G[i][j]=='*') flag=1;
            if (row[i] + col[j] - flag == total) {
                cout << "YES" << endl;
                cout << i+1 << " " << j+1 << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;



}