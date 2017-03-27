// 6564344_AC_0ms_0kB.cpp
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string.h>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
using namespace std;
#define N 57
int n;

string s = "_";


int main() {

    for (char i='A'; i<='Z'; i++) {
        s.push_back(i);
    }
    for (int i='a'; i<='z'; i++) {
        s.push_back(i);
    }

    cin >> n;

    while (1) {
        cout << 2 << " " << n <<  " " << n << endl;

        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << s[j];
            }cout << endl;
        }cout << endl;


        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                cout << s[i];
            }cout << endl;
        }cout << endl;

        if (cin >> n) {
            cout << endl;
        } else {
            break;
        }
    }



}
