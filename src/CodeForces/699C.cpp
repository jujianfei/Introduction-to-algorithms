#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 2007
int n,m;

int sp[N],wr[N],re[N];
int a[N];

int main() {
    //freopen("in.txt", "r", stdin);
    memset(sp, -1, sizeof(sp));
    memset(wr, -1, sizeof(wr));
    memset(re, -1, sizeof(re));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    sp[0] = wr[0]= 0;
    re[0] = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == 0) {
            re[i] = max(re[i-1], max(sp[i-1], wr[i-1]));
        } else if (a[i] == 1) {
            int fir = re[i-1] + 1;
            int sec = sp[i-1] + 1;
            wr[i] = max(fir, sec);
            re[i] = max(re[i-1], max(sp[i-1], wr[i-1]));
        } else if (a[i]==2) {
            int fir = re[i-1] + 1;
            int sec = wr[i-1] + 1;
            sp[i] = max(fir, sec);
            re[i] = max(re[i-1], max(sp[i-1], wr[i-1]));
        } else {
            int fir = re[i-1] + 1;
            int sec = sp[i-1] + 1;
            wr[i] = max(fir, sec);
            fir = re[i-1] + 1;
            sec = wr[i-1] + 1;
            sp[i] = max(fir, sec);
            re[i] = max(re[i-1], max(sp[i-1], wr[i-1]));
        }
    }
    cout << n-(max(sp[n], max(wr[n], re[n]))) << endl;


}