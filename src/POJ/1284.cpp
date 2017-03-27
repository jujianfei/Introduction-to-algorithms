// 6999120_AC_79ms_1124kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string.h>
#define N 100007
using namespace std;
typedef long long ll;

int phi[N];

void init() {
    for (int i=0; i<N; i++) phi[i] = 0;
    phi[1] = 1;
    for (ll i=2; i<N; i++) if (phi[i] == 0) {
        for (ll j=i; j<N; j+=i) {
            if (phi[j] == 0) phi[j] = j;
            phi[j] = phi[j] / i * (i-1);
        }
    }
}

int main() {
    init();
    int tmp;
    while (cin >> tmp) {
        cout << phi[tmp-1] << endl;
    }
}
