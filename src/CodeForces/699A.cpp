#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 200007
int n;
char s[N];
int x[N];
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    cin >> s;

    for (int i=0; i<n; i++) cin >> x[i];
    int miner = INF;
    for (int i=0; i<n-1; i++) {
        if (s[i] == 'R' && s[i+1]=='L') miner = min((x[i+1]-x[i])/2, miner);
    }
    if (miner == INF) cout << -1 << endl;
    else cout << miner << endl;
}