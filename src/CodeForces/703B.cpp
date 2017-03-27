#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 100007
long long n,k;
long long a[N];
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n; cin >> k;
    cin >> a[0];
    long long ans = 0;
    long long sum = a[0];
    for (long long i=1; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        ans += a[i] * a[i-1];
    }
    ans += a[0] * a[n-1];


    long long x;
    long long nowis_sum = 0;
    set<long long> st;
    for (long long _=0; _<k; _++) {
        cin >> x;
        x--;
        long long tmp = sum;
        tmp = (tmp - a[x] - nowis_sum) ;
        if (st.find((x+1)%n) == st.end()) tmp -= a[(x+1)%n];
        if (st.find((x-1+n)%n) == st.end()) tmp -= a[(x-1+n)%n];
        ans = ans + a[x] * tmp;

        nowis_sum += a[x];
        st.insert(x);
    }
    cout << ans << endl;

}