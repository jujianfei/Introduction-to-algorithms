// 6643176_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 1007
using namespace std;
int n,D;



int main() {
    //freopen("in.txt", "r", stdin);
    int p,L,v;


    int cnt = 0;
    while (cin >> n >> D ) {
        double ans = 0;
        cnt ++;
        int sumL = 0;
        if (n == 0 && D == 0) break;
        for (int i=0; i<n; i++) {
             cin >> p >> L >> v;
            ans += (2.0*L)/v;
            sumL += L;
        }
        ans += (D-sumL);
        printf("Case %d: %.3f\n\n", cnt, ans);
    }


}
