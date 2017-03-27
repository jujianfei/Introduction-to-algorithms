#include <bits/stdc++.h>
using namespace std;
#define N 100004
int n;
int a[N];

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    int last = 0;
    for (int i=0; i<n; i++) {
        if (a[i] >= last + 1)  {
                a[i] = last + 1;
                last ++;
        }
        else if (a[i] == last) {



        }
    }
    cout << last + 1 << endl;

}