// 6424848_AC_20ms_0kB.cpp
#include <iostream>
#include <stdio.h>
using namespace std;
//学习这种简单的编码方式


bool solve(int &w) { //传入当前天平的质量
    int a,b,c,d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    bool res1 = true, res2 = true; //默认是可以的
    if (a==0) { res1 = solve(a); }
    if (c==0) { res2 = solve(c); }
    w = a + c;
    return res1 && res2 && (a*b == c*d);
}

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        int w;
        if (solve(w)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        if (cases) {
            cout << endl;
        }
    }

}
