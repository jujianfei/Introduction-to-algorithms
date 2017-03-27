// 6632771_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define N 50007
int phi[N];
int f[N];


void init()
{
    int i, j;
    memset(phi, 0, sizeof(phi));
    phi[1] = 1;
    for(int i = 2; i < N; i++) if(!phi[i])
    {
        for(j = i; j < N; j+=i)
        {
            if(!phi[j]) phi[j] = j;
            phi[j] = phi[j] / i * (i-1);
        }
    }
    f[2] = phi[2];
    for (int i=3; i<N; i++) {
        f[i] = f[i-1] + phi[i];
    }
    return ;

}


int main() {
    //reopen("in.txt", "r", stdin);
    init();
    int n;
    ///////////////

    /////////////
    while (cin >> n && n) {
        cout << 2 * f[n] + 1 << endl;
    }

}
