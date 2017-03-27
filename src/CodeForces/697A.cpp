#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 200007
int n,m;

int t, s, x;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> t >> s >> x;
    if (((x-1-t)%s==0 && (x-1-t)/s>0) || (x-t)%s==0 && (x-t)/s>=0 ) cout << "YES" << endl;
    else cout << "NO" << endl;
}