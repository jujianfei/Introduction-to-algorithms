#include <bits/stdc++.h>
using namespace std;

#define N 200007
int n;
int dp[N];
int a[N];



int main() {

    memset(dp, -1, sizeof(dp));
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];



    dp[1] = 0;

    deque<int> d;
    d.push_back(1);


    while (d.empty()==false) {

        int fro = d.front();
        d.pop_front();

        //cout << "front " << endl;

        if (fro + 1<=n && fro + 1 >=1 && dp[fro + 1] == -1) {
            dp[fro + 1] = dp[fro] + 1;

            d.push_back(fro + 1);
        }
        //cout << "ok + 1" << endl;

        if (fro - 1<=n && fro - 1 >=1 && dp[fro - 1] == -1) {
            //cout << fro - 1 << " ?? " << endl;
            dp[fro - 1] = dp[fro] + 1;
            d.push_back(fro - 1);
        }

        //cout << "ok - 1" << endl;
        if (a[fro] != fro &&  dp[a[fro]] == -1) {
            dp[a[fro]] = dp[fro] + 1;

            d.push_back(a[fro]);
        }
        //cout << " ok a[]  " << endl;

    }
    for (int i=1; i<=n; i++) cout << dp[i] << " "; cout << endl;







}