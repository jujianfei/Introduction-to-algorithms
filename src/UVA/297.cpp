// 6455854_AC_0ms_0kB.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 32
int pix[N][N];

void draw(int bx, int ex, int by, int ey) {
    for (int i=bx; i<=ex; i++) {
        for (int j=by; j<=ey; j++) {
            pix[i][j] = 1;
        }
    }
}

void build(int bx, int ex, int by, int ey, const string& s,int& cur) {
    //cout << bx << "->" << ex << " *** " << by << "->" << ey << endl;
    if (bx > ex || by > ey) return;
    if (s[cur]=='e') {}
    else if (s[cur]=='f') {
        draw(bx, ex, by, ey);
    } else {
        cur ++;
        build(bx, (bx + ex + 1)/2 - 1, by, (by + ey + 1)/2 - 1, s, cur);
        cur ++;
        build(bx, (bx + ex + 1)/2 - 1, (by + ey + 1)/2, ey, s, cur);
        cur ++;
        build((bx + ex + 1)/2, ex, by, (by + ey + 1)/2 - 1, s, cur);
        cur ++;
        build((bx + ex + 1)/2, ex, (by + ey + 1)/2, ey, s, cur);
    }
}

int counter() {
    int ret = 0;
    for (int i=0; i<N; i++) {
        for (int j=0;j<N; j++) {
            ret += pix[i][j];
        }
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    string fir,sec;
    scanf("%d", &cases);
    while (cases--) {
        memset(pix, 0 ,sizeof(pix));
        cin >> fir >> sec;
        //cout << fir << " " << sec << endl;
        int cur = 0;
        build(0,31,0,31,fir,cur);
        cur = 0;
        build(0,31,0,31,sec,cur);
        cout << "There are "<<counter()<<" black pixels." << endl;

    }
}
