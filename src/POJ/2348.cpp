// 6851641_AC_0ms_700kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
#define N (1007)
using namespace std;


int a, b;

string solve(int a, int b) {
    bool f = true;
    while (1) {
        if (a > b) swap(a, b);
        if (b % a == 0) break;
        if (b - a > a) break;
        b = b - a;
        f = !f;
    }
    if (f) return "Stan wins";
    else return "Ollie wins";

}

int main() {
    while (cin >> a >> b) {
        if (a==0 && b==0) break;

        cout << solve(a,b) << endl;
    }
}
