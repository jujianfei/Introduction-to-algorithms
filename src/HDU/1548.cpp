// 6505016_AC_15ms_1616kB.cpp
#include <bits/stdc++.h>
using namespace std;
#include <deque>
#define N 207
int n;
int a[N];
int d[N];
int A,B;

int BFS() {
    deque<int> pq;
    d[A]=0;
    pq.push_back(A);
    while (pq.empty()==false) {

        int fro = pq.front();
        //cout << "fro " << fro << endl;
        if (fro == B) {
            return d[fro];
        }
        pq.pop_front();
        int up = fro + a[fro];
        if (up >=1 && up <= n && d[up]==-1) {
            d[up]=d[fro] + 1;
            pq.push_back(up);
            //cout << "push " << up << endl;
        }
        int down = fro - a[fro];
        if (down >=1 && down <=n && d[down]==-1) {
            d[down]=d[fro] + 1;
            pq.push_back(down);
            //cout << "push " << down << endl;
        }

    }
    return -1;
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n && n) {
        cin >> A >> B;
        memset(d,-1,sizeof(d));
        for (int i=1; i<=n; i++) {
            scanf("%d", &a[i]);
        }
        cout << BFS() << endl;
    }
}
