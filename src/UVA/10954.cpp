// 6593851_AC_0ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
using namespace std;
#define N  10007
#define INF 0x3f3f3f3f
int a[N];

int n;
int tmp;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    //freopen("in.txt", "r", stdin);

    while (cin >> n && n) {
        while (pq.size()!=0) { pq.pop(); }
        for (int i=0;i<n;i++) {
            scanf("%d", &tmp);
            pq.push(tmp);
        }
        int ans = 0;
        while (pq.size()>1) {
            int fir = pq.top(); pq.pop();
            int sec = pq.top(); pq.pop();
            ans += (fir + sec);
            pq.push(fir + sec);
        }

        cout  << ans << endl;



    }

}
