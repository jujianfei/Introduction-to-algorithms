#include <bits/stdc++.h>
using namespace std;
#define N 1000007
#define INF 0x3f3f3f3f
long long  n, k;

long long  row[N];
long long  col[N];
long long  rownum;
long long  colnum;

int  main()
{

    //freopen("in.txt", "r", stdin);
    cin >> n >> k;
    long long  ans = n * n;
    long long  x, y;
    for (long long  i=0; i<k; i++) {
        cin >> x >> y;
        if (row[x] && col[y]) {
            cout << ans << endl;
        } else if (row[x] && !col[y]) {
            ans = ans - (n - rownum);
            colnum ++;
            col[y] = 1;
            cout << ans << endl;
        } else if (!row[x] && col[y]) {
            ans = ans - (n - colnum);
            rownum++;
            row[x] = 1;
            cout << ans << endl;
        } else {

            ans = ans - ((n-colnum) + (n-rownum)) + 1;
            rownum++;
            colnum++;
            row[x] = col[y] = 1;
            cout << ans << endl;
        }
    }
}