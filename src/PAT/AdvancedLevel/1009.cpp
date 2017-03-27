// 多项式乘法，注意0是系数这个条件
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

    map<double,double> mp;

    for (int i=0; i<fir.size(); i++) {
        for (int j=0; j<sec.size(); j++) {
            double xa = fir[i].first * sec[j].first;
            double xe = fir[i].second + sec[j].second;
            mp[xe] += xa;
        }
    }

    vector<P> ret;
    for (map<double, double>::iterator p=mp.begin(); p!=mp.end(); p++) {
        if (p->second!=0.0)
            ret.push_back(P(p->second, p->first)); // sec是系数，fir是指数

    }


    cout << ret.size();

    for (int i=ret.size()-1; i>=0; i--) {
        printf(" %.0f %.1f", ret[i].second, ret[i].first);
    }

    printf("\n");

}

