// 6639852_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <cstring>
#define N 10007
#include <cmath>
using namespace std;
//(m - s - s *ln(m/s)) / m。 m  = a*b
double a,b,s,m;
int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> a >> b >> s;
        m = a * b;
        double ans ;
        if (m < s) {
            ans = 0;
        } else {
            if (fabs(s) < 1e-5) {
                ans = 1;
            } else {
                ans = (m - s - s *log(m/s)) / m;
            }
        }
        ans = ans * 100;
        printf("%.6f%%\n", ans);
    }
}
