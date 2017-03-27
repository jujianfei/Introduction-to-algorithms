// 题目出的一般，如果sum相同的话，输出较小的i，j，这里的i和j没有说清楚怎么比较
// 最后如果全是负数，输出数列的第一个元素，和最后一个元素，这是何苦啊，WA了好多次....
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 10007

int a[N];
int dp[N]; //到当前位置的最大的那个子序列的大小
int n;
int flag[N]; // 是否依赖前面的

int get(int i) {
    int cnt = 1;
    while (flag[i]==1) {
        cnt ++;
        i --;
    }
    return cnt;
}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    int ok = true;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] >= 0) ok = false;
    }
    if (ok) {
        cout << 0 << " " << a[1] << " " << a[n] << endl;
        return 0;
    }

    for (int i=1; i<=n; i++) {
        if (dp[i-1] <= 0) {
            dp[i] = a[i];
            flag[i] = 0;
        } else if (dp[i-1] > 0) {
            if (dp[i-1] + a[i] <= a[i]) {
                dp[i] = a[i];
                flag[i] = 0;
            } else {
                dp[i] = dp[i-1] + a[i];
                flag[i] = 1;
            }
        }
        // 处理特殊情况
        if (i>1 && a[i-1]==0) flag[i] = 1;
    }

    int maxer = -INF;
    int recb = -1;
    int rece = -1;

    for (int i=1; i<=n; i++) {

        if (dp[i]>maxer) {
            maxer = dp[i];
            rece = i;
            recb = i-get(i)+1;
        } else if (dp[i] == maxer) {
            if (i-get(i)+1 < recb) {
                rece = i;
                recb = i-get(i)+1;
            }
        }
    }

    if (maxer<0) maxer = 0;
    cout << maxer << " " << a[recb] << " " << a[rece] << endl;
}
