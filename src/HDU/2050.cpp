// 6374779_AC_0ms_1604kB.cpp
#include <bits/stdc++.h>
using namespace std;

#define N 10007
int a[N];
void pre() {
    a[1]=2;
    for (int i=2; i<N-1; i++) {
        a[i] = a[i-1] + 4 * (i-1) + 1;
    }
}
int tmp;
int main() {
    pre();
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &tmp);
        printf("%d\n", a[tmp]);
    }

}
