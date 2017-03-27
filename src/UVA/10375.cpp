// 6632167_AC_210ms_0kB.cpp

#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#define N 10007
#include <cmath>
vector<int> v;
int prime[N];
int e[N]; // 对应每个素数的指数

void getprime() {
    for (int i=0; i<N; i++) { prime[i]=1; } //素数是1
    prime[1] = 0;
    prime[0] = 0;
    for (int i=2; i<N; i++) {
        if (prime[i]) {
            v.push_back(i);
            for(int j=i*i; j<N; j+=i) { prime[j] = 0; }
        }
    }
}

void add_integer(int n, int flag) {
    for (int i=0; i<v.size(); i++) {
        while (n % v[i] == 0) {
            n = n / v[i];
            e[i] += flag;
        }
        if (n == 1) break;
    }

}

int add_fractions(int n, int flag) {
    for (int i=1; i<=n ; i++) {
        add_integer(i, flag);
    }
}

double get_ans() {
    double ans = 1;
    for (int i=0; i<v.size(); i++) {
        ans = ans * pow(v[i], e[i]);
    }
    return ans;
}

int main() {
    getprime();
    int p,q,r,s;
    //freopen("in.txt", "r", stdin);
    while (cin >> p >> q >> r >> s) {


        memset(e, 0, sizeof(e));

        add_fractions(p, 1);
        add_fractions(q, -1);
        add_fractions(p-q, -1);

        add_fractions(r,-1);
        add_fractions(s, 1);
        add_fractions(r-s, 1);




        printf("%.5f\n", get_ans());
    }
}
