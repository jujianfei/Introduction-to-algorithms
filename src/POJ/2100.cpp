// 6713986_AC_3672ms_1788kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;

long long n;

vector<vector<long long> > res;

void slove(long long tar) {
    long long n = ceil(sqrt(tar + 1));
    long long l=1, r=1;
    long long sum = 1;
    while (l <= n && r <= n) {
        //cout << "now " << sum << " " << l << " "  << " " << r << endl;
        if (sum == tar) {
            vector<long long> tmp;
            for (long long i=l; i<=r; i++) tmp.push_back(i);
            res.push_back(tmp);
            r++;
            sum += r * r;
        } else if (sum < tar) {
            r ++;
            sum += r * r;
        } else {

            sum -= l * l;
            l ++;
        }
    }

}

int main() {
    while (cin >> n && n) {
        res.clear();
        slove(n);
        cout << res.size() << endl;
        for (long long i=0; i<res.size(); i++) {
            cout << res[i].size() << " ";
            for (long long j=0; j<res[i].size(); j++) {
                cout << res[i][j] << " ";
            }cout << endl;
        }
    }

}

