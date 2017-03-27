// 比较简单，判断栈是不是可以生成某个序列，这里多了一个条件，就是栈的大小，模拟的过程中注意一下就好了。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 5007

int a[N];
int k, m, n;

bool ok() {

    vector<int> v;
    for (int i=n; i>=1; i--) v.push_back(i);
    vector<int> stk;

    for (int i=0; i<n; i++) {
        if (stk.empty()==false && stk.back() == a[i]) {
            stk.pop_back();
        } else {
            int flag = 0;
            while (!v.empty()) {
                if (v.back()==a[i]) {
                    if (stk.size() >= k) return false;

                    flag = 1;

                    v.pop_back();
                    break;
                } else {
                    stk.push_back(v.back());
                    if (stk.size() > k) return false;
                    v.pop_back();
                }
            }
            if (flag == 0) return false;
        }
    }
    return true;

}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> k >> n >> m;
    while (m--) {



        for (int i=0; i<n; i++) cin >> a[i];

        if (ok()) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

}
