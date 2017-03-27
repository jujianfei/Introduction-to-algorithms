// 6597726_AC_180ms_0kB.cpp
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include <set>
using namespace std;
#define N 100007

int n;
int a[N];
int b[N];

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    int cntr = 0;
    while (cases--) {
        cntr++;
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        for (int i=0; i<n; i++) scanf("%d", &b[i]);
        bool ok;
        int ans = -1;
        int ty = 0;
        int tank;
        set<int> st;
        do {
            st.insert(ty);
            //cout << "try " << ty << endl;
            int p = ty;
            tank = 0;
            ok = false;
            int counter = 0;
            while (tank >= 0) {
                    //cout << "now " << p << endl;
                tank += a[p] - b[p];
                p = (p+1) % n;
                counter ++;
                if (counter > n) {
                    //cout << "get " << endl;
                    ans = ty + 1;
                    ok = true;
                    break;
                }
                if (ok){
                    break;
                }
            }
            if (ok == true) break;
            else {
                //cout << "failed " << p << endl;
                ty = p;
            }

        }while (st.find(ty) == st.end());

        if (ok==false) cout << "Case " << cntr << ": " << "Not possible" << endl;
        else cout << "Case " << cntr << ": " << "Possible from station " << ans << endl;
    }
}
