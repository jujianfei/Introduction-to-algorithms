// 6559528_AC_907ms_1520kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define LLINF 1e12
#define INF 0x3f3f3f3f
using namespace std;
#define N 100007
long long n,k;
long long a[N];
long long miner = INF,maxer = -INF;

bool can(long long mid) {//总的花费x时间能不能洗完
        long long ans = 0;
        for (long long i=1;i<=n;i++) {
            if (a[i]>mid) {
                ans += ceil((a[i]-mid)*1.0/(k-1));
            }
        }
        //ans是甩干的时间
        //mid是自然风的时间
        if (ans <= mid){
            return true;
        } else {
            return false;
        }
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n) {
        miner = INF,maxer = -INF;
        for (long long i=1;i<=n;i++) {
            scanf("%d", &a[i]);
            maxer = max(maxer, a[i]);
        }
        cin >> k;
        if (k==1) { cout << maxer << endl; continue; }

        long long l=0,r=INF,mid;
        while (r-l>1) {

            mid = (l+r)/2;
            //cout << "try " << mid << endl;
            if (can(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << endl;//边界条件总是确定不好


    }

}



