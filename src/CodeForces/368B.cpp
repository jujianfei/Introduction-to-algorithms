#include <bits/stdc++.h>
using namespace std;
#define N 100007

int n, m;
int a[N];
int dp[N];
set<int> st;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<n; i++)  cin >> a[i];
    for (int i=n-1; i>=0; i--) {
        st.insert(a[i]);
        dp[i] = st.size();
    }
    int x;
    for (int i=0; i<m; i++) {
        cin >> x;
        cout << dp[x-1] << endl;
    }
}