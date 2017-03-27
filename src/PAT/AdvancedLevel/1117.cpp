//hehe,这tm是道英语阅读理解题吧，就是没读懂题意，微笑脸

#include <bits/stdc++.h>
using namespace std;
#define N 100007

int n;
int a[N];
bool cmp(int a, int b) { return a > b;}
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n, cmp);
    int ans = n;
    for (int i=0; i<n; i++) {

        if (i+1 >= a[i]) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ans << endl;

}
