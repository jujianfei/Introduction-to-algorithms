#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 10007

int x[N],y[N];

int n,w,v,u;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> w >> v >> u;
    double maxer = -1;
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    double lim = u * 1.0 / v;
    bool flag1 = false; // 检测都是在右侧的标志位
    bool flag2 = false; // 检测都是在左侧的标志位
    for (int i=0; i<n; i++) {
        if (y[i] * 1.0 / x[i] > lim  || y[i] * 1.0 / x[i] < 0) {
            flag1 = true;
        }
        if (y[i] * 1.0 / x[i] < lim) {
            flag2 = true;
        }
        double tmp = x[i] * 1.0 / v + (w - y[i]) * 1.0 / u;
        maxer = max(maxer, tmp);
    }

    if (flag1 == false || flag2 == false)  {
        printf("%.10f\n", w*1.0/u);
        return 0;
    }

    printf("%.10f\n", maxer);



}