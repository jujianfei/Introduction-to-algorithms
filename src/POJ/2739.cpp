// 6712572_AC_0ms_888kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#define INF 0x3f3f3f3f
typedef long long LL;
using namespace std;
#define N 50000

vector<int> primes;

bool isprime[N];

int sum[N]; // 前i个素数的和

int method[N];

void pre() {
    memset(isprime, true, sizeof(isprime));
    for (LL i=2; i<N; i++) {
        if (isprime[i]==false) continue;
        primes.push_back(i);
        for (LL j=i*i; j<N; j+=i) {
            isprime[j]=false;
        }
    }
//    for (int i=0; i<N; i++){
//        if (primes[i] > 10000) {
//            cout << i << "  " << primes[i] << endl;
//            break;
//        }
//    }
    sum[1] = primes[0];
    for (int i=2; i<1300; i++) {
        sum[i] = sum[i-1] + primes[i-1];
    }
    for (int i=0; i<1300; i++) {
        for (int j=i+1; j<1300; j++) {
            int s = sum[j] - sum[i];
            if (s < 10007)
                method[s]++;
        }
    }


}

int main() {
    //freopen("in.txt", "r", stdin);
    pre();
    int n;
    while (cin >> n && n) {
        cout << method[n] << endl;
    }
}


