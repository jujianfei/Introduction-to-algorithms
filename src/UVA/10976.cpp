// 6461419_AC_0ms_0kB.cpp
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <algorithm>
bool cmp(int x,int y) {
    return x>y;
}
using namespace std;
#define N 10007
const double eps = 1e-100;  // 精度范围
int k;

int resa[N];
int resx[N];


int cur;

struct Node {
    int x,y;
    Node(int x,int y):x(x), y(y) {}
    Node() {}
};
Node res[N];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (~scanf("%d", &k)) {
        cur = 0;
        for (int x=k + 1; x<=2 * k; x++) {
            double a = k * x * 1.0 / (x - k) * 1.0;

            if (a == floor(a) * 1.0) {
               res[cur].x = floor(a);
               res[cur].y = x;
               cur ++;
            }
        }

        cout << cur << endl;
        for(int i=0; i<cur; i++){
            cout<<"1/"<<k<<" = 1/"<<res[i].x<< " + "<< "1/" <<res[i].y<<endl;
        }

    }
}
