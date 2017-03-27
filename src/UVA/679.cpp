// 6409964_AC_150ms_0kB.cpp
#include <iostream>
using namespace std;
int x,y;

long long getans(int x, int y) {
    int begin = 1;
    for (int i=0; i<x-1; i++) {
        if (y % 2 == 0) {
            begin = begin * 2 + 1;
            y = (y ) / 2;
        } else {
            begin = begin * 2;
            y = (y+1) / 2;
        }
    }
    return begin;
}

int main() {
    int cases;
    while (cin>>cases && cases != -1) {
        while (cases--) {
            cin>>x>>y;
            cout<<getans(x,y)<<endl;
        }
    }
}
