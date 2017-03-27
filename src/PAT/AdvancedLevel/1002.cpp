// 多项式求和，简单，不多说
#include <bits/stdc++.h>
using namespace std;

vector<pair<double,double> > fir, sec;

int n, m;
typedef pair<double, double> P;

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    double a, e;
    for (int i=0; i<n; i++) {
        cin >> e >> a;
        fir.push_back(P(a, e));
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        cin >> e >> a;
        sec.push_back(P(a, e));
    }


    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());



    vector<P> ret;

    int ncur=0, mcur=0;

    while(ncur!=n && mcur!=m) {

        if (fir[ncur].second < sec[mcur].second) {
            ret.push_back(fir[ncur]);
            ncur++;
        } else if (fir[ncur].second > sec[mcur].second) {
            ret.push_back(sec[mcur]);
            mcur++;
        } else {
            if (fir[ncur].first + sec[mcur].first) {
                 ret.push_back(P(fir[ncur].first + sec[mcur].first, fir[ncur].second));
            }
            mcur++, ncur++;
        }

    }


    while (ncur!=n) {
        ret.push_back(fir[ncur++]);
    }
    while (mcur!=m) {
        ret.push_back(sec[mcur++]);
    }

    cout << ret.size();
    for (int i=ret.size()-1; i>=0; i--) {
        printf(" %.0f %.1f", ret[i].second, ret[i].first);
    }
    printf("\n");

}
