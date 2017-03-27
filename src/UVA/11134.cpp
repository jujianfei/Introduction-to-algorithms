// 6598606_AC_10ms_0kB.cpp

#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include <set>
#include <algorithm>
using namespace std;
#define N 100000

int n;

struct Node {
    int l,r;
    int id;
};
bool cmp(const Node &n1, const Node&n2) {
    if (n1.r < n2.r)return true;
    else if (n1.r > n2.r) return false;
    else return n1.l < n2.l;
}

Node x[N],y[N];

int resx[N], resy[N],_hash[N];

void init() {
    memset(resx, 0, sizeof(resx));
    memset(resy, 0, sizeof(resy));
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        init();
        for (int i=0; i<n; i++) {
            scanf("%d%d%d%d", &(x[i].l), &(y[i].l), &(x[i].r), &(y[i].r));
            x[i].id = i; y[i].id = i;
        }
        sort(x, x+n, cmp),sort(y,y+n, cmp);
        bool leftok = true;
        {
                memset(_hash, 0, sizeof(_hash));
                for (int i=0; i<n; i++) {
                    bool finder = false;
                    for (int j=x[i].l; j<=x[i].r; j++) {

                        if (_hash[j]==0) {
                            finder = true;
                            _hash[j] = 1;
                            resx[x[i].id] = j;
                            break;
                        }

                    }
                    if (finder == false) {
                            leftok = false;
                            break;
                    }
                }
        }

        bool rightok = true;
        {
                memset(_hash, 0, sizeof(_hash));
                for (int i=0; i<n; i++) {
                    bool finder = false;
                    for (int j=y[i].l; j<=y[i].r; j++) {

                        if (_hash[j]==0) {
                            finder = true;
                            _hash[j] = 1;
                            resy[y[i].id] = j;
                            break;
                        }

                    }
                    if (finder == false) {
                            rightok = false;
                            break;
                    }
                }
//                for (int i=0; i<n; i++) {
//                    cout << resy[i] << " ";
//                }cout << endl;
        }

        if (leftok && rightok) {
                for (int i=0; i<n; i++) {
                    cout << resx[i] << " " << resy[i] << endl;
            }
        } else {
            cout << "IMPOSSIBLE" << endl;
        }

    }
}
