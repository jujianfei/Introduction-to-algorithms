#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define N 200007
int n,m;

int fa[N];
int getroot(int x) {
    if (x != fa[x]) {
        fa[x] = getroot(fa[x]);     //回溯时的压缩路径
    }
    return fa[x];
}

bool q_m(int i,int j) {
    return getroot(i) == getroot(j);
}

void merger(int i,int j) {
    fa[getroot(j)]=getroot(i);
}

int a[N];
map<int,int> mp;
vector<int> self, oth;


int main() {
    //freopen("in.txt", "r", stdin);
    for (int i=0; i<N; i++) fa[i] = i;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) {
        if (q_m(i, a[i])==false) {
            merger(a[i], i);
        } else {
            if (a[i] == i) self.push_back(i);
            else oth.push_back(i);
        }
    }
    int cnt = 0;
    copy(oth.begin(), oth.end(), back_inserter(self));
    if (self.size()==0) {}
    else {
        mp[self[0]] = self[0];
        for (int i=1; i<self.size(); i++) {
            mp[self[i]] = self[0];
        }
    }

    for (int i=1; i<=n; i++) {
        if (mp.find(i)==mp.end()) {}
        else if (mp[i]!=a[i]) {
            a[i] = mp[i]; cnt++;
        }
    }

    cout << cnt << endl;
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
}