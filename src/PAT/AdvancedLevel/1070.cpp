//贪心 WA了一发，换了一种姿势，过了

#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define N 100007
int n;
struct Node{
    double v, w;
    Node() {}
    bool operator < (const Node& n) const {
        return w / v > n.w / n.v;
    }
};

Node a[N];
double tar;
int main()
{
    //freopen("in.txt", "r", stdin);
    cin >> n >> tar;
    for (int i=0; i<n; i++) {
        cin >> a[i].v;
    }
    for (int i=0; i<n; i++) {
        cin >> a[i].w;
    }
    sort(a, a+n);

    double ret = 0;

    for (int i=0; i<n; i++) {
        if (tar == 0) break;
        if (a[i].v < tar) {
            ret += a[i].w;
            tar -= a[i].v;
        } else {

            ret += a[i].w * tar / a[i].v;
            tar = 0;
        }
    }

    printf("%.2f\n", ret);



}

