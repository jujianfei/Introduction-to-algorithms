// 6733225_AC_735ms_4676kB.cpp
#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define N 1007

int n, m;
int tre[N][N];
int lowbit(int x) {
    return x&(-x);
}
void modify(int x,int y,int delta)
{
    for(int i = x; i <= n; i+= lowbit(i)) {
        for(int j = y; j <= n; j += lowbit(j)) {
            tre[i][j] += delta;
        }
    }
}
int get_sum(const int& x,const int& y)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i)) {
        for(int j = y; j > 0; j -= lowbit(j)) {
            sum += tre[i][j];
        }
    }
    return sum;
}


int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        memset(tre, 0, sizeof(tre));
        scanf("%d%d", &n, &m);
        //cout << n << " " << m << endl;
        int x1, y1, x2, y2;
        char type;
        while (m--) {
            cin >> type;

            if (type == 'C') {
                scanf("%d%d%d%d", &x1,&y1,&x2,&y2);
                //cout << "C" << x1 << y1 << x2 << y2 << endl;
                modify(x1, y1, 1);
                modify(x2+1, y1, 1);
                modify(x1, y2+1, 1);
                modify(x2+1, y2+1, 1);
            } else {
                scanf("%d%d", &x1, &y1);
                int tmp = get_sum(x1, y1); //- get_sum(x1, y1-1) - get_sum(x1-1, y1) + get_sum(x1-1, y1-1);
                //cout << "tmp" << tmp << endl;
                printf("%d\n", tmp%2);
            }

        }
        printf("\n");
    }
}