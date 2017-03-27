//英语阅读理解
#include <bits/stdc++.h>
using namespace std;

double a[3][3];

char F(int i) {
    if (i==0) return 'W';
    if (i==1) return 'T';
    if (i==2) return 'L';
}

int main() {
    //freopen("in.txt", "r", stdin);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> a[i][j];
        }
    }

    double maxer = -1.0;
    int reci, recj, reck;
    for (int j=0; j<3; j++) {
        if (a[0][j] > maxer) {
            reci = j, maxer = a[0][j];
        }
    }

    maxer = -1.0;
    for (int j=0; j<3; j++) {
        if (a[1][j] > maxer) {
            recj = j, maxer = a[1][j];
        }
    }

    maxer = -1.0;
    for (int j=0; j<3; j++) {
        if (a[2][j] > maxer) {
            reck = j, maxer = a[2][j];
        }
    }

    double ans = (a[0][reci]*a[1][recj]*a[2][reck] * 0.65 - 1) * 2.0;


    cout << F(reci) << " " << F(recj) << " " << F(reck) << " ";



    printf("%.2f\n", ans);



}
