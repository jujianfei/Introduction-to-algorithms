#include <bits/stdc++.h>
using namespace std;
#define N 1000007
#define INF 0x3f3f3f3f
int n, k;
struct Node {
    int id, val;
    bool operator < (const Node& n2) const { return val < n2.val; }
};

Node a[N];
int main()
{

    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
    sort(a+1, a+n+1);

    for (int i=1; i<=n/2; i++) {

        cout << a[i].id << " " << a[n+1-i].id << endl;
    }

}