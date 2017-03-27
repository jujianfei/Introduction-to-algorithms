// 6707849_AC_657ms_5340kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#define N 100007
#define INF 0x3f3f3f3f
using namespace std;

deque<int> pq;

int d[(1<<20)];


int flip(int n, int index) {
    for (int i=index-1; i<=index + 1; i++) {
        if (i>=0 && i <=19) {
            n = n ^ (1<<i);
        }
    }
    return n;
}


int main() {
    //freopen("in.txt", "r", stdin);

    int begin = 0;

    int tmp;
    for (int i=0; i<20; i++) {
        cin >> tmp;
        if (tmp) {
            begin = begin | (1<<i);
        }
    }
    memset(d, -1, sizeof(d));
    pq.push_back(begin);
    d[begin] = 0;
    while (pq.empty()==false) {
        int fro = pq.front();
        //cout << "now _fro " << fro << endl;
        pq.pop_front();
        if (fro == 0) {
            cout << d[fro] << endl;
            return 0;
        }

        for (int index = 0; index <=19; index ++) {
            int tmp = flip(fro, index);
            if (d[tmp] == -1) {
                d[tmp] = d[fro] + 1;
                pq.push_back(tmp);
            }
        }
    }


}

