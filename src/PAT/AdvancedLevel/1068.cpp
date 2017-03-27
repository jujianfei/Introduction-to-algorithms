// 背包的问题，但是按照字典序输出，详见背包九讲，注意这里的代价和价值相等
#include <bits/stdc++.h>
using namespace std;
#define N 10007

int f[107];
int a[N];
int g[N][107];

int cmp(int a, int b) { return a>b; }

int n, tar;
int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &tar);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    sort(a+1, a+n+1, cmp);

    for (int i=1; i<=n; i++) {
        for (int j=tar; j>=0; j--) {
            //if (can[j]) continue;
            if (j < a[i]) {}
            else {
                 int fir = f[j];
                 int sec = f[j-a[i]] + a[i];
                 if (sec >= fir) {
                    g[i][j] = 1;
                 } else {
                    g[i][j] = 0;
                 }
                 f[j] = max(fir, sec);
            }
        }
    }

    vector<int> ret;
    if (f[tar] != tar) {
        cout << "No Solution" << endl;
    } else {
        int i=n;
        int v=tar;
        while (i>0) {
            if (g[i][v]) {
                ret.push_back(a[i]);
                //cout << "select " << a[i] << endl;
                v = v - a[i];
            } else {
                //cout << "no select" << a[i] << endl;
            }
            i = i - 1;
        }
        for (int i=0; i<ret.size()-1; i++) cout << ret[i] << " "; cout << ret[ret.size()-1] << endl;
    }







}
