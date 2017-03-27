// 6498181_AC_31ms_2760kB.cpp
#include <bits/stdc++.h>
#define N 100007
#define INF 0x3f3f3f3f
using namespace std;
int n;
int a[N];
int b[N];
int flag[N];

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    int cnt=0;
    int line = cases;
    while (cases--) {
        cnt++;
        memset(flag, -1,sizeof(flag));
        scanf("%d", &n);
        for (int i=0;i<n;i++) {
            scanf("%d", &a[i]);
        }
        b[0]=a[0];flag[0]=0;
        for (int i=1;i<n;i++){
            if (b[i-1]<0) {
                    b[i]=a[i];
                    flag[i]=0;
            } else {
                    b[i] = b[i-1] + a[i];
                    flag[i]=1;
            }
        }
        int maxer = -INF;
        int k = 0;
        for (int i=0;i<n;i++) {
            if (b[i] > maxer) {
                maxer = b[i];
                k = i;
            }
        }
        int begin = k;
        while (flag[begin]) {
            begin = begin - 1;
        }
        cout << "Case "<<cnt << ":" << endl;
        cout << maxer << " " << begin+1 << " " << k+1 <<endl;
        if (cnt!=line)cout << endl;
    }
}
