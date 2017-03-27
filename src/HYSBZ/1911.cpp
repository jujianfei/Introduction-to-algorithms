// 6588529_AC_1180ms_32544kB.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <deque>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define N 1000007

long long a,b,c,n;

long long d[N];
long long dp[N];
long long sum[N];
long long q[N];

long long f(long long x) {
    return a * x * x + b * x + c;
}

long long getDP(long long i,long long j) {
    return dp[j] + f(sum[i]-sum[j]);
}

long long GUP(long long j,long long k) {
    return dp[j]-dp[k] + a * (sum[j] + sum[k]) * (sum[j]-sum[k]);
}

long long GDOWN(long long j, long long k) { // j > k
    return sum[j] - sum[k];
}

long long g(long long i) {
    return 2 * a * sum[i] + b;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    cin >> a >> b >> c;
    for (long long i=1;i<=n;i++) {
        scanf("%d", &d[i]);
    }

    sum[0] =dp[0] = 0;
    for(long long i=1; i<=n; i++)
        sum[i] = sum[i-1] + d[i];

    long long head=0;
    long long tail=0;
    q[tail++]=0;

    for(long long i=1;i<=n;i++)
    {
        while(head+1<tail && GUP(q[head+1],q[head])>=g(i)*GDOWN(q[head+1],q[head]))
            head++;
        dp[i]=getDP(i,q[head]);
        while(head+1<tail && GUP(i,q[tail-1])*GDOWN(q[tail-1],q[tail-2])>=GUP(q[tail-1],q[tail-2])*GDOWN(i,q[tail-1]))
            tail--;
        q[tail++]=i;
    }

    cout << dp[n] << endl;

    return 0;


}
