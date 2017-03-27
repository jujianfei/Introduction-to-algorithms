// 6505841_AC_46ms_1596kB.cpp
#include <bits/stdc++.h>
using namespace std;
#include <deque>
#define N 207
#define M 65

//只需证明18+a*k能否被65整除就行了

int main() {
    //freopen("in.txt", "r", stdin);
    int k;
    while (cin >> k) {
        bool have = false;
        for (int a=0; a<100; a++) {
            if ((18+a*k) % M ==0){
                have = true;
                cout << a << endl;
                break;
            }
        }
        if (have == false) {
            cout << "no" << endl;
        }
    }
}
