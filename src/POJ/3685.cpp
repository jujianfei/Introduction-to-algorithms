// 6556877_AC_2500ms_732kB.cpp
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
#define INF 1e12
using namespace std;
#define N 50007

long long n,m;

long long maxer = -INF;
long long miner = INF;

long long g(long long i) {
    return i*i;
}

long long f(long long i, long long j) { //对于x是单调递增的，对于y我们认为不确定，其实这里是先简后增的。
    return ((i*i) + (100000 * i) + (j*j) - (100000*j) + (i*j));
}

//
//long long upper_iter_test(long long lo, long long hi, long long target) {//统计某一列中小于target的个数有多少
//    long long res;
//    while(lo<hi){
//        long long mid=lo+(hi-lo)/2;
//        if((g(mid))<target){
//            lo=mid+1;
//            res=lo;
//        }else {
//            hi=mid;
//            res=hi;
//        }
//    }
//    return res;
//}



long long upper_iter(long long col, long long lo, long long hi, long long target) {//统计某一列中小于target的个数有多少
    long long res;
    while(lo<hi){
        long long mid=lo+(hi-lo)/2;
        if((f(mid, col))<target){
            lo=mid+1;
            res=lo;
        }else {
            hi=mid;
            res=hi;
        }
    }
    return res;
}

long long cntr(long long M) {
    //统计矩阵中<M的数有多少个
    long long ans = 0;
    for (long long i=1;i<=n;i++) { //每一列
        ans += upper_iter(i, 1, n+1, M) - 1;
    }
    return ans;
}

long long bfcnt(long long M) {
    long long ans = 0;
    for (long long i=1;i<=n;i++) {
        for (long long j=1;j<=n;j++) {
            if (f(i,j)<M) {
                ans ++;
            }
        }
    }
    return ans;
}


int main() {

    //freopen("in.txt", "r", stdin);
    long long cases;
    cin >> cases;
    while (cases--) {
        maxer = -INF;
        miner = INF;
        cin >> n >> m;
        //最小值一定在第一行，最大值一定在最后一行
        long long left = -INF;
        long long right = INF;
        long long cnt = 0;
        long long mid;

        while (right-left>1) {
            mid = (left + right) / 2;
            long long tmp = cntr(mid);
            if (tmp <= m-1) {
                left = mid;
            } else {
                right = mid;
            }
            cnt++;
        }
        cout << left << endl;
    }

}



