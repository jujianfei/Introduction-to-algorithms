// 6633876_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 50007

string tmp;

int main() {

    //freopen("in.txt", "r", stdin);
    while (cin >> tmp) {
        int n = tmp.size();
        int b = count(tmp.begin(), tmp.end(), '0');
        int a = 0;
        for (int i=0; i<n; i++) {
            if (tmp[i]=='0' && tmp[(i+1)%n]=='0') a++;
        }
        if (a*n > b*b) cout << "SHOOT" << endl;
        else if (a*n < b*b) cout << "ROTATE" << endl;
        else cout << "EQUAL" << endl;

    }


}
