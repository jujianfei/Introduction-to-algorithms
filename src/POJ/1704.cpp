// 6852056_AC_0ms_704kB.cpp
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
#define N (1007)
using namespace std;


int P[N];
int n;

int main() {
    //freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            scanf("%d", &P[i]);
        }
        if (n%2==1) P[n++] = 0;
        sort(P, P+n);
        int ans = 0;
        for (int i=0; i+1<n; i+=2) {
            ans ^= (P[i+1] - P[i] - 1);
        }
        if (!ans) cout << "Bob will win" << endl;
        else cout << "Georgia will win" << endl;
    }
}
