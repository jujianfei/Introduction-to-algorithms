// 15698292_AC_16MS_916K.cc

//http://poj.org/problem?id=1887

using namespace std;
#include <iostream>
#include <stdio.h>
#define N 33767
#define INF 0x3f3f3f3f
#include <vector>
#include <algorithm>
#include <cstring>

int dp[N];
vector<int> a;

int tmp;
int n;
int casenum = 0;

void init() {
    n = 0;
    memset(dp, 0x3f, sizeof(dp));
    a.clear();
}


int getans() {
    reverse(a.begin(), a.end());
    for (int i=0; i<a.size(); i++) {
        //cout << a[i] << " ";
        *(lower_bound(dp, dp + n, a[i])) = a[i];
    }//cout<<endl;
    return lower_bound(dp, dp + n, INF) - dp;
}

int main() {

    //freopen("in.txt", "r", stdin);
    init();
    while (cin >> tmp) {
        if (tmp == -1) {
            if (n == 0) {
                return 0;
            } else {
                casenum ++;
                printf("Test #%d:\n  maximum possible interceptions: %d\n\n",casenum, getans());
                init();
            }
        } else {
            n ++;
            a.push_back(tmp);
        }
    }

}
